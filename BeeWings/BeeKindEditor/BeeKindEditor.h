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
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TSpeedButton *SpeedButton1;
	TEdit *Edit2;
	TEdit *Edit3;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TStringGrid *StringGrid1;
	TSpeedButton *SpeedButton2;
	TSpeedButton *SpeedButton3;
	TEdit *Edit1;
	TButton *Button1;
	void __fastcall SpeedButton2Click(TObject *Sender);
	void __fastcall SpeedButton3Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:
	 BeeKinds b;
	 void UpdateTable();

	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
