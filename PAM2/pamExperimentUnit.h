//---------------------------------------------------------------------------

#ifndef pamExperimentUnitH
#define pamExperimentUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class Tpam2ExperimentForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TStatusBar *StatusBar1;
private:	// User declarations
public:		// User declarations
	__fastcall Tpam2ExperimentForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tpam2ExperimentForm *pam2ExperimentForm;
//---------------------------------------------------------------------------
#endif
