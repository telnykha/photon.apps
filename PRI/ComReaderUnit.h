//---------------------------------------------------------------------------

#ifndef ComReaderUnitH
#define ComReaderUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#define BUFSIZE 255     		//ёмкость буфера

bool COMOpen(UnicodeString portname);             //открыть порт
void COMClose(void);            //закрыть порт


//---------------------------------------------------------------------------
//поток для чтения последовательности байтов из COM-порта в буфер
class ReadThread : public TThread
{
 private:
        void __fastcall Printing0();	//вывод принятых байтов на экран и в файл
 protected:
        void __fastcall Execute();	//основная функция потока
 public:
        __fastcall ReadThread(bool CreateSuspended);	//конструктор потока
};


//поток для записи последовательности байтов из буфера в COM-порт
class WriteThread : public TThread
{
private:
protected:
        void __fastcall Execute();      //основная функция потока
public:
        __fastcall WriteThread(bool CreateSuspended);	//конструктор потока
};

extern ReadThread  *reader;     //объект потока ReadThread
extern WriteThread *writer;     //объект потока WriteThread

//---------------------------------------------------------------------------
#endif
