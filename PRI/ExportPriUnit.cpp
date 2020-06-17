//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "ExportPriUnit.h"
//---------------------------------------------------------------------
#pragma resource "*.dfm"
TExportPriDlg *ExportPriDlg;
//--------------------------------------------------------------------- 
__fastcall TExportPriDlg::TExportPriDlg(TComponent* AOwner)
	: TForm(AOwner)
{
}
//---------------------------------------------------------------------
void __fastcall TExportPriDlg::Button1Click(TObject *Sender)
{
	UnicodeString str = L"Новая папка";
	if (InputQuery(L"Добавить паку", L"Имя папки", str))
	{
		UnicodeString path = this->DirectoryListBox1->Directory;
		path += L"\\";
		path += str;
		path += L"\\";
		if (!CreateDir(path))
		{
			ShowMessage(L"Не могу создать папку: " + path);
		}
		else
		{
			DirectoryListBox1->Refresh();
			DirectoryListBox1->Directory = path;
		}
	}
}
//---------------------------------------------------------------------------
EPriBlurMode TExportPriDlg::GetPriBlurMode()
{
	switch(RadioGroup1->ItemIndex)
	{
		case 0:
			return modeNone;
		break;
		case 1:
			return modeBlur;
		break;
		case 2:
            return modeBlurMore;
		break;
	}
}

