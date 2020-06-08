//---------------------------------------------------------------------------
#include <System.hpp>
#pragma hdrstop

#include "ComReaderUnit.h"
#include "PriMain.h"
#include "string.h"
#pragma package(smart_init)


HANDLE COMport;
int counter;
bool fl=0;	//флаг, указывающий на успешность операций записи (1 - успешно, 0 - не успешно)

ReadThread  *reader;     //объект потока ReadThread
WriteThread *writer;     //объект потока WriteThread


//структура OVERLAPPED необходима для асинхронных операций, при этом для операции чтения и записи нужно объявить разные структуры
//эти структуры необходимо объявить глобально, иначе программа не будет работать правильно
OVERLAPPED overlapped;		//будем использовать для операций чтения (см. поток ReadThread)
OVERLAPPED overlappedwr;       	//будем использовать для операций записи (см. поток WriteThread)
unsigned char bufrd[BUFSIZE], bufwr[BUFSIZE]; //приёмный и передающий буферы

//---------------------------------------------------------------------------
//функция открытия и инициализации порта
bool COMOpen(UnicodeString portname)
{
 //String portname;     	 //имя порта (например, "COM1", "COM2" и т.д.)
 DCB dcb;                //структура для общей инициализации порта DCB
 COMMTIMEOUTS timeouts;  //структура для установки таймаутов



 //открыть порт, для асинхронных операций обязательно нужно указать флаг FILE_FLAG_OVERLAPPED
 COMport = CreateFile(portname.c_str(),GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_FLAG_OVERLAPPED, NULL);
 //здесь:
 // - portname.c_str() - имя порта в качестве имени файла, c_str() преобразует строку типа String в строку в виде массива типа char, иначе функция не примет
 // - GENERIC_READ | GENERIC_WRITE - доступ к порту на чтение/записть
 // - 0 - порт не может быть общедоступным (shared)
 // - NULL - дескриптор порта не наследуется, используется дескриптор безопасности по умолчанию
 // - OPEN_EXISTING - порт должен открываться как уже существующий файл
 // - FILE_FLAG_OVERLAPPED - этот флаг указывает на использование асинхронных операций
 // - NULL - указатель на файл шаблона не используется при работе с портами

 if(COMport == INVALID_HANDLE_VALUE)            //если ошибка открытия порта
  {
   return false;
  }

 //инициализация порта

 dcb.DCBlength = sizeof(DCB); 	//в первое поле структуры DCB необходимо занести её длину, она будет использоваться функциями настройки порта для контроля корректности структуры

 //считать структуру DCB из порта
 if(!GetCommState(COMport, &dcb))	//если не удалось - закрыть порт и вывести сообщение об ошибке в строке состояния
  {
   COMClose();
   return false;
  }

 //инициализация структуры DCB
 dcb.BaudRate = 9600;//StrToInt(Form1->ComboBox2->Text);       //задаём скорость передачи 115200 бод
 dcb.fBinary = TRUE;                                    //включаем двоичный режим обмена
 dcb.fOutxCtsFlow = FALSE;                              //выключаем режим слежения за сигналом CTS
 dcb.fOutxDsrFlow = FALSE;                              //выключаем режим слежения за сигналом DSR
 dcb.fDtrControl = DTR_CONTROL_DISABLE;                 //отключаем использование линии DTR
 dcb.fDsrSensitivity = FALSE;                           //отключаем восприимчивость драйвера к состоянию линии DSR
 dcb.fNull = FALSE;                                     //разрешить приём нулевых байтов
 dcb.fRtsControl = RTS_CONTROL_DISABLE;                 //отключаем использование линии RTS
 dcb.fAbortOnError = FALSE;                             //отключаем остановку всех операций чтения/записи при ошибке
 dcb.ByteSize = 8;                                      //задаём 8 бит в байте
 dcb.Parity = 0;                                        //отключаем проверку чётности
 dcb.StopBits = 0;                                      //задаём один стоп-бит

 //загрузить структуру DCB в порт
 if(!SetCommState(COMport, &dcb))	//если не удалось - закрыть порт и вывести сообщение об ошибке в строке состояния
  {
   COMClose();
   return false;
  }

 //установить таймауты
 timeouts.ReadIntervalTimeout = 0;	 	//таймаут между двумя символами
 timeouts.ReadTotalTimeoutMultiplier = 0;	//общий таймаут операции чтения
 timeouts.ReadTotalTimeoutConstant = 0;         //константа для общего таймаута операции чтения
 timeouts.WriteTotalTimeoutMultiplier = 0;      //общий таймаут операции записи
 timeouts.WriteTotalTimeoutConstant = 0;        //константа для общего таймаута операции записи

 //записать структуру таймаутов в порт
 if(!SetCommTimeouts(COMport, &timeouts))	//если не удалось - закрыть порт и вывести сообщение об ошибке в строке состояния
  {
   COMClose();
   return false;
  }

 //установить размеры очередей приёма и передачи
 SetupComm(COMport,2000,2000);
 PurgeComm(COMport, PURGE_RXCLEAR);	//очистить принимающий буфер порта

 reader = new ReadThread(false);	//создать и запустить поток чтения байтов
 reader->FreeOnTerminate = true;    //установить это свойство потока, чтобы он автоматически уничтожался после завершения
 return true;
}

//---------------------------------------------------------------------------

//функция закрытия порта
void COMClose()
{
// if(writer)writer->Terminate();		//если поток записи работает, завершить его; проверка if(writer) обязательна, иначе возникают ошибки
 if(reader)reader->Terminate();         //если поток чтения работает, завершить его; проверка if(reader) обязательна, иначе возникают ошибки
 CloseHandle(COMport);                  //закрыть порт
 COMport=0;				//обнулить переменную для дескриптора порта
}


//конструктор потока ReadThread, по умолчанию пустой
__fastcall ReadThread::ReadThread(bool CreateSuspended) : TThread(CreateSuspended)
{}

//---------------------------------------------------------------------------

//главная функция потока, реализует приём байтов из COM-порта
void __fastcall ReadThread::Execute()
{
 COMSTAT comstat;		//структура текущего состояния порта, в данной программе используется для определения количества принятых в порт байтов
 DWORD btr, temp, mask, signal;	//переменная temp используется в качестве заглушки

 overlapped.hEvent = CreateEvent(NULL, true, true, NULL);	//создать сигнальный объект-событие для асинхронных операций
 SetCommMask(COMport, EV_RXCHAR);                   	        //установить маску на срабатывание по событию приёма байта в порт
 while(!Terminated)						//пока поток не будет прерван, выполняем цикл
  {
   WaitCommEvent(COMport, &mask, &overlapped);               	//ожидать события приёма байта (это и есть перекрываемая операция)
   //signal = WaitForSingleObject(overlapped.hEvent, 1000);	//приостановить поток до прихода байта
   //if(signal == WAIT_OBJECT_0)				        //если событие прихода байта произошло
    {
     if(GetOverlappedResult(COMport, &overlapped, &temp, true)) //проверяем, успешно ли завершилась перекрываемая операция WaitCommEvent
      if((mask & EV_RXCHAR)!=0)					//если произошло именно событие прихода байта
       {
        ClearCommError(COMport, &temp, &comstat);		//нужно заполнить структуру COMSTAT
        btr = comstat.cbInQue;                          	//и получить из неё количество принятых байтов
        if(btr)                         			//если действительно есть байты для чтения
        {
         ReadFile(COMport, bufrd, btr, &temp, &overlapped);     //прочитать байты из порта в буфер программы
         counter+=btr;                                          //увеличиваем счётчик байтов
         Synchronize(Printing0);                      		//вызываем функцию для вывода данных на экран и в файл
        }
       }
    }
  }
 CloseHandle(overlapped.hEvent);		//перед выходом из потока закрыть объект-событие
}

//---------------------------------------------------------------------------

//выводим принятые байты на экран и в файл (если включено)
void __fastcall ReadThread::Printing0()
{
   	 memset(bufrd, 0, BUFSIZE);	        //очистить буфер (чтобы данные не накладывались друг на друга)
	 MainForm->ProcessData();
}
//конструктор потока WriteThread, по умолчанию пустой
__fastcall WriteThread::WriteThread(bool CreateSuspended) : TThread(CreateSuspended)
{}

//---------------------------------------------------------------------------

//главная функция потока, выполняет передачу байтов из буфера в COM-порт
void __fastcall WriteThread::Execute()
{
 DWORD temp, signal;	//temp - переменная-заглушка

 overlappedwr.hEvent = CreateEvent(NULL, true, true, NULL);   	  //создать событие
 WriteFile(COMport, bufwr, sizeof(bufwr), &temp, &overlappedwr);  //записать байты в порт (перекрываемая операция!)
 signal = WaitForSingleObject(overlappedwr.hEvent, INFINITE);	  //приостановить поток, пока не завершится перекрываемая операция WriteFile
 if((signal == WAIT_OBJECT_0) && (GetOverlappedResult(COMport, &overlappedwr, &temp, true))) fl = true; //если операция завершилась успешно, установить соответствующий флажок
 else fl = false;
 CloseHandle(overlappedwr.hEvent);	//перед выходом из потока закрыть объект-событие
}

//---------------------------------------------------------------------------


