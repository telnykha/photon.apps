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

const awp2DPoint points[8] =
{
{26.630311, 29.036995},
{79.292189,27.278273},
{49.054636,33.093616},
{35.557874,35.099718},
{50,50},
{57.519525,55.686925},
{61.804425,54.376162},
{50,75}
};

void _findPoints(awp2DPoint p4, awp2DPoint p7, awp2DPoint* out)
{

	double L0  = sqrt((p4.X - p7.X)*(p4.X - p7.X) + (p4.Y - p7.Y)*(p4.Y - p7.Y));
	double L1  = sqrt((points[4].X - points[7].X)*(points[4].X - points[7].X) + (points[4].Y - points[7].Y)*(points[4].Y - points[7].Y));
	double alfa = L0 / L1;
	double tanfi = (p7.X - p4.X) / (p7.Y - p4.Y);
	double fi = atan(tanfi);

	double sinfi = sin(fi);
	double cosfi = cos(fi);

	awpImage* mtx = NULL;
	awpImage* imtx = NULL;
	awpCreateImage(&mtx, 2,2,1,AWP_DOUBLE);
	awpCreateImage(&imtx, 2,2,1,AWP_DOUBLE);
	double* pmtx = (double*)mtx->pPixels;

	pmtx[0] = cosfi;
	pmtx[1] = -sinfi;
	pmtx[2] = sinfi;
	pmtx[3] = cosfi;

	awpMatrixInvert(mtx, imtx);
	double* pimtx = (double*)imtx->pPixels;
	for (int i = 0; i < 8; i++) {
		awpImage* dst = NULL;
		awpImage* src = NULL;
		awpCreateImage(&src, 1,2,1,AWP_DOUBLE);
		double* psrc = (double*)src->pPixels;
		psrc[0] = points[i].X - points[4].X;
		psrc[1] = points[i].Y - points[4].Y;
		awpMulMatrix(imtx, src, &dst);
		double* pdst = (double*)dst->pPixels;
		out[i].X = pdst[0];
		out[i].Y = pdst[1];
		awp2DPoint p;

		out[i].X = alfa*out[i].X;
		out[i].Y = alfa*out[i].Y;
		out[i].X += p4.X;
		out[i].Y += p4.Y;
/*
		awp2DPoint lt;
		awp2DPoint rb;
		double radiusx = 7;
		double radiusy = ((double)w/(double)h)*radiusx;

		lt.X = p.X - radiusx;
		lt.Y = p.Y - radiusy;
		rb.X = p.X + radiusx;
		rb.Y = p.Y + radiusy;

		TRect srcRect;
		srcRect.Left = w*lt.X / 100;
		srcRect.top  = h*lt.Y / 100;
		srcRect.bottom = h*rb.Y / 100;
		srcRect.right = w*rb.X / 100;
		double rx = 0.5;
		if (i == 4 || i == 7) {
			rx = 2;
		}

		DrawCross(p, Canvas, rx);

		p.X = w*p.X / 100.;
		p.Y = h*p.Y / 100.;

		awpReleaseImage(&dst);



		TRect rr = m_pImage->GetScreenRect(srcRect);
		Canvas->Ellipse(rr);
*/
	}

	awpReleaseImage(&mtx);
	awpReleaseImage(&imtx);
}

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

		// поиск областей интереса
		awp2DPoint p4;
		awp2DPoint p7;
		awp2DPoint out[8];

		p4.X = 50.*(r5.left + r5.right) / (double)img.GetImage()->sSizeX;
		p4.Y = 50.*(r5.top + r5.bottom) / (double)img.GetImage()->sSizeY;

		p7.X = 50.*(r8.left + r8.right) / (double)img.GetImage()->sSizeX;
		p7.Y = 50.*(r8.top + r8.bottom) / (double)img.GetImage()->sSizeY;

		_findPoints(p4,p7, out);

		int w = img.GetImage()->sSizeX;
		int h = img.GetImage()->sSizeY;

		for (int i = 0; i < 8; i++)
		{
			if (i == 4 || i == 7)
				continue;

			awpRect r;
			r.left   = w*out[i].X / 100 - 64;
			r.right  = w*out[i].X / 100 + 64;
			r.top    = h*out[i].Y / 100 - 64;
			r.bottom = h*out[i].Y / 100 + 64;

			awpDrawRect(img.GetImage(), &r, 0,255, 2);
		}


		img.SaveToFile("out.jpg");
	}
	else
		printf("Object not found.\n");




	fvcFreeTemplate(&tmpl5);
	fvcFreeTemplate(&tmpl8);
	return 0;
}
