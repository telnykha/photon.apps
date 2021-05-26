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
const int c_exposure[10]= {50,100,250,500,1000,2000,4000,8000,16000,32000};
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
   SpinEdit3->Value = exposhure;
   GroupBox1->Caption = L"Экспозиция " + IntToStr(exposhure) + L" mks";
}
//---------------------------------------------------------------------------
void __fastcall Tpam2HardwareForm::SpinEdit3Change(TObject *Sender)
{
	pamMainForm->SetExposure(SpinEdit3->Value);
	GroupBox1->Caption = L"Экспозиция " + IntToStr(SpinEdit3->Value) + L" mks";
}
//---------------------------------------------------------------------------
void __fastcall Tpam2HardwareForm::PhTrackBar2Change(TObject *Sender)
{
	int v = PhTrackBar2->Position;
	GroupBox5->Caption = L"Усиление " + IntToStr(v) + L" dB";
    SpinEdit2->Value = v;
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
	PhTrackBar2->Position = SpinEdit2->Value;
	PhTrackBar2->OnChange =e;
	pamMainForm->SetGain(SpinEdit2->Value);
}
//---------------------------------------------------------------------------
void __fastcall Tpam2HardwareForm::PhTrackBar3MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
//
}
//---------------------------------------------------------------------------
void __fastcall Tpam2HardwareForm::PhTrackBar3Change(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------
void __fastcall Tpam2HardwareForm::SpinEdit1Change(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------
