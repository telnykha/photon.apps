//---------------------------------------------------------------------------

#ifndef priExperimentUnitH
#define priExperimentUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.CheckLst.hpp>
#include <Vcl.Samples.Spin.hpp>
#include "_LF.h"
//---------------------------------------------------------------------------
class TShotItem : public TLFObjectList
{
protected:
	int m_FilterIndex;
	int m_LedStatus;
	int m_Exposure;
	int m_Focus;
	int m_Aperture;
	int m_Status; /*0 - ожидание, 1 - выполениние, 2 - записано*/

	int GetStatus();
	int SetStatus(int value);

public:
	TShotItem(int filter, int led, int exposhure, int focus, int aperture);
	virtual ~TShotItem();

	__property int FilterIndex = {read = m_FilterIndex};
	__property int LedStatus = {read = m_LedStatus} ;
	__property int Exposure = {read = m_Exposure};
	__property int Focus = {read = m_Focus};
	__property int Aperture = {read = m_Aperture};
	__property int Status = {read = GetStatus, write = SetStatus}; /*0 - ожидание, 1 - выполениние, 2 - записано*/
};


class TexperimentForm : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TButton *Button1;
	TCheckListBox *CheckListBox1;
	TGroupBox *GroupBox2;
	TLabel *Interval;
	TLabel *Label2;
	TSpinEdit *seriesIntervalSE;
	TSpinEdit *seriesTotalSE;
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
	void __fastcall MakeExperimentList();
	TLFObjectList* __fastcall  GetShots();
	TLFObjectList m_list;
public:		// User declarations
	__fastcall TexperimentForm(TComponent* Owner);
	__property TLFObjectList* shots = {read = GetShots};

};
//---------------------------------------------------------------------------
extern PACKAGE TexperimentForm *experimentForm;
//---------------------------------------------------------------------------
#endif
