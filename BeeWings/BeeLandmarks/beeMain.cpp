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
#pragma link "PhLandmarksTool"
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



TForm10 *Form10;
//---------------------------------------------------------------------------
__fastcall TForm10::TForm10(TComponent* Owner)
	: TForm(Owner)
{
   m_object = NULL;
   m_selectedFile = L"";
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
			ShowMessage(L"Íå ìîãó ñîõðàíèòü ôàéë: " +SaveDialog1->FileName);
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
	PhImage1->Close();
	PhImage1->Paint();

	UnicodeString str = DirectoryListBox1->Directory;
	str += "\\beelandmarks.xml";
	 if (FileExists(str)) {
		if (!PhLandmarksTool1->Connect(str))
		{
			ShowMessage(L"Íå ìîãó îòêðûòü áàçó äàííûõ.");
		}
	 }
	 else
		this->PhLandmarksTool1->Close();

	UpdateTPSGrid();
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
	this->SpeedButton7->Caption = L"";
	this->SpeedButton8->Caption = L"";
	this->SpeedButton9->Caption = L"";
	this->SpeedButton10->Caption = L"";
	this->SpeedButton11->Caption = L"";

	AnsiString _ansi = ExtractFilePath(Application->ExeName);
	PhZonesTool1->LoadZones(_ansi + "\\output.xml");
	PhZonesTool1->OnChangeRoi = ChangeRoi;
	m_object = beeObjectCreate(_ansi.c_str());
	if (m_object == NULL) {
		ShowMessage(L"Íå ìîãó çàãðóçèòü äåòåêòîð îñîáûõ òî÷åê.");
	}
	PhImage1->Cursor = TCursor(crHandPoint);
	StringGrid1->ColWidths[0] = 40;
	StringGrid1->ColWidths[1] = 96;
	StringGrid1->ColWidths[2] = 40;
	StringGrid1->ColWidths[3] = 40;
    StringGrid1->Cells[0][0] = L"¹";
	StringGrid1->Cells[1][0] = L"Ñòàòóñ";
	StringGrid1->Cells[2][0] = L"X";
	StringGrid1->Cells[3][0] = L"Y";

}
//---------------------------------------------------------------------------

void __fastcall TForm10::PhImage1ToolChange(TObject *Sender)
{
	if (PhImage1->PhTool != NULL) {
	   UnicodeString strText = L"";
	   if (PhImage1->PhTool->ToolName == L"RULER") {
		  strText = L"ËÈÍÅÉÊÀ";
		  PhImage1->Cursor = TCursor(crDefault);
	   }
	   else if (PhImage1->PhTool->ToolName == L"ZOOM/PANE") {
		  strText = L"ÓÂÅËÈ×ÍÅÍÈÅ/ÏÅÐÅÌÅÙÅÍÈÅ";
		  PhImage1->Cursor = TCursor(crHandPoint);
	   }
	   else if (PhImage1->PhTool->ToolName == L"ZOOM TO RECT") {
		  strText = L"ÓÂÅËÈ×ÍÅÍÈÅ ÏÐßÌÎÓÃÎËÜÍÈÊÀ";
		  PhImage1->Cursor = TCursor(crDefault);
	   }
	   else if (PhImage1->PhTool->ToolName == L"TRIANGLE") {
		  strText = L"ÈÇÌÅÐÅÍÈÅ ÓÃËÀ";
		  PhImage1->Cursor = TCursor(crDefault);
	   }
	   else if (PhImage1->PhTool->ToolName == L"ZONES EDITOR") {
		  strText = L"ÎÁËÀÑÒÈ ÏÎÈÑÊÀ";
		  PhImage1->Cursor = TCursor(crDefault);
	   }
	   else if (PhImage1->PhTool->ToolName == L"LANDMARKS") {
		  strText = L"ÎÑÎÁÛÅ ÒÎ×ÊÈ";
		  PhImage1->Cursor = TCursor(crDefault);
	   }
	   StatusBar1->Panels->Items[4]->Text = L"Èíñòðóìåíò: " + strText;
	}
	else
		   StatusBar1->Panels->Items[4]->Text = L"Èíñòðóìåíò: ÍÅ ÂÛÁÐÀÍ";
	PhImage1->Paint();
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
			Form1->Label1->Caption = _ansi;
			Form1->ProgressBar1->Position = 100*i/FileListBox1->Items->Count;
			awpReleaseImage(&img);
		}
	}
	//
	if (PhLandmarksTool1->SelectFile(FileListBox1->FileName))
	{
	  PhImage1->Paint();
	}
	UpdateTPSGrid();
}

bool __fastcall TForm10::CreateLandmarks()
{
	PhLandmarksTool1->Close();
	AnsiString _ansi = DirectoryListBox1->Directory + "\\beelandmarks.xml";
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
		 AnsiString _ansi = ExtractFileName(this->m_selectedFile.LowerCase());
		 TLFLandmarkFile* f = PhLandmarksTool1->db->Files()->File(_ansi.c_str());
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
			ShowMessage(L"Íå ìîãó çàãðóçèòü äåòåêòîð îñîáûõ òî÷åê.");
		}
	}


	ShowMessage("îáíîâëåíèå output.xml");
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
   if (!PhLandmarksTool1->Connected)
   {
		StringGrid1->RowCount = 2;
		StringGrid1->Cells[0][1] = L"¹";
   }
   else
   {
		StringGrid1->RowCount = 1+9*PhLandmarksTool1->db->Files()->Count();
		for (int i = 0; i < PhLandmarksTool1->db->Files()->Count(); i++)
		{
			 TLFLandmarkFile* file = PhLandmarksTool1->db->Files()->File(i);
			 int index = 1+9*i;
			 StringGrid1->Cells[0][index] = L"IMG=";
			 StringGrid1->Cells[1][index] = file->FileName();
			 for (int j = 1; j <= 8; j++)
			 {
				  StringGrid1->Cells[0][index +j ] = IntToStr(j);
				  StringGrid1->Cells[1][index +j ] = FormatFloat("##0.00", file->Landmark(j-1)->Status());
				  StringGrid1->Cells[2][index +j ] = FormatFloat("###.##", file->Landmark(j-1)->x());
				  StringGrid1->Cells[3][index +j ] = FormatFloat("###.##", file->Landmark(j-1)->y());
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
	if (str == L"0.00") {
		StringGrid1->Canvas->Brush->Color = clYellow;
	 StringGrid1->Canvas->FillRect(Rect); // ïðèìåíÿåì èçìåíåíèÿ
	 StringGrid1->Canvas->TextOut(Rect.Left, Rect.Top, StringGrid1->Cells[ACol][ARow]);
	}
}
//---------------------------------------------------------------------------

