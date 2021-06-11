//---------------------------------------------------------------------------

#pragma hdrstop
#include <assert.h>
#include "pamScriptDocUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
TPam2ScriptDoc::TPam2ScriptDoc(TRichEdit* edit)
{
	m_edit = edit;
	m_fileName = L"default.pam2s";
}

void __fastcall TPam2ScriptDoc::New()
{
	 assert(m_edit != NULL);
	 Clear();
     m_fileName = L"default.pam2s";
}

bool __fastcall TPam2ScriptDoc::Open(const UnicodeString& fileName)
{
    assert(m_edit != NULL);
	m_edit->Lines->LoadFromFile(fileName);
	m_fileName = fileName;
    m_edit->Modified = false;
	return m_edit->Lines->Count > 0;
}

bool __fastcall TPam2ScriptDoc::SaveAs(const UnicodeString& fileName)
{
	assert(m_edit != NULL);
	try
	{
		m_edit->PlainText =true;
		m_edit->Lines->SaveToFile(fileName);
	}
	catch(...)
	{
		return false;
	}
	m_fileName = fileName;
	m_edit->Modified = false;
	return true;
}

bool __fastcall TPam2ScriptDoc::SaveXml(TiXmlNode* node)
{
	return false;
}
bool __fastcall TPam2ScriptDoc::Clear()
{
	assert(m_edit != NULL);
	m_edit->Clear();
	m_edit->Modified = false;
	return true;
}

bool __fastcall TPam2ScriptDoc::Save()
{
	assert(m_edit != NULL);
	try
	{
		m_edit->PlainText =true;
		m_edit->Lines->SaveToFile(m_fileName);
	}
	catch(...)
	{
		return false;
	}
	m_edit->Modified = false;
    return true;
}

bool __fastcall TPam2ScriptDoc::CheckScript()
{
	bool result = true;
	for(int i = 0; i < m_edit->Lines->Count; i++)
	{
		UnicodeString str = m_edit->Lines->Strings[i];
		if (!this->CheckCommand(str)) {
			result = false;
            break;
		}
	}
	return result;
}

bool __fastcall TPam2ScriptDoc::CheckCommand(const UnicodeString& str)
{
	if (str == NULL) {
        return true;
	}

	UnicodeString _str = str.Trim();
	// проверка пустой строки
	if (_str == "") {
        return true;
	}
	// проверка комментария
	int pos = _str.Pos(L"//");
	if (pos == 1) {
		return true;
	}
	// проверка команд без параметров
	if (_str == L"PAM2" ||
		 _str == L"EXP?" ||
		 _str == L"GAIN?" ||
		 _str == L"LSAT?" ||
		 _str == L"LACT?" ||
		 _str == L"LADD?" ||
		 _str == L"LFLASH?" ||
		 _str == L"SAT?" ||
		 _str == L"ACT?" ||
		 _str == L"ADD?")
	{
        return true;
	}


    return false;
}


