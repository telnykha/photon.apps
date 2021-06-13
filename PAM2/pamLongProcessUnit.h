//---------------------------------------------------------------------------

#ifndef pamLongProcessUnitH
#define pamLongProcessUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Samples.Gauges.hpp>
//---------------------------------------------------------------------------
class TLongProcessForm : public TForm
{
__published:	// IDE-managed Components
	TGauge *Gauge1;
	TGauge *Gauge2;
	TButton *Button1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TLongProcessForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TLongProcessForm *LongProcessForm;
//---------------------------------------------------------------------------
#endif
