//---------------------------------------------------------------------------

#pragma hdrstop
#include "pamDocumentUnit.h"
#include "pamMainUnit.h"
#include "pamConsoleUnit.h"
#include "System.IOUtils.hpp"
#include "pamEventUnit.h"
#include "pamRoiProcessThread.h"
#include "pamDistributionUnit.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TinyXML.lib"

static UnicodeString GetDefaultFileName()
{
	LPITEMIDLIST pidl;
	LPMALLOC pShellMalloc;
	wchar_t szDir[MAX_PATH];
	UnicodeString PathStr ;

	if (SUCCEEDED(SHGetMalloc(&pShellMalloc)))
	{
		if (SUCCEEDED(SHGetSpecialFolderLocation(NULL, CSIDL_APPDATA, &pidl)))
		{
			if (SHGetPathFromIDList(pidl, szDir))
			{
				PathStr = szDir ;
				PathStr = PathStr + "\\" ;
			}
			pShellMalloc->Free(pidl);
		}
		pShellMalloc->Release();
	}

	PathStr += L"\\BFL\\";
	if (!DirectoryExists(PathStr))
		CreateDir(PathStr);

	PathStr += L"\\PAM2\\";
	if (!DirectoryExists(PathStr))
		CreateDir(PathStr);


	UnicodeString DataStr = PathStr + "\\default\\";
	if (!DirectoryExists(DataStr))
		CreateDir(DataStr);

	return PathStr + L"\\default.pam2";
}

TPam2Document::TPam2Document(HWND wnd)
{
	m_frameBuffer = NULL;
	m_fofmBuffer  = NULL;
	m_ftfm1Buffer = NULL;

	m_numFrames = 0;
	m_currentFrame = 0;

	m_hwnd = wnd;
	ClearDocument();

	m_fileName =  GetDefaultFileName();
	AnsiString _ansi = m_fileName;

	TiXmlDeclaration* decl = new TiXmlDeclaration( "1.0", "windows-1251", "" );
	m_doc.LinkEndChild( decl );
	TiXmlNode* node = new TiXmlElement("pam2tree");
	m_doc.LinkEndChild( node );

	m_doc.SaveFile(_ansi.c_str());

	m_threads = new TList();
	m_notSaved = false;
}

TPam2Document::~TPam2Document()
{
	ClearDocument();
	m_fileName =  GetDefaultFileName();
	AnsiString _ansi = m_fileName;
	m_doc.SaveFile(_ansi.c_str());
}

bool __fastcall TPam2Document::NewDocument()
{
	ClearDocument();
	m_fileName =  GetDefaultFileName();
	AnsiString _ansi = m_fileName;

	TiXmlDeclaration* decl = new TiXmlDeclaration( "1.0", "windows-1251", "" );
	m_doc.LinkEndChild( decl );

	return m_doc.SaveFile(_ansi.c_str());
}
// загрузка документа из файла
bool __fastcall TPam2Document::OpenDocument(const UnicodeString& fileName)
{
	if (!FileExists(fileName))
		return false;
	AnsiString _ansi = fileName;
	if (!m_doc.LoadFile(_ansi.c_str()))
		return false;
	TiXmlNode* node = m_doc.GetDocument()->FirstChild("pam2tree");
	if (node == NULL)
		return false;
	m_events.Clear();
	// считываем список событий
	for(TiXmlNode* child = node->FirstChild("pam2Event"); child; child = child->NextSibling() )
	{
		TPam2Event* e = new TPam2Event();
		if (e->LoadXmlNode(child)) {
              m_events.Add(e);
		}
	}

	// todo: считываем скрипт
	// todo: считываем начальное состояние
	// todo: считываем области интереса
	this->m_fileName = fileName;
	if (m_events.GetCount() > 0) {
		// из массива events получаем массив изображений
		if (LoadFrames()) {
			// считаем первые два кадра FOFM и FTFM1
			First();
		}
		else
		{
			this->m_fileName =  GetDefaultFileName();
			ClearDocument();
			return false;
		}
	}
	else
		return true;
}
// сохранение документа под тем же именем файла
bool __fastcall TPam2Document::SaveDocument()
{
	m_doc.Clear();
	TiXmlDeclaration* decl = new TiXmlDeclaration( "1.0", "windows-1251", "" );
	m_doc.LinkEndChild( decl );
	TiXmlNode* node = m_doc.GetDocument()->FirstChild("pam2tree");

	// сохраняем список событий, если он есть.
	for (int i = 0; i < m_events.GetCount(); i++)
	{
		TPam2Event* e = (TPam2Event*)m_events.Get(i);
		e->SaveXmlNode(node);
	}

	//todo: сохраняем начальные настройки, если они есть

	//todo: сохраняем скрипт, если он есть

	//todo: сохраняем выделенные области, если они есть.

	AnsiString _ansi = this->m_fileName;
	return m_doc.SaveFile(_ansi.c_str());
}
// сохранение документа под новым именем
// предполагает переписывание результатов измерений в новую папку.
bool __fastcall TPam2Document::SaveAsDocument(const UnicodeString& fileName)
{

	UnicodeString str1 = ExtractFilePath(fileName);
	UnicodeString str2 = ChangeFileExt(ExtractFileName(fileName), "");
	UnicodeString dataPath = str1+str2;

	if (DirectoryExists(dataPath)) {
		// удаляем все файлы в папке
		if (!TDirectory::IsEmpty(dataPath))
		{
			System::DynamicArray<System::UnicodeString> arr = TDirectory::GetFiles(dataPath);
			for (int i = arr.Length-1; i >= 0; i--)
			{
				DeleteFile(arr[i]);
			}
		}
	}
	else
		CreateDir(dataPath);
	// копируем файлы
	UnicodeString str3 = ExtractFilePath(m_fileName);
	UnicodeString str4 = ChangeFileExt(ExtractFileName(m_fileName), "");
	UnicodeString srcPath = str3+str4;
	System::DynamicArray<System::UnicodeString> arr = TDirectory::GetFiles(srcPath);
	for(int i = 0; i < arr.Length; i++)
	{
		UnicodeString dstName = dataPath + L"\\"+ ExtractFileName(arr[i]);
		CopyFile(arr[i].c_str(), dstName.c_str(), false);
	}

	AnsiString _ansi = fileName;
	bool result = m_doc.SaveFile(_ansi.c_str());
	if (result)
	{
		// сохранение прошло успешно
		m_notSaved = false;
		m_fileName = fileName;
	}
	return result;
}

bool __fastcall TPam2Document::DeleteDocument(const UnicodeString& fileName)
{
 	UnicodeString str1 = ExtractFilePath(fileName);
	UnicodeString str2 = ChangeFileExt(ExtractFileName(fileName), "");
	UnicodeString dataPath = str1+str2;

	if (DirectoryExists(dataPath)) {
		// удаляем все файлы в папке
		if (!TDirectory::IsEmpty(dataPath))
		{
			System::DynamicArray<System::UnicodeString> arr = TDirectory::GetFiles(dataPath);
			for (int i = arr.Length-1; i >= 0; i--)
			{
				DeleteFile(arr[i]);
			}
		}
	}

	return DeleteFile(fileName);
}


void __fastcall TPam2Document::ClearDocument()
{
	m_notSaved = false;
	UnicodeString str = GetDefaultFileName();
	str = ExtractFilePath(str);
	str += L"default\\";

	if (!TDirectory::IsEmpty(str))
	{
		System::DynamicArray<System::UnicodeString> arr = TDirectory::GetFiles(str);
		for (int i = arr.Length-1; i >= 0; i--)
		{
			DeleteFile(arr[i]);
		}
	}
	m_numFrames    = 0;
	m_currentFrame = 0;

	m_FoFm.Clear();
	m_FtFm1.Clear();

	if (m_frameBuffer != NULL)
	{
		delete m_frameBuffer;
		m_frameBuffer = NULL;
	}
	if (m_fofmBuffer != NULL)
	{
		delete m_fofmBuffer;
		m_fofmBuffer = NULL;
	}
	if (m_ftfm1Buffer != NULL)
	{
		delete m_ftfm1Buffer;
        m_ftfm1Buffer = NULL;
	}
	m_events.Clear();
	m_frames.Clear();

	m_doc.Clear();
}

awpImage* TPam2Document::GetFrame()
{
	awpImage* result = NULL;
	if (this->m_frameBuffer != NULL)
	{
		awpCopyImage(this->m_frameBuffer->getImage(0), &result);
		return result;
	}
	return NULL;
}

awpImage* TPam2Document::GetFo()
{
/*	awpImage* result = NULL;
	awpCopyImage(m_FoFm.Frame0, &result);
	return result;*/
	return m_proc.GetFo();
}
awpImage* TPam2Document::GetFm()
{
/*	awpImage* result = NULL;
	awpCopyImage(m_FoFm.Frame1, &result);
	return result;*/
	return m_proc.GetFm();
}
awpImage* TPam2Document::GetFt()
{
/*	awpImage* result = NULL;
	awpCopyImage(m_FtFm1.Frame0, &result);
	return result;*/
	return m_proc.GetFt();
}
awpImage* TPam2Document::GetFm1()
{
/*	awpImage* result = NULL;
	awpCopyImage(m_FtFm1.Frame1, &result);
	return result;*/
    return m_proc.GetFm1();
}
awpImage* TPam2Document::GetFv()
{
/*	awpImage* result = NULL;

	awpImage* Fo = m_FoFm.Frame0;
	awpImage* Fm = m_FoFm.Frame1;

	awpCreateImage(&result, Fo->sSizeX, Fo->sSizeY, 1, AWP_FLOAT);

	AWPFLOAT* _Fo = (AWPFLOAT*)Fo->pPixels;
	AWPFLOAT* _Fm = (AWPFLOAT*)Fm->pPixels;
	AWPFLOAT* _result = (AWPFLOAT*)result->pPixels;

	for (int i = 0; i < Fo->sSizeX*Fo->sSizeY; i++) {
		_result[i] = _Fm[i] - _Fo[i];
	}

	return result;*/
	return m_proc.GetFv();
}
awpImage* TPam2Document::GetFv1()
{
/*	awpImage* result = NULL;

	awpImage* Fo = this->GetFo1();
	awpImage* Fm = m_FtFm1.Frame1;

	awpCreateImage(&result, Fo->sSizeX, Fo->sSizeY, 1, AWP_FLOAT);

	AWPFLOAT* _Fo = (AWPFLOAT*)Fo->pPixels;
	AWPFLOAT* _Fm = (AWPFLOAT*)Fm->pPixels;
	AWPFLOAT* _result = (AWPFLOAT*)result->pPixels;

	for (int i = 0; i < Fo->sSizeX*Fo->sSizeY; i++) {
		_result[i] = _Fm[i] - _Fo[i];
	}
	awpReleaseImage(&Fo);
	return result; */
	return m_proc.GetFv1();
}
awpImage* TPam2Document::GetFq1()
{
 /*	awpImage* result = NULL;

	awpImage* Ft = m_FtFm1.Frame0;
	awpImage* Fm1 = m_FtFm1.Frame1;

	awpCreateImage(&result, Ft->sSizeX, Ft->sSizeY, 1, AWP_FLOAT);

	AWPFLOAT* _Ft = (AWPFLOAT*)Ft->pPixels;
	AWPFLOAT* _Fm1 = (AWPFLOAT*)Fm1->pPixels;
	AWPFLOAT* _result = (AWPFLOAT*)result->pPixels;

	for (int i = 0; i < Ft->sSizeX*Ft->sSizeY; i++) {
		_result[i] = _Fm1[i] - _Ft[i];
	}

	return result;        */
	return m_proc.GetFq1();
}
awpImage* TPam2Document::GetFo1()
{
/*	awpImage* result = NULL;

	awpImage* Fo = m_FoFm.Frame0;
	awpImage* Fm = m_FoFm.Frame1;
	awpImage* Fm1 = m_FtFm1.Frame1;
	awpImage* Fv  = this->GetFv();

	awpCreateImage(&result, Fo->sSizeX, Fo->sSizeY, 1, AWP_FLOAT);

	AWPFLOAT* _Fo = (AWPFLOAT*)Fo->pPixels;
	AWPFLOAT* _Fm = (AWPFLOAT*)Fm->pPixels;
	AWPFLOAT* _Fm1 = (AWPFLOAT*)Fm1->pPixels;
	AWPFLOAT* _Fv = (AWPFLOAT*)Fv->pPixels;

	AWPFLOAT* _result = (AWPFLOAT*)result->pPixels;


	for (int i = 0; i < Fo->sSizeX*Fo->sSizeY; i++) {
		float a = _Fv[i] / (_Fm[i]);
		float b = _Fo[i] / (_Fm1[i]);
		float c = a + b;
		if (fabs(c) < 1) {
			c = 1;
		}
		_result[i] = _Fo[i] /c;
	}
	awpReleaseImage(&Fv);
	return result;  */
	return m_proc.GetFo1();
}
awpImage* TPam2Document::GetFvFm1()
{
/*	awpImage* result = NULL;

	awpImage* Fv1 = this->GetFv1();
	awpImage* Fm1 = m_FtFm1.Frame1;

	awpCreateImage(&result, Fv1->sSizeX, Fv1->sSizeY, 1, AWP_FLOAT);

	AWPFLOAT* _Fv1 = (AWPFLOAT*)Fv1->pPixels;
	AWPFLOAT* _Fm1 = (AWPFLOAT*)Fm1->pPixels;
	AWPFLOAT* _result = (AWPFLOAT*)result->pPixels;

	for (int i = 0; i < Fv1->sSizeX*Fv1->sSizeY; i++) {
		_result[i] = _Fv1[i] / (_Fm1[i] + 0.0001);
	}
	awpReleaseImage(&Fv1);
	return result;     */
	return m_proc.GetFvFm1();
}
awpImage* TPam2Document::GetYII1()
{
 /*	awpImage* result = NULL;

	awpImage* Fq1 = this->GetFq1();
	awpImage* Fm1 = m_FtFm1.Frame1;

	awpCreateImage(&result, Fq1->sSizeX, Fq1->sSizeY, 1, AWP_FLOAT);

	AWPFLOAT* _Fq1 = (AWPFLOAT*)Fq1->pPixels;
	AWPFLOAT* _Fm1 = (AWPFLOAT*)Fm1->pPixels;
	AWPFLOAT* _result = (AWPFLOAT*)result->pPixels;

	for (int i = 0; i < Fq1->sSizeX*Fq1->sSizeY; i++) {
		float a = _Fm1[i];
		if (a == 0) a = 0.1;
		_result[i] = _Fq1[i] / a;
	}
	awpReleaseImage(&Fq1);
	return result;  */
	return m_proc.GetYII1();

}

awpImage* TPam2Document::GetNPQ1()
{
/*	awpImage* result = NULL;

	awpImage* Fm = m_FoFm.Frame1;
	awpImage* Fm1 = m_FtFm1.Frame1;

	awpCreateImage(&result, Fm->sSizeX, Fm->sSizeY, 1, AWP_FLOAT);

	AWPFLOAT* _Fm = (AWPFLOAT*)Fm->pPixels;
	AWPFLOAT* _Fm1 = (AWPFLOAT*)Fm1->pPixels;
	AWPFLOAT* _result = (AWPFLOAT*)result->pPixels;

	for (int i = 0; i < Fm1->sSizeX*Fm1->sSizeY; i++) {
	    float a = _Fm1[i];
		if (a == 0) a = 0.1;
		_result[i] = (_Fm[i] - _Fm1[i])/a;
	}
	return result; */
	return m_proc.GetNPQ1();
}
awpImage* TPam2Document::GetqN1()
{
 /*
	awpImage* result = NULL;

	awpImage* Fm = m_FoFm.Frame1;
	awpImage* Fm1 = m_FtFm1.Frame1;
	awpImage* Fo1 = this->GetFo1();

	awpCreateImage(&result, Fm->sSizeX, Fm->sSizeY, 1, AWP_FLOAT);

	AWPFLOAT* _Fm = (AWPFLOAT*)Fm->pPixels;
	AWPFLOAT* _Fm1 = (AWPFLOAT*)Fm1->pPixels;
	AWPFLOAT* _Fo1 = (AWPFLOAT*)Fo1->pPixels;
	AWPFLOAT* _result = (AWPFLOAT*)result->pPixels;

	for (int i = 0; i < Fm1->sSizeX*Fm1->sSizeY; i++) {
		_result[i] = (_Fm[i] - _Fm1[i])/(_Fm[i] - _Fo1[i]);
	}
    awpReleaseImage(&Fo1);
	return result;*/
    return m_proc.GetqN1();
}


bool __fastcall TPam2Document::HasFrame()
{
	return m_frameBuffer != NULL;
}

bool __fastcall TPam2Document::HasFoFm()
{
	return m_FoFm.Frame0 != NULL && m_FoFm.Frame1 != NULL;
}

bool __fastcall TPam2Document::HasFtFm1()
{
	return m_FtFm1.Frame0 != NULL && m_FtFm1.Frame1 != NULL;
}
/*

*/
bool __fastcall TPam2Document::SetBuffer(TPamImageBuffer* buffer)
{
	if (buffer == NULL)
		return false;

	if (buffer->BufferType == pam2bfDark || buffer->BufferType == pam2bfFlash)
	{
		// set frame buffer
		SetFrameBuffer(buffer);
	}
	else if (buffer->BufferType == pam2bfFoFm)
	{
		// set FoFm
		SetFoFmBuffer(buffer);
	}
	else //if (buffer->BufferType == pam2bfFtFm1)
	{
		// set FtFm1
		SetFtFm1Buffer(buffer);
	}

	return true;
}

void __fastcall TPam2Document::SetFrameBuffer(TPamImageBuffer* buffer)
{
	if (this->m_frameBuffer != NULL) {
		delete this->m_frameBuffer;
	}
	m_frameBuffer = new TPamImageBuffer(*buffer);
	// notify UI to update frame buffer
	::SendMessage(pamMainForm->Handle, WM_USER+1, 0,0);
}

void __fastcall TPam2Document::SetFoFmBuffer(TPamImageBuffer* buffer)
{
	if (m_fofmBuffer != NULL)
	{
		delete m_fofmBuffer;
	}
	m_fofmBuffer = new TPamImageBuffer(*buffer);
	m_FoFm.SetBuffer(m_fofmBuffer);
	m_proc.FoFm = &m_FoFm;
	::SendMessage(pamMainForm->Handle, WM_USER+1, 0,0);
	m_numFrames = 1;
}

void __fastcall TPam2Document::SetFtFm1Buffer(TPamImageBuffer* buffer)
{
	if (m_ftfm1Buffer != NULL)
	{
		delete m_ftfm1Buffer;
	}
	m_ftfm1Buffer = new TPamImageBuffer(*buffer);
	m_FtFm1.SetBuffer(m_ftfm1Buffer);
    m_proc.FtFm1 = &m_FtFm1;
	if (m_numFrames == 1)
	{
		m_numFrames = 2;
	}
	::SendMessage(pamMainForm->Handle, WM_USER+1, 0,0);
}

void __fastcall TPam2Document::AddEvent(const UnicodeString& event)
{
	ConsoleForm->Memo1->Lines->Add(event);
	AnsiString eventStr = event;

	TPam2Event* e = new TPam2Event(GetTickCount(), eventStr.c_str());
	// сохраняем изображения
	UnicodeString str = GetDefaultFileName();
	str = ExtractFilePath(str);
	str += L"default\\";

	if (e->name == "FLASH" || e->name == "DARK")
	{
		AnsiString fileName = str + e->GetAttribute("FileName");
		awpImage* img = m_frameBuffer->getImage(0);
		if (img != NULL){
			awpSaveImage(fileName.c_str(), img);
		}
	}
	else if (e->name == "FOFM" || e->name == "FTFM1")
	{

		TPamImageBuffer* buf = NULL;
		TPam2Frame*      frame = NULL;
		if (e->name == "FOFM")
		{
			buf = m_fofmBuffer;
			frame = &m_FoFm;
		}
		else if (e->name == "FTFM1")
		{
			buf = m_ftfm1Buffer;
			frame = &m_FtFm1;
		}

	   AnsiString fileName = str + e->GetAttribute("FT");
	   awpSaveImage(fileName.c_str(), frame->Frame0);
	   fileName = str + e->GetAttribute("FM");
	   awpSaveImage(fileName.c_str(), frame->Frame1);
	}
	m_events.Add(e);
}

void __fastcall TPam2Document::BeginRecording()
{
	// todo: добавить в документ начальсное состояние оборудования
	// и области интереса
}
void __fastcall TPam2Document::EndRecording()
{
	TiXmlNode* node = m_doc.GetDocument()->FirstChild("pam2tree");

	for (int i = 0; i < m_events.GetCount(); i++)
	{
		TPam2Event* e = (TPam2Event*)m_events.Get(i);
		e->SaveXmlNode(node);
	}

	AnsiString _ansi = m_fileName;
	m_doc.SaveFile(_ansi.c_str());
    this->LoadFrames();
	m_notSaved = true;

}
void __fastcall TPam2Document::AbortRecording()
{
	   this->ClearDocument();
}

bool __fastcall TPam2Document::LoadFrames()
{
	 m_frames.Clear();
	 for (int i = 0; i < m_events.GetCount(); i++)
	 {
		TPam2Event* e = (TPam2Event*)m_events.Get(i);
		AnsiString str = e->GetAttribute("name");
		if (str == "FOFM" || str == "FTFM1")
		{
			TPam2Event* e1 = new TPam2Event(*e);
			m_frames.Add(e1);
		}
	 }
	 this->m_numFrames = m_frames.GetCount();
	 return m_frames.GetCount() > 0;
}

void __fastcall TPam2Document::First()
{
	UnicodeString srcPath = GetDataPath();

   //todo: мы предполагаем, что первое изображение в списке будет FOFT,
   // хоть и нет никаких причин, чтобы этому не верить, но надо убедиться
   TPam2Event* e = (TPam2Event*)m_frames.Get(0);
   AnsiString ftFileName = srcPath + e->GetAttribute("FT");
   AnsiString fmFileName = srcPath + e->GetAttribute("FM");

   awpImage* img0 = NULL;
   awpImage* img1 = NULL;

   awpLoadImage(ftFileName.c_str(), &img0);
   awpLoadImage(fmFileName.c_str(), &img1);
   m_FoFm.SetFrames(img0, img1);
   m_proc.SetFoFm(img0, img1);

   _AWP_SAFE_RELEASE_(img0)
   _AWP_SAFE_RELEASE_(img1)

   // считываем второе изображение это уже изображение FTFM1

   e = (TPam2Event*)m_frames.Get(1);
   ftFileName = srcPath + e->GetAttribute("FT");
   fmFileName = srcPath + e->GetAttribute("FM");

   awpLoadImage(ftFileName.c_str(), &img0);
   awpLoadImage(fmFileName.c_str(), &img1);
   m_FtFm1.SetFrames(img0, img1);
   m_proc.SetFtFm1(img0, img1);

   _AWP_SAFE_RELEASE_(img0)
   _AWP_SAFE_RELEASE_(img1)

   this->m_numFrames = m_frames.GetCount();
   this->m_currentFrame = 1;

}
void __fastcall TPam2Document::Previous()
{
	m_currentFrame--;
	if(m_currentFrame  < 1)
	{
		m_currentFrame = 1;
		return;
	}
}
void __fastcall TPam2Document::Next()
{
	m_currentFrame++;
	if(m_currentFrame  > m_frames.GetCount() -1)
	{
		m_currentFrame = m_frames.GetCount() -1;
		return;
	}
	LoadFtFm1();
}
void __fastcall TPam2Document::Last()
{
	m_currentFrame = m_frames.GetCount() -1;
	LoadFtFm1();
}

UnicodeString __fastcall TPam2Document::GetDataPath()
{
	UnicodeString str3 = ExtractFilePath(m_fileName);
	UnicodeString str4 = ChangeFileExt(ExtractFileName(m_fileName), "");
	UnicodeString srcPath = str3+str4 + L"\\";
	return     srcPath;
}

void __fastcall TPam2Document::LoadFtFm1()
{
   TPam2Event* e = (TPam2Event*)m_frames.Get(m_currentFrame);
	UnicodeString srcPath = GetDataPath();

   AnsiString ftFileName = srcPath + e->GetAttribute("FT");
   AnsiString fmFileName = srcPath + e->GetAttribute("FM");

   awpImage* img0 = NULL;
   awpImage* img1 = NULL;

   awpLoadImage(ftFileName.c_str(), &img0);
   awpLoadImage(fmFileName.c_str(), &img1);
   m_FtFm1.SetFrames(img0, img1);
   m_proc.SetFtFm1(img0, img1);

   _AWP_SAFE_RELEASE_(img0)
   _AWP_SAFE_RELEASE_(img1)
	::SendMessage(pamMainForm->Handle, WM_USER+1, 0,0);
}

void __fastcall TPam2Document::GoFrame(int index)
{
	if (index < 1 || index >= this->m_numFrames || index == m_currentFrame) {
		return;
	}

	this->m_currentFrame = index;
	this->LoadFtFm1();
}

void __fastcall TPam2Document::ProcessRoi(TPam2ROI* roi)
{
	if (roi == NULL) {
		return;
	}

   Tpam2RoiProcessThread* t = new Tpam2RoiProcessThread(true);
   t->FreeOnTerminate = true;
   roi->Locked = true;
   t->roi = roi;
   t->doc = this;
   t->OnTerminate = TrminateThread;
   m_threads->Add(t);
   t->Start();
}

void __fastcall TPam2Document::TrminateThread(TObject* sender)
{
	Tpam2RoiProcessThread* t = (Tpam2RoiProcessThread*)sender;
    t->roi->Locked = false;
    pam2ROIForm->ChangeItem(t->roi);
	m_threads->Remove(t);
}

UnicodeString __fastcall TPam2Document::GetFoName()
{
	UnicodeString srcPath = GetDataPath();
	TPam2Event* e = (TPam2Event*)m_frames.Get(0);
	AnsiString ftFileName = srcPath + e->GetAttribute("FT");
	UnicodeString result = ftFileName;
	return result;
}

UnicodeString __fastcall TPam2Document::GetFmName()
{
	UnicodeString srcPath = GetDataPath();
	TPam2Event* e = (TPam2Event*)m_frames.Get(0);
	AnsiString ftFileName = srcPath + e->GetAttribute("FM");
	UnicodeString result = ftFileName;
	return result;

}
UnicodeString __fastcall TPam2Document::GetFtName(int index)
{
	UnicodeString srcPath = GetDataPath();
	TPam2Event* e = (TPam2Event*)m_frames.Get(index);
	AnsiString ftFileName = srcPath + e->GetAttribute("FT");
	UnicodeString result = ftFileName;
	return result;
}
UnicodeString __fastcall TPam2Document::GetFm1Name(int index)
{
	UnicodeString srcPath = GetDataPath();
	TPam2Event* e = (TPam2Event*)m_frames.Get(index);
	AnsiString ftFileName = srcPath + e->GetAttribute("FM");
	UnicodeString result = ftFileName;
	return result;
}



