//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop

#include "ExportImagesThread.h"
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
//      void __fastcall TExportImagesThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall TExportImagesThread::TExportImagesThread(bool CreateSuspended)
	: TThread(CreateSuspended)
{
     OnTerminate = ThreadTerminate;
     ext = L".jpg";
}
//---------------------------------------------------------------------------
void __fastcall TExportImagesThread::Execute()
{
    if (mainForm == NULL || mainForm->videoSource == NULL)
        return;

    AnsiString inputFile  = mainForm->videoSource->Source;
    AnsiString outputDir  = this->outputName;

    HCVVIDEO     reader = awpcvConnect(inputFile.c_str());
    int pos = mainForm->PhTrackBar1->SelStart;
    m_total = (mainForm->PhTrackBar1->SelEnd - mainForm->PhTrackBar1->SelStart) / frequency;
    int count = 0;
    while(!Terminated)
    {
       char buffer[32];
       awpImage* img = NULL;
       awpcvQueryImagePos(reader, &img, pos);
       AnsiString strFileName = outputDir;
       strFileName += "frame_";
       sprintf(buffer, "%06i", pos);
       strFileName += buffer;//IntToStr(pos);
       strFileName += ext;
       if (ext == L".awp")
    	   awpSaveImage(strFileName.c_str(), img);
       else
	       awpcvSaveImage(strFileName.c_str(), img);
       awpcvFreeImage(img);

       pos += this->frequency;
       count++;
       m_pos = count;
       Synchronize(&UpdateStatus);

       if (pos > mainForm->PhTrackBar1->SelEnd)
        break;
    }

    awpcvDisconnect(reader);
}
//---------------------------------------------------------------------------
void __fastcall TExportImagesThread::ThreadTerminate(TObject* sender)
{
	LongProcDlg->Close();
}
//---------------------------------------------------------------------------
void __fastcall TExportImagesThread::UpdateStatus()
{
   LongProcDlg->Label2->Caption = L"Экспорт изображений";
   UnicodeString str = L"Изображение ";
   str += IntToStr(m_pos);
   str += L" из ";
   str += IntToStr(m_total);
   LongProcDlg->Label1->Caption = str;
   LongProcDlg->ProgressBar1->Position = m_pos;
}
