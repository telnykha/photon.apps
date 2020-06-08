//---------------------------------------------------------------------------
#include <System.hpp>
#pragma hdrstop

#include "ComReaderUnit.h"
#include "PriMain.h"
#include "string.h"
#pragma package(smart_init)


HANDLE COMport;
int counter;
bool fl=0;	//����, ����������� �� ���������� �������� ������ (1 - �������, 0 - �� �������)

ReadThread  *reader;     //������ ������ ReadThread
WriteThread *writer;     //������ ������ WriteThread


//��������� OVERLAPPED ���������� ��� ����������� ��������, ��� ���� ��� �������� ������ � ������ ����� �������� ������ ���������
//��� ��������� ���������� �������� ���������, ����� ��������� �� ����� �������� ���������
OVERLAPPED overlapped;		//����� ������������ ��� �������� ������ (��. ����� ReadThread)
OVERLAPPED overlappedwr;       	//����� ������������ ��� �������� ������ (��. ����� WriteThread)
unsigned char bufrd[BUFSIZE], bufwr[BUFSIZE]; //������� � ���������� ������

//---------------------------------------------------------------------------
//������� �������� � ������������� �����
bool COMOpen(UnicodeString portname)
{
 //String portname;     	 //��� ����� (��������, "COM1", "COM2" � �.�.)
 DCB dcb;                //��������� ��� ����� ������������� ����� DCB
 COMMTIMEOUTS timeouts;  //��������� ��� ��������� ���������



 //������� ����, ��� ����������� �������� ����������� ����� ������� ���� FILE_FLAG_OVERLAPPED
 COMport = CreateFile(portname.c_str(),GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_FLAG_OVERLAPPED, NULL);
 //�����:
 // - portname.c_str() - ��� ����� � �������� ����� �����, c_str() ����������� ������ ���� String � ������ � ���� ������� ���� char, ����� ������� �� ������
 // - GENERIC_READ | GENERIC_WRITE - ������ � ����� �� ������/�������
 // - 0 - ���� �� ����� ���� ������������� (shared)
 // - NULL - ���������� ����� �� �����������, ������������ ���������� ������������ �� ���������
 // - OPEN_EXISTING - ���� ������ ����������� ��� ��� ������������ ����
 // - FILE_FLAG_OVERLAPPED - ���� ���� ��������� �� ������������� ����������� ��������
 // - NULL - ��������� �� ���� ������� �� ������������ ��� ������ � �������

 if(COMport == INVALID_HANDLE_VALUE)            //���� ������ �������� �����
  {
   return false;
  }

 //������������� �����

 dcb.DCBlength = sizeof(DCB); 	//� ������ ���� ��������� DCB ���������� ������� � �����, ��� ����� �������������� ��������� ��������� ����� ��� �������� ������������ ���������

 //������� ��������� DCB �� �����
 if(!GetCommState(COMport, &dcb))	//���� �� ������� - ������� ���� � ������� ��������� �� ������ � ������ ���������
  {
   COMClose();
   return false;
  }

 //������������� ��������� DCB
 dcb.BaudRate = 9600;//StrToInt(Form1->ComboBox2->Text);       //����� �������� �������� 115200 ���
 dcb.fBinary = TRUE;                                    //�������� �������� ����� ������
 dcb.fOutxCtsFlow = FALSE;                              //��������� ����� �������� �� �������� CTS
 dcb.fOutxDsrFlow = FALSE;                              //��������� ����� �������� �� �������� DSR
 dcb.fDtrControl = DTR_CONTROL_DISABLE;                 //��������� ������������� ����� DTR
 dcb.fDsrSensitivity = FALSE;                           //��������� ��������������� �������� � ��������� ����� DSR
 dcb.fNull = FALSE;                                     //��������� ���� ������� ������
 dcb.fRtsControl = RTS_CONTROL_DISABLE;                 //��������� ������������� ����� RTS
 dcb.fAbortOnError = FALSE;                             //��������� ��������� ���� �������� ������/������ ��� ������
 dcb.ByteSize = 8;                                      //����� 8 ��� � �����
 dcb.Parity = 0;                                        //��������� �������� ��������
 dcb.StopBits = 0;                                      //����� ���� ����-���

 //��������� ��������� DCB � ����
 if(!SetCommState(COMport, &dcb))	//���� �� ������� - ������� ���� � ������� ��������� �� ������ � ������ ���������
  {
   COMClose();
   return false;
  }

 //���������� ��������
 timeouts.ReadIntervalTimeout = 0;	 	//������� ����� ����� ���������
 timeouts.ReadTotalTimeoutMultiplier = 0;	//����� ������� �������� ������
 timeouts.ReadTotalTimeoutConstant = 0;         //��������� ��� ������ �������� �������� ������
 timeouts.WriteTotalTimeoutMultiplier = 0;      //����� ������� �������� ������
 timeouts.WriteTotalTimeoutConstant = 0;        //��������� ��� ������ �������� �������� ������

 //�������� ��������� ��������� � ����
 if(!SetCommTimeouts(COMport, &timeouts))	//���� �� ������� - ������� ���� � ������� ��������� �� ������ � ������ ���������
  {
   COMClose();
   return false;
  }

 //���������� ������� �������� ����� � ��������
 SetupComm(COMport,2000,2000);
 PurgeComm(COMport, PURGE_RXCLEAR);	//�������� ����������� ����� �����

 reader = new ReadThread(false);	//������� � ��������� ����� ������ ������
 reader->FreeOnTerminate = true;    //���������� ��� �������� ������, ����� �� ������������� ����������� ����� ����������
 return true;
}

//---------------------------------------------------------------------------

//������� �������� �����
void COMClose()
{
// if(writer)writer->Terminate();		//���� ����� ������ ��������, ��������� ���; �������� if(writer) �����������, ����� ��������� ������
 if(reader)reader->Terminate();         //���� ����� ������ ��������, ��������� ���; �������� if(reader) �����������, ����� ��������� ������
 CloseHandle(COMport);                  //������� ����
 COMport=0;				//�������� ���������� ��� ����������� �����
}


//����������� ������ ReadThread, �� ��������� ������
__fastcall ReadThread::ReadThread(bool CreateSuspended) : TThread(CreateSuspended)
{}

//---------------------------------------------------------------------------

//������� ������� ������, ��������� ���� ������ �� COM-�����
void __fastcall ReadThread::Execute()
{
 COMSTAT comstat;		//��������� �������� ��������� �����, � ������ ��������� ������������ ��� ����������� ���������� �������� � ���� ������
 DWORD btr, temp, mask, signal;	//���������� temp ������������ � �������� ��������

 overlapped.hEvent = CreateEvent(NULL, true, true, NULL);	//������� ���������� ������-������� ��� ����������� ��������
 SetCommMask(COMport, EV_RXCHAR);                   	        //���������� ����� �� ������������ �� ������� ����� ����� � ����
 while(!Terminated)						//���� ����� �� ����� �������, ��������� ����
  {
   WaitCommEvent(COMport, &mask, &overlapped);               	//������� ������� ����� ����� (��� � ���� ������������� ��������)
   //signal = WaitForSingleObject(overlapped.hEvent, 1000);	//������������� ����� �� ������� �����
   //if(signal == WAIT_OBJECT_0)				        //���� ������� ������� ����� ���������
    {
     if(GetOverlappedResult(COMport, &overlapped, &temp, true)) //���������, ������� �� ����������� ������������� �������� WaitCommEvent
      if((mask & EV_RXCHAR)!=0)					//���� ��������� ������ ������� ������� �����
       {
        ClearCommError(COMport, &temp, &comstat);		//����� ��������� ��������� COMSTAT
        btr = comstat.cbInQue;                          	//� �������� �� �� ���������� �������� ������
        if(btr)                         			//���� ������������� ���� ����� ��� ������
        {
         ReadFile(COMport, bufrd, btr, &temp, &overlapped);     //��������� ����� �� ����� � ����� ���������
         counter+=btr;                                          //����������� ������� ������
         Synchronize(Printing0);                      		//�������� ������� ��� ������ ������ �� ����� � � ����
        }
       }
    }
  }
 CloseHandle(overlapped.hEvent);		//����� ������� �� ������ ������� ������-�������
}

//---------------------------------------------------------------------------

//������� �������� ����� �� ����� � � ���� (���� ��������)
void __fastcall ReadThread::Printing0()
{
   	 memset(bufrd, 0, BUFSIZE);	        //�������� ����� (����� ������ �� ������������� ���� �� �����)
	 MainForm->ProcessData();
}
//����������� ������ WriteThread, �� ��������� ������
__fastcall WriteThread::WriteThread(bool CreateSuspended) : TThread(CreateSuspended)
{}

//---------------------------------------------------------------------------

//������� ������� ������, ��������� �������� ������ �� ������ � COM-����
void __fastcall WriteThread::Execute()
{
 DWORD temp, signal;	//temp - ����������-��������

 overlappedwr.hEvent = CreateEvent(NULL, true, true, NULL);   	  //������� �������
 WriteFile(COMport, bufwr, sizeof(bufwr), &temp, &overlappedwr);  //�������� ����� � ���� (������������� ��������!)
 signal = WaitForSingleObject(overlappedwr.hEvent, INFINITE);	  //������������� �����, ���� �� ���������� ������������� �������� WriteFile
 if((signal == WAIT_OBJECT_0) && (GetOverlappedResult(COMport, &overlappedwr, &temp, true))) fl = true; //���� �������� ����������� �������, ���������� ��������������� ������
 else fl = false;
 CloseHandle(overlappedwr.hEvent);	//����� ������� �� ������ ������� ������-�������
}

//---------------------------------------------------------------------------


