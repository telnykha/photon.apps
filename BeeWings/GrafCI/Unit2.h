// ---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <VCLTee.Chart.hpp>
#include <VCLTee.Series.hpp>
#include <VclTee.TeeGDIPlus.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
#include <_LF.h>
#include <VCLTee.TeeShape.hpp>
#include <VCLTee.TeeSpline.hpp>
#include <SHDocVw.hpp>
#include <Vcl.OleCtrls.hpp>
#include "BeeKinds.h"
#include "BeeFeatures.h"
#include <Vcl.Dialogs.hpp>

// #include "Signs.cpp"
// ---------------------------------------------------------------------------
class TForm2 : public TForm {
__published: // IDE-managed Components
	TPageControl *Unit1;
	TTabSheet *Индексы;
	TTabSheet *График_CI1;
	TTabSheet *График_CI;
	TTabSheet *График_DsA;
	TTabSheet *График_HI;
	TTabSheet *Анализ;
	TStringGrid *StringGrid1;
	TChart *Chart1;
	TBarSeries *Series1;
	TChart *Chart2;
	TBarSeries *Series2;
	TLineSeries *Series3;
	TChart *Chart3;
	TBarSeries *Series4;
	TLineSeries *Series5;
	TTabSheet *Результаты;
	TStringGrid *StringGrid3;
	TLineSeries *Series6;
	TPanel *Panel1;
	TPanel *Panel2;
	TChart *Chart5;
	TPointSeries *Series16;
	TSplitter *Splitter1;
	TPanel *Panel3;
	TChart *Chart6;
	TSplitter *Splitter2;
	TPanel *Panel4;
	TChart *Chart4;
	TPanel *Panel5;
	TSplitter *Splitter3;
	TWebBrowser *WebBrowser1;
	TOpenDialog *OpenDialog1;
	TPopupMenu *PopupMenu1;
	TMenuItem *PopupMenu11;
	TMenuItem *N1;
	TMenuItem *N2;
	TPointSeries *Series8;
	TPointSeries *Series9;

	void __fastcall FormCreate(TObject *Sender);
	void __fastcall N2Click(TObject *Sender);
	void __fastcall PopupMenu11Click(TObject *Sender);

private: // User declarations
	TLFHistogramm hstCI, hstDsA, hstHI;
	BeeKinds b;
	//bool GetBeeFeatures(TLFLandmarkFile* file, double& Ci, double& DsA,double& Hi);

public: // User declarations
	__fastcall TForm2(TComponent* Owner);
	void Update(const char* path, TLFDBLandmarks* db);
};

// ---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
// ---------------------------------------------------------------------------
#endif
