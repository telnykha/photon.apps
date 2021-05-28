//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop

#include "pamFrameProcessingUnit.h"
#include "pamImageBufferUnit.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall TPamFramePorcessing::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall TPamFramePorcessing::TPamFramePorcessing(bool CreateSuspended)
	: TThread(CreateSuspended)
{
    m_buffer = NULL;
}
__fastcall TPamFramePorcessing::TPamFramePorcessing(TPamImageBuffer* buffer)
{
	m_buffer = buffer;
}

//---------------------------------------------------------------------------
void __fastcall TPamFramePorcessing::Execute()
{
	//---- Place thread code here ----
	if (m_buffer == NULL) {
		return;
	}
	m_buffer->Process();
}
//---------------------------------------------------------------------------
void __fastcall TPamFramePorcessing::OnTerminate(TObject *Sender)
{

}

