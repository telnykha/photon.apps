//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormBimaryUnit.h"
#include "MainFormUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FImage41"
#pragma resource "*.dfm"
TFormBinaryView *FormBinaryView;
//---------------------------------------------------------------------------
__fastcall TFormBinaryView::TFormBinaryView(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormBinaryView::FormHide(TObject *Sender)
{
	MainForm->ShowLeftDockPanel(Parent, false, NULL);
}
//---------------------------------------------------------------------------
