//---------------------------------------------------------------------------

#pragma hdrstop

#include "ConsoleIO.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#define bzero(a) memset(a,0,sizeof(a)) //для сокращения писанины
TConsoleIO::TConsoleIO(TMemo* memo)
{
    m_memo = NULL;
    m_memo = memo;
}
// возвращает 0 в случае успешного выполнения команды
// возвращает -1 в случае ошибки.
int TConsoleIO::Run(char* command)
{
    char buf[1024];
	STARTUPINFO si;
	SECURITY_ATTRIBUTES sa;
	SECURITY_DESCRIPTOR sd;        //структура security для пайпов
	PROCESS_INFORMATION pi;

    HANDLE newstdin,newstdout,read_stdout,write_stdin;  //дескрипторы
                                                        // пайпов
    if (IsWinNT())        //инициализация security для Windows NT
    {
        InitializeSecurityDescriptor(&sd,SECURITY_DESCRIPTOR_REVISION);
        SetSecurityDescriptorDacl(&sd, true, NULL, false);
        sa.lpSecurityDescriptor = &sd;
    }
    else
		sa.lpSecurityDescriptor = NULL;

    if (!CreatePipe(&newstdin,&write_stdin,&sa,0))   //создаем пайп
                                                   // для stdin
    {
        ErrorMessage("CreatePipe error");
        return -1;
    }

    if (!CreatePipe(&read_stdout,&newstdout,&sa,0)) //создаем пайп
                                                  // для stdout
    {
        ErrorMessage("CreatePipe error");
        return -1;
        CloseHandle(newstdin);
        CloseHandle(write_stdin);
        return -1;
    }



    GetStartupInfo(&si);      //создаем startupinfo для
                              // дочернего процесса

  /*

  Параметр dwFlags сообщает функции CreateProcess
  как именно надо создать процесс.

  STARTF_USESTDHANDLES управляет полями hStd*.
  STARTF_USESHOWWINDOW управляет полем wShowWindow.

  */

  si.dwFlags = STARTF_USESTDHANDLES|STARTF_USESHOWWINDOW;
  si.wShowWindow = SW_HIDE;
  si.hStdOutput = newstdout;
  si.hStdError = newstdout;   //подменяем дескрипторы для
  si.hStdInput = newstdin;    // дочернего процесса

  //создаем дочерний процесс
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



  unsigned long exit=0;  //код завершения процесса
  unsigned long bread;   //кол-во прочитанных байт
  unsigned long avail;   //кол-во доступных байт



  bzero(buf);

  for(;;)      //основной цикл программы
  {
    GetExitCodeProcess(pi.hProcess,&exit); //пока дочерний процесс
                                           // не закрыт
    if (exit != STILL_ACTIVE)
      break;
    Application->ProcessMessages();
    PeekNamedPipe(read_stdout,buf,sizeof(buf),&bread,&avail,NULL);

    //Проверяем, есть ли данные для чтения в stdout

    if (bread != 0)
    {
      bzero(buf);
      if (avail > sizeof(buf))
      {
        while (bread >= sizeof(buf))
        {
          ReadFile(read_stdout,buf,sizeof(buf),&bread,NULL);  //читаем из
                                                       // пайпа stdout
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
  CloseHandle(newstdin);            //небольшая уборка за собой
  CloseHandle(newstdout);
  CloseHandle(read_stdout);
  CloseHandle(write_stdin);
  m_memo->Lines->Add("успешно.");
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


