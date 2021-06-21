//---------------------------------------------------------------------------
#ifndef pamDocumentUnitH
#define pamDocumentUnitH
//---------------------------------------------------------------------------
#include <system.hpp>
#include <System.Classes.hpp>
#include "pamImageBufferUnit.h"
#include "pamFrameUnit.h"
#include "TinyXml.h"
#include "pamROI.h"
#include "pamImageProcessor.h"


class TPam2Document
{
private:
	HWND m_hwnd;
	UnicodeString m_fileName;
	bool          m_notSaved;
protected:
	TPamImageBuffer* m_frameBuffer;
	TPamImageBuffer* m_fofmBuffer;
	TPamImageBuffer* m_ftfm1Buffer;

	TPam2Frame  m_FoFm;
	TPam2Frame  m_FtFm1;
	TiXmlDocument m_doc;

    TPam2ImageProcessor m_proc;

	int m_numFrames;
	int m_currentFrame;

	TLFObjectList m_events;
	TLFObjectList m_frames;

	TList*  m_threads;

	bool __fastcall LoadFrames();
	void __fastcall LoadFtFm1();

	UnicodeString __fastcall GetDataPath();

	bool __fastcall HasFrame();
	bool __fastcall HasFoFm();
	bool __fastcall HasFtFm1();

	void __fastcall SetFrameBuffer(TPamImageBuffer* buffer);
	void __fastcall SetFoFmBuffer(TPamImageBuffer* buffer);
	void __fastcall SetFtFm1Buffer(TPamImageBuffer* buffer);

	void __fastcall ClearDocument();
	void __fastcall TrminateThread(TObject* sender);

public:
	TPam2Document(HWND wnd = NULL);
	~TPam2Document();

	bool __fastcall NewDocument();
	bool __fastcall OpenDocument(const UnicodeString& fileName);
	bool __fastcall SaveDocument();
	bool __fastcall SaveAsDocument(const UnicodeString& fileName);

	bool __fastcall SetBuffer(TPamImageBuffer* buffer);
	void __fastcall AddEvent(const UnicodeString& event);


	void __fastcall BeginRecording();
	void __fastcall EndRecording();
	void __fastcall AbortRecording();

	static bool __fastcall DeleteDocument(const UnicodeString& fileName);

	void __fastcall ProcessRoi(TPam2ROI* roi);

	//Навигация по фреймам
	void __fastcall First();
	void __fastcall Previous();
	void __fastcall Next();
	void __fastcall Last();
	void __fastcall GoFrame(int index);

	// имена фреймов
	UnicodeString __fastcall GetFoName();
	UnicodeString __fastcall GetFmName();
	UnicodeString __fastcall GetFtName(int index);
	UnicodeString __fastcall GetFm1Name(int index);



	// получение визуализых данных из документа.
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
	__property bool notSaved = {read = m_notSaved};

	__property int NumFrames = {read = m_numFrames};
	__property int CurrentFrame = {read = m_currentFrame};

};
#endif
