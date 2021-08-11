#ifndef __beepoints_h__
#define __beepoints_h__

#ifdef WIN32
#ifdef BEEPOINTS_EXPORTS
#define BEEPOINTS_API __declspec(dllexport)
#else
#define BEEPOINTS_API __declspec(dllimport)
#endif
#else
#define BEEPOINTS_API
#endif

#include <Rpc.h>
typedef void* HANDLE;
typedef struct beePoint{
  double x;
  double y;
  double q; // качество
};

extern "C"
{

BEEPOINTS_API HANDLE beeObjectCreate(const char* path);
BEEPOINTS_API HRESULT beeImageProcess(HANDLE beeObject, int width, int height, unsigned char* data, int* num, beePoint* result);
BEEPOINTS_API HRESULT beeObjectFree(HANDLE beeObject);

}
#endif //
