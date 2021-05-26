//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "pamConsoleUnit.h"
#include "pamMainUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TConsoleForm *ConsoleForm;
//---------------------------------------------------------------------------
__fastcall TConsoleForm::TConsoleForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TConsoleForm::FormHide(TObject *Sender)
{
	if (Parent != NULL)
	{
		pamMainForm->ShowDockPanel(Parent, false, NULL);
	}
}
//---------------------------------------------------------------------------
void __fastcall TConsoleForm::FormShow(TObject *Sender)
{
	if (Parent != NULL)
	{
		pamMainForm->ShowDockPanel(Parent, true, NULL);
	}
}
//---------------------------------------------------------------------------
void __fastcall TConsoleForm::FormCreate(TObject *Sender)
{
	if (pamMainForm->Comm1->Enabled()) {
		Memo1->Lines->Add("Open "+pamMainForm->Comm1->DeviceName+" OK");
	}
}
//---------------------------------------------------------------------------

void __fastcall TConsoleForm::Button1Click(TObject *Sender)
{
	char wb[256] ;
    int i ;
	if (pamMainForm->Comm1->Enabled())
	{
		AnsiString str = ComboBox1->Text.c_str();
		sprintf(wb,"%s",str.c_str());
		i = pamMainForm->Comm1->Write(wb, ComboBox1->Text.Length()+1);
	}
	else
		Memo1->Lines->Add("Устройство не подключено.");
}
//---------------------------------------------------------------------------

