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
#include "PhZonesTool.h"
#include "PhLandmarksTool.h"
#include <Vcl.Dialogs.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ValEdit.hpp>
#include "BeeLandmarksTool.h"
#include "BeeMorphology.h"

//---------------------------------------------------------------------------
class TForm10 : public TForm
{
__published:	// IDE-managed Components
	TStatusBar *StatusBar1;
	TPanel *Panel1;
	TPanel *Panel3;
	TActionList *ActionList1;
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
	TPhLandmarksTool *PhLandmarksTool1;
	TSaveDialog *SaveDialog1;
	TPageControl *PageControl2;
	TTabSheet *TabSheet2;
	TTabSheet *TabSheet3;
	TPanel *Panel7;
	TSplitter *Splitter3;
	TPanel *Panel8;
	TDirectoryListBox *DirectoryListBox1;
	TPanel *Panel9;
	TDriveComboBox *DriveComboBox1;
	TPanel *Panel10;
	TFileListBox *FileListBox1;
	TSplitter *Splitter1;
	TSpeedButton *SpeedButton5;
	TSpeedButton *SpeedButton6;
	TSpeedButton *SpeedButton9;
	TSpeedButton *SpeedButton10;
	TSpeedButton *SpeedButton11;
	TAction *viewActualSizeAction;
	TMenuItem *N24;
	TStringGrid *StringGrid1;
	TPopupMenu *PopupMenu1;
	TMenuItem *PS2;
	TMenuItem *N25;
	TAction *viewHideSuccessAction;
	TMenuItem *N26;
	TTabSheet *TabSheet4;
	TValueListEditor *ValueListEditor1;
	TLabel *Label2;
	TLabel *Label3;
	TValueListEditor *ValueListEditor2;
	TAction *helpAboutAction;
	TMenuItem *N27;
	TMenuItem *N28;
	TAction *fileImportTPSAction;
	TMenuItem *PS3;
	TOpenDialog *OpenDialog1;
	TAction *toolsOptionsAction;
	TMenuItem *N29;
	TAction *toolsKindEditorAction;
	TMenuItem *N30;
	TAction *fileClearDBAction;
	TMenuItem *N31;
	TAction *viewAnalysisAction;
	TMenuItem *N32;
	TAction *fileRemoveAction;
	TMenuItem *N33;
	TMenuItem *N34;
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
	void __fastcall PhImage1Paint(TObject *Sender);
	void __fastcall viewActualSizeActionExecute(TObject *Sender);
	void __fastcall viewActualSizeActionUpdate(TObject *Sender);
	void __fastcall viewBestFitActionUpdate(TObject *Sender);
	void __fastcall StringGrid1Click(TObject *Sender);
	void __fastcall StringGrid1DrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State);
	void __fastcall viewHideSuccessActionExecute(TObject *Sender);
	void __fastcall viewHideSuccessActionUpdate(TObject *Sender);
	void __fastcall PhLandmarksTool1Change(TObject *Sender);
	void __fastcall TabSheet4Show(TObject *Sender);
	void __fastcall helpAboutActionExecute(TObject *Sender);
	void __fastcall fileImportTPSActionExecute(TObject *Sender);
	void __fastcall toolsOptionsActionExecute(TObject *Sender);
	void __fastcall toolsKindEditorActionExecute(TObject *Sender);
	void __fastcall fileClearDBActionExecute(TObject *Sender);
	void __fastcall fileClearDBActionUpdate(TObject *Sender);
	void __fastcall viewAnalysisActionExecute(TObject *Sender);
	void __fastcall fileRemoveActionExecute(TObject *Sender);
	void __fastcall fileRemoveActionUpdate(TObject *Sender);

private:	// User declarations
//	HANDLE m_object;
	TBeeMorphology m_morphology;
	TLFDBLandmarks m_db;
    TPhBeeLandmarksTool* m_beeTool;
	bool __fastcall CreateLandmarks();
	void __fastcall ChangeRoi(TObject* sender,  int index, bool update);
	bool __fastcall ExportTPS(const UnicodeString& strFileName);
	void __fastcall UpdateTPSGrid();
	void __fastcall MakeReport();
	UnicodeString m_selectedFile;
public:		// User declarations
	__fastcall TForm10(TComponent* Owner);
	void __fastcall ProcessImages(bool replace = true);
	//void __fastcall ProcessImages0(bool replace = true);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm10 *Form10;
//---------------------------------------------------------------------------
#endif
