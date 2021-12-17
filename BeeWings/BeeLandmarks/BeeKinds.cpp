// ---------------------------------------------------------------------------

#pragma hdrstop

#include "BeeKinds.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

BeeKind::BeeKind(const char* name, double minCi, double maxCi, double minDsA,
	double maxDsA, double minHi, double maxHi, int color) : TLFObject() {
	m_strName = name;
	m_minCi = minCi;
	m_maxCi = maxCi;
	m_minDsA = minDsA;
	m_maxDsA = maxDsA;
	m_minHi = minHi;
	m_maxHi = maxHi;
	m_color = color;
}

const char* BeeKind::GetKindName() {
	return m_strName.c_str();
}



void BeeKind::SetKindName(const char* value) {
	m_strName = value;
}

TiXmlElement* BeeKind::SaveXML() {
	TiXmlElement* f = new TiXmlElement("BeeKind");
	f->SetAttribute("KindName", m_strName.c_str());
	f->SetDoubleAttribute("MinCi", m_minCi);
	f->SetDoubleAttribute("MaxCi", m_maxCi);
	f->SetDoubleAttribute("MinDsA", m_minCi);
	f->SetDoubleAttribute("MaxDsA", m_maxCi);
	f->SetDoubleAttribute("MinHi", m_minHi);
	f->SetDoubleAttribute("MaxHi", m_maxHi);
	f->SetAttribute("color", m_color);
	return f;
}

BeeKind* BeeKind::LoadXML(TiXmlElement* parent) {
	if (parent == NULL)
		return NULL;
	const char* name = parent->Value();
	if (strcmp(name, "BeeKind") != 0)
		return NULL;

	BeeKind* result = NULL;
	const char* KindName = parent->Attribute("KindName");
	if (KindName == NULL) {
		return NULL;
	}
	int color;
	if (parent->QueryIntAttribute("color", &color) == TIXML_NO_ATTRIBUTE)
		return NULL;
	// return result;
	double minCi;
	double maxCi;
	double minDsA;
	double maxDsA;
	double minHi;
	double maxHi;
	if (parent->QueryDoubleAttribute("MinCi", &minCi) == TIXML_NO_ATTRIBUTE)
		return NULL;
	if (parent->QueryDoubleAttribute("MaxCi", &maxCi) == TIXML_NO_ATTRIBUTE)
		return NULL;
	if (parent->QueryDoubleAttribute("MinDsA", &minDsA) == TIXML_NO_ATTRIBUTE)
		return NULL;
	if (parent->QueryDoubleAttribute("MaxDsA", &maxDsA) == TIXML_NO_ATTRIBUTE)
		return NULL;
	if (parent->QueryDoubleAttribute("MinHi", &minHi) == TIXML_NO_ATTRIBUTE)
		return NULL;
	if (parent->QueryDoubleAttribute("MaxHi", &maxHi) == TIXML_NO_ATTRIBUTE)
		return NULL;

	return new BeeKind(KindName, minCi, maxCi, minDsA, maxDsA, minHi,
		maxHi, color);
}

double BeeKind::GetMinCi() {
	return m_minCi;
}

void BeeKind::SetMinCi(const double value) {
	m_minCi = value;
}

double BeeKind::GetMaxCi() {
	return m_maxCi;
}

void BeeKind::SetMaxCi(const double value) {
	m_maxCi = value;
}

double BeeKind::GetMinDsA() {
	return m_minDsA;
}

void BeeKind::SetMinDsA(const double value) {
	m_minDsA = value;
}

double BeeKind::GetMaxDsA() {
	return m_maxDsA;
}

void BeeKind::SetMaxDsA(const double value) {
	m_maxDsA = value;
}

double BeeKind::GetMinHi() {
	return m_minHi;
}

void BeeKind::SetMinhi(const double value) {
	m_minHi = value;
}

double BeeKind::GetMaxHi() {
	return m_maxHi;
}

void BeeKind::SetmaxHi(const double value) {
	m_maxHi = value;
}

int BeeKind::GetColor() {
	return m_color;
}

void BeeKind::SetColor(const int color) {
	m_color = color;
}

BeeKinds::BeeKinds() : TLFObjectList() {

}

bool BeeKinds::LoadXml(const char* fileName) {
	TiXmlDocument doc(fileName);
	if (!doc.LoadFile())
		return false;

	TiXmlElement* pElem = doc.FirstChildElement("BeeKinds");
	if (pElem == NULL)
		return false;

	for (TiXmlNode * child = pElem->FirstChild("BeeKind"); child;
	child = child->NextSibling()) {
		TiXmlElement* e = child->ToElement();
		BeeKind* b = BeeKind::LoadXML(e);
		if (b != NULL)
			AddBeeKind(b);
		else {
			Clear();
			return false;
		}
	}

	return true;
}

bool BeeKinds::SaveXml(const char* fileName) {
	TiXmlDocument doc;
	TiXmlDeclaration* decl = new TiXmlDeclaration("1.0", "", "");
	doc.LinkEndChild(decl);
	TiXmlElement* parent = new TiXmlElement("BeeKinds");
	doc.LinkEndChild(parent);

	for (int i = 0; i < GetCount(); i++) {
		BeeKind* kind = GetBeeKind(i);
		TiXmlElement* e = kind->SaveXML();
		parent->LinkEndChild(e);
	}

	return doc.SaveFile(fileName);
}

bool BeeKinds::AddBeeKind(BeeKind* Kind) {
	if (Kind == NULL)
		return false;
	Add(Kind);
	return true;
}

bool BeeKinds::DeleteBeeKind(int index) {
	Delete(index);
	return true;
}

BeeKind* BeeKinds::GetBeeKind(int index) {
	BeeKind* Kind = (BeeKind*)Get(index);
	return Kind;
}

BeeKind* BeeKinds::Classify(double Ci, double DsA, double Hi) {
	BeeKind* result = NULL;
	for (int i = 0; i < GetCount(); i++) {
		BeeKind* b = GetBeeKind(i);
		if (Ci > b->GetMinCi() && Ci < b->GetMaxCi() && DsA >
			b->GetMinDsA() && DsA < b->GetMaxDsA() && Hi > b->GetMinHi() && Hi <
			b->GetMaxHi()) {
			result = b;
			break;
		}
	}
	return result;

}

void BeeKinds::New_Classify(double Ci, double DsA, double Hi, BeeKinds* kinds) {
	kinds->Clear();
	for (int i = 0; i < GetCount(); i++) {
		BeeKind* b = GetBeeKind(i);
		if (Ci > b->GetMinCi() && Ci < b->GetMaxCi() && DsA >
			b->GetMinDsA() && DsA < b->GetMaxDsA() && Hi > b->GetMinHi() && Hi <
			b->GetMaxHi()) {
			BeeKind* bb = new BeeKind(b->GetKindName(), b->GetMinCi(),
				b->GetMaxCi(), b->GetMinDsA(), b->GetMaxDsA(), b->GetMinHi(),
				b->GetMaxHi(), b->GetColor());
			kinds->Add(bb);
		}

	}
}

/*
	возвращает индекс породы из списка по имени
	если порода с таким именем не найдена,
	возвращает -1
*/
int BeeKinds::GetKindIndex(const char* lpKindName){

	if (lpKindName == NULL)
		return -1;
	for (int i = 0; i < GetCount(); i++) {
		BeeKind* b = GetBeeKind(i);
		if (strcmp(b->GetKindName(), lpKindName) == 0)
			return i;
	}
	return -1;
}
