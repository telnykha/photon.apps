//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "LongProcessForm.h"
#include "mainUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TLongProcDlg *LongProcDlg;
//---------------------------------------------------------------------------
__fastcall TLongProcDlg::TLongProcDlg(TComponent* Owner)
	: TForm(Owner)
{
    m_tool = NULL;
    m_job = nothing;
}
//---------------------------------------------------------------------------
void __fastcall TLongProcDlg::ProgressHandler(TObject *Sender, int Progress, String& aComment)
{
	ProgressBar1->Position  = Progress;
	Label1->Caption =  aComment;
}
void __fastcall TLongProcDlg::FormShow( TObject *Sender)
{
  if (m_tool != NULL)
  {
      m_tool->OnProgress = ProgressHandler;
      Timer1->Enabled = true;
  }
}
//---------------------------------------------------------------------------

void __fastcall TLongProcDlg::Timer1Timer(TObject *Sender)
{
	Timer1->Enabled = false;
    m_tool->ExportToLFDatabase(m_str.c_str());
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TLongProcDlg::DoIt(TPhVideoMarkTool* tool, const char* path)
{
    m_tool = tool;
    m_str = path;
    m_job = exportToLFDatabase;
    ShowModal();
}

void __fastcall TLongProcDlg::DoExportVideo(UnicodeString fileName)
{
    ProgressBar1->Min = 0;
    ProgressBar1->Max = mainForm->PhTrackBar1->SelEnd - mainForm->PhTrackBar1->SelStart;
    ProgressBar1->Position = 0;

    TExportVideoThread* e = new TExportVideoThread(true);
    m_exportVideo = e;
    e->FreeOnTerminate = true;
    e->outputName = fileName;
    e->Start();
    ShowModal();
}

void __fastcall TLongProcDlg::FormClose(TObject *Sender, TCloseAction &Action)
{
    m_tool = NULL;
    m_job = nothing;
}
//---------------------------------------------------------------------------

void __fastcall TLongProcDlg::Button1Click(TObject *Sender)
{
    if (m_job == exportVideo)
    	m_exportVideo->Terminate();
    else if (m_job == exportImages)
        m_exportImages->Terminate();
}
//---------------------------------------------------------------------------
void __fastcall TLongProcDlg::DoExportImages(UnicodeString outDir, UnicodeString ext, int frequency)
{
    ProgressBar1->Min = 0;
    ProgressBar1->Max = (mainForm->PhTrackBar1->SelEnd - mainForm->PhTrackBar1->SelStart) / frequency;
    ProgressBar1->Position = 0;

    m_exportImages = new TExportImagesThread(true);
    m_exportImages->FreeOnTerminate = true;
    m_exportImages->outputName = outDir;
    m_exportImages->frequency = frequency;
    m_exportImages->ext = ext;
    m_exportImages->Start();
    ShowModal();
}

