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
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall OKBtnClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:
	TPriCalibration m_calibration;
	void __fastcall UpdateUI();
public:
	virtual __fastcall TCalibrationDlg(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern PACKAGE TCalibrationDlg *CalibrationDlg;
//----------------------------------------------------------------------------
#endif    
