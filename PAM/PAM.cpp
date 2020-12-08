//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("PAMLongProcessUnit.cpp", PAMLongProcessForm);
USEFORM("editorUnit.cpp", editorDlg);
USEFORM("ABOUT.cpp", AboutBox);
USEFORM("optionsUnit.cpp", OptionsDlg);
USEFORM("MainUnit.cpp", mainPAM);
USEFORM("diff_table.cpp", Difficult_command);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
        Application->ShowHint = true;
		Application->CreateForm(__classid(TmainPAM), &mainPAM);
		Application->CreateForm(__classid(TAboutBox), &AboutBox);
		Application->CreateForm(__classid(TOptionsDlg), &OptionsDlg);
		Application->CreateForm(__classid(TeditorDlg), &editorDlg);
		Application->CreateForm(__classid(TPAMLongProcessForm), &PAMLongProcessForm);
		Application->CreateForm(__classid(TDifficult_command), &Difficult_command);
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
