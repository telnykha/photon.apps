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

bool _detect(TSCObjectDetector& d, FvcTemplate* t, awpImage* img, awpRect& result)
{
	awpResize(img, 960, 540);
	d.Init(img, true);

	int num = 0;
	if (num = d.Detect())
			printf("num detected %d fragments %d \n ", num, d.GetScanner()->GetFragmentsCount());
	if (num == 0)
		return false;

	double min_ro = 1;
	int min_idx = -1;
	for (int i = 0; i < num; i++)
	{
		TLFDetectedItem* di = d.GetItem(i);
		awpRect r = di->GetBounds()->GetRect();
		awpImage* fragment = _preprocess(img, r);
		if (fragment!= NULL)
		{

			 double ro = 1;
			 fvcCompare(fragment, t, &ro, FVC_COMPARE_EUCLID);
			 if (ro < min_ro)
			 {
				min_ro = ro;
				min_idx = i;
			 }
			_AWP_SAFE_RELEASE_(fragment)
		}

	}
	if (min_idx >= 0)
	{
		TLFDetectedItem* di = d.GetItem(min_idx);
		result = di->GetBounds()->GetRect();
	 //	awpDrawCross(img.GetImage(), &r, 1, 255, 1);
	}
	printf ("index =  %d ro = %lf\n", min_idx, min_ro);
	return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
	printf("beedetect.\n");

	FvcTemplate* tmpl5 = NULL;
	FvcTemplate* tmpl8 = NULL;
	if (fvcLoadTemplate("tmplAWP5.fvc", &tmpl5) != FVC_OK)
	{
		printf("error: cannot load template.\n");
		return 1;
	}
	if (fvcLoadTemplate("tmplAWP8.fvc", &tmpl8) != FVC_OK)
	{
		printf("error: cannot load template.\n");
		return 1;
	}

	TSCObjectDetector detector5;
	TSCObjectDetector detector8;

	if (!detector5.LoadDetector("test5.xml"))
	{
		printf("cannot load detector.\n");
		return 0;
	}

	if (!detector8.LoadDetector("test8.xml"))
	{
		printf("cannot load detector.\n");
		return 0;
	}

	TLFImage img;
	img.LoadFromFile(argv[1]);
	awpRect r5;
	awpRect r8;
	if (_detect(detector5, tmpl5, img.GetImage(), r5) &&
	_detect(detector8, tmpl8, img.GetImage(), r8))
	{
		awpDrawCross(img.GetImage(), &r5, 1, 255, 1);
		awpDrawCross(img.GetImage(), &r8, 1, 255, 1);

		img.SaveToFile("out.jpg");
	}
	else
		printf("Object not found.\n");


	fvcFreeTemplate(&tmpl5);
	fvcFreeTemplate(&tmpl8);
	return 0;
}
