//---------------------------------------------------------------------------

#ifndef FormLongProcessUnitH
#define FormLongProcessUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
#include "cgauges.h"
//---------------------------------------------------------------------------
class TLongProcessForm : public TForm
{
__published:	// IDE-managed Components
	TTimer *Timer1;
	TLabel *Label1;
	TCGauge *CGauge1;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TLongProcessForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TLongProcessForm *LongProcessForm;
//---------------------------------------------------------------------------
#endif
