//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
#include <Vcl.Styles.hpp>
#include <Vcl.Themes.hpp>
#include "BeeIniParamsUnit.h"

USEFORM("BeeOptionsForm.cpp", OptionsForm);
USEFORM("beeMain.cpp", Form10);
USEFORM("BeeAboutForm.cpp", AboutBox);
USEFORM("beeLongProcessForm.cpp", Form1);
//---------------------------------------------------------------------------
TBeeIniParams gBeeIniParams;
TBeeIniParams* beeIni = &gBeeIniParams;
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		TStyleManager::TrySetStyle(gBeeIniParams.UITheme);
		Application->CreateForm(__classid(TForm10), &Form10);
		Application->CreateForm(__classid(TForm1), &Form1);
		Application->CreateForm(__classid(TAboutBox), &AboutBox);
		Application->CreateForm(__classid(TOptionsForm), &OptionsForm);
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
