//---------------------------------------------------------------------------

#ifndef ExportImagesThreadH
#define ExportImagesThreadH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
class TExportImagesThread : public TThread
{
private:
    int m_pos;
    int m_total;
protected:
	void __fastcall Execute();
    void __fastcall ThreadTerminate(TObject* sender);
    void __fastcall UpdateStatus();
public:
	__fastcall TExportImagesThread(bool CreateSuspended);
	UnicodeString outputName;
    UnicodeString ext;
    int           frequency;
};
//---------------------------------------------------------------------------
#endif
