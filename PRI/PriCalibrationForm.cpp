//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "PriCalibrationForm.h"
#include "SelectDirUnit.h"
//---------------------------------------------------------------------
#pragma link "FImage41"
#pragma resource "*.dfm"
TCalibrationDlg *CalibrationDlg;
//--------------------------------------------------------------------- 
__fastcall TCalibrationDlg::TCalibrationDlg(TComponent* AOwner)
	: TForm(AOwner)
{
}
//---------------------------------------------------------------------
void __fastcall TCalibrationDlg::Button1Click(TObject *Sender)
{
  //
	if (SelectDirDlg->ShowModal() == mrOk)
	{
		// пытаемся открыть архив
	}
}
//---------------------------------------------------------------------------

