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
		// �������� ������� �����
		if (m_calibration.LoadArchive(SelectDirDlg->DirectoryListBox1->Directory))
		{
		  // Update IU
		  UpdateUI();
		}
		else
			ShowMessage(L"�� ���� ������� �����: " + SelectDirDlg->DirectoryListBox1->Directory);
	}
}
//---------------------------------------------------------------------------

void __fastcall TCalibrationDlg::OKBtnClick(TObject *Sender)
{
	if (SelectDirDlg->ShowModal() == mrOk)
	{
		if (!m_calibration.SaveCalibration(SelectDirDlg->DirectoryListBox1->Directory))
		{
			ShowMessage(L"�� ���� ��������� ��������� ����������: " + SelectDirDlg->DirectoryListBox1->Directory);
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TCalibrationDlg::FormShow(TObject *Sender)
{
	UnicodeString path = "";

	//
	if (m_calibration.LoadCalibration(path))
	{
		// update UI
		UpdateUI();
	}
	else
		ShowMessage(L"�� ���� ����� ��������� ����������: " + path);
}
//---------------------------------------------------------------------------
void __fastcall TCalibrationDlg::UpdateUI()
{
	//
}

