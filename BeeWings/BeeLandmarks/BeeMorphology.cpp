//---------------------------------------------------------------------------

#pragma hdrstop

#include "BeeMorphology.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

TBeeMorphology::TBeeMorphology()
{
	m_points = NULL;
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


	return false;
}

awp2DPoint* TBeeMorphology::ProcessImage(const char* lpFileName)
{
	return NULL;
}
awp2DPoint* TBeeMorphology::ProcessImage(TLFImage* image)
{
	return NULL;
}
