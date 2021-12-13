//---------------------------------------------------------------------------
#pragma hdrstop

#include "BeePointDetector.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

TBeePointDector::TBeePointDector()
{
   m_template = NULL;
}

TBeePointDector::~TBeePointDector()
{
	if (m_template != NULL)
		fvcFreeTemplate(&m_template);
}

bool TBeePointDector::Init(const char* lpDetectorName, const char* lpTemplateName)
{
	if (m_template != NULL)
		fvcFreeTemplate(&m_template);
	if (fvcLoadTemplate(lpTemplateName, &m_template) != FVC_OK)
		return false;
	return m_detector.LoadDetector(lpDetectorName);
}


/**
	LFImage*	img0 - imtegral image 960x540 pixels
*/
bool TBeePointDector::Detect(TLFImage* img0, awp2DPoint& result , awpRect* rect)
{
	if (img0 == NULL || img0->GetImage() == NULL || m_template == NULL)
		return false;
	awpImage* img = img0->GetImage();
	if (img->dwType != AWP_DOUBLE || img->sSizeX != 960 || img->sSizeY != 540)
		return false;
	awpRect roi;
	if (rect == NULL)
	{
		roi.left  = 0;
		roi.right = img->sSizeX;
		roi.top   = 0;
		roi.bottom = img->sSizeY;
	}
	else
		roi = *rect;

	ILFScanner* s = m_detector.GetScanner();
	s->Scan(img->sSizeX, img->sSizeY);
	int count = s->GetFragmentsCount();
	TLFObjectList* strongs = m_detector.GetStrongs();
	double min_ro = 1;
	int min_idx   = -1;
	for (int i = 0; i < count; i++)
	{
		awpRect fr = s->GetFragmentRect(i);
		if (fr.left >= roi.left && fr.right <= roi.right &&
		fr.top >= roi.top && fr.bottom <= roi.bottom)
		{
			// do detection
			bool detected = true;
			for (int k = 0; k < strongs->GetCount(); k++)
			{
				TCSStrong* s = (TCSStrong*)strongs->Get(k);
				s->Setup(fr, 48);
				double err=0;
				if (!s->Classify(img0, err))
				{
					detected = false;
					break;
				}
			}
			if (detected)
			{
				awpImage* fragment = Preprocess(img, fr);
				if (fragment!= NULL)
				{

					 double ro = 1;
					 fvcCompare(fragment, m_template, &ro, FVC_COMPARE_EUCLID);
					 if (ro < min_ro)
					 {
						min_ro = ro;
						min_idx = i;
					 }
					_AWP_SAFE_RELEASE_(fragment)
				}
			}
		}
	}

	if (min_idx < 0)
		return false;

	//
	awpRect resultRect = s->GetFragmentRect(min_idx);
	awpPoint cp;
	cp.X = (resultRect.left + resultRect.right)/ 2;
	cp.Y = (resultRect.top + resultRect.bottom) / 2;
	result.X = 100.*cp.X / (double)img->sSizeX;
    result.Y = 100.*cp.Y / (double)img->sSizeY;
	return true;
}

awpImage* TBeePointDector::Preprocess(awpImage* img, awpRect& r)
{
	awpImage* result = NULL;
	if (awpCopyRect(img, &result, &r) != AWP_OK)
		return NULL;
	if (awpConvert(result, AWP_CONVERT_3TO1_BYTE) != AWP_OK)
	{
		_AWP_SAFE_RELEASE_(result)
		return NULL;
	}
	awpImage* norm = NULL;
	if (awpNormalize(result, &norm, AWP_NORM_L2) != AWP_OK)
	{
		_AWP_SAFE_RELEASE_(result)
		return NULL;
	}
	if (awpConvert(norm, AWP_CONVERT_TO_FLOAT) != AWP_OK)
	{
		_AWP_SAFE_RELEASE_(result)
		_AWP_SAFE_RELEASE_(norm)
		return NULL;
	}
	_AWP_SAFE_RELEASE_(result)
	return norm;
}
