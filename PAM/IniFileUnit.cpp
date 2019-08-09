//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "IniFiles.hpp"
#include "IniFileUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

TPAMOptions::TPAMOptions()
{
    Load();
}

void __fastcall TPAMOptions::SetArchivePath(UnicodeString path)
{
    m_ArchivePath = path;
    Save();
}

void __fastcall TPAMOptions::SetIntensivity(unsigned char value)
{
    m_Intensivity = value;
    Save();
}
void __fastcall TPAMOptions::SetOpenArchive(bool value)
{
    m_OpenArchive = value;
    Save();
}
void __fastcall TPAMOptions::SetExploshureIndex(int value)
{
    m_exploshureIndex = value;
    Save();
}
void __fastcall TPAMOptions::SetExploshureValue(int value)
{
    m_exploshureValue = value;
    Save();
}
static UnicodeString GetIniFileName()
{
    LPITEMIDLIST pidl;
    LPMALLOC pShellMalloc;
	char szDir[MAX_PATH];
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

    PathStr += L"\\PAM\\";
    if (!DirectoryExists(PathStr))
        CreateDir(PathStr);


    return PathStr + L"\\pam.ini";
}

static UnicodeString GetDefaultArchivePath()
{
    LPITEMIDLIST pidl;
    LPMALLOC pShellMalloc;
	char szDir[MAX_PATH];
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

    PathStr += L"\\NNVideolab\\";
    if (!DirectoryExists(PathStr))
        CreateDir(PathStr);

    PathStr += L"\\PAM\\";
    if (!DirectoryExists(PathStr))
        CreateDir(PathStr);

    return PathStr;
}

void __fastcall TPAMOptions::Load()
{
    UnicodeString fileName = GetIniFileName();
    UnicodeString defaultArchive = GetDefaultArchivePath();
    TIniFile* file = new TIniFile(fileName);
    this->m_ArchivePath = file->ReadString(L"pam", L"archive", defaultArchive);
    this->m_Intensivity = file->ReadInteger(L"pam", L"intensivity", 100);
    this->m_OpenArchive = file->ReadBool(L"pam", L"open", true);
    this->m_exploshureIndex = file->ReadInteger(L"pam", L"eindex", 1);
    this->m_exploshureValue = file->ReadInteger(L"pam", L"evalue", 50);
    delete file;
}

void __fastcall TPAMOptions::Save()
{
    UnicodeString fileName = GetIniFileName();
    TIniFile* file = new TIniFile(fileName);
    file->WriteString(L"pam", L"archive", m_ArchivePath);
    file->WriteInteger(L"pam", L"intensivity", m_Intensivity);
    file->WriteBool(L"pam", L"open", m_OpenArchive);
    file->WriteInteger(L"pam", L"eindex", m_exploshureIndex);
    file->WriteInteger(L"pam", L"evalue", m_exploshureValue);
    delete file;
}

