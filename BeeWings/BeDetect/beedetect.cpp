#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif



#include <stdio.h>
#include "_LF.h"
#include "fvlcore.h"

extern "C"
{
	#pragma link "awpipl2b.lib"
	#pragma link "JPEGLIB.lib"
}
#pragma link "awplflibb.lib"
#pragma link "tinyxml.lib"


awpImage* _preprocess(awpImage* img, awpRect& r)
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

int _tmain(int argc, _TCHAR* argv[])
{
	printf("beedetect.\n");

	FvcTemplate* tmpl = NULL;
	if (fvcLoadTemplate("tmplAWP5.fvc", &tmpl) != FVC_OK)
	{
		printf("error: cannot load template.\n");
		return 1;
	}

	TSCObjectDetector detector;
	if (!detector.LoadDetector("test5.xml"))
	{
		printf("cannot load detector.\n");
		return 0;
	}

	TLFImage img;
	img.LoadFromFile(argv[1]);
	awpResize(img.GetImage(), 960, 540);
	detector.Init(img.GetImage(), true);
	int num = 0;
	if (num = detector.Detect())
			printf("num detected %d fragments %d \n ", num, detector.GetScanner()->GetFragmentsCount());
	double min_ro = 1;
	int min_idx = -1;
	for (int i = 0; i < num; i++)
	{
		TLFDetectedItem* di = detector.GetItem(i);
		awpRect r = di->GetBounds()->GetRect();
  //		awpDrawRect(img.GetImage(), &r, 1, 255, 1);
		awpImage* fragment = _preprocess(img.GetImage(), r);
		if (fragment!= NULL)
		{

			 double ro = 1;
			 fvcCompare(fragment, tmpl, &ro, FVC_COMPARE_EUCLID);
			 if (ro < min_ro)
			 {
				min_ro = ro;
				min_idx = i;
			 }
			_AWP_SAFE_RELEASE_(fragment)
		}

	}

	printf ("index =  %d ro = %lf\n", min_idx, min_ro);
	if (min_idx >= 0)
	{
		TLFDetectedItem* di = detector.GetItem(min_idx);
		awpRect r = di->GetBounds()->GetRect();
		awpDrawRect(img.GetImage(), &r, 1, 255, 1);
	}

	img.SaveToFile("out.jpg");

	fvcFreeTemplate(&tmpl);
	return 0;
}
