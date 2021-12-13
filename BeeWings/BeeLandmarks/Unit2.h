//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <VCLTee.Chart.hpp>
#include <VCLTee.Series.hpp>
#include <VclTee.TeeGDIPlus.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TPageControl *Unit1;
	TTabSheet *Индексы;
	TTabSheet *График_CI1;
	TTabSheet *График_CI;
	TTabSheet *График_DsA;
	TTabSheet *График_HI;
	TTabSheet *Анализ;
	TStringGrid *StringGrid1;
	TChart *Chart1;
	TBarSeries *Series1;
	TChart *Chart2;
	TBarSeries *Series2;
	TLineSeries *Series3;
	TChart *Chart3;
	TBarSeries *Series4;
	TLineSeries *Series5;
	TStringGrid *StringGrid2;
	TTabSheet *Результаты;
	TStringGrid *StringGrid3;
	//void __fastcall StringGrid1Click(TObject *Sender);
	//void __fastcall Unit1Change(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
