//---------------------------------------------------------------------------

#pragma hdrstop

#include "pamFrameUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
TPam2Frame::TPam2Frame()
{}
void __fastcall TPam2Frame::SetBuffer(TPamImageBuffer* buffer)
{
	if (buffer == NULL)
		return;
	if (buffer->BufferType == pam2bfDark || buffer->BufferType == pam2bfFlash)
		return;

	awpImage* f0 = NULL;
	awpImage* f1 = NULL;

	awpImage* img = buffer->getImage(0);
	awpCreateImage(&f0, img->sSizeX, img->sSizeY, 1, AWP_FLOAT);
	awpCreateImage(&f1, img->sSizeX, img->sSizeY, 1, AWP_FLOAT);

	AWPFLOAT* _f0 = (AWPFLOAT*)f0->pPixels;
	AWPFLOAT* _f1 = (AWPFLOAT*)f1->pPixels;

	AWPFLOAT* _i0 = (AWPFLOAT*)(buffer->getImage(0)->pPixels);
	AWPFLOAT* _i1 = (AWPFLOAT*)(buffer->getImage(1)->pPixels);
	AWPFLOAT* _i2 = (AWPFLOAT*)(buffer->getImage(2)->pPixels);
	AWPFLOAT* _i3 = (AWPFLOAT*)(buffer->getImage(3)->pPixels);

	AWPFLOAT* _i00 = (AWPFLOAT*)(buffer->getImage(0)->pPixels);
	AWPFLOAT* _i01 = (AWPFLOAT*)(buffer->getImage(4)->pPixels);
	AWPFLOAT* _i02 = (AWPFLOAT*)(buffer->getImage(5)->pPixels);
	AWPFLOAT* _i03 = (AWPFLOAT*)(buffer->getImage(6)->pPixels);

	for (int i = 0; i < img->sSizeX*img->sSizeY; i++)
	{
		_f0[i] = (_i1[i]+_i2[i]+_i3[i])/3     - _i0[i];
		float a = (_i01[i]+_i02[i]+_i03[i])/3 - _i00[i];
		_f1[i] = a == 0 ? 1:a; // - _i03[i];
	}

	m_frame0.SetImage(f0);
	m_frame1.SetImage(f1);
	awpReleaseImage(&f0);
	awpReleaseImage(&f1);
}

awpImage* __fastcall TPam2Frame::GetFrame0()
{
	return this->m_frame0.GetImage();
}
awpImage* __fastcall TPam2Frame::GetFrame1()
{
	return this->m_frame1.GetImage();
}

void __fastcall TPam2Frame::Clear()
{
	m_frame0.FreeImages();
	m_frame1.FreeImages();
}

bool __fastcall TPam2Frame::SetFrames(awpImage* frame0, awpImage* frame1)
{
	m_frame0.SetImage(frame0);
	m_frame1.SetImage(frame1);
}

