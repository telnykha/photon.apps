//---------------------------------------------------------------------------

#ifndef mainUnitH
#define mainUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "FImage41.h"
#include "PhTrackBar.h"
#include <Vcl.Buttons.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <System.Actions.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.Dialogs.hpp>
#include "PhImageTool.h"
#include "PhLenzTool.h"
#include "PhPaneTool.h"
#include "PhSelectRectTool.h"
#include "PhZoomToRectTool.h"
#include "PhVideoMarkTool.h"
#include "PhRulerTool.h"
//---------------------------------------------------------------------------
class TPhMediaSource;
class TmainForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel3;
	TSpeedButton *SpeedButton4;
	TSpeedButton *SpeedButton1;
	TSpeedButton *SpeedButton3;
	TSpeedButton *SpeedButton2;
	TSpeedButton *SpeedButton9;
	TPhTrackBar *PhTrackBar1;
	TPhImage *PhImage1;
	TMainMenu *MainMenu1;
	TActionList *ActionList1;
	TOpenDialog *OpenDialog1;
	TMenuItem *N1;
	TMenuItem *N2;
	TAction *fileExitAction;
	TAction *fileOpenImageAction;
	TAction *fileOpenVideoAction;
	TAction *fileCloseAction;
	TMenuItem *N3;
	TMenuItem *N4;
	TMenuItem *N5;
	TMenuItem *N6;
	TMenuItem *N7;
	TMenuItem *N8;
	TStatusBar *StatusBar1;
	TAction *navFirstAction;
	TAction *navPrevAction;
	TAction *navNextAction;
	TAction *navLastAction;
	TAction *navPlayAction;
	TAction *helpAboutAction;
	TMenuItem *helpAboutAction1;
	TPanel *Panel1;
	TMenuItem *N9;
	TAction *toolsPaneAction;
	TAction *toolsZoomAction;
	TMenuItem *N10;
	TMenuItem *N11;
	TAction *toolsLenzAction;
	TMenuItem *N12;
	TAction *toolsSelectRectAction;
	TMenuItem *N13;
	TMenuItem *N14;
	TAction *toolsMarkFrameAction;
	TMenuItem *N15;
	TPhPaneTool *PhPaneTool1;
	TPhZoomToRectTool *PhZoomToRectTool1;
	TPhLenzTool *PhLenzTool1;
	TPhSelRectTool *PhSelRectTool1;
	TMenuItem *N16;
	TAction *editCopyAction;
	TMenuItem *N17;
	TAction *editClearSelectionAction;
	TMenuItem *N18;
	TMenuItem *N19;
	TAction *viewBestFitAction;
	TMenuItem *N20;
	TAction *viewActualSizeAction;
	TMenuItem *N21;
	TPopupMenu *PopupMenu1;
	TMenuItem *N22;
	TMenuItem *N23;
	TMenuItem *N24;
	TMenuItem *N25;
	TMenuItem *N26;
	TMenuItem *N27;
	TMenuItem *N28;
	TMenuItem *N29;
	TMenuItem *N30;
	TPanel *Panel2;
	TPanel *Panel4;
	TListView *ListView1;
	TListView *ListView2;
	TLabel *Label1;
	TCheckBox *CheckBox1;
	TSaveDialog *SaveDialog1;
	TPopupMenu *PopupMenu2;
	TMenuItem *N31;
	TPopupMenu *PopupMenu3;
	TMenuItem *N32;
	TMenuItem *N33;
	TSplitter *Splitter1;
	TPanel *Panel5;
	TSpeedButton *SpeedButton5;
	TSpeedButton *SpeedButton6;
	TSpeedButton *SpeedButton7;
	TSpeedButton *SpeedButton8;
	TSpeedButton *SpeedButton10;
	TSpeedButton *SpeedButton11;
	TSpeedButton *SpeedButton12;
	TSpeedButton *SpeedButton13;
	TSpeedButton *SpeedButton14;
	TSpeedButton *SpeedButton15;
	TSpeedButton *SpeedButton16;
	TAction *editStartSelAction;
	TAction *editEndSelAction;
	TSpeedButton *SpeedButton17;
	TSpeedButton *SpeedButton18;
	TSpeedButton *SpeedButton19;
	TBevel *Bevel1;
	TAction *editSelToStartAction;
	TAction *editSelToEndAction;
	TAction *editSelPlayAction;
	TTimer *Timer1;
	TAction *fileExportVideoAction;
	TMenuItem *N34;
	TAction *fileExportImagesAction;
	TMenuItem *N35;
	TTimer *Timer2;
	TPhRulerTool *PhRulerTool1;
	TAction *toolsRulerAction;
	TMenuItem *N36;
	void __fastcall fileExitActionExecute(TObject *Sender);
	void __fastcall PhImage1AfterOpen(TObject *Sender);
	void __fastcall fileOpenImageActionExecute(TObject *Sender);
	void __fastcall navFirstActionExecute(TObject *Sender);
	void __fastcall navFirstActionUpdate(TObject *Sender);
	void __fastcall navPrevActionExecute(TObject *Sender);
	void __fastcall navPrevActionUpdate(TObject *Sender);
	void __fastcall navNextActionExecute(TObject *Sender);
	void __fastcall navNextActionUpdate(TObject *Sender);
	void __fastcall navLastActionExecute(TObject *Sender);
	void __fastcall navLastActionUpdate(TObject *Sender);
	void __fastcall navPlayActionExecute(TObject *Sender);
	void __fastcall navPlayActionUpdate(TObject *Sender);
	void __fastcall PhTrackBar1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall fileCloseActionExecute(TObject *Sender);
	void __fastcall fileOpenVideoActionExecute(TObject *Sender);
	void __fastcall PhImage1FrameData(TObject *Sender, int w, int h, int c, BYTE *data);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall helpAboutActionExecute(TObject *Sender);
	void __fastcall toolsPaneActionExecute(TObject *Sender);
	void __fastcall toolsPaneActionUpdate(TObject *Sender);
	void __fastcall toolsZoomActionExecute(TObject *Sender);
	void __fastcall toolsZoomActionUpdate(TObject *Sender);
	void __fastcall toolsLenzActionExecute(TObject *Sender);
	void __fastcall toolsLenzActionUpdate(TObject *Sender);
	void __fastcall toolsSelectRectActionExecute(TObject *Sender);
	void __fastcall toolsSelectRectActionUpdate(TObject *Sender);
	void __fastcall editCopyActionExecute(TObject *Sender);
	void __fastcall editCopyActionUpdate(TObject *Sender);
	void __fastcall editClearSelectionActionExecute(TObject *Sender);
	void __fastcall editClearSelectionActionUpdate(TObject *Sender);
	void __fastcall viewBestFitActionExecute(TObject *Sender);
	void __fastcall viewBestFitActionUpdate(TObject *Sender);
	void __fastcall viewActualSizeActionExecute(TObject *Sender);
	void __fastcall viewActualSizeActionUpdate(TObject *Sender);
	void __fastcall toolsMarkFrameActionExecute(TObject *Sender);
	void __fastcall toolsMarkFrameActionUpdate(TObject *Sender);
	void __fastcall PhImage1ToolChange(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall ListView1SelectItem(TObject *Sender, TListItem *Item, bool Selected);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall N31Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall ListView2SelectItem(TObject *Sender, TListItem *Item, bool Selected);
	void __fastcall N32Click(TObject *Sender);
	void __fastcall N33Click(TObject *Sender);
	void __fastcall editStartSelActionExecute(TObject *Sender);
	void __fastcall editStartSelActionUpdate(TObject *Sender);
	void __fastcall editEndSelActionExecute(TObject *Sender);
	void __fastcall editEndSelActionUpdate(TObject *Sender);
	void __fastcall editSelToStartActionExecute(TObject *Sender);
	void __fastcall editSelToStartActionUpdate(TObject *Sender);
	void __fastcall editSelToEndActionExecute(TObject *Sender);
	void __fastcall editSelToEndActionUpdate(TObject *Sender);
	void __fastcall editSelPlayActionExecute(TObject *Sender);
	void __fastcall editSelPlayActionUpdate(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall fileExportVideoActionExecute(TObject *Sender);
	void __fastcall fileExportVideoActionUpdate(TObject *Sender);
	void __fastcall fileExportImagesActionExecute(TObject *Sender);
	void __fastcall fileExportImagesActionUpdate(TObject *Sender);
	void __fastcall SpeedButton11Click(TObject *Sender);
	void __fastcall Timer2Timer(TObject *Sender);
	void __fastcall toolsRulerActionExecute(TObject *Sender);
	void __fastcall toolsRulerActionUpdate(TObject *Sender);
private:	// User declarations
	TPhMediaSource* m_videoSource;
	TPhVideoMarkTool* m_markTool;
    int m_selIndex;

	void __fastcall SetSource(TPhMediaSource* source);
	void __fastcall UpdateFramesList();

	void __fastcall ToolChange(TObject *Sender);
	void __fastcall ToolLoad(TObject *Sender);
	void __fastcall ToolAddData(TObject *Sender, TFrameItem* item);
	void __fastcall ToolDelFrame(TObject *Sender, TFrameItem* item);

public:		// User declarations
	__fastcall TmainForm(TComponent* Owner);

    __property 	TPhMediaSource* videoSource = {read = m_videoSource};

};
//---------------------------------------------------------------------------
extern PACKAGE TmainForm *mainForm;
//---------------------------------------------------------------------------
#endif
