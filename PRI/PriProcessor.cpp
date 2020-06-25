//---------------------------------------------------------------------------

#pragma hdrstop

#include "PriProcessor.h"
#include "PriCalibration.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

TPriProcessor::TPriProcessor()
{
	m_blurMode = modeBlurMore;
	m_needCalibration = true;
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

   AWPRESULT res = AWP_OK;
   awpImage* i531 = NULL;
   awpImage* i531b = NULL;
   awpImage* i570 = NULL;
   awpImage* i570b = NULL;

   awpCopyImage(img531, &i531);
   awpCopyImage(img531b, &i531b);
   if (m_needCalibration) {
	   i570 = m_calibration.invTransform(img570);
	   i570b = m_calibration.invTransform(img570b);
   }
   else
   {
	   awpCopyImage(img570, &i570);
	   awpCopyImage(img570b, &i570b);
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

bool __fastcall TPriProcessor::InitCalibration(UnicodeString path)
{
	return m_calibration.LoadCalibration(path);
}


TPriSpatialCalibration* __fastcall TPriProcessor::GetCalibration()
{
	return    &m_calibration;
}
