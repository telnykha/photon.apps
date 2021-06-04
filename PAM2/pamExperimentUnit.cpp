//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "pamMainUnit.h"
#include "pamExperimentUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "PhTrackBar"
#pragma resource "*.dfm"
Tpam2ExperimentForm *pam2ExperimentForm;
//---------------------------------------------------------------------------
__fastcall Tpam2ExperimentForm::Tpam2ExperimentForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tpam2ExperimentForm::SpinEdit3Change(TObject *Sender)
{
	TNotifyEvent e = PhTrackBar1->OnChange;
	PhTrackBar1->OnChange = NULL;
	PhTrackBar1->Position = SpinEdit3->Value;
	PhTrackBar1->OnChange =e;
    pamMainForm->NumFlashes =  PhTrackBar1->Position;
}
//---------------------------------------------------------------------------

void __fastcall Tpam2ExperimentForm::SpinEdit1Change(TObject *Sender)
{
	TNotifyEvent e = PhTrackBar2->OnChange;
	PhTrackBar2->OnChange = NULL;
	PhTrackBar2->Position = SpinEdit1->Value;
	PhTrackBar2->OnChange =e;
	pamMainForm->DutyÑycle =  PhTrackBar2->Position;
}
//---------------------------------------------------------------------------

void __fastcall Tpam2ExperimentForm::PhTrackBar1Change(TObject *Sender)
{
   TNotifyEvent e = SpinEdit3->OnChange;
   SpinEdit3->OnChange = NULL;
   SpinEdit3->Value = PhTrackBar1->Position;
   SpinEdit3->OnChange = e;

}
//---------------------------------------------------------------------------

void __fastcall Tpam2ExperimentForm::PhTrackBar1MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	pamMainForm->NumFlashes =  PhTrackBar1->Position;
}
//---------------------------------------------------------------------------

void __fastcall Tpam2ExperimentForm::PhTrackBar2Change(TObject *Sender)
{
   TNotifyEvent e = SpinEdit1->OnChange;
   SpinEdit1->OnChange = NULL;
   SpinEdit1->Value = PhTrackBar2->Position;
   SpinEdit1->OnChange = e;
}
//---------------------------------------------------------------------------

void __fastcall Tpam2ExperimentForm::PhTrackBar2MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	pamMainForm->DutyÑycle =  PhTrackBar2->Position;
}
//---------------------------------------------------------------------------

void __fastcall Tpam2ExperimentForm::Button2Click(TObject *Sender)
{
	pamMainForm->toolsStartExperimetAction->OnExecute(Sender);
}
//---------------------------------------------------------------------------

void __fastcall Tpam2ExperimentForm::Button1Click(TObject *Sender)
{
	pamMainForm->toolsStopExperimentAction->OnExecute(Sender);
}
//---------------------------------------------------------------------------

