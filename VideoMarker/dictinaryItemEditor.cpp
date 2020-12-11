//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "dictinaryItemEditor.h"
//---------------------------------------------------------------------
#pragma resource "*.dfm"
TdictinaryItemDlg *dictinaryItemDlg;

static int ZoneTypeToComboIndex(TEZoneTypes z)
{
	switch(z)
	{
		case ZTContour:
			return 2;
		case ZTLineSegment:
			return 1;
		default:
			return 0;
	}
}

static  TEZoneTypes ComboIndexToZoneType(int index)
{
	switch(index)
	{
		case 1:
			return ZTLineSegment;
		case 2:
			return ZTContour;
		default:
			return ZTRect;
	}
}

//--------------------------------------------------------------------- 
__fastcall TdictinaryItemDlg::TdictinaryItemDlg(TComponent* AOwner)
	: TForm(AOwner)
{
}
//---------------------------------------------------------------------
bool __fastcall TdictinaryItemDlg::EditItem(TLFSemanticDictinaryItem* item, TPhVideoMarkTool* tool)
{
    if (item == NULL || tool == NULL)
    {
        return false;
    }

	Edit1->Text = item->GetItemLabel();
	int index = ColorGrid1->ColorToIndex(item->GetColor());
    ColorGrid1->ForegroundIndex = index;
    Panel1->Color = ColorGrid1->ForegroundColor;
	ComboBox1->ItemIndex = ZoneTypeToComboIndex(item->GetZoneType());
	if (ShowModal() == mrOk)
	{
		item->SetColor(ColorGrid1->ForegroundColor);
		UnicodeString str = item->GetItemLabel();
		if (str != Edit1->Text)
		{
			AnsiString _ansi = Edit1->Text;
			item->SetItemLabel(_ansi.c_str());
			item->SetZoneType(ComboIndexToZoneType(ComboBox1->ItemIndex));
		}
		tool->SaveData();
		return true;
    }

    return false;
}
bool __fastcall TdictinaryItemDlg::AddItem(TLFSemanticDictinaryItem* item, TPhVideoMarkTool* tool)
{
	if (ShowModal() == mrOk)
	{
		AnsiString _ansi = Edit1->Text;
		item->SetItemLabel(_ansi.c_str());
		item->SetColor(ColorGrid1->ForegroundColor);
		item->SetZoneType(ComboIndexToZoneType(ComboBox1->ItemIndex));
		tool->dictinary->AddWordToDictinary(item);
		tool->SaveData();
		return true;
    }
    return false;
}

void __fastcall TdictinaryItemDlg::ColorGrid1Click(TObject *Sender)
{
    Panel1->Color = this->ColorGrid1->ForegroundColor;
}
//---------------------------------------------------------------------------


