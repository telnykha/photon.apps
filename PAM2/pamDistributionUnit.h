//---------------------------------------------------------------------------

#ifndef pamDistributionUnitH
#define pamDistributionUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.CheckLst.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <VCLTee.Chart.hpp>
#include <VCLTee.Series.hpp>
#include <VclTee.TeeGDIPlus.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
//---------------------------------------------------------------------------
class Tpam2ROIForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
private:	// User declarations
public:		// User declarations
	__fastcall Tpam2ROIForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tpam2ROIForm *pam2ROIForm;
//---------------------------------------------------------------------------
#endif
