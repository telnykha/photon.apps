//---------------------------------------------------------------------------
#ifndef ConsoleIOH
#define ConsoleIOH
#include <vcl.h>
//---------------------------------------------------------------------------
class TConsoleIO
{
protected:
    TMemo* m_memo;
    bool IsWinNT();
    void ErrorMessage(const char* message);
public:
      TConsoleIO(TMemo* memo);
      // возвращает 0 в случае успешного выполнения команды
      // возвращает -1 в случае ошибки.
      int Run(char* command);
};


#endif
