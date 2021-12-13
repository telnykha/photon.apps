//---------------------------------------------------------------------------

#ifndef BeeIniParamsUnitH
#define BeeIniParamsUnitH
//---------------------------------------------------------------------------
class TBeeIniParams
{
protected:
	UnicodeString m_strLastPath;
	bool m_NeedAnalysis;
	UnicodeString  m_UITheme;
	int  m_LandmarkSkin;
	void __fastcall LoadParams();
	void __fastcall SaveParams();

	void __fastcall SetNeedAnaysis(const bool value);
	void __fastcall SetUITheme(const UnicodeString value);
	void __fastcall SetLandmarkSkin(const int value);
	void __fastcall SetLastPath(const UnicodeString& value);

	UnicodeString __fastcall GetIniPath();
public:
	TBeeIniParams();

	__property bool NeedAnalysis = {read = m_NeedAnalysis, write = SetNeedAnaysis};
	__property UnicodeString UITheme = {read = m_UITheme, write = SetUITheme};
	__property int LandmarkSkin = {read = m_LandmarkSkin, write = SetLandmarkSkin};
	__property UnicodeString LastPath = {read = m_strLastPath, write = SetLastPath};
	__property UnicodeString IniPath = {read = GetIniPath};
};

#endif
