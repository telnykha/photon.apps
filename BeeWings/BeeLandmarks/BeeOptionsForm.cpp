//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "BeeOptionsForm.h"
//---------------------------------------------------------------------
#pragma resource "*.dfm"
TOptionsForm *OptionsForm;
//--------------------------------------------------------------------- 
__fastcall TOptionsForm::TOptionsForm(TComponent* AOwner)
	: TForm(AOwner)
{
}
//---------------------------------------------------------------------

void __fastcall TOptionsForm::RadioGroup1Click(TObject *Sender)
{
	UpdatePicture();
}
//---------------------------------------------------------------------------
void __fastcall TOptionsForm::UpdatePicture()
{
	UnicodeString str = ExtractFilePath(Application->ExeName);
	if (RadioGroup1->ItemIndex == 0) {
	   Image1->Picture->LoadFromFile(str + "\\circle0.bmp");
	}
	else if (RadioGroup1->ItemIndex == 1) {
	   Image1->Picture->LoadFromFile(str+ "\\circle.bmp");
	}
	else
	   Image1->Picture->LoadFromFile(str + "\\circle1.bmp");
}

void __fastcall TOptionsForm::FormShow(TObject *Sender)
{
    UpdatePicture();
}
//---------------------------------------------------------------------------

