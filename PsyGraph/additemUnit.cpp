//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "additemUnit.h"
#include "DataModuleUnit.h"
#include "addUserUnit.h"
#include "TestTypesListUnit.h"
#include "MainUnit.h"
#include "_LF.h"
//---------------------------------------------------------------------
#pragma resource "*.dfm"
TAddItemDialog *AddItemDialog;
//--------------------------------------------------------------------- 
__fastcall TAddItemDialog::TAddItemDialog(TComponent* AOwner)
	: TForm(AOwner)
{
}
//---------------------------------------------------------------------
void __fastcall TAddItemDialog::Button1Click(TObject *Sender)
{
// 	AddUserDialog->ShowModal();
//    DataModule1->ADOTable1->Active = false;
//    DataModule1->ADOTable1->Active = true;
      AddUserDialog->AddNewUser();

}
//---------------------------------------------------------------------------

void __fastcall TAddItemDialog::Button2Click(TObject *Sender)
{
    TestTypesForm->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TAddItemDialog::FormShow(TObject *Sender)
{
	DataModule1->ADOTable5->Insert();

}
//---------------------------------------------------------------------------

void __fastcall TAddItemDialog::OKBtnClick(TObject *Sender)
{
//
    if (DBLookupComboBox1->Text == "")
        return;

    DataModule1->ADOTable5->FieldByName("UserID")->Value = DataModule1->ADOTable2->FieldByName("UserID")->Value;
	if (MainForm->Model != NULL)
    {
		TPsyGraphModel* m = MainForm->Model;
        DataModule1->ADOTable5->FieldByName("left_top_x")->Value = m->LeftTop.X;
        DataModule1->ADOTable5->FieldByName("left_top_y")->Value = m->LeftTop.Y;
        DataModule1->ADOTable5->FieldByName("right_top_x")->Value = m->RightTop.X;
        DataModule1->ADOTable5->FieldByName("right_top_y")->Value = m->RightTop.Y;
        DataModule1->ADOTable5->FieldByName("right_bottom_x")->Value = m->RightBottom.X;
        DataModule1->ADOTable5->FieldByName("right_bottom_y")->Value = m->RightBottom.Y;
        DataModule1->ADOTable5->FieldByName("left_bottom_x")->Value = m->LeftBottom.X;
        DataModule1->ADOTable5->FieldByName("left_bottom_y")->Value = m->LeftBottom.Y;
        DataModule1->ADOTable5->FieldByName("point1_x")->Value = m->Start.X;
        DataModule1->ADOTable5->FieldByName("point1_y")->Value = m->Start.Y;
        DataModule1->ADOTable5->FieldByName("point2_x")->Value = m->Middle.X;
        DataModule1->ADOTable5->FieldByName("point2_y")->Value = m->Middle.Y;
        DataModule1->ADOTable5->FieldByName("point3_x")->Value = m->End.X;
        DataModule1->ADOTable5->FieldByName("point3_y")->Value = m->End.Y;

        UnicodeString path = MainForm->PathToImages;
        if (path != L"")
        {
            UUID id;
            LF_UUID_CREATE(id)

			UnicodeString FileName = path;
            FileName += L"\\";
			std::string str_name =  LFGUIDToString(&id);
            str_name += ".jpg";
            AnsiString _ansi = FileName;
            _ansi += str_name.c_str();
            DataModule1->ADOTable5->FieldByName("ImageName")->Value = str_name.c_str();
            MainForm->FImage1->SaveToFile(_ansi);
			DataModule1->ADOTable5->Post();
        }
        else
		    DataModule1->ADOTable5->Cancel();
    }
    else
	    DataModule1->ADOTable5->Cancel();
}
//---------------------------------------------------------------------------

void __fastcall TAddItemDialog::CancelBtnClick(TObject *Sender)
{
    DataModule1->ADOTable5->Cancel();
}
//---------------------------------------------------------------------------

void __fastcall TAddItemDialog::FormCloseQuery(TObject *Sender, bool &CanClose)
{
	if (this->ModalResult == mrOk)
    {
    	if (DBLookupComboBox1->Text == "")
        {
        	ShowMessage("Не выбран мотив!");
            CanClose = false;
        }
        else
        	CanClose = true;
    }
    else
    	CanClose = true;
}
//---------------------------------------------------------------------------

