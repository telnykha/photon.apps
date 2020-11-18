// test_awpipcam.cpp : Defines the entry point for the console application.
//rtsp://admin:12345@192.168.1.103/mjpeg/ch1/sub/av_stream

#include "opencv\cv.h"
#include "opencv\highgui.h"
#include "..\..\..\..\Modules\_ipcam\module\awpipcam\awpipcam.h"
#include "package.h"
#include "vautils.h"

extern "C"
{
	#pragma comment(lib, "opencv_world300.lib")
}
int awpImageDepthToCvDepth(awpImage* src)
{
    switch(src->dwType)
    {
        case AWP_BYTE:
            return IPL_DEPTH_8U;
        case AWP_SHORT:
            return IPL_DEPTH_8S;
        case AWP_FLOAT:
            return IPL_DEPTH_32F;
		case AWP_DOUBLE:
			return 64;
        default:
            return -1;
    }
}

//converts awpImage.awpType to openCV depth
//in the error case returns -1
static int awpCvDepthToImageDepth(IplImage* src)
{
    switch(src->depth)
    {
        case IPL_DEPTH_8U:
            return AWP_BYTE;
        case IPL_DEPTH_8S:
            return AWP_SHORT;
        case IPL_DEPTH_32F:
            return AWP_FLOAT;
		case 64:
			return AWP_DOUBLE;
        default:
            return -1;
    }
}
//returns line width of awpImage in BYTES
//in the error case returns -1
static int awpWidthStep(awpImage* src)
{
    int c = src->bChannels*src->sSizeX;
    switch(src->dwType)
    {
        case AWP_BYTE:
            return c*sizeof(AWPBYTE);
        case AWP_SHORT:
            return c*sizeof(short);
        case AWP_FLOAT:
            return c*sizeof(float);
		case AWP_DOUBLE:
			return c*sizeof(double);
        default:
            return -1;
    }
}
// awp to openCV image convertion
IplImage* awpConvertToIplImage(awpImage* src)
{
  IplImage* result = NULL;
  if (src == NULL)
    return result;
  CvSize size;
  if (awpCheckImage(src) != AWP_OK)
    return result;
  size.width  = src->sSizeX;
  size.height = src->sSizeY;
  int depth = awpImageDepthToCvDepth(src);
  if (depth == -1)
    return result;
  int awpStep = awpWidthStep(src);
  if (awpStep == -1)
    return result;
  result = cvCreateImage(size, depth, src->bChannels);
  if (result == NULL)
    return result;
  // copy image pixels
  AWPBYTE* awp = (AWPBYTE*)src->pPixels;
  AWPBYTE* ipl = (AWPBYTE*)result->imageData;

  int iplStep = result->widthStep;
  for (int i = 0; i < src->sSizeY; i++)
  {
    memcpy(ipl,awp, awpStep);
    ipl += iplStep;
    awp += awpStep;
  }
  return result;
}

int main(int argc, char* argv[])
{
	awpImage* frame = NULL;
	IplImage* iplFrame = NULL;
	HANDLE camera = awpIpConnect(argv[1]);
	CvVideoWriter* writer = NULL;
	double _img_width;
	double _img_height;
	double _alfa;

	if (camera != NULL)
	{
		for(;;)
		{

			frame = awpIpQueryImage(camera);
			if (frame == NULL)
				break;
			iplFrame = awpConvertToIplImage(frame);
			if (iplFrame)
			{

				_img_width = iplFrame->width;
				_img_height = iplFrame->height;
				_alfa = 640. / _img_width;

				IplImage* si = cvCreateImage(cvSize(640, floor(_alfa*_img_height + 0.5)), IPL_DEPTH_8U, 3);


				if (iplFrame != NULL && writer == NULL)
				{			
					writer = cvCreateVideoWriter("out.avi", CV_FOURCC('D', 'I', 'V', 'X'), 20, cvSize(640, floor(_alfa*_img_height + 0.5)));
					if (writer == NULL)
					{
						printf("cannot create writer!\n");
						return -1;
					}
				}

				cvShowImage("test", iplFrame);
				if (writer != NULL)
				{
					cvResize(iplFrame, si);
					cvWriteFrame(writer, si);
				}
						
				cvReleaseImage(&si);
				cvReleaseImage(&iplFrame);
			}
			awpIpFreeImage(frame);
			int c;
			c = cvWaitKey(10);
			if ((char)c == 27)
				break;	
		}
		awpIpDisconnect(camera);
		if (writer != NULL)
			cvReleaseVideoWriter(&writer);
	}
	return 0;
}

