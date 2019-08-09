//----------------------------------------------------------------------------
#ifndef editorUnitH
#define editorUnitH
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
#include <Vcl.Samples.Spin.hpp>
//----------------------------------------------------------------------------
class TeditorDlg : public TForm
{
__published:
	TButton *OKBtn;
	TButton *CancelBtn;
	TBevel *Bevel1;
	TLabel *Label1;
	TComboBox *ComboBox1;
	TLabel *Label2;
	TComboBox *ComboBox2;
	TLabel *Label3;
	TSpinEdit *SpinEdit1;
	TLabel *Label4;
	TEdit *Edit1;
	void __fastcall ComboBox1Change(TObject *Sender);
private:
public:
	virtual __fastcall TeditorDlg(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern PACKAGE TeditorDlg *editorDlg;
//----------------------------------------------------------------------------
#endif    
