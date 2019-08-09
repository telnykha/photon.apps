//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "PAMThreadUnit.h"
#include "PAMLongProcessUnit.h"
#include "MainUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TPAMLongProcessForm *PAMLongProcessForm;
//---------------------------------------------------------------------------
__fastcall TPAMLongProcessForm::TPAMLongProcessForm(TComponent* Owner)
	: TForm(Owner)
{
    m_thread = NULL;
    m_cancel = false;
    m_success = true;
}
//---------------------------------------------------------------------------
void __fastcall TPAMLongProcessForm::Execute()
{
    this->Gauge1->Visible = true;
    this->Label1->Visible = true;

    this->Gauge1->MinValue  = 0;
    this->Gauge1->MaxValue  = mainPAM->table->list->Count;
    this->Gauge1->Progress = 0;
    this->Label1->Caption = L"";
    this->Button1->Caption = L"Остановить";
    m_cancel = false;
    this->ShowModal();
}
void __fastcall TPAMLongProcessForm::FormShow(TObject *Sender)
{
    m_success = mainPAM->StartProcess();
    if (!m_success)
    {
	    this->Gauge1->Visible = false;
	    this->Label1->Caption = L"Ошибка при загрузке микоропрограммы.";
	    this->Button1->Caption = L"Закрыть.";

        mainPAM->Memo2->Lines->Add(L"Не могу запустить процесс: " + DateTimeToStr(Now()));
        return;
    }
    //
    mainPAM->Memo2->Lines->Add(L"Начало эксперимента: " + DateTimeToStr(Now()));
    m_thread = new TPAMThread(true);
    m_thread->FreeOnTerminate = true;
    m_thread->OnTerminate = OnTerminateHelper;
    m_thread->Start();
}
//---------------------------------------------------------------------------
void __fastcall TPAMLongProcessForm::Button1Click(TObject *Sender)
{
//
    if (!m_success)
        Close();
    else
    {
        m_cancel = true;
        m_thread->Terminate();
    }
}
//---------------------------------------------------------------------------
void __fastcall TPAMLongProcessForm::OnTerminateHelper(TObject *Sender)
{
    Close();
    if (!m_cancel)
	    mainPAM->FinishProcess();
    else
        mainPAM->CancelProcess();
}
