//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormLongProcessUnit.h"
#include "MainFormUnit.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cgauges"
#pragma resource "*.dfm"
TLongProcessForm *LongProcessForm;
//---------------------------------------------------------------------------
__fastcall TLongProcessForm::TLongProcessForm(TComponent* Owner)
	: TForm(Owner)
{
	bProcessing = false;
}
//---------------------------------------------------------------------------
void __fastcall TLongProcessForm::FormShow(TObject *Sender)
{
	Timer1->Enabled = true;
	Label1->Caption = L"";
	CGauge1->Progress = 0;
}
//---------------------------------------------------------------------------
void __fastcall TLongProcessForm::Timer1Timer(TObject *Sender)
{
	Timer1->Enabled = false;
	if (!bProcessing)
	{
		MainForm->DecodeTIFF();
	}
	else
        MainForm->ProcessImages();
}
//---------------------------------------------------------------------------
