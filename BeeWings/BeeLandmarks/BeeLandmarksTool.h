//---------------------------------------------------------------------------

#ifndef BeeLandmarksToolH
#define BeeLandmarksToolH
//---------------------------------------------------------------------------
#include "PhImageTool.h"
#include "_LF.h"
class PACKAGE TPhBeeLandmarksTool : public TPhPaneTool
{
protected:
	awp2DPoint m_points[8];
	awp2DPoint m_out[8];
	awp2DPoint m_p4;
	awp2DPoint m_p7;
	int m_selected;
	int _is_near(int X, int Y);
	void DrawCross(awp2DPoint& p, TCanvas* c, double radius = 1);
public:
	__fastcall TPhBeeLandmarksTool(TComponent* Owner);
	virtual __fastcall ~TPhBeeLandmarksTool();

	virtual void Draw(TCanvas* Canvas);
	virtual void MouseDown(int X, int Y, TMouseButton Button = mbLeft);
	virtual void MouseUp(int X, int Y, TMouseButton Button = mbLeft);
	virtual void MouseMove(int X, int Y, TShiftState Shift);
	virtual void Reset();

};
#endif
