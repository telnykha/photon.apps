//---------------------------------------------------------------------------

#ifndef OptoacusticsProcessorH
#define OptoacusticsProcessorH
//---------------------------------------------------------------------------
#include "_LF.h"

class TOAProcessor
{
protected:
	double m_radius;
	double m_threshold;
	bool   m_needContours;
	TLFZones m_contours;
	TLFImage m_source;
	TLFImage m_result;
public:
	TOAProcessor();

	void SetImage(awpImage* image);
	awpImage* GetImage();

	double GetThreshold();
	double GetRadius();
	bool   GetNeedContours();

	void SetThreshold(double value);
	void SetRadius(double value);
	void SetNeedContours(bool value);
};
#endif
