//---------------------------------------------------------------------------

#ifndef InitFileUnitH
#define InitFileUnitH
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
class TPriInitFile
{
private:
    String GetIniFilePath();
protected:
 UnicodeString m_strPath;
// arduino
 UnicodeString m_strCOM;
// папка для экспорта
 UnicodeString m_strExport;
// папка архива
 UnicodeString m_strArchive;
// калибровка
 int           m_dx;
 int           m_dy;
 double        m_scale;
// краевой эффект
 int           m_borderSize;
 int           m_viewBorder;
// формат входных данных
 int           m_inputData; // 0 = 8 bit, 1 = 12 bit
// формат выходных данных
 int           m_outData;   // 0 = raw, 1 = tiff
// отображение pri
 int           m_viewPri;   // 0 = grayscale, 1 = palette
// съемка серий
 int           m_seriesInterval; // сек 1 - 300
 int           m_seriesTotal;    // 10 - 9000
 int           m_needSaveAll; // сохранять все исходные данные
 int           m_exploshureIndex; // пределы изменения экспозиции
 int           m_exploshureValue; // значение точного регулятора экспозиции

 void __fastcall SetCOM( UnicodeString strCom);
 void __fastcall SetDx(int dx);
 void __fastcall SetDy(int dy);
 void __fastcall SetScale(double s);

void __fastcall SetBorderSize(int value);
void __fastcall SetViewBorder(int value);
void __fastcall SetInputData(int value);
void __fastcall SetOutData(int value);
void __fastcall SetViewPri(int value);
void __fastcall SetSeriesInterval(int value);
void __fastcall SetSeriesTotal(int value);
void __fastcall SetNeedSaveAll(int value);
void __fastcall SetExploshureIndex(int value);
void __fastcall SetExploshureValue(int value);
void __fastcall SetStrExport(UnicodeString value);
void __fastcall SetStrArchive(UnicodeString value);

public:
      TPriInitFile();
      ~TPriInitFile();

      bool __fastcall Load();
      bool __fastcall Save();

      __property UnicodeString strPath = {read = m_strPath};
      __property UnicodeString strCom = {read = m_strCOM, write = SetCOM};
      __property UnicodeString strExport = {read = m_strExport, write = SetStrExport};
      __property UnicodeString strArchive = {read = m_strArchive, write = SetStrArchive};

      __property int dx = {read = m_dx, write = SetDx};
      __property int dy = {read = m_dy, write = SetDy};
      __property double scale = {read = m_scale, write = SetScale};

     __property int           borderSize = {read = m_borderSize, write = SetBorderSize};
     __property int           viewBorder ={read = m_viewBorder, write = SetViewBorder};
     __property int           inputData = {read = m_inputData, write = SetInputData};
     __property int           outData = {read = m_outData, write = SetOutData};
     __property int           viewPri = {read = m_viewPri, write = SetViewPri};
     __property int           seriesInterval = {read = m_seriesInterval, write = SetSeriesInterval};
     __property int           seriesTotal = {read = m_seriesTotal, write = SetSeriesTotal};
     __property int           needSaveAll = {read = m_needSaveAll, write = SetNeedSaveAll};

    __property int           exploshureIndex = {read = m_exploshureIndex, write = SetExploshureIndex};
    __property int           exploshureValue = {read = m_exploshureValue, write = SetExploshureValue};


};
#endif
