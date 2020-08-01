//---------------------------------------------------------------------------

#ifndef Form3DUnitH
#define Form3DUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TForm3DView : public TForm
{
__published:	// IDE-managed Components
	void __fastcall FormHide(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm3DView(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3DView *Form3DView;
//---------------------------------------------------------------------------
#endif
