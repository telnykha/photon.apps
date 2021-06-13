//---------------------------------------------------------------------------

#ifndef pamScriptUnitH
#define pamScriptUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <System.Actions.hpp>
#include <System.ImageList.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.ToolWin.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.StdActns.hpp>
#include "pamScriptDocUnit.h"
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
class Tpam2ScriptForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TStatusBar *StatusBar1;
	TRichEdit *RichEdit1;
	TActionList *ActionList1;
	TAction *scriptNewAction;
	TAction *scriptOpenAction;
	TAction *scriptSaveAction;
	TAction *scriptSaveAsAction;
	TAction *scriptCheckAction;
	TAction *scriptExecuteAction;
	TAction *scriptClearAction;
	TPopupMenu *PopupMenu1;
	TMenuItem *scriptNewAction1;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *N3;
	TMenuItem *N4;
	TMenuItem *N5;
	TMenuItem *scriptClearAction1;
	TEditCopy *scriptEditCopyAction;
	TMenuItem *N6;
	TMenuItem *scriptCheckAction1;
	TMenuItem *N7;
	TMenuItem *scriptExecuteAction1;
	TOpenDialog *OpenDialog1;
	TSaveDialog *SaveDialog1;
	TEditSelectAll *scriptEditSelectAllAction;
	TMenuItem *N8;
	void __fastcall scriptNewActionExecute(TObject *Sender);
	void __fastcall scriptNewActionUpdate(TObject *Sender);
	void __fastcall scriptOpenActionUpdate(TObject *Sender);
	void __fastcall scriptOpenActionExecute(TObject *Sender);
	void __fastcall scriptSaveActionUpdate(TObject *Sender);
	void __fastcall scriptSaveAsActionUpdate(TObject *Sender);
	void __fastcall scriptSaveAsActionExecute(TObject *Sender);
	void __fastcall scriptSaveActionExecute(TObject *Sender);
	void __fastcall RichEdit1Change(TObject *Sender);
	void __fastcall scriptCheckActionExecute(TObject *Sender);
	void __fastcall scriptCheckActionUpdate(TObject *Sender);
	void __fastcall scriptExecuteActionExecute(TObject *Sender);
	void __fastcall scriptExecuteActionUpdate(TObject *Sender);
private:	// User declarations
	TPam2ScriptDoc* m_script;
public:		// User declarations
	__fastcall Tpam2ScriptForm(TComponent* Owner);

	__property TPam2ScriptDoc* Script = {read = m_script};
};
//---------------------------------------------------------------------------
extern PACKAGE Tpam2ScriptForm *pam2ScriptForm;
//---------------------------------------------------------------------------
#endif
