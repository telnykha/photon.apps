//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainUnit.h"
#include "AboutUnit.h"
#include "VerInfoUnit.h"
#include "optionsUnit.h"
#include "_LF.h"
#include "DataModuleUnit.h"
#include "additemUnit.h"
#include "addUserUnit.h"
#include "StartUnit.h"
#include <OleServer.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
extern "C"
{
	#pragma link "awpipl2b.lib"
	#pragma link "JPEGLIB.lib"
}
#pragma link "TinyXML.lib"
#pragma link "awplflibb.lib"
#pragma link "FImage"
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
    m_width = 80;
    m_height = 150;
    m_open = false;
    m_strDatabase = L"";
    m_threshold = 50;
    m_new_measuare = false;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::fileExitActionExecute(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::helpAboutActionExecute(TObject *Sender)
{
    TVersionInfo* vi = new TVersionInfo(NULL);
    AboutBox->ProductName->Caption = vi->ProductName;
    AboutBox->Version->Caption = vi->FileVersion;
    AboutBox->Copyright->Caption = vi->LegalCopyright;
	AboutBox->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::dbCreateActionExecute(TObject *Sender)
{
 	NewMeasureHelper();
    OpenDialog1->Filter = c_strDbFilter;
	if (OpenDialog1->Execute())
    {
    	this->DoCreateDatabase(OpenDialog1->FileName);
    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DoCreateDatabase(UnicodeString path)
{
   UnicodeString path1 = ChangeFileExt(path, ".mdb");
   if (FileExists(path1))
   {
   		ShowMessage(L"Невозможно создать базу данных: " + path1 + L" База данных с таким именем уже существует.");
        return;
   }

   UnicodeString strSourceFile = ExtractFilePath(Application->ExeName);
   strSourceFile += L"\\";
   strSourceFile += c_strSourceDb;

   UnicodeString strDir = ExtractFilePath(path1);
   strDir += L"\\";
   strDir += ExtractFileName(path1);
   strDir = ChangeFileExt(strDir, L"");

   try
   {
      if (!CopyFile(strSourceFile.c_str(), path1.c_str(), true) || !CreateDir(strDir) )
      {
	     DeleteFile(path1);
       	 throw new Exception("Невозможно создать базу данных.");
      }
   }
   catch(Exception& e)
   {
   	 ShowMessage(e.Message);
   }

   this->DoOpenDatabase(path1);
}
void __fastcall TMainForm::dbOpenActionExecute(TObject *Sender)
{
    NewMeasureHelper();
    OpenDialog1->Filter = c_strDbFilter;
	if (OpenDialog1->Execute())
    {
    	this->DoOpenDatabase(OpenDialog1->FileName);
    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DoOpenDatabase(UnicodeString strFileName)
{
    this->DoCloseDatabase();
	UnicodeString strConnection = c_strConnectionDb;
    strConnection += strFileName;
    strConnection += L";";
    DataModule1->ADOConnection1->ConnectionString = strConnection;
    try
    {
    DataModule1->ADOConnection1->Connected = true;
    if (DataModule1->ADOConnection1->Connected)
    {
    	DataModule1->ADOTable1->Active = true;
    	DataModule1->ADOTable2->Active = true;
    	DataModule1->ADOTable3->Active = true;
        DataModule1->ADOTable4->Active = true;
        DataModule1->ADOTable5->Active = true;
        DataModule1->ADOTable6->Active = true;
    }
    }
    catch(Exception& e)
    {
        DataModule1->ADOConnection1->Connected = false;
    	ShowMessage(e.Message);

    }
    this->m_strDatabase = strFileName;
    this->SaveIniFile();
    MainForm->Caption = L"PsyGraph 2.0 [" + strFileName + L"]";
}
void __fastcall TMainForm::dbCloseActionExecute(TObject *Sender)
{
        NewMeasureHelper();
        this->DoCloseDatabase();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::dbCloseActionUpdate(TObject *Sender)
{
	dbCloseAction->Enabled = DataModule1->ADOConnection1->Connected && DataModule1->ADOTable1->Active && !this->NewMeasure;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DoCloseDatabase()
{
	DataModule1->ADOTable1->Active = false;
    DataModule1->ADOTable2->Active = false;
    DataModule1->ADOTable3->Active = false;
    DataModule1->ADOTable4->Active = false;
    DataModule1->ADOTable5->Active = false;
    DataModule1->ADOTable6->Active = false;

    DataModule1->ADOConnection1->Connected = false;
    MainForm->Caption = L"PsyGraph 2.0";
    FImage1->Close();
    FImage1->Paint();
}
void __fastcall TMainForm::fileOpenActionExecute(TObject *Sender)
{
    NewMeasureHelper();
	OpenDialog1->Filter = c_strImageFilter;
    if (OpenDialog1->Execute())
    {
       	m_new_measuare = true;
    	FImage1->Init(OpenDialog1->FileName, NULL);
    }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::fileOpenActionUpdate(TObject *Sender)
{
	fileOpenAction->Enabled =  DataModule1->ADOConnection1->Connected && DataModule1->ADOTable1->Active && !this->NewMeasure;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FImage1AfterOpen(TObject *Sender)
{
	FImage1->BestFit();
    if (this->m_new_measuare)
    {
        TPsyGraphTool* tool = dynamic_cast< TPsyGraphTool*>(FImage1->Tool);
        if (tool != NULL)
        {
             double t = (double)this->m_threshold / 100.;
             tool->Process(t);
             {
               	this->Label12->Caption = FormatFloat("###", Model->Alfa);
				this->Label11->Caption = FormatFloat("###", Model->X);
				this->Label10->Caption = FormatFloat("###", Model->Y);
				this->Label9->Caption = FormatFloat("###", Model->J0);
				this->Label8->Caption = FormatFloat("###", Model->Jn);
				this->Label7->Caption = Model->Quadrant;
                this->Label30->Caption = IntToStr(Model->Score);
                this->Label31->Caption = IntToStr(Model->Level);
				this->Label32->Caption = Model->Comment;
			    this->Label33->Caption = Model->Comment2;
             }
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FImage1Resize(TObject *Sender)
{
	FImage1->BestFit();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::helpContentsActionExecute(TObject *Sender)
{
	ShellExecute(Handle, L"open", c_strHelpUrl.c_str(), NULL, NULL, SW_SHOW);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::toolsOptionsActionExecute(TObject *Sender)
{
    OptionsDlg->CheckBox1->Checked = this->m_open;
    OptionsDlg->SpinEdit1->Value = this->m_width;
    OptionsDlg->SpinEdit2->Value = this->m_height;
    OptionsDlg->TrackBar1->Position = this->m_threshold;
	if (OptionsDlg->ShowModal() == mrOk)
    {
    	// save options
        this->m_open = OptionsDlg->CheckBox1->Checked;
        this->m_width = OptionsDlg->SpinEdit1->Value;
        this->m_height = OptionsDlg->SpinEdit2->Value;
        this->m_threshold = OptionsDlg->TrackBar1->Position;
        SaveIniFile();
    }
}
//---------------------------------------------------------------------------
bool __fastcall TMainForm::LoadIniFile()
{
	TiXmlDocument doc;
    UnicodeString strIniFile = ExtractFilePath(Application->ExeName) + L"\\" + c_strIniFile;
    AnsiString _ansi = strIniFile;
	if (!doc.LoadFile(_ansi.c_str()))
		return false;
	TiXmlHandle hDoc(&doc);
	TiXmlElement* pElem = NULL;
	pElem = hDoc.FirstChildElement().Element();
	if (!pElem)
		return false;
   const char* name = pElem->Value();
   if (strcmp(name, "psygraph") != 0)
		return false;
   pElem->QueryIntAttribute("width", &this->m_width);
   pElem->QueryIntAttribute("height", &this->m_height);
   int value = 0;
   pElem->QueryIntAttribute("open", &value);
   this->m_open = value != 0;
   pElem->QueryIntAttribute("threshold", &this->m_threshold);
   this->m_strDatabase = pElem->Attribute("in_database");

   return true;
}
bool __fastcall TMainForm::SaveIniFile()
{
 	TiXmlDocument doc;
    UnicodeString strIniFile = ExtractFilePath(Application->ExeName) + L"\\" + c_strIniFile;
    AnsiString _ansi = strIniFile;
	if (!doc.LoadFile(_ansi.c_str()))
		return false;
	TiXmlHandle hDoc(&doc);
	TiXmlElement* pElem = NULL;
	pElem = hDoc.FirstChildElement().Element();
	if (!pElem)
		return false;
   const char* name = pElem->Value();
   if (strcmp(name, "psygraph") != 0)
		return false;

  _ansi = this->m_strDatabase;
   pElem->SetAttribute("in_database", _ansi.c_str());
   pElem->SetAttribute("width", this->m_width);
   pElem->SetAttribute("height", this->m_height);
   pElem->SetAttribute("open", this->m_open?1:0);
   pElem->SetAttribute("threshold", this->m_threshold);


   return doc.SaveFile();
}
void __fastcall TMainForm::FormCreate(TObject *Sender)
{
	 Application->OnHint = DisplayHint;
     Application->OnIdle = IdleHandler;
     if (!LoadIniFile())
     {
     	ShowMessage("Не могу загрузить файл конфигурации.");
        Application->Terminate();
     }

     if (this->m_open)
     	this->DoOpenDatabase(this->m_strDatabase);
	this->FImage1->CurrentTool = ftPsyGraph;
    this->SpinEdit2->Value = this->m_width;
    this->SpinEdit1->Value = this->m_height;

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::dbInsertActionExecute(TObject *Sender)
{
	if (AddItemDialog->ShowModal() == mrOk)
    {
    	DataModule1->ADOTable1->Active = false;
    	DataModule1->ADOTable1->Active = true;
        DataModule1->UpdateNamesCombo();
    }
    m_new_measuare = false;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::dbInsertActionUpdate(TObject *Sender)
{
	dbInsertAction->Enabled =  this->NewMeasure;
}
//---------------------------------------------------------------------------
TPsyGraphModel* __fastcall TMainForm::GetModel()
{
    if (FImage1 == NULL)
    {
    	return NULL;
    }
    TPsyGraphTool* tool = dynamic_cast< TPsyGraphTool*>(FImage1->Tool);
    if (tool != NULL)
    {
         return tool->Model;
    }
    else
    	return NULL;
}

UnicodeString __fastcall TMainForm::GetPathToImages()
{
	if (DataModule1->ADOConnection1->Connected)
    {
        UnicodeString s = m_strDatabase;
        UnicodeString strPath = ExtractFilePath(m_strDatabase);
        s = ChangeFileExt(ExtractFileName(s), L"");
		strPath += L"\\";
        strPath += s;
        return strPath;
    }
    else
    	return L"";
}

void __fastcall TMainForm::NewMeasureHelper()
{
    if (!m_new_measuare)
    	return;


    if (Application->MessageBox(L"Есть новое измерение. Сохранить его в базе данных?", L"Сохрение измерения", MB_YESNO ) == IDYES)
    {
        m_new_measuare = false;
        if (AddItemDialog->ShowModal() == mrOk)
        {

            DataModule1->ADOTable1->Active = false;
            DataModule1->ADOTable1->Active = true;
        }
    }
    m_new_measuare = false;
}

void __fastcall TMainForm::FImage1Change(TObject *Sender)
{
 		if (this->NewMeasure)
        	return;

		int Id = DataModule1->ADOTable1->FieldByName("PsyTestId")->Value;
        TLocateOptions SearchOptions;
        SearchOptions.Clear();
        SearchOptions << loPartialKey;
        if (DataModule1->ADOTable5->Locate("PsyTestId", Id, SearchOptions))
        {
            DataModule1->ADOTable5->Edit();

            TPsyGraphModel* m = MainForm->Model;
            DataModule1->ADOTable5->FieldByName("left_top_x")->Value = m->LeftTop.X;
            DataModule1->ADOTable5->FieldByName("left_top_y")->Value = m->LeftTop.Y;
            DataModule1->ADOTable5->FieldByName("right_top_x")->Value = m->RightTop.X;
            DataModule1->ADOTable5->FieldByName("right_top_y")->Value = m->RightTop.Y;
            DataModule1->ADOTable5->FieldByName("right_bottom_x")->Value = m->RightBottom.X;
            DataModule1->ADOTable5->FieldByName("right_bottom_y")->Value = m->RightBottom.Y;
            DataModule1->ADOTable5->FieldByName("left_bottom_x")->Value = m->LeftBottom.X;
            DataModule1->ADOTable5->FieldByName("left_bottom_y")->Value = m->LeftBottom.Y;
            DataModule1->ADOTable5->FieldByName("point1_x")->Value = m->Start.X;
            DataModule1->ADOTable5->FieldByName("point1_y")->Value = m->Start.Y;
            DataModule1->ADOTable5->FieldByName("point2_x")->Value = m->Middle.X;
            DataModule1->ADOTable5->FieldByName("point2_y")->Value = m->Middle.Y;
            DataModule1->ADOTable5->FieldByName("point3_x")->Value = m->End.X;
            DataModule1->ADOTable5->FieldByName("point3_y")->Value = m->End.Y;

            DataModule1->ADOTable5->Post();
            DataModule1->ADOTable1->DisableControls();
            DataModule1->ADOTable1->Active = false;
            DataModule1->ADOTable1->Active = true;
            DataModule1->ADOTable1->Locate("PsyTestId", Id, SearchOptions);
            DataModule1->ADOTable1->EnableControls();

       }

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FImage1MouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y)
{

    if (!Model->DoMeasuremet(this->ModelWidth, this->ModelHeight))
    {
        this->Label12->Caption = FormatFloat("###", 0);
        this->Label11->Caption = FormatFloat("###", 0);
        this->Label10->Caption = FormatFloat("###", 0);
        this->Label9->Caption = FormatFloat("###", 0);
        this->Label8->Caption = FormatFloat("###", 0);
        this->Label7->Caption = Model->Quadrant;
        this->Label30->Caption = IntToStr(0);
        this->Label31->Caption = IntToStr(0);
        this->Label32->Caption = Model->Comment;
        Label33->Caption = Model->Comment2;

		return;
    }
    this->Label12->Caption = FormatFloat("###", Model->Alfa);
    this->Label11->Caption = FormatFloat("###", Model->X);
    this->Label10->Caption = FormatFloat("###", Model->Y);
    this->Label9->Caption = FormatFloat("###", Model->J0);
    this->Label8->Caption = FormatFloat("###", Model->Jn);
    this->Label7->Caption = Model->Quadrant;
    this->Label30->Caption = IntToStr(Model->Score);
    this->Label31->Caption = IntToStr(Model->Level);
    this->Label32->Caption = Model->Comment;
    Label33->Caption = Model->Comment2;

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::DbExportActionExecute(TObject *Sender)
{
    Variant app1;
    Variant books1;
    Variant book1;
    Variant sheet1;
    Variant cell1, range1;

    app1 = CreateOleObject("Excel.Application");
    books1 = app1.OlePropertyGet(L"Workbooks");
    books1.Exec(Procedure(L"Add"));
    book1 = books1.OlePropertyGet(L"item",1);
    sheet1= book1.OlePropertyGet(L"WorkSheets",1);


    cell1 = sheet1.OlePropertyGet(L"Cells").OlePropertyGet(L"Item",1,1);
    AnsiString _ansi =  "Id";
    OleVariant v;
    v =  _ansi.c_str();
    cell1.OlePropertySet(L"Value", v);

    cell1 = sheet1.OlePropertyGet(L"Cells").OlePropertyGet(L"Item",1,2);
     _ansi =  "Имя";
    v =  _ansi.c_str();
    cell1.OlePropertySet(L"Value", v);

    cell1 = sheet1.OlePropertyGet(L"Cells").OlePropertyGet(L"Item",1,3);
     _ansi =  "Фамилия";     v;
    v =  _ansi.c_str();
    cell1.OlePropertySet(L"Value", v);

    cell1 = sheet1.OlePropertyGet(L"Cells").OlePropertyGet(L"Item",1,4);
     _ansi =  "Пол";
    v =  _ansi.c_str();
    cell1.OlePropertySet(L"Value", v);

    cell1 = sheet1.OlePropertyGet(L"Cells").OlePropertyGet(L"Item",1,5);
     _ansi =  "Возраст";
    v =  _ansi.c_str();
    cell1.OlePropertySet(L"Value", v);

    cell1 = sheet1.OlePropertyGet(L"Cells").OlePropertyGet(L"Item",1,6);
     _ansi =  "Профессия";
    v =  _ansi.c_str();
    cell1.OlePropertySet(L"Value", v);

    cell1 = sheet1.OlePropertyGet(L"Cells").OlePropertyGet(L"Item",1,7);
     _ansi =  "Вид теста";
    v =  _ansi.c_str();
    cell1.OlePropertySet(L"Value", v);

    cell1 = sheet1.OlePropertyGet(L"Cells").OlePropertyGet(L"Item",1,8);
     _ansi =  "Alfa";
    v =  _ansi.c_str();
    cell1.OlePropertySet(L"Value", v);

    cell1 = sheet1.OlePropertyGet(L"Cells").OlePropertyGet(L"Item",1,9);
     _ansi =  "X";
    v =  _ansi.c_str();
    cell1.OlePropertySet(L"Value", v);

    cell1 = sheet1.OlePropertyGet(L"Cells").OlePropertyGet(L"Item",1,10);
     _ansi =  "Y";
    v =  _ansi.c_str();
    cell1.OlePropertySet(L"Value", v);

    cell1 = sheet1.OlePropertyGet(L"Cells").OlePropertyGet(L"Item",1,11);
     _ansi =  "Jn";
    v =  _ansi.c_str();
    cell1.OlePropertySet(L"Value", v);

    cell1 = sheet1.OlePropertyGet(L"Cells").OlePropertyGet(L"Item",1,12);
     _ansi =  "J0";
    v =  _ansi.c_str();
    cell1.OlePropertySet(L"Value", v);

    cell1 = sheet1.OlePropertyGet(L"Cells").OlePropertyGet(L"Item",1,13);
     _ansi =  "Квадрант";
    v =  _ansi.c_str();
    cell1.OlePropertySet(L"Value", v);

    cell1 = sheet1.OlePropertyGet(L"Cells").OlePropertyGet(L"Item",1,14);
     _ansi =  "Общий балл мотивации";
    v =  _ansi.c_str();
    cell1.OlePropertySet(L"Value", v);

    cell1 = sheet1.OlePropertyGet(L"Cells").OlePropertyGet(L"Item",1,15);
     _ansi =  "Уровень выраженности мотивации";
    v =  _ansi.c_str();
    cell1.OlePropertySet(L"Value", v);


    DataModule1->ADOTable1->DisableControls();
  	DataModule1->ADOTable1->First();
    int row = 1;
    int col = 0;
    while(!DataModule1->ADOTable1->Eof)
    {
    	cell1 = sheet1.OlePropertyGet(L"Cells").OlePropertyGet(L"Item",row+1,1);
        AnsiString _ansi =  DataModule1->ADOTable1->FieldByName("PsyTestId")->AsString;
        OleVariant v;
        v =  _ansi.c_str();
        cell1.OlePropertySet(L"Value", v);

    	cell1 = sheet1.OlePropertyGet(L"Cells").OlePropertyGet(L"Item",row+1,2);
        _ansi =  DataModule1->ADOTable1->FieldByName("FirstName")->AsString;
        v =  _ansi.c_str();
        cell1.OlePropertySet(L"Value", v);

    	cell1 = sheet1.OlePropertyGet(L"Cells").OlePropertyGet(L"Item",row+1,3);
        _ansi =  DataModule1->ADOTable1->FieldByName("LastName")->AsString;
        v =  _ansi.c_str();
        cell1.OlePropertySet(L"Value", v);

    	cell1 = sheet1.OlePropertyGet(L"Cells").OlePropertyGet(L"Item",row+1,4);
        _ansi =  DataModule1->ADOTable1->FieldByName("Gender")->AsString;
        v =  _ansi.c_str();
        cell1.OlePropertySet(L"Value", v);

    	cell1 = sheet1.OlePropertyGet(L"Cells").OlePropertyGet(L"Item",row+1,5);
        _ansi =  DataModule1->ADOTable1->FieldByName("Age")->AsString;
        v =  _ansi.c_str();
        cell1.OlePropertySet(L"Value", v);

    	cell1 = sheet1.OlePropertyGet(L"Cells").OlePropertyGet(L"Item",row+1,6);
        _ansi =  DataModule1->ADOTable1->FieldByName("WorkType")->AsString;
        v =  _ansi.c_str();
        cell1.OlePropertySet(L"Value", v);

    	cell1 = sheet1.OlePropertyGet(L"Cells").OlePropertyGet(L"Item",row+1,7);
        _ansi =  DataModule1->ADOTable1->FieldByName("PsyTestType")->AsString;
        v =  _ansi.c_str();
        cell1.OlePropertySet(L"Value", v);

        TPsyGraphModel* m = MainForm->Model;
        m->LeftTop.X = DataModule1->ADOTable1->FieldByName("left_top_x")->Value;
        m->LeftTop.Y = DataModule1->ADOTable1->FieldByName("left_top_y")->Value;
        m->RightTop.X = DataModule1->ADOTable1->FieldByName("right_top_x")->Value;
        m->RightTop.Y = DataModule1->ADOTable1->FieldByName("right_top_y")->Value;
        m->RightBottom.X = DataModule1->ADOTable1->FieldByName("right_bottom_x")->Value;
        m->RightBottom.Y = DataModule1->ADOTable1->FieldByName("right_bottom_y")->Value;
    	m->LeftBottom.X = DataModule1->ADOTable1->FieldByName("left_bottom_x")->Value;
        m->LeftBottom.Y = DataModule1->ADOTable1->FieldByName("left_bottom_y")->Value;
        m->Start.X = DataModule1->ADOTable1->FieldByName("point1_x")->Value;
        m->Start.Y = DataModule1->ADOTable1->FieldByName("point1_y")->Value;
        m->Middle.X = DataModule1->ADOTable1->FieldByName("point2_x")->Value;
        m->Middle.Y = DataModule1->ADOTable1->FieldByName("point2_y")->Value;
        m->End.X = DataModule1->ADOTable1->FieldByName("point3_x")->Value;
        m->End.Y = DataModule1->ADOTable1->FieldByName("point3_y")->Value;

        m->DoMeasuremet(ModelWidth, ModelHeight);

    	cell1 = sheet1.OlePropertyGet(L"Cells").OlePropertyGet(L"Item",row+1,8);
        cell1.OlePropertySet(L"Value", m->Alfa);
    	cell1 = sheet1.OlePropertyGet(L"Cells").OlePropertyGet(L"Item",row+1,9);
        cell1.OlePropertySet(L"Value", m->X);
    	cell1 = sheet1.OlePropertyGet(L"Cells").OlePropertyGet(L"Item",row+1,10);
        cell1.OlePropertySet(L"Value", m->Y);
    	cell1 = sheet1.OlePropertyGet(L"Cells").OlePropertyGet(L"Item",row+1,11);
        cell1.OlePropertySet(L"Value", m->Jn);
    	cell1 = sheet1.OlePropertyGet(L"Cells").OlePropertyGet(L"Item",row+1,12);
        cell1.OlePropertySet(L"Value", m->J0);
    	cell1 = sheet1.OlePropertyGet(L"Cells").OlePropertyGet(L"Item",row+1,13);
        _ansi =  m->Quadrant;
        v =  _ansi.c_str();
        cell1.OlePropertySet(L"Value", v);

    	cell1 = sheet1.OlePropertyGet(L"Cells").OlePropertyGet(L"Item",row+1,14);
        cell1.OlePropertySet(L"Value", m->Score);

    	cell1 = sheet1.OlePropertyGet(L"Cells").OlePropertyGet(L"Item",row+1,15);
        cell1.OlePropertySet(L"Value", m->Level);

        row++;
		DataModule1->ADOTable1->Next();
    }
	DataModule1->ADOTable1->EnableControls();
    app1.OlePropertySet("Visible", 1);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::DbExportActionUpdate(TObject *Sender)
{
	DbExportAction->Enabled = DataModule1->ADOConnection1->Connected && DataModule1->ADOTable1->Active && !this->NewMeasure;
}
//---------------------------------------------------------------------------

bool __fastcall TMainForm::NeedWhere()
{
	if (ComboBoxGender->Text == L"Любой" && ComboBoxAge->Text == L"Любой" && ComboBoxWorkType->Text == L"Любой"  && ComboBoxPsyTestType->Text == L"Любой" )
    	return false;
    else
    	return true;
}

void __fastcall TMainForm::dbAddUserActionExecute(TObject *Sender)
{
	    m_new_measuare = false;
        Model->ClearModel();
        //FImage1->Paint();
         DataModule1->ADOTable1->Active = false;
         DataModule1->ADOTable1->Active = true;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::dbAddUserActionUpdate(TObject *Sender)
{
   	dbAddUserAction->Enabled = DataModule1->ADOConnection1->Connected && DataModule1->ADOTable1->Active && this->NewMeasure;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::dbSelectActionExecute(TObject *Sender)
{
    UnicodeString strQuery = L"select * from queryTests";
    if (ComboBoxNames->ItemIndex != 0)
    {
		strQuery += L" where ";

        strQuery += " LastName = '";
        strQuery += ComboBoxNames->Text;
        strQuery += "'";

    }
    else if (NeedWhere())
    {
		strQuery += L" where ";
        if (ComboBoxGender->Text != L"Любой")
        {
        	strQuery += " Gender = '";
            strQuery += ComboBoxGender->Text;
            strQuery += "'";
        }
        if (ComboBoxAge->Text != L"Любой")
        {
           int index = ComboBoxAge->ItemIndex;
           if (ComboBoxGender->Text != L"Любой")
           		strQuery += L" and ";

           strQuery += L" Age > ";

           switch (index)
           {
			case 1:
				strQuery += L" 10 and Age <= 15 ";
            break;
			case 2:
				strQuery += L" 15 and Age <= 20 ";
            break;
			case 3:
				strQuery += L" 20 and Age <= 25 ";
            break;
			case 4:
				strQuery += L" 25 and Age <= 30 ";
            break;
			case 5:
				strQuery += L" 30 and Age <= 35 ";
            break;
			case 6:
				strQuery += L" 35 and Age <=40 ";
            break;
			case 7:
				strQuery += L" 40 and Age <= 45 ";
            break;
			case 8:
				strQuery += L" 45 and Age <= 50 ";
            break;
			case 9:
				strQuery += L" 50 and Age <= 55 ";
            break;
			case 10:
				strQuery += L" 55 and Age <= 60 ";
            break;
			case 11:
				strQuery += L" 60 ";
            break;
           }
        }

        if (ComboBoxWorkType->Text != L"Любой")
        {
            if (ComboBoxGender->Text != L"Любой" || ComboBoxAge->Text != L"Любой" )
           		strQuery += L" and ";

         	strQuery += " WorkType = '";
            strQuery += ComboBoxWorkType->Text;
            strQuery += "'";

        }

        if (ComboBoxPsyTestType->Text != L"Любой")
        {
            if (ComboBoxGender->Text != L"Любой" || ComboBoxAge->Text != L"Любой" ||  ComboBoxWorkType->Text != L"Любой")
           		strQuery += L" and ";

         	strQuery += " PsyTestType = '";
            strQuery += ComboBoxPsyTestType->Text;
            strQuery += "'";

        }

    }

    DataModule1->ADOTable1->Active = false;
    FImage1->Close();
    FImage1->Paint();
	DataModule1->ADOTable1->SQL->Clear();
	DataModule1->ADOTable1->SQL->Add(strQuery);
    DataModule1->ADOTable1->Active = true;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::dbSelectActionUpdate(TObject *Sender)
{
	dbSelectAction->Enabled = DataModule1->ADOConnection1->Connected && DataModule1->ADOTable1->Active && !this->NewMeasure;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DisplayHint(TObject *Sender)
{
 StatusBar1->Panels->Items[0]->Text = GetLongHint(Application->Hint);
}
void __fastcall TMainForm::IdleHandler(TObject *Sender, bool& done)
{
 if (this->NewMeasure)
	 StatusBar1->Panels->Items[1]->Text = "Новое измерение";
 else
	 StatusBar1->Panels->Items[1]->Text = "Просмотр";
}


void __fastcall TMainForm::viewLifeLineActionExecute(TObject *Sender)
{
	this->Model->NeedDrawLifeLine = !this->Model->NeedDrawLifeLine;
    FImage1->BestFit();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::viewLifeLineActionUpdate(TObject *Sender)
{

	viewLifeLineAction->Checked = this->Model != NULL && this->Model->NeedDrawLifeLine;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::viewFrameActionExecute(TObject *Sender)
{
	this->Model->NeedDrawFrame = !this->Model->NeedDrawFrame;
    FImage1->BestFit();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::viewFrameActionUpdate(TObject *Sender)
{
	viewFrameAction->Checked = this->Model != NULL && this->Model->NeedDrawFrame;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::viewCoordsActionExecute(TObject *Sender)
{
	this->Model->NeedDrawCoords = !this->Model->NeedDrawCoords;
    FImage1->BestFit();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::viewCoordsActionUpdate(TObject *Sender)
{
	viewCoordsAction->Checked = this->Model != NULL && this->Model->NeedDrawCoords;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::dbCreateActionUpdate(TObject *Sender)
{
    dbCreateAction->Enabled = !this->NewMeasure;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::dbOpenActionUpdate(TObject *Sender)
{
   dbOpenAction->Enabled = !this->NewMeasure;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::dbEditUserActionExecute(TObject *Sender)
{
	AddUserDialog->EditUser();
  //  DataModule1->ADOTable1->Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::dbEditUserActionUpdate(TObject *Sender)
{
	dbAddUserAction->Enabled = DataModule1->ADOConnection1->Connected && DataModule1->ADOTable1->Active && !this->NewMeasure;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormShow(TObject *Sender)
{
	if (!m_open)
    {
         StartForm->ShowModal();
    }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ComboBoxNamesChange(TObject *Sender)
{
	if (ComboBoxNames->ItemIndex != 0)
    {
    	ComboBoxGender->ItemIndex = 0;
        ComboBoxGender->Enabled = false;

        ComboBoxAge->ItemIndex = 0;
        ComboBoxAge->Enabled = false;

        ComboBoxWorkType->ItemIndex = 0;
        ComboBoxWorkType->Enabled = false;

        ComboBoxPsyTestType->ItemIndex = 0;
        ComboBoxPsyTestType->Enabled = false;
    }
    else
    {
    	ComboBoxGender->ItemIndex = 0;
        ComboBoxGender->Enabled = true;

        ComboBoxAge->ItemIndex = 0;
        ComboBoxAge->Enabled = true;

        ComboBoxWorkType->ItemIndex = 0;
        ComboBoxWorkType->Enabled = true;

        ComboBoxPsyTestType->ItemIndex = 0;
        ComboBoxPsyTestType->Enabled = true;
    }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SpinEdit2Change(TObject *Sender)
{
	this->m_width = this->SpinEdit2->Value;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SpinEdit1Change(TObject *Sender)
{
	this->m_height = this->SpinEdit1->Value;
}
//---------------------------------------------------------------------------

