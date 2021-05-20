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
//---------------------------------------------------------------------------
class Tpam2ScriptForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TStatusBar *StatusBar1;
	TRichEdit *RichEdit1;
private:	// User declarations
public:		// User declarations
	__fastcall Tpam2ScriptForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tpam2ScriptForm *pam2ScriptForm;
//---------------------------------------------------------------------------
#endif
