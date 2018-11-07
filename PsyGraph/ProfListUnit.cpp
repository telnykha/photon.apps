//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ProfListUnit.h"
#include "DataModuleUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TProfForm *ProfForm;
//---------------------------------------------------------------------------
__fastcall TProfForm::TProfForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
