//----------------------------------------------------------------------------
#ifndef addUserUnitH
#define addUserUnitH
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
#include <Vcl.Mask.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
//----------------------------------------------------------------------------
class TAddUserDialog : public TForm
{
__published:
	TButton *OKBtn;
	TButton *CancelBtn;
	TBevel *Bevel1;
	TDBEdit *DBEdit1;
	TDBEdit *DBEdit2;
	TDBEdit *DBEdit3;
	TDBLookupComboBox *DBLookupComboBox1;
	TDBLookupComboBox *DBLookupComboBox2;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TButton *Button1;
	void __fastcall Button1Click(TObject *Sender);
private:
public:
	virtual __fastcall TAddUserDialog(TComponent* AOwner);
    void __fastcall AddNewUser();
    void __fastcall EditUser();
};
//----------------------------------------------------------------------------
extern PACKAGE TAddUserDialog *AddUserDialog;
//----------------------------------------------------------------------------
#endif    
