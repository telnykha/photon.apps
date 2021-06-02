//---------------------------------------------------------------------------
#ifndef pamFrameUnitH
#define pamFrameUnitH
#include "_LF.h"
#include "pamImageBufferUnit.h"
//---------------------------------------------------------------------------
class TPam2Frame
{
protected:
	TLFImage m_frame0;
	TLFImage m_frame1;

	awpImage* __fastcall GetFrame0();
	awpImage* __fastcall GetFrame1();

public:
	TPam2Frame();
	void __fastcall SetBuffer(TPamImageBuffer* buffer);

	__property awpImage* Frame0 = {read = GetFrame0};
	__property awpImage* Frame1 = {read = GetFrame1};

};
#endif
