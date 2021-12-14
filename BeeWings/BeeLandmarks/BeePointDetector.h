//---------------------------------------------------------------------------
#ifndef BeePointDetectorH
#define BeePointDetectorH

#include "_LF.h"
//---------------------------------------------------------------------------
class TBeePointDector : public TLFObject
{
protected:
	TSCObjectDetector m_detector;
	TLFString m_strClassName;
public:
	TBeePointDector(const char* className);
	virtual ~TBeePointDector();

	bool Init(const char* lpDetectorName, const char* lpTemplateName);
	bool Detect(TLFImage* img0, awp2DPoint& result , awpRect* rect = NULL);
	const char* GetClassName();
};
#endif