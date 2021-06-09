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
	TImageList *ImageList1;
	TSpeedButton *SpeedButton1;
	void __fastcall scriptNewActionExecute(TObject *Sender);
	void __fastcall scriptNewActionUpdate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall Tpam2ScriptForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tpam2ScriptForm *pam2ScriptForm;
//---------------------------------------------------------------------------
#endif
