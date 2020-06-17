//---------------------------------------------------------------------------

#ifndef CaptureDataUnitH
#define CaptureDataUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "cgauges.h"
#include "FImage41.h"
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TCaptureForm : public TForm
{
__published:	// IDE-managed Components
	TBevel *Bevel1;
	TPhImage *PhImage1;
	TPhImage *PhImage3;
	TCGauge *CGauge1;
	TLabel *Label1;
	TButton *Button1;
	TLabel *Label2;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TCaptureForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TCaptureForm *CaptureForm;
//---------------------------------------------------------------------------
#endif
