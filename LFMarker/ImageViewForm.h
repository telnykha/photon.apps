//---------------------------------------------------------------------------

#ifndef ImageViewFormH
#define ImageViewFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.AppEvnts.hpp>
#include "FImage41.h"
#include "_LF.h"
//---------------------------------------------------------------------------
class TFragmentForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TSpeedButton *SpeedButton1;
	TSpeedButton *SpeedButton2;
	TPanel *Panel2;
	TLabel *Label1;
	TLabel *Label2;
	TCheckBox *CheckBox1;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TEdit *Edit1;
	TEdit *Edit3;
	TEdit *Edit4;
	TEdit *Edit5;
	TSpeedButton *SpeedButton3;
	TSpeedButton *SpeedButton4;
	TSpeedButton *SpeedButton5;
	TSpeedButton *SpeedButton6;
	TComboBox *ComboBox1;
	TApplicationEvents *ApplicationEvents1;
	TEdit *Edit2;
	TLabel *Label8;
	TSpeedButton *SpeedButton7;
	TPhImage *PhImage1;
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall SpeedButton2Click(TObject *Sender);
	void __fastcall CheckBox1Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall ComboBox1Change(TObject *Sender);
	void __fastcall ApplicationEvents1Idle(TObject *Sender, bool &Done);
	void __fastcall SpeedButton3Click(TObject *Sender);
	void __fastcall SpeedButton4Click(TObject *Sender);
	void __fastcall SpeedButton5Click(TObject *Sender);
	void __fastcall SpeedButton6Click(TObject *Sender);
	void __fastcall ComboBox1Exit(TObject *Sender);
	void __fastcall SpeedButton7Click(TObject *Sender);
private:	// User declarations
	void __fastcall DoDetectionFragment(awpImage* img);
	void __fastcall DoDetectionImage(awpImage* img, awpRect& rect);
    TLFSemanticImageDescriptor* m_descr;
public:		// User declarations
	__fastcall TFragmentForm(TComponent* Owner);
    void __fastcall DrawSelected();
    void __fastcall ChangeDictonary();
    __property TLFSemanticImageDescriptor* SDescriptor = {read = m_descr, write = m_descr};

};
//---------------------------------------------------------------------------
extern PACKAGE TFragmentForm *FragmentForm;
//---------------------------------------------------------------------------
#endif
