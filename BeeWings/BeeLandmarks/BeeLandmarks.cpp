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
USEFORM("DiaKIND.cpp", KindEdit);
USEFORM("beeLongProcessForm.cpp", longProcessForm);
USEFORM("BeeAboutForm.cpp", AboutBox);
USEFORM("BeeKindEditor.cpp", kindEditorForm);
USEFORM("..\GrafCI\BeeAnalysisForm.cpp", AnalysisForm);
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
		Application->CreateForm(__classid(TlongProcessForm), &longProcessForm);
		Application->CreateForm(__classid(TAboutBox), &AboutBox);
		Application->CreateForm(__classid(TOptionsForm), &OptionsForm);
		Application->CreateForm(__classid(TKindEdit), &KindEdit);
		Application->CreateForm(__classid(TkindEditorForm), &kindEditorForm);
		Application->CreateForm(__classid(TAnalysisForm), &AnalysisForm);
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
