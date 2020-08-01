//---------------------------------------------------------------------------

#ifndef FormBimaryUnitH
#define FormBimaryUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "FImage41.h"
//---------------------------------------------------------------------------
class TFormBinaryView : public TForm
{
__published:	// IDE-managed Components
	TPhImage *PhImage1;
	void __fastcall FormHide(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormBinaryView(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormBinaryView *FormBinaryView;
//---------------------------------------------------------------------------
#endif
