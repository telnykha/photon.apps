//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "mainUnit.h"
#include "PhVideo.h"
#include "PhSlideShow.h"
#include "dictinaryEditor.h"
#include "LongProcessForm.h"
#include "AboutForm.h"
#include "VerInfoUnit.h"
#include "awpcvvideo.h"

//#include "ExportVideoThread.h"
#include "exportImagesOptionsUnit.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FImage41"
#pragma link "PhTrackBar"
#pragma link "PhImageTool"
#pragma link "PhLenzTool"
#pragma link "PhPaneTool"
#pragma link "PhSelectRectTool"
#pragma link "PhZoomToRectTool"
#pragma link "PhRulerTool"
#pragma resource "*.dfm"

extern "C"
{
    #pragma link "awpipl2b.lib"
    #pragma link "JPEGLIB.lib"
}
#pragma link "awplflibb.lib"


const UnicodeString cstrVideos = L"Avi videos|*.avi";


TmainForm *mainForm;

//---------------------------------------------------------------------------
#define _CHECK_SOURCE_     \
if (m_videoSource == NULL) \
    return;                \

#define _NAV_ENABLED_(v) \
    v->Enabled = m_videoSource != NULL && m_videoSource->NumFrames > 1 && !this->m_videoSource->IsPlaying;



//---------------------------------------------------------------------------
__fastcall TmainForm::TmainForm(TComponent* Owner)
	: TForm(Owner)
{
	m_markTool = NULL;
}
//---------------------------------------------------------------------------
void __fastcall TmainForm::SetSource(TPhMediaSource* source)
{
   if (m_videoSource != NULL)
   {
      delete m_videoSource;
      m_videoSource = NULL;
   }

    PhTrackBar1->SelStart = 0;
    PhTrackBar1->SelEnd = 0;


   m_videoSource = source;
   if (m_videoSource  != NULL)
   {
	   StatusBar1->Panels->Items[2]->Text = L"Источник данных: " + m_videoSource->SourceName;
       UnicodeString cap = L"photon.base [";
       cap += m_videoSource->Source;
       cap  += L"]";
       this->Caption = cap;

        PhTrackBar1->Min = 0;
        PhTrackBar1->Max = m_videoSource->NumFrames;
        PhTrackBar1->Frequency = m_videoSource->NumFrames / 50;
        m_videoSource->First();
   }
   else
   {
        PhTrackBar1->Min = 0;
        PhTrackBar1->Max = 0;
        PhTrackBar1->Frequency = 10;


	   StatusBar1->Panels->Items[1]->Text = L"";
	   StatusBar1->Panels->Items[2]->Text = L"Источник данных: NULL";
       this->Caption = L"photon.base";
   }
}
//---------------------------------------------------------------------------
void __fastcall TmainForm::fileExitActionExecute(TObject *Sender)
{
	 if (m_markTool != NULL)
		delete m_markTool;
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TmainForm::PhImage1AfterOpen(TObject *Sender)
{
    PhImage1->BestFit();
}
//---------------------------------------------------------------------------
void __fastcall TmainForm::fileOpenImageActionExecute(TObject *Sender)
{
	String cstrImages = "Jpeg images|*.jpeg;*.jpg|AWP images|*.awp";
    OpenDialog1->Filter = cstrImages;
    if (OpenDialog1->Execute())
    {
        TPhMediaSource* videoSource = new TPhSlideShowSource(PhImage1);
        videoSource->Open(OpenDialog1->Files);
        this->SetSource(videoSource);
    }
}
//---------------------------------------------------------------------------

void __fastcall TmainForm::navFirstActionExecute(TObject *Sender)
{
    _CHECK_SOURCE_
    m_videoSource->First();
}
//---------------------------------------------------------------------------

void __fastcall TmainForm::navFirstActionUpdate(TObject *Sender)
{
     _NAV_ENABLED_(navFirstAction)
}
//---------------------------------------------------------------------------

void __fastcall TmainForm::navPrevActionExecute(TObject *Sender)
{
    _CHECK_SOURCE_
    m_videoSource->Prev();
}
//---------------------------------------------------------------------------

void __fastcall TmainForm::navPrevActionUpdate(TObject *Sender)
{
     _NAV_ENABLED_(navPrevAction)
}
//---------------------------------------------------------------------------

void __fastcall TmainForm::navNextActionExecute(TObject *Sender)
{
	_CHECK_SOURCE_
	m_videoSource->Next();
}
//---------------------------------------------------------------------------

void __fastcall TmainForm::navNextActionUpdate(TObject *Sender)
{
     _NAV_ENABLED_(navNextAction)
}
//---------------------------------------------------------------------------

void __fastcall TmainForm::navLastActionExecute(TObject *Sender)
{
    _CHECK_SOURCE_
    m_videoSource->Last();
}
//---------------------------------------------------------------------------

void __fastcall TmainForm::navLastActionUpdate(TObject *Sender)
{
      _NAV_ENABLED_(navLastAction)
}
//---------------------------------------------------------------------------

void __fastcall TmainForm::navPlayActionExecute(TObject *Sender)
{
    Timer2->Enabled = false;
	_CHECK_SOURCE_
    if (!m_videoSource->IsPlaying)
    {
	    m_videoSource->Play();
        navPlayAction->Caption = L"Стоп";
        SpeedButton9->Down = true;
    }
    else
    {
        m_videoSource->Stop();
        navPlayAction->Caption = L"Воспроизвести";
        SpeedButton9->Down = false;
        Timer1->Enabled = false;
    }
}
//---------------------------------------------------------------------------

void __fastcall TmainForm::navPlayActionUpdate(TObject *Sender)
{
    navPlayAction->Enabled = m_videoSource != NULL && (m_videoSource->NumFrames > 1 || m_videoSource->NumFrames == 0);
}
//---------------------------------------------------------------------------


void __fastcall TmainForm::PhTrackBar1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
   _CHECK_SOURCE_
   m_videoSource->CurrentFrame = PhTrackBar1->Position;
}
//---------------------------------------------------------------------------

void __fastcall TmainForm::fileCloseActionExecute(TObject *Sender)
{
    PhImage1->Close();
	PhImage1->Refresh();
    this->SetSource(NULL);
}
//---------------------------------------------------------------------------

void __fastcall TmainForm::fileOpenVideoActionExecute(TObject *Sender)
{
	String cstrVideos = "Videos |*.avi;*.mp4;*.mpg;|Avi videos|*.avi;|MP4 videos|*.mp4|mpeg files|*.mpg";
    OpenDialog1->Filter = cstrVideos;
    if (OpenDialog1->Execute())
    {
        TPhMediaSource* videoSource= new TPhVideoSource(PhImage1);
        videoSource->Open(OpenDialog1->Files);
        if (videoSource->NumFrames == 0)
        {
            ShowMessage(L"Не могу открыть файл: " + OpenDialog1->FileName);
            SetSource(NULL);
            return;
        }
        else
        {
			if (m_markTool != NULL)
				delete m_markTool;
			toolsPaneActionExecute(NULL);
			SetSource(videoSource);
		}
    }

}
//---------------------------------------------------------------------------
static String RectToString(TRect& rect)
{
	String str = IntToStr((int)rect.Left);
	str+= L":";
	str+= IntToStr((int)rect.top);
	str+= L":";
	str+= IntToStr((int)rect.Width());
	str+= L":";
	str+= IntToStr((int)rect.Height());
	return str;
}

void __fastcall TmainForm::PhImage1FrameData(TObject *Sender, int w, int h, int c, BYTE *data)
{
   _CHECK_SOURCE_
    if (m_videoSource != NULL)
    {
		StatusBar1->Panels->Items[1]->Text = L"Кадр "  + IntToStr( m_videoSource->CurrentFrame) +
   		" of " + IntToStr(m_videoSource->NumFrames);
	    StatusBar1->Panels->Items[3]->Text = L"Изображение: " + IntToStr(w) + L":" + IntToStr(h) + L":" + IntToStr(c);
    }
    else
		StatusBar1->Panels->Items[1]->Text = L" ";

   PhTrackBar1->Position =  m_videoSource->CurrentFrame;

	if (dynamic_cast< TPhVideoMarkTool*>(PhImage1->PhTool) != NULL)
	{
		 TPhVideoMarkTool* t = dynamic_cast< TPhVideoMarkTool*>(PhImage1->PhTool);
		 t->NewFrame(CheckBox1->Checked);
		 ListView2->Clear();
		 TLFObjectList* list = t->data;
		 for (int i = 0; i < list->GetCount(); i++)
		 {
			TLFDetectedItem* mi = (TLFDetectedItem*)list->Get(i);
			TListItem* item = ListView2->Items->Add();
			item->Caption = IntToStr(i+1);
			item->SubItems->Add(mi->GetType().c_str());
//			item->SubItems->Add(RectToString(mi->rect));
		 }
	}
}
//---------------------------------------------------------------------------

void __fastcall TmainForm::FormCreate(TObject *Sender)
{
    Caption = ExtractFileName(Application->ExeName);
}
//---------------------------------------------------------------------------

void __fastcall TmainForm::helpAboutActionExecute(TObject *Sender)
{
  TVersionInfo* vi = new TVersionInfo(NULL);
  AboutBox->ProductName->Caption = vi->ProductName;
  AboutBox->Version->Caption = vi->FileVersion;
  AboutBox->Copyright->Caption = vi->LegalCopyright;
  //AboutBox->Label1->Caption = vi->Comments;
  String str = ExtractFilePath(Application->ExeName);
  AboutBox->Memo1->Lines->LoadFromFile(str + L"\\license_videomarker.txt");
  AboutBox->ShowModal();
  delete vi;

//    AboutBox->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TmainForm::toolsPaneActionExecute(TObject *Sender)
{
	  Timer2->Enabled = false;
      PhImage1->SelectPhTool(PhPaneTool1);
}
//---------------------------------------------------------------------------

void __fastcall TmainForm::toolsPaneActionUpdate(TObject *Sender)
{
	toolsPaneAction->Enabled = !PhImage1->Empty;
	toolsPaneAction->Checked =  dynamic_cast< TPhPaneTool*>(PhImage1->PhTool) != NULL;
}
//---------------------------------------------------------------------------

void __fastcall TmainForm::toolsZoomActionExecute(TObject *Sender)
{
         PhImage1->SelectPhTool(PhZoomToRectTool1);
}
//---------------------------------------------------------------------------

void __fastcall TmainForm::toolsZoomActionUpdate(TObject *Sender)
{
	toolsZoomAction->Enabled = !PhImage1->Empty;
	toolsZoomAction->Checked = dynamic_cast< TPhZoomToRectTool*>(PhImage1->PhTool) != NULL;
}
//---------------------------------------------------------------------------

void __fastcall TmainForm::toolsLenzActionExecute(TObject *Sender)
{
	PhImage1->SelectPhTool(PhLenzTool1);
}
//---------------------------------------------------------------------------

void __fastcall TmainForm::toolsLenzActionUpdate(TObject *Sender)
{
	toolsLenzAction->Enabled = !PhImage1->Empty;
	toolsLenzAction->Checked =  dynamic_cast< TPhLenzTool*>(PhImage1->PhTool) != NULL;
}
//---------------------------------------------------------------------------

void __fastcall TmainForm::toolsSelectRectActionExecute(TObject *Sender)
{
	PhImage1->SelectPhTool(PhSelRectTool1);
}
//---------------------------------------------------------------------------

void __fastcall TmainForm::toolsSelectRectActionUpdate(TObject *Sender)
{
	toolsSelectRectAction->Enabled = !PhImage1->Empty;
	toolsSelectRectAction->Checked = dynamic_cast< TPhSelRectTool*>(PhImage1->PhTool) != NULL;
}
//---------------------------------------------------------------------------

void __fastcall TmainForm::editCopyActionExecute(TObject *Sender)
{
	PhImage1->SaveToClipBoard();
}
//---------------------------------------------------------------------------

void __fastcall TmainForm::editCopyActionUpdate(TObject *Sender)
{
	editCopyAction->Enabled = !PhImage1->Empty;
}
//---------------------------------------------------------------------------
void __fastcall TmainForm::editClearSelectionActionExecute(TObject *Sender)
{
    PhTrackBar1->SelStart = 0;
    PhTrackBar1->SelEnd = 0;

	PhImage1->ClearSelection();
	if (PhImage1->Mosaic)
        PhImage1->Frames->ClearSelection();
}
//---------------------------------------------------------------------------

void __fastcall TmainForm::editClearSelectionActionUpdate(TObject *Sender)
{
    int d =  PhTrackBar1->SelEnd - PhTrackBar1->SelStart;
	editClearSelectionAction->Enabled = PhImage1->HasSelection() || d > 0;
}
//---------------------------------------------------------------------------

void __fastcall TmainForm::viewBestFitActionExecute(TObject *Sender)
{
	PhImage1->BestFit();
}
//---------------------------------------------------------------------------

void __fastcall TmainForm::viewBestFitActionUpdate(TObject *Sender)
{
	viewBestFitAction->Enabled = !PhImage1->Empty;
}
//---------------------------------------------------------------------------

void __fastcall TmainForm::viewActualSizeActionExecute(TObject *Sender)
{
 	PhImage1->ActualSize();
}
//---------------------------------------------------------------------------

void __fastcall TmainForm::viewActualSizeActionUpdate(TObject *Sender)
{
 	viewActualSizeAction->Enabled = !PhImage1->Empty;
}
//---------------------------------------------------------------------------
void __fastcall TmainForm::toolsMarkFrameActionExecute(TObject *Sender)
{
	m_markTool = new TPhVideoMarkTool(NULL);
	m_markTool->PhImage = PhImage1;
	m_markTool->OnChange = ToolChange;
	m_markTool->OnAddData = ToolAddData;
	m_markTool->OnLoad = ToolLoad;
	m_markTool->OnDelFrame = ToolDelFrame;

	PhImage1->SelectPhTool(m_markTool);
}
//---------------------------------------------------------------------------

void __fastcall TmainForm::toolsMarkFrameActionUpdate(TObject *Sender)
{
	toolsMarkFrameAction->Enabled = !PhImage1->Empty;
	toolsMarkFrameAction->Checked = dynamic_cast< TPhVideoMarkTool*>(PhImage1->PhTool) != NULL;
}
//---------------------------------------------------------------------------

void __fastcall TmainForm::PhImage1ToolChange(TObject *Sender)
{
	if (dynamic_cast< TPhVideoMarkTool*>(PhImage1->PhTool) != NULL)
	{
		Panel1->Visible = true;
		m_markTool->MediaSource = m_videoSource;
		PhImage1->PopupMenu = NULL;
		// fill frames list box
		// режим отоборажения.
		String strName = ChangeFileExt(m_videoSource->Source, L".mark");
		if (FileExists(strName))
		{
			//ShowMessage("разметка присутствует!");
			m_markTool->LoadData();
		}
		else
		{
			//ShowMessage("разметка отсутствует!");
			TPhVideoMarkTool* t = dynamic_cast< TPhVideoMarkTool*>(PhImage1->PhTool);
			if (!dictinaryEditDlg->Process(t))
			  toolsPaneActionExecute(NULL);
		}

	}
	else
	{
		Panel1->Visible = false;
        PhImage1->PopupMenu = this->PopupMenu1;
	}
}
//---------------------------------------------------------------------------
void __fastcall TmainForm::UpdateFramesList()
{

}

void __fastcall TmainForm::Button3Click(TObject *Sender)
{
	if (dynamic_cast< TPhVideoMarkTool*>(PhImage1->PhTool) != NULL)
	{
		 PhImage1->PhTool->Reset();
	}
}
//---------------------------------------------------------------------------
void __fastcall TmainForm::ToolChange(TObject *Sender)
{
	if (dynamic_cast< TPhVideoMarkTool*>(PhImage1->PhTool) != NULL)
	{
		 TPhVideoMarkTool* t = dynamic_cast< TPhVideoMarkTool*>(PhImage1->PhTool);
		 ListView2->Clear();
		 TLFObjectList* list = t->data;
		 for (int i = 0; i < list->GetCount(); i++)
		 {
			TLFDetectedItem* mi = (TLFDetectedItem*)list->Get(i);
			TListItem* item = ListView2->Items->Add();
			item->Caption = IntToStr(i+1);
			item->SubItems->Add(mi->GetType().c_str());
		 }
		 for (int i = 0; i < t->frames->GetCount(); i++)
		 {
			 TFrameItem* fi = (TFrameItem*)t->frames->Get(i);
			 if (fi->FrameNum == m_videoSource->CurrentFrame)
			 {
				 TListItem* itm = ListView1->Items->Item[i];
				 itm->SubItems->Strings[0] = IntToStr(list->GetCount());
				 break;
			 }
		 }

	}
}

void __fastcall TmainForm::Button1Click(TObject *Sender)
{
	if (dynamic_cast< TPhVideoMarkTool*>(PhImage1->PhTool) != NULL)
	{
		 TPhVideoMarkTool* t = dynamic_cast< TPhVideoMarkTool*>(PhImage1->PhTool);
		 t->SaveData();
	}
}
//---------------------------------------------------------------------------

void __fastcall TmainForm::ToolAddData(TObject *Sender, TFrameItem* item)
{
	TListItem* itm = ListView1->Items->Add();
	itm->Caption = IntToStr(item->FrameNum);
	itm->SubItems->Add(IntToStr(item->GetCount()));
}

void __fastcall TmainForm::ListView1SelectItem(TObject *Sender, TListItem *Item, bool Selected)

{
	if (dynamic_cast< TPhVideoMarkTool*>(PhImage1->PhTool) != NULL)
	{
		 TPhVideoMarkTool* t = dynamic_cast< TPhVideoMarkTool*>(PhImage1->PhTool);
		 t->SetFrame(ListView1->ItemIndex);
	}
}
//---------------------------------------------------------------------------
void __fastcall TmainForm::ToolLoad(TObject *Sender)
{
	TPhVideoMarkTool* t = dynamic_cast< TPhVideoMarkTool*>(PhImage1->PhTool);

	ListView1->Clear();
	ListView2->Clear();
	TLFObjectList* frames = t->frames;
	for (int i = 0; i < frames->GetCount(); i++)
	{
		TFrameItem* item = (TFrameItem*)frames->Get(i);
		TListItem* itm = ListView1->Items->Add();
		itm->Caption = IntToStr(item->FrameNum);
		itm->SubItems->Add(IntToStr(item->GetCount()));
	}
}

void __fastcall TmainForm::Button2Click(TObject *Sender)
{
	//
	if (SaveDialog1->Execute())
	{
		TPhVideoMarkTool* t = dynamic_cast< TPhVideoMarkTool*>(PhImage1->PhTool);
		AnsiString _ansi = ExtractFilePath(SaveDialog1->FileName);
        LongProcDlg->DoIt(t, _ansi.c_str());
        ShowMessage(L"Экспорт завершен.");
	}
}
//---------------------------------------------------------------------------

void __fastcall TmainForm::N31Click(TObject *Sender)
{
	if (ListView1->ItemIndex >= 0)
	{
		TListItem* item = ListView1->Selected;
		int frame = StrToInt(item->Caption);
		TPhVideoMarkTool* t = dynamic_cast< TPhVideoMarkTool*>(PhImage1->PhTool);
		t->DeleteEntry(frame);
        t->SaveData();
		ListView1->DeleteSelected();
        m_videoSource->Next();
	}
}
//---------------------------------------------------------------------------

void __fastcall TmainForm::Button4Click(TObject *Sender)
{
	TPhVideoMarkTool* t = dynamic_cast< TPhVideoMarkTool*>(PhImage1->PhTool);
	if (dictinaryEditDlg->Process(t))
    {
        PhImage1->Paint();
    }
}
//---------------------------------------------------------------------------

void __fastcall TmainForm::ListView2SelectItem(TObject *Sender, TListItem *Item, bool Selected)

{
	if (dynamic_cast< TPhVideoMarkTool*>(PhImage1->PhTool) != NULL)
	{
		 TPhVideoMarkTool* t = dynamic_cast< TPhVideoMarkTool*>(PhImage1->PhTool);
		 t->SetSelected(ListView2->ItemIndex);
	}
}
//---------------------------------------------------------------------------

void __fastcall TmainForm::N32Click(TObject *Sender)
{
 	if (ListView2->ItemIndex >= 0)
	{
		TPhVideoMarkTool* t = dynamic_cast< TPhVideoMarkTool*>(PhImage1->PhTool);
		t->DeleteObject(ListView2->ItemIndex);
		ListView2->DeleteSelected();
	}
}
//---------------------------------------------------------------------------

void __fastcall TmainForm::N33Click(TObject *Sender)
{
    //
	TPhVideoMarkTool* t = dynamic_cast< TPhVideoMarkTool*>(PhImage1->PhTool);
    t->SortData();
	ToolLoad(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TmainForm::ToolDelFrame(TObject *Sender, TFrameItem* item)
{
   for (int i = 0; i < ListView1->Items->Count; i++)
   {
	TListItem* itm = ListView1->Items->Item[i];
	int index = StrToInt(itm->Caption);
    if (item->FrameNum == index)
    {
        ListView1->Items->Delete(i);
        break;
    }

   }
}
//---------------------------------------------------------------------------

void __fastcall TmainForm::editStartSelActionExecute(TObject *Sender)
{
	  PhTrackBar1->SelStart = PhTrackBar1->Position;
}
//---------------------------------------------------------------------------

void __fastcall TmainForm::editStartSelActionUpdate(TObject *Sender)
{
    editStartSelAction->Enabled = m_videoSource != NULL && (m_videoSource->NumFrames > 1);
}
//---------------------------------------------------------------------------

void __fastcall TmainForm::editEndSelActionExecute(TObject *Sender)
{
	PhTrackBar1->SelEnd = PhTrackBar1->Position;
}
//---------------------------------------------------------------------------

void __fastcall TmainForm::editEndSelActionUpdate(TObject *Sender)
{
    editEndSelAction->Enabled = m_videoSource != NULL && (m_videoSource->NumFrames > 1);
}
//---------------------------------------------------------------------------

void __fastcall TmainForm::editSelToStartActionExecute(TObject *Sender)
{
   _CHECK_SOURCE_
   m_videoSource->CurrentFrame = PhTrackBar1->SelStart;
}
//---------------------------------------------------------------------------

void __fastcall TmainForm::editSelToStartActionUpdate(TObject *Sender)
{
    int d =  PhTrackBar1->SelEnd - PhTrackBar1->SelStart;
    editSelToStartAction->Enabled = m_videoSource != NULL && (m_videoSource->NumFrames > 1) && d > 1;
}
//---------------------------------------------------------------------------

void __fastcall TmainForm::editSelToEndActionExecute(TObject *Sender)
{
   _CHECK_SOURCE_
   m_videoSource->CurrentFrame = PhTrackBar1->SelEnd;
}
//---------------------------------------------------------------------------

void __fastcall TmainForm::editSelToEndActionUpdate(TObject *Sender)
{
    int d =  PhTrackBar1->SelEnd - PhTrackBar1->SelStart;
    editSelToEndAction->Enabled = m_videoSource != NULL && (m_videoSource->NumFrames > 1) && d > 1;
}
//---------------------------------------------------------------------------

void __fastcall TmainForm::editSelPlayActionExecute(TObject *Sender)
{
	_CHECK_SOURCE_
    m_videoSource->CurrentFrame = PhTrackBar1->SelStart;
    Timer1->Enabled = true;
    navPlayActionExecute(NULL);
}
//---------------------------------------------------------------------------

void __fastcall TmainForm::editSelPlayActionUpdate(TObject *Sender)
{
    int d =  PhTrackBar1->SelEnd - PhTrackBar1->SelStart;
    editSelPlayAction->Enabled = m_videoSource != NULL && (m_videoSource->NumFrames > 1) && d > 1 && !this->m_videoSource->IsPlaying;
}
//---------------------------------------------------------------------------

void __fastcall TmainForm::Timer1Timer(TObject *Sender)
{
  if (m_videoSource->CurrentFrame > PhTrackBar1->SelEnd)
  {
      Timer1->Enabled = false;
      navPlayActionExecute(NULL);
  }
}
//---------------------------------------------------------------------------

void __fastcall TmainForm::fileExportVideoActionExecute(TObject *Sender)
{
    _CHECK_SOURCE_
    SaveDialog1->Filter = cstrVideos;
    if (SaveDialog1->Execute())
    {
     	LongProcDlg->DoExportVideo(SaveDialog1->FileName);
    }
    SaveDialog1->Filter = L"";
}
//---------------------------------------------------------------------------

void __fastcall TmainForm::fileExportVideoActionUpdate(TObject *Sender)
{
    int d =  PhTrackBar1->SelEnd - PhTrackBar1->SelStart;
    fileExportVideoAction->Enabled = m_videoSource != NULL && (m_videoSource->NumFrames > 1) && d > 1;
}
//---------------------------------------------------------------------------


void __fastcall TmainForm::fileExportImagesActionExecute(TObject *Sender)
{
    if (exportImagesDlg->ShowModal() == mrOk)
    {
        if (!DirectoryExists(exportImagesDlg->exportDir))
        {
            if (!CreateDir(exportImagesDlg->exportDir))
            {
                UnicodeString str = L"Не могу создать папку: ";
                str += exportImagesDlg->exportDir;
                ShowMessage(str);
                return;
            }
        }

        LongProcDlg->DoExportImages(exportImagesDlg->exportDir, exportImagesDlg->ext, exportImagesDlg->value);
    }
}
//---------------------------------------------------------------------------

void __fastcall TmainForm::fileExportImagesActionUpdate(TObject *Sender)
{
    int d =  PhTrackBar1->SelEnd - PhTrackBar1->SelStart;
    fileExportImagesAction->Enabled = m_videoSource != NULL && (m_videoSource->NumFrames > 1) && d > 1;
}
//---------------------------------------------------------------------------
void __fastcall TmainForm::SpeedButton11Click(TObject *Sender)
{
	TPhVideoMarkTool* t = dynamic_cast< TPhVideoMarkTool*>(PhImage1->PhTool);
    if (t == NULL)
        return;
    m_selIndex = 0;
    Timer2->Enabled = !Timer2->Enabled;
}
//---------------------------------------------------------------------------

void __fastcall TmainForm::Timer2Timer(TObject *Sender)
{
	TPhVideoMarkTool* t = dynamic_cast< TPhVideoMarkTool*>(PhImage1->PhTool);
    t->SetFrame(m_selIndex);
    this->m_selIndex++;
    if (this->m_selIndex > t->frames->GetCount())
          m_selIndex = 0;
}
//---------------------------------------------------------------------------


void __fastcall TmainForm::toolsRulerActionExecute(TObject *Sender)
{
	PhImage1->SelectPhTool(PhRulerTool1);
}
//---------------------------------------------------------------------------

void __fastcall TmainForm::toolsRulerActionUpdate(TObject *Sender)
{
	toolsRulerAction->Enabled = !PhImage1->Empty;
	toolsRulerAction->Checked = dynamic_cast< TPhRulerTool*>(PhImage1->PhTool) != NULL;}
//---------------------------------------------------------------------------



void __fastcall TmainForm::SpeedButton5Click(TObject *Sender)
{
    m_markTool->Mode = MTRect;
}
//---------------------------------------------------------------------------

void __fastcall TmainForm::SpeedButton6Click(TObject *Sender)
{
	m_markTool->Mode = MTVector;
}
//---------------------------------------------------------------------------

void __fastcall TmainForm::SpeedButton13Click(TObject *Sender)
{
	m_markTool->Mode = MTContour;
}
//---------------------------------------------------------------------------

