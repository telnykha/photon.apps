//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "pamLongProcessUnit.h"
#include "pamMainUnit.h"
#include "pamConsoleUnit.h"
#include "pamScriptUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TLongProcessForm *LongProcessForm;
//---------------------------------------------------------------------------
__fastcall TLongProcessForm::TLongProcessForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TLongProcessForm::FormShow(TObject *Sender)
{
	this->Gauge1->Progress = 0;
	this->Gauge2->Progress = 0;
	Label1->Caption = L"";
	 ConsoleForm->Memo1->Lines->Add("[PAM2@INFO:] Начало скрипта.");
	 pam2ScriptForm->Script->IsRunning = true;
	 pamMainForm->Timer2->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TLongProcessForm::Button1Click(TObject *Sender)
{
    pamMainForm->CancelScript();
}
//---------------------------------------------------------------------------
