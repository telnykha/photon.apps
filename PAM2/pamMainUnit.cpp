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
#include "pamExperimentUnit.h"
#include "Buf_USBCCDCamera_SDK.h"
#include "System.AnsiStrings.hpp"
#include "pamLongProcessUnit.h"
#include "pamSplashUnit.h"
#include "pamScriptDocUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FImage41"
#pragma link "Comm"
#pragma link "PhPalette"
#pragma link "PhVideoTrackBar"
#pragma link "PhImageTool"
#pragma link "PhPaneTool"
#pragma link "PhTrackBar"
#pragma resource "*.dfm"

#pragma link "BUF_USBCCDCamera_SDK_b.lib"
#pragma link "awplflibb.lib"

TpamMainForm *pamMainForm;


void CamHook(TProcessedDataProperty* Attributes, unsigned char *BytePtr)
{
	 if (pamMainForm != NULL)
	 {
		pamMainForm->PreviewFrame(Attributes->Column, Attributes->Row, BytePtr, Attributes->CameraID);
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
	// инициализация переменных микроконтроллера
	m_initArduino = false;
	m_exposure = 250;
	m_gain = 10;

	m_sat = 0;
	m_act = 0;
	m_add = 0;
	m_lsat = 30;
	m_lact = 20;
	m_ladd = 50;
	m_lflash = 20;

	m_hardware_ready = false;

	m_initCommands = new TStringList();
	m_initCommands->Add("EXP=" + IntToStr(m_exposure));
	m_initCommands->Add("GAIN=" + IntToStr(m_gain));
	m_initCommands->Add("SAT=" + IntToStr(m_sat));
	m_initCommands->Add("ACT=" + IntToStr(m_act));
	m_initCommands->Add("ADD=" +IntToStr(m_add));
	m_initCommands->Add("LSAT=" + IntToStr(m_lsat));
	m_initCommands->Add("LACT=" + IntToStr(m_lact));
	m_initCommands->Add("LADD=" + IntToStr(m_ladd));
	m_initCommands->Add("LFLASH=" + IntToStr(m_lflash));

	m_roiTool = new TPhPam2RoiTool(NULL);
	m_roiTool->OnAddRoi = AddRoi;
    m_roiTool->OnChangeRoi = ChangeRoi;
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
	m_hardware_ready = true;
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
		m_hardware_ready = false;
	}
	if (!OpenCamera())
	{
		ShowMessage("Не подключена видеокамера!");
		m_hardware_ready = false;
	}
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
				{
					if (m_mode == pam2Capture)
					{
						this->m_pam2Doc.AddEvent(rs);

					}
					else
					{
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

void __fastcall TpamMainForm::windowExperimentActionExecute(TObject *Sender)
{

	pam2ExperimentForm->Visible = !pam2ExperimentForm->Visible;
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::windowExperimentActionUpdate(TObject *Sender)
{
   windowExperimentAction->Enabled = m_mode == pam2Tuning;
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
    windowScriptAction->Enabled = m_mode != pam2Analysis;
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
    windowResultAction->Enabled = m_mode == pam2Analysis;
	windowResultAction->Checked = pam2ResultForm->Visible;
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::windowROIActionExecute(TObject *Sender)
{
	pam2ROIForm->Visible = !pam2ROIForm->Visible;
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::windowROIActionUpdate(TObject *Sender)
{
	windowROIAction->Enabled = !PhImage1->Empty;
	windowROIAction->Checked = pam2ROIForm->Visible;
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::windowTimeLineActionExecute(TObject *Sender)
{
    pam2TimeLineForm->Visible = !pam2TimeLineForm->Visible;
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::windowTimeLineActionUpdate(TObject *Sender)
{
    windowTimeLineAction->Enabled = m_mode == pam2Analysis;
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
	editCopyAction->Enabled = m_mode !=  pam2Capture;
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
	// добавим в консоль метку начала выполнения скрипта
/*	 ConsoleForm->Memo1->Lines->Add("[PAM2@INFO:] Начало скрипта.");
	 pam2ScriptForm->Script->IsRunning = true;
	 Timer2->Enabled = true;
*/
	m_numEvents = pam2ScriptForm->Script->CommandsCount;
	m_currentEvent = 0;
    m_cancelScript = false;
	LongProcessForm->ShowModal();
}
//---------------------------------------------------------------------------
//
void __fastcall TpamMainForm::toolsExecuteActionUpdate(TObject *Sender)
{
    toolsExecuteAction->Enabled = m_mode == pam2Tuning && pam2ScriptForm->RichEdit1->Lines->Count > 0 && pam2ScriptForm->RichEdit1->Modified == false && pam2ScriptForm->Script->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::toolsStartExperimetActionExecute(TObject *Sender)
{
	// Начало измерений
	pam2ExperimentForm->Gauge1->Progress = 0;
	Timer1->Interval = 1000*this->m_dutyСycle;
	this->SetMode(pam2Capture);
	ConsoleForm->Memo1->Lines->Add("[PAM2@INFO:] Начало измерений.");
	Timer1->Enabled = true;
    m_pam2Doc.BeginRecording();
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::toolsStartExperimetActionUpdate(TObject *Sender)
{
	toolsStartExperimetAction->Enabled = m_mode == pam2Tuning;
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::toolsStopExperimentActionExecute(TObject *Sender)
{
	pam2ExperimentForm->Gauge1->Progress = 0;
	this->SetMode(pam2Tuning);
	Timer1->Enabled = false;
    m_pam2Doc.AbortRecording();
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::toolsStopExperimentActionUpdate(TObject *Sender)
{
    toolsStopExperimentAction->Enabled = m_mode == pam2Capture;
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
	if (m_pam2Doc.notSaved)
	{
		if (Application->MessageBoxW(L"Документ содержит измерения, которые не были сохранены.\n\
		 Сохранить документ?", L"PAM2",  MB_YESNO) == IDYES)
		{
			//save helper
			if (!this->SaveAsHelper()) {
				return;
			}
		}
	}
	SetMode(pam2Tuning);
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::fileNewActionUpdate(TObject *Sender)
{
    fileNewAction->Enabled = m_mode != pam2Capture;
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::fileOpenActionExecute(TObject *Sender)
{
	if (m_pam2Doc.notSaved)
	{
		if (Application->MessageBoxW(L"Документ содержит измерения, которые не были сохранены.\n\
		 Сохранить документ?", L"PAM2",  MB_YESNO) == IDYES)
		{
			//save helper
			if (!this->SaveAsHelper()) {
				return;
			}
		}
	}

	 if (OpenDialog1->Execute())
	 {
		if (!m_pam2Doc.OpenDocument(OpenDialog1->FileName)) {
			ShowMessage(L"Не могу открыть файл \n" + OpenDialog1->FileName);
		}
		else
		{
			SetMode(pam2Analysis);
		}
	 }
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::fileOpenActionUpdate(TObject *Sender)
{
	fileOpenAction->Enabled = m_mode != pam2Capture;
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::fileCloseExperimentActionExecute(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::fileCloseExperimentActionUpdate(TObject *Sender)
{
	fileCloseExperimentAction->Enabled = m_mode != pam2Capture;
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::fileSaveExperimentActionExecute(TObject *Sender)
{
	if (m_pam2Doc.SaveDocument())
	{
		ShowMessage(L"Не могу сохранить документ!");
	}
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::fileSaveExperimentActionUpdate(TObject *Sender)
{
	fileSaveExperimentAction->Enabled = m_mode !=  pam2Capture && m_pam2Doc.notSaved;
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::windowConsoleActionUpdate(TObject *Sender)
{
	windowConsoleAction->Enabled = m_mode != pam2Analysis;
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
	 //  ConsoleForm->Memo1->Lines->Add("Изображение отправлено на экран.");
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
	if (this->m_hardware_ready) {
		ExecuteCommand(L"OFF");
		BUFCCDUSB_StopFrameGrab();
		BUFCCDUSB_StopFrameGrab();
		BUFCCDUSB_UnInitDevice();
	}

}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::tuningLiveVideoExecute(TObject *Sender)
{
	SetVideoMode(pam2videoLive);
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::tuningLiveVideoUpdate(TObject *Sender)
{
	tuningLiveVideo->Enabled = m_mode == pam2Tuning;
	tuningLiveVideo->Checked = m_videoMode == pam2videoLive;
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::tuningFlashActionExecute(TObject *Sender)
{
	BUFCCDUSB_StartFrameGrab(1);
	this->ExecuteCommand(L"FLASH");
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::tuningFlashActionUpdate(TObject *Sender)
{
	//tuningFlashAction->Checked = m_videoMode == pam2videoFlash;
	tuningFlashAction->Enabled = m_mode == pam2Tuning && m_videoMode == pam2videoCommands;
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::tuningCommandsActionExecute(TObject *Sender)
{
   SetVideoMode(pam2videoCommands);
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::tuningCommandsActionUpdate(TObject *Sender)
{
	tuningCommandsAction->Enabled = m_mode == pam2Tuning;
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
//	if (mode == m_mode)
//		  return;

	m_mode = mode;
	switch(m_mode)
	{
		case pam2Tuning:
			Panel2->Visible = false;
		break;
		case pam2Capture:
			Panel2->Visible = false;
		break;
		case pam2Analysis:
			Panel2->Visible = true;
			pam2HardwareForm->Visible = false;
			pam2ExperimentForm->Visible = false;
			ConsoleForm->Visible = false;
            pam2ScriptForm->Visible = false;
			PhTrackBar1->Min = 1;
			PhTrackBar1->Max = m_pam2Doc.NumFrames;
			PhTrackBar1->Frequency = m_pam2Doc.NumFrames / 20;
		break;

	}
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
		BUFCCDUSB_SetFrameTime( m_camera, 2500);
		BUFCCDUSB_StartFrameGrab(GRAB_FRAME_FOREVER);
	  }
	  else if (m_videoMode == pam2videoFlash)
	  {
		// запускаем таймер
		BUFCCDUSB_SetCameraWorkMode(m_camera, 1);
		//BUFCCDUSB_SetFrameTime( m_camera, 2500);
		Timer1->Enabled = true;
	  }
	  else if (m_videoMode == pam2videoCommands)
	  {
		// запускаем командный режим.
		BUFCCDUSB_StopFrameGrab();
		//BUFCCDUSB_SetFrameTime( m_camera, 2500);
		BUFCCDUSB_SetCameraWorkMode(m_camera, 1);
	  }
}

void __fastcall TpamMainForm::Timer1Timer(TObject *Sender)
{
	if (m_currentFlash == 0)
	{
		this->ExecuteCommand(L"FOFM");
	}
	else
		this->ExecuteCommand(L"FTFM1");
	m_currentFlash++;
	pam2ExperimentForm->Gauge1->Progress = (100*m_currentFlash)/m_numFlashes;
	if (m_currentFlash > m_numFlashes)
	{
		Timer1->Enabled = false;
		ConsoleForm->Memo1->Lines->Add("[PAM2@INFO:] Завершение измерений.");
		pam2ExperimentForm->Gauge1->Progress = 0;
		m_currentFlash = 0;
        m_pam2Doc.EndRecording();
        SetMode(pam2Analysis);
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
	windowHardwareAction->Enabled = m_mode == pam2Tuning;
	windowHardwareAction->Checked = pam2HardwareForm->Visible;
}
//---------------------------------------------------------------------------
void __fastcall TpamMainForm::SetExposure(int value)
{
	int exp_units = value / 50;
	if (BUFCCDUSB_SetExposureTime(m_camera, exp_units) == -1)
		ConsoleForm->Memo1->Lines->Add(L"[PAM2@ERROR]: Не могу установить экспозицю. Подключите видеокамеру Mightex.");
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
		ConsoleForm->Memo1->Lines->Add(L"[PAM2@ERROR]: Не могу установить усиление. Подключите видеокамеру Mightex.");
}

void __fastcall TpamMainForm::SetFlash(int value)
{
	if (value < 10 || value > 50) {
		ConsoleForm->Memo1->Lines->Add(L"[PAM2@ERROR]: Не могу установить длительность вспышки.");
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
		ConsoleForm->Memo1->Lines->Add(L"[PAM2@ERROR]: Не могу установить интенсивность насыщающего света.");
		return;
	}
	UnicodeString str = L"LSAT=";
	str += IntToStr(value);
	ExecuteCommand(str);
}

void __fastcall TpamMainForm::SwitchSat(int value)
{
	if (value !=0 && value !=1) {
		ConsoleForm->Memo1->Lines->Add(L"[PAM2@ERROR]: переключить источник насыщающего света.");
		return;
	}
	UnicodeString str = L"SAT=";
	str += IntToStr(value);
	ExecuteCommand(str);

}
void __fastcall TpamMainForm::SetAdd(int value)
{
	if (value < 0 || value > 100) {
		ConsoleForm->Memo1->Lines->Add(L"[PAM2@ERROR]: Не могу установить интенсивность дополнительного света.");
		return;
	}
	UnicodeString str = L"LADD=";
	str += IntToStr(value);
	ExecuteCommand(str);
}
void __fastcall TpamMainForm::SwitchAdd(int value)
{
	if (value !=0 && value !=1) {
		ConsoleForm->Memo1->Lines->Add(L"[PAM2@ERROR]: переключить источник дополнительного света.");
		return;
	}
	UnicodeString str = L"ADD=";
	str += IntToStr(value);
	ExecuteCommand(str);
}
void __fastcall TpamMainForm::SetAct(int value)
{
	if (value < 0 || value > 100) {
		ConsoleForm->Memo1->Lines->Add(L"[PAM2@ERROR]: Не могу установить интенсивность актиничного света.");
		return;
	}
	UnicodeString str = L"LACT=";
	str += IntToStr(value);
	ExecuteCommand(str);
}

void __fastcall TpamMainForm::SwitchAct(int value)
{
	if (value !=0 && value !=1) {
		ConsoleForm->Memo1->Lines->Add(L"[PAM2@ERROR]: переключить источник актиничного света.");
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
			ConsoleForm->Memo1->Lines->Add("[PAM2@ERROR]: команда " + command + L" не поддерживается в режиме отображения видеосигнала.");
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
			BUFCCDUSB_SetFrameTime( m_camera, 2500);
			BUFCCDUSB_StartFrameGrab(1);
		}
		 else if(command == L"FTFM1")
		 {
			m_buffer = new TPamImageBuffer(pam2bfFtFm1);
			BUFCCDUSB_SetCameraWorkMode(m_camera, 1);
			BUFCCDUSB_SetFrameTime( m_camera, 2500);
			BUFCCDUSB_StartFrameGrab(1);
		 }

		// если выполняется команда установки значения
		// переменной микропрограммы, то это значение записывается в
		// соотвтетствующую переменную приложения.
		UnicodeString cmd = command;
		cmd = ReplaceStr(cmd, L" ",L"");
		UnicodeString _str = cmd;
		int v= 0;
		bool checkAssigment = true;
		if (_str.Pos(L"EXP=")== 1) {
			// проверка допустимости команды
			 checkAssigment =TPam2ScriptDoc::CheckAssignment(_str, L"EXP", 50, 32000, v);
			 if (checkAssigment) {
				this->m_exposure = v;
				int exp_units = v / 50;
				if (BUFCCDUSB_SetExposureTime(m_camera, exp_units) == -1)
					ConsoleForm->Memo1->Lines->Add(L"[PAM2@ERROR]: Не могу установить экспозицю. Подключите видеокамеру Mightex.");
			 }
		}
		else if(_str.Pos(L"GAIN=")== 1)
		{
			checkAssigment =TPam2ScriptDoc::CheckAssignment(_str, L"GAIN", 6, 41,v);
			 if (checkAssigment) {
				this->m_gain = v;
			 if (BUFCCDUSB_SetGains(m_camera, v , v, v) == -1)
					ConsoleForm->Memo1->Lines->Add(L"[PAM2@ERROR]: Не могу установить усиление. Подключите видеокамеру Mightex.");

			 }
		}
		else if(_str.Pos(L"LSAT=")== 1)
		{
			checkAssigment =TPam2ScriptDoc::CheckAssignment(_str, L"LSAT", 0, 100,v);
			 if (checkAssigment) {
				this->m_lsat = v;
			 }

		}
		else if(_str.Pos(L"LACT=")== 1)
		{
			checkAssigment =TPam2ScriptDoc::CheckAssignment(_str, L"LACT", 0, 100,v);
			 if (checkAssigment) {
				this->m_lact = v;
			 }

		}
		else if(_str.Pos(L"LADD=")== 1)
		{
			checkAssigment =TPam2ScriptDoc::CheckAssignment(_str, L"ADD", 0, 1,v);
			 if (checkAssigment) {
				this->m_ladd = v;
			 }

		}
		else if(_str.Pos(L"SAT=")== 1)
		{
			checkAssigment =TPam2ScriptDoc::CheckAssignment(_str, L"SAT", 0, 1,v);
			 if (checkAssigment) {
				this->m_sat = v;
			 }

		}
		else if(_str.Pos(L"ACT=")== 1)
		{
			checkAssigment =TPam2ScriptDoc::CheckAssignment(_str, L"ACT", 0, 1,v);
			 if (checkAssigment) {
				this->m_act = v;
			 }

		}
		else if(_str.Pos(L"ADD=")== 1)
		{
			checkAssigment =TPam2ScriptDoc::CheckAssignment(_str, L"ADD", 0, 1,v);
			 if (checkAssigment) {
				this->m_add = v;
			 }

		}
		else if(_str.Pos(L"LFLASH=")== 1)
		{
			checkAssigment =TPam2ScriptDoc::CheckAssignment(_str, L"LFLASH", 20, 50,v);
			 if (checkAssigment) {
				this->m_lflash = v;
			 }

		}

		AnsiString str = command;
		sprintf(wb,"%s",str.c_str());
		i = pamMainForm->Comm1->Write(wb, command.Length()+1);
		//todo: проверить i !!!!
	}
	else
		ConsoleForm->Memo1->Lines->Add("[PAM2@ERROR]: Устройство не подключено.");
}

void __fastcall TpamMainForm::tuningDarkActionExecute(TObject *Sender)
{
	BUFCCDUSB_StartFrameGrab(1);
	this->ExecuteCommand(L"DARK");
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::tuningDarkActionUpdate(TObject *Sender)
{
	tuningDarkAction->Enabled = m_mode == pam2Tuning && m_videoMode == pam2videoCommands;
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::tuningFoFmActionExecute(TObject *Sender)
{
		this->ExecuteCommand(L"FOFM");
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::tuningFoFmActionUpdate(TObject *Sender)
{
	tuningFoFmAction->Enabled = m_mode == pam2Tuning && m_videoMode == pam2videoCommands;
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::tuningFtTm1ActionExecute(TObject *Sender)
{
	this->ExecuteCommand(L"FTFM1");
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::tuningFtTm1ActionUpdate(TObject *Sender)
{
	tuningFtTm1Action->Enabled = m_mode == pam2Tuning &&  m_videoMode == pam2videoCommands && m_pam2Doc.hasFoFm;
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
		//


		awpConvert(_img, AWP_CONVERT_TO_BYTE_WITH_NORM);
		this->SetPicture(_img);

		pam2ROIForm->NewImage(m_screenSource);

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
// устанавливает свкажность вспышек FTFM1 в секундах
// допустимый диапазон [2..30]
void __fastcall TpamMainForm::SetDutyСycle(int value)
{
	this->m_dutyСycle = value;
	bool e = Timer1->Enabled;
	Timer1->Enabled = false;
	this->Timer1->Interval = 1000*this->m_dutyСycle;
    Timer1->Enabled = e;
}
//---------------------------------------------------------------------------
// возвращает длительность эксперимента в секундах
int __fastcall TpamMainForm::GetCaptureDuration()
{
	return this->m_dutyСycle*this->m_numFlashes;
}

void __fastcall TpamMainForm::toolsOptionsActionUpdate(TObject *Sender)
{
    toolsOptionsAction->Enabled = m_mode != pam2Capture;
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::FormCloseQuery(TObject *Sender, bool &CanClose)
{
	if (m_mode == pam2Capture)
	{
		if (Application->MessageBoxW(L"Устройство находится в режиме измерений.\n\
			Остановить программу?",L"PAM2", MB_YESNO) == IDYES)
		{
			CanClose = true;
		}
		else
			CanClose = false;
	}
}
//---------------------------------------------------------------------------
bool __fastcall TpamMainForm::SaveAsHelper()
{
	if (SaveDialog1->Execute())
	{
		// добавим расширение к имени файла
		UnicodeString strFileName = ChangeFileExt(SaveDialog1->FileName, ".pam2");

		// проверка наличия файла
		if (FileExists(strFileName))
		{
			UnicodeString strMessage = L"Файл " + ExtractFileName(strFileName) + L" уже существует.\n";
			strMessage += L" Удалить его?";
			if (Application->MessageBoxW(strMessage.c_str(), L"PAM2", MB_YESNO)== IDYES)
			{
				// удаляем все файлы, связанные с экспериментом
				if (!TPam2Document::DeleteDocument(strFileName))
					return false;
			}
			else
				return false;
		}
		else
			return m_pam2Doc.SaveAsDocument(strFileName);
	}
	else
		return false;
}



void __fastcall TpamMainForm::PhTrackBar1Change(TObject *Sender)
{
	 m_pam2Doc.GoFrame(PhTrackBar1->Position);
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::fileSaveAsActionExecute(TObject *Sender)
{
    SaveAsHelper();
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::fileSaveAsActionUpdate(TObject *Sender)
{
	fileSaveAsAction->Enabled = m_mode !=  pam2Capture && m_pam2Doc.notSaved;
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::Timer2Timer(TObject *Sender)
{
	// получаем следующу команду
	UnicodeString cmd = pam2ScriptForm->Script->NextCommand();
	cmd = ReplaceStr(cmd, L" ",L"");
	Timer2->Enabled = false;
    Timer3->Enabled = true;
	if (cmd == L"END") {
	   // останавливаем выполнение скрипта
	   pam2ScriptForm->Script->IsRunning = false;
	   ConsoleForm->Memo1->Lines->Add("[PAM2@INFO:] Завершение скрипта.");
	   LongProcessForm->ModalResult= mrOk;
	}
	else if (m_cancelScript) {
		   pam2ScriptForm->Script->IsRunning = false;
		   ConsoleForm->Memo1->Lines->Add("[PAM2@INFO:] Отмена скрипта.");
		   LongProcessForm->ModalResult= mrOk;
		   //todo: удалить все, что скрипт начудил.
	 }
	else
	{
        LongProcessForm->Label1->Caption = L"Выполняется команда: " + cmd;
		LongProcessForm->Gauge1->Progress = 100*(double)m_currentEvent / (double)m_numEvents;
		m_currentEvent++;
		m_commandTime = pam2ScriptForm->Script->GetCommandTime(cmd);
		m_currentTime = GetTickCount();
		LongProcessForm->Gauge2->Progress = 0;
		this->ExecuteCommand(cmd);
	}

}
//---------------------------------------------------------------------------
void __fastcall TpamMainForm::Timer3Timer(TObject *Sender)
{
	//
	int t = GetTickCount() - m_currentTime;
	LongProcessForm->Gauge2->Progress = 100*(double)t / (double)m_commandTime;
}
//---------------------------------------------------------------------------
void __fastcall TpamMainForm::CancelScript()
{
    m_cancelScript = true;
}
void __fastcall TpamMainForm::InitHardware()
{
	 m_initArduino = true;
	 m_currentCommand = 0;
	 Timer4->Enabled = true;
	 pamSplashForm->ShowModal();

}
void __fastcall TpamMainForm::Timer4Timer(TObject *Sender)
{
	if (m_initArduino) {
		// получить следующую команду
		UnicodeString cmd = NextCommand();
		cmd = ReplaceStr(cmd, L" ",L"");
		Timer4->Enabled = false;
		if (cmd == L"END")
		{
			m_initArduino = false;
            pamSplashForm->ModalResult = mrOk;
		}
		else
		{
		   this->ExecuteCommand(cmd);
		}
	}
}
//---------------------------------------------------------------------------
UnicodeString  __fastcall TpamMainForm::NextCommand()
{
	if (m_currentCommand < m_initCommands->Count) {
		UnicodeString str = m_initCommands->Strings[m_currentCommand];
        m_currentCommand++;
		return str;
	}
	else
		return L"END";
}
void __fastcall TpamMainForm::FormShow(TObject *Sender)
{
	/*	Устанавливаем режим настройки, в случае когда все оборудование
		обнаружено и работает без ошибок.
	*/
	SetMode(m_hardware_ready?pam2Tuning:pam2Analysis);
	SetVideoMode(pam2videoCommands);
	SetViewSource(pam2viewFrame);
	if (m_hardware_ready) {
		InitHardware();
	}
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::imageBestFitActionExecute(TObject *Sender)
{
    PhImage1->BestFit();
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::imageBestFitActionUpdate(TObject *Sender)
{
	imageBestFitAction->Enabled = !PhImage1->Empty;
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::imageActualSizeActionExecute(TObject *Sender)
{
    PhImage1->ActualSize();
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::imageActualSizeActionUpdate(TObject *Sender)
{
	imageActualSizeAction->Enabled = !PhImage1->Empty;
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::imageZoomInActionExecute(TObject *Sender)
{
    PhImage1->ZoomIn(0,0);
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::imageZoomInActionUpdate(TObject *Sender)
{
	imageZoomInAction->Enabled = !PhImage1->Empty;
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::imageZoomOutActionExecute(TObject *Sender)
{
    PhImage1->ZoomOut(0,0);
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::imageZoomOutActionUpdate(TObject *Sender)
{
	imageZoomOutAction->Enabled = !PhImage1->Empty;
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::imageAddRectActionExecute(TObject *Sender)
{
	m_roiTool->PhImage = PhImage1;
	m_roiTool->Mode = TMRect;
	PhImage1->SelectPhTool(m_roiTool);
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::imageAddRectActionUpdate(TObject *Sender)
{
	imageAddRectAction->Enabled =  !PhImage1->Empty;
	TPhPam2RoiTool* tool = dynamic_cast< TPhPam2RoiTool*>(PhImage1->PhTool);
	imageAddRectAction->Checked = tool != NULL && tool->Mode == TMRect;

}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::imageAddCircleActionExecute(TObject *Sender)
{
	m_roiTool->PhImage = PhImage1;
	m_roiTool->Mode = TMCircle;
	PhImage1->SelectPhTool(m_roiTool);
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::imageAddCircleActionUpdate(TObject *Sender)
{
	imageAddCircleAction->Enabled = !PhImage1->Empty;
	TPhPam2RoiTool* tool = dynamic_cast< TPhPam2RoiTool*>(PhImage1->PhTool);
	imageAddCircleAction->Checked = tool != NULL && tool->Mode == TMCircle;
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::imageAddPolygonActionExecute(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::imageAddPolygonActionUpdate(TObject *Sender)
{
	imageAddPolygonAction->Enabled =  !PhImage1->Empty;
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::imageSaveActionExecute(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::imageSaveActionUpdate(TObject *Sender)
{
	imageSaveAction->Enabled = !PhImage1->Empty;
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::imageZoomPaneActionExecute(TObject *Sender)
{
	PhImage1->SelectPhTool(PhPaneTool1);
    PhImage1->Paint();
}
//---------------------------------------------------------------------------

void __fastcall TpamMainForm::imageZoomPaneActionUpdate(TObject *Sender)
{
	imageZoomPaneAction->Enabled = !PhImage1->Empty;
	TPhPaneTool* tool = dynamic_cast< TPhPaneTool*>(PhImage1->PhTool);
	imageZoomPaneAction->Checked = tool != NULL;// && tool->Mode == TMCircle;

}
//---------------------------------------------------------------------------
void __fastcall TpamMainForm::AddRoi(TObject* sender, TPam2ROI* item)
{
	if (item == NULL) {
		return;
	}
	// получим информацию с изображения
	item->Calculate(m_screenSource);

	pam2ROIForm->AddItem(item);
}

void __fastcall TpamMainForm::ChangeRoi(TObject* sender, int index)
{
   TPam2ROI* roi = RoiTool->GetRoi(index);
	if (roi == NULL) {
		return;
	}
	// получим информацию с изображения
	roi->Calculate(m_screenSource);
	pam2ROIForm->ChangeItem(index);
}

