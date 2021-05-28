//---------------------------------------------------------------------------

#ifndef pamConsoleUnitH
#define pamConsoleUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TConsoleForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TButton *Button1;
	TMemo *Memo1;
	TComboBox *ComboBox1;
	void __fastcall FormHide(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
	UnicodeString __fastcall UpdateHardwarePanel(const UnicodeString& command);
public:		// User declarations
	__fastcall TConsoleForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TConsoleForm *ConsoleForm;
//---------------------------------------------------------------------------
#endif
