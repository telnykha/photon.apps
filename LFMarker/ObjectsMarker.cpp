//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
#include <Vcl.Styles.hpp>
#include <Vcl.Themes.hpp>
USEFORM("MainForm.cpp", Form1);
USEFORM("MedianFilterForm.cpp", MedianFilterDlg);
USEFORM("GaussFilterForm.cpp", GaussFilterDlg);
USEFORM("ImageViewForm.cpp", FragmentForm);
USEFORM("LongProcessForm.cpp", LongProcDlg);
USEFORM("SelRectForm.cpp", RectToolForm);
USEFORM("SystemOptionsForm.cpp", PagesDlg);
USEFORM("TableViewForm.cpp", TableForm);
USEFORM("ResizeForm.cpp", ResizeDlg);
USEFORM("RotateForm.cpp", RotateDlg);
USEFORM("FilterForm.cpp", FilterDlg);
USEFORM("..\EngineView\EngineViewUnit.cpp", EngineViewForm);
USEFORM("DbConvertForm.cpp", DbConvertDlg);
USEFORM("..\common\AboutForm.cpp", AboutBox);
USEFORM("..\common\dictinaryEditor.cpp", dictinaryEditDlg);
USEFORM("..\common\dictinaryItemEditor.cpp", dictinaryItemDlg);
USEFORM("DbSplitForm.cpp", DbSplitDlg);
USEFORM("DetectorInfoForm.cpp", DetectorForm);
USEFORM("DictionaryForm.cpp", DictionaryDialog);
USEFORM("EngineErrForm.cpp", EngineErrDlg);
USEFORM("DbCopyForm.cpp", DbCopyDlg);
USEFORM("DbExportForm.cpp", DbExportDialog);
USEFORM("DbInfoForm.cpp", DbInfoDialog);
//---------------------------------------------------------------------------
HANDLE hm = 0;
bool Check()
{
      bool res=  false;
	  hm = CreateMutex(NULL, false, L"CFBROWSER_Mutex");

	  return res;
}

WINAPI wWinMain(HINSTANCE, HINSTANCE, LPWSTR, int)
{
    try
    {
 //        Check();
        Application->Initialize();
        Application->CreateForm(__classid(TForm1), &Form1);
		Application->CreateForm(__classid(TAboutBox), &AboutBox);
		Application->CreateForm(__classid(TTableForm), &TableForm);
		Application->CreateForm(__classid(TFragmentForm), &FragmentForm);
		Application->CreateForm(__classid(TRectToolForm), &RectToolForm);
		Application->CreateForm(__classid(TDbInfoDialog), &DbInfoDialog);
		Application->CreateForm(__classid(TDbExportDialog), &DbExportDialog);
		Application->CreateForm(__classid(TPagesDlg), &PagesDlg);
		Application->CreateForm(__classid(TEngineErrDlg), &EngineErrDlg);
		Application->CreateForm(__classid(TDbConvertDlg), &DbConvertDlg);
		Application->CreateForm(__classid(TDbCopyDlg), &DbCopyDlg);
		Application->CreateForm(__classid(TDetectorForm), &DetectorForm);
		Application->CreateForm(__classid(TEngineViewForm), &EngineViewForm);
		Application->CreateForm(__classid(TDictionaryDialog), &DictionaryDialog);
		Application->CreateForm(__classid(TDbSplitDlg), &DbSplitDlg);
		Application->CreateForm(__classid(TLongProcDlg), &LongProcDlg);
		Application->CreateForm(__classid(TRotateDlg), &RotateDlg);
		Application->CreateForm(__classid(TFilterDlg), &FilterDlg);
		Application->CreateForm(__classid(TGaussFilterDlg), &GaussFilterDlg);
		Application->CreateForm(__classid(TMedianFilterDlg), &MedianFilterDlg);
		Application->CreateForm(__classid(TResizeDlg), &ResizeDlg);
		Application->CreateForm(__classid(TdictinaryEditDlg), &dictinaryEditDlg);
		Application->CreateForm(__classid(TdictinaryItemDlg), &dictinaryItemDlg);
		Application->Run();
        ReleaseMutex(hm);
        CloseHandle(hm);
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
