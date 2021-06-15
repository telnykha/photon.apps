//---------------------------------------------------------------------------

#ifndef pamTimeLineUnitH
#define pamTimeLineUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <VCLTee.Chart.hpp>
#include <VCLTee.Series.hpp>
#include <VclTee.TeeGDIPlus.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
#include <Vcl.Buttons.hpp>
//---------------------------------------------------------------------------
class Tpam2TimeLineForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TStatusBar *StatusBar1;
private:	// User declarations
public:		// User declarations
	__fastcall Tpam2TimeLineForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tpam2TimeLineForm *pam2TimeLineForm;
//---------------------------------------------------------------------------
#endif
