//---------------------------------------------------------------------------

#ifndef DetectorInfoFormH
#define DetectorInfoFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "FImage.h"
#include <Vcl.ExtCtrls.hpp>
#include <VCLTee.Chart.hpp>
#include <VclTee.TeeGDIPlus.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
#include <VCLTee.Series.hpp>
//---------------------------------------------------------------------------
class TDetectorForm : public TForm
{
__published:	// IDE-managed Components
	TChart *Chart1;
	TPanel *Panel1;
	TPanel *Panel2;
	TFImage *FImage1;
	TLabel *Label1;
	TComboBox *ComboBox1;
	TLabel *Label2;
	TComboBox *ComboBox2;
	TBarSeries *Series1;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TCheckBox *CheckBox1;
	TCheckBox *CheckBox2;
	TLabel *Label7;
	TLabel *Label8;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall ComboBox1Change(TObject *Sender);
	void __fastcall ComboBox2Change(TObject *Sender);
	void __fastcall CheckBox1Click(TObject *Sender);
	void __fastcall CheckBox2Click(TObject *Sender);
private:	// User declarations
	void __fastcall DoDetectorInfo();
public:		// User declarations
	__fastcall TDetectorForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDetectorForm *DetectorForm;
//---------------------------------------------------------------------------
#endif
