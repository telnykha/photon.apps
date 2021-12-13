//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "beeMain.h"
#include "beeLongProcessForm.h"
#include "BeeAboutForm.h"
#include "VerInfoUnit.h"
#include "..\include\beepoints.h"
#include "tpsUnit.h"
#include "BeeOptionsForm.h"
#include "BeeIniParamsUnit.h"
#include "BeeKindEditor.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FImage41"
#pragma link "PhImageTool"
#pragma link "PhPaneTool"
#pragma link "PhRulerTool"
#pragma link "PhZoomToRectTool"
#pragma link "PhTriangleTool"
#pragma link "PhZonesTool"
#pragma link "MCTPoints.lib"
#pragma link "PhLandmarksTool"
#pragma resource "*.dfm"
TForm10 *Form10;
const UnicodeString c_strDbFile = L"\\beelandmarks.xml";
const UnicodeString c_strDbFile0 = L"\\beelandmarks0.xml";

const UnicodeString c_strDbFile1 = L"beelandmarks.xml";
const UnicodeString c_strDbFile2 = L"beelandmarks0.xml";

extern TBeeIniParams* beeIni;

//---------------------------------------------------------------------------
__fastcall TForm10::TForm10(TComponent* Owner)
	: TForm(Owner)
{
   m_object = NULL;
   m_selectedFile = L"";
   m_beeTool = NULL;
}
//---------------------------------------------------------------------------
void __fastcall TForm10::fileExitActionExecute(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm10::fileFirstActionExecute(TObject *Sender)
{
	FileListBox1->ItemIndex = 0;
    FileListBox1Change(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm10::fileFirstActionUpdate(TObject *Sender)
{
	fileFirstAction->Enabled = FileListBox1->Items->Count > 0;
}
//---------------------------------------------------------------------------

void __fastcall TForm10::fileLastActionExecute(TObject *Sender)
{
	FileListBox1->ItemIndex = FileListBox1->Items->Count -1;
	FileListBox1Change(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm10::fileLastActionUpdate(TObject *Sender)
{
	fileLastAction->Enabled = FileListBox1->Items->Count > 0;
}
//---------------------------------------------------------------------------

void __fastcall TForm10::fileNextActionExecute(TObject *Sender)
{
	int index = FileListBox1->ItemIndex + 1;
	if (index < FileListBox1->Items->Count) {
	   FileListBox1->ItemIndex = index;
	   FileListBox1Change(Sender);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm10::fileNextActionUpdate(TObject *Sender)
{
	fileNextAction->Enabled = FileListBox1->Items->Count > 0;
}
//---------------------------------------------------------------------------

void __fastcall TForm10::filePrevActionExecute(TObject *Sender)
{
	int index = FileListBox1->ItemIndex - 1;
	if (index >= 0) {
	   FileListBox1->ItemIndex = index;
	   FileListBox1Change(Sender);
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm10::filePrevActionUpdate(TObject *Sender)
{
	filePrevAction->Enabled = FileListBox1->Items->Count > 0;
}
//---------------------------------------------------------------------------

void __fastcall TForm10::fileExportTPSActionExecute(TObject *Sender)
{
	if (SaveDialog1->Execute()) {
		if (!ExportTPS(ChangeFileExt(SaveDialog1->FileName, L".tps")))
			ShowMessage(L"Не могу сохранить файл: " +SaveDialog1->FileName);
		else
		{
			AnsiString _ansi = "notepad.exe " + ChangeFileExt(SaveDialog1->FileName, L".tps");
			WinExec(_ansi.c_str(), SW_SHOW);
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm10::fileExportTPSActionUpdate(TObject *Sender)
{
	fileExportTPSAction->Enabled = PhLandmarksTool1->db->Files()->Count() > 0;
}
//---------------------------------------------------------------------------

void __fastcall TForm10::fileAnalysisActionExecute(TObject *Sender)
{
   longProcessForm->replace = true;
   longProcessForm->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm10::fileAnalysisActionUpdate(TObject *Sender)
{
	fileAnalysisAction->Enabled = FileListBox1->Items->Count > 0 && this->m_object != NULL;
}
//---------------------------------------------------------------------------
// отображает в строке статуса число файлов в ListBox
void __fastcall TForm10::DirectoryListBox1Change(TObject *Sender)
{
	StatusBar1->Panels->Items[0]->Text = L"Число файлов: " + IntToStr(FileListBox1->Items->Count);
	PhImage1->Close();
	PhImage1->Paint();

	UnicodeString str = DirectoryListBox1->Directory;
	str += c_strDbFile;
	 if (FileExists(str)) {
		if (!PhLandmarksTool1->Connect(str))
		{
			ShowMessage(L"Не могу открыть базу данных.");
		}
		else
		{
			AnsiString _ansi = DirectoryListBox1->Directory + c_strDbFile0;
			m_db.Connect(_ansi.c_str());
		}
	 }
	 else
	 {
		this->PhLandmarksTool1->Close();
		m_db.Close();
	 }

	UpdateTPSGrid();
	beeIni->LastPath = DirectoryListBox1->Directory;
}
//---------------------------------------------------------------------------

void __fastcall TForm10::viewToolbarActionExecute(TObject *Sender)
{
	Panel1->Visible = !Panel1->Visible;
}
//---------------------------------------------------------------------------

void __fastcall TForm10::viewToolbarActionUpdate(TObject *Sender)
{
	viewToolbarAction->Checked = Panel1->Visible;
}
//---------------------------------------------------------------------------

void __fastcall TForm10::viewFilePanelActionExecute(TObject *Sender)
{
	PageControl2->Visible = !PageControl2->Visible;
}
//---------------------------------------------------------------------------

void __fastcall TForm10::viewFilePanelActionUpdate(TObject *Sender)
{
	viewFilePanelAction->Checked = PageControl2->Visible;
}
//---------------------------------------------------------------------------

void __fastcall TForm10::viewStatusBarActionExecute(TObject *Sender)
{
	StatusBar1->Visible = !StatusBar1->Visible;
}
//---------------------------------------------------------------------------

void __fastcall TForm10::viewStatusBarActionUpdate(TObject *Sender)
{
	viewStatusBarAction->Checked = StatusBar1->Visible;
}
//---------------------------------------------------------------------------

void __fastcall TForm10::viewBestFitActionExecute(TObject *Sender)
{
//	viewBestFitAction->Checked = !viewBestFitAction->Checked;
//	if (viewBestFitAction->Checked) {
	   PhImage1->BestFit();
//	}
//	else
//		PhImage1->Paint();
}
//---------------------------------------------------------------------------

void __fastcall TForm10::FileListBox1Change(TObject *Sender)
{
	m_selectedFile = FileListBox1->FileName;
	if (FileListBox1->FileName != "") {
		PhImage1->InitFile(m_selectedFile);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm10::PhImage1AfterOpen(TObject *Sender)
{
	PhLandmarksTool1->SelectFile(m_selectedFile);
	PhImage1->BestFit();
	StatusBar1->Panels->Items[1]->Text = L"Размер: " + IntToStr(PhImage1->Bitmap->Width) + L"x" + IntToStr(PhImage1->Bitmap->Height);
}
//---------------------------------------------------------------------------

void __fastcall TForm10::PhImage1ScaleChange(TObject *Sender)
{
	StatusBar1->Panels->Items[2]->Text = L"Увелич: " + FormatFloat("###.00", PhImage1->Scale);
}
//---------------------------------------------------------------------------


void __fastcall TForm10::FormResize(TObject *Sender)
{
	if (viewBestFitAction->Checked) {
	   PhImage1->BestFit();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm10::toolsZoomPaneActionExecute(TObject *Sender)
{
	PhImage1->SelectPhTool(PhPaneTool1);
}
//---------------------------------------------------------------------------

void __fastcall TForm10::toolsZoomPaneActionUpdate(TObject *Sender)
{
	toolsZoomPaneAction->Enabled = !PhImage1->Empty;
	toolsZoomPaneAction->Checked =  dynamic_cast< TPhPaneTool*>(PhImage1->PhTool) != NULL;
}
//---------------------------------------------------------------------------

void __fastcall TForm10::toolsZoomToRectActionExecute(TObject *Sender)
{
	PhImage1->SelectPhTool(PhZoomToRectTool1);
}
//---------------------------------------------------------------------------

void __fastcall TForm10::toolsZoomToRectActionUpdate(TObject *Sender)
{
	toolsZoomToRectAction->Enabled = !PhImage1->Empty;
	toolsZoomToRectAction->Checked = dynamic_cast< TPhZoomToRectTool*>(PhImage1->PhTool) != NULL;
}
//---------------------------------------------------------------------------

void __fastcall TForm10::toolsRulerActionExecute(TObject *Sender)
{
	 PhImage1->SelectPhTool(PhRulerTool1);
}
//---------------------------------------------------------------------------

void __fastcall TForm10::toolsRulerActionUpdate(TObject *Sender)
{
	toolsRulerAction->Enabled = !PhImage1->Empty;
	toolsRulerAction->Checked =  dynamic_cast< TPhRulerTool*>(PhImage1->PhTool) != NULL;
}
//---------------------------------------------------------------------------

void __fastcall TForm10::toolsAngleActionExecute(TObject *Sender)
{
	PhImage1->SelectPhTool(PhTriangleTool1);
}
//---------------------------------------------------------------------------

void __fastcall TForm10::toolsAngleActionUpdate(TObject *Sender)
{
	toolsAngleAction->Enabled = !PhImage1->Empty;
	toolsAngleAction->Checked = dynamic_cast<TPhTriangleTool*>(PhImage1->PhTool) != NULL;
}
//---------------------------------------------------------------------------

void __fastcall TForm10::toolsBeeLandmarksActionExecute(TObject *Sender)
{
	PhImage1->SelectPhTool(PhLandmarksTool1);
}
//---------------------------------------------------------------------------

void __fastcall TForm10::toolsBeeLandmarksActionUpdate(TObject *Sender)
{
	toolsBeeLandmarksAction->Enabled = this->PhLandmarksTool1->Connected;
	toolsBeeLandmarksAction->Checked = dynamic_cast<TPhLandmarksTool*>(PhImage1->PhTool) != NULL;
}
//---------------------------------------------------------------------------

void __fastcall TForm10::toolsEditROIActionExecute(TObject *Sender)
{
  //	PhImage1->SelectPhTool(PhZonesTool1);
  if (m_beeTool != NULL) {
	  delete m_beeTool;
  }
  m_beeTool = new TPhBeeLandmarksTool(NULL);
  m_beeTool->PhImage = PhImage1;
  PhImage1->SelectPhTool(m_beeTool);
}
//---------------------------------------------------------------------------

void __fastcall TForm10::toolsEditROIActionUpdate(TObject *Sender)
{
	toolsEditROIAction->Enabled = !PhImage1->Empty;
	toolsEditROIAction->Checked = dynamic_cast<TPhBeeLandmarksTool*>(PhImage1->PhTool) != NULL;
}
//---------------------------------------------------------------------------

void __fastcall TForm10::PhImage1MouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y)
{
	if (PhImage1->Empty)
    	return;
	int x = PhImage1->GetImageX(X);
	int y = PhImage1->GetImageY(Y);
	AnsiString strStatusText = "x=" + IntToStr(x) + ":y=" + IntToStr(y);
	StatusBar1->Panels->Items[3]->Text = strStatusText;
}
//---------------------------------------------------------------------------
//
void __fastcall TForm10::FormCreate(TObject *Sender)
{
	this->SpeedButton1->Caption = L"";
	this->SpeedButton2->Caption = L"";
	this->SpeedButton3->Caption = L"";
	this->SpeedButton4->Caption = L"";
	this->SpeedButton5->Caption = L"";
	this->SpeedButton6->Caption = L"";
	this->SpeedButton9->Caption = L"";
	this->SpeedButton10->Caption = L"";
	this->SpeedButton11->Caption = L"";

	AnsiString _ansi = ExtractFilePath(Application->ExeName);
	PhZonesTool1->LoadZones(_ansi + "\\output.xml");
	PhZonesTool1->OnChangeRoi = ChangeRoi;
	m_object = beeObjectCreate(_ansi.c_str());
	if (m_object == NULL) {
		ShowMessage(L"Не могу загрузить детектор особых точек.");
	}
	PhImage1->Cursor = TCursor(crHandPoint);
	StringGrid1->ColWidths[0] = 40;
	StringGrid1->ColWidths[1] = 96;
	StringGrid1->ColWidths[2] = 40;
	StringGrid1->ColWidths[3] = 40;
    StringGrid1->Cells[0][0] = L"№";
	StringGrid1->Cells[1][0] = L"Статус";
	StringGrid1->Cells[2][0] = L"X";
	StringGrid1->Cells[3][0] = L"Y";

	DirectoryListBox1->Directory =  beeIni->LastPath;

}
//---------------------------------------------------------------------------

void __fastcall TForm10::PhImage1ToolChange(TObject *Sender)
{
	if (PhImage1->PhTool != NULL) {
	   UnicodeString strText = L"";
	   if (PhImage1->PhTool->ToolName == L"RULER") {
		  strText = L"ЛИНЕЙКА";
		  PhImage1->Cursor = TCursor(crDefault);
	   }
	   else if (PhImage1->PhTool->ToolName == L"ZOOM/PANE") {
		  strText = L"УВЕЛИЧНЕНИЕ/ПЕРЕМЕЩЕНИЕ";
		  PhImage1->Cursor = TCursor(crHandPoint);
	   }
	   else if (PhImage1->PhTool->ToolName == L"ZOOM TO RECT") {
		  strText = L"УВЕЛИЧНЕНИЕ ПРЯМОУГОЛЬНИКА";
		  PhImage1->Cursor = TCursor(crDefault);
	   }
	   else if (PhImage1->PhTool->ToolName == L"TRIANGLE") {
		  strText = L"ИЗМЕРЕНИЕ УГЛА";
		  PhImage1->Cursor = TCursor(crDefault);
	   }
	   else if (PhImage1->PhTool->ToolName == L"ZONES EDITOR") {
		  strText = L"ОБЛАСТИ ПОИСКА";
		  PhImage1->Cursor = TCursor(crDefault);
	   }
	   else if (PhImage1->PhTool->ToolName == L"LANDMARKS") {
		  strText = L"ОСОБЫЕ ТОЧКИ";
		  PhImage1->Cursor = TCursor(crDefault);
	   }
	   StatusBar1->Panels->Items[4]->Text = L"Инструмент: " + strText;
	}
	else
		   StatusBar1->Panels->Items[4]->Text = L"Инструмент: НЕ ВЫБРАН";
	PhImage1->Paint();
}
//---------------------------------------------------------------------------
void __fastcall TForm10::ProcessImages(bool replace)
{
	if (m_object == NULL)
		return;
	if (!this->CreateLandmarks()) {
		return;
	}
	beePoint bp[8];
	int num = 8;

	TLFLandmarkFiles* files = PhLandmarksTool1->db->Files();

	for (int i = 0; i < FileListBox1->Items->Count; i++)
	{
		awpImage* img = NULL;
		AnsiString _ansi = FileListBox1->Items->Strings[i];
		awpLoadImage(_ansi.c_str(), &img);
		AWPBYTE* data = NULL;
		AWPDWORD l = 0;
		if (img)
		{
			if (beeImageProcess(m_object, img->sSizeX, img->sSizeY,  (AWPBYTE*)img->pPixels,&num,  bp) == S_OK)
			{
			   TLFLandmarkFile* file = new TLFLandmarkFile(_ansi.c_str());
				for (int i = 0; i < 8; i++) {
				   TLFLandmarkAttr* attr = PhLandmarksTool1->db->Attributes()->Attribute(i);
				   awp2DPoint p;
				   p.X = 100.f*bp[i].x/(double)img->sSizeX;
				   p.Y = 100.f*bp[i].y/(double)img->sSizeY;
				   TLFLandmark* land = new TLFLandmark(attr, p, bp[i].q);
				   file->Append(land);
				}
				files->Append(file);
			}

			Application->ProcessMessages();
			longProcessForm->Label1->Caption = _ansi;
			longProcessForm->ProgressBar1->Position = 100*i/FileListBox1->Items->Count;
			awpReleaseImage(&img);
		}
	}
	//
	PhLandmarksTool1->Close();
	PhLandmarksTool1->Connect(c_strDbFile1);
	if (replace) {
		CopyFile(c_strDbFile1.c_str(),c_strDbFile2.c_str(), false);
	}
	if (PhLandmarksTool1->SelectFile(FileListBox1->FileName))
	{
	  AnsiString _ansi = DirectoryListBox1->Directory + c_strDbFile0;
	  m_db.Connect(_ansi.c_str());
	  PhImage1->Paint();
	}
	UpdateTPSGrid();
}

bool __fastcall TForm10::CreateLandmarks()
{
	PhLandmarksTool1->Close();
	AnsiString _ansi = DirectoryListBox1->Directory + c_strDbFile;
	if (FileExists(_ansi, false))
	{
	   DeleteFile(_ansi);
	}

	TLFLandmarkAttributes attrs;
	//1
	TLFString strID = ATTRUUIDS[0];
	TLFString className = "wing-1";
	int color;
	awpRGBtoWeb(0,128,255,&color);
	TLFLandmarkAttr* wing = new TLFLandmarkAttr(strID, color, className.c_str());
	attrs.Append(wing);
	//2
	strID = ATTRUUIDS[1];
	className = "wing-2";
	awpRGBtoWeb(255,255,255,&color);
	wing = new TLFLandmarkAttr(strID, color, className.c_str());
	attrs.Append(wing);
	//3
	strID = ATTRUUIDS[2];
	className = "wing-3";
	awpRGBtoWeb(0,255,255,&color);
	wing = new TLFLandmarkAttr(strID, color, className.c_str());
	attrs.Append(wing);
	//4
	strID = ATTRUUIDS[3];
	className = "wing-4";
	awpRGBtoWeb(255,0,255,&color);
	wing = new TLFLandmarkAttr(strID, color, className.c_str());
	attrs.Append(wing);
	//5
	strID = ATTRUUIDS[4];
	className = "wing-5";
	awpRGBtoWeb(255,255,0,&color);
	wing = new TLFLandmarkAttr(strID, color, className.c_str());
	attrs.Append(wing);
	//6
	strID = ATTRUUIDS[5];
	className = "wing-6";
	awpRGBtoWeb(255,0,0,&color);
	wing = new TLFLandmarkAttr(strID, color, className.c_str());
	attrs.Append(wing);
	//7
	strID = ATTRUUIDS[6];
	className = "wing-7";
	awpRGBtoWeb(0,255,0,&color);
	wing = new TLFLandmarkAttr(strID, color, className.c_str());
	attrs.Append(wing);
	//8
	strID = ATTRUUIDS[7];
	className = "wing-8";
	awpRGBtoWeb(0,0,255,&color);
	wing = new TLFLandmarkAttr(strID, color, className.c_str());
	attrs.Append(wing);


	TLFDBLandmarks* db = TLFDBLandmarks::CreateDatabase(attrs, _ansi.c_str());
	delete db;
	return PhLandmarksTool1->Connect(_ansi);
}

void __fastcall TForm10::PhImage1Paint(TObject *Sender)
{
	int delta = 8;
	int idx =  -1;
	if (this->PageControl2->ActivePage == this->TabSheet3) {
		UnicodeString str = StringGrid1->Cells[0][StringGrid1->Row];
		try
		{
			idx = StrToInt(str);
			idx--;
		}
		catch(EConvertError& e)
		{
			idx = -1;
		}
	}


	if (PhLandmarksTool1->Connected &&  dynamic_cast<TPhLandmarksTool*>(PhImage1->PhTool) == NULL)
	{
		 AnsiString _ansi = ExtractFileName(this->m_selectedFile);
		 TLFLandmarkFile* f = PhLandmarksTool1->db->Files()->File(_ansi.c_str());
		 TLFLandmarkFile* f0 = NULL;
		 if (m_db.Files() != NULL)
			f0 =  m_db.Files()->File(_ansi.c_str());
		 int w = PhImage1->Bitmap->Width;
		 int h = PhImage1->Bitmap->Height;
		 if (f) {
			 // draw landmarks
			 for (int i = 0; i < f->Count(); i++) {
				 TLFLandmark* ll = f->Landmark(i);
				 if (ll) {
					   double x,y;
					   x = ll->x();
					   y = ll->y();
					   int xx = x*w / 100;
					   int yy = y*h / 100;
					   TCanvas* cnv = PhImage1->Canvas;

					   TPoint p = PhImage1->GetScreenPoint(xx, yy);

					   TRect r;
					   TRect rr;


					   cnv->Brush->Color = (TColor)ll->Color();
					   cnv->Pen->Color = (TColor)ll->Color();
					   if (i == idx)
						  delta = 24;
					   else
						  delta = 8;
					   r.init(xx - delta, yy-delta,xx+delta, yy+delta );
					   rr= PhImage1->GetScreenRect(r);
					   cnv->Ellipse(rr);
					   if (ll->Status() == 0.5 && f0 != NULL)
					   {
						 TBrushStyle s = cnv->Brush->Style;
						 cnv->Brush->Style = bsClear;
						 TLFLandmark* ll0 = f0->Landmark(i);
						 double x0,y0;
						 x0 = ll0->x();
						 y0 = ll0->y();
						 int xx0 = x0*w / 100;
						 int yy0 = y0*h / 100;
						 TRect r0;
						 TRect rr0;
						 r0.init(xx0 - delta, yy0-delta,xx0+delta, yy0+delta );
						 rr0= PhImage1->GetScreenRect(r0);
						 cnv->Ellipse(rr0);
						 cnv->MoveTo(PhImage1->GetScreenPoint(xx,yy).x, PhImage1->GetScreenPoint(xx,yy).y);
						 cnv->LineTo(PhImage1->GetScreenPoint(xx0,yy0).x, PhImage1->GetScreenPoint(xx0,yy0).y);
                         cnv->Brush->Style = s;
					   }
				 }
			 }
		 }
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm10::ChangeRoi(TObject* sender,  int index, bool update)
{
	UnicodeString str = ExtractFilePath(Application->ExeName);
	this->PhZonesTool1->SaveZones(str + "\\output.xml");
	if (update) {
		AnsiString _ansi = str;
		if (m_object != NULL) {
			beeObjectFree(m_object);
			m_object = NULL;
		}
		m_object = beeObjectCreate(_ansi.c_str());
		if (m_object == NULL) {
			ShowMessage(L"Не могу загрузить детектор особых точек.");
		}
	}
}

bool __fastcall TForm10::ExportTPS(const UnicodeString& strFileName)
{
	AnsiString _ansi = strFileName;
	FILE* f = fopen(_ansi.c_str(), "w+t");
	if (f != NULL)
	{
		TLFDBLandmarks* db = PhLandmarksTool1->db;
		for (int i = 0; i < db->Files()->Count(); i++)
		{
			TLFLandmarkFile* file = db->Files()->File(i);
			if (file != NULL)
			{
				fprintf(f, "LM=8\n");
				for (int j = 0; j < 8; j++)
				{
					TLFLandmark* ll = file->Landmark(j);
					fprintf(f, "%lf %lf\n", 1920*ll->x()/100, 1080*(100-ll->y())/100.);
				}
				fprintf(f, "IMAGE=%s\n", file->FileName());
			}
			else
				return false;
		}
		fclose(f);
        return true;
	}
	return false;
}


void __fastcall TForm10::viewActualSizeActionExecute(TObject *Sender)
{
    PhImage1->ActualSize();
}
//---------------------------------------------------------------------------

void __fastcall TForm10::viewActualSizeActionUpdate(TObject *Sender)
{
	viewActualSizeAction->Enabled = !PhImage1->Empty;
}
//---------------------------------------------------------------------------

void __fastcall TForm10::viewBestFitActionUpdate(TObject *Sender)
{
	viewBestFitAction->Enabled = !PhImage1->Empty;
}
//---------------------------------------------------------------------------
void __fastcall TForm10::UpdateTPSGrid()
{
	StringGrid1->RowCount = 2;
	StringGrid1->Cells[0][1] = L"№";
   if (PhLandmarksTool1->Connected)
   {
		for (int i = 0; i < PhLandmarksTool1->db->Files()->Count(); i++)
		{
			 TLFLandmarkFile* file = PhLandmarksTool1->db->Files()->File(i);
			 int index = StringGrid1->RowCount - 1;
			 StringGrid1->RowCount +=1;
			 StringGrid1->Cells[0][index] = L"IMG=";
			 StringGrid1->Cells[1][index] = file->FileName();

			 for (int j = 1; j <= 8; j++)
			 {
				  if (viewHideSuccessAction->Checked){
					if (file->Landmark(j-1)->Status() == 0)
					{
					  index = StringGrid1->RowCount -1;
					  StringGrid1->RowCount +=1;
					  StringGrid1->Cells[0][index] = IntToStr(j);
					  StringGrid1->Cells[1][index] = FormatFloat("##0.00", file->Landmark(j-1)->Status());
					  StringGrid1->Cells[2][index] = FormatFloat("###.##", file->Landmark(j-1)->x());
					  StringGrid1->Cells[3][index] = FormatFloat("###.##", file->Landmark(j-1)->y());
					}
				  }
				  else
				  {
					  index = StringGrid1->RowCount -1;
					  StringGrid1->RowCount +=1;
					  StringGrid1->Cells[0][index] = IntToStr(j);
					  StringGrid1->Cells[1][index] = FormatFloat("##0.00", file->Landmark(j-1)->Status());
					  StringGrid1->Cells[2][index] = FormatFloat("###.##", file->Landmark(j-1)->x());
					  StringGrid1->Cells[3][index] = FormatFloat("###.##", file->Landmark(j-1)->y());
				  }

			 }
		}
   }
}


void __fastcall TForm10::StringGrid1Click(TObject *Sender)
{
	int idx = StringGrid1->Row;
	if (idx == 0) {
		return;
	}
	else
	{
		while(idx > 0 && StringGrid1->Cells[0][idx] != L"IMG=")
			idx--;
		// Open Image
		if (StringGrid1->Cells[1][idx] != PhImage1->FileName) {
			m_selectedFile = StringGrid1->Cells[1][idx];
			PhImage1->InitFile(m_selectedFile);
		}
		PhImage1->Paint();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm10::StringGrid1DrawCell(TObject *Sender, int ACol, int ARow,
		  TRect &Rect, TGridDrawState State)
{
	UnicodeString str = StringGrid1->Cells[ACol][ARow];
	if (str == L"0.00")
	{
	 StringGrid1->Canvas->Brush->Color = clYellow;
	 StringGrid1->Canvas->FillRect(Rect); // применяем изменения
	 StringGrid1->Canvas->TextOut(Rect.Left, Rect.Top, StringGrid1->Cells[ACol][ARow]);
	}
	else if (str == "0.50") {
	 StringGrid1->Canvas->Brush->Color = clLime;
	 StringGrid1->Canvas->FillRect(Rect); // применяем изменения
	 StringGrid1->Canvas->TextOut(Rect.Left, Rect.Top, StringGrid1->Cells[ACol][ARow]);
	 }
}
//---------------------------------------------------------------------------

void __fastcall TForm10::viewHideSuccessActionExecute(TObject *Sender)
{
	viewHideSuccessAction->Checked = !viewHideSuccessAction->Checked;
	if (viewHideSuccessAction->Checked) {
		viewHideSuccessAction->Caption = L"Показать все";
	}
	else
		viewHideSuccessAction->Caption = L"Скрыть найденные";
	UpdateTPSGrid();
}
//---------------------------------------------------------------------------

void __fastcall TForm10::viewHideSuccessActionUpdate(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------

void __fastcall TForm10::PhLandmarksTool1Change(TObject *Sender)
{
	if (dynamic_cast<TPhLandmarksTool*>(PhImage1->PhTool) == NULL) {
		return;
	}
   int row = StringGrid1->Row;
   UpdateTPSGrid();
   StringGrid1->Row = row;
}
//---------------------------------------------------------------------------
void __fastcall TForm10::MakeReport()
{
	if (m_db.Files()->Count() == 0) {
		return;
	}
	double err[8];
	memset(err,0, sizeof(err));
	double count = m_db.Files()->Count();
	for (int i = 0; i < m_db.Files()->Count(); i++) {
	   TLFLandmarkFile* f= m_db.Files()->File(i);
	   for (int j = 0; j < f->Count(); j++) {
		   TLFLandmark* ll = f->Landmark(j);
		   if (ll->Status() == 0) {
			   err[j]++;
		   }
	   }
	}
	for (int i = 0; i < 8; i++) {
		 err[i] /= count;
		 err[i] *= 100;
         err[i] = 100 - err[i];
		 ValueListEditor2->Strings->ValueFromIndex[i] = FormatFloat("###.##", err[i]) + L"%";
	}
}


void __fastcall TForm10::TabSheet4Show(TObject *Sender)
{
MakeReport();
}
//---------------------------------------------------------------------------

void __fastcall TForm10::helpAboutActionExecute(TObject *Sender)
{
  TVersionInfo* vi = new TVersionInfo(NULL);
  AboutBox->ProductName->Caption = vi->ProductName;
  AboutBox->Version->Caption = vi->FileVersion;
  AboutBox->Copyright->Caption = vi->LegalCopyright;
  AboutBox->Comments->Caption = vi->Comments;
  AboutBox->ShowModal();
  delete vi;

}
//---------------------------------------------------------------------------
/*
Загрузка данных из tps файла.
TPS файл может находиться в любом месте на диске, он конвертируется в beelandmarks.xml
beelandmarks.xml записывается в папку, определяемую переменной DirectoryListBox1->Directory
*/
void __fastcall TForm10::fileImportTPSActionExecute(TObject *Sender)
{
	OpenDialog1->InitialDir =  DirectoryListBox1->Directory;
	if (OpenDialog1->Execute()) {
		AnsiString _ansi = OpenDialog1->FileName;
		AnsiString _xml  =  DirectoryListBox1->Directory + c_strDbFile;
		if (FileExists(_xml, true)) {
		   int result = Application->MessageBoxW(L"База данных точек на крыльях уже существует. Заменить ее?",
		   ExtractFileName(Application->ExeName).c_str(), MB_YESNO);
		   if (result == IDNO) {
				return;
		   }
		}
		ConvertTPSTolandmarks(_ansi.c_str(), _xml.c_str());
		//
		_xml  =  DirectoryListBox1->Directory + c_strDbFile0;
		if (!FileExists(_xml, true)) {
			 // включить обработчик изображений
			 longProcessForm->replace = false;
			 longProcessForm->ShowModal();
		}

		// connect to database
		PhLandmarksTool1->Close();
		PhLandmarksTool1->Connect(c_strDbFile1);
		if (PhLandmarksTool1->SelectFile(FileListBox1->FileName))
		{
		  AnsiString _ansi = DirectoryListBox1->Directory + c_strDbFile0;
		  m_db.Connect(_ansi.c_str());
		  PhImage1->Paint();
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm10::toolsOptionsActionExecute(TObject *Sender)
{
	OptionsForm->RadioGroup1->ItemIndex = beeIni->LandmarkSkin;
	OptionsForm->CheckBox1->Checked = beeIni->NeedAnalysis;
	OptionsForm->RadioGroup2->ItemIndex = beeIni->UITheme == L"Windows"?0:1;

	if (OptionsForm->ShowModal() == mrOk) {
		beeIni->LandmarkSkin = OptionsForm->RadioGroup1->ItemIndex;
		beeIni->NeedAnalysis = OptionsForm->CheckBox1->Checked;
		beeIni->UITheme  = OptionsForm->RadioGroup2->ItemIndex==0?L"Windows":L"Carbon";
		if (OptionsForm->RadioGroup2->ItemIndex == 0)
			TStyleManager::SetStyle("Windows");
		else
			TStyleManager::SetStyle("Carbon");
		PhLandmarksTool1->Skin = OptionsForm->RadioGroup1->ItemIndex;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm10::toolsKindEditorActionExecute(TObject *Sender)
{
    kindEditorForm->ShowModal();
}
//---------------------------------------------------------------------------


