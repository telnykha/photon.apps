//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop

#include "ExportVideoThread.h"
#include "LongProcessForm.h"

#include "awpcvvideo.h"
#include "mainUnit.h"

#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall TExportVideoThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall TExportVideoThread::TExportVideoThread(bool CreateSuspended)
	: TThread(CreateSuspended)
{
    OnTerminate = ThreadTerminate;
}
//---------------------------------------------------------------------------
void __fastcall TExportVideoThread::Execute()
{
    if (mainForm == NULL || mainForm->videoSource == NULL)
        return;

    AnsiString inputFile  = mainForm->videoSource->Source;
    UnicodeString str = this->outputName;
    str = ChangeFileExt(str, ".avi");
    AnsiString outputFile = str;

    HCVVIDEO     reader = awpcvConnect(inputFile.c_str());
    HCVVIDEOREC  writer = NULL;
    int pos = mainForm->PhTrackBar1->SelStart;
    m_total = mainForm->PhTrackBar1->SelEnd - mainForm->PhTrackBar1->SelStart;
    while(!Terminated)
    {
       awpImage* img = NULL;
       awpcvQueryImagePos(reader, &img, pos);
       // write frame
       if (writer == NULL)
          writer = awpcvCreateWriter(outputFile.c_str(), img);
        awpcvWriteFrame(writer, img);
	    awpcvFreeImage(img);

       pos++;
       m_pos = pos - mainForm->PhTrackBar1->SelStart;
       Synchronize(&UpdateStatus);

       if (pos > mainForm->PhTrackBar1->SelEnd)
        break;
    }

    awpcvDisconnect(reader);
    awpcvCloseWriter(writer);

}
//---------------------------------------------------------------------------
void __fastcall TExportVideoThread::UpdateStatus()
{
   LongProcDlg->Label2->Caption = L"Экспорт видео";
   UnicodeString str = L"Кадр ";
   str += IntToStr(m_pos);
   str += L" из ";
   str += IntToStr(m_total);
   LongProcDlg->Label1->Caption = str;
   LongProcDlg->ProgressBar1->Position = m_pos;
}
void __fastcall TExportVideoThread::ThreadTerminate(TObject* sender)
{
    LongProcDlg->Close();
}
