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
//---------------------------------------------------------------------------
class Tpam2ResultForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TPanel *Panel2;
	TSplitter *Splitter1;
	TPanel *Panel3;
	TChart *Chart1;
	TLineSeries *Series1;
	TCheckListBox *CheckListBox1;
private:	// User declarations
public:		// User declarations
	__fastcall Tpam2ResultForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tpam2ResultForm *pam2ResultForm;
//---------------------------------------------------------------------------
#endif
