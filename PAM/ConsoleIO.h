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
      // ���������� 0 � ������ ��������� ���������� �������
      // ���������� -1 � ������ ������.
      int Run(char* command);
};


#endif
