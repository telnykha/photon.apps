//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Form3DUnit.h"
#include "MainFormUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3DView *Form3DView;
//---------------------------------------------------------------------------
__fastcall TForm3DView::TForm3DView(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm3DView::FormHide(TObject *Sender)
{
	// здесь мы должны вы€снить, к какой панели подсоединен компонент.
	if (Parent != NULL)
	{
		MainForm->ShowLeftDockPanel(Parent, false, NULL);
	}

}
//---------------------------------------------------------------------------
void __fastcall TForm3DView::FormShow(TObject *Sender)
{
	if (Parent != NULL)
	{
		MainForm->ShowLeftDockPanel(Parent, true, NULL);
	}
}
//---------------------------------------------------------------------------
