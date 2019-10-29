//---------------------------------------------------------------------------
#ifndef cammandsTableH
#define cammandsTableH
//---------------------------------------------------------------------------
#include <Vcl.Grids.hpp>
#include "editorUnit.h"

const UnicodeString c_FileName = L"default.pam";

struct expEvent
{
  int command;              // command
  int pinStatus;            // intensivity [0..100]
  unsigned long pinDelay;   // delay in mks
  AnsiString imageName;     // connected image
};

class TCommandsTable
{
protected:
    bool m_changed;
    TStringGrid* m_grid;
	TList*       m_list;
	int          m_exposure; // экспозиция в микросекундах
    int          m_exp_index;
    int          m_exp_value;
    UnicodeString m_fileName;
    UnicodeString GetCommandName(int index);
    UnicodeString GetScriptCommandName(int index);
	UnicodeString __fastcall GetScript();
	void __fastcall SetExposure(int value);
    void __fastcall SetExpIndex(int value);
    void __fastcall SetExpValue(int value);
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
	__property int exposure = {read = m_exposure, write = SetExposure};
    __property int exp_index = {read = m_exp_index, write = SetExpIndex};
    __property int exp_value = {read = m_exp_value, write = SetExpValue};
};

#endif
