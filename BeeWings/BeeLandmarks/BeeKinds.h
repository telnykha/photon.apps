// ---------------------------------------------------------------------------

#ifndef BeeKindsH
#define BeeKindsH
#include "_LF.h"

class BeeKind : public TLFObject {
protected:
	TLFString m_strName;
	double m_minCi;
	double m_maxCi;
	double m_minDsA;
	double m_maxDsA;
	double m_minHi;
	double m_maxHi;
	int m_color;

public:
	BeeKind(const char* name, double minCi, double maxCi, double minDsA,
		double maxDsA, double minHi, double maxHi, int color);
	BeeKind(BeeKind& Other);

	TiXmlElement* SaveXML();
	static BeeKind* LoadXML(TiXmlElement* parent);

	double GetMinCi();
	void SetMinCi(const double value);

	double GetMaxCi();
	void SetMaxCi(const double value);

	double GetMinDsA();
	void SetMinDsA(const double value);

	double GetMaxDsA();
	void SetMaxDsA(const double value);

	double GetMinHi();
	void SetMinhi(const double value);

	double GetMaxHi();
	void SetmaxHi(const double value);

	int GetColor();
	void SetColor(const int color);

	const char* GetKindName();


	void SetKindName(const char* value);

};

// ---------------------------------------------------------------------------
class BeeKinds : public TLFObjectList {
protected:
public:
	BeeKinds();

	bool LoadXml(const char* fileName);
	bool SaveXml(const char* fileName);

	bool AddBeeKind(BeeKind* Kind);
	bool DeleteBeeKind(int index);
	int GetKindIndex(const char* lpKindName);

	BeeKind* GetBeeKind(int index);
	BeeKind* Classify(double Ci, double DsA, double Hi);
	void New_Classify(double Ci, double DsA, double Hi, BeeKinds* kinds);
};
#endif
