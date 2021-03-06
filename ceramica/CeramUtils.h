//---------------------------------------------------------------------------
#ifndef CeramUtilsH
#define CeramUtilsH
#include "awpipl.h"
#include "_LF.h"


//---------------------------------------------------------------------------

////////////////////////////////////////
class TCeramCalibration
{
protected:
	double m_alfa;
public:
	TCeramCalibration();
	TCeramCalibration(double alfa);
	TCeramCalibration(double lenght_pix, double lenght_mm);

    ~TCeramCalibration();
    void __fastcall Init(double lenght_pix, double lenght_mm);
    double __fastcall ValueMM(double value);
    int __fastcall ValuePix(double value_mm);

    __property double alfa = {read = m_alfa, write = m_alfa};
};

class TCeramImageProcessor
{
private:
    awpPoint m_oldc;
    int      m_oldr;
    TLFBuffer* m_bx;
    TLFBuffer* m_by;
    TLFBuffer* m_bd;
    int        m_count;

    bool       m_useBuffer;
    int        m_bufferSize;
protected:
    bool       m_useAprox;
    awpImage*   m_process;
    awpImage*   m_copy;
    awp2DPoint  m_center;
    double    m_angle;
    double    m_diam;
    double    m_major;
    double    m_minor;
    awpImage* m_mask;
    awpContour* m_contour;
    int       m_mask_radius;
    awpPoint  m_mask_center;
    bool      m_acceptable;

    void __fastcall CreateMask(awpPoint p, double r, int w, int h);
    void __fastcall MakeMaskImage();
    void __fastcall ProcessHelper();
    void __fastcall Analysis();
    bool __fastcall FindCircle(awpImage* img, int &r, awpPoint &p);
    void __fastcall SetUseBuffer(bool value);
    void __fastcall SetBufferSize(int value);
    int  __fastcall GetBufferSize();

    bool __fastcall CheckAcceptable(awpImage* image);
public:
    TCeramImageProcessor();
    ~TCeramImageProcessor();

    bool __fastcall Process(awpImage* img);
    void __fastcall Reset();

    __property awpImage* source = {read = m_copy};
    __property awp2DPoint center = {read = m_center};
    __property awpImage* mask   = {read = m_mask};
    __property awpImage* process  = {read = m_process};
    __property double    diam   = {read = m_diam};
    __property double    angle  = {read = m_angle};
    __property double    major  = {read = m_major};
    __property double    minor  = {read = m_minor};
    __property awpContour*    contour = {read = m_contour};

    // ����������� ���������.
    __property bool useBuffer   = {read = m_useBuffer, write = SetUseBuffer};
    __property int  bufferSize  = {read = GetBufferSize, write = SetBufferSize};
    __property bool useAprox    = {read = m_useAprox, write = m_useAprox};
    __property int  maskRadius  = {read = m_mask_radius, write = m_mask_radius};
    __property awpPoint maskCener = {read = m_mask_center, write = m_mask_center};
    __property bool acceptable = {read = m_acceptable};
};
#endif
