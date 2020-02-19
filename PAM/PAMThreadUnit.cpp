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
	char readystatus;
    DWORD testRead = 0;
    DWORD testWrote = 0;
	char command = '1';
	char buffer[256];
	m_count = 0;
	m_comPort = CreateFile( port_name, GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, FILE_FLAG_NO_BUFFERING, 0);
	if(m_comPort != INVALID_HANDLE_VALUE)
	{
	   if (!WriteFile(m_comPort, &command, sizeof(char), &testWrote, NULL))
	   {
		 sprintf(buffer, "Ошибка записи в порт: %i\n", GetLastError());
		 mainPAM->Memo2->Lines->Add(buffer);
		 CloseHandle(m_comPort);
		 return;
	   }

	   if (!FlushFileBuffers(m_comPort)) // flush buffers to tell Ardunio to bark it's data
	   {
		 sprintf(buffer, "Ошибка очистки: %i\n", GetLastError());
		 mainPAM->Memo2->Lines->Add(buffer);
		 CloseHandle(m_comPort);
		 return;
	   }
	   do
	   {
			 if (m_count == 0)
				m_startTime = ::GetTickCount();
			 if (Terminated)
				break;
			 if (!ReadFile(m_comPort, &readystatus, 1, &testRead, NULL))
			 {
				 sprintf(buffer, "Ошибка чтения из порта: %i\n", GetLastError());
				 mainPAM->Memo2->Lines->Add(buffer);
				 break;
			 }
			 if (testRead > 0 && readystatus == '5')
			 {
				break;
			 }
			 if (testRead > 0)
			 {
				 m_count++;
				 m_commandSt = ::GetTickCount();
				 Synchronize(&ProgressHelper);
			 }
			 else
			 {
				 Synchronize(&UpdateTime);
			 }
	   }while(true);
	}
	CloseHandle(m_comPort);
}
//---------------------------------------------------------------------------
void __fastcall TPAMThread::ProgressHelper()
{
	if (m_count > mainPAM->table->list->Count)
		return;
	PAMLongProcessForm->Label1->Caption = L"Выполняется команда: " + mainPAM->StringGrid1->Cells[0][m_count] + L". №" + IntToStr(m_count) +  L" из " + IntToStr(mainPAM->StringGrid1->RowCount);
	PAMLongProcessForm->Gauge1->Progress = m_count;
	//
	expEvent* e = (expEvent*)mainPAM->table->list->Items[m_count-1];
	e->eventTime = ::GetTickCount() - m_commandSt;

	mainPAM->Memo2->Lines->Add(mainPAM->StringGrid1->Cells[0][m_count] + L"... ожидание ..." + mainPAM->StringGrid1->Cells[2][m_count] + L" ms");
}

void __fastcall TPAMThread::UpdateTime()
{
	if (m_count > mainPAM->table->list->Count)
		return;
	if (mainPAM->Memo2->Lines->Count > 0)
	{
		UnicodeString str = mainPAM->StringGrid1->Cells[0][m_count];
		UnicodeString t = IntToStr(__int64(::GetTickCount() - m_commandSt));
		mainPAM->Memo2->Lines->Strings[mainPAM->Memo2->Lines->Count-1] = t + L" ms  " + str + + L"... ожидание ..." + mainPAM->StringGrid1->Cells[2][m_count] + L" ms";
	}
}
