//---------------------------------------------------------------------------
#pragma hdrstop
#include "ArchiveUnit.h"
#include "PriMain.h"
#include "DIBimage41.h"
#include "dialogs.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//CSIDL_PERSONAL
TPRIArchive::TPRIArchive()
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
TPRIArchive::~TPRIArchive()
{

}
bool __fastcall TPRIArchive::Save(TMainForm* form)
{
    DoCurrentTime();
    AnsiString _ansi = m_currentPath;
    _ansi += "\\";
    _ansi += m_currentTime;
    if (!DirectoryExists(_ansi))
        CreateDir(_ansi);

    AnsiString strFileName;
    strFileName = _ansi;

    if(form->iniFile->needSaveAll)
    {
        strFileName += "\\531nm";

		this->SaveRAW(form->image1, strFileName.c_str());

        strFileName = _ansi;
        strFileName += "\\570nm";
        this->SaveRAW(form->image2, strFileName.c_str());

        strFileName = _ansi;
        strFileName += "\\531fnm";
        this->SaveRAW(form->image11, strFileName.c_str());

        strFileName = _ansi;
        strFileName += "\\570fnm";
        this->SaveRAW(form->image22, strFileName.c_str());
    }
    strFileName = _ansi;
    strFileName += "\\pri";
	//this->SaveRAW(form->pri, strFileName.c_str());

    return true;
}

bool __fastcall TPRIArchive::SaveRAW(awpImage* img, const char* lpFileName)
{
    AnsiString str = lpFileName;

    str += ".txt";
    FILE* f = fopen(str.c_str(), "w+t");
    fprintf(f, "%i\n", img->sSizeX);
    fprintf(f, "%i\n", img->sSizeY);
    fclose(f);

    str = lpFileName;
    str += ".raw";

    awpImage* tmp = NULL;
    awpCopyImage(img, &tmp);
    awpConvert(tmp, AWP_CONVERT_TO_FLOAT);
    AWPFLOAT* d = (AWPFLOAT*)tmp->pPixels;
#ifdef _DEBUG
for (int i = 0; i < img->sSizeX*img->sSizeY; i++) {
    float c = d[i];
}
#endif
    f = fopen(str.c_str(), "w+b");
    fwrite(d, img->sSizeX*img->sSizeY*sizeof(AWPFLOAT), 1, f);
    fclose(f);
    awpReleaseImage(&tmp);

    return true;
}

bool __fastcall TPRIArchive::LoadRAW(awpImage** img, const char* lpFileName)
{
    AnsiString str = lpFileName;
    awpImage _img;
    _img.nMagic = AWP_MAGIC2;
    _img.bChannels = 1;
    _img.dwType = AWP_FLOAT;

    int v = 0;
    str += ".txt";
    FILE* f = fopen(str.c_str(), "r+t");
    if (f == NULL)
        return false;

    fscanf(f, "%i\n", &v);
    _img.sSizeX = v;
    fscanf(f, "%i\n", &v);
    _img.sSizeY = v;
    fclose(f);

    str = lpFileName;
    str += ".raw";

    AWPFLOAT* d = (AWPFLOAT*)malloc(_img.sSizeX*_img.sSizeY*sizeof(AWPFLOAT));
    if (d == NULL)
        return false;

    f = fopen(str.c_str(), "r+b");
    if (f == NULL)
    {
	    free(d);
        return false;
    }
    fread(d, _img.sSizeX*_img.sSizeY*sizeof(AWPFLOAT), 1, f);
    _img.pPixels = d;
    fclose(f);
	awpCopyImage(&_img, img);
	awpConvert(*img, AWP_CONVERT_TO_DOUBLE);
	free(d);
    return true;
}


void __fastcall TPRIArchive::DoCurrentTime()
{
    TDateTime dt = Now();
    UnicodeString str = dt.DateTimeString();
    str = StringReplace(str, L":", L"_", TReplaceFlags()<< rfReplaceAll << rfIgnoreCase);
    str = StringReplace(str, L" ", L"_", TReplaceFlags()<< rfReplaceAll << rfIgnoreCase);
    str = StringReplace(str, L".", L"_", TReplaceFlags()<< rfReplaceAll << rfIgnoreCase);
    m_currentTime = str;
}


bool __fastcall TPRIArchive::BeginSave(TMainForm* form)
{
    DoCurrentTime();
    UnicodeString strPath = m_strPath + m_currentTime + L"\\";
#ifdef _DEBUG
	ShowMessage(strPath);
#endif
    if (!DirectoryExists(strPath))
        CreateDir(strPath);
    this->m_currentPath = strPath;

    // сохраняем калибровку
    int dx = form->iniFile->dx;
    int dy = form->iniFile->dy;
    double scale = form->iniFile->scale;
    AnsiString _ansi = strPath;
    _ansi += "calibration.txt";
    FILE* f = fopen(_ansi.c_str(), "w+t");
	fprintf(f, "%i\n", dx);
	fprintf(f, "%i\n", dy);
	fprintf(f, "%lf\n", scale);
	fclose(f);
	return true;
}

bool __fastcall TPRIArchive::ExportPRI(UnicodeString strDst, UnicodeString path)
{
	if (!DirectoryExists(strDst))
		CreateDir(strDst);

	TSearchRec serchmas;
	UnicodeString S,str="";
	UnicodeString strPath = path;
	strPath +="\\*.*";
	if (FindFirst(strPath, faDirectory, serchmas)==0)
	{
		do
		{
			if(serchmas.Name==str)break;//если каталог уже встречался -выходим
			if((serchmas.Name==".")||(serchmas.Name==".."))continue;//пропускаем
			if (serchmas.Attr==faDirectory)
			{
				UnicodeString strFileName = path;
				strFileName += L"\\";
				strFileName += serchmas.Name;
				strFileName += "\\pri.raw";

				UnicodeString strDstFileName = strDst;
				strDstFileName += "\\";
				strDstFileName += serchmas.Name;
				strDstFileName += "_pri.raw";
				CopyFile(strFileName.c_str(), strDstFileName.c_str(), true);

				strFileName = ChangeFileExt(strFileName, L".txt");
				strDstFileName = ChangeFileExt(strDstFileName, L".txt");
				CopyFile(strFileName.c_str(), strDstFileName.c_str(), true);
			}
			str=serchmas.Name;
		}
		while (FindNext(serchmas) != -1);//ищем в активной директории следующий каталог
		FindClose(serchmas);//закрываем экземпляр класса, освобождаем ресурсы
	}

	ShowMessage("Экспорт завершен.");
}

bool __fastcall TPRIArchive::ExportPRIProc(UnicodeString strDst, UnicodeString path, TPriProcessor* processor)
{
   return true;
}


bool __fastcall TPRIArchive::ExportData(UnicodeString strDst, UnicodeString path)
{
	if (!DirectoryExists(strDst))
		CreateDir(strDst);

	TSearchRec serchmas;
	UnicodeString S,str="";
	UnicodeString strPath = path;
	strPath +="\\*.*";
	int i = 0;
	if (FindFirst(strPath, faDirectory, serchmas)==0)
	{
		do
        {
            if(serchmas.Name==str)break;//если каталог уже встречался -выходим
            if((serchmas.Name==".")||(serchmas.Name==".."))continue;//пропускаем
            if (serchmas.Attr==faDirectory)
            {
                // pri

                UnicodeString strFileName = path;
                strFileName += L"\\";
                strFileName += serchmas.Name;
                strFileName += "\\pri.raw";

                UnicodeString strDstFileName = strDst;
                strDstFileName += "\\";
                strDstFileName += serchmas.Name;
                strDstFileName += "_pri.raw";
                CopyFile(strFileName.c_str(), strDstFileName.c_str(), true);

                strFileName = ChangeFileExt(strFileName, L".txt");
                strDstFileName = ChangeFileExt(strDstFileName, L".txt");
                CopyFile(strFileName.c_str(), strDstFileName.c_str(), true);

                // 531fnm

                strFileName = path;
                strFileName += L"\\";
                strFileName += serchmas.Name;
                strFileName += "\\531fnm.raw";

                strDstFileName = strDst;
                strDstFileName += "\\";
                strDstFileName += serchmas.Name;
                strDstFileName += "_531fnm.raw";
                CopyFile(strFileName.c_str(), strDstFileName.c_str(), true);

                strFileName = ChangeFileExt(strFileName, L".txt");
                strDstFileName = ChangeFileExt(strDstFileName, L".txt");
                CopyFile(strFileName.c_str(), strDstFileName.c_str(), true);


                // 531nm

                strFileName = path;
                strFileName += L"\\";
                strFileName += serchmas.Name;
                strFileName += "\\531nm.raw";

                strDstFileName = strDst;
                strDstFileName += "\\";
                strDstFileName += serchmas.Name;
                strDstFileName += "_531nm.raw";
                CopyFile(strFileName.c_str(), strDstFileName.c_str(), true);

                strFileName = ChangeFileExt(strFileName, L".txt");
                strDstFileName = ChangeFileExt(strDstFileName, L".txt");
                CopyFile(strFileName.c_str(), strDstFileName.c_str(), true);

                // 570nm

                strFileName = path;
                strFileName += L"\\";
                strFileName += serchmas.Name;
                strFileName += "\\570nm.raw";

                strDstFileName = strDst;
                strDstFileName += "\\";
                strDstFileName += serchmas.Name;
                strDstFileName += "_570nm.raw";
                CopyFile(strFileName.c_str(), strDstFileName.c_str(), true);

                strFileName = ChangeFileExt(strFileName, L".txt");
                strDstFileName = ChangeFileExt(strDstFileName, L".txt");
                CopyFile(strFileName.c_str(), strDstFileName.c_str(), true);

                // 570fnm

                strFileName = path;
                strFileName += L"\\";
                strFileName += serchmas.Name;
                strFileName += "\\570fnm.raw";

                strDstFileName = strDst;
                strDstFileName += "\\";
                strDstFileName += serchmas.Name;
                strDstFileName += "_570fnm.raw";
                CopyFile(strFileName.c_str(), strDstFileName.c_str(), true);

                strFileName = ChangeFileExt(strFileName, L".txt");
                strDstFileName = ChangeFileExt(strDstFileName, L".txt");
				CopyFile(strFileName.c_str(), strDstFileName.c_str(), true);

				Application->ProcessMessages();
				MainForm->Gauge1->Progress =  100*(i+1) / MainForm->ListBox2->Items->Count;
				i++;
            }
            str=serchmas.Name;
        }
        while (FindNext(serchmas) != -1);//ищем в активной директории следующий каталог
        FindClose(serchmas);//закрываем экземпляр класса, освобождаем ресурсы
    }
    MainForm->Gauge1->Progress = 0;
	ShowMessage("Экспорт завершен успешно.");
}


bool __fastcall TPRIArchive::Load(UnicodeString str)
{
	UnicodeString fileName = str;
	AnsiString _ansi = str;
	AnsiString strFileName;
    strFileName = _ansi;
	strFileName += "\\531nm";
	if (!LoadRAW(&MainForm->m_image1, strFileName.c_str()))
		return false;

	strFileName = _ansi;
	strFileName += "\\570nm";
	if (!LoadRAW(&MainForm->m_image2, strFileName.c_str()))
        return false;

	strFileName = _ansi;
	strFileName += "\\531fnm";
	if (!LoadRAW(&MainForm->m_image11, strFileName.c_str()))
        return false;

	strFileName = _ansi;
	strFileName += "\\570fnm";
	if (!LoadRAW(&MainForm->m_image22, strFileName.c_str()))
		return false;

	return true;
}

bool __fastcall TPRIArchive::LoadImages(UnicodeString str, awpImage** i531, awpImage** i570, awpImage** i531f, awpImage** i570f)
{
	UnicodeString fileName = str;
	AnsiString _ansi = str;
	AnsiString strFileName;
    strFileName = _ansi;
	strFileName += "\\531nm";
	if (!LoadRAW(i531, strFileName.c_str()))
		return false;

	strFileName = _ansi;
	strFileName += "\\570nm";
	if (!LoadRAW(i570, strFileName.c_str()))
        return false;

	strFileName = _ansi;
	strFileName += "\\531fnm";
	if (!LoadRAW(i531f, strFileName.c_str()))
        return false;

	strFileName = _ansi;
	strFileName += "\\570fnm";
	if (!LoadRAW(i570f, strFileName.c_str()))
		return false;

	return true;
}


bool __fastcall TPRIArchive::LoadPRI(UnicodeString str)
{
    UnicodeString fileName = str;
    AnsiString _ansi = str;
    AnsiString strFileName;
    strFileName = _ansi;
    strFileName += "\\pri";
	return this->LoadRAW(&MainForm->m_pri, strFileName.c_str());
}



