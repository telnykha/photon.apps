//---------------------------------------------------------------------------

#ifndef BeeKindEditorH
#define BeeKindEditorH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.Buttons.hpp>
#include <Data.DB.hpp>
#include <Data.FMTBcd.hpp>
#include <Data.SqlExpr.hpp>
#include <Vcl.Grids.hpp>
#include "BeeKinds.h"
//---------------------------------------------------------------------------
class TkindEditorForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TPanel *Panel1;
	TButton *Button1;
	TSpeedButton *SpeedButton3;
	TSpeedButton *SpeedButton2;
	TPanel *Panel2;
	TStringGrid *StringGrid1;
	TButton *Button2;
	TLabel *Label2;
	TEdit *Ci;
	TEdit *DsA;
	TEdit *Hi;
	TButton *Порода;
	void __fastcall SpeedButton2Click(TObject *Sender);
	void __fastcall SpeedButton3Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall ПородаClick(TObject *Sender);
private:
	 BeeKinds b;
	 void UpdateTable();

	// User declarations
public:		// User declarations
	__fastcall TkindEditorForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TkindEditorForm *kindEditorForm;
//---------------------------------------------------------------------------
#endif
