/*
*/
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "pamMainUnit.h"
#include "pamConsoleUnit.h"
#include "pamAboutUnit.h"
#include "pamResultUnit.h"
#include "pamScriptUnit.h"
#include "pamDistributionUnit.h"
#include "pamExperimentUnit.h"
#include "pamTimeLineUnit.h"
#include "pamOptionsUnit.h"
#include "pamHardwareUnit.h"

#include "Buf_USBCCDCamera_SDK.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FImage41"
#pragma link "Comm"
#pragma link "PhPalette"
#pragma resource "*.dfm"

#pragma link "BUF_USBCCDCamera_SDK_b.lib"
#pragma link "awplflibb.lib"

TpamMainForm *pamMainForm;


void CamHook(TProcessedDataProperty* Attributes, unsigned char *BytePtr)
{
	 if (pamMainForm != NULL)
	 {
		MSG msg;
		if(GetMessage(&msg,NULL,NULL,NULL))
		{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
		}
//		ConsoleForm->Memo1->Lines->Add(L"Mightex exposure: " + IntToStr(50*Attributes->ExposureTime) + L" mks");
//		ConsoleForm->Memo1->Lines->Add(L"Mightex Frq : " + IntToStr(Attributes->CCDFrequency) + L" mks");
		ConsoleForm->Memo1->Lines->Add(L"Mightex Frame time : " + IntToStr(Attributes->FrameTime) + L" mks");
		pamMainForm->PreviewFrame(Attributes->Column, Attributes->Row, BytePtr, Attributes->CameraID);

#ifdef _DEBUG
#endif
	 }
}

//---------------------------------------------------------------------------
__fastcall TpamMainForm::TpamMainForm(TComponent* Owner)
	: TForm(Owner)
{
	m_camera = 0;
	m_numCameras = 0;
	m_videoMode  = pam2videoCommands;
	m_viewSource = pam2viewFrame;
	m_Flash = 20;
	m_buffer = NULL;
	m_screenSource = NULL;

	m_numFlashes = 10;
	m_dutyСycle = 2;
	m_currentFlash = 0;

}
void TpamMainForm::ShowDockPanel(TWinControl* APanel, bool MakeVisible, TControl* Client)
{
  if (APanel == NULL || (!MakeVisible && (APanel->VisibleDockClientCount > 1)))
	return;
  if (MakeVisible)
  {
	  if (APanel->Name == L"BottomDocPanel")
		  APanel->Height = ClientHeight / 3;
	  else
		  APanel->Width = ClientWidth / 3;
  }
  else
  {
	  if (APanel->Name == L"BottomDocPanel")
		  APanel->Height = 5;
	  else
		  APanel->Width = 5;
  }

  if (MakeVisible && (Client != NULL))
	Client->Show();
}
//---------------------------------------------------------------------------
void __fastcall TpamMainForm::filesCloseActionExecute(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TpamMainForm::LeftDocPanelDockOver(TObject *Sender, TDragDockObject *Source,
		  int X, int Y, TDragState State, bool &Accept)
{
  Accept = (Source->Control) != NULL;
  if (Accept)
  {
	// Modify the DockRect to preview dock area.
	Types::TPoint TopLeft = LeftDocPanel->ClientToScreen(Point(0, 0));
	Types::TPoint BottomRight = LeftDocPanel->ClientToScreen(Point(PhImage1->Width / 3, LeftDocPanel->Height));
	Source->DockRect = Types::TRect(TopLeft, BottomRight);
  }
}
//---------------------------------------------------------------------------
void __fastcall TpamMainForm::RightDocPanelDockOver(TObject *Sender, TDragDockObject *Source,
		  int X, int Y, TDragState State, bool &Accept)
{
  Accept = (Source->Control) != NULL;
  if (Accept)
  {
	// Modify the DockRect to preview dock area.
	Types::TPoint TopLeft = LeftDocPanel->ClientToScreen(Point(ClientWidth, 0));
	Types::TPoint BottomRight = LeftDocPanel->ClientToScreen(Point(ClientWidth - PhImage1->Width / 3, RightDocPanel->Height));
	Source->DockRect = Types::TRect(TopLeft, BottomRight);
  }
}
//---------------------------------------------------------------------------
void __fastcall TpamMainForm::BottomDocPanelDockOver(TObject *Sender, TDragDockObject *Source,
          int X, int Y, TDragState State, bool &Accept)
{
  Accept = (Source->Control) != NULL;
  if (Accept)
  {
	// Modify the DockRect to preview dock area.
	Types::TPoint TopLeft = BottomDocPanel->ClientToScreen(Point(BottomDocPanel->Left, -PhImage1->Height/3));
	Types::TPoint BottomRight = BottomDocPanel->ClientToScreen(Point(BottomDocPanel->Width, BottomDocPanel->Height));
	Source->DockRect = Types::TRect(TopLeft, BottomRight);
  }

}
//---------------------------------------------------------------------------
void __fastcall TpamMainForm::windowConsoleActionExecute(TObject *Sender)
{
	ConsoleForm->Visible = !ConsoleForm->Visible;
}
//---------------------------------------------------------------------------
void __fastcall TpamMainForm::LeftDocPanelUnDock(TObject *Sender, TControl *Client, TWinControl *NewTarget,
          bool &Allow)
{
	ShowDockPanel(LeftDocPanel, false, NULL);
}
//---------------------------------------------------------------------------
void __fastcall TpamMainForm::LeftDocPanelDockDrop(TObject *Sender, TDragDockObject *Source,
		  int X, int Y)
{
	ShowDockPanel(LeftDocPanel, true, NULL);
}
//---------------------------------------------------------------------------
void __fastcall TpamMainForm::RightDocPanelDockDrop(TObject *Sender, TDragDockObject *Source,
		  int X, int Y)
{
	ShowDockPanel(RightDocPanel, true, NULL);
}
//---------------------------------------------------------------------------
void __fastcall TpamMainForm::RightDocPanelUnDock(TObject *Sender, TControl *Client,
		  TWinControl *NewTarget, bool &Allow)
{
	ShowDockPanel(RightDocPanel, false, NULL);
}
//---------------------------------------------------------------------------
void __fastcall TpamMainForm::BottomDocPanelDockDrop(TObject *Sender, TDragDockObject *Source,
		  int X, int Y)
{
	ShowDockPanel(BottomDocPanel, true, NULL);
}
//---------------------------------------------------------------------------
void __fastcall TpamMainForm::BottomDocPanelUnDock(TObject *Sender, TControl *Client,
		  TWinControl *NewTarget, bool &Allow)
{
	ShowDockPanel(BottomDocPanel, false, NULL);
}
//---------------------------------------------------------------------------
void __fastcall TpamMainForm::FormCreate(TObject *Sender)
{
	bool hardware_ready = true;
	try
	{
		Comm1->DeviceName = L"COM8";
		Comm1->Open();
		Comm1->SetRTSState(true);
		Comm1->SetDTRState(true);
	}
	catch(Exception& e)
	{
		ShowMessage(e.Message);
		hardware_ready = false;
	}
	if (!OpenCamera())
	{
		ShowMessage("Не подключена видеокамера!");
		hardware_ready = false;
	}
	/*	Устанавливаем режим настройки, в случае когда все оборудование
		обнаружено и работает без ошибок. в
	*/
	SetMode(hardware_ready?pam2Tuning:pam2Analysis);
	SetVideoMode(pam2videoCommands);
    SetViewSource(pam2viewFrame);
}
//---------------------------------------------------------------------------
void __fastcall TpamMainForm::Comm1RxChar(TObject *param_0, DWORD Count)
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
				{ ConsoleForm->Memo1->Lines->Add(TimeToStr(Time()) +L">" + rs); rs="" ;}
			  else
			  {
				sprintf(ts,"%c",rb[i]); rs=rs+ts;
			  }
		}
	}

}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::windowExperimentActionExecute(TObject *Sender)
{
    pam2ExperimentForm->Visible = !pam2ExperimentForm->Visible;
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::windowExperimentActionUpdate(TObject *Sender)
{
   windowExperimentAction->Checked = pam2ExperimentForm->Visible;
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::windowScriptActionExecute(TObject *Sender)
{
	pam2ScriptForm->Visible = !pam2ScriptForm->Visible;
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::windowScriptActionUpdate(TObject *Sender)
{
	windowScriptAction->Checked = pam2ScriptForm->Visible;
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::windowResultActionExecute(TObject *Sender)
{
	pam2ResultForm->Visible = !pam2ResultForm->Visible;
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::windowResultActionUpdate(TObject *Sender)
{
	windowResultAction->Checked = pam2ResultForm->Visible;
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::windowDistributionActionExecute(TObject *Sender)
{
    pam2DistributionForm->Visible = !pam2DistributionForm->Visible;
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::windowDistributionActionUpdate(TObject *Sender)
{
	windowDistributionAction->Checked = pam2DistributionForm->Visible;
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::windowTimeLineActionExecute(TObject *Sender)
{
    pam2TimeLineForm->Visible = !pam2TimeLineForm->Visible;
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::windowTimeLineActionUpdate(TObject *Sender)
{
	windowTimeLineAction->Checked = pam2TimeLineForm->Visible;
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::editCopyActionExecute(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::editCopyActionUpdate(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::toolsOptionsActionExecute(TObject *Sender)
{
	//todo: load options from config

	if (pam2OptionsForm->ShowModal() == mrOk)
	{
        //todo: save options to config
	}
}
//---------------------------------------------------------------------------
//
//
void __fastcall TpamMainForm::toolsExecuteActionExecute(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------
//
void __fastcall TpamMainForm::toolsExecuteActionUpdate(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::toolsStartExperimetActionExecute(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::toolsStartExperimetActionUpdate(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::toolsStopExperimentActionExecute(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::toolsStopExperimentActionUpdate(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::helpAboutActionExecute(TObject *Sender)
{
    AboutBox->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::helpAboutActionUpdate(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::helpContentActionExecute(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::helpContentActionUpdate(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::fileNewActionExecute(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::fileNewActionUpdate(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::fileOpenActionExecute(TObject *Sender)
{
 //
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::fileOpenActionUpdate(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::fileCloseExperimentActionExecute(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::fileCloseExperimentActionUpdate(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::fileSaveExperimentActionExecute(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::fileSaveExperimentActionUpdate(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::windowConsoleActionUpdate(TObject *Sender)
{
	windowConsoleAction->Checked = ConsoleForm->Visible;
}
//---------------------------------------------------------------------------
bool TpamMainForm::OpenCamera()
{
	bool result = false;
	m_numCameras = BUFCCDUSB_InitDevice();
	if (m_numCameras == 0)
		return false;

	m_camera = 1;
	BUFCCDUSB_AddDeviceToWorkingSet(m_camera);
	BUFCCDUSB_InstallFrameHooker( 0, CamHook );
	BUFCCDUSB_StartCameraEngine(this->Handle, 12);
	BUFCCDUSB_SetCameraWorkMode(m_camera, 1);
	BUFCCDUSB_StartFrameGrab(1);

	return true;
}

void __fastcall TpamMainForm::PreviewFrame(int width, int height, unsigned char* data, int cameraID)
{
	if (m_videoMode == pam2videoLive)
	{
		awpImage* img = NULL;
		if (cameraID == 1)
		{
		   awpCreateImage(&img, width, height, 1, AWP_BYTE);
		   AWPBYTE* dst = (AWPBYTE*)img->pPixels;
		   int x,y, i=0;
		   for (x = 0; x < width; x++)
		   {
			   for (y = 0; y < height; y++)
			   {
				   AWPWORD value = data[2*y + 2*x*height+ 1];
				   AWPWORD v2 = data[2*y + 2*x*height];
				   v2 = v2 << 4;
				   value |= v2;
				   dst[i] = 255*(float)value/4096.;
				   i++;
			   }

		   }
		   awpImage* pal = (awpImage*)PhPalette1->ApplyPalette((void*)img);
		   if (pal != NULL) {
			   PhImage1->SetAwpImage(pal);
			   awpReleaseImage(&pal);
		   }
		   else
			   PhImage1->SetAwpImage(img);
		   awpReleaseImage(&img);
		}
	}
	else
	{
#ifdef _DEBUG
//		ConsoleForm->Memo1->Lines->Add("изображение добавлено в буфер");
#endif
		BUFCCDUSB_StartFrameGrab(1);
		m_buffer->AddFrame(width, height, data);
	}
}

void __fastcall TpamMainForm::SetPicture(awpImage* img)
{
#ifdef _DEBUG
	   ConsoleForm->Memo1->Lines->Add("Изображение отправлено на экран.");
#endif
	   awpImage* pal = (awpImage*)PhPalette1->ApplyPalette((void*)img);
	   if (pal != NULL) {
		   PhImage1->SetAwpImage(pal);
		   awpReleaseImage(&pal);
	   }
	   else
		   PhImage1->SetAwpImage(img);
}


void __fastcall TpamMainForm::FormClose(TObject *Sender, TCloseAction &Action)
{
       BUFCCDUSB_UnInitDevice();
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::tuningLiveVideoExecute(TObject *Sender)
{
	SetVideoMode(pam2videoLive);
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::tuningLiveVideoUpdate(TObject *Sender)
{
	tuningLiveVideo->Checked = m_videoMode == pam2videoLive;
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::tuningFlashActionExecute(TObject *Sender)
{
	//SetVideoMode(pam2videoFlash);
	this->ExecuteCommand(L"FLASH");
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::tuningFlashActionUpdate(TObject *Sender)
{
	//tuningFlashAction->Checked = m_videoMode == pam2videoFlash;
	tuningFlashAction->Enabled = m_videoMode == pam2videoCommands;
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::tuningCommandsActionExecute(TObject *Sender)
{
   SetVideoMode(pam2videoCommands);
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::tuningCommandsActionUpdate(TObject *Sender)
{
	tuningCommandsAction->Checked = m_videoMode == pam2videoCommands;
}
//---------------------------------------------------------------------------
// typedef enum {pam2Tuning, pam2Capture, pam2Analysis}EPam2Modes;
static UnicodeString EPam2ModeToString(EPam2Modes mode)
{
	if (mode == pam2Tuning)
		return L"настройка";

	if (mode == pam2Capture)
		return L"измерение";

	if (mode == pam2Analysis)
		return L"анализ";
}

void __fastcall TpamMainForm::SetMode(EPam2Modes mode)
{
	m_mode = mode;
	StatusBar1->Panels->Items[0]->Text = L"Режим: " + EPam2ModeToString(m_mode);
}

static UnicodeString EPam2VideoModesToString(EPam2VideoModes mode)
{
	if (mode == pam2videoLive)
		return L" видео";

	if (mode == pam2videoFlash)
		return L"вспышки";

	if (mode == pam2videoCommands)
		return L"команды";
}
/*
typedef enum {pam2viewFrame, pam2viewFo, pam2viewFm, pam2viewFt,pam2viewFm1,
pam2viewFv, pam2viewFv1, pam2viewFq1, pam2viewFo1, pam2vewFvFm1,
pam2viewYII1, pam2viewNPQ1, pam2viewqN1}EPam2ViewSource;

*/
static UnicodeString EPam2ViewSourceToString(EPam2ViewSource source)
{
	if (source == pam2viewFrame)
		return "Frame";
	if (source == pam2viewFo)
		return "Fo";
	if (source == pam2viewFm)
		return "Fm";
	if (source == pam2viewFt)
		return "Ft";
	if (source == pam2viewFm1)
		return "Fm1";
	if (source == pam2viewFv)
		return "Fv";
	if (source == pam2viewFv1)
		return "Fv'";
	if (source == pam2viewFq1)
		return "Fq'";
	if (source == pam2viewFo1)
		return "Fo'";
	if (source == pam2viewFvFm1)
		return "Fv/Fm'";
	if (source == pam2viewYII1)
		return "YII'";
	if (source == pam2viewNPQ1)
		return "NPQ'";
	if (source == pam2viewqN1)
		return "qN'";
}

void __fastcall TpamMainForm::SetVideoMode(EPam2VideoModes mode)
{
	  Timer1->Enabled = false;

	  m_videoMode = mode;
	  BUFCCDUSB_StopFrameGrab();
	  if (m_videoMode == pam2videoLive)
	  {
		// запускаем живое видео
		BUFCCDUSB_SetCameraWorkMode(m_camera, 0);
	   	BUFCCDUSB_SetFrameTime( m_camera, 1000);
	  }
	  else if (m_videoMode == pam2videoFlash)
	  {
		// запускаем таймер
		BUFCCDUSB_SetCameraWorkMode(m_camera, 1);
		Timer1->Enabled = true;
	  }
	  else if (m_videoMode == pam2videoCommands)
	  {
		// запускаем командный режим.
		BUFCCDUSB_StopFrameGrab();
		//BUFCCDUSB_SetCustomizedResolution(m_camera, 1280, 960, 0, 24);
		BUFCCDUSB_SetCameraWorkMode(m_camera, 1);
        //BUFCCDUSB_StartFrameGrab(12);
		//BUFCCDUSB_SetMinimumFrameDelay(1);
	  }

	 // BUFCCDUSB_StartFrameGrab(GRAB_FRAME_FOREVER);
}

void __fastcall TpamMainForm::Timer1Timer(TObject *Sender)
{
	this->ExecuteCommand(L"FLASH");
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::paletteScaleActionExecute(TObject *Sender)
{
	PhPalette1->TicksVisible = !PhPalette1->TicksVisible;
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::paletteScaleActionUpdate(TObject *Sender)
{
	paletteScaleAction->Checked = PhPalette1->TicksVisible;
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::plaetteGrayscaleActionExecute(TObject *Sender)
{
	PhPalette1->PaletteType = phpalGrayscale;
	this->UpdateScreen();
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::plaetteGrayscaleActionUpdate(TObject *Sender)
{
	plaetteGrayscaleAction->Checked = PhPalette1->PaletteType == phpalGrayscale;
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::paletteOceanActionExecute(TObject *Sender)
{
	PhPalette1->PaletteType = phpalOcean;
	this->UpdateScreen();
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::paletteOceanActionUpdate(TObject *Sender)
{
	paletteOceanAction->Checked = PhPalette1->PaletteType == phpalOcean;
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::paletteGlowActionExecute(TObject *Sender)
{
	PhPalette1->PaletteType = phpalGlow;
	this->UpdateScreen();
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::paletteGlowActionUpdate(TObject *Sender)
{
	paletteGlowAction->Checked = PhPalette1->PaletteType == phpalGlow;
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::paletteRedBlueActionExecute(TObject *Sender)
{
	PhPalette1->PaletteType = phpalBluered;
    this->UpdateScreen();
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::paletteRedBlueActionUpdate(TObject *Sender)
{
	paletteRedBlueAction->Checked = PhPalette1->PaletteType == phpalBluered;
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::paletteTrafficActionExecute(TObject *Sender)
{
	PhPalette1->PaletteType = phpalTraffic;
    this->UpdateScreen();
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::paletteTrafficActionUpdate(TObject *Sender)
{
	paletteTrafficAction->Checked = PhPalette1->PaletteType == phpalTraffic;
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::paletteSpecturmActionExecute(TObject *Sender)
{
	PhPalette1->PaletteType = phpalSpectum;
	this->UpdateScreen();
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::paletteSpecturmActionUpdate(TObject *Sender)
{
	paletteSpecturmAction->Checked = PhPalette1->PaletteType == phpalSpectum;
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::paletteSpectrum2ActionExecute(TObject *Sender)
{
	PhPalette1->PaletteType = phpalSpectrum2;
    this->UpdateScreen();
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::paletteSpectrum2ActionUpdate(TObject *Sender)
{
	paletteSpectrum2Action->Checked = PhPalette1->PaletteType == phpalSpectrum2;
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::paletteFalseColorsActionExecute(TObject *Sender)
{
	PhPalette1->PaletteType = phpalFalseColors;
    this->UpdateScreen();
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::paletteFalseColorsActionUpdate(TObject *Sender)
{
	paletteFalseColorsAction->Checked = PhPalette1->PaletteType == phpalFalseColors;
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::windowHardwareActionExecute(TObject *Sender)
{
    pam2HardwareForm->Visible = !pam2HardwareForm->Visible;
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::windowHardwareActionUpdate(TObject *Sender)
{
	windowHardwareAction->Checked = pam2HardwareForm->Visible;
}
//---------------------------------------------------------------------------
void __fastcall TpamMainForm::SetExposure(int value)
{
	int exp_units = value / 50;
	if (BUFCCDUSB_SetExposureTime(m_camera, exp_units) == -1)
		ConsoleForm->Memo1->Lines->Add(L"ERROR: Не могу установить экспозицю. Подключите видеокамеру Mightex.");
	else
	{
		UnicodeString str = L"EXP=";
		str += IntToStr(value);
		ExecuteCommand(str);
	}
}

void __fastcall TpamMainForm::SetGain(int value)
{
	int v = value;
	if (BUFCCDUSB_SetGains(m_camera, v , v, v) == -1)
		ConsoleForm->Memo1->Lines->Add(L"ERROR: Не могу установить усиление. Подключите видеокамеру Mightex.");
}

void __fastcall TpamMainForm::SetFlash(int value)
{
	if (value < 10 || value > 50) {
		ConsoleForm->Memo1->Lines->Add(L"ERROR: Не могу установить длительность вспышки.");
		return;
	}
	m_Flash = value;
	UnicodeString str = L"LFLASH=";
	str += IntToStr(value);
	ExecuteCommand(str);
}

void __fastcall TpamMainForm::SetSat(int value)
{
	if (value < 0 || value > 100) {
		ConsoleForm->Memo1->Lines->Add(L"ERROR: Не могу установить интенсивность насыщающего света.");
		return;
	}
	UnicodeString str = L"LSAT=";
	str += IntToStr(value);
	ExecuteCommand(str);
}

void __fastcall TpamMainForm::SwitchSat(int value)
{
	if (value !=0 && value !=1) {
		ConsoleForm->Memo1->Lines->Add(L"ERROR: переключить источник насыщающего света.");
		return;
	}
	UnicodeString str = L"SAT=";
	str += IntToStr(value);
	ExecuteCommand(str);

}
void __fastcall TpamMainForm::SetAdd(int value)
{
	if (value < 0 || value > 100) {
		ConsoleForm->Memo1->Lines->Add(L"ERROR: Не могу установить интенсивность дополнительного света.");
		return;
	}
	UnicodeString str = L"LADD=";
	str += IntToStr(value);
	ExecuteCommand(str);
}
void __fastcall TpamMainForm::SwitchAdd(int value)
{
	if (value !=0 && value !=1) {
		ConsoleForm->Memo1->Lines->Add(L"ERROR: переключить источник дополнительного света.");
		return;
	}
	UnicodeString str = L"ADD=";
	str += IntToStr(value);
	ExecuteCommand(str);
}
void __fastcall TpamMainForm::SetAct(int value)
{
	if (value < 0 || value > 100) {
		ConsoleForm->Memo1->Lines->Add(L"ERROR: Не могу установить интенсивность актиничного света.");
		return;
	}
	UnicodeString str = L"LACT=";
	str += IntToStr(value);
	ExecuteCommand(str);
}

void __fastcall TpamMainForm::SwitchAct(int value)
{
	if (value !=0 && value !=1) {
		ConsoleForm->Memo1->Lines->Add(L"ERROR: переключить источник актиничного света.");
		return;
	}
	UnicodeString str = L"ACT=";
	str += IntToStr(value);
	ExecuteCommand(str);
}
// Выполнить команду
void __fastcall TpamMainForm::ExecuteCommand(const UnicodeString& command)
{
	char wb[256] ;
	int i ;
	if (Comm1->Enabled())
	{
		if (m_videoMode == pam2videoLive && (command == L"FLASH" ||
		 command == L"DARK" || command == L"FOFM" || command == L"FTFM1")) {
			ConsoleForm->Memo1->Lines->Add("ERROR: команда " + command + L" не поддерживается в режиме отображения видеосигнала.");
			return;
		}

		if ((command == L"FLASH" ||
		 command == L"DARK" || command == L"FOFM" || command == L"FTFM1")) {
			delete this->m_buffer;
			m_buffer = NULL;
		}

		if (command == L"FLASH")
			m_buffer = new TPamImageBuffer(pam2bfFlash);
		else if (command == L"DARK")
			m_buffer = new TPamImageBuffer(pam2bfFlash);
		else if (command == L"FOFM")
		{
			m_buffer = new TPamImageBuffer(pam2bfFoFm);
			BUFCCDUSB_SetCameraWorkMode(m_camera, 1);
			BUFCCDUSB_SetFrameTime( m_camera, 100);
			BUFCCDUSB_StartFrameGrab(1);
			//BUFCCDUSB_SetMinimumFrameDelay(1);

		}
		 else if(command == L"FTFM1")
			m_buffer = new TPamImageBuffer(pam2bfFtFm1);

		AnsiString str = command;
		sprintf(wb,"%s",str.c_str());
		i = pamMainForm->Comm1->Write(wb, command.Length()+1);
	}
	else
		ConsoleForm->Memo1->Lines->Add("Устройство не подключено.");
}

void __fastcall TpamMainForm::tuningDarkActionExecute(TObject *Sender)
{
	this->ExecuteCommand(L"DARK");
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::tuningDarkActionUpdate(TObject *Sender)
{
	tuningDarkAction->Enabled = m_videoMode == pam2videoCommands;
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::tuningFoFmActionExecute(TObject *Sender)
{
		this->ExecuteCommand(L"FOFM");
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::tuningFoFmActionUpdate(TObject *Sender)
{
	tuningFoFmAction->Enabled = m_videoMode == pam2videoCommands;
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::tuningFtTm1ActionExecute(TObject *Sender)
{
    this->ExecuteCommand(L"FTFM1");
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::tuningFtTm1ActionUpdate(TObject *Sender)
{
	tuningFtTm1Action->Enabled = m_videoMode == pam2videoCommands && m_pam2Doc.hasFoFm;
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::viewFrameActionExecute(TObject *Sender)
{
	SetViewSource(pam2viewFrame);
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::viewFrameActionUpdate(TObject *Sender)
{
	viewFrameAction->Enabled = m_pam2Doc.hasFrame;
	viewFrameAction->Checked = m_viewSource == pam2viewFrame;
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::viewFoActionExecute(TObject *Sender)
{
	SetViewSource(pam2viewFo);
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::viewFoActionUpdate(TObject *Sender)
{
	viewFoAction->Enabled = m_pam2Doc.hasFoFm;
	viewFoAction->Checked = m_viewSource == pam2viewFo;
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::viewFmActionExecute(TObject *Sender)
{
	SetViewSource(pam2viewFm);
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::viewFmActionUpdate(TObject *Sender)
{
	viewFmAction->Enabled = m_pam2Doc.hasFoFm;
	viewFmAction->Checked = m_viewSource == pam2viewFm;
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::viewFtActionExecute(TObject *Sender)
{
	SetViewSource(pam2viewFt);
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::viewFtActionUpdate(TObject *Sender)
{
		viewFtAction->Enabled = m_pam2Doc.hasFtFm1;
		viewFtAction->Checked = m_viewSource == pam2viewFt;
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::viewFm1ActionExecute(TObject *Sender)
{
	SetViewSource(pam2viewFm1);
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::viewFm1ActionUpdate(TObject *Sender)
{
	viewFm1Action->Enabled = m_pam2Doc.hasFtFm1;
	viewFm1Action->Checked = m_viewSource == pam2viewFm1;
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::viewFvActionExecute(TObject *Sender)
{
	SetViewSource(pam2viewFv);
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::viewFvActionUpdate(TObject *Sender)
{
	viewFvAction->Enabled = m_pam2Doc.hasFtFm1;
	viewFvAction->Checked = m_viewSource == pam2viewFv;
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::viewFv1ActionExecute(TObject *Sender)
{
	SetViewSource(pam2viewFv1);
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::viewFv1ActionUpdate(TObject *Sender)
{
	viewFv1Action->Enabled = m_pam2Doc.hasFtFm1;
	viewFv1Action->Checked = m_viewSource == pam2viewFv1;
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::viewFq1ActionExecute(TObject *Sender)
{
	SetViewSource(pam2viewFq1);
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::viewFq1ActionUpdate(TObject *Sender)
{
	viewFq1Action->Enabled = m_pam2Doc.hasFtFm1;
	viewFq1Action->Checked = m_viewSource == pam2viewFq1;
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::viewFo1ActionExecute(TObject *Sender)
{
	SetViewSource(pam2viewFo1);
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::viewFo1ActionUpdate(TObject *Sender)
{
	viewFo1Action->Enabled = m_pam2Doc.hasFtFm1;
	viewFo1Action->Checked = m_viewSource == pam2viewFo1;
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::viewFvFm1ActionExecute(TObject *Sender)
{
	SetViewSource(pam2viewFvFm1);
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::viewFvFm1ActionUpdate(TObject *Sender)
{
	viewFvFm1Action->Enabled = m_pam2Doc.hasFtFm1;
	viewFvFm1Action->Checked = m_viewSource == pam2viewFvFm1;
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::viewYII1ActionExecute(TObject *Sender)
{
	SetViewSource(pam2viewYII1);
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::viewYII1ActionUpdate(TObject *Sender)
{
	viewYII1Action->Enabled = m_pam2Doc.hasFtFm1;
	viewYII1Action->Checked = m_viewSource == pam2viewYII1;
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::viewNPQ1ActionExecute(TObject *Sender)
{
	SetViewSource(pam2viewNPQ1);
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::viewNPQ1ActionUpdate(TObject *Sender)
{
	viewNPQ1Action->Enabled = m_pam2Doc.hasFtFm1;
	viewNPQ1Action->Checked = m_viewSource == pam2viewNPQ1;
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::viewqN1ActionExecute(TObject *Sender)
{
	SetViewSource(pam2viewqN1);
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::viewqN1ActionUpdate(TObject *Sender)
{
	viewqN1Action->Enabled = m_pam2Doc.hasFtFm1;
	viewqN1Action->Checked = m_viewSource == pam2viewqN1;
}
//---------------------------------------------------------------------------
void __fastcall TpamMainForm::WMUSER1(TMessage & msg)
{
	this->UpdateScreen();
}
void __fastcall TpamMainForm::WMUSER2(TMessage & msg)
{

}

TPam2Document* __fastcall TpamMainForm::GetDocument()
{
	return &m_pam2Doc;
}

void __fastcall TpamMainForm::SetViewSource(EPam2ViewSource source)
{
   m_viewSource = source;
   // обновляем экран
  UpdateScreen();
}

void __fastcall TpamMainForm::UpdateScreen()
{
	_AWP_SAFE_RELEASE_(this->m_screenSource)

	StatusBar1->Panels->Items[1]->Text = L"Визуализация: " + EPam2ViewSourceToString(m_viewSource);
	awpImage* img = NULL;
	switch(m_viewSource)
	{
	  case  pam2viewFrame:
		img = m_pam2Doc.GetFrame();
	  break;
	  case  pam2viewFo:
		img = m_pam2Doc.GetFo();
	  break;
	  case  pam2viewFm:
		img = m_pam2Doc.GetFm();
	  break;
	  case  pam2viewFt:
		img = m_pam2Doc.GetFt();
	  break;
	  case  pam2viewFm1:
		img = m_pam2Doc.GetFm1();
	  break;
	  case  pam2viewFv:
		img = m_pam2Doc.GetFv();
	  break;
	  case  pam2viewFv1:
		img = m_pam2Doc.GetFv1();
	  break;
	  case  pam2viewFq1:
		img = m_pam2Doc.GetFq1();
	  break;
	  case  pam2viewFo1:
		img = m_pam2Doc.GetFo1();
	  break;
	  case  pam2viewFvFm1:
		img = m_pam2Doc.GetFvFm1();
	  break;
	  case  pam2viewYII1:
		img = m_pam2Doc.GetYII1();
	  break;
	  case  pam2viewNPQ1:
		img = m_pam2Doc.GetNPQ1();
	  break;
	  case  pam2viewqN1:
		img = m_pam2Doc.GetqN1();
	  break;
	}
	if (img != NULL)
	{
		awpImage* _img = NULL;

		awpCopyImage(img, &_img);
		awpCopyImage(img, &this->m_screenSource);

		awpConvert(_img, AWP_CONVERT_TO_BYTE_WITH_NORM);
		this->SetPicture(_img);

		awpReleaseImage(&_img);
		awpReleaseImage(&img);
	}
}


void __fastcall TpamMainForm::PhImage1MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y)
{
	if (PhImage1->Bitmap->Empty || this->m_screenSource == NULL)
		return;
	int _x = PhImage1->GetImageX(X);
	int _y = PhImage1->GetImageY(Y);

	if (_x >= 0 && _y >= 0)
	{
		AWPFLOAT* f = (AWPFLOAT*)this->m_screenSource->pPixels;
		double value = f[_y*this->m_screenSource->sSizeX + _x];
		StatusBar1->Panels->Items[2]->Text = L"X:" + IntToStr(_x) + L" Y:" +IntToStr(_y) + L" V:" +FormatFloat("###.#", value);
	}
	else
        StatusBar1->Panels->Items[2]->Text  = L"";

}
//---------------------------------------------------------------------------
void __fastcall TpamMainForm::SetmDutyСycle(int value)
{
	this->m_dutyСycle = value;
	this->Timer1->Interval = 1000*this->m_dutyСycle;
}


