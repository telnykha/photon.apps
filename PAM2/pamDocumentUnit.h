//---------------------------------------------------------------------------
#ifndef pamDocumentUnitH
#define pamDocumentUnitH
//---------------------------------------------------------------------------
#include <system.hpp>

class TPam2Document
{
protected:
public:
	TPam2Document();
	~TPam2Document();

	bool newDocument();
	bool OpenDocument(UnicodeString& fileName);
	bool SaveDocument(UnicodeString& fileName);
	bool closeDocument();
};
#endif
