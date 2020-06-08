//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "SelectDirUnit.h"
//---------------------------------------------------------------------
#pragma resource "*.dfm"
TSelectDirDlg *SelectDirDlg;
//---------------------------------------------------------------------
__fastcall TSelectDirDlg::TSelectDirDlg(TComponent* AOwner)
	: TForm(AOwner)
{
}
//---------------------------------------------------------------------

void __fastcall TSelectDirDlg::Button1Click(TObject *Sender)
{
    String v = L"archive";
    if (InputQuery(L"Новая папка", L"Имя папки",  v))
    {
        //
        if (v != L"")
        {
            String s = DirectoryListBox1->Directory +L"\\" + v + L"\\";
	        ShowMessage(s);
            if (!DirectoryExists(s))
            {
                CreateDir(s);
                DirectoryListBox1->Refresh();
                DirectoryListBox1->Directory = s;
            }
            else
	            ShowMessage("Папка уже существует.");
        }
        else
            ShowMessage("Не задано имя папки.");
    }

}
//---------------------------------------------------------------------------

