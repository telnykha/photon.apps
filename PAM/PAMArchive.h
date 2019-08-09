//---------------------------------------------------------------------------
#ifndef PAMArchiveH
#define PAMArchiveH

#include <System.Classes.hpp>
#include "cammandsTable.h"
#include "awpipl.h"
#include <vector>
//---------------------------------------------------------------------------
class TPAMArchive
{
protected:
	TCommandsTable* m_table;
    std::vector<int>  m_indexes;
    int m_counter;
    UnicodeString m_path;
    UnicodeString m_currentTime;
    UnicodeString m_currentPath;
    void __fastcall DoCurrentTime();
    void __fastcall DoCurrentPath();
public:
    TPAMArchive(UnicodeString path);

    static UnicodeString GetCurrentTime();
    static awpImage* LoadPicture(UnicodeString path);
    void SavePicture(awpImage* image);
    void __fastcall CreateArchiveEntry(TCommandsTable* table);
    void __fastcall DeleteArchiveEntry();
    void __fastcall FinishSave();

    __property UnicodeString CurrentPath = {read = m_currentPath};
};
#endif
