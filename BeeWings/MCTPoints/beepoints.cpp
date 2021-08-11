#include "beepoints.h"
#include "MCTObject.h"

BEEPOINTS_API HANDLE beeObjectCreate(const char* path)
{
	TMCTObject* mct = new TMCTObject();
	if (!mct->CreateObject(path)) {
		return NULL;
	}
    return (HANDLE)mct;
}
BEEPOINTS_API HRESULT beeImageProcess(HANDLE beeObject, int width, int height, unsigned char* data, int* num, beePoint* result)
{
	if (beeObject == NULL) {
		return E_FAIL;
	}
	TMCTObject* mct = (TMCTObject*)beeObject;
	bool res = mct->ProcessImage(width, height, data, num, result);
	return res? S_OK:E_FAIL;
}
BEEPOINTS_API HRESULT beeObjectFree(HANDLE beeObject)
{
	if (beeObject == NULL) {
		return E_FAIL;
	}
	TMCTObject* mct = (TMCTObject*)beeObject;
	delete mct;
	return S_OK;
}
