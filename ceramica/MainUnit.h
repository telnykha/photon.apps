//---------------------------------------------------------------------------

#ifndef MainUnitH
#define MainUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <System.Actions.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "FImage41.h"
#include <Vcl.Dialogs.hpp>
#include <Vcl.Buttons.hpp>
#include "PhImageTool.h"
#include "PhRulerTool.h"
#include "PhPaneTool.h"
#include "awpipl.h"
#include "CeramUtils.h"
#include "CeramArchive.h"
#include <Vcl.Samples.Spin.hpp>
#include <VCLTee.Chart.hpp>
#include <VCLTee.Series.hpp>
#include <VclTee.TeeGDIPlus.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdCustomTCPServer.hpp>
#include <IdTCPServer.hpp>
#include <IdContext.hpp>
#include <Vcl.ToolWin.hpp>
#include <System.ImageList.hpp>
#include <Vcl.ImgList.hpp>
#include "PhSelectRectTool.h"
#include <Vcl.AppEvnts.hpp>
#include "PhTrackBar.h"

//---------------------------------------------------------------------------
class TPhMediaSource;
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TStatusBar *StatusBar1;
	TActionList *ActionList1;
	TAction *fileExitAction;
	TMainMenu *MainMenu1;
	TMenuItem *N1;
	TMenuItem *N2;
	TPanel *Panel2;
	TPanel *Panel3;
	TPhImage *PhImage1;
	TMenuItem *N3;
	TAction *modeExperimentAction;
	TAction *modeAutoAnalysisAction;
	TAction *modeHandAction;
	TMenuItem *N4;
	TMenuItem *N6;
	TMenuItem *N7;
	TMenuItem *N8;
	TAction *viewSourceImageAction;
	TAction *viewAnalysisAreaAction;
	TAction *viewObjectContourAction;
	TAction *viewCenterAction;
	TAction *viewAxisAction;
	TAction *viewEllipseAction;
	TMenuItem *N9;
	TMenuItem *N10;
	TMenuItem *N11;
	TMenuItem *N12;
	TMenuItem *N13;
	TMenuItem *N14;
	TAction *fileOpenImagesAction;
	TAction *fileOpenVideoAction;
	TAction *fileConnectToCameraAction;
	TAction *fileCloseAction;
	TOpenDialog *OpenDialog1;
	TMenuItem *N15;
	TMenuItem *N16;
	TMenuItem *N17;
	TMenuItem *N18;
	TMenuItem *N19;
	TSpeedButton *SpeedButton4;
	TSpeedButton *SpeedButton1;
	TSpeedButton *SpeedButton3;
	TSpeedButton *SpeedButton2;
	TSpeedButton *SpeedButton9;
	TAction *viewFirstAction;
	TAction *viewPrevAction;
	TAction *viewNextAction;
	TAction *viewLastAction;
	TAction *viewPlayAction;
	TPhRulerTool *PhRulerTool1;
	TPhPaneTool *PhPaneTool1;
	TAction *viewBinaryAction;
	TMenuItem *N20;
	TTimer *Timer1;
	TPanel *Panel1;
	TGroupBox *GroupBox1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TChart *Chart1;
	TFastLineSeries *Series1;
	TPanel *Panel4;
	TIdTCPServer *IdTCPServer1;
	TGroupBox *GroupBox2;
	TLabel *Label12;
	TLabel *Label13;
	TLabel *Label14;
	TLabel *Label15;
	TLabel *Label16;
	TLabel *Label17;
	TLabel *Label18;
	TBevel *Bevel1;
	TLabel *Label19;
	TLabel *Label20;
	TEdit *Edit1;
	TCheckBox *CheckBox1;
	TSpinEdit *SpinEdit1;
	TButton *Button1;
	TEdit *Edit2;
	TSpinEdit *SpinEdit2;
	TMemo *Memo1;
	TSpinEdit *SpinEdit3;
	TLabel *Label23;
	TComboBox *ComboBox1;
	TAction *fileClientAction;
	TMenuItem *N5;
	TMenuItem *N21;
	TAction *helpAboutAction;
	TMenuItem *N22;
	TMenuItem *N23;
	TCheckBox *CheckBox2;
	TAction *viewVideoControlAction;
	TMenuItem *N24;
	TMenuItem *viewVideoControlAction1;
	TCheckBox *CheckBox3;
	TAction *viewRawContourAction;
	TMenuItem *N25;
	TPanel *Panel5;
	TImageList *ImageList1;
	TSpeedButton *SpeedButton6;
	TSpeedButton *SpeedButton7;
	TSpeedButton *SpeedButton8;
	TSpeedButton *SpeedButton10;
	TSpeedButton *SpeedButton11;
	TSpeedButton *SpeedButton12;
	TSpeedButton *SpeedButton13;
	TAction *helpManualAction;
	TMenuItem *N26;
	TAction *toolPaneAction;
	TAction *toolRulerAction;
	TAction *toolSelRectAction;
	TPhSelRectTool *PhSelRectTool1;
	TSpeedButton *SpeedButton5;
	TBevel *Bevel2;
	TApplicationEvents *ApplicationEvents1;
	TPhTrackBar *PhTrackBar1;
	TCheckBox *CheckBox4;
	void __fastcall fileExitActionExecute(TObject *Sender);
	void __fastcall modeExperimentActionExecute(TObject *Sender);
	void __fastcall modeExperimentActionUpdate(TObject *Sender);
	void __fastcall modeAutoAnalysisActionExecute(TObject *Sender);
	void __fastcall modeAutoAnalysisActionUpdate(TObject *Sender);
	void __fastcall modeHandActionExecute(TObject *Sender);
	void __fastcall modeHandActionUpdate(TObject *Sender);
	void __fastcall viewAnalysisAreaActionExecute(TObject *Sender);
	void __fastcall viewAnalysisAreaActionUpdate(TObject *Sender);
	void __fastcall viewObjectContourActionExecute(TObject *Sender);
	void __fastcall viewObjectContourActionUpdate(TObject *Sender);
	void __fastcall viewCenterActionExecute(TObject *Sender);
	void __fastcall viewCenterActionUpdate(TObject *Sender);
	void __fastcall viewAxisActionExecute(TObject *Sender);
	void __fastcall viewAxisActionUpdate(TObject *Sender);
	void __fastcall viewEllipseActionExecute(TObject *Sender);
	void __fastcall viewEllipseActionUpdate(TObject *Sender);
	void __fastcall fileOpenImagesActionExecute(TObject *Sender);
	void __fastcall fileOpenVideoActionExecute(TObject *Sender);
	void __fastcall fileConnectToCameraActionExecute(TObject *Sender);
	void __fastcall fileCloseActionExecute(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall PhImage1AfterOpen(TObject *Sender);
	void __fastcall viewFirstActionExecute(TObject *Sender);
	void __fastcall viewFirstActionUpdate(TObject *Sender);
	void __fastcall viewPrevActionExecute(TObject *Sender);
	void __fastcall viewPrevActionUpdate(TObject *Sender);
	void __fastcall viewNextActionExecute(TObject *Sender);
	void __fastcall viewNextActionUpdate(TObject *Sender);
	void __fastcall viewLastActionExecute(TObject *Sender);
	void __fastcall viewLastActionUpdate(TObject *Sender);
	void __fastcall viewPlayActionExecute(TObject *Sender);
	void __fastcall viewPlayActionUpdate(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall PhImage1MouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall PhImage1FrameData(TObject *Sender, int w, int h, int c, BYTE *data);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall viewSourceImageActionExecute(TObject *Sender);
	void __fastcall CheckBox1Click(TObject *Sender);
	void __fastcall SpinEdit1Change(TObject *Sender);
	void __fastcall Edit2Change(TObject *Sender);
	void __fastcall SpinEdit2Change(TObject *Sender);
	void __fastcall viewBinaryActionExecute(TObject *Sender);
	void __fastcall viewBinaryActionUpdate(TObject *Sender);
	void __fastcall Edit1Change(TObject *Sender);
	void __fastcall Edit1Enter(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Panel4Click(TObject *Sender);
	void __fastcall IdTCPServer1Execute(TIdContext *AContext);
	void __fastcall IdTCPServer1Connect(TIdContext *AContext);
	void __fastcall IdTCPServer1Disconnect(TIdContext *AContext);
	void __fastcall fileClientActionExecute(TObject *Sender);
	void __fastcall helpAboutActionExecute(TObject *Sender);
	void __fastcall CheckBox2Click(TObject *Sender);
	void __fastcall viewVideoControlActionExecute(TObject *Sender);
	void __fastcall viewVideoControlActionUpdate(TObject *Sender);
	void __fastcall viewRawContourActionExecute(TObject *Sender);
	void __fastcall viewRawContourActionUpdate(TObject *Sender);
	void __fastcall helpManualActionExecute(TObject *Sender);
	void __fastcall toolPaneActionExecute(TObject *Sender);
	void __fastcall toolPaneActionUpdate(TObject *Sender);
	void __fastcall toolRulerActionExecute(TObject *Sender);
	void __fastcall toolRulerActionUpdate(TObject *Sender);
	void __fastcall toolSelRectActionExecute(TObject *Sender);
	void __fastcall toolSelRectActionUpdate(TObject *Sender);
	void __fastcall CheckBox3Click(TObject *Sender);
	void __fastcall ApplicationEvents1Idle(TObject *Sender, bool &Done);
	void __fastcall PhTrackBar1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall PhTrackBar1Change(TObject *Sender);




private:	// User declarations
    void __fastcall SetMode(TAction* action);
    void __fastcall SetSource(TPhMediaSource* source);

    void __fastcall StartExperiment();
    void __fastcall StopExperiment();

    TPhMediaSource* m_videoSource;
    TAction*        m_modeAction;

    // drawing
    void __fastcall RenderScene(awpImage* img);
    void __fastcall DrawRuler(awpImage* img);
    void __fastcall DrawMask(awpImage* img);
    void __fastcall DrawSource(awpImage* img);
    void __fastcall DrawCenter(awpImage* img);
    void __fastcall DrawObject(awpImage* img);
    void __fastcall DrawEllipce(awpImage* img);
    void __fastcall DrawAxis(awpImage* img);
    void __fastcall DrawBinary(awpImage* img);
    void __fastcall DrawRawContour(awpImage* img);
    // processing
    TCeramImageProcessor m_engine;
    TCeramCalibration    m_c;
    TLFBuffer*           m_buffer;
    TCeramArchive*       m_archive;
    TLFImage             m_copy;
    // result
    void __fastcall ShowResult();
    void __fastcall Reset();
    // params
    void  __fastcall SaveParams();
    void  __fastcall LoadParams();

    // updates
    void __fastcall UpdateRuler();

    // edit3 old value
    int m_e3ov;
    // edit1 ild value
    float m_e1ov;

public:		// User declarations
	__fastcall TMainForm(TComponent* Owner);

	__property TPhMediaSource* videoSource = {read = m_videoSource};
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
