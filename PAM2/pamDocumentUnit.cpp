//---------------------------------------------------------------------------

#pragma hdrstop

#include "pamDocumentUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

TPam2Document::TPam2Document()
{
	m_frameBuffer = NULL;
	m_fofmBuffer  = NULL;
	m_ftfm1Buffer = NULL;

	m_numFrames = 0;
	m_currentFrame = 0;

}
TPam2Document::~TPam2Document()
{
    //
}

bool TPam2Document::newDocument()
{
    return false;
}
bool TPam2Document::OpenDocument(const UnicodeString& fileName)
{
	return false;
}
bool TPam2Document::SaveDocument(const UnicodeString& fileName)
{
	return false;
}
bool TPam2Document::closeDocument()
{
    return false;
}

awpImage* TPam2Document::GetFrame()
{
    return NULL;
}
awpImage* TPam2Document::GetFo()
{
    return NULL;
}
awpImage* TPam2Document::GetFm()
{
    return NULL;
}
awpImage* TPam2Document::GetFt()
{
    return NULL;
}
awpImage* TPam2Document::GetFm1()
{
    return NULL;
}
awpImage* TPam2Document::GetFv()
{
    return NULL;
}
awpImage* TPam2Document::GetFv1()
{
    return NULL;
}
awpImage* TPam2Document::GetFq()
{
    return NULL;
}
awpImage* TPam2Document::GetFq1()
{
    return NULL;
}
awpImage* TPam2Document::GetFo1()
{
    return NULL;
}
awpImage* TPam2Document::GetFvFm1()
{
    return NULL;
}
awpImage* TPam2Document::GetYII1()
{
	return NULL;
}
awpImage* TPam2Document::GetNPQ1()
{
	return NULL;
}
awpImage* TPam2Document::GetqN1()
{
	return NULL;
}


bool __fastcall TPam2Document::HasFrame()
{
	return m_frameBuffer != NULL;
}

bool __fastcall TPam2Document::HasFoFm()
{
	return m_numFrames > 0;
}

bool __fastcall TPam2Document::HasFtFm1()
{
    return m_numFrames > 1;
}

