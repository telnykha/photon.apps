//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("PriMain.cpp", MainForm);
USEFORM("PriCalibrationForm.cpp", CalibrationDlg);
USEFORM("SelectDirUnit.cpp", SelectDirDlg);
USEFORM("ABOUT.cpp", AboutBox);
USEFORM("CaptureDataUnit.cpp", CaptureForm);
USEFORM("OptionsUnit.cpp", Form3);
USEFORM("ExportPriUnit.cpp", ExportPriDlg);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TMainForm), &MainForm);
		Application->CreateForm(__classid(TSelectDirDlg), &SelectDirDlg);
		Application->CreateForm(__classid(TAboutBox), &AboutBox);
		Application->CreateForm(__classid(TForm3), &Form3);
		Application->CreateForm(__classid(TCalibrationDlg), &CalibrationDlg);
		Application->CreateForm(__classid(TCaptureForm), &CaptureForm);
		Application->CreateForm(__classid(TExportPriDlg), &ExportPriDlg);
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
