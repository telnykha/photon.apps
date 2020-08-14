//----------------------------------------------------------------------------
#ifndef FormParamsUnitH
#define FormParamsUnitH
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
#include <Vcl.ComCtrls.hpp>
//----------------------------------------------------------------------------
class TParamsDlg : public TForm
{
__published:
	TButton *OKBtn;
	TButton *CancelBtn;
	TBevel *Bevel1;
	TLabel *Label1;
	TTrackBar *TrackBar1;
	TLabel *Label2;
	TTrackBar *TrackBar2;
	TLabel *Label3;
	TLabel *Label4;
	void __fastcall TrackBar1Change(TObject *Sender);
	void __fastcall TrackBar2Change(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:
	//double
public:
	virtual __fastcall TParamsDlg(TComponent* AOwner);

	double radius;
    double threshold;
};
//----------------------------------------------------------------------------
extern PACKAGE TParamsDlg *ParamsDlg;
//----------------------------------------------------------------------------
#endif    
