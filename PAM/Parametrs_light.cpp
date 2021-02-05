//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Parametrs_light.h"
#include "pam_common.h"
#include "cammandsTable.h"
#include "diff_table.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormLight *FormLight;
//---------------------------------------------------------------------------
__fastcall TFormLight::TFormLight(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

double __fastcall TFormLight::ExploshureTime(int index, int pos)
{
double exp_start = c_expLimit[index] / 100.;
double exp = exp_start*pos;
int exp_mks = floor(exp*1000 + 0.5);
	int exp_units = exp_mks / 50;
GroupBox1->Caption = L"Экспозиция " + IntToStr(exp_mks) + L" mks";

   m_light_options.exploshureIndex = index;
   m_light_options.exploshureValue = pos;

int delay = 500 / exp_mks;

SpinEdit3->MinValue = delay + 1;
if (SpinEdit3->Value < SpinEdit3->MinValue)
	SpinEdit3->Value = SpinEdit3->MinValue;

	SpinEdit3Change(NULL);
	SpinEdit4Change(NULL);


return exp;
}
void __fastcall TFormLight::FormShow(TObject *Sender)
{
ComboBox1->ItemIndex = m_light_options.exploshureIndex;
if (m_table != NULL)
		m_table->changed = true;
m_light_options.freeze = false;
}
//---------------------------------------------------------------------------

void __fastcall TFormLight::SpinEdit4Change(TObject *Sender)
{
int exp = m_light_options.Exposure;
	int value = exp*SpinEdit4->Value / 100;
	m_light_options.exploshureIndex = ComboBox1->ItemIndex;
	Label9->Caption = IntToStr(value) + L" mks";
	m_light_options.Length = SpinEdit4->Value;
	if (m_table != NULL)
		m_table->changed = true;
}
//---------------------------------------------------------------------------

void __fastcall TFormLight::SpinEdit3Change(TObject *Sender)
{
int exp = m_light_options.Exposure;
	int value = exp*SpinEdit3->Value / 100;
	m_light_options.exploshureIndex = ComboBox1->ItemIndex;
	Label7->Caption = IntToStr(value) + L" mks";
	m_light_options.Delay = SpinEdit3->Value;
	if (m_table != NULL)
		m_table->changed = true;
}
//---------------------------------------------------------------------------
void __fastcall TFormLight::TrackBar3Change(TObject *Sender)
{
	ExploshureTime(ComboBox1->ItemIndex,  TrackBar3->Position);
	m_light_options.exploshureValue = TrackBar3->Position;
	if (m_table != NULL)
		m_table->changed = true;

}
//---------------------------------------------------------------------------


void __fastcall TFormLight::TrackBar4Change(TObject *Sender)
{
	int v = TrackBar4->Position;
	GroupBox2->Caption = L"Усиление " + IntToStr(v) + L" dB";
	m_light_options.Gain = v;

	if (m_table != NULL)
		m_table->changed = true;
}
//---------------------------------------------------------------------------

void __fastcall TFormLight::ComboBox1Change(TObject *Sender)
{

   ExploshureTime(ComboBox1->ItemIndex,  TrackBar3->Position);
	m_light_options.exploshureIndex = ComboBox1->ItemIndex;
	if (m_table != NULL)
		m_table->changed = true;

}
//---------------------------------------------------------------------------




