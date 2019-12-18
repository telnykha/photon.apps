//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "dictinaryItemEditor.h"
//---------------------------------------------------------------------
#pragma resource "*.dfm"
TdictinaryItemDlg *dictinaryItemDlg;
//--------------------------------------------------------------------- 
__fastcall TdictinaryItemDlg::TdictinaryItemDlg(TComponent* AOwner)
	: TForm(AOwner)
{
}
//---------------------------------------------------------------------
bool __fastcall TdictinaryItemDlg::EditItem(TLFSemanticDictinaryItem* item)
{
    if (item == NULL )
    {
        return false;
    }

    Edit1->Text = item->GetItemLabel();
	int index = ColorGrid1->ColorToIndex(item->GetColor());
    ColorGrid1->ForegroundIndex = index;
	Panel1->Color = ColorGrid1->ForegroundColor;
	ILFScanner* s = item->GetScanner();
	SpinEdit1->Value = s->GetBaseWidth();
	SpinEdit2->Value = s->GetBaseHeight();
    if (ShowModal() == mrOk)
    {
        item->SetColor(ColorGrid1->ForegroundColor);
		UnicodeString str = item->GetItemLabel();
        AnsiString _ansi = Edit1->Text;
		item->SetItemLabel(_ansi.c_str());
		ILFScanner* s = item->GetScanner();
		assert(s);

		s->SetBaseHeight(SpinEdit2->Value);
		s->SetBaseWidth(SpinEdit1->Value);
        return true;
    }

    return false;
}
//
bool __fastcall TdictinaryItemDlg::AddItem(TLFSemanticDictinaryItem* item)
{
    if (ShowModal() == mrOk)
    {
		AnsiString _ansi = Edit1->Text;
		item->SetItemLabel(_ansi.c_str());
		item->SetColor(ColorGrid1->ForegroundColor);
		// setup scanner
		ILFScanner* s = item->GetScanner();
		assert(s);

		s->SetBaseHeight(SpinEdit2->Value);
		s->SetBaseWidth(SpinEdit1->Value);
        return true;
    }
    return false;
}

void __fastcall TdictinaryItemDlg::ColorGrid1Click(TObject *Sender)
{
    Panel1->Color = this->ColorGrid1->ForegroundColor;
}
//---------------------------------------------------------------------------


