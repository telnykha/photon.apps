//---------------------------------------------------------------------------

#pragma hdrstop

#include "pamROI.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

TPam2ROI::TPam2ROI()
{
   m_zone =NULL;
   m_area = 0;
   m_min = 0;
   m_max = 0;
   m_avg = 0;
   m_std = 0;
   m_locked = false;
}
TPam2ROI::~TPam2ROI()
{
   if (m_zone != NULL) {
	   delete m_zone;
   }
}
// вычисление параметров.
bool TPam2ROI::Calculate(awpImage* image)
{
	 if (image == NULL) {
		return false;
	 }
	 if (image->sSizeX != PAM_IMAGE_WIDTH) {
		 return false;
	 }
	 if (image->sSizeY != PAM_IMAGE_HEIGHT) {
		 return false;
	 }
	 if (image->dwType != AWP_FLOAT) {
		 return false;
	 }

	 AWPBYTE*  m = (AWPBYTE*)(m_mask.GetImage())->pPixels;
	 AWPFLOAT* f = (AWPFLOAT*)image->pPixels;


	 // вычисление параметров.
	 double area = 0;
	 double avg = 0;
	 double min = f[0];
	 double max = f[0];
	 double std = 0;

	 for (int i = 0; i < PAM_IMAGE_WIDTH*PAM_IMAGE_HEIGHT; i++) {
		if (m[i] ==1)
		{
			area += 1;
			avg  += f[i];
			std  += (f[i]*f[i]);
			if (f[i] < min) {
				min = f[i];
			}
			if (f[i] > max) {
			   max = f[i];
			}
		}
	 }

	 if (area == 0) {
         return false;
	 }

	 m_area = area;
	 m_avg = avg / area;
	 m_min = min;
	 m_max = max;
	 m_std = std/area;
     m_std = sqrt(m_std - m_avg*m_avg);
}

void  TPam2ROI::CreateMask()
{
   TLFZones zones;
   zones.AddZone(new TLFZone(*m_zone));

   awpImage* image = NULL;
   awpCreateImage(&image, PAM_IMAGE_WIDTH, PAM_IMAGE_HEIGHT, 1, AWP_BYTE);
   awpImage* mask  = zones.GetMaskImage(image, false);
   m_mask.SetImage(mask);
   _AWP_SAFE_RELEASE_(image);
   _AWP_SAFE_RELEASE_(mask);

}

void     TPam2ROI::SetZone(TLFZone* zone)
{
	if (m_zone != NULL) {
		delete m_zone;
	}
	m_zone = new TLFZone(*zone);
	// маска пересчитывается всякий раз, когда устанавливается зона? может
	// быть имеет смысл маску пересчитывать не так части, а только по необходимости
	// например в Calculate?
	CreateMask();
}
UnicodeString __fastcall TPam2ROI::GetRoiType()
{
   if (m_locked) {
        return "Вычисление....";
   }

	if (m_zone == NULL) {
		return L"Неизвестный объект";
	}
	UnicodeString strRoiType = L"";
	switch(m_zone->GetZoneType())
	{
		case ZTCircle:
			strRoiType = L"Окружность";
		break;
		case ZTRect:
			strRoiType = L"Прямоугольник";
		break;
		case ZTContour:
			strRoiType = L"Многоугольник";
		break;

	}
	return  strRoiType;
}

int __fastcall TPam2ROI::GetCount()
{
	return m_Ft.GetCount();
}

void __fastcall TPam2ROI::GlearData()
{
	m_Ft.Clear();
}
void __fastcall TPam2ROI::AddData(TPam2ROIData* data)
{
	m_Ft.Add(data);
}
TPam2ROIData* __fastcall TPam2ROI::GetData(int index)
{
	if (index < 0 || index >= m_Ft.GetCount()) {
		 return NULL;
	}
	return (TPam2ROIData*)m_Ft.Get(index);
}



