//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
 #include "PriMain.h"
#include "OptionsUnit.h"
#include "SelectDirUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button1Click(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button2Click(TObject *Sender)
{
	TPriInitFile* ini = MainForm->iniFile;
    ini->borderSize = borderSizeSE->Value;
    ini->viewBorder = (int)this->borderCB->Checked;
    ini->inputData  = this->inputRG->ItemIndex;
    ini->outData    = this->outRG->ItemIndex;
    ini->viewPri    = this->priRG->ItemIndex;
    ini->seriesInterval = this->seriesIntervalSE->Value;
    ini->seriesTotal  = this->seriesTotalSE->Value;
    ini->needSaveAll = CheckBox1->Checked;
    ini->strArchive = Edit1->Text;
	MainForm->m_arcive.path =ini->strArchive;

    Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::FormShow(TObject *Sender)
{
	TPriInitFile* ini = MainForm->iniFile;

    borderSizeSE->Value = ini->borderSize;
    borderCB->Checked = ini->viewBorder;
    inputRG->ItemIndex = ini->inputData;
    outRG->ItemIndex = ini->outData;
    priRG->ItemIndex = ini->viewPri;
    seriesIntervalSE->Value = ini->seriesInterval;
    seriesTotalSE->Value = ini->seriesTotal;
    CheckBox1->Checked = ini->needSaveAll;
    Edit1->Text = ini->strArchive;
}
//----------------------------------------------------------------------------

void __fastcall TForm3::Button3Click(TObject *Sender)
{
    SelectDirDlg->DirectoryListBox1->Directory = Edit1->Text;
    if (SelectDirDlg->ShowModal() == mrOk)
    {
        String str = SelectDirDlg->DirectoryListBox1->Directory;
        str += L"\\";
        Edit1->Text = str;
    }
}
//---------------------------------------------------------------------------

