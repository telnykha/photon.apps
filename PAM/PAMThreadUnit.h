//---------------------------------------------------------------------------

#ifndef PAMThreadUnitH
#define PAMThreadUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
class TPAMThread : public TThread
{
private:
	HANDLE m_comPort;
    int m_count;
	DWORD m_startTime;
    DWORD m_commandSt;
protected:
	void __fastcall Execute();
	void __fastcall ProgressHelper();
    void __fastcall UpdateTime();
public:
	__fastcall TPAMThread(bool CreateSuspended);
};
//---------------------------------------------------------------------------
#endif
