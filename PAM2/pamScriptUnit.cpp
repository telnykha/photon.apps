//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "pamScriptUnit.h"
#include "pamMainUnit.h"
#include "PhTime.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tpam2ScriptForm *pam2ScriptForm;
//---------------------------------------------------------------------------
__fastcall Tpam2ScriptForm::Tpam2ScriptForm(TComponent* Owner)
	: TForm(Owner)
{
	m_script = new TPam2ScriptDoc(this->RichEdit1);
}
//---------------------------------------------------------------------------

void __fastcall Tpam2ScriptForm::scriptNewActionExecute(TObject *Sender)
{
	m_script->New();
}
//---------------------------------------------------------------------------

void __fastcall Tpam2ScriptForm::scriptNewActionUpdate(TObject *Sender)
{
   scriptNewAction->Enabled = RichEdit1->Lines->Count > 0;
}
//---------------------------------------------------------------------------
void __fastcall Tpam2ScriptForm::scriptOpenActionUpdate(TObject *Sender)
{
	scriptOpenAction->Enabled =  pamMainForm->Mode == pam2Tuning;
}
//---------------------------------------------------------------------------


void __fastcall Tpam2ScriptForm::scriptOpenActionExecute(TObject *Sender)
{
	if (OpenDialog1->Execute())
	{
		if (!m_script->Open(OpenDialog1->FileName))
			ShowMessage(L"Не могу открыть файл \n" + ExtractFileName(OpenDialog1->FileName));
	}
}
//---------------------------------------------------------------------------


void __fastcall Tpam2ScriptForm::scriptSaveActionUpdate(TObject *Sender)
{
	scriptSaveAction->Enabled =  RichEdit1->Modified && FileExists(m_script->FileName);
}
//---------------------------------------------------------------------------

void __fastcall Tpam2ScriptForm::scriptSaveAsActionUpdate(TObject *Sender)
{
   scriptSaveAsAction->Enabled = RichEdit1->Lines->Count > 0;
}
//---------------------------------------------------------------------------

void __fastcall Tpam2ScriptForm::scriptSaveAsActionExecute(TObject *Sender)
{
	if (SaveDialog1->Execute())
	{
		UnicodeString fileName = ChangeFileExt(SaveDialog1->FileName, ".pam2s");
		if (!m_script->SaveAs(fileName)) {
			ShowMessage(L"Не могу сохранить файл \n" + ExtractFileName(SaveDialog1->FileName));
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall Tpam2ScriptForm::scriptSaveActionExecute(TObject *Sender)
{
   if (!m_script->Save()) {
			ShowMessage(L"Не могу сохранить файл \n" + ExtractFileName(m_script->FileName));
   }
}
//---------------------------------------------------------------------------

void __fastcall Tpam2ScriptForm::RichEdit1Change(TObject *Sender)
{
	RichEdit1->Modified = true;
	UpdateStatus();
}
//---------------------------------------------------------------------------

void __fastcall Tpam2ScriptForm::scriptCheckActionExecute(TObject *Sender)
{
	if (m_script->CheckScript()) {
		int CommandsCount = m_script->CommandsCount;
		UnicodeString strTime = PhGetTimeMSecStamp(m_script->GetScriptTime());
		StatusBar1->Panels->Items[0]->Text = L"Число событий " + IntToStr(CommandsCount) + L". Ожидаемое время выполнения:" + strTime;
	}
	else
	{
		ShowMessage(L"Скрипт содержит ошибки!");
		StatusBar1->Panels->Items[0]->Text = L"Скрипт содержит ошибки.";
	}
}
//---------------------------------------------------------------------------

void __fastcall Tpam2ScriptForm::scriptCheckActionUpdate(TObject *Sender)
{
	scriptCheckAction->Enabled = RichEdit1->Lines->Count > 0;
}
//---------------------------------------------------------------------------
void __fastcall Tpam2ScriptForm::UpdateStatus()
{
//
}

void __fastcall Tpam2ScriptForm::scriptExecuteActionExecute(TObject *Sender)
{
	m_script->IsRunning = true;
	pamMainForm->Timer2->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall Tpam2ScriptForm::scriptExecuteActionUpdate(TObject *Sender)
{
    scriptExecuteAction->Enabled = RichEdit1->Lines->Count > 0 && RichEdit1->Modified == false && m_script->Checked;
}
//---------------------------------------------------------------------------

