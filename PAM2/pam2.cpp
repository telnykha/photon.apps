//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("pamMainUnit.cpp", pamMainForm);
USEFORM("pamHardwareUnit.cpp", pam2HardwareForm);
USEFORM("pamExperimentUnit.cpp", pam2ExperimentForm);
USEFORM("pamTimeLineUnit.cpp", pam2TimeLineForm);
USEFORM("pamScriptUnit.cpp", pam2ScriptForm);
USEFORM("pamResultUnit.cpp", pam2ResultForm);
USEFORM("pamOptionsUnit.cpp", pam2OptionsForm);
USEFORM("pamDistributionUnit.cpp", pam2DistributionForm);
USEFORM("pamConsoleUnit.cpp", ConsoleForm);
USEFORM("pamAboutUnit.cpp", AboutBox);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TpamMainForm), &pamMainForm);
		Application->CreateForm(__classid(TConsoleForm), &ConsoleForm);
		Application->CreateForm(__classid(TAboutBox), &AboutBox);
		Application->CreateForm(__classid(Tpam2ResultForm), &pam2ResultForm);
		Application->CreateForm(__classid(Tpam2ScriptForm), &pam2ScriptForm);
		Application->CreateForm(__classid(Tpam2DistributionForm), &pam2DistributionForm);
		Application->CreateForm(__classid(Tpam2ExperimentForm), &pam2ExperimentForm);
		Application->CreateForm(__classid(Tpam2TimeLineForm), &pam2TimeLineForm);
		Application->CreateForm(__classid(Tpam2OptionsForm), &pam2OptionsForm);
		Application->CreateForm(__classid(Tpam2HardwareForm), &pam2HardwareForm);
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
