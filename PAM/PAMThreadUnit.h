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
protected:
	void __fastcall Execute();
	void __fastcall ProgressHelper();
public:
	__fastcall TPAMThread(bool CreateSuspended);
};
//---------------------------------------------------------------------------
#endif
