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
	if (!m_e1.Load(strFile.c_str()))
		return false;
	strFile = strpath + "\\wing_2_detector.xml";
	if (!m_e2.Load(strFile.c_str()))
		return false;
	strFile = strpath + "\\wing_3_detector.xml";
	if (!m_e3.Load(strFile.c_str()))
		return false;
	strFile = strpath + "\\wing_4_detector.xml";
	if (!m_e4.Load(strFile.c_str()))
		return false;
	strFile = strpath + "\\wing_5_detector.xml";
	if (!m_e5.Load(strFile.c_str()))
		return false;
	strFile = strpath + "\\wing_6_detector.xml";
	if (!m_e6.Load(strFile.c_str()))
		return false;
	strFile = strpath + "\\wing_7_detector.xml";
	if (!m_e7.Load(strFile.c_str()))
		return false;
	strFile = strpath + "\\wing_8_detector.xml";
	if (!m_e8.Load(strFile.c_str()))
		return false;

	return true;
}
bool TMCTObject::ProcessImage(int width, int height, unsigned char* data, int* num, beePoint* result)
{
	for (int i = 0; i < m_zones.GetCount(); i++)
	{
		TLFZone* z = m_zones.GetZone(i);

		awpRect r;
		r.left  = width*z->GetRect()->left() / 100;
		r.right = width*z->GetRect()->right() / 100;
		r.top = height*z->GetRect()->top() / 100;
		r.bottom = height*z->GetRect()->bottom() / 100;
		result[i].x = (r.left + r.right) / 2;
		result[i].y = (r.top + r.bottom) / 2;
		result[i].q = 1;
	}
	
	return true;
}

//---------------------------------------------------------------------------
#pragma package(smart_init)
