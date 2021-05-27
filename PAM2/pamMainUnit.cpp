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
		pamMainForm->PreviewFrame(Attributes->Column, Attributes->Row, BytePtr, Attributes->CameraID);
	 }
}

//---------------------------------------------------------------------------
__fastcall TpamMainForm::TpamMainForm(TComponent* Owner)
	: TForm(Owner)
{
	m_camera = 0;
	m_numCameras = 0;
	m_videoMode = pam2videoCommands;
    m_Flash = 20;
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
		Comm1->DeviceName = L"COM5";
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
	BUFCCDUSB_StartFrameGrab(GRAB_FRAME_FOREVER);

	return true;
}

void __fastcall TpamMainForm::PreviewFrame(int width, int height, unsigned char* data, int cameraID)
{
	int bits = 1;//this->m_pInitFile->inputData;
    int type = bits == 0 ? AWP_BYTE:AWP_DOUBLE;
    int size = bits == 0 ? sizeof(AWPBYTE):sizeof(AWPDOUBLE);
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
void __fastcall TpamMainForm::FormClose(TObject *Sender, TCloseAction &Action)
{
       BUFCCDUSB_UnInitDevice();
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::modeLiveVideoExecute(TObject *Sender)
{
	SetVideoMode(pam2videoLive);
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::modeLiveVideoUpdate(TObject *Sender)
{
	modeLiveVideo->Checked = m_videoMode == pam2videoLive;
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::modeFlashActionExecute(TObject *Sender)
{
	SetVideoMode(pam2videoFlash);
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::modeFlashActionUpdate(TObject *Sender)
{
	modeFlashAction->Checked = m_videoMode == pam2videoFlash;
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::modeCommandsActionExecute(TObject *Sender)
{
   SetVideoMode(pam2videoCommands);
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::modeCommandsActionUpdate(TObject *Sender)
{
	modeCommandsAction->Checked = m_videoMode == pam2videoCommands;
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

void __fastcall TpamMainForm::SetVideoMode(EPam2VideoModes mode)
{
	  Timer1->Enabled = false;

	  m_videoMode = mode;
	  BUFCCDUSB_StopFrameGrab();
	  if (m_videoMode == pam2videoLive)
	  {
		// запускаем живое видео
		BUFCCDUSB_SetCameraWorkMode(m_camera, 0);
        BUFCCDUSB_SetFrameTime( m_camera, 2500);
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
		BUFCCDUSB_SetCameraWorkMode(m_camera, 1);
	  }

	  BUFCCDUSB_StartFrameGrab(GRAB_FRAME_FOREVER);
	  StatusBar1->Panels->Items[1]->Text = L"Визуализация: " + EPam2VideoModesToString(m_videoMode);
}

void __fastcall TpamMainForm::Timer1Timer(TObject *Sender)
{
	char wb[256] ;
	int i ;
	if (Comm1->Enabled())
	{
		AnsiString str = "FLASH(50)";
		sprintf(wb,"%s",str.c_str());
		i = pamMainForm->Comm1->Write(wb,str.Length()+1);
	}
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
		char wb[256] ;
		int i ;
		if (Comm1->Enabled())
		{
			AnsiString str = "EXP=";
			str += IntToStr(value);
			sprintf(wb,"%s",str.c_str());
			i = pamMainForm->Comm1->Write(wb,str.Length()+1);
		}
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
	char wb[256] ;
	int i ;
	if (Comm1->Enabled())
	{
		AnsiString str = "LFLASH=";
		str += IntToStr(value);
		sprintf(wb,"%s",str.c_str());
		i = pamMainForm->Comm1->Write(wb,str.Length()+1);
	}
}

void __fastcall TpamMainForm::SetSat(int value)
{
	if (value < 0 || value > 100) {
		ConsoleForm->Memo1->Lines->Add(L"ERROR: Не могу установить интенсивность насыщающего света.");
		return;
	}
	char wb[256] ;
	int i ;
	if (Comm1->Enabled())
	{
		AnsiString str = "LSAT=";
		str += IntToStr(value);
		sprintf(wb,"%s",str.c_str());
		i = pamMainForm->Comm1->Write(wb,str.Length()+1);
	}
}

void __fastcall TpamMainForm::SwitchSat(int value)
{
	if (value !=0 && value !=1) {
		ConsoleForm->Memo1->Lines->Add(L"ERROR: переключить источник насыщающего света.");
		return;
	}

	char wb[256] ;
	int i ;
	if (Comm1->Enabled())
	{
		AnsiString str = "SAT=";
		str += IntToStr(value);
		sprintf(wb,"%s",str.c_str());
		i = pamMainForm->Comm1->Write(wb,str.Length()+1);
	}
}
void __fastcall TpamMainForm::SetAdd(int value)
{
	if (value < 0 || value > 100) {
		ConsoleForm->Memo1->Lines->Add(L"ERROR: Не могу установить интенсивность дополнительного света.");
		return;
	}
	char wb[256] ;
	int i ;
	if (Comm1->Enabled())
	{
		AnsiString str = "LADD=";
		str += IntToStr(value);
		sprintf(wb,"%s",str.c_str());
		i = pamMainForm->Comm1->Write(wb,str.Length()+1);
	}
}
void __fastcall TpamMainForm::SwitchAdd(int value)
{
	if (value !=0 && value !=1) {
		ConsoleForm->Memo1->Lines->Add(L"ERROR: переключить источник дополнительного света.");
		return;
	}

	char wb[256] ;
	int i ;
	if (Comm1->Enabled())
	{
		AnsiString str = "ADD=";
		str += IntToStr(value);
		sprintf(wb,"%s",str.c_str());
		i = pamMainForm->Comm1->Write(wb,str.Length()+1);
	}
}
void __fastcall TpamMainForm::SetAct(int value)
{
	if (value < 0 || value > 100) {
		ConsoleForm->Memo1->Lines->Add(L"ERROR: Не могу установить интенсивность актиничного света.");
		return;
	}
	char wb[256] ;
	int i ;
	if (Comm1->Enabled())
	{
		AnsiString str = "LACT=";
		str += IntToStr(value);
		sprintf(wb,"%s",str.c_str());
		i = pamMainForm->Comm1->Write(wb,str.Length()+1);
	}
}

void __fastcall TpamMainForm::SwitchAct(int value)
{
	if (value !=0 && value !=1) {
		ConsoleForm->Memo1->Lines->Add(L"ERROR: переключить источник актиничного света.");
		return;
	}

	char wb[256] ;
	int i ;
	if (Comm1->Enabled())
	{
		AnsiString str = "ACT=";
		str += IntToStr(value);
		sprintf(wb,"%s",str.c_str());
		i = pamMainForm->Comm1->Write(wb,str.Length()+1);
	}
}







