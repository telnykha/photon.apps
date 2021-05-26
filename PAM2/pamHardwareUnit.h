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
//---------------------------------------------------------------------------
class Tpam2HardwareForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel6;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TGroupBox *GroupBox3;
	TTrackBar *TrackBar3;
	TGroupBox *GroupBox2;
	TTrackBar *TrackBar2;
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
private:	// User declarations
public:		// User declarations
	__fastcall Tpam2HardwareForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tpam2HardwareForm *pam2HardwareForm;
//---------------------------------------------------------------------------
#endif
