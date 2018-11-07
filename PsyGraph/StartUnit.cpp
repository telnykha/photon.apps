//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StartUnit.h"
#include "MainUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TStartForm *StartForm;
//---------------------------------------------------------------------------
__fastcall TStartForm::TStartForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TStartForm::Button1Click(TObject *Sender)
{
    Close();
	MainForm->dbCreateActionExecute(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TStartForm::Button2Click(TObject *Sender)
{
//
	Close();
    MainForm->dbOpenActionExecute(NULL);
}
//---------------------------------------------------------------------------
