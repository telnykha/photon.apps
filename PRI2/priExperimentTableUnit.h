//---------------------------------------------------------------------------

#ifndef priExperimentTableUnitH
#define priExperimentTableUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Samples.Gauges.hpp>
//---------------------------------------------------------------------------
class TexperimentTableForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TButton *Button1;
	TGauge *Gauge1;
	TStringGrid *StringGrid1;
private:	// User declarations
public:		// User declarations
	__fastcall TexperimentTableForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TexperimentTableForm *experimentTableForm;
//---------------------------------------------------------------------------
#endif
