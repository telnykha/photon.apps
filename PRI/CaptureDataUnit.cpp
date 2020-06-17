//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CaptureDataUnit.h"
#include "PriMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cgauges"
#pragma link "FImage41"
#pragma resource "*.dfm"
TCaptureForm *CaptureForm;
//---------------------------------------------------------------------------
__fastcall TCaptureForm::TCaptureForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TCaptureForm::Button1Click(TObject *Sender)
{
	//
	if (MainForm->Timer1->Enabled)
	{
		MainForm->Timer1->Enabled = false;
		Close();
	}
	else
	{
		MainForm->Timer1->Enabled = true;
        MainForm->m_arcive.BeginSave(MainForm);
        Button1->Caption = L"Остановить запись";
	}
}
//---------------------------------------------------------------------------

void __fastcall TCaptureForm::FormClose(TObject *Sender, TCloseAction &Action)
{
	if (MainForm->Timer1->Enabled)
	{
		MainForm->Timer1->Enabled = false;
	}

    MainForm->StopVideoEngine();
}
//---------------------------------------------------------------------------

