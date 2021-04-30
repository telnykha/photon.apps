//---------------------------------------------------------------------------

#ifndef MainUnitH
#define MainUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <System.Actions.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.StdActns.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.AppEvnts.hpp>
#include <Vcl.FileCtrl.hpp>
#include "FImage41.h"
#include <Vcl.Buttons.hpp>
#include "cammandsTable.h"
#include <Vcl.Dialogs.hpp>
#include "IniFileUnit.h"
#include "PAMArchive.h"
#include "PhImageTool.h"
#include "PhPaneTool.h"
#include "PhRulerTool.h"
#include <Vcl.Samples.Spin.hpp>
#include "diff_table.h"
#include "PhSelectRectTool.h"
#include "PhZoomToRectTool.h"
#include <Vcl.CheckLst.hpp>
#include <VCLTee.Chart.hpp>
#include <VclTee.TeeGDIPlus.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
#include <Vcl.ActnCtrls.hpp>
#include <Vcl.ActnMan.hpp>
#include <Vcl.ToolWin.hpp>

//---------------------------------------------------------------------------
class TmainPAM : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TMenuItem *N1;
	TMenuItem *N2;
	TPanel *Panel1;
	TStatusBar *StatusBar1;
	TActionList *ActionList1;
	TFileExit *FileExit1;
	TMemo *Memo2;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TStringGrid *StringGrid1;
	TMemo *Memo1;
	TApplicationEvents *ApplicationEvents1;
	TTabSheet *TabSheet3;
	TTabSheet *Архив;
	TPanel *Panel2;
	TDirectoryListBox *DirectoryListBox1;
	TSplitter *Splitter1;
	TFileListBox *FileListBox1;
	TDriveComboBox *DriveComboBox1;
	TAction *fileNewAction;
	TAction *fileOpenAction;
	TAction *fileSaveAction;
	TAction *fileSaveAsAction;
	TPhImage *PhImage1;
	TMenuItem *N3;
	TMenuItem *N4;
	TMenuItem *N5;
	TMenuItem *N6;
	TMenuItem *N7;
	TAction *deviceCheckAction;
	TAction *device460nmAction;
	TAction *device660nmAction;
	TAction *deviceVideocamAction;
	TAction *deviceExperimentAction;
	TMenuItem *N8;
	TMenuItem *N9;
	TMenuItem *N10;
	TMenuItem *N460nm1;
	TMenuItem *N660nm1;
	TMenuItem *N11;
	TMenuItem *N12;
	TMenuItem *deviceExperimentAction1;
	TAction *toolsOptionsAction;
	TMenuItem *N13;
	TMenuItem *N14;
	TSpeedButton *SpeedButton1;
	TSpeedButton *SpeedButton2;
	TSpeedButton *SpeedButton3;
	TSpeedButton *SpeedButton4;
	TSpeedButton *SpeedButton5;
	TSpeedButton *SpeedButton6;
	TSpeedButton *SpeedButton7;
	TSpeedButton *SpeedButton8;
	TSpeedButton *SpeedButton9;
	TAction *helpAboutAction;
	TAction *helpContextAction;
	TMenuItem *N15;
	TMenuItem *N16;
	TMenuItem *N17;
	TPanel *Panel3;
	TPanel *Panel4;
	TSpeedButton *SpeedButton10;
	TSpeedButton *SpeedButton11;
	TSpeedButton *SpeedButton12;
	TAction *editInsertAction;
	TAction *editDeleteAction;
	TAction *editEditAction;
	TMenuItem *N18;
	TMenuItem *N19;
	TMenuItem *N20;
	TMenuItem *N21;
	TPopupMenu *PopupMenu1;
	TMenuItem *N22;
	TMenuItem *N23;
	TMenuItem *N24;
	TOpenDialog *OpenDialog1;
	TSaveDialog *SaveDialog1;
	TButton *Button1;
	TPanel *Panel5;
	TPhImage *PhImage2;
	TSplitter *Splitter2;
	TPhPaneTool *PhPaneTool1;
	TSplitter *Splitter3;
	TSplitter *Splitter4;
	TPanel *Panel6;
	TGroupBox *GroupBox3;
	TTrackBar *TrackBar3;
	TGroupBox *GroupBox4;
	TGroupBox *GroupBox2;
	TTrackBar *TrackBar2;
	TLabel *Label1;
	TLabel *Label2;
	TGroupBox *GroupBox1;
	TTrackBar *TrackBar1;
	TComboBox *ComboBox1;
	TGroupBox *GroupBox5;
	TTrackBar *TrackBar5;
	TLabel *Label3;
	TGroupBox *GroupBox6;
	TSpinEdit *SpinEdit2;
	TSpinEdit *SpinEdit1;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TPanel *Panel7;
	TStringGrid *StringGrid2;
	TPanel *Panel8;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label12;
	TLabel *Label13;
	TLabel *Label14;
	TLabel *Label15;
	TLabel *Label16;
	TLabel *Label17;
	TLabel *Label18;
	TLabel *Label19;
	TButton *Button2;
	TAction *editAddAction;
	TMenuItem *N25;
	TMenuItem *N26;
	TAction *editUpAction;
	TAction *editDownAction;
	TMenuItem *N27;
	TMenuItem *N28;
	TMenuItem *N29;
	TAction *editCopyAction;
	TAction *editPasteAction;
	TMenuItem *N30;
	TMenuItem *N31;
	TMenuItem *N32;
	TMenuItem *N33;
	TMenuItem *N34;
	TMenuItem *N35;
	TMenuItem *N36;
	TAction *AddDiffComm;
	TMenuItem *N37;
	TTabSheet *Сложные_команды;
	TPhImage *PhImage3;
	TPageControl *PageControl2;
	TTabSheet *График;
	TTabSheet *Таблица;
	TCheckListBox *CheckListBox1;
	TPhZoomToRectTool *PhZoomToRectTool1;
	TPopupMenu *PopupPhDiffCom;
	TMenuItem *zoomtoRect1;
	TAction *ZoomToRect;
	TPhSelRectTool *PhSelRectTool1;
	TMenuItem *ModeSelectRect1;
	TAction *SelectRect;
	TSpeedButton *Рассчитать;
	TSplitter *Splitter5;
	TPanel *Panel9;
	TPanel *Panel10;
	TStringGrid *StringGrid3;
	TLabel *Label21;
	TLabel *Label22;
	TLabel *Label23;
	TMenuItem *Copy1;
	TAction *CopyAction;
	TAction *PastAction;
	TMenuItem *PastAction1;
	TAction *ZoomToActualSize;
	TMenuItem *Z1;
	TPanel *Panel12;
	TSplitter *Splitter6;
	TStringGrid *StringGrid4;
	TChart *Chart1;
	TSplitter *Splitter8;
	TComboBox *ComboBox2;
	TStringGrid *StringGrid5;
	TLabel *Label24;
	TSplitter *Splitter7;
	TPanel *Panel13;
	TSpeedButton *SpeedButton13;
	TSpeedButton *SpeedButton14;
	TSpeedButton *SpeedButton15;
	TSpeedButton *SpeedButton16;
	TSpeedButton *SpeedButton17;
	TSpeedButton *SpeedButton18;
	TSpeedButton *SpeedButton19;
	TAction *ZoomToBestFit;
	TMenuItem *ZoomToActualSize1;
	TAction *ViewPanAction;
	TAction *ViewZoom;
	TPanel *RightDocPanel;
	TPanel *LeftDocPanel;
	TMenuItem *N38;
	TMenuItem *N39;
	TMenuItem *N40;
	TAction *ShowMightex;
	TAction *ShowPanelResult;
	TAction *ShowPanelParametrs;
	TSpeedButton *SpeedButton20;
	void __fastcall N2Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall ApplicationEvents1Idle(TObject *Sender, bool &Done);
	void __fastcall fileNewActionExecute(TObject *Sender);
	void __fastcall fileOpenActionExecute(TObject *Sender);
	void __fastcall fileOpenActionUpdate(TObject *Sender);
	void __fastcall fileSaveActionExecute(TObject *Sender);
	void __fastcall fileSaveActionUpdate(TObject *Sender);
	void __fastcall fileSaveAsActionExecute(TObject *Sender);
	void __fastcall fileSaveAsActionUpdate(TObject *Sender);
	void __fastcall deviceCheckActionExecute(TObject *Sender);
	void __fastcall deviceCheckActionUpdate(TObject *Sender);
	void __fastcall device460nmActionExecute(TObject *Sender);
	void __fastcall device460nmActionUpdate(TObject *Sender);
	void __fastcall device660nmActionExecute(TObject *Sender);
	void __fastcall device660nmActionUpdate(TObject *Sender);
	void __fastcall deviceVideocamActionExecute(TObject *Sender);
	void __fastcall deviceVideocamActionUpdate(TObject *Sender);
	void __fastcall deviceExperimentActionExecute(TObject *Sender);
	void __fastcall deviceExperimentActionUpdate(TObject *Sender);
	void __fastcall toolsOptionsActionExecute(TObject *Sender);
	void __fastcall toolsOptionsActionUpdate(TObject *Sender);
	void __fastcall helpAboutActionExecute(TObject *Sender);
	void __fastcall helpContextActionExecute(TObject *Sender);
	void __fastcall editInsertActionExecute(TObject *Sender);
	void __fastcall editInsertActionUpdate(TObject *Sender);
	void __fastcall editDeleteActionExecute(TObject *Sender);
	void __fastcall editDeleteActionUpdate(TObject *Sender);
	void __fastcall editEditActionExecute(TObject *Sender);
	void __fastcall editEditActionUpdate(TObject *Sender);
	void __fastcall StringGrid1DblClick(TObject *Sender);
	void __fastcall PageControl1Change(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ComboBox1Change(TObject *Sender);
	void __fastcall TrackBar2Change(TObject *Sender);
	void __fastcall FileListBox1Change(TObject *Sender);
	void __fastcall ApplicationEvents1Hint(TObject *Sender);
	void __fastcall DirectoryListBox1Change(TObject *Sender);
	void __fastcall TrackBar3Change(TObject *Sender);
	void __fastcall TrackBar1Change(TObject *Sender);
	void __fastcall TabSheet3Show(TObject *Sender);
	void __fastcall StringGrid2Click(TObject *Sender);
	void __fastcall TrackBar5Change(TObject *Sender);
	void __fastcall SpinEdit2Change(TObject *Sender);
	void __fastcall SpinEdit1Change(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall editAddActionExecute(TObject *Sender);
	void __fastcall editAddActionUpdate(TObject *Sender);
	void __fastcall editUpActionExecute(TObject *Sender);
	void __fastcall editUpActionUpdate(TObject *Sender);
	void __fastcall editDownActionUpdate(TObject *Sender);
	void __fastcall editDownActionExecute(TObject *Sender);
	void __fastcall editCopyActionExecute(TObject *Sender);
	void __fastcall editCopyActionUpdate(TObject *Sender);
	void __fastcall editPasteActionUpdate(TObject *Sender);
	void __fastcall editPasteActionExecute(TObject *Sender);
	void __fastcall AddDiffCommExecute(TObject *Sender);
	void __fastcall ZoomToRectExecute(TObject *Sender);
	void __fastcall ZoomToRectUpdate(TObject *Sender);
	void __fastcall SelectRectExecute(TObject *Sender);
	void __fastcall SelectRectUpdate(TObject *Sender);
	void __fastcall CopyActionExecute(TObject *Sender);
	void __fastcall CopyActionUpdate(TObject *Sender);
	void __fastcall PastActionExecute(TObject *Sender);
	void __fastcall PastActionUpdate(TObject *Sender);
	void __fastcall ZoomToActualSizeExecute(TObject *Sender);
	void __fastcall ZoomToActualSizeUpdate(TObject *Sender);
	void __fastcall ZoomToBestFitExecute(TObject *Sender);
	void __fastcall ZoomToBestFitUpdate(TObject *Sender);
	void __fastcall ViewPanActionExecute(TObject *Sender);
	void __fastcall ViewPanActionUpdate(TObject *Sender);
	void __fastcall ViewZoomExecute(TObject *Sender);
	void __fastcall ViewZoomUpdate(TObject *Sender);
	void __fastcall RightDocPanelDockDrop(TObject *Sender, TDragDockObject *Source,
          int X, int Y);
	void __fastcall RightDocPanelUnDock(TObject *Sender, TControl *Client, TWinControl *NewTarget,
          bool &Allow);
	void __fastcall RightDocPanelDockOver(TObject *Sender, TDragDockObject *Source,
          int X, int Y, TDragState State, bool &Accept);
	void __fastcall LeftDocPanelDockDrop(TObject *Sender, TDragDockObject *Source, int X,
          int Y);
	void __fastcall LeftDocPanelDockOver(TObject *Sender, TDragDockObject *Source, int X,
          int Y, TDragState State, bool &Accept);
	void __fastcall LeftDocPanelUnDock(TObject *Sender, TControl *Client, TWinControl *NewTarget,
          bool &Allow);
	void __fastcall ShowMightexExecute(TObject *Sender);
	void __fastcall ShowMightexUpdate(TObject *Sender);
	void __fastcall ShowPanelResultExecute(TObject *Sender);
	void __fastcall ShowPanelResultUpdate(TObject *Sender);
	void __fastcall ShowPanelParametrsExecute(TObject *Sender);
	void __fastcall ShowPanelParametrsUpdate(TObject *Sender);
	void __fastcall SpeedButton20Click(TObject *Sender);







private:	// User declarations
	int    			m_board;
	TCommandsTable* m_table; // таблица в окне для редактирования
    int             m_camera;
    int				m_numCameras;
	int 			m_mode;
	TPAMOptions 	m_options;
	UnicodeString   m_currentArchive;
    TPAMArchive*    m_archive;
	TCommandsTable* m_tableArchive; // таблица архива

	UINT            m_clipFormat;

    void   __fastcall AskSaveTable();
    void   __fastcall StartExperiment();
    void   __fastcall BoardDetected(TAction* action);
    void   __fastcall CheckArduino();
    void   __fastcall StartVideo();
    void   __fastcall StopVideo();
	double __fastcall ExploshureTime(int index, int pos);
	void   __fastcall OpenArchivePage(UnicodeString path);

	UnicodeString __fastcall GetSketchPath();
	void   __fastcall CheckSketch();

public:		// User declarations
	__fastcall TmainPAM(TComponent* Owner);
    void __fastcall SetFrame(int width, int height, unsigned char* data, int cameraID);
    void __fastcall PreviewFrame(int width, int height, unsigned char* data, int cameraID);
    bool __fastcall StartProcess();
    void __fastcall FinishProcess();
	void __fastcall CancelProcess();

	void ShowLeftDockPanel(TWinControl* APanel, bool MakeVisible, TControl* Client);

	__property int CameraMode 		 = {read = m_mode};
    __property int board 			 = {read = m_board};
	__property TCommandsTable* table = {read = m_table};
	__property UINT clipFormat = {read = m_clipFormat};
};
//---------------------------------------------------------------------------
extern PACKAGE TmainPAM *mainPAM;
//---------------------------------------------------------------------------
#endif
