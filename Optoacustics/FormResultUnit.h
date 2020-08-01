//---------------------------------------------------------------------------

#ifndef FormResultUnitH
#define FormResultUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "FImage41.h"
//---------------------------------------------------------------------------
class TFormResultView : public TForm
{
__published:	// IDE-managed Components
	TPhImage *PhImage1;
private:	// User declarations
public:		// User declarations
	__fastcall TFormResultView(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormResultView *FormResultView;
//---------------------------------------------------------------------------
#endif
