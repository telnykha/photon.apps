//---------------------------------------------------------------------------
#ifndef IniFileUnitH
#define IniFileUnitH
//---------------------------------------------------------------------------
class TPAMOptions
{
protected:
     UnicodeString m_ArchivePath;
     unsigned char m_Intensivity;
     bool          m_OpenArchive;

     // экспозиция (mks)  = T0[m_exploshureIndex]*m_exploshureValue
     int           m_exploshureIndex;
     int           m_exploshureValue;
     int           m_gain;     // усиление видеокамеры

     int           m_delay;    // задержка перед началом вспышкой от начала экспозиции
     int           m_length;   // длительность вспышки

     bool           m_freeze;

     void __fastcall SetArchivePath(UnicodeString path);
     void __fastcall SetIntensivity(unsigned char value);
     void __fastcall SetOpenArchive(bool value);
     void __fastcall SetExploshureIndex(int value);
	 void __fastcall SetExploshureValue(int value);
     void __fastcall SetGain(int value);
     void __fastcall SetDelay(int value);
     void __fastcall SetLength(int value);
     int __fastcall GetExposure();

     void __fastcall Load();
     void __fastcall Save();

public:
    TPAMOptions();

    void __fastcall UpdateUI();


    __property UnicodeString ArchivePath 	= {read = m_ArchivePath, write = SetArchivePath};
    __property unsigned char Intensivity    = {read = m_Intensivity,write =  SetIntensivity};
    __property bool OpenArchive             = {read = m_OpenArchive, write = SetOpenArchive};
    __property int exploshureIndex          = {read = m_exploshureIndex, write = SetExploshureIndex};
    __property int exploshureValue			= {read = m_exploshureValue, write = SetExploshureValue};
    __property int Gain						= {read = m_gain, write = SetGain};
    __property int Delay						= {read = m_delay, write = SetDelay};
    __property int Length						= {read = m_length, write = SetLength};
    __property int Exposure                     = {read = GetExposure};

    __property bool freeze                      = {read = m_freeze, write = m_freeze};

};

#endif
