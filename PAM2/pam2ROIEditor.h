//---------------------------------------------------------------------------
#ifndef pam2ROIEditorH
#define pam2ROIEditorH
#include "PhImageTool.h"
#include "pamROI.h"
#include "_LF.h"
//---------------------------------------------------------------------------
typedef enum {TMRect, TMCircle, TMContour} EPam2ToolModes;
typedef void __fastcall (__closure *TPhAddRoiEvent)(System::TObject* Sender, TPam2ROI* item);
typedef void __fastcall (__closure *TPhChangeRoiEvent)(System::TObject* Sender, int index, bool update);

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
	TLFObjectList 		m_rois;
	TPhAddRoiEvent      m_OnAddRoi;
	TPhChangeRoiEvent   m_OnChangeRoi;
	void __fastcall AddNewRoi();
	awp2DPoint __fastcall Get2DPoint(int X, int Y);
	double _2D_Dist(double x1,double y1,double x2,double y2);
	bool   _is_near_vertex(int X, int Y, int& idx1, int& idx2);
	TPoint GetRectPoint(int index, TRect& rect);
	void __fastcall SetVertex(int x, int y, bool update);
	TRect __fastcall GetBoundsRect(TLFZone* zone);
	int __fastcall GetRoiCount();
	void __fastcall SetSelected(int value);
public:
	__fastcall TPhPam2RoiTool(TComponent* Owner);
   virtual __fastcall ~TPhPam2RoiTool();

	virtual void Draw(TCanvas* Canvas);
	virtual void MouseDown(int X, int Y, TMouseButton Button = mbLeft);
	virtual void MouseUp(int X, int Y, TMouseButton Button = mbLeft);
	virtual void MouseMove(int X, int Y, TShiftState Shift);
	virtual void Reset();

	// получение указателя на область интереса
	TPam2ROI* __fastcall GetRoi(int index);
	void __fastcall Clear();
	void __fastcall DeleteRoi(int index);

	// сохрание roi в файл
	bool __fastcall SaveRois(const UnicodeString fileName);
	// загрузка roi из файла
	bool __fastcall LoadRoi(const UnicodeString fileName);

	__property EPam2ToolModes Mode = {read = m_mode, write = m_mode};
	__property int RoiCount = {read = GetRoiCount};
	__property int Selected = {read = m_selected, write = SetSelected};

	__property TPhAddRoiEvent     OnAddRoi = {read = m_OnAddRoi, write = m_OnAddRoi};
	__property TPhChangeRoiEvent  OnChangeRoi = {read = m_OnChangeRoi, write = m_OnChangeRoi};
};
#endif
