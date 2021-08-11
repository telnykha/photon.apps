//---------------------------------------------------------------------------
#ifndef MCTObjectH
#define MCTObjectH
//---------------------------------------------------------------------------
#include "beeobject.h"
#include "_LF.h"
class TMCTObject : public IBeeObject
{
protected:
	TLFZones m_zones;
	TLFDetectEngine m_e1;
	TLFDetectEngine m_e2;
	TLFDetectEngine m_e3;
	TLFDetectEngine m_e4;
	TLFDetectEngine m_e5;
	TLFDetectEngine m_e6;
	TLFDetectEngine m_e7;
	TLFDetectEngine m_e8;

public:
	TMCTObject();
	virtual bool CreateObject(const char* path);
	virtual bool ProcessImage(int width, int height, unsigned char* data, int* num, beePoint* result);
};
#endif
