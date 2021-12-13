//---------------------------------------------------------------------------

#ifndef BeeMorphologyH
#define BeeMorphologyH
#include "BeePointDetector.h"
//---------------------------------------------------------------------------
class TBeeMorphology
{
protected:
	TLFObjectList m_detectors;
	awp2DPoint*   m_points;
	int m_width;
    int m_height;


public:
   TBeeMorphology();
   ~TBeeMorphology();

   bool Init(const char* lpConfigFile);

   awp2DPoint* ProcessImage(const char* lpFileName);
   awp2DPoint* ProcessImage(TLFImage* image);

};
#endif
