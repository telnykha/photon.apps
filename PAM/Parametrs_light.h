//---------------------------------------------------------------------------

#ifndef Parametrs_lightH
#define Parametrs_lightH
//---------------------------------------------------------------------------
#include "IniFileUnit.h"
#include "MainUnit.h"
#include "pam_common.h"
#include "cammandsTable.h"
#include "diff_table.h"
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Samples.Spin.hpp>
//---------------------------------------------------------------------------
class TFormLight : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TPanel *Panel2;
	TSplitter *Splitter1;
	TPanel *Panel3;
	TLabel *LightSetting;
	TPanel *Panel4;
	TPanel *Panel5;
	TPanel *Panel6;
	TTrackBar *TrackBar1;
	TPanel *Panel7;
	TTrackBar *TrackBar2;
	TSpinEdit *SpinEdit1;
	TSpinEdit *SpinEdit2;
	TLabel *Label1;
	TLabel *Label2;
	TPanel *Panel8;
	TPanel *Panel9;
	TSplitter *Splitter2;
	TSplitter *Splitter3;
	TLabel *Label3;
	TPanel *Panel11;
	TPanel *Panel10;
	TGroupBox *GroupBox1;
	TGroupBox *GroupBox2;
	TTrackBar *TrackBar4;
	TLabel *Label5;
	TTrackBar *TrackBar3;
	TLabel *Label4;
	TGroupBox *GroupBox3;
	TGroupBox *GroupBox4;
	TSpinEdit *SpinEdit3;
	TLabel *Label6;
	TLabel *Label7;
	TSpinEdit *SpinEdit4;
	TLabel *Label8;
	TLabel *Label9;
	TSplitter *Splitter4;
	TPanel *Panel13;
	TTrackBar *TrackBar5;
	TPanel *Panel14;
	TSpinEdit *SpinEdit5;
	TComboBox *ComboBox1;
	TPanel *Panel12;
	TPanel *Panel15;
	TPanel *Panel16;
	TPanel *Panel17;
	TTrackBar *TrackBar6;
	TTrackBar *TrackBar7;
	TPanel *Panel18;
	TPanel *Panel19;
	TSplitter *Splitter5;
	TSpinEdit *SpinEdit6;
	TSpinEdit *SpinEdit7;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall TrackBar3Change(TObject *Sender);
	void __fastcall SpinEdit4Change(TObject *Sender);
	void __fastcall SpinEdit3Change(TObject *Sender);
	void __fastcall TrackBar4Change(TObject *Sender);
	void __fastcall ComboBox1Change(TObject *Sender);
private:	// User declarations
TCommandsTable* m_table;
TPAMOptions 	m_light_options;
TmainPAM*        m;
double __fastcall ExploshureTime(int index, int pos);
public:		// User declarations
	__fastcall TFormLight(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormLight *FormLight;
//---------------------------------------------------------------------------
#endif
