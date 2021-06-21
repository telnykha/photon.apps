//---------------------------------------------------------------------------

#pragma hdrstop

#include "pamImageProcessor.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

TPam2ImageProcessor::TPam2ImageProcessor()
{
}


awpImage* TPam2ImageProcessor::GetFo()
{
	awpImage* result = NULL;
	awpCopyImage(m_FoFm.Frame0, &result);
	return result;
}
awpImage* TPam2ImageProcessor::GetFm()
{
	awpImage* result = NULL;
	awpCopyImage(m_FoFm.Frame1, &result);
	return result;
}
awpImage* TPam2ImageProcessor::GetFt()
{
	awpImage* result = NULL;
	awpCopyImage(m_FtFm1.Frame0, &result);
	return result;
}
awpImage* TPam2ImageProcessor::GetFm1()
{
	awpImage* result = NULL;
	awpCopyImage(m_FtFm1.Frame1, &result);
	return result;
}
awpImage* TPam2ImageProcessor::GetFv()
{
	awpImage* result = NULL;

	awpImage* Fo = m_FoFm.Frame0;
	awpImage* Fm = m_FoFm.Frame1;

	awpCreateImage(&result, Fo->sSizeX, Fo->sSizeY, 1, AWP_FLOAT);

	AWPFLOAT* _Fo = (AWPFLOAT*)Fo->pPixels;
	AWPFLOAT* _Fm = (AWPFLOAT*)Fm->pPixels;
	AWPFLOAT* _result = (AWPFLOAT*)result->pPixels;

	for (int i = 0; i < Fo->sSizeX*Fo->sSizeY; i++) {
		_result[i] = _Fm[i] - _Fo[i];
	}

	return result;
}
awpImage* TPam2ImageProcessor::GetFv1()
{
	awpImage* result = NULL;

	awpImage* Fo = this->GetFo1();
	awpImage* Fm = m_FtFm1.Frame1;

	awpCreateImage(&result, Fo->sSizeX, Fo->sSizeY, 1, AWP_FLOAT);

	AWPFLOAT* _Fo = (AWPFLOAT*)Fo->pPixels;
	AWPFLOAT* _Fm = (AWPFLOAT*)Fm->pPixels;
	AWPFLOAT* _result = (AWPFLOAT*)result->pPixels;

	for (int i = 0; i < Fo->sSizeX*Fo->sSizeY; i++) {
		_result[i] = _Fm[i] - _Fo[i];
	}
	awpReleaseImage(&Fo);
	return result;
}
awpImage* TPam2ImageProcessor::GetFq1()
{
	awpImage* result = NULL;

	awpImage* Ft = m_FtFm1.Frame0;
	awpImage* Fm1 = m_FtFm1.Frame1;

	awpCreateImage(&result, Ft->sSizeX, Ft->sSizeY, 1, AWP_FLOAT);

	AWPFLOAT* _Ft = (AWPFLOAT*)Ft->pPixels;
	AWPFLOAT* _Fm1 = (AWPFLOAT*)Fm1->pPixels;
	AWPFLOAT* _result = (AWPFLOAT*)result->pPixels;

	for (int i = 0; i < Ft->sSizeX*Ft->sSizeY; i++) {
		_result[i] = _Fm1[i] - _Ft[i];
	}

	return result;
}
awpImage* TPam2ImageProcessor::GetFo1()
{
	awpImage* result = NULL;

	awpImage* Fo = m_FoFm.Frame0;
	awpImage* Fm = m_FoFm.Frame1;
	awpImage* Fm1 = m_FtFm1.Frame1;
	awpImage* Fv  = this->GetFv();

	awpCreateImage(&result, Fo->sSizeX, Fo->sSizeY, 1, AWP_FLOAT);

	AWPFLOAT* _Fo = (AWPFLOAT*)Fo->pPixels;
	AWPFLOAT* _Fm = (AWPFLOAT*)Fm->pPixels;
	AWPFLOAT* _Fm1 = (AWPFLOAT*)Fm1->pPixels;
	AWPFLOAT* _Fv = (AWPFLOAT*)Fv->pPixels;

	AWPFLOAT* _result = (AWPFLOAT*)result->pPixels;


	for (int i = 0; i < Fo->sSizeX*Fo->sSizeY; i++) {
		float a = _Fv[i] / (_Fm[i]);
		float b = _Fo[i] / (_Fm1[i]);
		float c = a + b;
		if (fabs(c) < 1) {
			c = 1;
		}
		_result[i] = _Fo[i] /c;
	}
	awpReleaseImage(&Fv);
	return result;
}
awpImage* TPam2ImageProcessor::GetFvFm1()
{
	awpImage* result = NULL;

	awpImage* Fv1 = this->GetFv1();
	awpImage* Fm1 = m_FtFm1.Frame1;

	awpCreateImage(&result, Fv1->sSizeX, Fv1->sSizeY, 1, AWP_FLOAT);

	AWPFLOAT* _Fv1 = (AWPFLOAT*)Fv1->pPixels;
	AWPFLOAT* _Fm1 = (AWPFLOAT*)Fm1->pPixels;
	AWPFLOAT* _result = (AWPFLOAT*)result->pPixels;

	for (int i = 0; i < Fv1->sSizeX*Fv1->sSizeY; i++) {
		_result[i] = _Fv1[i] / (_Fm1[i] + 0.0001);
	}
	awpReleaseImage(&Fv1);
	return result;
}
awpImage* TPam2ImageProcessor::GetYII1()
{
	awpImage* result = NULL;

	awpImage* Fq1 = this->GetFq1();
	awpImage* Fm1 = m_FtFm1.Frame1;

	awpCreateImage(&result, Fq1->sSizeX, Fq1->sSizeY, 1, AWP_FLOAT);

	AWPFLOAT* _Fq1 = (AWPFLOAT*)Fq1->pPixels;
	AWPFLOAT* _Fm1 = (AWPFLOAT*)Fm1->pPixels;
	AWPFLOAT* _result = (AWPFLOAT*)result->pPixels;

	for (int i = 0; i < Fq1->sSizeX*Fq1->sSizeY; i++) {
		float a = _Fm1[i];
		if (a == 0) a = 0.1;
		_result[i] = _Fq1[i] / a;
	}
	awpReleaseImage(&Fq1);
	return result;
}
awpImage* TPam2ImageProcessor::GetNPQ1()
{
    awpImage* result = NULL;
	awpImage* Fm = m_FoFm.Frame1;
	awpImage* Fm1 = m_FtFm1.Frame1;

	awpCreateImage(&result, Fm->sSizeX, Fm->sSizeY, 1, AWP_FLOAT);

	AWPFLOAT* _Fm = (AWPFLOAT*)Fm->pPixels;
	AWPFLOAT* _Fm1 = (AWPFLOAT*)Fm1->pPixels;
	AWPFLOAT* _result = (AWPFLOAT*)result->pPixels;

	for (int i = 0; i < Fm1->sSizeX*Fm1->sSizeY; i++) {
	    float a = _Fm1[i];
		if (a == 0) a = 0.1;
		_result[i] = (_Fm[i] - _Fm1[i])/a;
	}
	return result;
}
awpImage* TPam2ImageProcessor::GetqN1()
{
	awpImage* result = NULL;

	awpImage* Fm = m_FoFm.Frame1;
	awpImage* Fm1 = m_FtFm1.Frame1;
	awpImage* Fo1 = this->GetFo1();

	awpCreateImage(&result, Fm->sSizeX, Fm->sSizeY, 1, AWP_FLOAT);

	AWPFLOAT* _Fm = (AWPFLOAT*)Fm->pPixels;
	AWPFLOAT* _Fm1 = (AWPFLOAT*)Fm1->pPixels;
	AWPFLOAT* _Fo1 = (AWPFLOAT*)Fo1->pPixels;
	AWPFLOAT* _result = (AWPFLOAT*)result->pPixels;

	for (int i = 0; i < Fm1->sSizeX*Fm1->sSizeY; i++) {
		_result[i] = (_Fm[i] - _Fm1[i])/(_Fm[i] - _Fo1[i]);
	}
    awpReleaseImage(&Fo1);
	return result;
}

void __fastcall TPam2ImageProcessor::SetFoFm(awpImage* fo, awpImage* fm)
{
	this->m_FoFm.SetFrames(fo,fm);
}
void __fastcall TPam2ImageProcessor::SetFtFm1(awpImage* ft, awpImage* fm1)
{
	this->m_FtFm1.SetFrames(ft,fm1);
}

void __fastcall TPam2ImageProcessor::SetFoFmFrame(TPam2Frame* frame)
{
	this->m_FoFm.SetFrames(frame->Frame0, frame->Frame1);
}

void __fastcall TPam2ImageProcessor::SetFtFm1Frame(TPam2Frame* frame)
{
	this->m_FtFm1.SetFrames(frame->Frame0, frame->Frame1);
}

TPam2Frame* __fastcall TPam2ImageProcessor::GetFoFmFrame()
{
	return &this->m_FoFm;
}

TPam2Frame* __fastcall TPam2ImageProcessor::GetFtFm1Frame()
{
	return &this->m_FtFm1;
}
