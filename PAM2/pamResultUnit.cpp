//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "pamResultUnit.h"
#include "pamMainUnit.h"
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
	if (roi == NULL || pamMainForm->Mode == pam2Capture) {
		return;
	}
	Series1->Clear();
    Chart1->Title->Text->Clear();
	Chart1->Title->Text->Add(roi->RoiType + L" : " + FormatFloat(L"####.#",roi->Area));
	for(int i = 0; i < roi->Count; i++)
	{
		TPam2ROIFrame* f = roi->GetFrame(i);
		TPam2ROIData* d = NULL;

		switch(pamMainForm->ViewSource)
		{
			case pam2viewFo:
				d = f->Fo;
			break;
			case pam2viewFm:
				d = f->Fm;
			break;
			case pam2viewFt:
				d = f->Ft;
			break;
			case pam2viewFm1:
				d = f->Fm1;
			break;
			case pam2viewFv:
				d = f->Fv;
			break;
			case pam2viewFv1:
				d = f->Fv1;
			break;
			case pam2viewFq1:
				d = f->Fq1;
			break;
			case pam2viewFo1:
				d = f->Fo1;
			break;
			case pam2viewYII1:
				d= f->YII1;
			break;
			case pam2viewNPQ1:
				d = f->NPQ1;
			break;
			case pam2viewqN1:
				d = f->qN;
			break;
		}
		if (d == NULL) {
			 return;
		}

        Series1->Add(d->avg);

	}
}

