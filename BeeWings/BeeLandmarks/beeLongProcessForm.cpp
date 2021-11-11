//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "beeLongProcessForm.h"
#include "beeMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	m_replace = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormShow(TObject *Sender)
{
  Label1->Caption = L"";
  ProgressBar1->Position = 0;
  //Form1->m_db.OnProgress = ProgressHandler;
  Timer1->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	Timer1->Enabled = false;
	Label2->Caption = "Обработка изображений";
	Form10->ProcessImages(m_replace);
	Close();
}
//---------------------------------------------------------------------------
