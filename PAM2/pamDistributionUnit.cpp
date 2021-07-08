//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "pamMainUnit.h"
#include "pamDistributionUnit.h"
#include "pamResultUnit.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tpam2ROIForm *pam2ROIForm;
//---------------------------------------------------------------------------
__fastcall Tpam2ROIForm::Tpam2ROIForm(TComponent* Owner)
	: TForm(Owner)
{
	// Заголовки
	StringGrid1->Cells[1][0] = L"Тип объекта";
	StringGrid1->ColWidths[1] = 68;
	StringGrid1->Cells[2][0] = L"Площадь";
	StringGrid1->ColWidths[2] = 64;
	StringGrid1->Cells[3][0] = L"Минимум";
	StringGrid1->ColWidths[3] = 64;
	StringGrid1->Cells[4][0] = L"Максимум";
	StringGrid1->ColWidths[4] = 64;
	StringGrid1->Cells[5][0] = L"Ср. значение";
	StringGrid1->ColWidths[5] = 74;
	StringGrid1->Cells[6][0] = L"Стд. отклонение";
	StringGrid1->ColWidths[6] = 74;
	m_empty = true;
}
//---------------------------------------------------------------------------
void __fastcall Tpam2ROIForm::AddItem(TPam2ROI* item)
{
//
	int idx = StringGrid1->RowCount-1;

	this->SetItem(idx, item);
    StringGrid1->RowCount++;
	StringGrid1->Row = StringGrid1->RowCount-1;
	TPhPam2RoiTool* rt = pamMainForm->RoiTool;

	idx = StringGrid1->RowCount-1;
	StringGrid1->Cells[1][idx] = L"";
	StringGrid1->Cells[2][idx] = L"";
	StringGrid1->Cells[3][idx] = L"";
	StringGrid1->Cells[4][idx] = L"";
	StringGrid1->Cells[5][idx] = L"";
	StringGrid1->Cells[6][idx] = L"";
	rt->Selected = -1;
	m_empty = false;
}

void __fastcall Tpam2ROIForm::NewImage(awpImage* image)
{
	// обновление при получении нового изображения.
	TPhPam2RoiTool* rt = pamMainForm->RoiTool;
	for (int i = 0; i < rt->RoiCount; i++) {
		TPam2ROI* roi = rt->GetRoi(i);
		// анализ изображения
		roi->Calculate(image);
		int idx = i+1;
		this->SetItem(idx, roi);
	}
	// обновим график результатов
	int index =  StringGrid1->Row;
	pam2ResultForm->UpdateChart(rt->GetRoi(index-1));
}

void __fastcall Tpam2ROIForm::ChangeItem(int index)
{
	TPhPam2RoiTool* rt = pamMainForm->RoiTool;
	TPam2ROI* roi = rt->GetRoi(index);
	int idx = index+1;
	this->SetItem(idx, roi);
}

void __fastcall Tpam2ROIForm::ChangeItem(TPam2ROI* item)
{
	int index = -1;
	for (int i = 0; i < pamMainForm->RoiTool->RoiCount; i++) {
		TPam2ROI* roi = pamMainForm->RoiTool->GetRoi(i);
		if (item == roi) {
			index = i;
			break;
		}
	}
	if (index < 0) {
		return;
	}
	this->SetItem(index+1, item);
}


void __fastcall Tpam2ROIForm::StringGrid1Click(TObject *Sender)
{
	int index =  StringGrid1->Row;
	TPhPam2RoiTool* rt = pamMainForm->RoiTool;
	rt->Selected = index-1;

	// обновим график результатов
	pam2ResultForm->UpdateChart(rt->GetRoi(index-1));
}
//---------------------------------------------------------------------------

void __fastcall Tpam2ROIForm::roiDeleteActionExecute(TObject *Sender)
{
	int index =  StringGrid1->Row -1;
	TPhPam2RoiTool* rt = pamMainForm->RoiTool;
	rt->DeleteRoi(index);
	DeleteRecord(StringGrid1->Row);
}
//---------------------------------------------------------------------------

void __fastcall Tpam2ROIForm::roiDeleteActionUpdate(TObject *Sender)
{
	int index =  StringGrid1->Row -1;
	TPhPam2RoiTool* rt = pamMainForm->RoiTool;
	roiDeleteAction->Enabled = index >= 0 && index < rt->RoiCount;
}
//---------------------------------------------------------------------------

void __fastcall Tpam2ROIForm::roiClearActionExecute(TObject *Sender)
{
	TPhPam2RoiTool* rt = pamMainForm->RoiTool;
	rt->Clear();
	//StringGrid1->Row = 1;
	StringGrid1->RowCount = 2;
	StringGrid1->Cells[1][1] = L"";
	StringGrid1->Cells[2][1] = L"";
	StringGrid1->Cells[3][1] = L"";
	StringGrid1->Cells[4][1] = L"";
	StringGrid1->Cells[5][1] = L"";
	StringGrid1->Cells[6][1] = L"";
   	m_empty = true;

}
//---------------------------------------------------------------------------

void __fastcall Tpam2ROIForm::roiClearActionUpdate(TObject *Sender)
{
	TPhPam2RoiTool* rt = pamMainForm->RoiTool;
	roiClearAction->Enabled = rt->RoiCount > 0;
}
//---------------------------------------------------------------------------
void __fastcall Tpam2ROIForm::DeleteRecord(int index)
{
      TStringGrid* m_grid = StringGrid1;
	  SNDMSG(m_grid->Handle, WM_SETREDRAW, false, 0);
      try
      {
		const int row_count = m_grid->RowCount;

		// (1) shift the contents of the trailing columns
		for (int row = index; row < row_count - 1; ++row)
		{
		  m_grid->Rows[row] = m_grid->Rows[row + 1];
		}

		// (2) remove the last column
		m_grid->RowCount = row_count -1;
	  }
	  __finally
	  {
		SNDMSG(m_grid->Handle, WM_SETREDRAW, true, 0);
	  }

	  // update (repaint) the shifted cols
      RECT R = m_grid->CellRect(0, index);
      InflateRect(&R, m_grid->Width, m_grid->Height);
	  InvalidateRect(m_grid->Handle, &R, false);
}
void __fastcall Tpam2ROIForm::SetItem(int idx, TPam2ROI* item)
{
	UnicodeString strRoiType = item->RoiType;
	StringGrid1->Cells[1][idx] = strRoiType;
	StringGrid1->Cells[2][idx] = FormatFloat("####.##",item->Area);
	StringGrid1->Cells[3][idx] = FormatFloat("####.##",item->Min);
	StringGrid1->Cells[4][idx] = FormatFloat("####.##",item->Max);
	StringGrid1->Cells[5][idx] = FormatFloat("####.##",item->Avg);
	StringGrid1->Cells[6][idx] = FormatFloat("####.##",item->Std);
}
