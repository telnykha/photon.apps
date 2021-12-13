//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "beeLongProcessForm.h"
#include "beeMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TlongProcessForm *longProcessForm;
//---------------------------------------------------------------------------
__fastcall TlongProcessForm::TlongProcessForm(TComponent* Owner)
	: TForm(Owner)
{
	m_replace = true;
}
//---------------------------------------------------------------------------
void __fastcall TlongProcessForm::FormShow(TObject *Sender)
{
  Label1->Caption = L"";
  ProgressBar1->Position = 0;
  //Form1->m_db.OnProgress = ProgressHandler;
  Timer1->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TlongProcessForm::Timer1Timer(TObject *Sender)
{
	Timer1->Enabled = false;
	Label2->Caption = "Обработка изображений";
	Form10->ProcessImages(m_replace);
	Close();
}
//---------------------------------------------------------------------------
