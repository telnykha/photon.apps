//---------------------------------------------------------------------------
#include <vcl.h>
#include <process.h>
#pragma hdrstop

#include "priMainUnit.h"
#include "priEquipmentUnit.h"
#include "priExperimentUnit.h"
#include "phserialport.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FImage41"
#pragma link "Comm"
#pragma resource "*.dfm"
TpriMainForm *priMainForm;
#pragma link "awplflibb.lib"
extern "C"
{
	#include "pylon\driver\pylonwrapper\pylonwrapper.h"
	#pragma link "pylonwrapper.lib"
	#pragma link "phserialport.lib"
	#pragma link "EFW_filter.lib"
}

void ImageEvent(int frame, int w, int h, void* p)
{
	awpImage* img = NULL;
	awpCreateImage(&img, w,h,1, AWP_BYTE);
	AWPBYTE* b = (AWPBYTE*)img->pPixels;
	memcpy(b, p, w*h*sizeof(AWPBYTE));
	// todo: protect this code
	priMainForm->m_Image.SetImage(img);

	awpReleaseImage(&img);
	priMainForm->Caption = IntToStr(frame);

	SendMessage(priMainForm->Handle,WM_USER+1, 0,0 );

}
//---------------------------------------------------------------------------
__fastcall TpriMainForm::TpriMainForm(TComponent* Owner)
	: TForm(Owner)
{
	m_hardware_ready = false;
	m_programMode = pmTuning;
	m_setupInProgress = false;
}

void __fastcall TpriMainForm::WMUSER1(TMessage & msg)
{
	priMainForm->PhImage1->SetAwpImage(m_Image.GetImage());
	//if (videoMode == 1)
	//	ShowMessage("Yes!");
}

//---------------------------------------------------------------------------
void __fastcall TpriMainForm::fileCloseActionExecute(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TpriMainForm::FormCreate(TObject *Sender)
{
// connect to hardware
	camera =  wpCreateCamera(ImageEvent);
	m_hardware_ready = true;
	if (camera == NULL)
	{
		ShowMessage("Не могу подкоючиться к видеокамере!");
		m_hardware_ready = false;
	}
	try
	{

		 if (wpConnect(camera))
		 {
			 UnicodeString str = wpCameraName(camera);
			 StatusBar1->Panels->Items[0]->Text = str;
			 wpCameraSetExposure(camera, 100000);
			 m_exposure = wpCameraGetExposure(camera);
			 wpCameraSetMode(camera, 0);
		 }
		 else
		 {
			ShowMessage("Не могу подкоючиться к видеокамере!");
			m_hardware_ready = false;

		 }
	}
	catch(...)
	{
		ShowMessage("Не могу подкоючиться к видеокамере!");
		m_hardware_ready = false;
	}

	 UnicodeString deviceName = this->FindArduinoDevice();
	if (deviceName == L"") {
		m_hardware_ready = false;
		return;
	}
	try
	{
		Comm1->DeviceName = deviceName;//L"COM5";
		Comm1->Open();
		Comm1->SetRTSState(true);
		Comm1->SetDTRState(true);
		m_arduinoStatus = L"OK";
	}
	catch(Exception& e)
	{
		ShowMessage(e.Message);
		m_arduinoStatus = L"FAIL";

		//return;
	}
	m_arduinoPort =  deviceName;
	deviceName = this->FindASCOMDevice();
	if (deviceName == L"") {
		m_hardware_ready = false;
	}
	try
	{
		Comm2->DeviceName = deviceName;//L"COM5";

		Comm2->Open();
		Comm2->SetRTSState(true);
		Comm2->SetDTRState(true);
		AnsiString command = "P#";
		AscomCommand(command);
		ascomAperture = 0;
		m_strAscomStatus = L"ОК";
	}
	catch(Exception& e)
	{
		ShowMessage(e.Message);
		m_strAscomStatus = "FAIL";
		m_hardware_ready = false;
	}

	m_ascomPort = deviceName;
	int num = EFWGetNum();
	if (num != 1)
	{
		ShowMessage("Проблемы с EFW!");
		m_hardware_ready = false;
	}
	int efw_id = 0;
	if(EFWGetID(0, &efw_id) == EFW_SUCCESS)
	{
		EFW_INFO info;
		info.ID = efw_id;
		EFW_ERROR_CODE code = EFWOpen(efw_id);
		if ( code == EFW_SUCCESS)
		{
			EFWGetProperty(efw_id, &info);
			this->m_info = info;
			EFWGetPosition(efw_id, &m_efwPosition);
			m_strEFWStatus = L"OK";
		}
		else
		{
			m_hardware_ready = false;
			m_strEFWStatus = L"FAIL";

		}
	}
	else
	{
		m_hardware_ready = false;
		m_strEFWStatus = L"FAIL";
	}

	m_iniFile.Load();
}
//---------------------------------------------------------------------------

void __fastcall TpriMainForm::FormClose(TObject *Sender, TCloseAction &Action)
{
    ascomFocus = 10000;
	wpFreeCamera(camera);
	EFWClose(0);

}
//---------------------------------------------------------------------------

void __fastcall TpriMainForm::startActionExecute(TObject *Sender)
{
	wpStart(camera);
}
//---------------------------------------------------------------------------

void __fastcall TpriMainForm::stopActionExecute(TObject *Sender)
{
	wpStop(camera);
}
//---------------------------------------------------------------------------



void __fastcall TpriMainForm::FormCloseQuery(TObject *Sender, bool &CanClose)
{
	if (wpIsGrabbing(camera))
	{
		 wpStop(camera);
//		 CanClose = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TpriMainForm::Comm1RxChar(TObject *Sender, DWORD Count)
{
	int i , Bytes ;
	char rb[5000], ts[5000];
	memset(rb, 0, sizeof(rb));
	memset(ts, 0, sizeof(ts));
	Bytes = Comm1->Read(rb, Count);
	if (Bytes>0)
	{
		for (i=0;i<Bytes;i++)
		{
			if ((rb[i] ==  0))
			  { ; }
			 else if (/*rb[i]=='\n' ||*/ rb[i] == '\r')
				{
					if (m_programMode == pmTuning)
					{
//						this->m_pam2Doc.AddEvent(rs);
						//ShowMessage(rs);
					}
					else
					{
/*
						ConsoleForm->Memo1->Lines->Add(TimeToStr(Time()) +L">" + rs);
						if (pam2ScriptForm->Script->IsRunning) {
							Timer2->Interval = 50;
							Timer2->Enabled  = true;
							Timer3->Enabled = false;
						}
						if (m_initArduino) {
							Timer4->Interval = 250;
							Timer4->Enabled  = true;
						}
*/
					}
					rs="" ;
			}
			  else
			  {
				sprintf(ts,"%c",rb[i]); rs=rs+ts;
			  }
		}
	}

}
//---------------------------------------------------------------------------
UnicodeString __fastcall TpriMainForm::FindArduinoDevice()
{
	UnicodeString result = L"";
	phserialPortInit();
	int c;
	phserialPortCount(c);
	for (int i = 0; i < c; i++)
	{
		char buf[PHSERIAL_BUF];
		AnsiString _strLocation = phserialPortLocation(buf, i);
		AnsiString _strDescription = phserialPortDescription(buf, i);
		bool value = false;
		phserialPortHasVendorIdentifier(value, i);
		unsigned short value1;
		if (value) {

			phserialPortVendorIdentifier(value1, i);
		}

			if (value1 == 9025) {
				 result =  _strLocation;
				 m_arduinoSN = phserialPortSerialNumber(buf, i);
				 break;
			}
	}
	phserialPortFree();
	return result;

}

UnicodeString __fastcall TpriMainForm::FindASCOMDevice()
{
	UnicodeString result = L"";
	phserialPortInit();
	int c;
	phserialPortCount(c);
	for (int i = 0; i < c; i++)
	{
		char buf[PHSERIAL_BUF];
		AnsiString _strLocation = phserialPortLocation(buf, i);
		AnsiString _strDescription = phserialPortDescription(buf, i);
		bool value = false;
		phserialPortHasVendorIdentifier(value, i);
		unsigned short value1;
		if (value) {

			phserialPortVendorIdentifier(value1, i);
		}

			if (value1 == 1027) {
				 result =  _strLocation;
				 break;
			}
	}
	phserialPortFree();
	return result;
}

void __fastcall TpriMainForm::modeTuningActionExecute(TObject *Sender)
{
	experimentForm->Visible = false;
	m_programMode = pmTuning;
	pri2EquipmentForm->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TpriMainForm::modeTuningActionUpdate(TObject *Sender)
{
	modeTuningAction->Checked = m_programMode == pmTuning;
}
//---------------------------------------------------------------------------

void __fastcall TpriMainForm::modeExperimentActionExecute(TObject *Sender)
{
	pri2EquipmentForm->Visible = false;
	m_programMode = pmExperiment;
	experimentForm->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TpriMainForm::modeExperimentActionUpdate(TObject *Sender)
{
	modeExperimentAction->Enabled = m_hardware_ready;
	modeExperimentAction->Checked = m_programMode == pmExperiment;
}
//---------------------------------------------------------------------------

void __fastcall TpriMainForm::FormShow(TObject *Sender)
{
	modeTuningActionExecute(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TpriMainForm::SetExposure(const int value)
{
	m_exposure = value;
	wpCameraSetExposure(camera, m_exposure);
	// update control on the equipment form
	pri2EquipmentForm->UpdateExposure(m_exposure);
}

int  __fastcall TpriMainForm::GetVideoMode()
{
	return wpCameraGetMode(camera);
}
void __fastcall TpriMainForm::SetVideoMode(int value)
{
	if (value == 0)
		wpStart(camera);
	else
		wpStop(camera);

	wpCameraSetMode(camera, value);
	wpStart(camera);
}

void __fastcall TpriMainForm::SetLedState(int value)
{
	m_ledState = value;

	AnsiString str;
	char wb[256] ;
	int i ;

	if (m_ledState == 0)
	   str = "3";
	else
		str = "2";

	sprintf(wb,"%s",str.c_str());
	i = Comm1->Write(wb, str.Length()+1);
}

void __fastcall TpriMainForm::TakePicture()
{
	//


	AnsiString str = "1";
	char wb[256] ;
	int i ;
	sprintf(wb,"%s",str.c_str());
	i = Comm1->Write(wb, str.Length()+1);
}

void __fastcall TpriMainForm::AscomCommand(AnsiString& command)
{
	char wb[256] ;
	int i ;
	sprintf(wb,"%s",command.c_str());
	i = Comm2->Write(wb, command.Length());
}

void __fastcall TpriMainForm::Comm2RxChar(TObject *Sender, DWORD Count)
{
	int i , Bytes ;
	char rb[5000], ts[5000];
	memset(rb, 0, sizeof(rb));
	memset(ts, 0, sizeof(ts));
	Bytes = Comm2->Read(rb, Count);
	if (Bytes>0)
	{
		for (i=0;i<Bytes;i++)
		{
			if ((rb[i] ==  0))
			  { ; }
			 else if (rb[i] == '#')
				{
					if (m_programMode == pmTuning)
					{
						m_strFocus = ars;
						pri2EquipmentForm->Edit1->Text =m_strFocus;
					}
					else
					{

					}
					ars="" ;
			}
			  else
			  {
				sprintf(ts,"%c",rb[i]); ars=ars+ts;
			  }
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TpriMainForm::SetFocus(const UnicodeString value)
{
	 AnsiString str = "M10000#";
	 AscomCommand(str);
	 Sleep(500);
	 str = "M0#";
	 AscomCommand(str);
	 Sleep(500);
	 str = "M";

	 int v = StrToInt(value);
	 str += IntToStr(v);
	 str += "#";
	 AscomCommand(str);
	 str = "P#";
	 AscomCommand(str);
}

void __fastcall TpriMainForm::SetAperture(const int value)
{
	 AnsiString str = "A";
	 str += IntToStr(value);
	 str += "#";
	 AscomCommand(str);
	 m_ascomAperture = 0;
}

void __fastcall TpriMainForm::SetEFWSlot(int num)
{
	EFWSetPosition(m_info.ID, num);
	refreshPosStatus();
}

void MoveFunction(LPVOID params)
{
	TpriMainForm* dlg =(TpriMainForm*)params;
	int iID = dlg->info.ID;
	int pos;
	EFW_ERROR_CODE err;
	while(dlg->cap.bThrGetPosRun)
	{
		err = EFWGetPosition(iID, &pos);
		if(err != EFW_SUCCESS || pos != -1)
			break;
		Sleep(200);
	}
	dlg->cap.bThrGetPosRun = false;
	SendMessage(priMainForm->Handle,WM_USER+2, 0,0 );

	_endthread();
}

void __fastcall TpriMainForm::refreshPosStatus()
{
	int pos;
	EFW_ERROR_CODE err = EFWGetPosition(m_info.ID, &pos);
	if(err == EFW_SUCCESS && info.ID > -1)
	{
		if(pos == -1)
		{
			pri2EquipmentForm->Label20->Caption = L"Смена фильтра";

			if (!m_cap.bThrGetPosRun)
			{
				m_cap.bThrGetPosRun = true;
				m_cap.Thr_getPos = (HANDLE)_beginthread(MoveFunction, NULL, this);
			}
		}
		else
		{
			pri2EquipmentForm->Label20->Caption = L"Готов";
		}
	}
}
void __fastcall TpriMainForm::WMUSER2(TMessage & msg)
{
	this->refreshPosStatus();
}

void __fastcall TpriMainForm::SetupFilter(int filter)
{
//	m_setupInProgress = true;
	TPriFilter* f = m_iniFile.Filter[filter];
	if (f != NULL)
	{
		ascomAperture = f->aperture;
		Sleep(500);
		ascomFocus = f->focus;
		Sleep(500);
		exposure = f->exposure*1000;
		efwPosition = f->index-1;
	}
}

TPriInitFile* __fastcall TpriMainForm::GetIniFile()
{
	return &m_iniFile;
}

