//---------------------------------------------------------------------------

#pragma hdrstop

#include "BeeMorphology.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

TBeeMorphology::TBeeMorphology()
{
	m_points = NULL;
	m_width = 960;
	m_height = 540;
}

TBeeMorphology::~TBeeMorphology()
{
	if (m_points != NULL)
		delete m_points;
}

bool TBeeMorphology::Init(const char* lpConfigFile)
{
	TiXmlDocument doc;
	if (!doc.LoadFile(lpConfigFile))
		return false;

	TiXmlElement* e = doc.FirstChildElement("TBeeMorphology");
	if (e == NULL)
		return false;
	if (e->QueryIntAttribute("width", &m_width) !=   TIXML_SUCCESS)
		return false;
	if (e->QueryIntAttribute("height", &m_height) !=   TIXML_SUCCESS)
		return false;
	int count = 0;
	if (e->QueryIntAttribute("count", &count) !=   TIXML_SUCCESS)
		return false;

	TLFString strPath =   LFGetFilePath(lpConfigFile);
    strPath += "\\";
	m_detectors.Clear();
	for(TiXmlNode* child = e->FirstChild("BeePointDector"); child; child = child->NextSibling() )
	{

		TiXmlElement* detector = child->ToElement();
		TLFString className = detector->Attribute("class");
		TLFString detectorName = strPath + detector->Attribute("detector");
		TLFString templateName = strPath + detector->Attribute("template");

		TBeePointDector* bpd = new TBeePointDector(className.c_str());
		if (!bpd->Init(detectorName.c_str(), templateName.c_str()))
		{
			m_detectors.Clear();
			return false;
		}

		m_detectors.Add(bpd);
	}


	return m_detectors.GetCount() == count;
}

awp2DPoint* TBeeMorphology::ProcessImage(const char* lpFileName)
{
	return NULL;
}
awp2DPoint* TBeeMorphology::ProcessImage(TLFImage* image)
{
	return NULL;
}
