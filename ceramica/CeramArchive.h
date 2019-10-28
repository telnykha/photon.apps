//---------------------------------------------------------------------------
#ifndef CeramArchiveH
#define CeramArchiveH
#include <string>
#include <stdio.h>
//---------------------------------------------------------------------------
typedef struct tagTCeramArchiveRecord
{
    std::string time_stamp;
    std::string image_file;
    float diam;
    float xpos;
    float ypos;
    float mi;
    float ma;
    float angle;
    awpImage* img;
    int acceptable;
}TCeramArchiveRecord;

typedef struct tagTCeramArchiveHeader
{
    float alfa; // чило пискселей в одном миллиметре
    int   bufferSize; // размер буфера
    int   dutyRatio;  // скважность
    int   exposure;   // экспозиция
}TCeramArchiveHeader;

class TCeramArchive
{
protected:
    std::string m_path;
    std::string m_archive;
	FILE* m_pLog;
    int m_counter;
    bool m_bmpFormat;
public:
    TCeramArchive(const char* path);
    ~TCeramArchive();
    bool Create(TCeramArchiveHeader& header);
    void Close();
    bool AddRecord(TCeramArchiveRecord& record);
    __property bool bmpFormat = {read = m_bmpFormat, write = m_bmpFormat};
};
#endif
