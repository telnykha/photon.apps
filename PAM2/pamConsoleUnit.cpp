//---------------------------------------------------------------------------
#include <vcl.h>
#include "System.AnsiStrings.hpp"
#include "math.h"
#pragma hdrstop

#include "pamConsoleUnit.h"
#include "pamMainUnit.h"
#include "pamHardwareUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TConsoleForm *ConsoleForm;
//---------------------------------------------------------------------------
__fastcall TConsoleForm::TConsoleForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TConsoleForm::FormHide(TObject *Sender)
{
	if (Parent != NULL)
	{
		pamMainForm->ShowDockPanel(Parent, false, NULL);
	}
}
//---------------------------------------------------------------------------
void __fastcall TConsoleForm::FormShow(TObject *Sender)
{
	if (Parent != NULL)
	{
		pamMainForm->ShowDockPanel(Parent, true, NULL);
	}
}
//---------------------------------------------------------------------------
void __fastcall TConsoleForm::FormCreate(TObject *Sender)
{
	if (pamMainForm->Comm1->Enabled()) {
		Memo1->Lines->Add("Open "+pamMainForm->Comm1->DeviceName+" OK");
	}
}
//---------------------------------------------------------------------------

void __fastcall TConsoleForm::Button1Click(TObject *Sender)
{
	UnicodeString command = ComboBox1->Text.c_str();
	command = UpdateHardwarePanel(command);
	pamMainForm->ExecuteCommand(command);
}
static int FindValue(const UnicodeString& command)
{
	UnicodeString str = command;
	int pos = str.Pos(L"=");
	if (pos == 0)
		throw Exception(L"Недопустимый формат команды");
	str = str.SubString(pos+1, str.Length() - pos);
	return StrToInt(str);
}
static int FindExposureIndex(int value)
{
	int result = 0;
	double d = fabs((double)value - (double)c_exposure[0]);
	double min = d;
	for (int i = 0; i < 10; i++) {
		d = fabs((double)value - (double)c_exposure[i]);
		if (d < min) {
			 min = d;
			 result = i;
		}
	}
	return result;
}
//---------------------------------------------------------------------------
UnicodeString __fastcall TConsoleForm::UpdateHardwarePanel(const UnicodeString& command)
{
	UnicodeString cmd = command;
	cmd = ReplaceStr(cmd, L" ",L"");
	try
	{
		if (cmd.Pos(L"EXP=") !=  0)
		{
			// обновление PhTrackBar1, SpinEdit3, GroupBox1
			 int v = FindValue(cmd);
			 if (v >= 20 && v <=32000) {

				 pam2HardwareForm->PhTrackBar1->Position = FindExposureIndex(v);
				 pam2HardwareForm->SpinEdit3->Value = v;
			 }
			 else
				Memo1->Lines->Add(L"Значение параметра команды находится вне допустимого диапазона: " + cmd);
		}
		else if (cmd.Pos(L"GAIN=") != 0)
		{
			// обновление PhTrackBar2, SpinEdit2, GroupBox5
			 int v = FindValue(cmd);
			 if (v >= 6 && v <=41) {
				 pam2HardwareForm->PhTrackBar2->Position = v;
			 }
			 else
				Memo1->Lines->Add(L"Значение параметра команды находится вне допустимого диапазона: " + cmd);
		}
		else if (cmd.Pos(L"LFLASH=") != 0)
		{
			 // обновление PhTrackBar3, SpinEdit1, GroupBox6
			 int v = FindValue(cmd);
			 if (v >= 20 && v <=50) {
				 pam2HardwareForm->PhTrackBar3->Position = v;
			 }
			 else
				Memo1->Lines->Add(L"Значение параметра команды находится вне допустимого диапазона: " + cmd);
		}
		else if (cmd.Pos(L"LSAT=") != 0)
		{
			 // обновление PhTrackBar4, SpeedButton1
			 int v = FindValue(cmd);
			 if (v >= 0 && v <=100) {
				 pam2HardwareForm->PhTrackBar4->Position = v;
			 }
			 else
				Memo1->Lines->Add(L"Значение параметра команды находится вне допустимого диапазона: " + cmd);
		}
		else if (cmd.Pos(L"LACT=") != 0)
		{
			 // обновление PhTrackBar5, SpeedButton2
			 int v = FindValue(cmd);
			 if (v >= 0 && v <=100) {
				 pam2HardwareForm->PhTrackBar5->Position = v;
			 }
			 else
				Memo1->Lines->Add(L"Значение параметра команды находится вне допустимого диапазона: " + cmd);
		}
		else if (cmd.Pos(L"LADD=") != 0)
		{
			 // обновление PhTrackBar6, SpeedButton3
			 int v = FindValue(cmd);
			 if (v >= 0 && v <=100) {
				 pam2HardwareForm->PhTrackBar6->Position = v;
			 }
			 else
				Memo1->Lines->Add(L"Значение параметра команды находится вне допустимого диапазона: " + cmd);
		}
		else if (cmd.Pos(L"SAT=") != 0)
		{
			 // обновление SpeedButton1
			 int v = FindValue(cmd);
			 pam2HardwareForm->SpeedButton1->Down = v == 0? false:true;
		}
		else if (cmd.Pos(L"ACT=") != 0)
		{
			 // обновление SpeedButton2
			 int v = FindValue(cmd);
			 pam2HardwareForm->SpeedButton2->Down = v == 0? false:true;
		}
		else if (cmd.Pos(L"ADD=") != 0)
		{
			 // обновление SpeedButton3
			 int v = FindValue(cmd);
			 pam2HardwareForm->SpeedButton3->Down = v == 0? false:true;
		}
	}
	catch(Exception& e)
	{
		Memo1->Lines->Add(e.Message);
	}
	return cmd;
}


