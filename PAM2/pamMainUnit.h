//---------------------------------------------------------------------------

#ifndef pamMainUnitH
#define pamMainUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <System.Actions.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ToolWin.hpp>
#include "FImage41.h"
#include <Vcl.ExtCtrls.hpp>
#include "Comm.h"
#include "pamDocumentUnit.h"
#include "PhPalette.h"
#include <Vcl.Samples.Spin.hpp>
#include "pamImageBufferUnit.h"
#include "PhVideoTrackBar.h"
#include <Vcl.Dialogs.hpp>
#include "PhImageTool.h"
#include "PhPaneTool.h"
#include "PhTrackBar.h"
#include <System.ImageList.hpp>
#include <Vcl.ImgList.hpp>
#include "pam2ROIEditor.h"

typedef enum {pam2Tuning, pam2Capture, pam2Analysis}EPam2Modes;
typedef enum {pam2videoLive, pam2videoFlash, pam2videoCommands}EPam2VideoModes;
typedef enum {pam2viewFrame, pam2viewFo, pam2viewFm, pam2viewFt,pam2viewFm1,
pam2viewFv, pam2viewFv1, pam2viewFq1, pam2viewFo1, pam2viewFvFm1,
pam2viewYII1, pam2viewNPQ1, pam2viewqN1}EPam2ViewSource;
//---------------------------------------------------------------------------
class TpamMainForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TSplitter *Splitter1;
	TSplitter *Splitter2;
	TSplitter *Splitter3;
	TToolBar *ToolBar1;
	TPanel *LeftDocPanel;
	TPhImage *PhImage1;
	TPanel *RightDocPanel;
	TPanel *BottomDocPanel;
	TPhPalette *PhPalette1;
	TMainMenu *MainMenu1;
	TMenuItem *N1;
	TMenuItem *N23;
	TMenuItem *N27;
	TMenuItem *N24;
	TMenuItem *N26;
	TMenuItem *N22;
	TMenuItem *N25;
	TMenuItem *N2;
	TMenuItem *N3;
	TMenuItem *N13;
	TMenuItem *N28;
	TMenuItem *N29;
	TMenuItem *N30;
	TMenuItem *N31;
	TMenuItem *N5;
	TMenuItem *N14;
	TMenuItem *N19;
	TMenuItem *N15;
	TMenuItem *N16;
	TMenuItem *N4;
	TMenuItem *N7;
	TMenuItem *N6;
	TMenuItem *N20;
	TMenuItem *N21;
	TActionList *ActionList1;
	TAction *filesCloseAction;
	TAction *windowConsoleAction;
	TAction *windowExperimentAction;
	TAction *windowScriptAction;
	TAction *windowResultAction;
	TAction *windowROIAction;
	TAction *windowTimeLineAction;
	TAction *editCopyAction;
	TAction *toolsOptionsAction;
	TAction *toolsExecuteAction;
	TAction *toolsStartExperimetAction;
	TAction *toolsStopExperimentAction;
	TAction *helpContentAction;
	TAction *helpAboutAction;
	TAction *fileNewAction;
	TAction *fileOpenAction;
	TAction *fileCloseExperimentAction;
	TAction *fileSaveExperimentAction;
	TAction *tuningLiveVideo;
	TAction *tuningFlashAction;
	TAction *tuningCommandsAction;
	TComm *Comm1;
	TStatusBar *StatusBar1;
	TTimer *Timer1;
	TAction *paletteScaleAction;
	TAction *plaetteGrayscaleAction;
	TAction *paletteOceanAction;
	TAction *paletteGlowAction;
	TAction *paletteRedBlueAction;
	TAction *paletteTrafficAction;
	TAction *paletteSpecturmAction;
	TAction *paletteSpectrum2Action;
	TAction *paletteFalseColorsAction;
	TPopupMenu *PopupMenu1;
	TMenuItem *N32;
	TMenuItem *N33;
	TMenuItem *N34;
	TMenuItem *N35;
	TMenuItem *N36;
	TMenuItem *N37;
	TMenuItem *N38;
	TMenuItem *N39;
	TMenuItem *N210;
	TMenuItem *N40;
	TAction *windowHardwareAction;
	TToolButton *ToolButton1;
	TToolButton *ToolButton2;
	TToolButton *ToolButton3;
	TToolButton *ToolButton4;
	TToolButton *ToolButton5;
	TToolButton *ToolButton6;
	TToolButton *ToolButton7;
	TToolButton *ToolButton8;
	TToolButton *ToolButton9;
	TToolButton *ToolButton10;
	TToolButton *ToolButton11;
	TToolButton *ToolButton12;
	TToolButton *ToolButton13;
	TToolButton *ToolButton14;
	TToolButton *ToolButton15;
	TToolButton *ToolButton16;
	TAction *tuningDarkAction;
	TAction *tuningFoFmAction;
	TAction *tuningFtTm1Action;
	TMenuItem *N42;
	TMenuItem *N43;
	TMenuItem *FoFm1;
	TMenuItem *FtFm1;
	TMenuItem *N110;
	TMenuItem *N44;
	TAction *viewFrameAction;
	TAction *viewFoAction;
	TAction *viewFmAction;
	TAction *viewFtAction;
	TAction *viewFm1Action;
	TAction *viewFvAction;
	TAction *viewFv1Action;
	TAction *viewFq1Action;
	TAction *viewFo1Action;
	TAction *viewFvFm1Action;
	TAction *viewYII1Action;
	TAction *viewNPQ1Action;
	TAction *viewqN1Action;
	TMenuItem *N41;
	TMenuItem *N45;
	TMenuItem *N46;
	TMenuItem *Fo1;
	TMenuItem *Fm1;
	TMenuItem *Ft1;
	TMenuItem *Fm2;
	TMenuItem *Fv1;
	TMenuItem *Fv2;
	TMenuItem *Fq1;
	TMenuItem *Fo2;
	TMenuItem *FvFm1;
	TMenuItem *YII1;
	TMenuItem *NPQ1;
	TMenuItem *qN1;
	TMenuItem *Fyfkb1;
	TMenuItem *N47;
	TMenuItem *N48;
	TMenuItem *N49;
	TMenuItem *N50;
	TMenuItem *N8;
	TMenuItem *N9;
	TPanel *Panel2;
	TOpenDialog *OpenDialog1;
	TSaveDialog *SaveDialog1;
	TPhPaneTool *PhPaneTool1;
	TToolButton *ToolButton17;
	TPhTrackBar *PhTrackBar1;
	TImageList *ImageList1;
	TToolButton *ToolButton18;
	TToolButton *ToolButton19;
	TAction *fileSaveAsAction;
	TMenuItem *N10;
	TTimer *Timer2;
	TTimer *Timer3;
	TTimer *Timer4;
	TMenuItem *N11;
	TAction *imageBestFitAction;
	TAction *imageActualSizeAction;
	TAction *imageZoomInAction;
	TPopupMenu *PopupMenu2;
	TMenuItem *N12;
	TMenuItem *N17;
	TMenuItem *N18;
	TAction *imageZoomOutAction;
	TMenuItem *N51;
	TMenuItem *N52;
	TAction *imageAddRectAction;
	TAction *imageAddCircleAction;
	TAction *imageAddPolygonAction;
	TAction *imageSaveAction;
	TMenuItem *N56;
	TMenuItem *N57;
	TAction *imageZoomPaneAction;
	TMenuItem *N58;
	TMenuItem *N53;
	void __fastcall filesCloseActionExecute(TObject *Sender);
	void __fastcall LeftDocPanelDockOver(TObject *Sender, TDragDockObject *Source, int X,
          int Y, TDragState State, bool &Accept);
	void __fastcall RightDocPanelDockOver(TObject *Sender, TDragDockObject *Source,
		  int X, int Y, TDragState State, bool &Accept);
	void __fastcall BottomDocPanelDockOver(TObject *Sender, TDragDockObject *Source,
          int X, int Y, TDragState State, bool &Accept);
	void __fastcall windowConsoleActionExecute(TObject *Sender);
	void __fastcall LeftDocPanelUnDock(TObject *Sender, TControl *Client, TWinControl *NewTarget,
          bool &Allow);
	void __fastcall LeftDocPanelDockDrop(TObject *Sender, TDragDockObject *Source, int X,
          int Y);
	void __fastcall RightDocPanelDockDrop(TObject *Sender, TDragDockObject *Source,
          int X, int Y);
	void __fastcall RightDocPanelUnDock(TObject *Sender, TControl *Client, TWinControl *NewTarget,
          bool &Allow);
	void __fastcall BottomDocPanelDockDrop(TObject *Sender, TDragDockObject *Source,
          int X, int Y);
	void __fastcall BottomDocPanelUnDock(TObject *Sender, TControl *Client, TWinControl *NewTarget,
          bool &Allow);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Comm1RxChar(TObject *param_0, DWORD Count);
	void __fastcall windowExperimentActionExecute(TObject *Sender);
	void __fastcall windowExperimentActionUpdate(TObject *Sender);
	void __fastcall windowScriptActionExecute(TObject *Sender);
	void __fastcall windowScriptActionUpdate(TObject *Sender);
	void __fastcall windowResultActionExecute(TObject *Sender);
	void __fastcall windowResultActionUpdate(TObject *Sender);
	void __fastcall windowROIActionExecute(TObject *Sender);
	void __fastcall windowROIActionUpdate(TObject *Sender);
	void __fastcall windowTimeLineActionExecute(TObject *Sender);
	void __fastcall windowTimeLineActionUpdate(TObject *Sender);
	void __fastcall editCopyActionExecute(TObject *Sender);
	void __fastcall editCopyActionUpdate(TObject *Sender);
	void __fastcall toolsOptionsActionExecute(TObject *Sender);
	void __fastcall toolsExecuteActionExecute(TObject *Sender);
	void __fastcall toolsExecuteActionUpdate(TObject *Sender);
	void __fastcall toolsStartExperimetActionExecute(TObject *Sender);
	void __fastcall toolsStartExperimetActionUpdate(TObject *Sender);
	void __fastcall toolsStopExperimentActionExecute(TObject *Sender);
	void __fastcall toolsStopExperimentActionUpdate(TObject *Sender);
	void __fastcall helpAboutActionExecute(TObject *Sender);
	void __fastcall helpAboutActionUpdate(TObject *Sender);
	void __fastcall helpContentActionExecute(TObject *Sender);
	void __fastcall helpContentActionUpdate(TObject *Sender);
	void __fastcall fileNewActionExecute(TObject *Sender);
	void __fastcall fileNewActionUpdate(TObject *Sender);
	void __fastcall fileOpenActionExecute(TObject *Sender);
	void __fastcall fileOpenActionUpdate(TObject *Sender);
	void __fastcall fileCloseExperimentActionExecute(TObject *Sender);
	void __fastcall fileCloseExperimentActionUpdate(TObject *Sender);
	void __fastcall fileSaveExperimentActionExecute(TObject *Sender);
	void __fastcall fileSaveExperimentActionUpdate(TObject *Sender);
	void __fastcall windowConsoleActionUpdate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall tuningLiveVideoExecute(TObject *Sender);
	void __fastcall tuningLiveVideoUpdate(TObject *Sender);
	void __fastcall tuningFlashActionExecute(TObject *Sender);
	void __fastcall tuningFlashActionUpdate(TObject *Sender);
	void __fastcall tuningCommandsActionExecute(TObject *Sender);
	void __fastcall tuningCommandsActionUpdate(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall paletteScaleActionExecute(TObject *Sender);
	void __fastcall paletteScaleActionUpdate(TObject *Sender);
	void __fastcall plaetteGrayscaleActionExecute(TObject *Sender);
	void __fastcall plaetteGrayscaleActionUpdate(TObject *Sender);
	void __fastcall paletteOceanActionExecute(TObject *Sender);
	void __fastcall paletteOceanActionUpdate(TObject *Sender);
	void __fastcall paletteGlowActionExecute(TObject *Sender);
	void __fastcall paletteGlowActionUpdate(TObject *Sender);
	void __fastcall paletteRedBlueActionExecute(TObject *Sender);
	void __fastcall paletteRedBlueActionUpdate(TObject *Sender);
	void __fastcall paletteTrafficActionExecute(TObject *Sender);
	void __fastcall paletteTrafficActionUpdate(TObject *Sender);
	void __fastcall paletteSpecturmActionExecute(TObject *Sender);
	void __fastcall paletteSpecturmActionUpdate(TObject *Sender);
	void __fastcall paletteSpectrum2ActionExecute(TObject *Sender);
	void __fastcall paletteSpectrum2ActionUpdate(TObject *Sender);
	void __fastcall paletteFalseColorsActionExecute(TObject *Sender);
	void __fastcall paletteFalseColorsActionUpdate(TObject *Sender);
	void __fastcall windowHardwareActionExecute(TObject *Sender);
	void __fastcall windowHardwareActionUpdate(TObject *Sender);
	void __fastcall tuningDarkActionExecute(TObject *Sender);
	void __fastcall tuningDarkActionUpdate(TObject *Sender);
	void __fastcall tuningFoFmActionExecute(TObject *Sender);
	void __fastcall tuningFoFmActionUpdate(TObject *Sender);
	void __fastcall tuningFtTm1ActionExecute(TObject *Sender);
	void __fastcall tuningFtTm1ActionUpdate(TObject *Sender);
	void __fastcall viewFrameActionExecute(TObject *Sender);
	void __fastcall viewFrameActionUpdate(TObject *Sender);
	void __fastcall viewFoActionExecute(TObject *Sender);
	void __fastcall viewFoActionUpdate(TObject *Sender);
	void __fastcall viewFmActionExecute(TObject *Sender);
	void __fastcall viewFmActionUpdate(TObject *Sender);
	void __fastcall viewFtActionExecute(TObject *Sender);
	void __fastcall viewFtActionUpdate(TObject *Sender);
	void __fastcall viewFm1ActionExecute(TObject *Sender);
	void __fastcall viewFm1ActionUpdate(TObject *Sender);
	void __fastcall viewFvActionExecute(TObject *Sender);
	void __fastcall viewFvActionUpdate(TObject *Sender);
	void __fastcall viewFv1ActionExecute(TObject *Sender);
	void __fastcall viewFv1ActionUpdate(TObject *Sender);
	void __fastcall viewFq1ActionExecute(TObject *Sender);
	void __fastcall viewFq1ActionUpdate(TObject *Sender);
	void __fastcall viewFo1ActionExecute(TObject *Sender);
	void __fastcall viewFo1ActionUpdate(TObject *Sender);
	void __fastcall viewFvFm1ActionExecute(TObject *Sender);
	void __fastcall viewFvFm1ActionUpdate(TObject *Sender);
	void __fastcall viewYII1ActionExecute(TObject *Sender);
	void __fastcall viewYII1ActionUpdate(TObject *Sender);
	void __fastcall viewNPQ1ActionExecute(TObject *Sender);
	void __fastcall viewNPQ1ActionUpdate(TObject *Sender);
	void __fastcall viewqN1ActionExecute(TObject *Sender);
	void __fastcall viewqN1ActionUpdate(TObject *Sender);
	void __fastcall PhImage1MouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall toolsOptionsActionUpdate(TObject *Sender);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall PhTrackBar1Change(TObject *Sender);
	void __fastcall fileSaveAsActionExecute(TObject *Sender);
	void __fastcall fileSaveAsActionUpdate(TObject *Sender);
	void __fastcall Timer2Timer(TObject *Sender);
	void __fastcall Timer3Timer(TObject *Sender);
	void __fastcall Timer4Timer(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall imageBestFitActionExecute(TObject *Sender);
	void __fastcall imageBestFitActionUpdate(TObject *Sender);
	void __fastcall imageActualSizeActionExecute(TObject *Sender);
	void __fastcall imageActualSizeActionUpdate(TObject *Sender);
	void __fastcall imageZoomInActionExecute(TObject *Sender);
	void __fastcall imageZoomInActionUpdate(TObject *Sender);
	void __fastcall imageZoomOutActionExecute(TObject *Sender);
	void __fastcall imageZoomOutActionUpdate(TObject *Sender);
	void __fastcall imageAddRectActionExecute(TObject *Sender);
	void __fastcall imageAddRectActionUpdate(TObject *Sender);
	void __fastcall imageAddCircleActionExecute(TObject *Sender);
	void __fastcall imageAddCircleActionUpdate(TObject *Sender);
	void __fastcall imageAddPolygonActionExecute(TObject *Sender);
	void __fastcall imageAddPolygonActionUpdate(TObject *Sender);
	void __fastcall imageSaveActionExecute(TObject *Sender);
	void __fastcall imageSaveActionUpdate(TObject *Sender);
	void __fastcall imageZoomPaneActionExecute(TObject *Sender);
	void __fastcall imageZoomPaneActionUpdate(TObject *Sender);



private:	// User declarations
	AnsiString rs;
	TPam2Document   m_pam2Doc;
	int             m_camera;
	int				m_numCameras;
	int             m_Flash;
	EPam2Modes      m_mode;
	EPam2VideoModes m_videoMode;
	EPam2ViewSource m_viewSource;
	bool OpenCamera();
	void __fastcall SetMode(EPam2Modes mode);
	void __fastcall SetVideoMode(EPam2VideoModes mode);
	void __fastcall SetViewSource(EPam2ViewSource source);
	TPamImageBuffer* m_buffer;
	awpImage*        m_screenSource;
	// параметры эксперимента
	int              m_numFlashes;
	int              m_dutyСycle;
	int              m_currentFlash;
	int              m_timeOut;
	// параметры скрипта
	int              m_numEvents;
	int              m_currentEvent;
	int              m_commandTime;
	DWORD            m_currentTime;
	bool             m_cancelScript;
	// параметры видеокамеры
	int              m_exposure;
	int              m_gain;
	// параметры освещения
	int              m_sat;
	int              m_act;
	int              m_add;
	int              m_lsat;
	int              m_lact;
	int              m_ladd;
	int              m_lflash;
	// переменные инициализации оборудования
	int              m_currentCommand;
	bool             m_initArduino;
	TStringList*     m_initCommands;
	// получение состояния микроконтроллера
	bool             m_hardware_ready;

	// редактор roi
	TPhPam2RoiTool*  m_roiTool;
protected:
	BEGIN_MESSAGE_MAP
		VCL_MESSAGE_HANDLER(WM_USER+1, TMessage, WMUSER1)
		VCL_MESSAGE_HANDLER(WM_USER+2, TMessage, WMUSER2)
	END_MESSAGE_MAP(TForm)

	void __fastcall WMUSER1(TMessage & msg);
	void __fastcall WMUSER2(TMessage & msg);

	TPam2Document* __fastcall GetDocument();
	void __fastcall SetDutyСycle(int value);
	int __fastcall GetCaptureDuration();
	bool __fastcall SaveAsHelper();

	void __fastcall InitHardware();
	UnicodeString  __fastcall NextCommand();
	void __fastcall AddRoi(TObject* sender, TPam2ROI* item);
	void __fastcall ChangeRoi(TObject* sender,  int index);
public:		// User declarations
	__fastcall TpamMainForm(TComponent* Owner);
	void ShowDockPanel(TWinControl* APanel, bool MakeVisible, TControl* Client);
	void __fastcall PreviewFrame(int width, int height, unsigned char* data, int cameraID);
	void __fastcall SetExposure(int value);
	void __fastcall SetGain(int value);
	void __fastcall SetFlash(int value);
	void __fastcall SetSat(int value);
	void __fastcall SwitchSat(int value);
	void __fastcall SetAdd(int value);
	void __fastcall SwitchAdd(int value);
	void __fastcall SetAct(int value);
	void __fastcall SwitchAct(int value);
	void __fastcall ExecuteCommand(const UnicodeString& command);

	void __fastcall SetPicture(awpImage* img);
	void __fastcall UpdateScreen();
	void __fastcall CancelScript();
	__property TPam2Document* doc = {read = GetDocument};

	// параметры эксперимента
	__property int NumFlashes = {read = m_numFlashes, write = m_numFlashes};
	__property int DutyСycle = {read = m_dutyСycle, write = SetDutyСycle};
	__property int CaptureDuration = {read = GetCaptureDuration};

	__property EPam2Modes Mode = {read = m_mode};
	__property int Exposure = {read = m_exposure, write = SetExposure};
	__property int Gain     = {read = m_gain, write = SetGain};

	__property int Sat = {read = m_sat, write = SwitchSat};
	__property int Act = {read = m_act, write = SwitchAct};
	__property int Add = {read = m_add, write = SwitchAdd};
	__property int LSat = {read=m_lsat, write = SetSat};
	__property int LAct = {read = m_lact, write = SetAct};
	__property int LAdd = {read = m_ladd, write = SetAdd};
	__property int LFlash = {read= m_lflash, write = SetFlash};

	__property TPhPam2RoiTool* RoiTool = {read = m_roiTool};
};
//---------------------------------------------------------------------------
extern PACKAGE TpamMainForm *pamMainForm;
//---------------------------------------------------------------------------
#endif
