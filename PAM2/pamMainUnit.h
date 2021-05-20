//---------------------------------------------------------------------------

#ifndef pamMainUnitH
#define pamMainUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <System.Actions.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ToolWin.hpp>
#include "FImage41.h"
#include <Vcl.ExtCtrls.hpp>
#include "Comm.h"
#include "pamDocumentUnit.h"
//---------------------------------------------------------------------------
class TpamMainForm : public TForm
{
__published:	// IDE-managed Components
	TToolBar *ToolBar1;
	TMainMenu *MainMenu1;
	TMenuItem *N1;
	TActionList *ActionList1;
	TAction *filesCloseAction;
	TMenuItem *N2;
	TPanel *LeftDocPanel;
	TSplitter *Splitter1;
	TPhImage *PhImage1;
	TPanel *RightDocPanel;
	TSplitter *Splitter2;
	TPanel *BottomDocPanel;
	TSplitter *Splitter3;
	TMenuItem *N3;
	TMenuItem *N4;
	TMenuItem *N5;
	TMenuItem *N6;
	TAction *windowConsoleAction;
	TMenuItem *N7;
	TComm *Comm1;
	TAction *windowExperimentAction;
	TAction *windowScriptAction;
	TAction *windowResultAction;
	TAction *windowDistributionAction;
	TAction *windowTimeLineAction;
	TMenuItem *N8;
	TMenuItem *N9;
	TMenuItem *N10;
	TMenuItem *N11;
	TMenuItem *N12;
	TAction *editCopyAction;
	TMenuItem *N13;
	TAction *toolsOptionsAction;
	TAction *toolsExecuteAction;
	TAction *toolsStartExperimetAction;
	TAction *toolsStopExperimentAction;
	TAction *helpContentAction;
	TAction *helpAboutAction;
	TMenuItem *N14;
	TMenuItem *N15;
	TMenuItem *N16;
	TMenuItem *N17;
	TMenuItem *N18;
	TMenuItem *N19;
	TMenuItem *N20;
	TMenuItem *N21;
	TAction *fileNewAction;
	TAction *fileOpenAction;
	TAction *fileCloseExperimentAction;
	TAction *fileSaveExperimentAction;
	TMenuItem *N22;
	TMenuItem *N23;
	TMenuItem *N24;
	TMenuItem *N25;
	TMenuItem *N26;
	TMenuItem *N27;
	void __fastcall filesCloseActionExecute(TObject *Sender);
	void __fastcall LeftDocPanelDockOver(TObject *Sender, TDragDockObject *Source, int X,
          int Y, TDragState State, bool &Accept);
	void __fastcall RightDocPanelDockOver(TObject *Sender, TDragDockObject *Source,
          int X, int Y, TDragState State, bool &Accept);
	void __fastcall BottomDocPanelDockOver(TObject *Sender, TDragDockObject *Source,
          int X, int Y, TDragState State, bool &Accept);
	void __fastcall windowConsoleActionExecute(TObject *Sender);
	void __fastcall LeftDocPanelUnDock(TObject *Sender, TControl *Client, TWinControl *NewTarget,
          bool &Allow);
	void __fastcall LeftDocPanelDockDrop(TObject *Sender, TDragDockObject *Source, int X,
          int Y);
	void __fastcall RightDocPanelDockDrop(TObject *Sender, TDragDockObject *Source,
          int X, int Y);
	void __fastcall RightDocPanelUnDock(TObject *Sender, TControl *Client, TWinControl *NewTarget,
          bool &Allow);
	void __fastcall BottomDocPanelDockDrop(TObject *Sender, TDragDockObject *Source,
          int X, int Y);
	void __fastcall BottomDocPanelUnDock(TObject *Sender, TControl *Client, TWinControl *NewTarget,
          bool &Allow);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Comm1RxChar(TObject *param_0, DWORD Count);
	void __fastcall windowExperimentActionExecute(TObject *Sender);
	void __fastcall windowExperimentActionUpdate(TObject *Sender);
	void __fastcall windowScriptActionExecute(TObject *Sender);
	void __fastcall windowScriptActionUpdate(TObject *Sender);
	void __fastcall windowResultActionExecute(TObject *Sender);
	void __fastcall windowResultActionUpdate(TObject *Sender);
	void __fastcall windowDistributionActionExecute(TObject *Sender);
	void __fastcall windowDistributionActionUpdate(TObject *Sender);
	void __fastcall windowTimeLineActionExecute(TObject *Sender);
	void __fastcall windowTimeLineActionUpdate(TObject *Sender);
	void __fastcall editCopyActionExecute(TObject *Sender);
	void __fastcall editCopyActionUpdate(TObject *Sender);
	void __fastcall toolsOptionsActionExecute(TObject *Sender);
	void __fastcall toolsExecuteActionExecute(TObject *Sender);
	void __fastcall toolsExecuteActionUpdate(TObject *Sender);
	void __fastcall toolsStartExperimetActionExecute(TObject *Sender);
	void __fastcall toolsStartExperimetActionUpdate(TObject *Sender);
	void __fastcall toolsStopExperimentActionExecute(TObject *Sender);
	void __fastcall toolsStopExperimentActionUpdate(TObject *Sender);
	void __fastcall helpAboutActionExecute(TObject *Sender);
	void __fastcall helpAboutActionUpdate(TObject *Sender);
	void __fastcall helpContentActionExecute(TObject *Sender);
	void __fastcall helpContentActionUpdate(TObject *Sender);
	void __fastcall fileNewActionExecute(TObject *Sender);
	void __fastcall fileNewActionUpdate(TObject *Sender);
	void __fastcall fileOpenActionExecute(TObject *Sender);
	void __fastcall fileOpenActionUpdate(TObject *Sender);
	void __fastcall fileCloseExperimentActionExecute(TObject *Sender);
	void __fastcall fileCloseExperimentActionUpdate(TObject *Sender);
	void __fastcall fileSaveExperimentActionExecute(TObject *Sender);
	void __fastcall fileSaveExperimentActionUpdate(TObject *Sender);
	void __fastcall windowConsoleActionUpdate(TObject *Sender);


private:	// User declarations
	AnsiString rs;

    TPam2Document m_pam2Doc;

public:		// User declarations
	__fastcall TpamMainForm(TComponent* Owner);


	void ShowDockPanel(TWinControl* APanel, bool MakeVisible, TControl* Client);
};
//---------------------------------------------------------------------------
extern PACKAGE TpamMainForm *pamMainForm;
//---------------------------------------------------------------------------
#endif
