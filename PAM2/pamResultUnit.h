//---------------------------------------------------------------------------

#ifndef pamResultUnitH
#define pamResultUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.CheckLst.hpp>
#include <VCLTee.Chart.hpp>
#include <VCLTee.Series.hpp>
#include <VclTee.TeeGDIPlus.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
#include "pamROI.h"
//---------------------------------------------------------------------------
class Tpam2ResultForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TPanel *Panel3;
	TChart *Chart1;
	TLineSeries *Series1;
private:	// User declarations
public:		// User declarations
	__fastcall Tpam2ResultForm(TComponent* Owner);
	void __fastcall UpdateChart(TPam2ROI* roi);
};
//---------------------------------------------------------------------------
extern PACKAGE Tpam2ResultForm *pam2ResultForm;
//---------------------------------------------------------------------------
#endif
