//---------------------------------------------------------------------------
#ifndef pam2ROIEditorH
#define pam2ROIEditorH
#include "PhImageTool.h"
#include "_LF.h"
//---------------------------------------------------------------------------
typedef enum {TMRect, TMCircle, TMContour} EPam2ToolModes;
class PACKAGE TPhPam2RoiTool : public TPhImageTool
{
private:
	bool m_down;
	int  m_si; // selected index
	int  m_sv; // selectes vertex
	int  m_selected;
	TLFZone* m_newZone;
	EPam2ToolModes m_mode;
protected:
	TLFObjectList m_rois;
	double _2D_Dist(double x1,double y1,double x2,double y2);
	bool   _is_near_vertex(int X, int Y, int& idx1, int& idx2);
	TPoint GetRectPoint(int index, TRect& rect);
	void __fastcall SetVertex(int x, int y);
	TRect __fastcall GetBoundsRect(TLFZone* zone);
public:
	__fastcall TPhPam2RoiTool(TComponent* Owner);
   virtual __fastcall ~TPhPam2RoiTool();

	virtual void Draw(TCanvas* Canvas);
	virtual void MouseDown(int X, int Y, TMouseButton Button = mbLeft);
	virtual void MouseUp(int X, int Y, TMouseButton Button = mbLeft);
	virtual void MouseMove(int X, int Y, TShiftState Shift);
	virtual void Reset();

	__property EPam2ToolModes Mode = {read = m_mode, write = m_mode};

};
#endif
