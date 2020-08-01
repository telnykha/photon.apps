//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("MainFormUnit.cpp", MainForm);
USEFORM("Form3DUnit.cpp", Form3DView);
USEFORM("FormBimaryUnit.cpp", FormBinaryView);
USEFORM("FormLongProcessUnit.cpp", LongProcessForm);
USEFORM("FormResultUnit.cpp", FormResultView);
USEFORM("FormTableUnit.cpp", FormTableView);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TMainForm), &MainForm);
		Application->CreateForm(__classid(TForm3DView), &Form3DView);
		Application->CreateForm(__classid(TFormTableView), &FormTableView);
		Application->CreateForm(__classid(TFormBinaryView), &FormBinaryView);
		Application->CreateForm(__classid(TFormResultView), &FormResultView);
		Application->CreateForm(__classid(TLongProcessForm), &LongProcessForm);
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
