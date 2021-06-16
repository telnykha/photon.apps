//---------------------------------------------------------------------------

#ifndef pamDistributionUnitH
#define pamDistributionUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.CheckLst.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <VCLTee.Chart.hpp>
#include <VCLTee.Series.hpp>
#include <VclTee.TeeGDIPlus.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
#include <System.Actions.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Menus.hpp>
//---------------------------------------------------------------------------
class Tpam2ROIForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TPopupMenu *PopupMenu1;
	TActionList *ActionList1;
	TStatusBar *StatusBar1;
	TStringGrid *StringGrid1;
	TAction *roiDeleteAction;
	TAction *roiClearAction;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *N3;
	TMenuItem *N4;
	TMenuItem *N5;
	TMenuItem *N6;
	TMenuItem *N7;
	TMenuItem *N8;
	void __fastcall StringGrid1Click(TObject *Sender);
	void __fastcall roiDeleteActionExecute(TObject *Sender);
	void __fastcall roiDeleteActionUpdate(TObject *Sender);
	void __fastcall roiClearActionExecute(TObject *Sender);
	void __fastcall roiClearActionUpdate(TObject *Sender);
private:	// User declarations
    bool    m_empty;
	void __fastcall DeleteRecord(int index);
	void __fastcall SetItem(int idx, TPam2ROI* item);
public:		// User declarations
	__fastcall Tpam2ROIForm(TComponent* Owner);

	void __fastcall AddItem(TPam2ROI* item);
	void __fastcall NewImage(awpImage* image);
	void __fastcall ChangeItem(int index);
};
//---------------------------------------------------------------------------
extern PACKAGE Tpam2ROIForm *pam2ROIForm;
//---------------------------------------------------------------------------
#endif
