//---------------------------------------------------------------------------

#ifndef PhZonesEditorToolH
#define PhZonesEditorToolH
//---------------------------------------------------------------------------
#include "PhImageTool.h"
#include "PhVideo.h"
#include "_LF.h"

class PACKAGE TPhZonesEditorTool : public TPhImageTool
{
protected:
	TLF2DPoint* m_startPoint;
public:
	__fastcall TPhZonesEditorTool(TComponent* Owner);
   virtual __fastcall ~TPhZonesEditorTool();

	virtual void Draw(TCanvas* Canvas);
	virtual void MouseDown(int X, int Y, TMouseButton Button = mbLeft);
	virtual void MouseUp(int X, int Y, TMouseButton Button = mbLeft);
	virtual void MouseMove(int X, int Y, TShiftState Shift);
	virtual void Reset();
};

#endif
