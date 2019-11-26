//---------------------------------------------------------------------------
#ifndef cammandsTableH
#define cammandsTableH
//---------------------------------------------------------------------------
#include <Vcl.Grids.hpp>
#include "editorUnit.h"
#include "IniFileUnit.h"

const UnicodeString c_FileName = L"default.pam";

struct expEvent
{
  int command;              // command id
  int pinStatus;            // intensivity [0..100]
  unsigned long pinDelay;   // delay in mks
  AnsiString imageName;     // connected image
  unsigned int eventTime;   // event time
};

class TCommandsTable
{
protected:
    bool m_changed;
    TStringGrid* m_grid;
	TList*       m_list;
    UnicodeString m_fileName;
    bool          m_editable;
    TPAMOptions* m_options;

    UnicodeString GetCommandName(int index);
    UnicodeString GetScriptCommandName(int index);
	UnicodeString __fastcall GetScript();
public:
    TCommandsTable(TStringGrid* grid, TPAMOptions* pOptions, bool editable = true);
    //
    void __fastcall NewTable();
    void __fastcall LoadTable(const char* lpFileName);
    void __fastcall SaveTable(const char* lpFileName);
    void __fastcall Save();
    void __fastcall UpdateGrid();
    //
    void __fastcall AddRecord(TeditorDlg* dlg);
    void __fastcall DeleteRecord(int index);
    void __fastcall EditRecord(int index, TeditorDlg* dlg);
    void __fastcall InsertRecord(int index, TeditorDlg* dlg);
    void __fastcall Up(int index);
    void __fastcall Down(int index);

    __property TList* list = {read = m_list};
    __property bool changed = {read = m_changed, write = m_changed};
    __property UnicodeString fileName = {read = m_fileName, write = m_fileName};
	__property UnicodeString script = {read = GetScript};

    __property TPAMOptions* options = {read = m_options, write = m_options};
};

#endif
