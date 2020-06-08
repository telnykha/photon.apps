//---------------------------------------------------------------------------

#ifndef OptionsUnitH
#define OptionsUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Samples.Spin.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TLabel *Label1;
	TCheckBox *borderCB;
	TSpinEdit *borderSizeSE;
	TRadioGroup *outRG;
	TRadioGroup *inputRG;
	TGroupBox *GroupBox2;
	TLabel *Интервал;
	TSpinEdit *seriesIntervalSE;
	TLabel *Label2;
	TSpinEdit *seriesTotalSE;
	TRadioGroup *priRG;
	TGroupBox *GroupBox3;
	TLabel *Label3;
	TComboBox *arduinoCombo;
	TButton *Button1;
	TButton *Button2;
	TGroupBox *GroupBox4;
	TCheckBox *CheckBox1;
	TEdit *Edit1;
	TButton *Button3;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
