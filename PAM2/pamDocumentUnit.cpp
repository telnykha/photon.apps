//---------------------------------------------------------------------------

#pragma hdrstop
#include "pamDocumentUnit.h"
#include "pamMainUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

TPam2Document::TPam2Document(HWND wnd)
{
	m_frameBuffer = NULL;
	m_fofmBuffer  = NULL;
	m_ftfm1Buffer = NULL;

	m_numFrames = 0;
	m_currentFrame = 0;

    m_hwnd = wnd;
}
TPam2Document::~TPam2Document()
{

}

bool __fastcall TPam2Document::newDocument()
{
	return false;
}
bool __fastcall TPam2Document::OpenDocument(const UnicodeString& fileName)
{
	return false;
}
bool __fastcall TPam2Document::SaveDocument(const UnicodeString& fileName)
{
	return false;
}
bool __fastcall TPam2Document::closeDocument()
{
	return false;
}

awpImage* TPam2Document::GetFrame()
{
	awpImage* result = NULL;
	if (this->m_frameBuffer != NULL)
	{
		awpCopyImage(this->m_frameBuffer->getImage(0), &result);
		return result;
	}
	return NULL;
}

awpImage* TPam2Document::GetFo()
{
	awpImage* result = NULL;
	awpCopyImage(m_FoFm.Frame0, &result);
	return result;
}
awpImage* TPam2Document::GetFm()
{
	awpImage* result = NULL;
	awpCopyImage(m_FoFm.Frame1, &result);
	return result;
}
awpImage* TPam2Document::GetFt()
{
	awpImage* result = NULL;
	awpCopyImage(m_FtFm1.Frame0, &result);
	return result;
}
awpImage* TPam2Document::GetFm1()
{
	awpImage* result = NULL;
	awpCopyImage(m_FtFm1.Frame1, &result);
	return result;
}
awpImage* TPam2Document::GetFv()
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
awpImage* TPam2Document::GetFv1()
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
awpImage* TPam2Document::GetFq1()
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
awpImage* TPam2Document::GetFo1()
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
		float a = _Fv[i] / (0.001 + _Fm[i]);
		float b = _Fo[i] / (0.001 + _Fm1[i]);
		_result[i] = _Fo[i] /(0.001 + a + b);
	}
	awpReleaseImage(&Fv);
	return result;
}
awpImage* TPam2Document::GetFvFm1()
{
	awpImage* result = NULL;

	awpImage* Fv1 = this->GetFv1();
	awpImage* Fm1 = m_FtFm1.Frame1;

	awpCreateImage(&result, Fv1->sSizeX, Fv1->sSizeY, 1, AWP_FLOAT);

	AWPFLOAT* _Fv1 = (AWPFLOAT*)Fv1->pPixels;
	AWPFLOAT* _Fm1 = (AWPFLOAT*)Fm1->pPixels;
	AWPFLOAT* _result = (AWPFLOAT*)result->pPixels;

	for (int i = 0; i < Fv1->sSizeX*Fv1->sSizeY; i++) {
		_result[i] = _Fv1[i] / _Fm1[i];
	}
	awpReleaseImage(&Fv1);
	return result;
}
awpImage* TPam2Document::GetYII1()
{
	awpImage* result = NULL;

	awpImage* Fq1 = this->GetFq1();
	awpImage* Fm1 = m_FtFm1.Frame1;

	awpCreateImage(&result, Fq1->sSizeX, Fq1->sSizeY, 1, AWP_FLOAT);

	AWPFLOAT* _Fq1 = (AWPFLOAT*)Fq1->pPixels;
	AWPFLOAT* _Fm1 = (AWPFLOAT*)Fm1->pPixels;
	AWPFLOAT* _result = (AWPFLOAT*)result->pPixels;

	for (int i = 0; i < Fq1->sSizeX*Fq1->sSizeY; i++) {
		_result[i] = _Fq1[i] / _Fm1[i];
	}
	awpReleaseImage(&Fq1);
	return result;

}

awpImage* TPam2Document::GetNPQ1()
{
	awpImage* result = NULL;

	awpImage* Fm = m_FoFm.Frame1;
	awpImage* Fm1 = m_FtFm1.Frame1;

	awpCreateImage(&result, Fm->sSizeX, Fm->sSizeY, 1, AWP_FLOAT);

	AWPFLOAT* _Fm = (AWPFLOAT*)Fm->pPixels;
	AWPFLOAT* _Fm1 = (AWPFLOAT*)Fm1->pPixels;
	AWPFLOAT* _result = (AWPFLOAT*)result->pPixels;

	for (int i = 0; i < Fm1->sSizeX*Fm1->sSizeY; i++) {
		_result[i] = (_Fm[i] - _Fm1[i])/_Fm1[i];
	}
	return result;
}
awpImage* TPam2Document::GetqN1()
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


bool __fastcall TPam2Document::HasFrame()
{
	return m_frameBuffer != NULL;
}

bool __fastcall TPam2Document::HasFoFm()
{
	return m_numFrames > 0;
}

bool __fastcall TPam2Document::HasFtFm1()
{
	return m_numFrames > 1;
}
/*

*/
bool __fastcall TPam2Document::SetBuffer(TPamImageBuffer* buffer)
{
	if (buffer == NULL)
		return false;

	if (buffer->BufferType == pam2bfDark || buffer->BufferType == pam2bfFlash)
	{
		// set frame buffer
		SetFrameBuffer(buffer);
	}
	else if (buffer->BufferType == pam2bfFoFm)
	{
		// set FoFm
		SetFoFmBuffer(buffer);

	}
	else if (true)
	{
		// set FtFm1
		SetFtFm1Buffer(buffer);
	}

	return true;
}

void __fastcall TPam2Document::SetFrameBuffer(TPamImageBuffer* buffer)
{
	if (this->m_frameBuffer != NULL) {
		delete this->m_frameBuffer;
	}
	m_frameBuffer = new TPamImageBuffer(*buffer);
	// notify UI to update frame buffer
	::SendMessage(pamMainForm->Handle, WM_USER+1, 0,0);
}

void __fastcall TPam2Document::SetFoFmBuffer(TPamImageBuffer* buffer)
{
	if (m_fofmBuffer != NULL)
	{
		delete m_fofmBuffer;
	}
	m_fofmBuffer = new TPamImageBuffer(*buffer);
	m_FoFm.SetBuffer(m_fofmBuffer);
	::SendMessage(pamMainForm->Handle, WM_USER+1, 0,0);
	m_numFrames = 1;
}

void __fastcall TPam2Document::SetFtFm1Buffer(TPamImageBuffer* buffer)
{
	if (m_ftfm1Buffer != NULL)
	{
		delete m_ftfm1Buffer;
	}
	m_ftfm1Buffer = new TPamImageBuffer(*buffer);
	m_FtFm1.SetBuffer(m_ftfm1Buffer);
	if (m_numFrames == 1)
	{
		m_numFrames = 2;
	}
	::SendMessage(pamMainForm->Handle, WM_USER+1, 0,0);
}

