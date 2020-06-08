//---------------------------------------------------------------------------
#pragma hdrstop
#include "InitFileUnit.h"
#include <System.Classes.hpp>
#include "PriMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


TPriInitFile::TPriInitFile()
{
    m_strCOM = L"COM4";
    //m_strPath = path;
    GetIniFilePath();
    //
 	m_dx = 0;
 	m_dy = 0;
 	m_scale = 1;

	m_borderSize = 20;
	m_viewBorder = 0;
    m_inputData = 1;
    m_outData = 0;
    m_viewPri = 0;
    m_seriesInterval = 1;
    m_seriesTotal = 60;

    if (!Load())
        Save();
}
TPriInitFile::~TPriInitFile()
{

}
String TPriInitFile::GetIniFilePath()
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
    str += L"\\pri10\\";
    if (!DirectoryExists(str))
        CreateDir(str);
    m_strPath = str;
}

bool __fastcall TPriInitFile::Load()
{
    AnsiString _ansi = m_strPath;
    _ansi += "init.txt";
    FILE* f = fopen(_ansi.c_str(), "r+t");
    if (f == NULL)
    {
        return false;
    }
    char bufer[256];
    fscanf(f, "%s\n", &bufer);
    m_strCOM = bufer;
    fscanf(f, "%i\n", &m_dx);
    fscanf(f, "%i\n", &m_dy);
    fscanf(f, "%lf\n", &m_scale);

    fscanf(f, "%i\n", &m_borderSize);
    fscanf(f, "%i\n", &m_viewBorder);
    fscanf(f, "%i\n", &m_inputData);
    fscanf(f, "%i\n", &m_outData);
    fscanf(f, "%i\n", &m_viewPri);
    fscanf(f, "%i\n", &m_seriesInterval);
    fscanf(f, "%i\n", &m_seriesTotal);
    fscanf(f, "%i\n", &m_needSaveAll);
    fscanf(f, "%i\n", &m_exploshureIndex);
    fscanf(f, "%i\n", &m_exploshureValue);
    fscanf(f, "%s\n", &bufer);
    m_strExport = bufer;
    fscanf(f, "%s\n", &bufer);
    m_strArchive = bufer;

    fclose(f);
    return true;
}
bool __fastcall TPriInitFile::Save()
{
	AnsiString _ansi = m_strPath;
    _ansi += "init.txt";
    FILE* f = fopen(_ansi.c_str(), "w+t");
    _ansi = m_strCOM;
    fprintf(f, "%s\n", _ansi.c_str());
    fprintf(f, "%i\n", m_dx);
    fprintf(f, "%i\n", m_dy);
    fprintf(f, "%lf\n", m_scale);

    fprintf(f, "%i\n", m_borderSize);
    fprintf(f, "%i\n", m_viewBorder);
    fprintf(f, "%i\n", m_inputData);
    fprintf(f, "%i\n", m_outData);
    fprintf(f, "%i\n", m_viewPri);
    fprintf(f, "%i\n", m_seriesInterval);
    fprintf(f, "%i\n", m_seriesTotal);
    fprintf(f, "%i\n", m_needSaveAll);
    fprintf(f, "%i\n", m_exploshureIndex);
    fprintf(f, "%i\n", m_exploshureValue);
    _ansi = m_strExport;
    fprintf(f, "%s\n", _ansi.c_str());
    _ansi = m_strArchive;
    fprintf(f, "%s\n", _ansi.c_str());

    fclose(f);
    return true;
}
void __fastcall TPriInitFile::SetCOM(UnicodeString strCom)
{
    m_strCOM = strCom;
    Save();
}
void __fastcall TPriInitFile::SetDx(int dx)
{
   m_dx = dx;
   Save();
}
void __fastcall TPriInitFile::SetDy(int dy)
{
    m_dy = dy;
    Save();
}
void __fastcall TPriInitFile::SetScale(double s)
{
   m_scale = s;
   Save();
}

void __fastcall TPriInitFile::SetBorderSize(int value)
{
   m_borderSize = value;
   Save();
}
void __fastcall TPriInitFile::SetViewBorder(int value)
{
   m_viewBorder = value;
   Save();
}
void __fastcall TPriInitFile::SetInputData(int value)
{
   m_inputData = value;
   Save();
}
void __fastcall TPriInitFile::SetOutData(int value)
{
   m_outData = value;
   Save();
}
void __fastcall TPriInitFile::SetViewPri(int value)
{
   m_viewPri = value;
   Save();
}
void __fastcall TPriInitFile::SetSeriesInterval(int value)
{
   m_seriesInterval = value;
   Save();
}
void __fastcall TPriInitFile::SetSeriesTotal(int value)
{
   m_seriesTotal = value;
   Save();
}
void __fastcall TPriInitFile::SetNeedSaveAll(int value)
{
   m_needSaveAll = value;
   Save();
}

void __fastcall TPriInitFile::SetExploshureIndex(int value)
{
    m_exploshureIndex = value;
    Save();
}

void __fastcall TPriInitFile::SetExploshureValue(int value)
{
      m_exploshureValue = value;
      Save();
}
void __fastcall TPriInitFile::SetStrExport(UnicodeString value)
{
    m_strExport = value;
    Save();
}
void __fastcall TPriInitFile::SetStrArchive(UnicodeString value)
{
    m_strArchive = value;
    Save();
}

