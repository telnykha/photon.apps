//---------------------------------------------------------------------------
#pragma hdrstop

#include "MCTObject.h"
TMCTObject::TMCTObject()
{

}
bool TMCTObject::CreateObject(const char* path)
{
	TLFString strpath = path;
	TLFString strFile = strpath + "\\output.xml";
	if (!LFFileExists(strFile))
		return false;
	if (!m_zones.Load(strFile.c_str()))
		return false;
	strFile = strpath + "\\wing_1_detector.xml";
	if (!m_e[0].Load(strFile.c_str()))
		return false;
	strFile = strpath + "\\wing_2_detector.xml";
	if (!m_e[1].Load(strFile.c_str()))
		return false;
	strFile = strpath + "\\wing_3_detector.xml";
	if (!m_e[2].Load(strFile.c_str()))
		return false;
	strFile = strpath + "\\wing_4_detector.xml";
	if (!m_e[3].Load(strFile.c_str()))
		return false;
	strFile = strpath + "\\wing_5_detector.xml";
	if (!m_e[4].Load(strFile.c_str()))
		return false;
	strFile = strpath + "\\wing_6_detector.xml";
	if (!m_e[5].Load(strFile.c_str()))
		return false;
	strFile = strpath + "\\wing_7_detector.xml";
	if (!m_e[6].Load(strFile.c_str()))
		return false;
	strFile = strpath + "\\wing_8_detector.xml";
	if (!m_e[7].Load(strFile.c_str()))
		return false;

	return true;
}
bool TMCTObject::ProcessImage(int width, int height, unsigned char* data, int* num, beePoint* result)
{
	awpImage* image = NULL;
	awpCreateGrayImage(&image, width, height, 3, data);
	awpResizeBilinear(image, 480, 270);
	
	TLFImage img;
	img.SetImage(image);
	awpReleaseImage(&image);
	
	int  w = img.GetImage()->sSizeX;
	int  h = img.GetImage()->sSizeY;
	// todo: change scaner 
	TLFScanner scanner;
	scanner.Scan(w, h);
	double sums[8];
	memset(sums, 0, sizeof(sums));
	for (int i = 0; i < m_zones.GetCount(); i++)
	{
		TLFZone* z = m_zones.GetZone(i);

		awpRect r;
		r.left  = w*z->GetRect()->left() / 100;
		r.right = w*z->GetRect()->right() / 100;
		r.top = h*z->GetRect()->top() / 100;
		r.bottom = h*z->GetRect()->bottom() / 100;

		result[i].x = 0; //(r.left + r.right) / 2;
		result[i].y = 0;// (r.top + r.bottom) / 2;
		result[i].q = 0;

		TLFObjectList* strongs = m_e[i].GetDetector()->GetStrongs();
		for (int j = 0; j < scanner.GetFragmentsCount(); j++)
		{
			awpRect fr = scanner.GetFragmentRect(j);
			int cx = (fr.left + fr.right) / 2;
			int cy = (fr.top + fr.bottom) / 2;
			if (cx > r.left && cx < r.right && cy > r.top && cy < r.bottom)
			{
				// do detection 
				bool detected = true;
				for (int k = 0; k < strongs->GetCount(); k++)
				{
					TCSStrong* s = (TCSStrong*)strongs->Get(k);
					s->Setup(fr, 24);
					double err=0;
					if (!s->Classify(&img, err))
					{
						detected = false;
						break;
					}
				}
				if (detected)
				{
					// save result
					sums[i]++;
					result[i].x += cx;
					result[i].y += cy;
				}

			}
		}
	}

	for (int i = 0; i < 8; i++)
	{

		TLFZone* z = m_zones.GetZone(i);

		awpRect r;
		r.left = w*z->GetRect()->left() / 100;
		r.right = w*z->GetRect()->right() / 100;
		r.top = h*z->GetRect()->top() / 100;
		r.bottom = h*z->GetRect()->bottom() / 100;


		if (sums[i] > 0)
		{
			result[i].x /= sums[i];
			result[i].y /= sums[i];
			result[i].q = 1;
		}
		else
		{
			result[i].q = 0;
			result[i].x = (r.left + r.right) / 2;
			result[i].y = (r.top + r.bottom) / 2;
		}

		result[i].x *= 4;
		result[i].y *= 4;
	}
	
	return true;
}

//---------------------------------------------------------------------------
#pragma package(smart_init)
