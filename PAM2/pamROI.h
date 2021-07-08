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
	TPam2ROIData()
	{
		m_min = 0;
		m_max = 0;
		m_avg = 0;
		m_std = 0;
	}
	TPam2ROIData(double min, double max, double avg, double std)
	{
		m_min = min;
		m_max = max;
		m_avg = avg;
		m_std = std;
	}

	TPam2ROIData& operator =(TPam2ROIData& data)
	{
		if (this != &data)
		{
			this->m_min = data.m_min;
			this->m_max = data.m_max;
			this->m_avg = data.m_avg;
			this->m_std = data.m_std;
		}
		return *this;
	}

	__property double min = {read = m_min, write = m_min};
	__property double max = {read = m_max, write = m_max};
	__property double avg = {read = m_avg, write = m_avg};
	__property double std = {read = m_std, write = m_std};
};

class TPam2ROIFrame : public TLFObject
{
private:
   TPam2ROIData m_Fo;
   TPam2ROIData m_Fm;
   TPam2ROIData m_Ft;
   TPam2ROIData m_Fm1;
   TPam2ROIData m_Fv;
   TPam2ROIData m_Fv1;
   TPam2ROIData m_Fq1;
   TPam2ROIData m_Fo1;
   TPam2ROIData m_YII1;
   TPam2ROIData m_NPQ1;
   TPam2ROIData m_qN;

protected:
	TPam2ROIData* __fastcall GetFo();
	void __fastcall SetFo(TPam2ROIData* value);

	TPam2ROIData* __fastcall GetFm();
	void __fastcall SetFm(TPam2ROIData* value);

	TPam2ROIData* __fastcall GetFt();
	void __fastcall SetFt(TPam2ROIData* value);

	TPam2ROIData* __fastcall GetFm1();
	void __fastcall SetFm1(TPam2ROIData* value);

	TPam2ROIData* __fastcall GetFv();
	void __fastcall SetFv(TPam2ROIData* value);

	TPam2ROIData* __fastcall GetFv1();
	void __fastcall SetFv1(TPam2ROIData* value);

	TPam2ROIData* __fastcall GetFq1();
	void __fastcall SetFq1(TPam2ROIData* value);

	TPam2ROIData* __fastcall GetFo1();
	void __fastcall SetFo1(TPam2ROIData* value);

	TPam2ROIData* __fastcall GetYII1();
	void __fastcall SetYII1(TPam2ROIData* value);

	TPam2ROIData* __fastcall GetNPQ1();
	void __fastcall SetNPQ1(TPam2ROIData* value);

	TPam2ROIData* __fastcall GetqN();
	void __fastcall SetqN(TPam2ROIData* value);

public:
   TPam2ROIFrame();

   __property TPam2ROIData* Fo = {read = GetFo, write = SetFo};
   __property TPam2ROIData* Fm = {read = GetFm, write = SetFm};
   __property TPam2ROIData* Ft = {read = GetFt, write = SetFt};
   __property TPam2ROIData* Fm1 = {read = GetFm1, write = SetFm1};
   __property TPam2ROIData* Fv = {read = GetFv, write = SetFv};
   __property TPam2ROIData* Fv1 = {read = GetFv1, write = SetFv1};
   __property TPam2ROIData* Fq1 = {read = GetFq1, write = SetFq1};
   __property TPam2ROIData* Fo1 = {read = GetFo1, write = SetFo1};
   __property TPam2ROIData* YII1 = {read = GetYII1, write = SetYII1};
   __property TPam2ROIData* NPQ1 = {read = GetNPQ1, write = SetNPQ1};
   __property TPam2ROIData* qN = {read = GetqN, write = SetqN};

};

class TPam2ROI : public TLFObject
{
protected:
	TLFZone* 	m_zone;
	TLFImage    m_mask;
    TLFObjectList m_frames;
	TPam2ROIData m_data;
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
	TPam2ROIData* __fastcall GetData();
public:
   TPam2ROI();
   virtual ~TPam2ROI();
   void     SetZone(TLFZone* zone, bool update = true);
   bool     Calculate(awpImage* image);

   void __fastcall ClearFrames();
   void __fastcall AddFrame(TPam2ROIFrame* frame);
   TPam2ROIFrame* __fastcall GetFrame(int index);

   __property TLFZone* zone = {read = m_zone};
   // значения на текущем изображении
   __property double Area = {read = m_area};
   __property double Min = {read = m_min};
   __property double Max = {read = m_max};
   __property double Avg = {read = m_avg};
   __property double Std = {read = m_std};
   __property TPam2ROIData* Data = {read = GetData};
   __property UnicodeString RoiType = {read = GetRoiType};

   __property int Count = {read = GetCount};
   __property bool Locked = {read = m_locked, write = m_locked};
};

#endif
