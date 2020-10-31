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
bool __fastcall TdictinaryItemDlg::EditItem(TMarkItem* item, TPhVideoMarkTool* tool)
{
    if (item == NULL || tool == NULL)
    {
        return false;
    }

    Edit1->Text = item->label;
    int index = ColorGrid1->ColorToIndex(item->color);
    ColorGrid1->ForegroundIndex = index;
    Panel1->Color = ColorGrid1->ForegroundColor;

    if (ShowModal() == mrOk)
    {
        item->color = ColorGrid1->ForegroundColor;
        if (item->label != Edit1->Text)
        {
    	    String src = item->label;
            String dst = Edit1->Text;
            tool->ChangeLabel(src,  dst);

        }
        return true;
    }

    return false;
}
bool __fastcall TdictinaryItemDlg::AddItem(TMarkItem* item, TPhVideoMarkTool* tool)
{
    if (ShowModal() == mrOk)
    {
        item->label = Edit1->Text;
		item->color = ColorGrid1->ForegroundColor;
		tool->classes->Add(item);
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


