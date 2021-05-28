//---------------------------------------------------------------------------

#ifndef pamFrameProcessingUnitH
#define pamFrameProcessingUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
class TPamImageBuffer;
class TPamFramePorcessing : public TThread
{
private:
	TPamImageBuffer* m_buffer;
protected:
	void __fastcall Execute();
public:
	__fastcall TPamFramePorcessing(bool CreateSuspended);
	__fastcall TPamFramePorcessing(TPamImageBuffer* buffer);
	void __fastcall OnTerminate(TObject *Sender);
};
//---------------------------------------------------------------------------
#endif
