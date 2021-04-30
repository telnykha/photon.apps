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
//---------------------------------------------------------------------------
class TpamMainForm : public TForm
{
__published:	// IDE-managed Components
	TStatusBar *StatusBar1;
	TToolBar *ToolBar1;
	TMainMenu *MainMenu1;
	TMenuItem *N1;
	TActionList *ActionList1;
	TAction *filesClosAction;
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
	void __fastcall filesClosActionExecute(TObject *Sender);
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


private:	// User declarations
	AnsiString rs;
public:		// User declarations
	__fastcall TpamMainForm(TComponent* Owner);


	void ShowDockPanel(TWinControl* APanel, bool MakeVisible, TControl* Client);
};
//---------------------------------------------------------------------------
extern PACKAGE TpamMainForm *pamMainForm;
//---------------------------------------------------------------------------
#endif
