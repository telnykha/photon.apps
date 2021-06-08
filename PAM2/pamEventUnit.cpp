//---------------------------------------------------------------------------
#pragma hdrstop
#include "pamEventUnit.h"
#include "System.SysUtils.hpp"
#include "_LF.h"
#include <string>
//---------------------------------------------------------------------------
#pragma package(smart_init)
TPam2Event::TPam2Event()
{
	m_command = "";
	m_name = "";
	m_time = 0;
}

TPam2Event::TPam2Event(unsigned long t, const char* command)
{
	m_command = command;
	m_name = GetCommandName(command);
	m_time = t;
	m_attributes.insert(pair<string,string>("name", m_name.c_str()));
	AnsiString s = IntToStr((__int64)m_time);
	m_attributes.insert(pair<string,string>("time", s.c_str()));
	CreateAttibutes();
}
TPam2Event::~TPam2Event()
{
}
bool __fastcall TPam2Event::SaveXmlNode(TiXmlNode* node)
{
	if (node == NULL)
		return false;
	TiXmlElement* e = new TiXmlElement("pam2Event");
	// show content:
	for (std::map<string,string>::iterator it=m_attributes.begin(); it!=m_attributes.end(); ++it)
	{
		//std::cout << it->first << " => " << it->second << '\n';
		e->SetAttribute(it->first, it->second);
	}

	node->LinkEndChild(e);
	return true;
}
bool __fastcall TPam2Event::LoadXmlNode(TiXmlNode* node)
{
	if (node == NULL)
		return false;
	TiXmlElement* e = node->ToElement();
	for(TiXmlAttribute* attr = e->FirstAttribute(); attr; attr = attr->Next())
	{
       m_attributes.insert(pair<string,string>(attr->Name(), attr->Value()));
	}

	return true;
}
static AnsiString UUIDCreate()
{
	UUID id;
	LF_UUID_CREATE(id);
	std::string str = LFGUIDToString(&id);
	AnsiString result = str.c_str();
	return result;
}
bool __fastcall TPam2Event::CreateAttibutes()
{
	if (m_name == "UNKNOWN")
		return false;

	if (m_name == "EXP" || m_name == "GAIN" || m_name == "LSAT" || m_name == "LACT" ||
	m_name == "LADD" || m_name == "LFLASH" || m_name == "SAT" || m_name == "ACT" ||
	m_name == "ADD")
	{
	   // получаем значение атрибута vaue
	   int value = GetAttrValue();
	   AnsiString s = IntToStr(value);
	   m_attributes.insert(pair<string,string>("value", s.c_str()));
	   return true;
	}

	if (m_name == "FLASH" || m_name == "DARK")
	{
		AnsiString uuidStr = UUIDCreate() + ".awp";
		m_attributes.insert(pair<string,string>("FileName", uuidStr.c_str()));
		return true;
	}

	if (m_name == "ACTINIC" || m_name == "SATURATOIN" || m_name == "ADDITIONAL")
	{
		int value = 0;
		int duration = 0;
		GetAttrValueDuration(value, duration);
		AnsiString s = IntToStr(value);
		m_attributes.insert(pair<string,string>("value", s.c_str()));
		s = IntToStr(duration);
		m_attributes.insert(pair<string,string>("duration", s.c_str()));
		return true;
	}
	if (m_name == "DARKNESS")
	{
		int d = this->GetAttrDuration();
		AnsiString s = IntToStr(d);
		m_attributes.insert(pair<string,string>("duration", s.c_str()));
		return true;
	}
	if (m_name == "FOFM" || m_name == "FTFM1")
	{
		AnsiString uuidStr = UUIDCreate() + ".awp";
		m_attributes.insert(pair<string,string>("FT", uuidStr.c_str()));
		uuidStr = UUIDCreate() + ".awp";
		m_attributes.insert(pair<string,string>("FM", uuidStr.c_str()));
		uuidStr = UUIDCreate() + ".awp";
		m_attributes.insert(pair<string,string>("DARK", uuidStr.c_str()));
		uuidStr = UUIDCreate() + ".awp";
		m_attributes.insert(pair<string,string>("F0", uuidStr.c_str()));
		uuidStr = UUIDCreate() + ".awp";
		m_attributes.insert(pair<string,string>("F1", uuidStr.c_str()));
		uuidStr = UUIDCreate() + ".awp";
		m_attributes.insert(pair<string,string>("F2", uuidStr.c_str()));
		uuidStr = UUIDCreate() + ".awp";
		m_attributes.insert(pair<string,string>("F3", uuidStr.c_str()));
		uuidStr = UUIDCreate() + ".awp";
		m_attributes.insert(pair<string,string>("F4", uuidStr.c_str()));
		uuidStr = UUIDCreate() + ".awp";
		m_attributes.insert(pair<string,string>("F5", uuidStr.c_str()));

	}
	return false;
}
// todo: Value + Duration
void __fastcall TPam2Event::GetAttrValueDuration(int& value, int& duration)
{
	value = 0;
	duration = 0;
}
// todo: Duration
int __fastcall TPam2Event::GetAttrDuration()
{
    return 0;
}


int __fastcall TPam2Event::GetAttrValue()
{
	int Pos = m_command.Pos("=");
	if (Pos == 0)
		return 0; // -1?

	int value = 0;
	try
	{
	   value = StrToInt(m_command.SubString(Pos+1, m_command.Length() - Pos));
	}
	catch(EConvertError& e)
	{
		// todo: process exception
        value = -1;
	}
	return value;
}

char* __fastcall TPam2Event::GetCommandName(const char* command)
{
	AnsiString result = "";
	AnsiString commandStr = command;
	if (commandStr.Pos("EXP") != 0)
		return "EXP";
	if (commandStr.Pos("GAIN") != 0)
		return "GAIN";
	if (commandStr.Pos("LSAT") != 0)
		return "LSAT";
	if (commandStr.Pos("LACT") != 0)
		return "LACT";
	if (commandStr.Pos("LADD") != 0)
		return "LADD";
	if (commandStr.Pos("LFLASH") != 0)
		return "LFLASH";
	if (commandStr.Pos("SAT") != 0)
		return "SAT";
	if (commandStr.Pos("ACT") != 0)
		return "ACT";
	if (commandStr.Pos("ADD") != 0)
		return "ADD";
	if (commandStr.Pos("ACTINIC") != 0)
		return "ACTINIC";
	if (commandStr.Pos("SATURATION") != 0)
		return "SATURATION";
	if (commandStr.Pos("ADDITIONAL") != 0)
		return "ADDITIONAL";
	if (commandStr.Pos("FLASH") != 0)
		return "FLASH";
	if (commandStr.Pos("DARK") != 0)
		return "DARK";
	if (commandStr.Pos("DARKNESS") != 0)
		return "DARKNESS";
	if (commandStr.Pos("FOFM") != 0)
		return "FOFM";
	if (commandStr.Pos("FTFM1") != 0)
		return "FTFM1";

	return "UNKNOWN";
}

AnsiString TPam2Event::GetAttribute(AnsiString key)
{
   AnsiString result = "";
   string _key = key.c_str();
   string _result = m_attributes[_key];
   result = _result.c_str();
   return result;
}

TPam2Event::TPam2Event(TPam2Event& other)
{
	this->m_command = other.m_command;
	this->m_name = other.m_name;
	this->m_time = other.m_time;
    this->m_attributes = other.m_attributes;
}

