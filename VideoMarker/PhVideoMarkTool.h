//---------------------------------------------------------------------------

#ifndef PhVideoMarkToolH
#define PhVideoMarkToolH
//---------------------------------------------------------------------------
#include "PhImageTool.h"
#include "PhVideo.h"
#include "_LF.h"

/*
    Frame item - the collection of market items on specific frame
*/
class TFrameItem : public TLFObjectList
{
protected:
    /*frame number*/
	int m_frame;
    TLFSemanticImageDescriptor m_descriptor;
public:
   TFrameItem(){};
   virtual ~TFrameItem();

   TiXmlElement* SaveXML(int w, int h);
   bool LoadXML(TiXmlElement* parent);
   TLFSemanticImageDescriptor* GetDescriptor(int w, int h);

   __property int FrameNum = {read = m_frame, write = m_frame};
};
typedef enum {MTRect, MTVector, MTContour} TEMarkToolModes;
typedef void __fastcall (__closure *TPhAddDataEvent)(System::TObject* Sender, TFrameItem* item);
typedef void __fastcall (__closure *TPhDelFrameEvent)(System::TObject* Sender, TFrameItem* item);
typedef void __fastcall (__closure *TPhExportProgressEvent)(System::TObject* Sender, int progress, String& comment);

class PACKAGE TPhVideoMarkTool : public TPhImageTool
{
private:
	bool m_down;
	bool m_rdown;
	int  m_X;
	int  m_Y;
	int  m_si; // selected index
	int  m_sv; // selectes vertex
    int  m_selected;
	TRect* m_newRect;
	TLFZone* m_newZone;
	TEMarkToolModes m_mode;
	TLF2DPoint* m_startPoint;
	TPoint GetRectPoint(int index, TRect& rect);
		bool CheckZoneType(TLFSemanticDictinaryItem* sdi);
	void __fastcall SetVertex(int x, int y);
	bool m_edited;


	void __fastcall Commit();
	void __fastcall Rollback();
	void __fastcall ContourMouseUp(int x, int y, TMouseButton Button);
protected:
	 TPopupMenu *PopupMenu;
     /*collection of frame items*/
	 TLFObjectList m_frames;
     /*collection of items on the current frame*/
	 TLFSemanticImageDescriptor m_data;
     /*dictinary*/
	 TLFSemanticDictinary* m_dictinary;

	 double _2D_Dist(double x1,double y1,double x2,double y2);
	 bool   _is_near_vertex(int X, int Y, int& idx1, int& idx2);

	 String _get_label();
	 TColor GetItemColor(TLFDetectedItem* itm);
	 TEZoneTypes GetItemZoneType(TLFDetectedItem* itm);
	 TLFObjectList* __fastcall GetData();
	 TLFObjectList* __fastcall GetFrames();

     void __fastcall DoPopup(int X, int Y);
	 void __fastcall PopupClick(TObject* sender);
	void __fastcall TPhVideoMarkTool::DrawContour(TLFZone* z, TCanvas* Canvas, TColor c, int width, const char* text = NULL);

	TNotifyEvent 		m_OnChange;
	TNotifyEvent 		m_OnLoad;
	TPhAddDataEvent     m_OnAddData;
	TPhDelFrameEvent    m_OnDelFrame;
    TPhExportProgressEvent m_OnProgress;
protected:
	TPhMediaSource* m_mediaSource;
	virtual __fastcall SetMediaSource(TPhMediaSource* source);
    TFrameItem* GetFrameItem(int index);
public:
	__fastcall TPhVideoMarkTool(TComponent* Owner);
   virtual __fastcall ~TPhVideoMarkTool();

	virtual void Draw(TCanvas* Canvas);
	virtual void MouseDown(int X, int Y, TMouseButton Button = mbLeft);
	virtual void MouseUp(int X, int Y, TMouseButton Button = mbLeft);
	virtual void MouseMove(int X, int Y, TShiftState Shift);
	virtual void Reset();

	// Mark Tool Specific

	//methods
	void __fastcall SaveData();
	void __fastcall LoadData();
    void __fastcall SortData();

    // Default dictinary
    void __fastcall CreateDefaultDictinary();

	// add data to frames
	void __fastcall  NewFrame(bool keepData);
    // go to specific frame in the media source
	void __fastcall  SetFrame(int index);
    // delete frame data from frames
	void __fastcall  DeleteEntry(int index);
    //
    void __fastcall  DeleteObject(int index);
    // delete class label
    void __fastcall DeleteLabel(String label);
    // label statistics
    void __fastcall LabelStatistics(String label, int& numFrames, int& numEntries);
	void __fastcall  ExportToLFDatabase(const char* path);

    // show selected item
    void __fastcall  SetSelected(int index);

    //
    void __fastcall ChangeLabel(String& src_label, String& dst_label);

	//properties
	__property TPhMediaSource* MediaSource = {read = m_mediaSource, write = SetMediaSource};
	__property TLFObjectList*  data = {read = GetData};
	__property TLFObjectList*  frames = {read = GetFrames};
	__property TLFSemanticDictinary* dictinary = {read = m_dictinary};
	__property TEMarkToolModes Mode = {read = m_mode, write = m_mode};

	__property TNotifyEvent OnChange= {read = m_OnChange, write = m_OnChange};
	__property TNotifyEvent OnLoad  = {read = m_OnLoad, write = m_OnLoad};
	__property TPhAddDataEvent     OnAddData = {read = m_OnAddData, write = m_OnAddData};
	__property TPhDelFrameEvent    OnDelFrame = {read = m_OnDelFrame, write = m_OnDelFrame};
    __property TPhExportProgressEvent OnProgress = {read = m_OnProgress, write = m_OnProgress};

};
#endif
