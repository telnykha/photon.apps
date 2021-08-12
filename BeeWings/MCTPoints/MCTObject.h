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
	TLFDetectEngine m_e[8];
public:
	TMCTObject();
	virtual bool CreateObject(const char* path);
	virtual bool ProcessImage(int width, int height, unsigned char* data, int* num, beePoint* result);
};
#endif
