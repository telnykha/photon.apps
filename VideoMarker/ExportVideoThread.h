//---------------------------------------------------------------------------
#ifndef ExportVideoThreadH
#define ExportVideoThreadH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
class TExportVideoThread : public TThread
{
private:
    int m_pos;
    int m_total;
protected:
    void __fastcall UpdateStatus();
    void __fastcall ThreadTerminate(TObject* sender);
	void __fastcall Execute();
public:
	__fastcall TExportVideoThread(bool CreateSuspended);
    UnicodeString outputName;
};
//---------------------------------------------------------------------------
#endif
