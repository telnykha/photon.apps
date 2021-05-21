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
protected:
	TDateTime __fastcall GetStartTime();
	TDateTime __fastcall GetStopTime();
	EPam2Modes __fastcall GetMode();

	void __fastcall SetStartTime(TDateTime t);
	void __fastcall SetStopTime(TDateTime t);
	void __fastcall SetMode(EPam2Modes mode);
public:
	  TLFpam2docTimeNode(ILFPam2docNode* parent);
	  // override
	 virtual bool SaveXMLNode(TiXmlNode* node);
	 virtual TiXmlNode* LoadXMLNode(TiXmlNode* node);
	 virtual const char* GetName();

	 __property TDateTime StartTime = {read= GetStartTime, write = SetStartTime};
	 __property TDateTime StopTime  = {read= GetStopTime, write = SetStopTime};
	 __property EPam2Modes Mode = {read = GetMode, write = SetMode};
};
#endif
