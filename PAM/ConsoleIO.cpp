//---------------------------------------------------------------------------

#pragma hdrstop

#include "ConsoleIO.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#define bzero(a) memset(a,0,sizeof(a)) //��� ���������� ��������
TConsoleIO::TConsoleIO(TMemo* memo)
{
    m_memo = NULL;
    m_memo = memo;
}
// ���������� 0 � ������ ��������� ���������� �������
// ���������� -1 � ������ ������.
int TConsoleIO::Run(char* command)
{
    char buf[1024];
	STARTUPINFO si;
	SECURITY_ATTRIBUTES sa;
	SECURITY_DESCRIPTOR sd;        //��������� security ��� ������
	PROCESS_INFORMATION pi;

    HANDLE newstdin,newstdout,read_stdout,write_stdin;  //�����������
                                                        // ������
    if (IsWinNT())        //������������� security ��� Windows NT
    {
        InitializeSecurityDescriptor(&sd,SECURITY_DESCRIPTOR_REVISION);
        SetSecurityDescriptorDacl(&sd, true, NULL, false);
        sa.lpSecurityDescriptor = &sd;
    }
    else
		sa.lpSecurityDescriptor = NULL;

    if (!CreatePipe(&newstdin,&write_stdin,&sa,0))   //������� ����
                                                   // ��� stdin
    {
        ErrorMessage("CreatePipe error");
        return -1;
    }

    if (!CreatePipe(&read_stdout,&newstdout,&sa,0)) //������� ����
                                                  // ��� stdout
    {
        ErrorMessage("CreatePipe error");
        return -1;
        CloseHandle(newstdin);
        CloseHandle(write_stdin);
        return -1;
    }



    GetStartupInfo(&si);      //������� startupinfo ���
                              // ��������� ��������

  /*

  �������� dwFlags �������� ������� CreateProcess
  ��� ������ ���� ������� �������.

  STARTF_USESTDHANDLES ��������� ������ hStd*.
  STARTF_USESHOWWINDOW ��������� ����� wShowWindow.

  */

  si.dwFlags = STARTF_USESTDHANDLES|STARTF_USESHOWWINDOW;
  si.wShowWindow = SW_HIDE;
  si.hStdOutput = newstdout;
  si.hStdError = newstdout;   //��������� ����������� ���
  si.hStdInput = newstdin;    // ��������� ��������

  //������� �������� �������
  if (!CreateProcess(NULL,command,NULL,NULL,TRUE,CREATE_NEW_CONSOLE,
                     NULL,NULL,&si,&pi))
  {
    ErrorMessage("Create Process error");
    CloseHandle(newstdin);
    CloseHandle(newstdout);
    CloseHandle(read_stdout);
    CloseHandle(write_stdin);
    return -1;
  }



  unsigned long exit=0;  //��� ���������� ��������
  unsigned long bread;   //���-�� ����������� ����
  unsigned long avail;   //���-�� ��������� ����



  bzero(buf);

  for(;;)      //�������� ���� ���������
  {
    GetExitCodeProcess(pi.hProcess,&exit); //���� �������� �������
                                           // �� ������
    if (exit != STILL_ACTIVE)
      break;
    Application->ProcessMessages();
    PeekNamedPipe(read_stdout,buf,sizeof(buf),&bread,&avail,NULL);

    //���������, ���� �� ������ ��� ������ � stdout

    if (bread != 0)
    {
      bzero(buf);
      if (avail > sizeof(buf))
      {
        while (bread >= sizeof(buf))
        {
          ReadFile(read_stdout,buf,sizeof(buf),&bread,NULL);  //������ ��
                                                       // ����� stdout
          ErrorMessage(buf);
          bzero(buf);
        }
      }
      else {
        ReadFile(read_stdout,buf,sizeof(buf),&bread,NULL);
        ErrorMessage(buf);
      }
    }
  }

  CloseHandle(pi.hThread);
  CloseHandle(pi.hProcess);
  CloseHandle(newstdin);            //��������� ������ �� �����
  CloseHandle(newstdout);
  CloseHandle(read_stdout);
  CloseHandle(write_stdin);
  m_memo->Lines->Add("�������.");
  return 0;
}

bool TConsoleIO::IsWinNT()
{
  OSVERSIONINFO osv;
  osv.dwOSVersionInfoSize = sizeof(osv);
  GetVersionEx(&osv);
  return (osv.dwPlatformId == VER_PLATFORM_WIN32_NT);
}

void TConsoleIO::ErrorMessage(const char* message)
{
    UnicodeString str = message;
    str = str.TrimLeft();
    if (m_memo != NULL)
	    m_memo->Lines->Add(str.TrimRight());
}


