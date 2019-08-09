//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop

#include "PAMThreadUnit.h"
#include "MainUnit.h"
#include "PAMLongProcessUnit.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall TPAMThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall TPAMThread::TPAMThread(bool CreateSuspended)
	: TThread(CreateSuspended)
{
    m_comPort = NULL;

}
//---------------------------------------------------------------------------
void __fastcall TPAMThread::Execute()
{
	//---- Place thread code here ----
	char port_name[32];
    sprintf(port_name, "\\\\.\\COM%i\0", mainPAM->board);
    char readystatus[8] = {0};
    DWORD testRead = 0;
    DWORD testWrote = 0;
    unsigned char command = 0x01;
    m_count = 0;
    m_comPort = CreateFile( port_name, GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, FILE_FLAG_NO_BUFFERING, 0);
    if(m_comPort != INVALID_HANDLE_VALUE)
    {
       if (!WriteFile(m_comPort, &command, sizeof(char), &testWrote, NULL))
       {
         printf("error write port: %i\n", GetLastError());
         return;
       }

       if (!FlushFileBuffers(m_comPort)) // flush buffers to tell Ardunio to bark it's data
       {
         printf("error flush port: %i\n", GetLastError());
         return;
       }
       do
       {
             if (Terminated)
             	break;
             if (!ReadFile(m_comPort, readystatus, 1, &testRead, NULL))
             {
                 printf("error read port: %i\n", GetLastError());
                 break;
             }
             if (readystatus[0] == 0x05)
                break;
             if (testRead > 0)
             {
                 m_count++;
                 Synchronize(&ProgressHelper);
             }
       }while(true);
    }
    CloseHandle(m_comPort);
}
//---------------------------------------------------------------------------
void __fastcall TPAMThread::ProgressHelper()
{
    PAMLongProcessForm->Label1->Caption = mainPAM->StringGrid1->Cells[0][m_count+1];
    PAMLongProcessForm->Gauge1->Progress = m_count;
}
