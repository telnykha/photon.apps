//---------------------------------------------------------------------------
#ifndef PriProcessorH
#define PriProcessorH
//---------------------------------------------------------------------------
#include "_LF.h"
#define BORDER_SIZE 30
typedef enum {modeNone, modeBlur, modeBlurMore} EPriBlurMode;
class TPriProcessor
{
protected:
    // параметры алгоритма
    int m_dx;
    int m_dy;
	double m_scale;
	EPriBlurMode m_blurMode;
    // результат работы алгоритма
    TLFImage m_pri;
    TLFImage m_570;
    TLFImage m_531;
    TLFImage m_570b;
    TLFImage m_531b;

    awpImage* GetPri();
    awpImage* Get_570();
    awpImage* Get_570b();
    awpImage* Get_531();
    awpImage* Get_531b();
	bool __fastcall FilterImage(awpImage* image);
public:
	TPriProcessor();
    ~TPriProcessor();
    // на вход поступают два изображения с вычтенным фоном.
    bool __fastcall PriProcessImages(awpImage* img531, awpImage* img570, awpImage* img531b, awpImage* img570b);

    // результат вычислений.
    __property awpImage* pri    = {read = GetPri};
    __property awpImage* _570   = {read = Get_570};
    __property awpImage* _570b  = {read = Get_570b};
    __property awpImage* _531   = {read = Get_531};
    __property awpImage* _531b  = {read = Get_531b};

    // свойства алгоритма
    __property int dX = {read = m_dx, write = m_dx};
    __property int dY = {read = m_dy, write = m_dy};
	__property double Scale = {read = m_scale, write = m_scale};
	__property EPriBlurMode blurMode = {read = m_blurMode, write = m_blurMode};
};
#endif
