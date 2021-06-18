//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "pamResultUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tpam2ResultForm *pam2ResultForm;
//---------------------------------------------------------------------------
__fastcall Tpam2ResultForm::Tpam2ResultForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tpam2ResultForm::UpdateChart(TPam2ROI* roi)
{
	if (roi == NULL) {
		return;
	}
	Series1->Clear();
    Chart1->Title->Text->Clear();
	Chart1->Title->Text->Add(roi->RoiType + L" : " + FormatFloat(L"####.#",roi->Area));
}

