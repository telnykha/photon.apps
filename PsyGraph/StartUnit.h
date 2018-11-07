//---------------------------------------------------------------------------

#ifndef StartUnitH
#define StartUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TStartForm : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TButton *Button2;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TStartForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TStartForm *StartForm;
//---------------------------------------------------------------------------
#endif
