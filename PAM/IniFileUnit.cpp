//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "IniFiles.hpp"
#include "IniFileUnit.h"
#include "pam_common.h"
#include "MainUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

TPAMOptions::TPAMOptions()
{
    m_freeze = true;
    Load();
}

#define CHECK_FREEZE if (m_freeze) return;
void __fastcall TPAMOptions::SetArchivePath(UnicodeString path)
{
    CHECK_FREEZE
    m_ArchivePath = path;
    Save();
}

void __fastcall TPAMOptions::SetIntensivity(unsigned char value)
{
    CHECK_FREEZE
    m_Intensivity = value;
    Save();
}
void __fastcall TPAMOptions::SetOpenArchive(bool value)
{
    CHECK_FREEZE
    m_OpenArchive = value;
    Save();
}
void __fastcall TPAMOptions::SetExploshureIndex(int value)
{
    CHECK_FREEZE
    m_exploshureIndex = value;
    Save();
}
void __fastcall TPAMOptions::SetExploshureValue(int value)
{
    CHECK_FREEZE
    m_exploshureValue = value;
    Save();
}
void __fastcall TPAMOptions::SetGain(int value)
{
    CHECK_FREEZE
    m_gain = value;
    Save();
}

void __fastcall TPAMOptions::SetDelay(int value)
{
	CHECK_FREEZE
    m_delay = value;
    Save();
}

void __fastcall TPAMOptions::SetLength(int value)
{
    CHECK_FREEZE
    m_length = value;
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
    this->m_gain = file->ReadInteger(L"pam", L"gain", 10);
    this->m_delay = file->ReadInteger(L"pam", L"delay", 5);
    this->m_length = file->ReadInteger(L"pam", L"lenght", 100);
    delete file;
}

void __fastcall TPAMOptions::Save()
{
    if (m_freeze)
        return;

    UnicodeString fileName = GetIniFileName();
    TIniFile* file = new TIniFile(fileName);

    file->WriteString(L"pam", L"archive", m_ArchivePath);
    file->WriteInteger(L"pam", L"intensivity", m_Intensivity);
    file->WriteBool(L"pam", L"open", m_OpenArchive);
    file->WriteInteger(L"pam", L"eindex", m_exploshureIndex);
    file->WriteInteger(L"pam", L"evalue", m_exploshureValue);
    file->WriteInteger(L"pam", L"gain", m_gain);
    file->WriteInteger(L"pam", L"delay", m_delay);
    file->WriteInteger(L"pam", L"lenght", m_length);

    delete file;
}

int __fastcall TPAMOptions::GetExposure()
{
    double exp_limit = c_expLimit[m_exploshureIndex]/100.;

    return 1000*m_exploshureValue*exp_limit;
}

void __fastcall TPAMOptions::UpdateUI()
{
   if (mainPAM->table == NULL)
    return;

   mainPAM->ComboBox1->ItemIndex = m_exploshureIndex;
   mainPAM->TrackBar1->Position  = m_exploshureValue;
   mainPAM->TrackBar5->Position  = m_gain;
   mainPAM->SpinEdit2->Value     = m_delay;
   mainPAM->SpinEdit1->Value     = m_length;
   mainPAM->table->changed = true;
}

