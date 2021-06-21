//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
#include <Vcl.Styles.hpp>
#include <Vcl.Themes.hpp>
USEFORM("pamOptionsUnit.cpp", pam2OptionsForm);
USEFORM("pamResultUnit.cpp", pam2ResultForm);
USEFORM("pamLongProcessUnit.cpp", LongProcessForm);
USEFORM("pamMainUnit.cpp", pamMainForm);
USEFORM("pamSplashUnit.cpp", pamSplashForm);
USEFORM("pamTimeLineUnit.cpp", pam2TimeLineForm);
USEFORM("pamScriptUnit.cpp", pam2ScriptForm);
USEFORM("pamAboutUnit.cpp", AboutBox);
USEFORM("pamConsoleUnit.cpp", ConsoleForm);
USEFORM("pamExperimentUnit.cpp", pam2ExperimentForm);
USEFORM("pamHardwareUnit.cpp", pam2HardwareForm);
USEFORM("pamDistributionUnit.cpp", pam2ROIForm);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		TStyleManager::TrySetStyle("Carbon");
		Application->CreateForm(__classid(TpamMainForm), &pamMainForm);
		Application->CreateForm(__classid(TConsoleForm), &ConsoleForm);
		Application->CreateForm(__classid(TAboutBox), &AboutBox);
		Application->CreateForm(__classid(Tpam2ResultForm), &pam2ResultForm);
		Application->CreateForm(__classid(Tpam2ScriptForm), &pam2ScriptForm);
		Application->CreateForm(__classid(Tpam2ROIForm), &pam2ROIForm);
		Application->CreateForm(__classid(Tpam2ExperimentForm), &pam2ExperimentForm);
		Application->CreateForm(__classid(Tpam2TimeLineForm), &pam2TimeLineForm);
		Application->CreateForm(__classid(Tpam2OptionsForm), &pam2OptionsForm);
		Application->CreateForm(__classid(Tpam2HardwareForm), &pam2HardwareForm);
		Application->CreateForm(__classid(TLongProcessForm), &LongProcessForm);
		Application->CreateForm(__classid(TpamSplashForm), &pamSplashForm);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
