//---------------------------------------------------------------------------
#ifndef MCTObjectH
#define MCTObjectH
//---------------------------------------------------------------------------
#include "beeobject.h"
class TMCTObject : public IBeeObject
{
protected:

public:
	TMCTObject();
	virtual bool CreateObject(const char* path);
	virtual bool ProcessImage(int width, int height, unsigned char* data, int* num, beePoint* result);
};
#endif
