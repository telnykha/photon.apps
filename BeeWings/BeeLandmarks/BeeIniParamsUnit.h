//---------------------------------------------------------------------------

#ifndef BeeIniParamsUnitH
#define BeeIniParamsUnitH
//---------------------------------------------------------------------------
class TBeeIniParams
{
protected:
	bool m_NeedAnalysis;
	UnicodeString  m_UITheme;
	int  m_LandmarkSkin;
	void __fastcall LoadParams();
	void __fastcall SaveParams();

	void __fastcall SetNeedAnaysis(const bool value);
	void __fastcall SetUITheme(const UnicodeString value);
	void __fastcall SetLandmarkSkin(const int value);
public:
	TBeeIniParams();

	__property bool NeedAnalysis = {read = m_NeedAnalysis, write = SetNeedAnaysis};
	__property UnicodeString UITheme = {read = m_UITheme, write = SetUITheme};
	__property int LandmarkSkin = {read = m_LandmarkSkin, write = SetLandmarkSkin};
};

#endif
