//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "optionsUnit.h"
//---------------------------------------------------------------------
#pragma resource "*.dfm"
TOptionsDlg *OptionsDlg;
//--------------------------------------------------------------------- 
__fastcall TOptionsDlg::TOptionsDlg(TComponent* AOwner)
	: TForm(AOwner)
{
}
//---------------------------------------------------------------------
void __fastcall TOptionsDlg::TrackBar1Change(TObject *Sender)
{
	Label5->Caption = IntToStr(TrackBar1->Position) + L" %";
}
//---------------------------------------------------------------------------

