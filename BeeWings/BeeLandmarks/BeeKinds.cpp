//---------------------------------------------------------------------------

#pragma hdrstop

#include "BeeKinds.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


BeeKind::BeeKind(const char* name, double minCi, double maxCi, double minDsA, double maxDsA, double minHi, double maxHi, int color) : TLFObject()
{
}

TiXmlElement* BeeKind::SaveXML()
{
	return NULL;
}
BeeKind* BeeKind::LoadXML(TiXmlElement* parent)
{
	return NULL;
}

double BeeKind::GetMinCi()
{
	return 0;
}
void   BeeKind::SetMinCi(const double value)
{

}

double BeeKind::GetMaxCi()
{
	return 0;
}
void   BeeKind::SetMaxCi(const double value)
{

}

double BeeKind::GetMinDsA()
{
	return 0;
}
void   BeeKind::SetMinDsA(const double value)
{

}

double BeeKind::GetMaxDsA()
{
	return 0;
}
void   BeeKind::SetMaxDsA(const double value)
{

}

double BeeKind::GetMinHi()
{
	return 0;
}
void   BeeKind::SetMinhi(const double value)
{

}

double BeeKind::GetMaxHi()
{
	return 0;
}
void   BeeKind::SetmaxHi(const double value)
{

}


int    BeeKind::GetColor()
{
	return 0;
}
void   BeeKind::SetColor(const int color)
{

}


BeeKinds::BeeKinds():TLFObjectList()
{

}

bool BeeKinds::LoadXml(const char* fileName)
{
	return false;
}
bool BeeKinds::SaveXml(const char* fileName)
{
	return false;
}

bool BeeKinds::AddBeeKind(BeeKind* Kind)
{
	return false;
}
bool BeeKinds::DeleteBeeKind(int index)
{
	return false;
}

BeeKind* BeeKinds::GetBeeKind(int index)
{
	return NULL;
}
BeeKind* BeeKinds::Classify(double Ci, double DsA, double Hi)
{
    return NULL;
}
