// awpipcam.cpp : Defines the exported functions for the DLL application.
//
#ifdef _WIN32
#define snprintf _snprintf
#endif

#if defined(WIN32) && !defined(PRId64) 
#define PRId64 "I64d"
#endif

#define __STDC_CONSTANT_MACROS
#define _SDL_config_win32_h
extern "C"
{
#include <libavutil\imgutils.h>
#include <libavcodec\avcodec.h>
#include <libavformat\avformat.h>
#include <libavutil\samplefmt.h>
#include <libavutil\timestamp.h>
#include <libavfilter\avfiltergraph.h>
#include <libavfilter\avcodec.h>
#include <libavfilter\buffersink.h>
#include <libavfilter\buffersrc.h>
#include <libswscale\swscale.h>
#include "libavutil\opt.h"
}

#include "SDL.h"
#include "awpipl.h"
#include <string>
#include <ctime>

#include "awpipcam.h"

extern "C"
{
	#pragma comment(lib, "avutil.lib")
	#pragma comment(lib, "avformat.lib")
	#pragma comment(lib, "avcodec.lib")
	#pragma comment(lib, "swscale.lib")
	#pragma comment(lib, "avfilter.lib")
	#pragma comment(lib,"SDL.lib")
	#pragma comment(lib,"SDLmain.lib")
}

using namespace std;

static bool AVFrame2AwpRGBImage(AVFrame* frame, awpImage** ppImage)
{
    bool res = false;
    if (frame == NULL || ppImage == NULL)
        return res;

    AVPicture picture;
    picture.data[0] = NULL;
    int line_size = frame->width*3;
    
    picture.data[0] = (uint8_t*)malloc(line_size*frame->height);
    if (picture.data[0] == NULL)
        goto cleanup;
    picture.linesize[0] = 3*frame->width;
    SwsContext* context = NULL;  

    context = sws_getCachedContext(context, frame->width, frame->height, (PixelFormat)frame->format, 
		frame->width, frame->height, AV_PIX_FMT_BGR24   , 1, NULL, NULL, NULL);
    
    if (context == NULL)
        goto cleanup;

    int h = sws_scale(context, frame->data, frame->linesize, 0, frame->height, picture.data, picture.linesize);
    if (h != frame->height)
        goto cleanup;

    sws_freeContext(context);
    if (awpCreateImage(ppImage, frame->width, frame->height, 3, AWP_BYTE) != AWP_OK)
        goto cleanup;

    AWPBYTE* b = (AWPBYTE*)(*ppImage)->pPixels;
    memcpy(b, picture.data[0], line_size*frame->height);

    res = true;

cleanup:
    if (picture.data[0] != NULL)
        free(picture.data[0]);
    return res;
}


/*ooieoey ?oaiey iaeaoia ec aeaaiiioiea 
*/
int read_thread(void* arg);

/*oi?ea iiaee??aiey e ip eaia?a 
*/
class CFFMPEGIpSource
{
private:
	SDL_Thread  *m_video_tid;
	SDL_mutex	*m_mutex;
	bool		 m_quit;
private:
	/*aa?an oaaeaiiie eaia?u 
	*/
	string    m_strHostName; 

	/*ecia?a?aiea, a oiiaoa awp iieo?aiiia io oaaeaiiie eaia?u 
	*/
	awpImage* m_pImage; 
	/*n?ao?ee ?aniaeiaaiiuo eaa?ia 
	*/
	unsigned int n_numFrames; 
	/*ffmpeg variables 
	*/
	AVFormatContext *fmt_ctx;
	AVCodecContext *video_dec_ctx;
	AVFrame *frame;
	int video_stream_idx;
	//int got_frame;
    AVPacket pkt;
	/* ooieoey aaeiae?iaaiey iaeaoia
	*/
	int decode_packet(int *got_frame, int cached);
public: 
	 CFFMPEGIpSource();
	~CFFMPEGIpSource();
	/*iiaee??aaony e oaaeaiiie aeaaieaia?a e caioneaao oeee 
		?oaiey e ia?aaioee ecia?a?aiee 
	*/
	bool Connect(const char* lpHostName);
	/*ioee??iea io oaaeaiiie eaia?u 
	*/
	bool Disconnect();
	/*aica?auaao oaeouaa cia?aiea m_pImage 
	*/
	awpImage* QueryImage();

    /*Thread functions
    */
	int ReadPacketsLoop();
};

/* aey ?oaiey e aaoeo?iaee iaeaoia ec aeaaiiioiea eniieucoaony 
   iaoia ReadPacketsLoop() ec eeanna CFFMPEGIpSource
*/
int read_thread(void* arg)
{
    CFFMPEGIpSource* source = (CFFMPEGIpSource*)arg;
    if (source == NULL)
        return -1;
    /*aeaaiue iioie ?oaiey e aaeiae?iaaiey iaeaoia*/
	return source->ReadPacketsLoop();
}

CFFMPEGIpSource::CFFMPEGIpSource()
{
	m_pImage = NULL;
	m_strHostName = "";
	n_numFrames = 0;
	fmt_ctx = NULL;
	video_dec_ctx = NULL;
	frame = NULL;
	video_stream_idx = -1;
	m_video_tid = NULL;
	m_quit = false;
	m_mutex = SDL_CreateMutex();
    av_register_all();    
	avformat_network_init();
	av_log_set_level(AV_LOG_ERROR);
}

CFFMPEGIpSource::~CFFMPEGIpSource()
{
	Disconnect();
}

bool CFFMPEGIpSource::Connect(const char* lpHostName)
{
	int ret;
	/*inoaiaaeeaaai oaeouaa niaaeiaiea, anee iii nouanoaoao. 
	*/
	if (n_numFrames > 0)
		this->Disconnect();

	if (lpHostName == NULL)
	{
		printf("Host name is invalid.\n");
		return false; 
	}
	/*ioe?uaaai niaaeiaiea n aeaaina?aa?ii  	
	*/
	ret = avformat_open_input(&fmt_ctx, lpHostName, NULL, NULL);
	if (ret < 0 )
	{
		printf("Could not open source %s\n", lpHostName);
		return false;
	}
	/*euai eioi?iaoe? i aeaaiiioieao
	*/
	ret = avformat_find_stream_info(fmt_ctx, NULL) >= 0;
	if (ret < 0)
	{
		printf("Could not find video stream information in the %s\n", lpHostName);
		return false;
	}

	ret = av_find_best_stream(fmt_ctx, AVMEDIA_TYPE_VIDEO, -1, -1, NULL, 0);
	if (ret < 0 )
	{
		printf("Could not find video stream in the %s\n", lpHostName);
		return false;
	}

	video_stream_idx = ret;
    
	AVStream *st;
    AVCodecContext *dec_ctx = NULL;
    AVCodec *dec = NULL;
    AVDictionary *opts = NULL;

	st = fmt_ctx->streams[video_stream_idx];
	dec_ctx = st->codec;
	/*iaeaai aaeiaa?
	*/
	dec = avcodec_find_decoder(dec_ctx->codec_id);
	if (!dec)
	{
		printf("Failed to find video codec\n");
		return false;
	}
	/*iieo?ei eiioaeno eiaaea 
	*/
	ret = avcodec_open2(dec_ctx, dec, &opts);
	if (ret < 0)
	{
		printf("Failed to open video codec\n");
		return false;
	}

	AVStream *video_stream  = fmt_ctx->streams[video_stream_idx];
	video_dec_ctx = video_stream->codec;

#ifdef _DEBUG 
	/* dump input information to stderr */
    av_dump_format(fmt_ctx, 0, lpHostName, 0);
#endif 
	frame = avcodec_alloc_frame();
	/*caioneaai iioie ?oaiey iaeaoia 
	*/
	m_video_tid = SDL_CreateThread(read_thread, this);
	return true;
}

bool CFFMPEGIpSource::Disconnect()
{
	/*?aai inoaiiaee iioiea ?oaiey ec aeaaiiioiea 
	*/
	m_quit = true;
	if (m_video_tid)
	{
		SDL_WaitThread(m_video_tid, NULL);	
		m_video_tid = NULL;
	}
	/*inaiai?aaai eiioaeno ffmpeg
	*/
	avcodec_close(video_dec_ctx);
    avformat_close_input(&fmt_ctx);
	av_frame_free(&frame);
	/*inaiai?aaai aioo?aiiea ia?aiaiiua
	*/
	video_stream_idx = -1;
	awpReleaseImage(&m_pImage);
	m_pImage = NULL;
	m_strHostName = "";
	n_numFrames = 0;
	SDL_DestroyMutex(m_mutex);
	m_quit = false;

	return true;
}

awpImage* CFFMPEGIpSource::QueryImage()
{
	if (m_quit)
		return NULL;
	awpImage* img = NULL;
	int n = this->n_numFrames;
	while(n == this->n_numFrames)
		SDL_Delay(1);
	SDL_LockMutex(m_mutex);
	awpCopyImage(this->m_pImage, &img);
	SDL_UnlockMutex(m_mutex);
	return img;
}

int CFFMPEGIpSource::ReadPacketsLoop()
{
    int ret;
#ifdef _DEBUG
	printf("Enter CFFMPEGIpSource::ReadPacketsLoop()\n");	
#endif 
	/* initialize packet, set data to NULL, let the demuxer fill it */
    av_init_packet(&pkt);
    pkt.data = NULL;
    pkt.size = 0;
	int got_frame =0;
	/* ?eoaai iaeaou ec aeaaiiioiea */
    while (av_read_frame(fmt_ctx, &pkt) >= 0) {
        AVPacket orig_pkt = pkt;
        do {
            ret = decode_packet(&got_frame, 0);
            if (ret < 0)
                break;
            pkt.data += ret;
            pkt.size -= ret;
        } while (pkt.size > 0);
        av_free_packet(&orig_pkt);
		if (m_quit)
			break;
    }

    /* flush cached frames */
    pkt.data = NULL;
    pkt.size = 0;
    do {
        decode_packet(&got_frame, 1);
    } while (got_frame);
#ifdef _DEBUG
	printf("Exit CFFMPEGIpSource::ReadPacketsLoop()\n");
#endif 
	m_quit = true;
	return 0;
}

int CFFMPEGIpSource::decode_packet(int *got_frame, int cached)
{
    int ret = 0;
    int decoded = pkt.size;

    *got_frame = 0;

    if (pkt.stream_index == video_stream_idx) {
        /* decode video frame */
        ret = avcodec_decode_video2(video_dec_ctx, frame, got_frame, &pkt);
        if (ret < 0) {
            fprintf(stderr, "Error decoding video frame (%s)\n", ""/*av_err2str(ret)*/);
            return ret;
        }

        if (*got_frame) {
			n_numFrames++;
        
			//printf("video_frame%s n:%d coded_n:%d pts:%s\n",
             //      cached ? "(cached)" : "",
             //      n_numFrames++, frame->coded_picture_number,
             //      ""/*av_ts2timestr(frame->pts, &video_dec_ctx->time_base)*/);
			
			
			SDL_LockMutex(m_mutex);
			if (this->m_pImage != NULL)
				awpReleaseImage(&this->m_pImage);
			AVFrame2AwpRGBImage(frame, &this->m_pImage);
			SDL_UnlockMutex(m_mutex);
        }
    }

    return decoded;
}

extern "C" AWPIPCAM_API HANDLE awpIpConnect(LPSTR pszFilename)
{

	CFFMPEGIpSource* theSource = NULL;
	theSource = new CFFMPEGIpSource();
	if (theSource == NULL)
		return NULL;
	if (theSource->Connect(pszFilename))
		return (HANDLE)theSource;
	else
	{
		delete theSource;
		return NULL;
	}
}

extern "C" AWPIPCAM_API HRESULT awpIpDisconnect(HANDLE camera)
{
	
	CFFMPEGIpSource* theSource = (CFFMPEGIpSource*)camera;
	if (theSource != NULL)
	{
		theSource->Disconnect();
		return S_OK;
	}

	return E_FAIL;
}

 extern "C" AWPIPCAM_API awpImage* awpIpQueryImage(HANDLE camera)
{
	CFFMPEGIpSource* theSource = (CFFMPEGIpSource*)camera;
	if (theSource != NULL)
		return theSource->QueryImage();
	else
		return NULL;
}

extern "C" AWPIPCAM_API void awpIpFreeImage(awpImage* img)
{
	if (img != NULL)
		awpReleaseImage(&img);
}
