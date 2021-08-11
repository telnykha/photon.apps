#ifndef __beeobject_h_
#define __beeobject_h_
#include "beepoints.h"
class IBeeObject
{
public:
	IBeeObject(){};
	virtual bool CreateObject(const char* path) = 0;
	virtual bool ProcessImage(int width, int height, unsigned char* data, int* num, beePoint* result) = 0;
};
#endif //__beeobject_h_
