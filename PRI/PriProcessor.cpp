//---------------------------------------------------------------------------

#pragma hdrstop

#include "PriProcessor.h"
#include "PriCalibration.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

TPriProcessor::TPriProcessor()
{
    m_dx = -4;
    m_dy = -8;
	m_scale = 1.023;
	m_blurMode = modeBlurMore;
}

TPriProcessor::~TPriProcessor()
{

}

bool __fastcall TPriProcessor::FilterImage(awpImage* image)
{
	if (image == NULL)
		return false;
	if (m_blurMode == modeNone)
		return true;
	awpImage* tmp = NULL;
	if (awpCopyImage(image, &tmp) != AWP_OK)
	{
		return false;
	}
	int mask = m_blurMode == modeBlur ?  AWP_BLUR: AWP_BLUR_MORE;
	if (awpFilter(image, tmp, mask) != AWP_OK)
	{
	   _AWP_SAFE_RELEASE_(tmp)
	   return false;
	}
	if (awpCopyImage(tmp, &image) != AWP_OK)
	{
	   _AWP_SAFE_RELEASE_(tmp)
	   return false;
	}
   _AWP_SAFE_RELEASE_(tmp)
	return true;
}

//
// на вход поступают два изображения с вычтенным фоном.
// все входные изображения имеют тип AWP_FLOAT
//  изображение im531 - получено через фильтр 531 nm со вспышкой
// изображение img531b - получено через фильтр 531 nm без вспышки
//  изображение im570 - получено через фильтр 570 nm со вспышкой
// изображение img570b - получено через фильтр 570 nm без вспышки
bool __fastcall TPriProcessor::PriProcessImages(awpImage* img531, awpImage* img570, awpImage* img531b, awpImage* img570b)
{
   // проверка аргументов
   if (img531 == NULL || img570 == NULL)
    return false;
   // изображения должны иметь одинаковые параметры.
   //if (img531->dwType != AWP_DOUBLE || img570->dwType != AWP_DOUBLE ||
   //img531->sSizeX != img570->sSizeX || img531->sSizeY != img570->sSizeY ||
   //img531->bChannels != img570->bChannels)
   // return false;

   // вырезаем фрагменты изображения в соответствии с параметрами калибровки.
   awpRect r;
   r.left   = BORDER_SIZE;
   r.top    = BORDER_SIZE;
   r.right  = img531->sSizeX - BORDER_SIZE;
   r.bottom = img531->sSizeY - BORDER_SIZE;

   awpImage* i531 = NULL;
   awpImage* i570 = NULL;
   awpImage* i531b = NULL;
   awpImage* i570b = NULL;

   AWPRESULT res = AWP_OK;

   res = awpCopyRect(img531, &i531, &r);
   if (res != AWP_OK)
    return false;

   res = awpCopyRect(img531b, &i531b, &r);
   if (res != AWP_OK)
   {
    _AWP_SAFE_RELEASE_(i531)
    return false;
   }


   double rw = (double)(r.right  - r.left);
   double rh = (double)(r.bottom - r.top);

   r.left += m_dx;
   r.top  += m_dy;

   r.right   = r.left + (short)(m_scale*rw);
   r.bottom  = r.top  + (short)(m_scale*rh);

   res = awpCopyRect(img570, &i570, &r);
   if (res != AWP_OK)
   {
    _AWP_SAFE_RELEASE_(i531)
    _AWP_SAFE_RELEASE_(i531b)
    return false;
   }

   res = awpCopyRect(img570b, &i570b, &r);
   if (res != AWP_OK)
   {
    _AWP_SAFE_RELEASE_(i531)
    _AWP_SAFE_RELEASE_(i531b)
    _AWP_SAFE_RELEASE_(i570)
    return false;
   }

   res = awpResize(i570, i531->sSizeX, i531->sSizeY);
   if (res != AWP_OK)
   {
    _AWP_SAFE_RELEASE_(i531)
    _AWP_SAFE_RELEASE_(i531b)
    _AWP_SAFE_RELEASE_(i570)
	_AWP_SAFE_RELEASE_(i570b)
    return false;
   }

   res = awpResize(i570b, i531->sSizeX, i531->sSizeY);
   if (res != AWP_OK)
   {
    _AWP_SAFE_RELEASE_(i531)
    _AWP_SAFE_RELEASE_(i531b)
    _AWP_SAFE_RELEASE_(i570)
    _AWP_SAFE_RELEASE_(i570b)
    return false;
   }

   awpImage* sub570 = NULL;
   awpImage* sub531 = NULL;
   awpImage* sum = NULL;
   awpImage* sub = NULL;
   awpImage* _pri = NULL;

   // фильтрация изображений
   FilterImage(i570);
   FilterImage(i570b);
   FilterImage(i531);
   FilterImage(i531b);

   // ввычитание фона
   awpCalcImage(i570, i570b, &sub570, AWP_CALC_SUBIMAGES, AWP_CALC_OUTPLACE);
   awpCalcImage(i531, i531b, &sub531, AWP_CALC_SUBIMAGES, AWP_CALC_OUTPLACE);

    // вычитаем одно изображение из другого
    res = awpCalcImage(sub531, sub570, &sub, AWP_CALC_SUBIMAGES, AWP_CALC_OUTPLACE);
    if (res != AWP_OK)
    {
        _AWP_SAFE_RELEASE_(i531)
        _AWP_SAFE_RELEASE_(i531b)
        _AWP_SAFE_RELEASE_(i570)
        _AWP_SAFE_RELEASE_(i570b)
        return false;
    }
    // складываем два изображения
    res = awpCalcImage(sub531, sub570, &sum, AWP_CALC_ADDIMAGES, AWP_CALC_OUTPLACE);
    if (res != AWP_OK)
    {
        _AWP_SAFE_RELEASE_(i531)
        _AWP_SAFE_RELEASE_(i531b)
        _AWP_SAFE_RELEASE_(i570)
        _AWP_SAFE_RELEASE_(i570b)
        _AWP_SAFE_RELEASE_(sub)
        return false;
    }

    res = awpCalcImage(sub, sum, &_pri, AWP_CALC_DIVIMAGES, AWP_CALC_OUTPLACE);
    if (res != AWP_OK)
    {
        _AWP_SAFE_RELEASE_(i531)
        _AWP_SAFE_RELEASE_(i531b)
        _AWP_SAFE_RELEASE_(i570)
        _AWP_SAFE_RELEASE_(i570b)
        _AWP_SAFE_RELEASE_(sub)
	    _AWP_SAFE_RELEASE_(sum)
        return false;
    }
    AWPDOUBLE* p = (AWPDOUBLE*)_pri->pPixels;
    for (int i = 0; i < _pri->sSizeX*_pri->sSizeY; i++)
    {
        p[i] = p[i] < -1 ? -1 : p[i];
        p[i] = p[i] > 1 ? 1: p[i];
    }

    awpConvert(i570, AWP_CONVERT_TO_FLOAT);
    awpConvert(i570b, AWP_CONVERT_TO_FLOAT);
    awpConvert(i531, AWP_CONVERT_TO_FLOAT);
    awpConvert(i531b, AWP_CONVERT_TO_FLOAT);

    m_pri.SetImage(_pri);
    m_570.SetImage(i570);
    m_570b.SetImage(i570b);
    m_531.SetImage(i531);
    m_531b.SetImage(i531b);

    _AWP_SAFE_RELEASE_(i531)
    _AWP_SAFE_RELEASE_(i531b)
	_AWP_SAFE_RELEASE_(i570)
    _AWP_SAFE_RELEASE_(i570b)
    _AWP_SAFE_RELEASE_(sub)
    _AWP_SAFE_RELEASE_(sum)
    _AWP_SAFE_RELEASE_(_pri)
    _AWP_SAFE_RELEASE_(sub570)
    _AWP_SAFE_RELEASE_(sub531)

    return true;
}
// PRI индекс
awpImage* TPriProcessor::GetPri()
{
    return m_pri.GetImage();
}

awpImage* TPriProcessor::Get_570()
{
    return m_570.GetImage();
}

awpImage* TPriProcessor::Get_570b()
{
    return m_570b.GetImage();
}
awpImage* TPriProcessor::Get_531()
{
    return m_531.GetImage();
}

awpImage* TPriProcessor::Get_531b()
{
    return m_531b.GetImage();
}

