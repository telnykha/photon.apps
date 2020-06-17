//---------------------------------------------------------------------------

#ifndef ArchiveUnitH
#define ArchiveUnitH
#include <System.Classes.hpp>
#include "awpipl.h"
#include "PriProcessor.h"
//---------------------------------------------------------------------------
// forward
class  TMainForm;
class TPRIArchive
{
protected:
    UnicodeString m_strPath;
    UnicodeString m_currentPath;
    UnicodeString m_currentTime;
	void __fastcall DoCurrentTime();

public:
   TPRIArchive();
   ~TPRIArchive();

   bool __fastcall BeginSave(TMainForm* form);
   bool __fastcall Save(TMainForm* form);
   bool __fastcall Load(UnicodeString str);
   bool __fastcall LoadImages(UnicodeString str, awpImage** i531, awpImage** i570, awpImage** i531f, awpImage** i570f);

   bool __fastcall LoadPRI(UnicodeString str);

    bool __fastcall SaveRAW(awpImage* img, const char* lpFileName);
    bool __fastcall LoadRAW(awpImage** img, const char* lpFileName);

   bool __fastcall ExportPRI(UnicodeString strDst, UnicodeString path);
   bool __fastcall ExportPRIProc(UnicodeString strDst, UnicodeString path, TPriProcessor* processor);
   bool __fastcall ExportData(UnicodeString strDst, UnicodeString path);

   __property UnicodeString path = {read = m_strPath, write = m_strPath};
};

#endif
