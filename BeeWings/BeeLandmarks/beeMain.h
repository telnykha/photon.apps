//---------------------------------------------------------------------------

#ifndef beeMainH
#define beeMainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <System.Actions.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.FileCtrl.hpp>
#include "FImage41.h"
#include <Vcl.Menus.hpp>
#include "PhImageTool.h"
#include "PhPaneTool.h"
#include "PhRulerTool.h"
#include "PhZoomToRectTool.h"
#include <Vcl.Buttons.hpp>
#include "PhTriangleTool.h"
//---------------------------------------------------------------------------
class TForm10 : public TForm
{
__published:	// IDE-managed Components
	TStatusBar *StatusBar1;
	TPanel *Panel1;
	TPanel *Panel2;
	TSplitter *Splitter1;
	TPanel *Panel3;
	TActionList *ActionList1;
	TPanel *Panel4;
	TPanel *Panel5;
	TSplitter *Splitter2;
	TPanel *Panel6;
	TDriveComboBox *DriveComboBox1;
	TDirectoryListBox *DirectoryListBox1;
	TFileListBox *FileListBox1;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TPhImage *PhImage1;
	TAction *fileExitAction;
	TMainMenu *MainMenu1;
	TMenuItem *N1;
	TMenuItem *N2;
	TAction *fileFirstAction;
	TAction *fileLastAction;
	TAction *fileNextAction;
	TAction *filePrevAction;
	TMenuItem *N3;
	TMenuItem *N4;
	TMenuItem *N5;
	TMenuItem *N6;
	TMenuItem *N7;
	TAction *fileExportTPSAction;
	TAction *fileAnalysisAction;
	TMenuItem *N8;
	TMenuItem *N9;
	TMenuItem *PS1;
	TAction *viewToolbarAction;
	TAction *viewFilePanelAction;
	TAction *viewStatusBarAction;
	TMenuItem *N10;
	TMenuItem *N11;
	TMenuItem *N12;
	TMenuItem *N13;
	TMenuItem *N14;
	TAction *viewBestFitAction;
	TMenuItem *N15;
	TAction *toolsZoomPaneAction;
	TAction *toolsZoomToRectAction;
	TAction *toolsRulerAction;
	TAction *toolsAngleAction;
	TAction *toolsBeeLandmarksAction;
	TAction *toolsEditROIAction;
	TMenuItem *N16;
	TMenuItem *N17;
	TMenuItem *N18;
	TMenuItem *N19;
	TMenuItem *N20;
	TMenuItem *N21;
	TMenuItem *N22;
	TMenuItem *N23;
	TPhPaneTool *PhPaneTool1;
	TPhRulerTool *PhRulerTool1;
	TPhZoomToRectTool *PhZoomToRectTool1;
	TSpeedButton *SpeedButton1;
	TSpeedButton *SpeedButton4;
	TSpeedButton *SpeedButton3;
	TSpeedButton *SpeedButton2;
	TPhTriangleTool *PhTriangleTool1;
	void __fastcall fileExitActionExecute(TObject *Sender);
	void __fastcall fileFirstActionExecute(TObject *Sender);
	void __fastcall fileFirstActionUpdate(TObject *Sender);
	void __fastcall fileLastActionExecute(TObject *Sender);
	void __fastcall fileLastActionUpdate(TObject *Sender);
	void __fastcall fileNextActionExecute(TObject *Sender);
	void __fastcall fileNextActionUpdate(TObject *Sender);
	void __fastcall filePrevActionExecute(TObject *Sender);
	void __fastcall filePrevActionUpdate(TObject *Sender);
	void __fastcall fileExportTPSActionExecute(TObject *Sender);
	void __fastcall fileExportTPSActionUpdate(TObject *Sender);
	void __fastcall fileAnalysisActionExecute(TObject *Sender);
	void __fastcall fileAnalysisActionUpdate(TObject *Sender);
	void __fastcall DirectoryListBox1Change(TObject *Sender);
	void __fastcall viewToolbarActionExecute(TObject *Sender);
	void __fastcall viewToolbarActionUpdate(TObject *Sender);
	void __fastcall viewFilePanelActionExecute(TObject *Sender);
	void __fastcall viewFilePanelActionUpdate(TObject *Sender);
	void __fastcall viewStatusBarActionExecute(TObject *Sender);
	void __fastcall viewStatusBarActionUpdate(TObject *Sender);
	void __fastcall viewBestFitActionExecute(TObject *Sender);
	void __fastcall FileListBox1Change(TObject *Sender);
	void __fastcall PhImage1AfterOpen(TObject *Sender);
	void __fastcall PhImage1ScaleChange(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall toolsZoomPaneActionExecute(TObject *Sender);
	void __fastcall toolsZoomPaneActionUpdate(TObject *Sender);
	void __fastcall toolsZoomToRectActionExecute(TObject *Sender);
	void __fastcall toolsZoomToRectActionUpdate(TObject *Sender);
	void __fastcall toolsRulerActionExecute(TObject *Sender);
	void __fastcall toolsRulerActionUpdate(TObject *Sender);
	void __fastcall toolsAngleActionExecute(TObject *Sender);
	void __fastcall toolsAngleActionUpdate(TObject *Sender);
	void __fastcall toolsBeeLandmarksActionExecute(TObject *Sender);
	void __fastcall toolsBeeLandmarksActionUpdate(TObject *Sender);
	void __fastcall toolsEditROIActionExecute(TObject *Sender);
	void __fastcall toolsEditROIActionUpdate(TObject *Sender);
	void __fastcall PhImage1MouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall PhImage1ToolChange(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TForm10(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm10 *Form10;
//---------------------------------------------------------------------------
#endif
