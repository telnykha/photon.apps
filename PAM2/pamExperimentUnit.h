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
#include "PhTrackBar.h"
#include <Vcl.Samples.Gauges.hpp>
#include <Vcl.Samples.Spin.hpp>
//---------------------------------------------------------------------------
class Tpam2ExperimentForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TButton *Button1;
	TButton *Button2;
	TStatusBar *StatusBar1;
	TGauge *Gauge1;
	TGroupBox *GroupBox1;
	TPhTrackBar *PhTrackBar1;
	TPanel *Panel2;
	TSpinEdit *SpinEdit3;
	TGroupBox *GroupBox2;
	TPhTrackBar *PhTrackBar2;
	TPanel *Panel3;
	TSpinEdit *SpinEdit1;
private:	// User declarations
public:		// User declarations
	__fastcall Tpam2ExperimentForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tpam2ExperimentForm *pam2ExperimentForm;
//---------------------------------------------------------------------------
#endif
