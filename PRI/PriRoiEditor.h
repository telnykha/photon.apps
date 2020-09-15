//---------------------------------------------------------------------------
#ifndef PriRoiEditorH
#define PriRoiEditorH
#include "PhImageTool.h"
#define TIXML_USE_STL
#include "_LF.h"
//---------------------------------------------------------------------------
class TPriRoiItem : public TLFObject
{
protected:
	double m_x;
	double m_y;
	double m_r;
	bool   m_checked;
public:
	TPriRoiItem();
	TPriRoiItem(double x, double y, double r);
	TPriRoiItem(TPriRoiItem& item);
	virtual ~TPriRoiItem();

	virtual const char* GetName();

	double GetX();
	double GetY();
	double GetR();

	void SetX(double value);
	void SetY(double value);
	void SetR(double value);
	void Draw(TPhImage* image);

	bool LoadXML(TiXmlElement* parent);
	bool SaveXML(TiXmlElement* parent);

	void SetChecked(bool value);
	bool GetChecked();
};

typedef void __fastcall (__closure *TPhAddRoiEvent)(System::TObject* Sender, TPriRoiItem* item);

class PACKAGE TPhPriRoiEditor : public TPhImageTool
{
private:
	TPriRoiItem* m_newItem;
protected:

	TPhAddRoiEvent     m_OnAddRoi;

	bool m_down;
	TLFObjectList m_rois;
	int m_selectedIndex;
	void __fastcall SetSelected(int value);

	bool __fastcall LoadXML(TiXmlElement* parent);
	bool __fastcall SaveXML(TiXmlElement* parent);
public:
	__fastcall TPhPriRoiEditor(TComponent* Owner);
	virtual __fastcall ~TPhPriRoiEditor();

	virtual void Draw(TCanvas* Canvas);
	virtual void MouseDown(int X, int Y, TMouseButton Button = mbLeft);
	virtual void MouseUp(int X, int Y, TMouseButton Button = mbLeft);
	virtual void MouseMove(int X, int Y, TShiftState Shift);
	virtual void Reset();

	bool Load(UnicodeString path);
	bool Save(UnicodeString path);
	void Delete(int index);
	void ClearAll();

	int GetItemsCount();
	TPriRoiItem* GetItem(int index);
	void __fastcall EditSelected(double x, double y, double r);

	TRect GetRoiRect(TPriRoiItem* ri);

	void SetChecked(int index, bool value);

	__property int Selected = {read = m_selectedIndex, write = SetSelected};
	__property TPhAddRoiEvent     OnAddRoi = {read = m_OnAddRoi, write = m_OnAddRoi};
};
#endif
