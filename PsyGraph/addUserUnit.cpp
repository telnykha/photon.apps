//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "addUserUnit.h"
#include "DataModuleUnit.h"
#include "ProfListUnit.h"
#include "MainUnit.h"
//---------------------------------------------------------------------
#pragma resource "*.dfm"
TAddUserDialog *AddUserDialog;
//---------------------------------------------------------------------
__fastcall TAddUserDialog::TAddUserDialog(TComponent* AOwner)
	: TForm(AOwner)
{
}
//---------------------------------------------------------------------
void __fastcall TAddUserDialog::Button1Click(TObject *Sender)
{
	ProfForm->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TAddUserDialog::AddNewUser()
{
	DataModule1->ADOTable2->Insert();
    if (this->ShowModal() == mrOk)
    {
    	DataModule1->ADOTable2->Post();
    }
    else
       DataModule1->ADOTable2->Cancel();
}
void __fastcall TAddUserDialog::EditUser()
{
   DataModule1->ADOTable2->Edit();
   this->ShowModal();
}


