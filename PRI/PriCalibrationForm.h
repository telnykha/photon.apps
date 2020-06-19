//----------------------------------------------------------------------------
#ifndef PriCalibrationFormH
#define PriCalibrationFormH
//----------------------------------------------------------------------------
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Graphics.hpp>
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <Winapi.Windows.hpp>
#include <System.hpp>
#include "FImage41.h"
#include "ArchiveUnit.h"
#include "PriCalibration.h"
#include "PhImageTool.h"
#include "PhSelectRectTool.h"
//----------------------------------------------------------------------------
class TCalibrationDlg : public TForm
{
__published:
	TButton *OKBtn;
	TButton *CancelBtn;
	TBevel *Bevel1;
	TButton *Button1;
	TPhImage *PhImage1;
	TSpeedButton *SpeedButton1;
	TSpeedButton *SpeedButton2;
	TSpeedButton *SpeedButton3;
	TSpeedButton *SpeedButton4;
	TLabel *Label1;
	TComboBox *ComboBox1;
	TGroupBox *GroupBox1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TPhSelRectTool *PhSelRectTool1;
	TGroupBox *GroupBox2;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall OKBtnClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall SpeedButton2Click(TObject *Sender);
	void __fastcall SpeedButton3Click(TObject *Sender);
	void __fastcall SpeedButton4Click(TObject *Sender);
	void __fastcall ComboBox1Change(TObject *Sender);
	void __fastcall PhImage1MouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall PhImage1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall FormCreate(TObject *Sender);

private:
	void __fastcall UpdateUI();
	awpImage* GetSelectedImage();
public:
	virtual __fastcall TCalibrationDlg(TComponent* AOwner);
	TPriCalibration m_calibration;
};
//----------------------------------------------------------------------------
extern PACKAGE TCalibrationDlg *CalibrationDlg;
//----------------------------------------------------------------------------
#endif    
