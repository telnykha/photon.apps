//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "beeMain.h"
#include "beeLongProcessForm.h"
#include "..\include\beepoints.h"
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
#pragma resource "*.dfm"

const TLFString ATTRUUIDS[8] =
{
"65FE75D4-B829-4117-8076-0A6D116F6EE5",
"AAF4E336-75AE-4802-BF5B-5A054968DC84",
"DA50F8EA-E59A-480D-98F9-55710235D1B7",
"5F86768E-E0BA-45B2-BE5E-BB5A1F28C919",
"B3CF6567-2FEA-4169-B9EA-229652889D69",
"2C9C044F-73B6-4D31-B3B3-4645493B3745",
"CD5DE575-CD69-4349-89E4-2DCEFC47930E",
"7BFF3331-C358-461B-968E-F8ABB18A4C97"
};

static double _2D_Dist(double x1,double y1,double x2,double y2)
{
  return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

TForm10 *Form10;
//---------------------------------------------------------------------------
__fastcall TForm10::TForm10(TComponent* Owner)
	: TForm(Owner)
{
   m_object = NULL;
   m_db     = NULL;
   m_file   = NULL;
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
//
}
//---------------------------------------------------------------------------

void __fastcall TForm10::fileExportTPSActionUpdate(TObject *Sender)
{
    fileExportTPSAction->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm10::fileAnalysisActionExecute(TObject *Sender)
{
   // ProcessImages();
   Form1->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm10::fileAnalysisActionUpdate(TObject *Sender)
{
	fileAnalysisAction->Enabled = FileListBox1->Items->Count > 0 && this->m_object != NULL;
}
//---------------------------------------------------------------------------
// îòîáðàæàåò â ñòðîêå ñòàòóñà ÷èñëî ôàéëîâ â ListBox
void __fastcall TForm10::DirectoryListBox1Change(TObject *Sender)
{
	StatusBar1->Panels->Items[0]->Text = L"×èñëî ôàéëîâ: " + IntToStr(FileListBox1->Items->Count);
	if (m_db != NULL) {
		delete m_db;
		m_db = NULL;
	}
	UnicodeString str = DirectoryListBox1->Directory;
	str += "\\beelandmarks.xml";
	 if (FileExists(str)) {
		AnsiString _ansi = str;
		m_db = new TLFDBLandmarks();
		if (!m_db->Connect(_ansi.c_str()))
		{
			// Draw landmarks
			ShowMessage(L"Error");
		}
	 }
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
	Panel2->Visible = !Panel2->Visible;
}
//---------------------------------------------------------------------------

void __fastcall TForm10::viewFilePanelActionUpdate(TObject *Sender)
{
	viewFilePanelAction->Checked = Panel2->Visible;
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
	viewBestFitAction->Checked = !viewBestFitAction->Checked;
	if (viewBestFitAction->Checked) {
	   PhImage1->BestFit();
	}
	else
		PhImage1->Paint();
}
//---------------------------------------------------------------------------

void __fastcall TForm10::FileListBox1Change(TObject *Sender)
{
	if (FileListBox1->FileName != "") {
		PhImage1->InitFile(FileListBox1->FileName);
		if (m_db != NULL) {
			 AnsiString _ansi = ExtractFileName(FileListBox1->FileName.LowerCase());
			 m_file = m_db->Files()->File(_ansi.c_str());
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm10::PhImage1AfterOpen(TObject *Sender)
{
	if (viewBestFitAction->Checked) {
	   PhImage1->BestFit();
	}
	else
		PhImage1->ActualSize();
	StatusBar1->Panels->Items[1]->Text = L"Ðàçìåð: " + IntToStr(PhImage1->Bitmap->Width) + L"x" + IntToStr(PhImage1->Bitmap->Height);
}
//---------------------------------------------------------------------------

void __fastcall TForm10::PhImage1ScaleChange(TObject *Sender)
{
	StatusBar1->Panels->Items[2]->Text = L"Óâåëè÷: " + FormatFloat("###.00", PhImage1->Scale);
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
//
}
//---------------------------------------------------------------------------

void __fastcall TForm10::toolsBeeLandmarksActionUpdate(TObject *Sender)
{
	toolsBeeLandmarksAction->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm10::toolsEditROIActionExecute(TObject *Sender)
{
	PhImage1->SelectPhTool(PhZonesTool1);
}
//---------------------------------------------------------------------------

void __fastcall TForm10::toolsEditROIActionUpdate(TObject *Sender)
{
	toolsEditROIAction->Enabled = !PhImage1->Empty;
	toolsEditROIAction->Checked = dynamic_cast<TPhZonesTool*>(PhImage1->PhTool) != NULL;
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
	int idx;
	if (IsNearPoint(X, Y, idx))
		PhImage1->Cursor = crHandPoint;
	else
		PhImage1->Cursor = crArrow;

}
//---------------------------------------------------------------------------

void __fastcall TForm10::FormCreate(TObject *Sender)
{
    this->SpeedButton1->Caption = L"";
	this->SpeedButton2->Caption = L"";
	this->SpeedButton3->Caption = L"";
	this->SpeedButton4->Caption = L"";

	PhZonesTool1->LoadZones("output.xml");
	AnsiString _ansi = ExtractFilePath(Application->ExeName);
	m_object = beeObjectCreate(_ansi.c_str());
	if (m_object == NULL) {
		ShowMessage(L"Íå ìîãó çàãðóçèòü äåòåêòîð îñîáûõ òî÷åê.");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm10::PhImage1ToolChange(TObject *Sender)
{
	if (PhImage1->PhTool != NULL) {
	   UnicodeString strText = L"";
	   if (PhImage1->PhTool->ToolName == L"RULER") {
		  strText = L"ËÈÍÅÉÊÀ";
	   }
	   else if (PhImage1->PhTool->ToolName == L"ZOOM/PANE") {
		  strText = L"ÓÂÅËÈ×ÍÅÍÈÅ/ÏÅÐÅÌÅÙÅÍÈÅ";
	   }
	   else if (PhImage1->PhTool->ToolName == L"ZOOM TO RECT") {
		  strText = L"ÓÂÅËÈ×ÍÅÍÈÅ ÏÐßÌÎÓÃÎËÜÍÈÊÀ";
	   }
	   else if (PhImage1->PhTool->ToolName == L"TRIANGLE") {
		  strText = L"ÈÇÌÅÐÅÍÈÅ ÓÃËÀ";
	   }
	   else if (PhImage1->PhTool->ToolName == L"ZONES EDITOR") {
		  strText = L"ÎÁËÀÑÒÈ ÏÎÈÑÊÀ";
	   }
	   StatusBar1->Panels->Items[4]->Text = L"Èíñòðóìåíò: " + strText;
	}
	else
		   StatusBar1->Panels->Items[4]->Text = L"Èíñòðóìåíò: ÍÅ ÂÛÁÐÀÍ";
}
//---------------------------------------------------------------------------
void __fastcall TForm10::ProcessImages()
{
	if (m_object == NULL)
		return;
	if (!this->CreateLandmarks()) {
		return;
	}
	beePoint bp[8];
	int num = 8;

	TLFLandmarkFiles* files = m_db->Files();

	for (int i = 0; i < FileListBox1->Items->Count; i++)
	{
		awpImage* img = NULL;
		AnsiString _ansi = FileListBox1->Items->Strings[i];
		awpLoadImage(_ansi.c_str(), &img);
		if (img)
		{
			if (beeImageProcess(m_object, img->sSizeX, img->sSizeY,  (AWPBYTE*)img->pPixels,&num,  bp) == S_OK)
			{
			   TLFLandmarkFile* file = new TLFLandmarkFile(_ansi.c_str());
				for (int i = 0; i < 8; i++) {
				   TLFLandmarkAttr* attr = m_db->Attributes()->Attribute(i);
				   awp2DPoint p;
				   p.X = 100.f*bp[i].x/(double)img->sSizeX;
				   p.Y = 100.f*bp[i].y/(double)img->sSizeY;
				   TLFLandmark* land = new TLFLandmark(attr, p);
				   file->Append(land);
				}
                files->Append(file);
			}

			Application->ProcessMessages();
			Form1->Label1->Caption = _ansi;
			Form1->ProgressBar1->Position = 100*i/FileListBox1->Items->Count;
			awpReleaseImage(&img);
		}
	}
	delete m_db;
	m_db = NULL;
}

bool __fastcall TForm10::CreateLandmarks()
{
	TLFLandmarkAttributes attrs;
	//1
	TLFString strID = ATTRUUIDS[0];
	TLFString className = "wing-1";
	int color;
	awpRGBtoWeb(128,128,128,&color);
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

	m_db = TLFDBLandmarks::CreateDatabase(attrs, "beelandmarks.xml");
	return m_db != NULL;
}

void __fastcall TForm10::PhImage1Paint(TObject *Sender)
{
	if (m_db != NULL) {
		 AnsiString _ansi = ExtractFileName(FileListBox1->FileName.LowerCase());
		 TLFLandmarkFile* f = m_db->Files()->File(_ansi.c_str());
		 //
		 if (f) {
			 // draw landmarks
			 awpImage* img = NULL;
			 PhImage1->GetAwpImage(&img);
			 for (int i = 0; i < f->Count(); i++) {
				 TLFLandmark* ll = f->Landmark(i);
				 if (ll) {
					   double x,y;
					   x = ll->x();
					   y = ll->y();
					   int xx = x*img->sSizeX / 100;
					   int yy = y*img->sSizeY / 100;
					   TCanvas* cnv = PhImage1->Canvas;

					   TPoint p = PhImage1->GetScreenPoint(xx, yy);

					   TRect r;
					   TRect rr;


					   cnv->Brush->Color = ll->Color();
					   cnv->Pen->Color = ll->Color();
					   cnv->TextOutW(p.x, p.y - 30, ll->ClassName());
					   r.init(xx - 8, yy-8,xx+8, yy+8 );
					   rr= PhImage1->GetScreenRect(r);
					   cnv->Ellipse(rr);
					   cnv->Brush->Style = bsClear;
					   r.init(xx - 48, yy-48,xx+48, yy+48 );
					   rr= PhImage1->GetScreenRect(r);
					   cnv->Rectangle(rr);
				 }
			 }
			 awpReleaseImage(&img);
		 }
	}
}
//---------------------------------------------------------------------------
bool __fastcall TForm10::IsNearPoint(int x, int y)
{
   TPoint p = PhImage1->GetImagePoint(x, y);
   if (m_file == NULL) {
	   return false;
   }

   for (int i = 0; i < m_file->Count(); i++)
   {
		TLFLandmark* ll = m_file->Landmark(i);
		if (ll)
		{
		   double _x,_y;
		   _x = ll->x();
		   _y = ll->y();
		   int xx = _x*PhImage1->Bitmap->Width / 100;
		   int yy = _y*PhImage1->Bitmap->Height / 100;
		   if (_2D_Dist(xx,yy, p.x, p.y) < 10) {
                idx = i;
				return true;
		   }
		}
   }

   return false;
}

void __fastcall TForm10::PhImage1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
//
}
//---------------------------------------------------------------------------

void __fastcall TForm10::PhImage1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
//
}
//---------------------------------------------------------------------------

