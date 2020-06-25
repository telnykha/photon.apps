//---------------------------------------------------------------------------

#ifndef PriSpatialCalibrationH
#define PriSpatialCalibrationH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "FImage41.h"
#include <Vcl.ExtCtrls.hpp>
#include "PriSpatialCalibrationUnit.h"
#include "PhImageTool.h"
#include "PhPaneTool.h"
//---------------------------------------------------------------------------
class TSpatialCalibrationDlg : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TButton *Button2;
	TPhImage *PhImage1;
	TPhImage *PhImage2;
	TPhImage *PhImage3;
	TButton *Button3;
	TPhImage *PhImage4;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TPhPaneTool *PhPaneTool1;
	TPhPaneTool *PhPaneTool2;
	TPhPaneTool *PhPaneTool3;
	TPhPaneTool *PhPaneTool4;
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
   //	TPriSpatialCalibration m_calibration;
	void __fastcall UpdateUI();
public:		// User declarations
	__fastcall TSpatialCalibrationDlg(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSpatialCalibrationDlg *SpatialCalibrationDlg;
//---------------------------------------------------------------------------
#endif
