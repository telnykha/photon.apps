//---------------------------------------------------------------------------

#ifndef pamROIH
#define pamROIH
//---------------------------------------------------------------------------
#include "_LF.h"
#include <System.hpp>

#define PAM_IMAGE_WIDTH 1280
#define PAM_IMAGE_HEIGHT 960

class TPam2ROIData : public TLFObject
{
protected:
	double m_min;
	double m_max;
	double m_avg;
	double m_std;
public:
	TPam2ROIData(double min, double max, double avg, double std)
	{
		m_min = min;
		m_max = max;
		m_avg = avg;
		m_std = std;
	}

	__property double min = {read = m_min};
	__property double max = {read = m_max};
	__property double avg = {read = m_avg};
	__property double std = {read = m_std};
};

class TPam2ROI : public TLFObject
{
protected:
	TLFZone* 	m_zone;
	TLFImage    m_mask;

	TLFObjectList m_Fo;
	TLFObjectList m_Fm;
	TLFObjectList m_Ft;
	TLFObjectList m_Fm1;
	TLFObjectList m_Fv;
	TLFObjectList m_Fv1;
	TLFObjectList m_Fq1;
	TLFObjectList m_Fo1;
	TLFObjectList m_FvFm1;
	TLFObjectList m_YII1;
	TLFObjectList m_NPQ1;
	TLFObjectList m_qN1;

	// параметры
	double       m_area;
	double       m_min;
	double       m_max;
	double       m_avg;
	double       m_std;

	// захвачен потоком вычисления
	bool        m_locked;

	void        CreateMask();
	UnicodeString __fastcall GetRoiType();
	int __fastcall GetCount();
public:
   TPam2ROI();
   virtual ~TPam2ROI();
   void     SetZone(TLFZone* zone);
   bool     Calculate(awpImage* image);

   void __fastcall GlearData();
   void __fastcall AddData(TPam2ROIData* data);

   TPam2ROIData* __fastcall GetData(int index);

   __property TLFZone* zone = {read = m_zone};
   // значения на текущем изображении
   __property double Area = {read = m_area};
   __property double Min = {read = m_min};
   __property double Max = {read = m_max};
   __property double Avg = {read = m_avg};
   __property double Std = {read = m_std};
   __property UnicodeString RoiType = {read = GetRoiType};

   __property int Count = {read = GetCount};
   __property bool Locked = {read = m_locked, write = m_locked};
};

#endif
