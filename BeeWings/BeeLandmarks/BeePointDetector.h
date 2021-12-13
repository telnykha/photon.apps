//---------------------------------------------------------------------------
#ifndef BeePointDetectorH
#define BeePointDetectorH

#include "_LF.h"
#include "fvlcore.h"
//---------------------------------------------------------------------------
class TBeePointDector : public TLFObject
{
protected:
	TSCObjectDetector m_detector;
	FvcTemplate*      m_template;
	awpImage* Preprocess(awpImage* img, awpRect& r);
    TLFString m_strClassName;
public:
	TBeePointDector(const char* className);
	virtual ~TBeePointDector();

	bool Init(const char* lpDetectorName, const char* lpTemplateName);
	bool Detect(TLFImage* img0, awp2DPoint& result , awpRect* rect = NULL);

};
#endif
