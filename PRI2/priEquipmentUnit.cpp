//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "priEquipmentUnit.h"
#include "priMainUnit.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tpri2EquipmentForm *pri2EquipmentForm;
//---------------------------------------------------------------------------
__fastcall Tpri2EquipmentForm::Tpri2EquipmentForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tpri2EquipmentForm::FormShow(TObject *Sender)
{
	Label3->Caption = IntToStr(priMainForm->exposure / 1000) + " mc";

	TNotifyEvent e = TrackBar1->OnChange;
	TrackBar1->OnChange = NULL;
	TrackBar1->Position  = priMainForm->exposure / 1000;
	TrackBar1->OnChange = e;

	Label8->Caption  = priMainForm->arduinoPort;
	Label9->Caption  = priMainForm->arduinoStatus;
	Label10->Caption = priMainForm->arduinoSN;

	Label12->Caption = priMainForm->ascomStatus;
	Edit1->Text      = priMainForm->ascomFocus;

	e = ComboBox2->OnChange;
	ComboBox2->OnChange = NULL;
	ComboBox2->ItemIndex = priMainForm->efwPosition;
	ComboBox2->OnChange =  e;

	Label18->Caption = priMainForm->efwStatus;
	Label20->Caption = L"Готов";
	SpeedButton1Click(NULL);
}
//---------------------------------------------------------------------------

void __fastcall Tpri2EquipmentForm::SpeedButton1Click(TObject *Sender)
{
	priMainForm->videoMode = 0;
}
//---------------------------------------------------------------------------

void __fastcall Tpri2EquipmentForm::TrackBar1Change(TObject *Sender)
{
	// установка экспозиции видеокамеры
	priMainForm->exposure = 1000*TrackBar1->Position;
	// отображение экспозиции в миллисекундах
	Label3->Caption = IntToStr(priMainForm->exposure / 1000) + " mc";
	// сохранение экспозиции для выбранного фильтра в конфигурационном файле
	int index = ComboBox2->ItemIndex;
	TPriFilter*  filter = priMainForm->iniFile->Filter[index];
	if (filter != NULL)
		filter->exposure = priMainForm->exposure / 1000;
}
//---------------------------------------------------------------------------

void __fastcall Tpri2EquipmentForm::SpeedButton2Click(TObject *Sender)
{
	priMainForm->videoMode = 1;
}
//---------------------------------------------------------------------------

void __fastcall Tpri2EquipmentForm::Button2Click(TObject *Sender)
{
	  if (priMainForm->ledState == 0)
	  {
		priMainForm->ledState = 1;
		Button2->Caption = L"ВКЛ";
	  }
	  else
	  {
		priMainForm->ledState = 0;
		Button2->Caption = L"ВЫКЛ";
	  }
}
//---------------------------------------------------------------------------


void __fastcall Tpri2EquipmentForm::Button1Click(TObject *Sender)
{
	 priMainForm->TakePicture();
}
//---------------------------------------------------------------------------

void __fastcall Tpri2EquipmentForm::Button9Click(TObject *Sender)
{
/*	 AnsiString str = "M";
	 str += Edit1->Text;
	 str += "#";
	 priMainForm->AscomCommand(str);
	 str = "P#";
	 priMainForm->AscomCommand(str);*/
	 priMainForm->ascomFocus = Edit1->Text;
}
//---------------------------------------------------------------------------

void __fastcall Tpri2EquipmentForm::Button3Click(TObject *Sender)
{
	 int value = StrToInt(Edit1->Text) - 100;
	 priMainForm->ascomFocus = IntToStr(value);

}
//---------------------------------------------------------------------------

void __fastcall Tpri2EquipmentForm::Button4Click(TObject *Sender)
{
	 int value = StrToInt(Edit1->Text) - 10;
	 priMainForm->ascomFocus = IntToStr(value);
}
//---------------------------------------------------------------------------

void __fastcall Tpri2EquipmentForm::Button5Click(TObject *Sender)
{
	 int value = StrToInt(Edit1->Text) - 1;
	 priMainForm->ascomFocus = IntToStr(value);
}
//---------------------------------------------------------------------------

void __fastcall Tpri2EquipmentForm::Button6Click(TObject *Sender)
{
	 int value = StrToInt(Edit1->Text) + 1;
	 priMainForm->ascomFocus = IntToStr(value);
}
//---------------------------------------------------------------------------

void __fastcall Tpri2EquipmentForm::Button7Click(TObject *Sender)
{
	 int value = StrToInt(Edit1->Text) + 10;
	 priMainForm->ascomFocus = IntToStr(value);
}
//---------------------------------------------------------------------------

void __fastcall Tpri2EquipmentForm::Button8Click(TObject *Sender)
{
	 int value = StrToInt(Edit1->Text) + 100;
	 priMainForm->ascomFocus = IntToStr(value);
}
//---------------------------------------------------------------------------

void __fastcall Tpri2EquipmentForm::ComboBox1Change(TObject *Sender)
{
	priMainForm->ascomAperture = ComboBox1->ItemIndex;
}
//---------------------------------------------------------------------------

void __fastcall Tpri2EquipmentForm::ComboBox2Change(TObject *Sender)
{
 //  priMainForm->efwPosition = ComboBox2->ItemIndex;
	 priMainForm->SetupFilter(ComboBox2->ItemIndex);
}
//---------------------------------------------------------------------------
void __fastcall Tpri2EquipmentForm::UpdateExposure(int exposure)
{
	TNotifyEvent e = TrackBar1->OnChange;
	TrackBar1->OnChange = NULL;
	TrackBar1->Position  = priMainForm->exposure / 1000;
	Label3->Caption 	 = IntToStr(priMainForm->exposure / 1000) + " mc";
	TrackBar1->OnChange = e;
}

