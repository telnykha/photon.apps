//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "System.IniFiles.hpp"
#include "BeeIniParamsUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

const UnicodeString c_strSection = L"BeeLandmarks";

static UnicodeString GetIniFileName()
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

	PathStr += L"\\NNVideolab\\";
	if (!DirectoryExists(PathStr))
		CreateDir(PathStr);

	PathStr += L"\\BeeLandmarks\\";
	if (!DirectoryExists(PathStr))
		CreateDir(PathStr);


	return PathStr + L"\\BeeLandmarks.ini";
}



TBeeIniParams::TBeeIniParams()
{
	LoadParams();
}
void __fastcall TBeeIniParams::LoadParams()
{
	UnicodeString str = GetIniFileName();
	TIniFile *ini = NULL;
	ini = new TIniFile(str);
	this->m_NeedAnalysis = ini->ReadBool(c_strSection, L"analysis", true);
	this->m_UITheme      = ini->ReadString(c_strSection, L"theme", "Windows");
	this->m_LandmarkSkin = ini->ReadInteger(c_strSection, L"skin", 0);
	this->m_strLastPath = ini->ReadString(c_strSection, L"LastPath", "C:\\");
	delete ini;
}
void __fastcall TBeeIniParams::SaveParams()
{
	UnicodeString str = GetIniFileName();
	TIniFile *ini = NULL;
	ini = new TIniFile(str);
	ini->WriteBool(c_strSection, L"analysis", m_NeedAnalysis);
	ini->WriteString(c_strSection, L"theme", m_UITheme);
	ini->WriteInteger(c_strSection, L"skin", m_LandmarkSkin);
	ini->WriteString(c_strSection, L"LastPath", m_strLastPath);
	delete ini;
}

void __fastcall TBeeIniParams::SetNeedAnaysis(const bool value)
{
	this->m_NeedAnalysis = value;
    SaveParams();
}
void __fastcall TBeeIniParams::SetUITheme(const UnicodeString value)
{
	this->m_UITheme = value;
	SaveParams();
}
void __fastcall TBeeIniParams::SetLandmarkSkin(const int value)
{
	this->m_LandmarkSkin = value;
	SaveParams();
}

void __fastcall TBeeIniParams::SetLastPath(const UnicodeString& value)
{
	this->m_strLastPath = value;
    SaveParams();
}

