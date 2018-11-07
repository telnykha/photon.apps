//---------------------------------------------------------------------------

#ifndef MainUnitH
#define MainUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <System.Actions.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include "FImage.h"
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.Dialogs.hpp>
#include "ModelUnit.h"
#include <Vcl.DBCtrls.hpp>
#include <Vcl.Samples.Spin.hpp>

const UnicodeString c_strConnectionDb = L"Provider=Microsoft.Jet.OLEDB.4.0;User ID=Admin;Mode=Share Deny None;Jet OLEDB:System database="";Jet OLEDB:Registry Path="";Jet OLEDB:Database Password="";Jet OLEDB:Engine Type=5;Jet OLEDB:Database Locking Mode=1;Jet OLEDB:Global Partial Bulk Ops=2;Jet OLEDB:Global Bulk Transactions=1;Jet OLEDB:New Database Password="";Jet OLEDB:Create System Database=False;Jet OLEDB:Encrypt Database=False;Jet OLEDB:Don't Copy Locale on Compact=False;Jet OLEDB:Compact Without Replica Repair=False;Jet OLEDB:SFP=False;Data Source=";
const UnicodeString c_strSourceDb = L"source.mdb";
const UnicodeString c_strIniFile  = "\\PsyGraph.xml";
const UnicodeString c_strDbFilter = L"Базы данных MS Access (*.mdb)|*.mdb";
const UnicodeString c_strImageFilter = L"Изображения (*.jpg;*.png)|*.jpg;*.png";
const UnicodeString c_strHelpUrl = L"http://telnykha.wixsite.com/psygraph";
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TStatusBar *StatusBar1;
	TActionList *ActionList1;
	TMainMenu *MainMenu1;
	TAction *fileOpenAction;
	TAction *fileExitAction;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *N3;
	TMenuItem *N4;
	TPanel *Panel1;
	TSplitter *Splitter1;
	TPanel *Panel2;
	TPanel *Panel3;
	TGroupBox *GroupBox1;
	TAction *dbInsertAction;
	TDBGrid *DBGrid1;
	TPanel *Panel5;
	TPanel *Panel6;
	TFImage *FImage1;
	TAction *dbCreateAction;
	TAction *dbOpenAction;
	TAction *dbCloseAction;
	TMenuItem *dbCreateAction1;
	TMenuItem *N6;
	TMenuItem *N7;
	TAction *viewLifeLineAction;
	TAction *viewFrameAction;
	TMenuItem *N8;
	TMenuItem *N9;
	TMenuItem *N10;
	TAction *modelCreateAction;
	TAction *modelEditAction;
	TAction *modelDeleteAction;
	TAction *modelSaveAction;
	TMenuItem *N11;
	TMenuItem *N12;
	TMenuItem *N13;
	TMenuItem *N14;
	TMenuItem *N15;
	TAction *toolsOptionsAction;
	TMenuItem *N16;
	TMenuItem *N17;
	TAction *helpAboutAction;
	TAction *helpContentsAction;
	TMenuItem *N18;
	TMenuItem *N19;
	TMenuItem *N20;
	TOpenDialog *OpenDialog1;
	TMenuItem *N21;
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
	TLabel *Label11;
	TLabel *Label12;
	TLabel *Label13;
	TLabel *Label14;
	TLabel *Label15;
	TLabel *Label16;
	TComboBox *ComboBoxGender;
	TComboBox *ComboBoxAge;
	TComboBox *ComboBoxWorkType;
	TComboBox *ComboBoxPsyTestType;
	TButton *Button2;
	TAction *DbExportAction;
	TMenuItem *Excel1;
	TMenuItem *N23;
	TMenuItem *N24;
	TGroupBox *GroupBox2;
	TLabel *Label17;
	TLabel *Label18;
	TLabel *Label19;
	TLabel *Label20;
	TLabel *Label21;
	TLabel *Label22;
	TLabel *Label23;
	TDBText *DBText1;
	TDBText *DBText2;
	TDBText *DBText3;
	TDBText *DBText4;
	TDBText *DBText5;
	TDBText *DBText6;
	TDBText *DBText7;
	TButton *Button1;
	TButton *Button3;
	TButton *Button4;
	TAction *dbAddUserAction;
	TMenuItem *N26;
	TAction *dbSelectAction;
	TAction *viewCoordsAction;
	TMenuItem *N27;
	TPanel *Panel4;
	TPanel *Panel7;
	TLabel *Label24;
	TPanel *Panel8;
	TLabel *Label25;
	TPanel *Panel9;
	TLabel *Label26;
	TPanel *Panel10;
	TGroupBox *GroupBox3;
	TPanel *Panel11;
	TGroupBox *GroupBox4;
	TAction *dbEditUserAction;
	TMenuItem *N5;
	TLabel *Label27;
	TLabel *Label28;
	TLabel *Label29;
	TLabel *Label30;
	TLabel *Label31;
	TLabel *Label32;
	TLabel *Label33;
	TLabel *Label34;
	TComboBox *ComboBoxNames;
	TButton *Button5;
	TLabel *Label35;
	TSpinEdit *SpinEdit1;
	TSpinEdit *SpinEdit2;
	TLabel *Label36;
	TLabel *Label37;
	void __fastcall fileExitActionExecute(TObject *Sender);
	void __fastcall helpAboutActionExecute(TObject *Sender);
	void __fastcall dbCreateActionExecute(TObject *Sender);
	void __fastcall dbOpenActionExecute(TObject *Sender);
	void __fastcall dbCloseActionExecute(TObject *Sender);
	void __fastcall dbCloseActionUpdate(TObject *Sender);
	void __fastcall fileOpenActionExecute(TObject *Sender);
	void __fastcall fileOpenActionUpdate(TObject *Sender);
	void __fastcall FImage1AfterOpen(TObject *Sender);
	void __fastcall FImage1Resize(TObject *Sender);
	void __fastcall helpContentsActionExecute(TObject *Sender);
	void __fastcall toolsOptionsActionExecute(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall dbInsertActionExecute(TObject *Sender);
	void __fastcall dbInsertActionUpdate(TObject *Sender);
	void __fastcall FImage1Change(TObject *Sender);
	void __fastcall FImage1MouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall DbExportActionExecute(TObject *Sender);
	void __fastcall DbExportActionUpdate(TObject *Sender);
	void __fastcall dbAddUserActionExecute(TObject *Sender);
	void __fastcall dbAddUserActionUpdate(TObject *Sender);
	void __fastcall dbSelectActionExecute(TObject *Sender);
	void __fastcall dbSelectActionUpdate(TObject *Sender);
	void __fastcall viewLifeLineActionExecute(TObject *Sender);
	void __fastcall viewLifeLineActionUpdate(TObject *Sender);
	void __fastcall viewFrameActionExecute(TObject *Sender);
	void __fastcall viewFrameActionUpdate(TObject *Sender);
	void __fastcall viewCoordsActionExecute(TObject *Sender);
	void __fastcall viewCoordsActionUpdate(TObject *Sender);
	void __fastcall dbCreateActionUpdate(TObject *Sender);
	void __fastcall dbOpenActionUpdate(TObject *Sender);
	void __fastcall dbEditUserActionExecute(TObject *Sender);
	void __fastcall dbEditUserActionUpdate(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall ComboBoxNamesChange(TObject *Sender);
	void __fastcall SpinEdit2Change(TObject *Sender);
	void __fastcall SpinEdit1Change(TObject *Sender);

private:	// User declarations
    // database support
	void __fastcall DoCreateDatabase(UnicodeString path);
    void __fastcall DoOpenDatabase(UnicodeString strFileName);
    void __fastcall DoCloseDatabase();
    // ini file support
    int m_width;
    int m_height;
    bool m_open;
    int  m_threshold;
    UnicodeString m_strDatabase;
    bool m_new_measuare;
    bool __fastcall LoadIniFile();
    bool __fastcall SaveIniFile();

    // model support
    TPsyGraphModel* __fastcall GetModel();
    UnicodeString __fastcall GetPathToImages();
    bool __fastcall NeedWhere();
    void __fastcall DisplayHint(TObject *Sender);
    void __fastcall IdleHandler(TObject *Sender, bool& done);
public:		// User declarations
	__fastcall TMainForm(TComponent* Owner);
    void __fastcall NewMeasureHelper();



    __property TPsyGraphModel* Model = {read = GetModel};
    __property UnicodeString PathToImages = {read = GetPathToImages};
    __property int ModelWidth = {read = m_width};
    __property int ModelHeight = {read = m_height};
    __property bool NewMeasure = {read = m_new_measuare};
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
