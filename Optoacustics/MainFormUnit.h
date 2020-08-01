//---------------------------------------------------------------------------

#ifndef MainFormUnitH
#define MainFormUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
#include <System.Actions.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.ComCtrls.hpp>
#include "FImage41.h"
#include <Vcl.ToolWin.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Dialogs.hpp>

#include "tiff.h"
#include "tifflibio.h"
#include "PhImageTool.h"
#include "PhPaneTool.h"
#include <System.ImageList.hpp>
#include <Vcl.ImgList.hpp>

#include "OptoacusticsProcessor.h"


//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TMenuItem *File1;
	TMenuItem *Exit1;
	TMenuItem *Edit1;
	TMenuItem *CopyToClipboard1;
	TMenuItem *View1;
	TMenuItem *Run1;
	TMenuItem *Help1;
	TActionList *ActionList1;
	TStatusBar *StatusBar1;
	TPhImage *PhImage1;
	TToolBar *ToolBar1;
	TToolButton *ToolButton1;
	TToolButton *ToolButton2;
	TAction *fileCloseAction;
	TAction *fileCloseImageAction;
	TAction *fileOpenAction;
	TAction *view3DReconstructionAction;
	TAction *viewResultAction;
	TAction *viewBinaryAction;
	TAction *viewClustersTableAction;
	TMenuItem *ResultWindow1;
	TMenuItem *BinaryWindow1;
	TMenuItem *N3Dwindow1;
	TMenuItem *ClustersTable1;
	TMenuItem *CloseImage1;
	TMenuItem *OpenImage1;
	TMenuItem *N1;
	TPanel *LeftDocPanel;
	TPanel *RightDocPanel;
	TSplitter *Splitter2;
	TSplitter *Splitter3;
	TToolButton *ToolButton3;
	TOpenDialog *OpenDialog1;
	TAction *viewFirstAction;
	TAction *viewPrevAction;
	TAction *viewNextAction;
	TAction *viewLastAction;
	TAction *viewPlayAction;
	TMenuItem *N2;
	TMenuItem *Firstimage1;
	TMenuItem *Previousimage1;
	TMenuItem *Nextimage1;
	TMenuItem *Lastimage1;
	TMenuItem *N3;
	TMenuItem *Play1;
	TPhPaneTool *PhPaneTool1;
	TImageList *ImageList1;
	TToolButton *ToolButton4;
	TToolButton *ToolButton5;
	TToolButton *ToolButton6;
	void __fastcall fileCloseActionExecute(TObject *Sender);
	void __fastcall fileOpenActionExecute(TObject *Sender);
	void __fastcall fileCloseImageActionExecute(TObject *Sender);
	void __fastcall fileCloseImageActionUpdate(TObject *Sender);
	void __fastcall view3DReconstructionActionExecute(TObject *Sender);
	void __fastcall view3DReconstructionActionUpdate(TObject *Sender);
	void __fastcall viewClustersTableActionUpdate(TObject *Sender);
	void __fastcall viewClustersTableActionExecute(TObject *Sender);
	void __fastcall viewBinaryActionExecute(TObject *Sender);
	void __fastcall viewBinaryActionUpdate(TObject *Sender);
	void __fastcall viewResultActionExecute(TObject *Sender);
	void __fastcall viewResultActionUpdate(TObject *Sender);
	void __fastcall LeftDocPanelDockOver(TObject *Sender, TDragDockObject *Source, int X,
		  int Y, TDragState State, bool &Accept);
	void __fastcall LeftDocPanelDockDrop(TObject *Sender, TDragDockObject *Source, int X,
		  int Y);
	void __fastcall LeftDocPanelUnDock(TObject *Sender, TControl *Client, TWinControl *NewTarget,
		  bool &Allow);
	void __fastcall RightDocPanelDockOver(TObject *Sender, TDragDockObject *Source,
          int X, int Y, TDragState State, bool &Accept);
	void __fastcall RightDocPanelDockDrop(TObject *Sender, TDragDockObject *Source,
          int X, int Y);
	void __fastcall RightDocPanelUnDock(TObject *Sender, TControl *Client, TWinControl *NewTarget,
          bool &Allow);
	void __fastcall PhImage1Finish(TObject *Sender, EPhJobReason reason, bool Cancel);
	void __fastcall PhImage1Progress(TObject *Sender, UnicodeString &strMessage, int Progress);
	void __fastcall viewFirstActionExecute(TObject *Sender);
	void __fastcall viewFirstActionUpdate(TObject *Sender);
	void __fastcall viewPrevActionExecute(TObject *Sender);
	void __fastcall viewPrevActionUpdate(TObject *Sender);
	void __fastcall viewNextActionExecute(TObject *Sender);
	void __fastcall viewNextActionUpdate(TObject *Sender);
	void __fastcall viewLastActionExecute(TObject *Sender);
	void __fastcall viewLastActionUpdate(TObject *Sender);
	void __fastcall viewPlayActionExecute(TObject *Sender);
	void __fastcall viewPlayActionUpdate(TObject *Sender);
	void __fastcall PhImage1AfterOpen(TObject *Sender);
	void __fastcall PhImage1FrameData(TObject *Sender, int w, int h, int c, BYTE *data);



private:	// User declarations
    TIFF* tif;
	bool OpenTIFFImage(const char* fileName);
	TOAProcessor m_p;
public:		// User declarations
	__fastcall TMainForm(TComponent* Owner);
	void ShowLeftDockPanel(TWinControl* APanel, bool MakeVisible, TControl* Client);

	bool DecodeTIFF();
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
