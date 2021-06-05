//---------------------------------------------------------------------------
#ifndef PhTimeH
#define PhTimeH
#include <System.hpp>
//---------------------------------------------------------------------------
// преобразование заданного числа секунд в часы, минуты и секунды
class TPhSecTime
{
private:
	unsigned int m_sec;
protected:
	unsigned int __fastcall GetHours();
	unsigned int __fastcall GetMinutes();
	unsigned int __fastcall GetSecunds();
	unsigned int __fastcall GetTotalMinutes();
public:
	  TPhSecTime(unsigned int sec);
	  __property unsigned int Hours   = {read = GetHours};
	  __property unsigned int Minutes = {read = GetMinutes};
	  __property unsigned int TotalMinutes = {read = GetTotalMinutes};
	  __property unsigned int Secunds = {read = GetSecunds};
	  __property unsigned int TotalSec = {read = m_sec};
};

UnicodeString PhGetTimeSecStamp(unsigned int sec);
#endif
