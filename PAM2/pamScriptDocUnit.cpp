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
	m_cmds = new TStringList();

	m_cmds->Add(L"PAM2");
	m_cmds->Add(L"EXP");
	m_cmds->Add(L"GAIN");
	m_cmds->Add(L"LFLASH");
	m_cmds->Add(L"LSAT");
	m_cmds->Add(L"LACT");
	m_cmds->Add(L"LADD");
	m_cmds->Add(L"SAT");
	m_cmds->Add(L"ACT");
	m_cmds->Add(L"ADD");
	m_cmds->Add(L"FLASH");
	m_cmds->Add(L"DARK");
	m_cmds->Add(L"FOFM");
	m_cmds->Add(L"FTFM1");
	m_cmds->Add(L"DARKNESS");
	m_cmds->Add(L"SATURATION");
	m_cmds->Add(L"ACTINIC");
	m_cmds->Add(L"ADIITIONAL");

	m_script = new TStringList();
	m_running = false;
	m_nextCommand = 0;
}
TPam2ScriptDoc::~TPam2ScriptDoc()
{
	delete m_cmds;
	delete m_script;
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
		 _str == L"ADD?" ||
		 _str == L"FLASH" ||
		 _str == L"DARK" ||
		 _str == L"FOFM" ||
		 _str == L"FTFM1")
	{
		return true;
	}

	// проверка команд установки значений переменных
	// EXP, GAIN, LSAT, LACT, LADD, SAT, ACT, ADD, LFLASH
	//
	pos = _str.Pos(L"=");
	if (pos > 0) {
		return this->CheckAssigmentCommands(_str);
	}

	// поровека команд с одним параметром
	// DARKNESS
	pos = _str.Pos(L"DARKNESS(");
	int v,b;
	if (pos == 1) {
	   return this->CheckDARKNESS(_str, v);
	}
	// проверка команд с двумя параметрами
	// SATURATION, ACTINIC, ADDITIONAL
	if (_str.Pos(L"SATURATION(") > 0) {

	   return this->CheckDB(_str, L"SATURATION", b,v);
	}
	else if (_str.Pos(L"ACTINIC(") > 0) {
	   return this->CheckDB(_str, L"ACTINIC", b,v);
	}
	else if (_str.Pos(L"ADDITIONAL(") > 0) {
	   return this->CheckDB(_str, L"ADDITIONAL", b,v);
	}

	return false;
}
bool __fastcall TPam2ScriptDoc::CheckAssignment(const UnicodeString& str, const UnicodeString& cmd, int min, int max)
{
	UnicodeString _str = str;
	int pos = _str.Pos(cmd);
	if (pos != 1)
		return false;
	pos = _str.Pos(L"=");
	if (pos > 0) {
		UnicodeString sv = _str.SubString(pos+1, _str.Length() - pos);
		int value = 0;
		try
		{
			value = StrToInt(sv);
		}
		catch(EConvertError& e)
		{
			return false;
		}
		if (value <min || value > max) {
			return false;
		}
	}
	else
		return false;
	return true;

}

bool __fastcall TPam2ScriptDoc::CheckAssigmentCommands(const UnicodeString& str)
{
	UnicodeString _str = str;

		if (_str.Pos(L"EXP")== 1) {
			// проверка допустимости команды
			return this->CheckAssignment(_str, L"EXP", 50, 32000);
		}
		else if(_str.Pos(L"GAIN")== 1)
		{
			return this->CheckAssignment(_str, L"GAIN", 6, 41);
		}
		else if(_str.Pos(L"LSAT")== 1)
		{
			return this->CheckAssignment(_str, L"LSAT", 0, 100);
		}
		else if(_str.Pos(L"LACT")== 1)
		{
		return this->CheckAssignment(str, L"LACT", 0, 100);
		}
		else if(_str.Pos(L"LADD")== 1)
		{
			return this->CheckAssignment(_str, L"ADD", 0, 1);
		}
		else if(_str.Pos(L"SAT")== 1)
		{
			return this->CheckAssignment(_str, L"SAT", 0, 1);
		}
		else if(_str.Pos(L"ACT")== 1)
		{
			return this->CheckAssignment(str, L"ACT", 0, 1);
		}
		else if(_str.Pos(L"ADD")== 1)
		{
			return this->CheckAssignment(_str, L"ADD", 0, 1);
		}
		else if(_str.Pos(L"LFLASH")== 1)
		{
			return this->CheckAssignment(_str, L"LFLASH", 20, 50);
		}
		else
			return false;
}

bool __fastcall TPam2ScriptDoc::CheckDARKNESS(const UnicodeString& str, int& value)
{
	UnicodeString _str = str;
	value = 0;
	int index1 = _str.Pos(L"(");
	int index2 = _str.Pos(L")");
	if (index1 == 0 || index2 == 0)
		return false;
	if (_str.Length() - index2 > 0) {
		return false;
	}
	else
	{
		  UnicodeString param = _str.SubString(index1+1, index2-index1-1);
		  int duration = 0;
		  try
		  {
			duration = StrToInt(param);
		  }
		  catch(EConvertError& e)
		  {
			return false;
		  }
		  if (duration < 1 || duration > 60000) {
			return false;
		  }
		  value = duration;
		  return true;
   }
}
/*
#define _BEGIN_OBTAIN_PARAMS_
	int index1 = command.indexOf('(');                        \
	int index2 = command.indexOf(')');                        \
	if (index1 == -1 || index2 == -1)                         \
	  Serial.println(_error);                                 \
	else                                                      \
	{                                                         \
	  String params = command.substring(index1 + 1, index2);  \
	  int index3 = params.indexOf(',');                       \
	  if(index3 == -1)                                        \
		Serial.println(_error);                               \
	  else                                                    \
	  {                                                       \
		 String p1 = params.substring(0, index3);             \
		 String p2 = params.substring(index3+1, params.length());\
		 int brightness = p1.toInt();                         \
		 int duration   = p2.toInt();                         \
		 if (brightness < 1 || brightness > 100 || duration < 0)\
			Serial.println(_error);                           \
		 else                                                 \
		 {                                                    \

#define _END_OBTAIN_PARAMS_                                   \
		 }                                                    \
	  }                                                       \
	}                                                         \

*/
bool __fastcall TPam2ScriptDoc::CheckDB(const UnicodeString& str, const UnicodeString& cmd, int& bv, int& dv)
{
	UnicodeString _str = str.Trim();
	dv = 0;
	bv = 0;
	int pos = _str.Pos(cmd);
	if (pos != 1) {
		return false;
	}

	int index1 = _str.Pos(L"(");
	int index2 = _str.Pos(L")");
	if (index1 == 0 || index2 == 0)
		return false;
	if (_str.Length() - index2 > 0) {
		return false;
	}
	UnicodeString params = _str.SubString(index1 + 1, index2-index1-1);
	int index3 = params.Pos(L",");
	if (index3 == 0) {
		return false;
	}

	UnicodeString sb = params.SubString(0, index3-1);
	UnicodeString sd = params.SubString(index3+1, params.Length()-index3);

	int b = -1;
	int d = -1;
	try
	{
		b = StrToInt(sb);
		d = StrToInt(sd);
	}
	catch(EConvertError& e)
	{
		return false;
	}
	if (b < 0 || b > 100) {
		return false;
	}
	if (d < 1 || d > 60000) {
		return false;
	}
	dv = d;
	bv = b;
	return true;
}
//
bool __fastcall TPam2ScriptDoc::IsCommand(const UnicodeString& str)
{
   for (int i = 0; i < m_cmds->Count; i++) {
	   UnicodeString cmd = m_cmds->Strings[i];
	   if (str.Pos(cmd) == 1) {
		return true;
	   }
   }
   return false;
}

int __fastcall TPam2ScriptDoc::GetCommandsCount()
{
	int count = 0;
	for(int i = 0; i < m_edit->Lines->Count; i++)
	{
		UnicodeString str = m_edit->Lines->Strings[i];
		if (this->IsCommand(str)) {
			count++;
		}
	}
	return count;
}
// возвращает длительность команды в миллисекндах
int  __fastcall TPam2ScriptDoc::GetCommandTime(const UnicodeString& str)
{
	 if (!this->IsCommand(str)) {
		return 0;
	 }

	 UnicodeString _str = str.Trim();
	 int value = 0;
	 int b = 0;

	 if (_str.Pos(L"SATURATION") == 1)
	 {
		CheckDB(_str, L"SATURATION", b, value);
		return value;
	 }
	 else if (_str.Pos(L"ACTINIC") == 1) {
			CheckDB(_str, L"ACTINIC", b, value);
			return value;
		  }
	 else if (_str.Pos(L"ADDITIONAL") == 1) {
			CheckDB(_str, L"ADDITIONAL", b, value);
			return value;
		  }

	 if (_str.Pos(L"DARKNESS") == 1) {
		CheckDARKNESS(_str, value);
		return value;
	 }

	 if (_str.Pos(L"FLASH") == 1 ||
		_str.Pos(L"DARK") == 1){
		return 150;
	 }

	 if (_str.Pos(L"FOFM") == 1 ||
		_str.Pos(L"FTFM1") == 1){
		return 1000;
	 }

	 if (_str.Pos(L"PAM2") == 1 ||
		_str.Pos(L"EXP") == 1 ||
		_str.Pos(L"GAIN") == 1 ||
		_str.Pos(L"LFLASH") == 1 ||
		_str.Pos(L"LACT") == 1 ||
		_str.Pos(L"LSAT") == 1 ||
		_str.Pos(L"LADD") == 1 ||
		_str.Pos(L"SAT") == 1 ||
		_str.Pos(L"ACT") == 1 ||
		_str.Pos(L"ADD") == 1) {
		return 100;
	 }


	return 0;
}
// вычисляет длительность скрипта в миллисекундах
int  __fastcall TPam2ScriptDoc::GetScriptTime()
{
	int t = 0;
	for(int i = 0; i < m_edit->Lines->Count; i++)
	{
		UnicodeString str = m_edit->Lines->Strings[i];
		if (this->IsCommand(str)) {
			t += this->GetCommandTime(str);
		}
	}
	return t;
}

bool __fastcall TPam2ScriptDoc::GetChecked()
{
	return this->CheckScript();
}

bool __fastcall TPam2ScriptDoc::GetIsRunning()
{
	return m_running;
}
void __fastcall TPam2ScriptDoc::SetIsRunning(bool value)
{
	  if (m_running == value) {
		return;
	  }
	  m_nextCommand = 0;
	  m_running = value;
	  if (m_running) {
		CreateScript();
	  }
}

UnicodeString  TPam2ScriptDoc::NextCommand()
{
	if (m_running) {
	   if (m_nextCommand < m_script->Count) {
		  UnicodeString str = m_script->Strings[m_nextCommand];
		  m_nextCommand++;
		  return str;
	   }
	   else
		   return L"END";
	}
	else
		return L"";
}

void __fastcall TPam2ScriptDoc::CreateScript()
{
	m_script->Clear();
	for(int i = 0; i < m_edit->Lines->Count; i++)
	{
		UnicodeString str = m_edit->Lines->Strings[i];
		if (this->IsCommand(str)) {
			m_script->Add(str);
		}
	}
}


