//---------------------------------------------------------------------------
#pragma hdrstop

#include "MCTObject.h"
TMCTObject::TMCTObject()
{

}
bool TMCTObject::CreateObject(const char* path)
{
	return false;
}
bool TMCTObject::ProcessImage(int width, int height, unsigned char* data, int* num, beePoint* result)
{
    return false;
}

//---------------------------------------------------------------------------
#pragma package(smart_init)
