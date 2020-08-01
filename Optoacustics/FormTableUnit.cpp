//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormTableUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormTableView *FormTableView;
//---------------------------------------------------------------------------
__fastcall TFormTableView::TFormTableView(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
