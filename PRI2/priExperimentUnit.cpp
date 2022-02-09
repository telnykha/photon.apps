//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "priExperimentUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TexperimentForm *experimentForm;

TShotItem::TShotItem(int filter, int led, int exposure, int focus,  int aperture)
{
	m_FilterIndex = filter;
	m_LedStatus = led;
	m_Exposure = exposure;
	m_Focus = focus ;
	m_Aperture = aperture;
	m_Status = 0;
}
TShotItem::~TShotItem()
{

}
int TShotItem::GetStatus()
{
	return m_Status;
}
int TShotItem::SetStatus(int value)
{
	m_Status = value;
}


//---------------------------------------------------------------------------
__fastcall TexperimentForm::TexperimentForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TexperimentForm::Button1Click(TObject *Sender)
{
	//
	int numChecked = 0;
	for (int i = 0; i < CheckListBox1->Items->Count; i++)
	{
		if (CheckListBox1->Checked[i])
		   numChecked++;
	}
	if (numChecked < 2)
	{
		ShowMessage("Необходимо выбрать минимум два фильтра.");
		return;
	}


}
//---------------------------------------------------------------------------
void __fastcall TexperimentForm::MakeExperimentList()
{
	  m_list.Clear();

	  for (int i = 0; i < seriesTotalSE->Value; i++)
	  {

	  }
}

TLFObjectList* __fastcall  TexperimentForm::GetShots()
{
	return &m_list;
}
