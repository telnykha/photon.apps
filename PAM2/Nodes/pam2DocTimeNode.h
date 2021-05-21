//---------------------------------------------------------------------------
#ifndef pam2DocTimeNodeH
#define pam2DocTimeNodeH
//---------------------------------------------------------------------------
#include <System.hpp>
#include "pam2DocINode.h"
typedef enum {manual, automaic}EPam2Modes;
class TLFpam2docTimeNode : public ILFPam2docNode
{
private:
	 TDateTime m_startTime;
	 TDateTime m_stopTime;
	 EPam2Modes m_mode;
public:
	  TLFpam2docTimeNode(ILFPam2docNode* parent);
	  // override
	 virtual bool SaveXMLNode(TiXmlNode* node);
	 virtual TiXmlNode* LoadXMLNode(TiXmlNode* node);
	 virtual const char* GetName();
};
#endif
