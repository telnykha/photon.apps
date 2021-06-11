//---------------------------------------------------------------------------
#ifndef pamScriptDocUnitH
#define pamScriptDocUnitH
#include <vcl.h>
#include "TinyXml.h"
//---------------------------------------------------------------------------
class TPam2ScriptDoc
{
protected:
	TRichEdit* m_edit;
	UnicodeString m_fileName;
	bool __fastcall CheckCommand(const UnicodeString& str);
public:
   TPam2ScriptDoc(TRichEdit* edit);
   void __fastcall New();
   bool __fastcall Open(const UnicodeString& fileName);
   bool __fastcall SaveAs(const UnicodeString& fileName);
   bool __fastcall SaveXml(TiXmlNode* node);
   bool __fastcall Save();
   bool __fastcall Clear();

   bool __fastcall CheckScript();

   __property UnicodeString FileName = {read = m_fileName};

};
#endif
