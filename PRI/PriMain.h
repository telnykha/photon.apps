//---------------------------------------------------------------------------

#ifndef PriMainH
#define PriMainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.Samples.Spin.hpp>
#include "FImage41.h"
#include "_LF.h"
#include "InitFileUnit.h"
#include "ArchiveUnit.h"
#include "PriProcessor.h"
#include <Vcl.Grids.hpp>
#include <System.Actions.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.Buttons.hpp>
#include "PhImageTool.h"
#include "PhPaneTool.h"
#include "PhZoomToRectTool.h"
#include <VCLTee.Series.hpp>
#include <Vcl.CheckLst.hpp>
#include "PriRoiEditor.h"
#include <VCLTee.Chart.hpp>
#include <VclTee.TeeGDIPlus.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.Samples.Gauges.hpp>

//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel3;
	TPageControl *PageControl1;
	TTabSheet *TabSheet2;
	TPanel *Panel2;
	TGroupBox *GroupBox2;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TSpinEdit *SpinEdit1;
	TSpinEdit *SpinEdit2;
	TSpinEdit *SpinEdit3;
	TGroupBox *GroupBox1;
	TComboBox *ComboBox1;
	TTrackBar *TrackBar1;
	TCheckBox *CheckBox1;
	TPanel *Panel8;
	TTabSheet *TabSheet3;
	TPanel *Panel4;
	TPanel *Panel5;
	TSplitter *Splitter1;
	TPanel *Panel6;
	TSplitter *Splitter2;
	TPanel *Panel7;
	TPanel *Panel10;
	TSplitter *Splitter3;
	TPanel *Panel11;
	TLabel *Label4;
	TListBox *ListBox1;
	TLabel *Label5;
	TListBox *ListBox2;
	TPanel *Panel12;
	TSplitter *Splitter4;
	TLabel *Label6;
	TPageControl *PageControl3;
	TTabSheet *TabSheet8;
	TTabSheet *TabSheet9;
	TStringGrid *StringGrid1;
	TMainMenu *MainMenu1;
	TActionList *ActionList1;
	TAction *fileCloseAction;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *N3;
	TMenuItem *N5;
	TMenuItem *N6;
	TAction *deviceCalibrationAction;
	TMenuItem *N7;
	TAction *deviceExperimentAction;
	TMenuItem *N8;
	TAction *toolsOptionsAction;
	TMenuItem *N9;
	TAction *helpAboutAction;
	TAction *helpContestsAction;
	TMenuItem *N10;
	TMenuItem *N11;
	TPanel *Panel13;
	TPanel *Panel1;
	TPhImage *PhImage4;
	TPanel *Panel14;
	TPanel *Panel15;
	TStatusBar *StatusBar1;
	TStatusBar *StatusBar2;
	TSpeedButton *SpeedButton1;
	TSpeedButton *SpeedButton2;
	TSpeedButton *SpeedButton3;
	TSpeedButton *SpeedButton4;
	TSpeedButton *SpeedButton5;
	TAction *viewPRIAction;
	TAction *view531Action;
	TAction *view570Action;
	TAction *view531fAction;
	TAction *view570fAction;
	TMenuItem *N12;
	TAction *fileExportTableAction;
	TMenuItem *N13;
	TAction *fileExportImageAction;
	TMenuItem *N14;
	TAction *filePrintAction;
	TMenuItem *N4;
	TMenuItem *N15;
	TAction *editCopyImageAction;
	TMenuItem *N16;
	TAction *editCopyChartAction;
	TMenuItem *N17;
	TAction *editCopyTableAction;
	TMenuItem *N18;
	TAction *viewBestFitAction;
	TAction *viewActualSizeAction;
	TMenuItem *N19;
	TMenuItem *N20;
	TMenuItem *N21;
	TMenuItem *PRI1;
	TAction *viewPRI3x3Action;
	TMenuItem *PRI3x31;
	TAction *viewPRI5x5Action;
	TMenuItem *viewPRI5x5Action1;
	TMenuItem *N22;
	TMenuItem *view531Action1;
	TMenuItem *view531fAction1;
	TMenuItem *view570Action1;
	TMenuItem *view570fAction1;
	TMenuItem *N23;
	TSpeedButton *SpeedButton6;
	TSpeedButton *SpeedButton7;
	TPhPaneTool *PhPaneTool1;
	TPhZoomToRectTool *PhZoomToRectTool1;
	TMenuItem *N24;
	TMenuItem *N25;
	TAction *viewPaneAction;
	TMenuItem *N26;
	TAction *viewZoomAction;
	TMenuItem *N27;
	TAction *viewEditRoiAction;
	TMenuItem *ROI1;
	TSpeedButton *SpeedButton8;
	TSpeedButton *SpeedButton9;
	TSpeedButton *SpeedButton10;
	TSpeedButton *SpeedButton11;
	TSpeedButton *SpeedButton12;
	TCheckListBox *CheckListBox1;
	TPopupMenu *PopupMenu1;
	TAction *roisDeleteAction;
	TMenuItem *ROI2;
	TMenuItem *N28;
	TMenuItem *ROI3;
	TAction *roisClearAction;
	TButton *Button1;
	TPanel *Panel16;
	TMenuItem *N29;
	TMenuItem *N30;
	TAction *roisCalcAction;
	TMenuItem *N31;
	TMenuItem *N32;
	TGroupBox *GroupBox3;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TSpinEdit *SpinEdit4;
	TSpinEdit *SpinEdit5;
	TSpinEdit *SpinEdit6;
	TChart *Chart1;
	TLineSeries *Series1;
	TSaveDialog *SaveDialog1;
	TSaveDialog *SaveDialog2;
	TLineSeries *Series2;
	TSpeedButton *SpeedButton13;
	TMenuItem *N33;
	TMenuItem *N34;
	TMenuItem *N35;
	TAction *roiViewAverageAction;
	TAction *roiViewStddevAction;
	TMenuItem *N36;
	TMenuItem *N37;
	TMenuItem *N38;
	TMenuItem *N39;
	TMenuItem *N40;
	TGauge *Gauge1;
	TAction *deviceSpatialCalibration;
	TPhImage *PhImage1;
	TPanel *Panel9;
	TPhImage *PhImage2;
	TPhImage *PhImage3;
	TTimer *Timer1;
	TAction *fileExportDataAction;
	TAction *fileExportPRIAction;
	TMenuItem *N41;
	TMenuItem *PRI2;
	TAction *deviceSpatialCalibrationAction;
	TMenuItem *N42;
	TAction *viewBrightnessCalibrationAction;
	TAction *viewSpatialCalibrationAction;
	TMenuItem *N43;
	TMenuItem *N44;
	TMenuItem *N45;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall CloseButtonClick(TObject *Sender);
	void __fastcall fileCloseActionExecute(TObject *Sender);
	void __fastcall deviceCalibrationActionExecute(TObject *Sender);
	void __fastcall deviceCalibrationActionUpdate(TObject *Sender);
	void __fastcall deviceExperimentActionExecute(TObject *Sender);
	void __fastcall deviceExperimentActionUpdate(TObject *Sender);
	void __fastcall toolsOptionsActionExecute(TObject *Sender);
	void __fastcall helpAboutActionExecute(TObject *Sender);
	void __fastcall helpContestsActionExecute(TObject *Sender);
	void __fastcall TabSheet3Show(TObject *Sender);
	void __fastcall ListBox1Click(TObject *Sender);
	void __fastcall ListBox2Click(TObject *Sender);
	void __fastcall viewPRIActionExecute(TObject *Sender);
	void __fastcall viewPRIActionUpdate(TObject *Sender);
	void __fastcall view531ActionExecute(TObject *Sender);
	void __fastcall view531ActionUpdate(TObject *Sender);
	void __fastcall view570ActionExecute(TObject *Sender);
	void __fastcall view570ActionUpdate(TObject *Sender);
	void __fastcall view531fActionExecute(TObject *Sender);
	void __fastcall view531fActionUpdate(TObject *Sender);
	void __fastcall view570fActionExecute(TObject *Sender);
	void __fastcall view570fActionUpdate(TObject *Sender);
	void __fastcall fileExportTableActionExecute(TObject *Sender);
	void __fastcall fileExportTableActionUpdate(TObject *Sender);
	void __fastcall fileExportImageActionExecute(TObject *Sender);
	void __fastcall fileExportImageActionUpdate(TObject *Sender);
	void __fastcall filePrintActionExecute(TObject *Sender);
	void __fastcall filePrintActionUpdate(TObject *Sender);
	void __fastcall editCopyImageActionExecute(TObject *Sender);
	void __fastcall editCopyImageActionUpdate(TObject *Sender);
	void __fastcall editCopyChartActionExecute(TObject *Sender);
	void __fastcall editCopyChartActionUpdate(TObject *Sender);
	void __fastcall editCopyTableActionExecute(TObject *Sender);
	void __fastcall editCopyTableActionUpdate(TObject *Sender);
	void __fastcall viewBestFitActionExecute(TObject *Sender);
	void __fastcall viewBestFitActionUpdate(TObject *Sender);
	void __fastcall viewActualSizeActionUpdate(TObject *Sender);
	void __fastcall viewActualSizeActionExecute(TObject *Sender);
	void __fastcall viewPRI3x3ActionExecute(TObject *Sender);
	void __fastcall viewPRI3x3ActionUpdate(TObject *Sender);
	void __fastcall viewPRI5x5ActionExecute(TObject *Sender);
	void __fastcall viewPRI5x5ActionUpdate(TObject *Sender);
	void __fastcall viewPaneActionExecute(TObject *Sender);
	void __fastcall viewPaneActionUpdate(TObject *Sender);
	void __fastcall viewZoomActionExecute(TObject *Sender);
	void __fastcall viewZoomActionUpdate(TObject *Sender);
	void __fastcall viewEditRoiActionExecute(TObject *Sender);
	void __fastcall viewEditRoiActionUpdate(TObject *Sender);
	void __fastcall CheckListBox1Click(TObject *Sender);
	void __fastcall PhImage4ToolChange(TObject *Sender);
	void __fastcall roisDeleteActionExecute(TObject *Sender);
	void __fastcall roisDeleteActionUpdate(TObject *Sender);
	void __fastcall roisClearActionExecute(TObject *Sender);
	void __fastcall roisClearActionUpdate(TObject *Sender);
	void __fastcall roisCalcActionExecute(TObject *Sender);
	void __fastcall roisCalcActionUpdate(TObject *Sender);
	void __fastcall SpinEdit4Change(TObject *Sender);
	void __fastcall SpinEdit5Change(TObject *Sender);
	void __fastcall SpinEdit6Change(TObject *Sender);
	void __fastcall PhImage4Paint(TObject *Sender);
	void __fastcall PhImage4MouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall roiViewAverageActionExecute(TObject *Sender);
	void __fastcall roiViewAverageActionUpdate(TObject *Sender);
	void __fastcall roiViewStddevActionExecute(TObject *Sender);
	void __fastcall roiViewStddevActionUpdate(TObject *Sender);
	void __fastcall deviceSpatialCalibrationExecute(TObject *Sender);
	void __fastcall deviceSpatialCalibrationUpdate(TObject *Sender);
	void __fastcall CheckBox1Click(TObject *Sender);
	void __fastcall PageControl1Change(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ComboBox1Change(TObject *Sender);
	void __fastcall TrackBar1Change(TObject *Sender);
	void __fastcall PhImage3MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall PhImage2MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall PhImage4ScaleChange(TObject *Sender);
	void __fastcall fileExportDataActionExecute(TObject *Sender);
	void __fastcall fileExportDataActionUpdate(TObject *Sender);
	void __fastcall fileExportPRIActionExecute(TObject *Sender);
	void __fastcall fileExportPRIActionUpdate(TObject *Sender);
	void __fastcall SpeedButton13Click(TObject *Sender);
	void __fastcall deviceSpatialCalibrationActionExecute(TObject *Sender);
	void __fastcall deviceSpatialCalibrationActionUpdate(TObject *Sender);
	void __fastcall viewBrightnessCalibrationActionExecute(TObject *Sender);
	void __fastcall viewBrightnessCalibrationActionUpdate(TObject *Sender);
	void __fastcall viewSpatialCalibrationActionExecute(TObject *Sender);
	void __fastcall viewSpatialCalibrationActionUpdate(TObject *Sender);
	void __fastcall CheckListBox1ClickCheck(TObject *Sender);

private:	// User declarations
	int m_frameNum1;
	int m_frameNum2;


	int m_numCameras;
	int* m_cameras;

	int m_mode;
	TPriInitFile*  m_pInitFile;
	TPriProcessor  m_processor;
	TPhPriRoiEditor* m_roiTool;

	void __fastcall ClearPictures();
	bool __fastcall LoadArchiveEntry();
	void __fastcall RenderImage();
	void __fastcall NormAndSetImage(awpImage* img);
	void __fastcall UpdateImageStatus();
	EPriBlurMode __fastcall GetBlurMode();
	void __fastcall OnAddRoi(TObject *Sender, TPriRoiItem* item);
	void __fastcall Calculation();
	awpImage* __fastcall GetVisibleImage();
	void __fastcall UpdateChart();
	void __fastcall ClearTable();


	void   __fastcall SwitchLightOn();
	void   __fastcall SwitchLightOff();
	double __fastcall ExploshureTime(int index, int pos);

	void  __fastcall ReadArchive();
	TPriProcessor* __fastcall GetProcessor();
public:		// User declarations
	__fastcall TMainForm(TComponent* Owner);

	void __fastcall SetFrame(int width, int height, unsigned char* data, int cameraID);
	void __fastcall PreviewFrame(int width, int height, unsigned char* data, int cameraID);
	void __fastcall ProcessData(bool saveArchive = true);
	void __fastcall SaveData();
	void   __fastcall NormAndSetPri();
	void __fastcall UpdateCheckList();

	void   __fastcall TakePicture();

	void __fastcall StartVideoEngine();
	void __fastcall StopVideoEngine();
	awpImage* m_image1;
	awpImage* m_image2;

    awpImage* m_image11;
	awpImage* m_image22;

	awpImage* m_pri;   // результат измерения

	TPRIArchive    m_arcive;
	int m_viewCamera;
    int m_seriesCounter;
	__property int CameraMode = {read = m_mode};
	__property TPriInitFile* iniFile = {read = m_pInitFile};
	__property TPriProcessor* processor = {read = GetProcessor};

	__property awpImage* image1 = {read = m_image1};
	__property awpImage* image11 = {read = m_image11};
	__property awpImage* image2 = {read = m_image2};
	__property awpImage* image22 = {read = m_image22};
	__property awpImage* pri = {read = m_pri};
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
