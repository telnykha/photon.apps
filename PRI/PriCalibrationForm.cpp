//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "PriCalibrationForm.h"
#include "SelectDirUnit.h"
#include "PriMain.h"
#include "ArchiveUnit.h"
//---------------------------------------------------------------------
#pragma link "FImage41"
#pragma link "PhImageTool"
#pragma link "PhSelectRectTool"
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
		// пытаемс€ открыть архив
		if (m_calibration.LoadArchive(SelectDirDlg->DirectoryListBox1->Directory))
		{
		  // Update IU
		  UpdateUI();
		}
		else
			ShowMessage(L"Ќе могу открыть архив: " + SelectDirDlg->DirectoryListBox1->Directory);
	}
}
//---------------------------------------------------------------------------

void __fastcall TCalibrationDlg::OKBtnClick(TObject *Sender)
{
		TPRIArchive archive;

 //	if (SelectDirDlg->ShowModal() == mrOk)
	{
		if (!m_calibration.SaveCalibration(archive.path))
		{
			ShowMessage(L"Ќе могу сохранить €ркостную калибровку: " + archive.path);
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TCalibrationDlg::FormShow(TObject *Sender)
{
	UnicodeString path = MainForm->iniFile->strPath;

	if (m_calibration.LoadCalibration(path))
	{
		// update UI
		UpdateUI();
	}
	else
	{
		if (!m_calibration.CreateCalibration())
		{
			ShowMessage(L"Ќе могу создать €ркостную калибровку: " + path);
			return;
		}
		if (!m_calibration.SaveCalibration(path))
		{
			ShowMessage(L"Ќе могу сохранить €ркостную калибровку: " + path);
			return;
		}
		if (!m_calibration.LoadCalibration(path))
		{
			ShowMessage(L"Ќе могу найти €ркостную калибровку: " + path);
		}
	}

	Label2->Caption = L"";
	Label3->Caption = L"";
	Label4->Caption = L"";
	PhImage1->SelectPhTool(PhSelRectTool1);
}
//---------------------------------------------------------------------------
void __fastcall TCalibrationDlg::UpdateUI()
{
	//
	awpImage* img = GetSelectedImage();

	if (img != NULL)
	{
		awpImage* to_display = NULL;
		awpCopyImage(img, &to_display);
		awpConvert(to_display, AWP_CONVERT_TO_BYTE_WITH_NORM);
		PhImage1->SetAwpImage(to_display);


		_AWP_SAFE_RELEASE_(to_display)

		awpRect zone = m_calibration.zone;
		TRect rect;
		rect.init(zone.left, zone.top, zone.right, zone.bottom);
		PhImage1->SetSelRect(rect);
	}
}

void __fastcall TCalibrationDlg::SpeedButton1Click(TObject *Sender)
{
	UpdateUI();
}
//---------------------------------------------------------------------------

void __fastcall TCalibrationDlg::SpeedButton2Click(TObject *Sender)
{
	UpdateUI();
}
//---------------------------------------------------------------------------

void __fastcall TCalibrationDlg::SpeedButton3Click(TObject *Sender)
{
	UpdateUI();
}
//---------------------------------------------------------------------------

void __fastcall TCalibrationDlg::SpeedButton4Click(TObject *Sender)
{
	UpdateUI();
}
//---------------------------------------------------------------------------
awpImage* TCalibrationDlg::GetSelectedImage()
{
	awpImage* img = NULL;
	if (ComboBox1->ItemIndex == 0)
	{
		if (SpeedButton1->Down)
		{
			img = m_calibration.img531;
		}
		if (SpeedButton2->Down)
		{
			img = m_calibration.img531f;
		}
		if (SpeedButton3->Down)
		{
			img = m_calibration.img570;
		}
		if (SpeedButton4->Down)
		{
			img = m_calibration.img570f;
		}
	}
	else
	{
		if (SpeedButton1->Down)
		{
			img = m_calibration.img531c;
		}
		if (SpeedButton2->Down)
		{
			img = m_calibration.img531cf;
		}
		if (SpeedButton3->Down)
		{
			img = m_calibration.img570c;
		}
		if (SpeedButton4->Down)
		{
			img = m_calibration.img570cf;
		}
	}
	return img;
}

void __fastcall TCalibrationDlg::ComboBox1Change(TObject *Sender)
{
   UpdateUI();
}
//---------------------------------------------------------------------------

void __fastcall TCalibrationDlg::PhImage1MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y)
{
	if (PhImage1->Bitmap->Empty)
		return;

	awpImage* img = GetSelectedImage();
	AWPDOUBLE* d = (AWPDOUBLE*)img->pPixels;
	int x = PhImage1->GetImageX(X);
	int y = PhImage1->GetImageY(Y);
	if (x > 0 && y > 0)
	{
		Label2->Caption = L"X = " + IntToStr(x);
		Label3->Caption = L"Y = " + IntToStr(y);
		Label4->Caption = L"Value = " + FormatFloat("###.0000", d[y*IMAGE_WIDTH + x]);
		TRect r = PhImage1->GetSelRect();
		Label5->Caption = L"левый = " +IntToStr((int)r.left);
		Label6->Caption = L"верхний = " +IntToStr((int)r.top);
		Label7->Caption = L"ширина = " +IntToStr(r.Width());
		Label8->Caption = L"высота = " +IntToStr(r.Height());
	}
}
//---------------------------------------------------------------------------

void __fastcall TCalibrationDlg::PhImage1MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	TRect rect = PhImage1->GetSelRect();
	if (rect.Width() < 16 || rect.Height() < 16)
	{
        return;
	}
	awpRect zone;
	zone.left = rect.Left;
	zone.top = rect.Top;
	zone.right = rect.Right;
	zone.bottom = rect.Bottom;
	m_calibration.zone = zone;
    UpdateUI();
}
//---------------------------------------------------------------------------

void __fastcall TCalibrationDlg::FormCreate(TObject *Sender)
{
	UnicodeString path = MainForm->iniFile->strPath;

	if (m_calibration.LoadCalibration(path))
	{
		// update UI
		UpdateUI();
	}
	else
	{
		if (!m_calibration.CreateCalibration())
		{
			ShowMessage(L"Ќе могу создать €ркостную калибровку: " + path);
			return;
		}
		if (!m_calibration.SaveCalibration(path))
		{
			ShowMessage(L"Ќе могу сохранить €ркостную калибровку: " + path);
			return;
		}
		if (!m_calibration.LoadCalibration(path))
		{
			ShowMessage(L"Ќе могу найти €ркостную калибровку: " + path);
		}
	}

	Label2->Caption = L"";
	Label3->Caption = L"";
	Label4->Caption = L"";
	PhImage1->SelectPhTool(PhSelRectTool1);
}
//---------------------------------------------------------------------------

