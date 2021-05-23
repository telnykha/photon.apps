//---------------------------------------------------------------------------

#ifndef pam2DocScriptNodeH
#define pam2DocScriptNodeH
#include <System.hpp>
#include "pam2DocINode.h"
//---------------------------------------------------------------------------
class TLFpam2docScriptNode : public ILFPam2docNode
{
private:

public:
	  TLFpam2docScriptNode(ILFPam2docNode* parent);
	  // override
	 virtual bool SaveXMLNode(TiXmlNode* node);
	 virtual TiXmlNode* LoadXMLNode(TiXmlNode* node);
	 virtual const char* GetName();
};
#endif
