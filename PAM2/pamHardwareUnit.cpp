//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "pamMainUnit.h"
#include "pamHardwareUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "PhTrackBar"
#pragma resource "*.dfm"
Tpam2HardwareForm *pam2HardwareForm;
//---------------------------------------------------------------------------
__fastcall Tpam2HardwareForm::Tpam2HardwareForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tpam2HardwareForm::PhTrackBar1MouseUp(TObject *Sender, TMouseButton Button,
		  TShiftState Shift, int X, int Y)
{
	int exposhure = c_exposure[PhTrackBar1->Position];
	pamMainForm->SetExposure(exposhure);
}
//---------------------------------------------------------------------------
void __fastcall Tpam2HardwareForm::PhTrackBar1Change(TObject *Sender)
{
   int exposhure = c_exposure[PhTrackBar1->Position];
   TNotifyEvent e = SpinEdit3->OnChange;
   SpinEdit3->OnChange = NULL;
   SpinEdit3->Value = exposhure;
   SpinEdit3->OnChange = e;
   GroupBox1->Caption = L"Ёкспозици€ " + IntToStr(exposhure) + L" mks";
}
//---------------------------------------------------------------------------
void __fastcall Tpam2HardwareForm::SpinEdit3Change(TObject *Sender)
{
	GroupBox1->Caption = L"Ёкспозици€ " + IntToStr(SpinEdit3->Value) + L" mks";
    pamMainForm->SetExposure(SpinEdit3->Value);
}
//---------------------------------------------------------------------------
void __fastcall Tpam2HardwareForm::PhTrackBar2Change(TObject *Sender)
{
	int v = PhTrackBar2->Position;
	TNotifyEvent e = SpinEdit2->OnChange;
	SpinEdit2->OnChange = NULL;
	GroupBox5->Caption = L"”силение " + IntToStr(v) + L" dB";
	SpinEdit2->Value = v;
    SpinEdit2->OnChange = e;
}
//---------------------------------------------------------------------------
void __fastcall Tpam2HardwareForm::PhTrackBar2MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	pamMainForm->SetGain(SpinEdit2->Value);
}
//---------------------------------------------------------------------------
void __fastcall Tpam2HardwareForm::SpinEdit2Change(TObject *Sender)
{
	TNotifyEvent e = PhTrackBar2->OnChange;
    PhTrackBar2->OnChange = NULL;
	PhTrackBar2->Position = SpinEdit2->Value;
	PhTrackBar2->OnChange =e;
	pamMainForm->SetGain(SpinEdit2->Value);
}
//---------------------------------------------------------------------------
// ”становка прараметров измерительной вспышки.
void __fastcall Tpam2HardwareForm::PhTrackBar3MouseUp(TObject *Sender, TMouseButton Button,
		  TShiftState Shift, int X, int Y)
{
	pamMainForm->SetFlash(SpinEdit1->Value);
}
//---------------------------------------------------------------------------
//
void __fastcall Tpam2HardwareForm::PhTrackBar3Change(TObject *Sender)
{
	int v = PhTrackBar3->Position;
	TNotifyEvent e = SpinEdit1->OnChange;
	SpinEdit1->OnChange = NULL;
	GroupBox6->Caption = L"ƒлительность " + IntToStr(v) + L" мкс";
	SpinEdit1->Value = v;
    SpinEdit1->OnChange =e;
}
//---------------------------------------------------------------------------
void __fastcall Tpam2HardwareForm::SpinEdit1Change(TObject *Sender)
{
	TNotifyEvent e = PhTrackBar3->OnChange;
	PhTrackBar3->OnChange = NULL;
	PhTrackBar3->Position = SpinEdit1->Value;
	PhTrackBar3->OnChange =e;
	pamMainForm->SetFlash(SpinEdit1->Value);
}
//---------------------------------------------------------------------------
void __fastcall Tpam2HardwareForm::SpinEdit3Exit(TObject *Sender)
{
	pamMainForm->SetExposure(SpinEdit3->Value);
}
//---------------------------------------------------------------------------



void __fastcall Tpam2HardwareForm::PhTrackBar4Change(TObject *Sender)
{
	SpeedButton1->Caption = IntToStr(PhTrackBar4->Position) + L"%";
}
//---------------------------------------------------------------------------

void __fastcall Tpam2HardwareForm::PhTrackBar4MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
   pamMainForm->SetSat(PhTrackBar4->Position);
}
//---------------------------------------------------------------------------


void __fastcall Tpam2HardwareForm::PhTrackBar5Change(TObject *Sender)
{
	SpeedButton2->Caption = IntToStr(PhTrackBar5->Position) + L"%";
}
//---------------------------------------------------------------------------

void __fastcall Tpam2HardwareForm::PhTrackBar5MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	pamMainForm->SetAct(PhTrackBar5->Position);
}
//---------------------------------------------------------------------------

void __fastcall Tpam2HardwareForm::PhTrackBar6Change(TObject *Sender)
{
	SpeedButton3->Caption = IntToStr(PhTrackBar6->Position) + L"%";
}
//---------------------------------------------------------------------------

void __fastcall Tpam2HardwareForm::PhTrackBar6MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	pamMainForm->SetAdd(PhTrackBar6->Position);
}
//---------------------------------------------------------------------------

void __fastcall Tpam2HardwareForm::SpeedButton3Click(TObject *Sender)
{
	if (SpeedButton3->Down) {
		 pamMainForm->SwitchAdd(1);
	}
	else
	   pamMainForm->SwitchAdd(0);
}
//---------------------------------------------------------------------------

void __fastcall Tpam2HardwareForm::hardwareSATActionExecute(TObject *Sender)
{
	hardwareSATAction->Checked = !hardwareSATAction->Checked;
	if (hardwareSATAction->Checked)
	{
		 pamMainForm->SwitchSat(1);
	}
	else
		 pamMainForm->SwitchSat(0);
}
//---------------------------------------------------------------------------


void __fastcall Tpam2HardwareForm::hardwareACTActionExecute(TObject *Sender)
{
	hardwareACTAction->Checked = !hardwareACTAction->Checked;
	if (hardwareACTAction->Checked)
	{
		 pamMainForm->SwitchAct(1);
	}
	else
		 pamMainForm->SwitchAct(0);
}
//---------------------------------------------------------------------------


