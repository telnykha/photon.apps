//---------------------------------------------------------------------------

#pragma hdrstop

#include "pam2DocTimeNode.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

TLFpam2docTimeNode::TLFpam2docTimeNode(ILFPam2docNode* parent) :
ILFPam2docNode(parent)
{
}

// override
bool TLFpam2docTimeNode::SaveXMLNode(TiXmlNode* node)
{
	return false;
}
TiXmlNode* TLFpam2docTimeNode::LoadXMLNode(TiXmlNode* node)
{
	return NULL;
}
const char* TLFpam2docTimeNode::GetName()
{
	return "TLFpam2docTimeNode";
}

TDateTime __fastcall TLFpam2docTimeNode::GetStartTime()
{
	return this->m_startTime;
}
TDateTime __fastcall TLFpam2docTimeNode::GetStopTime()
{
	return this->m_stopTime;
}
EPam2Modes __fastcall TLFpam2docTimeNode::GetMode()
{
	return this->m_mode;
}

void __fastcall TLFpam2docTimeNode::SetStartTime(TDateTime t)
{
	this->m_startTime = t;
}
void __fastcall TLFpam2docTimeNode::SetStopTime(TDateTime t)
{
	this->m_stopTime = t;
}
void __fastcall TLFpam2docTimeNode::SetMode(EPam2Modes mode)
{
    this->m_mode = mode;
}
