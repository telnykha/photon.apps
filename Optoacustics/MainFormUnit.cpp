//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainFormUnit.h"
#include "FormTableUnit.h"
#include "Form3DUnit.h"
#include "FormBimaryUnit.h"
#include "FormResultUnit.h"
#include "FormLongProcessUnit.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FImage41"
#pragma link "PhImageTool"
#pragma link "PhPaneTool"
#pragma resource "*.dfm"

extern "C"
{
	#pragma link "awpipl2b.lib"
	#pragma link "tifflib.lib"
	#pragma link "zlib.lib"
	#pragma link "JPEGLIB.lib"
}

#pragma link "awplflibb.lib"
#pragma link "TinyXML.lib"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
	tif = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::fileCloseActionExecute(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::fileOpenActionExecute(TObject *Sender)
{
	if(OpenDialog1->Execute())
	{
		AnsiString _ansi = OpenDialog1->FileName;
		if(!OpenTIFFImage(_ansi.c_str()))
		{
			ShowMessage(L"Cannot open file:" + OpenDialog1->FileName);
			return;
		}
		LongProcessForm->ShowModal();
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::fileCloseImageActionExecute(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::fileCloseImageActionUpdate(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::view3DReconstructionActionExecute(TObject *Sender)
{
	Form3DView->Visible = !Form3DView->Visible;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::view3DReconstructionActionUpdate(TObject *Sender)
{
	view3DReconstructionAction->Checked = Form3DView->Visible;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::viewClustersTableActionUpdate(TObject *Sender)
{
	viewClustersTableAction->Checked = FormTableView->Visible;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::viewClustersTableActionExecute(TObject *Sender)
{
	FormTableView->Visible = !FormTableView->Visible;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::viewBinaryActionExecute(TObject *Sender)
{
	FormBinaryView->Visible = !FormBinaryView->Visible;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::viewBinaryActionUpdate(TObject *Sender)
{
	viewBinaryAction->Checked = FormBinaryView->Visible;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::viewResultActionExecute(TObject *Sender)
{
	FormResultView->Visible = !FormResultView->Visible;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::viewResultActionUpdate(TObject *Sender)
{
	viewResultAction->Checked = FormResultView->Visible;
}
//---------------------------------------------------------------------------
void TMainForm::ShowLeftDockPanel(TWinControl* APanel, bool MakeVisible, TControl* Client)
{
  if (APanel == NULL || (!MakeVisible && (APanel->VisibleDockClientCount > 1)))
    return;
  if (MakeVisible)
  {
	  APanel->Width = ClientWidth / 3;
  }
  else
  {
	  APanel->Width = 5;
  }

  if (MakeVisible && (Client != NULL))
	Client->Show();
}




void __fastcall TMainForm::LeftDocPanelDockOver(TObject *Sender, TDragDockObject *Source,
          int X, int Y, TDragState State, bool &Accept)
{
   Accept = (Source->Control) != NULL;
  if (Accept)
  {
	// Modify the DockRect to preview dock area.
	Types::TPoint TopLeft = LeftDocPanel->ClientToScreen(Point(0, 0));
	Types::TPoint BottomRight = LeftDocPanel->ClientToScreen(Point(PhImage1->Width / 3, LeftDocPanel->Height));
	Source->DockRect = Types::TRect(TopLeft, BottomRight);
  }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::LeftDocPanelDockDrop(TObject *Sender, TDragDockObject *Source,
          int X, int Y)
{
	ShowLeftDockPanel(LeftDocPanel, true, NULL);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::LeftDocPanelUnDock(TObject *Sender, TControl *Client, TWinControl *NewTarget,
		  bool &Allow)
{
	 ShowLeftDockPanel(LeftDocPanel, false, NULL);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::RightDocPanelDockOver(TObject *Sender, TDragDockObject *Source,
          int X, int Y, TDragState State, bool &Accept)
{
   Accept = (Source->Control) != NULL;
  if (Accept)
  {
	// Modify the DockRect to preview dock area.
	Types::TPoint TopLeft = LeftDocPanel->ClientToScreen(Point(Width, 0));
	Types::TPoint BottomRight = LeftDocPanel->ClientToScreen(Point(Width - PhImage1->Width / 3, RightDocPanel->Height));
	Source->DockRect = Types::TRect(TopLeft, BottomRight);
  }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::RightDocPanelDockDrop(TObject *Sender, TDragDockObject *Source,
		  int X, int Y)
{
	ShowLeftDockPanel(RightDocPanel, true, NULL);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::RightDocPanelUnDock(TObject *Sender, TControl *Client,
		  TWinControl *NewTarget, bool &Allow)
{
	ShowLeftDockPanel(RightDocPanel, false, NULL);
}
//---------------------------------------------------------------------------
// 1. Открывает многостраничное изображение TIFF и записвает все станицы во
// временную папку
// 2. Затем открывает папку с использованием PhImage

#define TIFF_NUM_DIRS 281
#define TIFF_WIDTH    500
#define TIFF_HEIGHT   500

bool TMainForm::OpenTIFFImage(const char* fileName)
{
	tif = NULL;
	tif = TIFFOpen(fileName, "r");
	if (tif == NULL)
		return false;
	int dircount = 0;
	do {
		dircount++;
	} while (TIFFReadDirectory(tif));
	if (dircount != TIFF_NUM_DIRS)
		return false;
	return true;
}

bool TMainForm::DecodeTIFF()
{
	AnsiString outDir = "C:\\_alt\\test_tiff\\";
	LongProcessForm->Label1->Caption = L"Decoding data...";
	LongProcessForm->CGauge1->MaxValue = TIFF_NUM_DIRS;
	awpImage* img = NULL;
	awpCreateImage(&img, TIFF_WIDTH, TIFF_HEIGHT, 1, AWP_BYTE);
	TStringList* list = new TStringList();
	for (int i = 0; i < TIFF_NUM_DIRS; i++)
	{
		AWPBYTE* p = (AWPBYTE*)img->pPixels;
		if (TIFFSetDirectory(tif, i) == 0)
			return false;
		Application->ProcessMessages();
		for(int j = 0; j < TIFF_HEIGHT; j++)
		{
			if ( TIFFReadScanline(tif, p, j)== -1 )
				throw Exception( "Reading file error" );
			p +=  TIFF_WIDTH;
		}
		AnsiString s = outDir + IntToStr(i) + ".awp";
		awpSaveImage(s.c_str(), img);
		LongProcessForm->CGauge1->Progress = i;
		list->Add(s);
	}
	awpReleaseImage(&img);
	TIFFClose(tif);
	tif = NULL;
	LongProcessForm->CGauge1->MaxValue = 100;

	PhImage1->Init(list);
	//delete list;
	return true;
}

void __fastcall TMainForm::PhImage1Finish(TObject *Sender, EPhJobReason reason, bool Cancel)

{
	LongProcessForm->Close();
	//PhImage1->Mosaic = true;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::PhImage1Progress(TObject *Sender, UnicodeString &strMessage,
		  int Progress)
{
	LongProcessForm->Label1->Caption = strMessage;
	LongProcessForm->CGauge1->Progress = Progress;
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::viewFirstActionExecute(TObject *Sender)
{
	PhImage1->Frames->First();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::viewFirstActionUpdate(TObject *Sender)
{
	viewFirstAction->Enabled = PhImage1->Frames->Count > 0;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::viewPrevActionExecute(TObject *Sender)
{
	PhImage1->Frames->Prev();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::viewPrevActionUpdate(TObject *Sender)
{
		viewPrevAction->Enabled = PhImage1->Frames->Count > 0;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::viewNextActionExecute(TObject *Sender)
{
	PhImage1->Frames->Next();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::viewNextActionUpdate(TObject *Sender)
{
	viewNextAction->Enabled = PhImage1->Frames->Count > 0;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::viewLastActionExecute(TObject *Sender)
{
	PhImage1->Frames->Last();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::viewLastActionUpdate(TObject *Sender)
{
	viewLastAction->Enabled = PhImage1->Frames->Count > 0;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::viewPlayActionExecute(TObject *Sender)
{
     PhImage1->SlideShowInterval = 100;
	 this->PhImage1->SlideShow = !this->PhImage1->SlideShow;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::viewPlayActionUpdate(TObject *Sender)
{
	viewPlayAction->Enabled = PhImage1->Frames->Count > 0;
    viewPlayAction->Checked = PhImage1->SlideShow;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::PhImage1AfterOpen(TObject *Sender)
{
    PhImage1->BestFit();
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::PhImage1FrameData(TObject *Sender, int w, int h, int c,
          BYTE *data)
{
	//
	awpImage* img = NULL;
	awpCreateImage(&img, w,h, c, AWP_BYTE);
	memcpy(img->pPixels, data, w*h*c*sizeof(AWPBYTE));

	m_p.SetImage(img);
	FormBinaryView->PhImage1->SetAwpImage(m_p.GetImage());
	FormBinaryView->PhImage1->BestFit();
	awpReleaseImage(&img);
}
//---------------------------------------------------------------------------

