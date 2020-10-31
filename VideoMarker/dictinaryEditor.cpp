//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "dictinaryEditor.h"
#include "dictinaryItemEditor.h"
//---------------------------------------------------------------------
#pragma resource "*.dfm"
TdictinaryEditDlg *dictinaryEditDlg;
//--------------------------------------------------------------------- 
__fastcall TdictinaryEditDlg::TdictinaryEditDlg(TComponent* AOwner)
	: TForm(AOwner)
{
}
//---------------------------------------------------------------------
void __fastcall TdictinaryEditDlg::Button3Click(TObject *Sender)
{
    TMarkItem* item = NULL;
    if (ListBox1->ItemIndex >= 0)
    {
       item = (TMarkItem*)m_tool->classes->Items[ListBox1->ItemIndex];
       if (dictinaryItemDlg->EditItem(item, m_tool))
       {
            // edit item in the dictinary
            ListBox1->Items->Strings[ListBox1->ItemIndex] = dictinaryItemDlg->Edit1->Text;
       }
    }
}
//---------------------------------------------------------------------------

void __fastcall TdictinaryEditDlg::Button1Click(TObject *Sender)
{
    TMarkItem* item = new TMarkItem();
    if (dictinaryItemDlg->AddItem(item, m_tool))
    {
        // add item to dictinary
        ListBox1->Items->Add(item->label);
    }
}
//---------------------------------------------------------------------------

void __fastcall TdictinaryEditDlg::FormShow(TObject *Sender)
{
    //
    ListBox1->Clear();
    for (int i = 0; i < m_tool->classes->Count; i++)
    {
        TMarkItem* mi = (TMarkItem*)m_tool->classes->Items[i];
        ListBox1->Items->Add(mi->label);
    }
}
//---------------------------------------------------------------------------
bool    __fastcall TdictinaryEditDlg::Process(TPhVideoMarkTool* tool)
{
    if (tool == NULL)
    {
        return false;
    }
    m_tool = tool;
    return this->ShowModal() == mrOk;
}
//---------------------------------------------------------------------------
void __fastcall TdictinaryEditDlg::Button2Click(TObject *Sender)
{
    if (this->m_tool == NULL)
        return;
    if (this->ListBox1->ItemIndex < 0)
    {
        ShowMessage("Не выбран ярлык для удаления.");
        return;
    }
    String del_label = this->ListBox1->Items->Strings[this->ListBox1->ItemIndex];
    String msg = L"Вы уверены, что хотите удалить все данные связанные с ярлыком ";
    msg += del_label;
    msg += L"? ";
    int numFrames = 0;
    int numEntries = 0;
    m_tool->LabelStatistics(del_label, numFrames, numEntries);
    msg += L"Ярлыком помечено ";
    msg += IntToStr(numEntries);
    msg += L" объектов на ";
    msg += IntToStr(numFrames);
    msg += L" кадрах.";

    if (Application->MessageBoxW(msg.c_str(), Application->Name.c_str(), MB_YESNO  | MB_ICONQUESTION) == IDNO)
        return;

    m_tool->DeleteLabel(del_label);
    this->ListBox1->Items->Delete(this->ListBox1->ItemIndex);
}
//---------------------------------------------------------------------------

