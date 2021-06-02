//---------------------------------------------------------------------------
#ifndef pamDocumentUnitH
#define pamDocumentUnitH
//---------------------------------------------------------------------------
#include <system.hpp>
#include "pamImageBufferUnit.h"
#include "pamFrameUnit.h"

class TPam2Document
{
private:
	HWND m_hwnd;
protected:
	TPamImageBuffer* m_frameBuffer;
	TPamImageBuffer* m_fofmBuffer;
	TPamImageBuffer* m_ftfm1Buffer;

	TPam2Frame  m_FoFm;
	TPam2Frame  m_FtFm1;

	int m_numFrames;
	int m_currentFrame;

	bool __fastcall HasFrame();
	bool __fastcall HasFoFm();
	bool __fastcall HasFtFm1();

	void __fastcall SetFrameBuffer(TPamImageBuffer* buffer);
	void __fastcall SetFoFmBuffer(TPamImageBuffer* buffer);
	void __fastcall SetFtFm1Buffer(TPamImageBuffer* buffer);

public:
	TPam2Document(HWND wnd = NULL);
	~TPam2Document();

	bool newDocument();
	bool OpenDocument(const UnicodeString& fileName);
	bool SaveDocument(const UnicodeString& fileName);
	bool closeDocument();

	bool __fastcall SetBuffer(TPamImageBuffer* buffer);

	// ��������� ���������� ������ �� ���������.
	awpImage* GetFrame();
	awpImage* GetFo();
	awpImage* GetFm();
	awpImage* GetFt();
	awpImage* GetFm1();
	awpImage* GetFv();
	awpImage* GetFv1();
	awpImage* GetFq();
	awpImage* GetFq1();
	awpImage* GetFo1();
	awpImage* GetFvFm1();
	awpImage* GetYII1();
	awpImage* GetNPQ1();
	awpImage* GetqN1();

	__property bool hasFrame = {read = HasFrame};
	__property bool hasFoFm  = {read = HasFoFm};
	__property bool hasFtFm1 = {read = HasFtFm1};

};
#endif
