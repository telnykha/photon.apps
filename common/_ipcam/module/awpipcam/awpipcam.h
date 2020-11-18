#ifndef _awp_ipcam_h_
#define _awp_ipcam_h_

#include "awpipl.h"

#ifdef AWPIPCAM_EXPORTS
#define AWPIPCAM_API  __declspec(dllexport)  
#else
#define AWPIPCAM_API  __declspec(dllimport) 
#endif

extern "C" AWPIPCAM_API HANDLE		awpIpConnect(LPSTR pszFilename);
extern "C" AWPIPCAM_API HRESULT		awpIpDisconnect(HANDLE camera);
extern "C" AWPIPCAM_API awpImage*	awpIpQueryImage(HANDLE camera);

extern "C" AWPIPCAM_API void awpIpFreeImage(awpImage* img);

#endif //_awp_ipcam_h_