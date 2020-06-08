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
//----------------------------------------------------------------------------
class TCalibrationDlg : public TForm
{
__published:
	TButton *OKBtn;
	TButton *CancelBtn;
	TBevel *Bevel1;
	TButton *Button1;
	TButton *Button2;
	TPhImage *PhImage1;
	void __fastcall Button1Click(TObject *Sender);
private:
public:
	virtual __fastcall TCalibrationDlg(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern PACKAGE TCalibrationDlg *CalibrationDlg;
//----------------------------------------------------------------------------
#endif    
