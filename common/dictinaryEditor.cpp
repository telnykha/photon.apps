//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "dictinaryEditor.h"
#include "dictinaryItemEditor.h"
#include "MainForm.h"
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
    TLFSemanticDictinaryItem* item = NULL;
    if (ListBox1->ItemIndex >= 0)
    {

       item = (TLFSemanticDictinaryItem*)Form1->m_db.Dictionary->Get(ListBox1->ItemIndex);
       if (dictinaryItemDlg->EditItem(item))
       {
            // edit item in the dictinary
            ListBox1->Items->Strings[ListBox1->ItemIndex] = dictinaryItemDlg->Edit1->Text;
       }
    }
}
//---------------------------------------------------------------------------
//
void __fastcall TdictinaryEditDlg::Button1Click(TObject *Sender)
{
    TLFSemanticDictinaryItem* item = new TLFSemanticDictinaryItem();
    if (dictinaryItemDlg->AddItem(item))
    {
        ListBox1->Items->Add(item->GetItemLabel());

        // add item to dictinary
        m_dictionary.AddWordToDictinary(item);
    }
    else
        delete item;
}
//---------------------------------------------------------------------------

void __fastcall TdictinaryEditDlg::FormShow(TObject *Sender)
{
    //
    ListBox1->Clear();
    if (Form1->m_db.Dictionary != NULL)
    {
        for (int i = 0; i < Form1->m_db.Dictionary->GetCount(); i++)
        {
            TLFSemanticDictinaryItem* mi = (TLFSemanticDictinaryItem*)Form1->m_db.Dictionary->Get(i);
            ListBox1->Items->Add(mi->GetItemLabel());
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TdictinaryEditDlg::Button2Click(TObject *Sender)
{
    if (this->ListBox1->ItemIndex < 0)
    {
        ShowMessage("Не выбран ярлык для удаления.");
        return;
    }
    String del_label = this->ListBox1->Items->Strings[this->ListBox1->ItemIndex];
    String msg = L"Вы уверены, что хотите удалить все данные связанные с ярлыком ";
    msg += del_label;
    msg += L"? ";

    if (Application->MessageBoxW(msg.c_str(), Application->Name.c_str(), MB_YESNO  | MB_ICONQUESTION) == IDNO)
        return;

//    Form1->m_db.Dictionary-> ->DeleteLabel(del_label);
    this->ListBox1->Items->Delete(this->ListBox1->ItemIndex);
}
//---------------------------------------------------------------------------
TLFSemanticDictinary* __fastcall TdictinaryEditDlg::GetSemanticDictionary()
{
    return &m_dictionary;
}
bool    __fastcall TdictinaryEditDlg::CreateDatabase()
{
    m_dictionary.Clear();
    return this->ShowModal() == mrOk;
}

bool    __fastcall TdictinaryEditDlg::EditDatabase(const char* lpFileName)
{

}

