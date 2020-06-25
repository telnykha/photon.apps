//---------------------------------------------------------------------------
#ifndef PriProcessorH
#define PriProcessorH
//---------------------------------------------------------------------------
#include "_LF.h"
#include "PriSpatialCalibrationUnit.h"
#define BORDER_SIZE 30
typedef enum {modeNone, modeBlur, modeBlurMore} EPriBlurMode;
 class TPriCalibration;
class TPriProcessor
{
protected:
	TPriSpatialCalibration m_calibration;
	EPriBlurMode m_blurMode;
	bool m_needCalibration;
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
	TPriSpatialCalibration* __fastcall GetCalibration();
public:
	TPriProcessor();
	~TPriProcessor();
	// инициализация калибровки
	bool __fastcall InitCalibration(UnicodeString path);
	// на вход поступают два изображения с вычтенным фоном.
	bool __fastcall PriProcessImages(awpImage* img531, awpImage* img570, awpImage* img531b, awpImage* img570b);

	TPriCalibration* m_calibr;

    // результат вычислений.
    __property awpImage* pri    = {read = GetPri};
    __property awpImage* _570   = {read = Get_570};
    __property awpImage* _570b  = {read = Get_570b};
    __property awpImage* _531   = {read = Get_531};
	__property awpImage* _531b  = {read = Get_531b};
	// свойства алгоритма
	__property EPriBlurMode blurMode = {read = m_blurMode, write = m_blurMode};
	__property bool needCalibration = {read = m_needCalibration, write = m_needCalibration};
	__property TPriSpatialCalibration* Calibration = {read = GetCalibration};
};
#endif
