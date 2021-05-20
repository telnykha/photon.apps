//---------------------------------------------------------------------------

#pragma hdrstop

#include "pamDocumentUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

TPam2Document::TPam2Document()
{
}
TPam2Document::~TPam2Document()
{
}

bool TPam2Document::newDocument()
{
    return false;
}
bool TPam2Document::OpenDocument(UnicodeString& fileName)
{
	return false;
}
bool TPam2Document::SaveDocument(UnicodeString& fileName)
{
	return false;
}
bool TPam2Document::closeDocument()
{
    return false;
}
