//----------------------------------------------------------------------------
#ifndef BeeOptionsFormH
#define BeeOptionsFormH
//----------------------------------------------------------------------------
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Graphics.hpp>
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <Winapi.Windows.hpp>
#include <System.hpp>
//----------------------------------------------------------------------------
class TOptionsForm : public TForm
{
__published:
	TButton *OKBtn;
	TButton *CancelBtn;
	TBevel *Bevel1;
	TCheckBox *CheckBox1;
	TRadioGroup *RadioGroup1;
	TRadioGroup *RadioGroup2;
	TPanel *Panel1;
	TImage *Image1;
	void __fastcall RadioGroup1Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:
	void __fastcall UpdatePicture();
public:
	virtual __fastcall TOptionsForm(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern PACKAGE TOptionsForm *OptionsForm;
//----------------------------------------------------------------------------
#endif    
