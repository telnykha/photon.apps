//---------------------------------------------------------------------------

#ifndef pamHardwareUnitH
#define pamHardwareUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Samples.Spin.hpp>
#include "PhTrackBar.h"
#include <Vcl.Buttons.hpp>
#include <System.Actions.hpp>
#include <Vcl.ActnList.hpp>
//---------------------------------------------------------------------------
class Tpam2HardwareForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel6;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TGroupBox *GroupBox1;
	TGroupBox *GroupBox5;
	TGroupBox *GroupBox6;
	TPhTrackBar *PhTrackBar1;
	TPanel *Panel1;
	TSpinEdit *SpinEdit3;
	TPanel *Panel2;
	TSpinEdit *SpinEdit2;
	TPhTrackBar *PhTrackBar2;
	TPanel *Panel3;
	TSpinEdit *SpinEdit1;
	TPhTrackBar *PhTrackBar3;
	TGroupBox *GroupBox2;
	TPhTrackBar *PhTrackBar4;
	TSpeedButton *SpeedButton1;
	TLabel *Label4;
	TSpeedButton *SpeedButton2;
	TLabel *Label5;
	TPhTrackBar *PhTrackBar5;
	TPhTrackBar *PhTrackBar6;
	TLabel *Label6;
	TSpeedButton *SpeedButton3;
	TActionList *ActionList1;
	TAction *hardwareSATAction;
	TAction *hardwareACTAction;
	void __fastcall PhTrackBar1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall PhTrackBar1Change(TObject *Sender);
	void __fastcall SpinEdit3Change(TObject *Sender);
	void __fastcall PhTrackBar2Change(TObject *Sender);
	void __fastcall PhTrackBar2MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall SpinEdit2Change(TObject *Sender);
	void __fastcall PhTrackBar3MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall PhTrackBar3Change(TObject *Sender);
	void __fastcall SpinEdit1Change(TObject *Sender);
	void __fastcall SpinEdit3Exit(TObject *Sender);
	void __fastcall PhTrackBar4Change(TObject *Sender);
	void __fastcall PhTrackBar4MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall PhTrackBar5Change(TObject *Sender);
	void __fastcall PhTrackBar5MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall PhTrackBar6Change(TObject *Sender);
	void __fastcall PhTrackBar6MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall SpeedButton3Click(TObject *Sender);
	void __fastcall hardwareSATActionExecute(TObject *Sender);
	void __fastcall hardwareACTActionExecute(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall Tpam2HardwareForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tpam2HardwareForm *pam2HardwareForm;
//---------------------------------------------------------------------------
#endif
