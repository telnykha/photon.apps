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
typedef enum {pam2Tuning, pam2Capture, pam2Analysis}EPam2Modes;
typedef enum {pam2videoLive, pam2videoFlash, pam2videoCommands}EPam2VideoModes;
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
	TMenuItem *N18;
	TMenuItem *N17;
	TMenuItem *N4;
	TMenuItem *N7;
	TMenuItem *N8;
	TMenuItem *N9;
	TMenuItem *N10;
	TMenuItem *N11;
	TMenuItem *N12;
	TMenuItem *N6;
	TMenuItem *N20;
	TMenuItem *N21;
	TActionList *ActionList1;
	TAction *filesCloseAction;
	TAction *windowConsoleAction;
	TAction *windowExperimentAction;
	TAction *windowScriptAction;
	TAction *windowResultAction;
	TAction *windowDistributionAction;
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
	TAction *modeLiveVideo;
	TAction *modeFlashAction;
	TAction *modeCommandsAction;
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
	TMenuItem *N41;
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
	void __fastcall windowDistributionActionExecute(TObject *Sender);
	void __fastcall windowDistributionActionUpdate(TObject *Sender);
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
	void __fastcall modeLiveVideoExecute(TObject *Sender);
	void __fastcall modeLiveVideoUpdate(TObject *Sender);
	void __fastcall modeFlashActionExecute(TObject *Sender);
	void __fastcall modeFlashActionUpdate(TObject *Sender);
	void __fastcall modeCommandsActionExecute(TObject *Sender);
	void __fastcall modeCommandsActionUpdate(TObject *Sender);
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


private:	// User declarations
	AnsiString rs;
	TPam2Document m_pam2Doc;
    int             m_camera;
    int				m_numCameras;
    int             m_Flash;
	EPam2Modes      m_mode;
	EPam2VideoModes m_videoMode;
	bool OpenCamera();
	void __fastcall SetMode(EPam2Modes mode);
	void __fastcall SetVideoMode(EPam2VideoModes mode);

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
};
//---------------------------------------------------------------------------
extern PACKAGE TpamMainForm *pamMainForm;
//---------------------------------------------------------------------------
#endif
