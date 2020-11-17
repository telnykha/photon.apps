//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
#include "VerInfoUnit.h"
#include "DownLoad.h"
#include "Down_dial.h"
//---------------------------------------------------------------------------
USEFORM("PriMain.cpp", MainForm);
USEFORM("PriCalibrationForm.cpp", CalibrationDlg);
USEFORM("SelectDirUnit.cpp", SelectDirDlg);
USEFORM("PriSpatialCalibration.cpp", SpatialCalibrationDlg);
USEFORM("CaptureDataUnit.cpp", CaptureForm);
USEFORM("ABOUT.cpp", AboutBox);
USEFORM("OptionsUnit.cpp", Form3);
USEFORM("ExportPriUnit.cpp", ExportPriDlg);
USEFORM("Down_dial.cpp", Form1);
//---------------------------------------------------------------------------

bool check_version()
{
	bool result = false;
	TVersionInfo* info = new TVersionInfo(NULL);
	String VersionApplication = info->FileVersion;
	delete info;
	bool c = download("https://71e94f04-aaa5-4d33-99e5-dd3139f3c17f.usrfiles.com/ugd/71e94f_dff5068d4f2d4f3da2a4573bfbb787a9.txt", "Updat.inf", result, VersionApplication);
	return !c;
}

int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
bool res = check_version();
bool k =    check_version() ;
if(check_version())
if (MessageDlg("обновить приложение?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo,0) == mrYes)
	{
	ShellExecute(NULL, L"open", L"https://telnykha.wixsite.com/nn-videolab", NULL, NULL, SW_SHOWNORMAL);
	return 0;
	}
	try
	{
	bool result = true;
	Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TMainForm), &MainForm);
		Application->CreateForm(__classid(TSelectDirDlg), &SelectDirDlg);
		Application->CreateForm(__classid(TAboutBox), &AboutBox);
		Application->CreateForm(__classid(TForm3), &Form3);
		Application->CreateForm(__classid(TCalibrationDlg), &CalibrationDlg);
		Application->CreateForm(__classid(TCaptureForm), &CaptureForm);
		Application->CreateForm(__classid(TExportPriDlg), &ExportPriDlg);
		Application->CreateForm(__classid(TSpatialCalibrationDlg), &SpatialCalibrationDlg);
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
