//---------------------------------------------------------------------------

#ifndef pamROIH
#define pamROIH
//---------------------------------------------------------------------------
#include "_LF.h"

#define PAM_IMAGE_WIDTH 1280
#define PAM_IMAGE_HEIGHT 960

class TPam2ROI : public TLFObject
{
protected:
	TLFZone* 	m_zone;
	TLFImage    m_mask;
	// параметры
	double       m_area;
	double       m_min;
	double       m_max;
	double       m_avg;
	double       m_std;

	void        CreateMask();
public:
   TPam2ROI();
   virtual ~TPam2ROI();
   void     SetZone(TLFZone* zone);
   bool     Calculate(awpImage* image);

   __property TLFZone* zone = {read = m_zone};

   __property double Area = {read = m_area};
   __property double Min = {read = m_min};
   __property double Max = {read = m_max};
   __property double Avg = {read = m_avg};
   __property double Std = {read = m_std};
};

#endif
