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
