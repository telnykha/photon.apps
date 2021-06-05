//---------------------------------------------------------------------------

#pragma hdrstop

#include "PhTime.h"
#include <System.SysUtils.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
TPhSecTime::TPhSecTime(unsigned int sec)
{
	m_sec = sec;
}
unsigned int __fastcall TPhSecTime::GetHours()
{
	return m_sec / 3600;
}
unsigned int __fastcall TPhSecTime::GetMinutes()
{
    return TotalMinutes - 60*Hours;
}
unsigned int __fastcall TPhSecTime::GetTotalMinutes()
{
	return m_sec / 60;
}

unsigned int __fastcall TPhSecTime::GetSecunds()
{
	return m_sec - 60*TotalMinutes;
}
// ѕреобразование заданного числа секунд в строку hh:mm:sec
UnicodeString PhGetTimeSecStamp(unsigned int sec)
{
	TPhSecTime t(sec);
    return FormatFloat("00",t.Hours) + L":" + FormatFloat("00",t.Minutes) + L":" + FormatFloat("00",t.Secunds);
}

