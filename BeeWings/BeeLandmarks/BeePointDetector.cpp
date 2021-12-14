//---------------------------------------------------------------------------
#pragma hdrstop

#include "BeePointDetector.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

TBeePointDector::TBeePointDector(const char* className)
{
   m_strClassName = className;
}

TBeePointDector::~TBeePointDector()
{
}

bool TBeePointDector::Init(const char* lpDetectorName, const char* lpTemplateName)
{
	return m_detector.LoadDetector(lpDetectorName);
}


/**
	LFImage*	img0 - imtegral image 960x540 pixels
*/
bool TBeePointDector::Detect(TLFImage* img0, awp2DPoint& result , awpRect* rect)
{
	if (img0 == NULL || img0->GetImage() == NULL )
		return false;
	awpImage* img = img0->GetImage();
	if (img->sSizeX != 960 || img->sSizeY != 540)
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

	/*ILFScanner* s = m_detector.GetScanner();
	s->Scan(img->sSizeX, img->sSizeY);*/
	m_detector.Init(img, true);
	int count =m_detector.DetectInRect(roi);/// s->GetFragmentsCount();
	//int count =m_detector.Detect();//InRect(roi);/// s->GetFragmentsCount();
	TLFObjectList* strongs = m_detector.GetStrongs();
	double min_ro = 0;
	int min_idx   = -1;
	for (int i = 0; i < count; i++)
	{
		TLFDetectedItem* di = m_detector.GetItem(i);
		awpRect r = di->GetBounds()->GetRect();
		//awpImage* fragment = Preprocess(img, r);
		//if (fragment!= NULL)
		{

			 double ro = di->GetRaiting();
			 //fvcCompare(fragment, m_template, &ro, FVC_COMPARE_EUCLID);

			 if (ro > min_ro)
			 {
				min_ro = ro;
				min_idx = i;
			 }
			//_AWP_SAFE_RELEASE_(fragment)
		}

 /*		awpRect fr = s->GetFragmentRect(i);
		awpPoint c;
		c.X = (fr.left + fr.right) / 2;
		c.Y = (fr.top + fr.bottom) / 2;
		if (c.X >= roi.left && c.X <= roi.right &&
		c.Y >= roi.top && c.Y <= roi.bottom)
		{
			// do detection
			bool detected = true;
			for (int k = 0; k < strongs->GetCount(); k++)
			{
				TCSStrong* s = (TCSStrong*)strongs->Get(k);
				s->Setup(fr, 24);
				double err=0;
				if (s->Classify(img0, err) == 0)
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
		}*/
	}

	if (min_idx < 0)
		return false;

	//
	TLFDetectedItem* di = m_detector.GetItem(min_idx);
	awpRect resultRect = di->GetBounds()->GetRect();;//s->GetFragmentRect(min_idx);

//		result = di->GetBounds()->GetRect();
	awpPoint cp;
	cp.X = (resultRect.left + resultRect.right)/ 2;
	cp.Y = (resultRect.top + resultRect.bottom) / 2;
	result.X = 100.*cp.X / (double)img->sSizeX;
	result.Y = 100.*cp.Y / (double)img->sSizeY;
	return true;
}


const char* TBeePointDector::GetClassName()
{
    return m_strClassName.c_str();
}

