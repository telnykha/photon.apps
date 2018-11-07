//----------------------------------------------------------------------------
#ifndef optionsUnitH
#define optionsUnitH
//----------------------------------------------------------------------------
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <StdCtrls.hpp>
#include <Controls.hpp>
#include <Forms.hpp>
#include <Graphics.hpp>
#include <Classes.hpp>
#include <SysUtils.hpp>
#include <Windows.hpp>
#include <System.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Samples.Spin.hpp>
//----------------------------------------------------------------------------
class TOptionsDlg : public TForm
{
__published:
	TButton *OKBtn;
	TButton *CancelBtn;
	TBevel *Bevel1;
	TCheckBox *CheckBox1;
	TGroupBox *GroupBox1;
	TSpinEdit *SpinEdit1;
	TSpinEdit *SpinEdit2;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TGroupBox *GroupBox2;
	TTrackBar *TrackBar1;
	TLabel *Label5;
	void __fastcall TrackBar1Change(TObject *Sender);
private:
public:
	virtual __fastcall TOptionsDlg(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern PACKAGE TOptionsDlg *OptionsDlg;
//----------------------------------------------------------------------------
#endif    
