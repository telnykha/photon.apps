//---------------------------------------------------------------------------
#ifndef pamScriptDocUnitH
#define pamScriptDocUnitH
#include <vcl.h>
#include "TinyXml.h"
//---------------------------------------------------------------------------
class TPam2ScriptDoc
{
private:
	bool __fastcall CheckOneParam(const UnicodeString& str, int& value);
	bool __fastcall CheckDB(const UnicodeString& str, const UnicodeString& cmd, int& bv, int& dv );
	bool __fastcall IsCommand(const UnicodeString& str);
	bool m_running;
	int  m_nextCommand;
protected:
	TStringList* m_cmds;
	TStringList* m_script;
	TRichEdit* m_edit;
	UnicodeString m_fileName;
	bool __fastcall CheckCommand(const UnicodeString& str);
	bool __fastcall CheckAssigmentCommands(const UnicodeString& str);
	int __fastcall GetCommandsCount();
	bool __fastcall GetChecked();
	bool __fastcall GetIsRunning();
	void __fastcall SetIsRunning(bool value);
	void __fastcall CreateScript();
public:
   TPam2ScriptDoc(TRichEdit* edit);
   ~TPam2ScriptDoc();
   void __fastcall New();
   bool __fastcall Open(const UnicodeString& fileName);
   bool __fastcall SaveAs(const UnicodeString& fileName);
   bool __fastcall SaveXml(TiXmlNode* node);
   bool __fastcall Save();
   bool __fastcall Clear();

   bool __fastcall CheckScript();
   int  __fastcall GetScriptTime();
   UnicodeString  __fastcall NextCommand();
   int  __fastcall GetCommandTime(const UnicodeString& str);
	static bool __fastcall CheckAssignment(const UnicodeString& str, const UnicodeString& cmd, int min, int max, int& value);

   __property UnicodeString FileName = {read = m_fileName};
   __property int CommandsCount = {read = GetCommandsCount};
   __property bool Checked = {read = GetChecked};
   __property bool IsRunning = {read = GetIsRunning, write = SetIsRunning};
};
#endif
