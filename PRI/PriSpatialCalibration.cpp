//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "PriSpatialCalibration.h"
#include "SelectDirUnit.h"
#include "ArchiveUnit.h"
#include "PriMain.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FImage41"
#pragma link "PhImageTool"
#pragma link "PhPaneTool"
#pragma resource "*.dfm"
TSpatialCalibrationDlg *SpatialCalibrationDlg;
//---------------------------------------------------------------------------
__fastcall TSpatialCalibrationDlg::TSpatialCalibrationDlg(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TSpatialCalibrationDlg::Button3Click(TObject *Sender)
{
	if (SelectDirDlg->ShowModal() == mrOk)
	{
		// пытаемся открыть архив
		TPriSpatialCalibration* c = MainForm->processor->Calibration;
		if (c->LoadArchive(SelectDirDlg->DirectoryListBox1->Directory))
		{
		  // Update IU
		  UpdateUI();
		}
		else
			ShowMessage(L"Не могу открыть архив: " + SelectDirDlg->DirectoryListBox1->Directory);
	}
}
//---------------------------------------------------------------------------
void __fastcall TSpatialCalibrationDlg::UpdateUI()
{
	TPriSpatialCalibration* c = MainForm->processor->Calibration;
	if (c->image531f != NULL)
		PhImage1->SetAwpImage(c->image531f);
	if (c->image570f)
		PhImage2->SetAwpImage(c->image570f);

	awpImage* src = NULL;
	awpCreateImage(&src, c->image531f->sSizeX, c->image531f->sSizeY, 3, AWP_BYTE);
	awpImage* dst = NULL;
	awpCreateImage(&dst, c->image531f->sSizeX, c->image531f->sSizeY, 3, AWP_BYTE);

	awp2DPoint* p531 = c->points531;
	awp2DPoint* p570 = c->points570;
	for (int i = 0; i < NUM_CHESS_POINTS; i++)
	{
		awpRect r;
		r.left = p531[i].X - 3;
		r.top  = p531[i].Y - 3;
		r.right = r.left + 6;
		r.bottom = r.top + 6;
		awpDrawCCross(src, &r, 0,0,255, 1);
		awpDrawCCross(dst, &r, 0,0,255, 1);

		r.left = p570[i].X - 3;
		r.top  = p570[i].Y - 3;
		r.right = r.left + 6;
		r.bottom = r.top + 6;
		awpDrawCCross(src, &r, 0,255,0, 1);

		awp2DPoint p = c->Correct(p570[i]);

		r.left = p.X - 3;
		r.top  = p.Y - 3;
		r.right = r.left + 6;
		r.bottom = r.top + 6;
		awpDrawCCross(dst, &r, 0,255,0, 1);
	}
	PhImage3->SetAwpImage(src);
    PhImage4->SetAwpImage(dst);
	_AWP_SAFE_RELEASE_( src );
	_AWP_SAFE_RELEASE_( dst );

	Label5->Caption = L"Ошибка= " + FormatFloat("00.00", c->sourceError) + L" пикс";
	Label6->Caption = L"Ошибка= " + FormatFloat("00.00", c->resultError) + L" пикс";
}
void __fastcall TSpatialCalibrationDlg::Button1Click(TObject *Sender)
{
	TPRIArchive archive;
	TPriSpatialCalibration* c = MainForm->processor->Calibration;
	if (!c->SaveCalibration(archive.path))
	{
	  ShowMessage(L"Не могу сохранить пространственную калибровку: " + archive.path);
	}
}
//---------------------------------------------------------------------------
void __fastcall TSpatialCalibrationDlg::FormShow(TObject *Sender)
{
	UpdateUI();
}
//---------------------------------------------------------------------------
