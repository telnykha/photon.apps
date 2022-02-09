//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("priMainUnit.cpp", priMainForm);
USEFORM("priExperimentUnit.cpp", experimentForm);
USEFORM("priEquipmentUnit.cpp", pri2EquipmentForm);
USEFORM("priExperimentTableUnit.cpp", experimentTableForm);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TpriMainForm), &priMainForm);
		Application->CreateForm(__classid(Tpri2EquipmentForm), &pri2EquipmentForm);
		Application->CreateForm(__classid(TexperimentForm), &experimentForm);
		Application->CreateForm(__classid(TexperimentTableForm), &experimentTableForm);
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
