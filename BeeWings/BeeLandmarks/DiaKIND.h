//----------------------------------------------------------------------------
#ifndef DiaKINDH
#define DiaKINDH
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
#include <Vcl.ColorGrd.hpp>
//#include <Vcl.ColorGrd.hpp>
//----------------------------------------------------------------------------
class TKindEdit : public TForm
{
__published:
	TButton *OKBtn;
	TButton *CancelBtn;
	TBevel *Bevel1;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TEdit *Edit4;
	TEdit *Edit5;
	TEdit *Edit6;
	TEdit *Edit7;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TButton *Button1;
	TColorGrid *ColorGrid1;
	void __fastcall Button1Click(TObject *Sender);

private:
public:
	virtual __fastcall TKindEdit(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern PACKAGE TKindEdit *KindEdit;
//----------------------------------------------------------------------------
#endif    
