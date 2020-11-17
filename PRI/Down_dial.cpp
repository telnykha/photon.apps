//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Down_dial.h"
#include "PriMain.h"
//---------------------------------------------------------------------------
USEFORM("PriCalibrationForm.cpp", CalibrationDlg);
USEFORM("SelectDirUnit.cpp", SelectDirDlg);
USEFORM("PriSpatialCalibration.cpp", SpatialCalibrationDlg);
USEFORM("CaptureDataUnit.cpp", CaptureForm);
USEFORM("ABOUT.cpp", AboutBox);
USEFORM("OptionsUnit.cpp", Form3);
USEFORM("ExportPriUnit.cpp", ExportPriDlg);
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton2Click(TObject *Sender)
{
		Form1->Close();

}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton1Click(TObject *Sender)
{
ShellExecute(NULL, L"open", L"https://telnykha.wixsite.com/nn-videolab", NULL, NULL, SW_SHOWNORMAL);
Application->Terminate();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
Form1->Show();
}
//---------------------------------------------------------------------------
