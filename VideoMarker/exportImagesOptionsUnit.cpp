//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "exportImagesOptionsUnit.h"
//---------------------------------------------------------------------
#pragma resource "*.dfm"
TexportImagesDlg *exportImagesDlg;
//--------------------------------------------------------------------- 
__fastcall TexportImagesDlg::TexportImagesDlg(TComponent* AOwner)
	: TForm(AOwner)
{
}
//---------------------------------------------------------------------
void __fastcall TexportImagesDlg::Edit1Exit(TObject *Sender)
{
	ValueChanged();
}
//---------------------------------------------------------------------------

void __fastcall TexportImagesDlg::Edit1Enter(TObject *Sender)
{
    m_oldValue = StrToInt(Edit1->Text);
    m_value = m_oldValue;
}
//---------------------------------------------------------------------------

void __fastcall TexportImagesDlg::Edit1Change(TObject *Sender)
{
	ValueChanged();
}
//---------------------------------------------------------------------------
void __fastcall TexportImagesDlg::ValueChanged()
{
    try
    {
        m_value = StrToInt(Edit1->Text);
        m_oldValue = m_value;
    }
    catch(EConvertError& e)
    {
        Edit1->Text = IntToStr(m_oldValue);
    }
}

void __fastcall TexportImagesDlg::FormShow(TObject *Sender)
{
    Edit2->Text = this->DirectoryListBox1->Directory;
    m_value = StrToInt(this->Edit1->Text);
}
//---------------------------------------------------------------------------

void __fastcall TexportImagesDlg::DirectoryListBox1Change(TObject *Sender)
{
    Edit2->Text = this->DirectoryListBox1->Directory;
}
//---------------------------------------------------------------------------
UnicodeString __fastcall TexportImagesDlg::GetExportDir()
{
    UnicodeString result =  Edit2->Text;
    result += L"\\";
    return result;
}
//---------------------------------------------------------------------------
UnicodeString __fastcall TexportImagesDlg::GetExt()
{
    switch(RadioGroup1->ItemIndex)
    {
        case 0:
            return L".jpg";
        case 1:
            return L".bmp";
        case 2:
            return L".png";
        case 3:
            return L".tiff";
        case 4:
            return L".awp";
    }
}


