//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("PAMLongProcessUnit.cpp", PAMLongProcessForm);
USEFORM("ABOUT.cpp", AboutBox);
USEFORM("editorUnit.cpp", editorDlg);
USEFORM("optionsUnit.cpp", OptionsDlg);
USEFORM("MainUnit.cpp", mainPAM);
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
