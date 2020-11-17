//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("mainUnit.cpp", mainForm);
USEFORM("LongProcessForm.cpp", LongProcDlg);
USEFORM("..\..\common\AboutForm.cpp", AboutBox);
USEFORM("exportImagesOptionsUnit.cpp", exportImagesDlg);
USEFORM("dictinaryItemEditor.cpp", dictinaryItemDlg);
USEFORM("dictinaryEditor.cpp", dictinaryEditDlg);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TmainForm), &mainForm);
		Application->CreateForm(__classid(TAboutBox), &AboutBox);
		Application->CreateForm(__classid(TdictinaryEditDlg), &dictinaryEditDlg);
		Application->CreateForm(__classid(TdictinaryItemDlg), &dictinaryItemDlg);
		Application->CreateForm(__classid(TLongProcDlg), &LongProcDlg);
		Application->CreateForm(__classid(TexportImagesDlg), &exportImagesDlg);
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
