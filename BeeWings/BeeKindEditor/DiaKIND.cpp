//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "DiaKIND.h"
//---------------------------------------------------------------------
#pragma link "cgrid"
#pragma resource "*.dfm"
TKindEdit *KindEdit;
//--------------------------------------------------------------------- 
__fastcall TKindEdit::TKindEdit(TComponent* AOwner)
	: TForm(AOwner)
{
}
//---------------------------------------------------------------------

void __fastcall TKindEdit::Button1Click(TObject *Sender)
{
    ShowMessage(ColorGrid1->ForegroundColor);
}
//---------------------------------------------------------------------------

