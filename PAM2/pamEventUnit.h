//---------------------------------------------------------------------------
#ifndef pamEventUnitH
#define pamEventUnitH
//---------------------------------------------------------------------------
//#include "System.Generics.Collections.hpp"
#include "System.hpp"
#include <map>
#include <string>
#include "TinyXml.h"
#include "LF.h"
using namespace std;

class TPam2Event : public TLFObject
{
protected:
	AnsiString      m_command;
	AnsiString 		m_name;
	unsigned long   m_time;
	std::map <string, string> m_attributes;
	bool __fastcall CreateAttibutes();
	int __fastcall GetAttrValue();
	void __fastcall GetAttrValueDuration(int& value, int& duration);
	int __fastcall GetAttrDuration();
	char* __fastcall GetCommandName(const char* command);
public:
   TPam2Event(unsigned long t, const char* command);
   ~TPam2Event();

   bool __fastcall SaveXmlNode(TiXmlNode* node);
   bool __fastcall LoadXmlNode(TiXmlNode* node);
   AnsiString GetAttribute(AnsiString key);

   __property AnsiString command = {read = m_command};
   __property AnsiString name = {read = m_name};
   __property unsigned long time = {read = m_time};

};

#endif
