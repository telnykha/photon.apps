//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "beeMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FImage41"
#pragma link "PhImageTool"
#pragma link "PhPaneTool"
#pragma link "PhRulerTool"
#pragma link "PhZoomToRectTool"
#pragma link "PhTriangleTool"
#pragma resource "*.dfm"
TForm10 *Form10;
//---------------------------------------------------------------------------
__fastcall TForm10::TForm10(TComponent* Owner)
	: TForm(Owner)
{

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
//
}
//---------------------------------------------------------------------------

void __fastcall TForm10::fileAnalysisActionUpdate(TObject *Sender)
{
	fileAnalysisAction->Enabled = FileListBox1->Items->Count > 0;
}
//---------------------------------------------------------------------------
// отображает в строке статуса число файлов в ListBox
void __fastcall TForm10::DirectoryListBox1Change(TObject *Sender)
{
	StatusBar1->Panels->Items[0]->Text = L"Число файлов: " + IntToStr(FileListBox1->Items->Count);
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
		TStringList* list = new TStringList();
		list->Add(FileListBox1->FileName);
		PhImage1->InitFile(FileListBox1->FileName);
		delete list;
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

	awpImage* img = NULL;
    PhImage1->GetAwpImage(&img);
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
//
}
//---------------------------------------------------------------------------

void __fastcall TForm10::toolsEditROIActionUpdate(TObject *Sender)
{
	toolsEditROIAction->Enabled = false;
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

void __fastcall TForm10::FormCreate(TObject *Sender)
{
    this->SpeedButton1->Caption = L"";
	this->SpeedButton2->Caption = L"";
	this->SpeedButton3->Caption = L"";
	this->SpeedButton4->Caption = L"";
}
//---------------------------------------------------------------------------

void __fastcall TForm10::PhImage1ToolChange(TObject *Sender)
{
	if (PhImage1->PhTool != NULL) {
	   UnicodeString strText = L"";
	   if (PhImage1->PhTool->ToolName == L"RULER") {
		  strText = L"ЛИНЕЙКА";
	   }
	   else if (PhImage1->PhTool->ToolName == L"ZOOM/PANE") {
		  strText = L"УВЕЛИЧНЕНИЕ/ПЕРЕМЕЩЕНИЕ";
	   }
	   else if (PhImage1->PhTool->ToolName == L"ZOOM TO RECT") {
		  strText = L"УВЕЛИЧНЕНИЕ ПРЯМОУГОЛЬНИКА";
	   }
	   else if (PhImage1->PhTool->ToolName == L"TRIANGLE") {
		  strText = L"ИЗМЕРЕНИЕ УГЛА";
	   }
	   StatusBar1->Panels->Items[4]->Text = L"Инструмент: " + strText;
	}
	else
		   StatusBar1->Panels->Items[4]->Text = L"Инструмент: НЕ ВЫБРАН";
}
//---------------------------------------------------------------------------

