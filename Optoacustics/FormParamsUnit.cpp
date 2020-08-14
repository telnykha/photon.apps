//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "FormParamsUnit.h"
//---------------------------------------------------------------------
#pragma resource "*.dfm"
TParamsDlg *ParamsDlg;
//--------------------------------------------------------------------- 
__fastcall TParamsDlg::TParamsDlg(TComponent* AOwner)
	: TForm(AOwner)
{
	radius = 1;
	threshold = 0.5;
}
//---------------------------------------------------------------------
void __fastcall TParamsDlg::TrackBar1Change(TObject *Sender)
{
	//
	radius =  (double)TrackBar1->Position / 20. + 0.5;
	Label3->Caption = FormatFloat(L"0.0", radius);

}
//---------------------------------------------------------------------------

void __fastcall TParamsDlg::TrackBar2Change(TObject *Sender)
{
	threshold = (double)TrackBar2->Position / 100.;
	Label4->Caption = FormatFloat(L"0.0", threshold);
}
//---------------------------------------------------------------------------

void __fastcall TParamsDlg::FormShow(TObject *Sender)
{
	TrackBar1->Position = 20*(radius - 0.5);
	TrackBar2->Position = 100*threshold;
}
//---------------------------------------------------------------------------

