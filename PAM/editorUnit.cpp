//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "editorUnit.h"
//---------------------------------------------------------------------
#pragma resource "*.dfm"
TeditorDlg *editorDlg;
//--------------------------------------------------------------------- 
__fastcall TeditorDlg::TeditorDlg(TComponent* AOwner)
	: TForm(AOwner)
{
}
//---------------------------------------------------------------------

void __fastcall TeditorDlg::ComboBox1Change(TObject *Sender)
{
    if (ComboBox1->ItemIndex == 3 || ComboBox1->ItemIndex == 4)
    {
        ComboBox2->Enabled = false;
    }
    else
    {
        ComboBox2->Enabled = true;
    }
}
//---------------------------------------------------------------------------

