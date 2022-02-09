//---------------------------------------------------------------------------
 #include <vcl.h>
#pragma hdrstop

#include "priInitUnit.h"
//---------------------------------------------------------------------------


TPriFilter::TPriFilter(TPriInitFile* file)
{
	m_file = file;
	m_index = 0;
	m_focus = 1000;
	m_aperture = 0;
	m_exposure = 100;
	m_filterName = L"не установлен";
}

TPriFilter::TPriFilter(TPriInitFile* file, int index, int focus, int aperture, int exposure, const char* name)
{
	m_file = file;
	m_index = index;
	m_focus = focus;
	m_aperture = aperture;
	m_exposure = exposure;
    m_filterName = name;
}

TPriFilter::~TPriFilter()
{}

bool __fastcall TPriFilter::Init(TiXmlElement* element)
{
	if (element == NULL)
		return false;

	element->QueryIntAttribute("index", &m_index);
	element->QueryIntAttribute("focus", &m_focus);
	element->QueryIntAttribute("aperture", &m_aperture);
	element->QueryIntAttribute("exposure", &m_exposure);

	TLFString str = element->Attribute("name");
	m_filterName = str.c_str();
	return true;
}

bool __fastcall TPriFilter::Save(TiXmlElement* element)
{
	if (element == NULL)
		return false;

	AnsiString s = m_filterName.c_str();
	element->SetAttribute("name", s.c_str());
	element->SetAttribute("index", m_index);
	element->SetAttribute("focus", m_focus);
	element->SetAttribute("aperture", m_aperture);
	element->SetAttribute("exposure", m_exposure);

	return true;
}

void __fastcall TPriFilter::SetName(const UnicodeString name)
{
	m_filterName = name;
	if (m_file != NULL )
		m_file->Save();
}

void __fastcall TPriFilter::SetIndex(const int index)
{
	 m_index = index;
	if (m_file != NULL)
		m_file->Save();
}

void __fastcall TPriFilter::SetFocus(const int focus)
{
	m_focus = focus;
	if (m_file != NULL)
		m_file->Save();

}
void __fastcall TPriFilter::SetAperture(const int aperture)
{
	m_aperture = aperture;
	if (m_file != NULL)
		m_file->Save();

}
void __fastcall TPriFilter::SetExposure(const int exposure)
{
	m_exposure = exposure;
	if (m_file != NULL )
		m_file->Save();

}



TPriInitFile::TPriInitFile()
{

}

TPriInitFile::~TPriInitFile()
{

}

bool __fastcall TPriInitFile::Load()
{
	UnicodeString strFileName = GetFileName();
	AnsiString _ansi = strFileName;
	if (!FileExists(strFileName, true))
	{
		//save defaults
		CreateDefults();
	}

	TiXmlDocument doc;

	if (!doc.LoadFile(_ansi.c_str()))
		return false;
	TiXmlNode* node = doc.FirstChild("pri20");
	if (node == NULL)
		return false;
	TiXmlElement* e = node->ToElement();
	for (TiXmlNode* e = node->FirstChildElement("filter"); e; e = e->NextSibling())
	{
		TPriFilter* filter = new TPriFilter(this);
		if (filter->Init(e->ToElement()))
			m_filters.Add(filter);
		else
		{
			m_filters.Clear();
			return false;
		}
	}
}

bool __fastcall TPriInitFile::Save()
{
	UnicodeString strFileName = GetFileName();
	AnsiString _ansi = strFileName;

	TiXmlDocument doc;
	TiXmlDeclaration* decl = new TiXmlDeclaration("1.0", "", "");
	doc.LinkEndChild(decl);

	TiXmlElement* e = new TiXmlElement("pri20");
	for (int i = 0; i < m_filters.GetCount(); i++)
	{
		TiXmlElement* element = new TiXmlElement("filter");
		TPriFilter* filter = (TPriFilter*)m_filters.Get(i);
		if (!filter->Save(element))
			return false;
		e->LinkEndChild(element);
	}
	doc.LinkEndChild(e);
	return doc.SaveFile(_ansi.c_str());

}

int __fastcall TPriInitFile::GetNumFilters()
{
	return m_filters.GetCount();
}
TPriFilter* __fastcall TPriInitFile::GetFilter(int index)
{
	if (index < 0 || index >= m_filters.GetCount())
		return NULL;
	return (TPriFilter*)m_filters.Get(index);
}

UnicodeString TPriInitFile::GetFileName()
{
	LPITEMIDLIST pidl;
	LPMALLOC pShellMalloc;
	wchar_t szDir[MAX_PATH];
	UnicodeString PathStr ;

	if (SUCCEEDED(SHGetMalloc(&pShellMalloc)))
	{
		if (SUCCEEDED(SHGetSpecialFolderLocation(NULL, CSIDL_PERSONAL, &pidl)))
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

	UnicodeString str = PathStr;
	str += L"\\pri20\\";
	if (!DirectoryExists(str))
		CreateDir(str);
	str += L"pri20.xml";
	return str;
}

void __fastcall TPriInitFile::CreateDefults()
{
	m_filters.Clear();

	TPriFilter* f = NULL;//new TPriFilter(this, 0, 1070, 0, 100, "BP448");

	f = new TPriFilter(this, 1, 1070, 0, 100, "BP448");
	m_filters.Add(f);
	f = new TPriFilter(this, 2, 1110, 0, 100, "BP510");
	m_filters.Add(f);
	f = new TPriFilter(this, 3, 1120, 0, 100, "BP532");
	m_filters.Add(f);
	f = new TPriFilter(this, 4, 1090, 0, 100, "BP545");
	m_filters.Add(f);
	f = new TPriFilter(this, 5, 1090, 0, 100, "BP448");
	m_filters.Add(f);
	f = new TPriFilter(this, 6, 1090, 0, 100, "BP572");
	m_filters.Add(f);
	f = new TPriFilter(this, 7, 1280, 0, 100, "не установлен");
	m_filters.Add(f);
	f = new TPriFilter(this, 7, 1280, 0, 100, "не установлен");
	m_filters.Add(f);
	Save();
}


#pragma package(smart_init)

