//---------------------------------------------------------------------------
#pragma hdrstop
#include "PAMArchive.h"
#include "system.sysutils.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)


TPAMArchive::TPAMArchive(UnicodeString path)
{
    m_path = path;
    m_path += L"\\";
    m_currentPath = path;
    DoCurrentTime();
    m_counter = 0;
}
void __fastcall TPAMArchive::DoCurrentTime()
{
    m_currentTime = GetCurrentTime();
}

void __fastcall TPAMArchive::CreateArchiveEntry(TCommandsTable* table)
{
    DoCurrentPath();
    UnicodeString strFileName = m_currentPath + L"\\config.pam";
    AnsiString _ansi = strFileName;
    m_table = table;
    m_indexes.clear();
    for (int i = 0; i < m_table->list->Count; i++)
    {
        expEvent* event = (expEvent*)m_table->list->Items[i];
        if (event->command == 2 || event->command == 3 || event->command == 5)
            m_indexes.push_back(i);
    }
//    table->SaveTable(_ansi.c_str());
}

void __fastcall TPAMArchive::DoCurrentPath()
{
    DoCurrentTime();
    UnicodeString strPath = m_path + m_currentTime + L"\\";
    if (!DirectoryExists(strPath))
        CreateDir(strPath);
    m_currentPath = strPath;
}

UnicodeString TPAMArchive::GetCurrentTime()
{
    TDateTime dt = Now();
    UnicodeString str = dt.DateTimeString();
    str = StringReplace(str, L":", L"_", TReplaceFlags()<< rfReplaceAll << rfIgnoreCase);
    str = StringReplace(str, L" ", L"_", TReplaceFlags()<< rfReplaceAll << rfIgnoreCase);
    str = StringReplace(str, L".", L"_", TReplaceFlags()<< rfReplaceAll << rfIgnoreCase);
    return str;
}

awpImage* TPAMArchive::LoadPicture(UnicodeString path)
{
    UnicodeString ext = ExtractFileExt(path);
    if (ext != L".raw")
        return NULL;
    UnicodeString strTxt = ChangeFileExt(path, L".txt");

    awpImage _img;
    _img.nMagic = AWP_MAGIC2;
    _img.bChannels = 1;
    _img.dwType = AWP_FLOAT;

    AnsiString str = strTxt;

    int v = 0;
    FILE* f = fopen(str.c_str(), "r+t");
    if (f == NULL)
        return NULL;

    fscanf(f, "%i\n", &v);
    _img.sSizeX = v;
    fscanf(f, "%i\n", &v);
    _img.sSizeY = v;
    fclose(f);

    str = path;

    AWPFLOAT* d = (AWPFLOAT*)malloc(_img.sSizeX*_img.sSizeY*sizeof(AWPFLOAT));
    if (d == NULL)
        return NULL;

    f = fopen(str.c_str(), "r+b");
    if (f == NULL)
    {
	    free(d);
        return NULL;
    }
    fread(d, _img.sSizeX*_img.sSizeY*sizeof(AWPFLOAT), 1, f);
    _img.pPixels = d;
    fclose(f);

    awpImage* img = NULL;
    if (awpCopyImage(&_img, &img) != AWP_OK)
    {
	    free(d);
        return NULL;
    }

    return img;
}

void TPAMArchive::SavePicture(awpImage* image)
{

    assert(m_table != NULL);

    AnsiString str =  m_currentPath;
    DWORD t = ::GetTickCount();
    str += IntToStr((__int64)t);

    AnsiString strName = str;
    strName += ".txt";

    FILE* f = fopen(strName.c_str(), "w+t");
    fprintf(f, "%i\n", image->sSizeX);
    fprintf(f, "%i\n", image->sSizeY);
    fclose(f);

	strName = str;
    strName += ".raw";

    awpImage* tmp = NULL;
    awpCopyImage(image, &tmp);
    awpConvert(tmp, AWP_CONVERT_TO_FLOAT);
    AWPFLOAT* d = (AWPFLOAT*)tmp->pPixels;

    f = fopen(strName.c_str(), "w+b");
    fwrite(d, image->sSizeX*image->sSizeY*sizeof(AWPFLOAT), 1, f);
    fclose(f);
    awpReleaseImage(&tmp);

    expEvent* event = (expEvent*)m_table->list->Items[m_indexes[m_counter]];
    m_counter++;
    event->imageName = ExtractFileName(strName);

}

void __fastcall TPAMArchive::DeleteArchiveEntry()
{
    TSearchRec serchmas;//класс для хранения результата поиска
    AnsiString S,str="";
    AnsiString path = this->m_currentPath;
    path += "\\*.*";
    if (FindFirst(path, faDirectory, serchmas)==0)//ищем каталог(faDirectory)без маски('*')-то есть все какие есть
    {
        while (FindNext(serchmas) != -1)
        {
            if(serchmas.Name==str)
            	break;//если каталог уже встречался -выходим
            str=serchmas.Name;//запоминаем имя текущего каталога
            if((serchmas.Name==".")||(serchmas.Name==".."))
            	continue;//пропускаем
            S = this->m_currentPath;
            S += str;
            DeleteFile(S);

        }
        FindClose(serchmas);//закрываем экземпляр класса, освобождаем ресурсы
    }
    RemoveDir(this->m_currentPath);
}
void __fastcall TPAMArchive::FinishSave()
{
    assert(m_table != NULL);

    UnicodeString strFileName = m_currentPath + L"\\config.pam";
    AnsiString _ansi = strFileName;
    m_table->SaveTable(_ansi.c_str());
}

