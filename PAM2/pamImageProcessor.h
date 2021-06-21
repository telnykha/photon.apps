//---------------------------------------------------------------------------
#ifndef pamImageProcessorH
#define pamImageProcessorH
#include "pamFrameUnit.h"
//---------------------------------------------------------------------------
class TPam2ImageProcessor
{
private:
	TPam2Frame  m_FoFm;
	TPam2Frame  m_FtFm1;
protected:
	void __fastcall SetFoFmFrame(TPam2Frame* frame);
	void __fastcall SetFtFm1Frame(TPam2Frame* frame);

	TPam2Frame* __fastcall GetFoFmFrame();
	TPam2Frame* __fastcall GetFtFm1Frame();
public:
	TPam2ImageProcessor();
	// setImages
	void __fastcall SetFoFm(awpImage* fo, awpImage* fm);
	void __fastcall SetFtFm1(awpImage* ft, awpImage* fm1);

	awpImage* GetFo();
	awpImage* GetFm();
	awpImage* GetFt();
	awpImage* GetFm1();
	awpImage* GetFv();
	awpImage* GetFv1();
	awpImage* GetFq1();
	awpImage* GetFo1();
	awpImage* GetFvFm1();
	awpImage* GetYII1();
	awpImage* GetNPQ1();
	awpImage* GetqN1();

	__property TPam2Frame* FoFm = {read = GetFoFmFrame, write = SetFoFmFrame};
	__property TPam2Frame* FtFm1 = {read = GetFtFm1Frame, write = SetFtFm1Frame};

};
#endif
