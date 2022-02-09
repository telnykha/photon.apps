// pylonwrapper.cpp: определяет экспортированные функции для приложения DLL.
//

#include "stdafx.h"
#include "pylonwrapper.h"


// Namespace for using pylon objects.
using namespace Pylon;
using namespace std;

//Example of an image event handler.
class CSampleImageEventHandler : public CImageEventHandler
{
protected: 
	OnCameraImageEvent m_onImage;
	int m_Frame;
public:
	CSampleImageEventHandler(OnCameraImageEvent onImage)
	{
		m_onImage = onImage;
		m_Frame = 0;
	}
	virtual void OnImageGrabbed(CInstantCamera& camera, const CGrabResultPtr& ptrGrabResult)
	{
		//cout << "CSampleImageEventHandler::OnImageGrabbed called." << std::endl;
		//cout << std::endl;
		//cout << std::endl;
		CLock lock;
		lock.Lock();
		m_Frame++;
		if (m_onImage != NULL)
		{
			m_onImage(m_Frame, ptrGrabResult->GetWidth(), ptrGrabResult->GetHeight(), ptrGrabResult->GetBuffer());
		}
		lock.Unlock();
	}
};

class CPylonCamera
{
protected: 
	string m_strName;
	CBaslerUniversalInstantCamera* m_pCamera;
	OnCameraImageEvent m_onImage;
public:
	CPylonCamera(OnCameraImageEvent onImage)
	{
		m_strName = "";
		m_pCamera = NULL;
		m_onImage = onImage;
		PylonInitialize();
	}
	~CPylonCamera()
	{
		DisconnectPylon();
		PylonTerminate();
	}

	bool ConnectPylon()
	{
		if (m_pCamera != NULL)
			DisconnectPylon();
		Pylon::IPylonDevice* d = CTlFactory::GetInstance().CreateFirstDevice();
		if (d == NULL)
			return false;
		m_pCamera = new CBaslerUniversalInstantCamera();
		m_pCamera->Attach(CTlFactory::GetInstance().CreateFirstDevice());
		m_strName = m_pCamera->GetDeviceInfo().GetModelName();
		m_pCamera->Open();
		m_pCamera->TriggerSelector.SetValue(Basler_UniversalCameraParams::TriggerSelector_FrameStart);
		m_pCamera->PixelFormat.SetValue(Basler_UniversalCameraParams::PixelFormat_Mono8);
		// For demonstration purposes only, register another image event handler.
		m_pCamera->RegisterImageEventHandler(new CSampleImageEventHandler(m_onImage), RegistrationMode_Append, Cleanup_Delete);
		return true;
	}
	bool DisconnectPylon()
	{
		StopGrabbing();
		m_pCamera->Close();
		delete m_pCamera;
		m_pCamera = NULL;
		return true;
	}

	const char* GetCameraName()
	{
		return m_strName.c_str();
	}

	const int GetExposure()
	{
		if (m_pCamera == NULL)
			return 0;
		try
		{
			
			
			return m_pCamera->ExposureTime.GetValue();
		}
		catch (const GenericException& e)
		{
			printf("An exception occurred: %s\n", e.GetDescription());
			return 0;
		}
	}

	void SetExposure(int value)
	{
		if (m_pCamera == NULL)
			return;
		try
		{
			m_pCamera->ExposureTime.SetValue(value);
		}
		catch (const GenericException& e)
		{
			printf("An exception occurred: %s\n", e.GetDescription());
		}
	}
	/*
		возвращает режим работы
		-1 - ошибка
		0  - непрерывный 
		1  - триггерный 
	*/
	int GetMode()
	{
		if (m_pCamera == NULL || !m_pCamera->IsOpen())
			return -1;
		Basler_UniversalCameraParams::TriggerModeEnums mode = m_pCamera->TriggerMode.GetValue();
		if (mode == Basler_UniversalCameraParams::TriggerModeEnums::TriggerMode_On)
			return 1;
		return 0;
	}
	/*
		0 - непрерывный режим
		1 - триггерный режим 
	*/
	void SetMode(int value)
	{
		if (m_pCamera == NULL || !m_pCamera->IsOpen())
			return;
		if (value == 0)
		{
			m_pCamera->TriggerMode.SetValue(Basler_UniversalCameraParams::TriggerModeEnums::TriggerMode_Off);
		}
		else if (value == 1)
		{
			m_pCamera->TriggerMode.SetValue(Basler_UniversalCameraParams::TriggerModeEnums::TriggerMode_On);
			m_pCamera->TriggerSource.SetValue(Basler_UniversalCameraParams::TriggerSourceEnums::TriggerSource_Line4);
		}
	}

	void StartGrabbing()
	{
		if (m_pCamera == NULL || !m_pCamera->IsOpen())
			return;
		if (m_pCamera->IsGrabbing())
			return;
		m_pCamera->StartGrabbing(GrabStrategy_OneByOne, GrabLoop_ProvidedByInstantCamera);
	}
	void StopGrabbing()
	{
		if (m_pCamera == NULL || !m_pCamera->IsOpen())
			return;
		if (m_pCamera->IsGrabbing())
			m_pCamera->StopGrabbing();
	}

	bool IsGrabbing()
	{
		if (m_pCamera == NULL || !m_pCamera->IsOpen())
			return false;
		return m_pCamera->IsGrabbing();
	}

};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
PYLONWRAPPER_API HANDLE wpCreateCamera(OnCameraImageEvent onImage)
{
	CPylonCamera* camera = new CPylonCamera(onImage);
	return (HANDLE)camera;
}
PYLONWRAPPER_API bool   wpConnect(HANDLE camera)
{
	CPylonCamera* c = (CPylonCamera*)camera;
	return c->ConnectPylon();
}
PYLONWRAPPER_API bool   wpDisconnect(HANDLE camera)
{
	CPylonCamera* c = (CPylonCamera*)camera;
	return c->DisconnectPylon();
}
PYLONWRAPPER_API void   wpFreeCamera(HANDLE camera)
{
	CPylonCamera* c = (CPylonCamera*)camera;
	delete c;
}

PYLONWRAPPER_API const char*  wpCameraName(HANDLE camera)
{
	CPylonCamera* c = (CPylonCamera*)camera;
	return c->GetCameraName();
}

PYLONWRAPPER_API const int  wpCameraGetExposure(HANDLE camera)
{
	CPylonCamera* c = (CPylonCamera*)camera;
	return c->GetExposure();
}

PYLONWRAPPER_API void  wpCameraSetExposure(HANDLE camera, int value)
{
	CPylonCamera* c = (CPylonCamera*)camera;
	c->SetExposure(value);
}

PYLONWRAPPER_API const int  wpCameraGetMode(HANDLE camera)
{
	CPylonCamera* c = (CPylonCamera*)camera;
	return c->GetMode();
}
PYLONWRAPPER_API void  wpCameraSetMode(HANDLE camera, int value)
{
	CPylonCamera* c = (CPylonCamera*)camera;
	c->SetMode(value);
}

PYLONWRAPPER_API void   wpStart(HANDLE camera)
{
	CPylonCamera* c = (CPylonCamera*)camera;
	c->StartGrabbing();
}

PYLONWRAPPER_API void   wpStop(HANDLE camera)
{
	CPylonCamera* c = (CPylonCamera*)camera;
	c->StopGrabbing();
}

PYLONWRAPPER_API bool   wpIsGrabbing(HANDLE camera)
{
	CPylonCamera* c = (CPylonCamera*)camera;
	return c->IsGrabbing();
}
