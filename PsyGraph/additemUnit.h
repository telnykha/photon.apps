//----------------------------------------------------------------------------
#ifndef additemUnitH
#define additemUnitH
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
#include <Vcl.DBCtrls.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
//----------------------------------------------------------------------------
class TAddItemDialog : public TForm
{
__published:
	TButton *OKBtn;
	TButton *CancelBtn;
	TBevel *Bevel1;
	TDBGrid *DBGrid1;
	TLabel *Label1;
	TButton *Button1;
	TLabel *Label2;
	TButton *Button2;
	TDBLookupComboBox *DBLookupComboBox1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall OKBtnClick(TObject *Sender);
	void __fastcall CancelBtnClick(TObject *Sender);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
private:
public:
	virtual __fastcall TAddItemDialog(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern PACKAGE TAddItemDialog *AddItemDialog;
//----------------------------------------------------------------------------
#endif    
