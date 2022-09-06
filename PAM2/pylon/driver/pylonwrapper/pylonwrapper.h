// ����������� ���� ���� ifdef - ��� ����������� ����� �������� ��������, ���������� ��������� 
// �������� �� ��������� DLL. ��� ����� ������ DLL �������������� � �������������� ������� PYLONWRAPPER_EXPORTS,
// � ��������� ������. ���� ������ �� ������ ���� ��������� � �����-���� �������
// ������������ ������ DLL. ��������� ����� ����� ������ ������, ��� �������� ����� �������� ������ ����, ����� 
// ������� PYLONWRAPPER_API ��� ��������������� �� DLL, ����� ��� ������ DLL ����� �������,
// ������������ ������ ��������, ��� ����������������.
#ifdef PYLONWRAPPER_EXPORTS
#define PYLONWRAPPER_API __declspec(dllexport)
#else
#define PYLONWRAPPER_API __declspec(dllimport)
#endif

typedef void (*OnCameraImageEvent)(int Frame, int w, int h, void* p);



PYLONWRAPPER_API HANDLE wpCreateCamera(OnCameraImageEvent onImage = NULL);
PYLONWRAPPER_API bool   wpConnect(HANDLE camera);
PYLONWRAPPER_API bool   wpDisconnect(HANDLE camera);
PYLONWRAPPER_API void   wpFreeCamera(HANDLE camera);

// Grabbing 
PYLONWRAPPER_API void   wpStart(HANDLE camera);
PYLONWRAPPER_API void   wpStop(HANDLE camera);
PYLONWRAPPER_API bool   wpIsGrabbing(HANDLE camera);

// props 
PYLONWRAPPER_API const char*  wpCameraName(HANDLE camera);
PYLONWRAPPER_API const int  wpCameraGetExposure(HANDLE camera);
PYLONWRAPPER_API void  wpCameraSetExposure(HANDLE camera, int value);
PYLONWRAPPER_API const int  wpCameraGetMode(HANDLE camera);
PYLONWRAPPER_API void  wpCameraSetMode(HANDLE camera, int value);




