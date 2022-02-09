//---------------------------------------------------------------------------
#ifndef priInitUnitH
#define priInitUnitH
#include "_LF.h"
#include <System.Classes.hpp>

class TPriInitFile;
class TPriFilter : public TLFObject
{
protected:
	TPriInitFile* m_file;
	int m_index;
	UnicodeString m_filterName;
	int m_focus;
	int m_aperture;
	int m_exposure;


	void __fastcall SetName(const UnicodeString name);
	void __fastcall SetIndex(const int index);
	void __fastcall SetFocus(const int focus);
	void __fastcall SetAperture(const int aperture);
	void __fastcall SetExposure(const int exposure);
public:
	TPriFilter(TPriInitFile* file);
	TPriFilter(TPriInitFile* file, int index, int focus, int aperture, int exposure, const char* name);
	virtual ~TPriFilter();

	bool __fastcall Init(TiXmlElement* element);
	bool __fastcall Save(TiXmlElement* element);


	__property int index = {read = m_index, write = SetIndex};
	__property UnicodeString name  = {read = m_filterName, write = SetName};
	__property int focus = {read = m_focus, write = SetFocus};
	__property int aperture = {read = m_aperture, write = SetAperture};
	__property int exposure = {read = m_exposure, write = SetExposure};
};

class TPriInitFile
{
private:
	TLFObjectList m_filters;
	void __fastcall CreateDefults();

	int __fastcall GetNumFilters();
	TPriFilter* __fastcall GetFilter(int index);
	UnicodeString GetFileName();
public:
	  TPriInitFile();
	  ~TPriInitFile();

	  bool __fastcall Load();
	  bool __fastcall Save();

	  __property int NumFilters = {read = GetNumFilters};
	  __property TPriFilter* Filter[int index] = {read = GetFilter};
};


//---------------------------------------------------------------------------
#endif
