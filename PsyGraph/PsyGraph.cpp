//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("ProfListUnit.cpp", ProfForm);
USEFORM("TestTypesListUnit.cpp", TestTypesForm);
USEFORM("addUserUnit.cpp", AddUserDialog);
USEFORM("additemUnit.cpp", AddItemDialog);
USEFORM("AboutUnit.cpp", AboutBox);
USEFORM("optionsUnit.cpp", OptionsDlg);
USEFORM("MainUnit.cpp", MainForm);
USEFORM("DataModuleUnit.cpp", DataModule1); /* TDataModule: File Type */
USEFORM("StartUnit.cpp", StartForm);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TDataModule1), &DataModule1);
		Application->CreateForm(__classid(TMainForm), &MainForm);
		Application->CreateForm(__classid(TAboutBox), &AboutBox);
		Application->CreateForm(__classid(TOptionsDlg), &OptionsDlg);
		Application->CreateForm(__classid(TAddItemDialog), &AddItemDialog);
		Application->CreateForm(__classid(TAddUserDialog), &AddUserDialog);
		Application->CreateForm(__classid(TProfForm), &ProfForm);
		Application->CreateForm(__classid(TTestTypesForm), &TestTypesForm);
		Application->CreateForm(__classid(TStartForm), &StartForm);
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
