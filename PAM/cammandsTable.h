//---------------------------------------------------------------------------
#ifndef cammandsTableH
#define cammandsTableH
//---------------------------------------------------------------------------
#include <Vcl.Grids.hpp>
#include "editorUnit.h"

const UnicodeString c_FileName = L"default.pam";

struct expEvent
{
  int command;
  int pinStatus;
  unsigned long pinDelay;
  AnsiString imageName;
};

class TCommandsTable
{
protected:
    bool m_changed;
    TStringGrid* m_grid;
    TList*       m_list;
    UnicodeString m_fileName;
    UnicodeString GetCommandName(int index);
    UnicodeString GetScriptCommandName(int index);
    UnicodeString GetCommandIntensivity(int index, int indexCommand);
    int GetCommandIntensivityValue(int index);
    UnicodeString __fastcall GetScript();
public:
    TCommandsTable(TStringGrid* grid);
    //
    void __fastcall NewTable();
    void __fastcall LoadTable(const char* lpFileName);
    void __fastcall SaveTable(const char* lpFileName);
    void __fastcall Save();
    //
    void __fastcall AddRecord(TeditorDlg* dlg);
    void __fastcall DeleteRecord(int index);
    void __fastcall EditRecord(int index, TeditorDlg* dlg);

    __property TList* list = {read = m_list};
    __property bool changed = {read = m_changed};
    __property UnicodeString fileName = {read = m_fileName};
    __property UnicodeString script = {read = GetScript};
};

#endif
