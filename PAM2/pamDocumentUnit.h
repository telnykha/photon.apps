//---------------------------------------------------------------------------
#ifndef pamDocumentUnitH
#define pamDocumentUnitH
//---------------------------------------------------------------------------
#include <system.hpp>
#include "pamImageBufferUnit.h"
#include "pamFrameUnit.h"
#include "TinyXml.h"

class TPam2Document
{
private:
	HWND m_hwnd;
    UnicodeString m_fileName;
protected:
	TPamImageBuffer* m_frameBuffer;
	TPamImageBuffer* m_fofmBuffer;
	TPamImageBuffer* m_ftfm1Buffer;

	TPam2Frame  m_FoFm;
	TPam2Frame  m_FtFm1;
	TiXmlDocument m_doc;

	int m_numFrames;
	int m_currentFrame;

	TLFObjectList m_events;

	bool __fastcall HasFrame();
	bool __fastcall HasFoFm();
	bool __fastcall HasFtFm1();

	void __fastcall SetFrameBuffer(TPamImageBuffer* buffer);
	void __fastcall SetFoFmBuffer(TPamImageBuffer* buffer);
	void __fastcall SetFtFm1Buffer(TPamImageBuffer* buffer);

	void __fastcall ClearDocument();

public:
	TPam2Document(HWND wnd = NULL);
	~TPam2Document();

	bool __fastcall NewDocument();
	bool __fastcall OpenDocument(const UnicodeString& fileName);
	bool __fastcall SaveDocument(const UnicodeString& fileName);

	bool __fastcall SetBuffer(TPamImageBuffer* buffer);
	void __fastcall AddEvent(const UnicodeString& event);


	void __fastcall BeginRecording();
	void __fastcall EndRecording();
	void __fastcall AbortRecording();

	// ��������� ���������� ������ �� ���������.
	awpImage* GetFrame();
	awpImage* GetFo();
	awpImage* GetFm();
	awpImage* GetFt();
	awpImage* GetFm1();
	awpImage* GetFv();
	awpImage* GetFv1();
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
