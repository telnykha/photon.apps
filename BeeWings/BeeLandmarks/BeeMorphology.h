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
	TBeePointDector* GetDetector(const char* lpClassName);
public:
   TBeeMorphology();
   ~TBeeMorphology();

   bool Init(const char* lpConfigFile);

   bool ProcessImage(const char* lpFileName, awp2DPoint* points, bool* status);
   bool ProcessImage(TLFImage* image, awp2DPoint* points,  bool* status );

};
#endif
