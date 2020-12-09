//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "diff_table.h"
#include "IniFileUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDifficult_command *Difficult_command;
//---------------------------------------------------------------------------
__fastcall TDifficult_command::TDifficult_command(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDifficult_command::Add_command(TObject *Sender)
{
editorDlg->ComboBox1->ItemIndex = 0;
	editorDlg->SpinEdit2->Value = 0;
	editorDlg->SpinEdit1->Value = 100;
	editorDlg->Edit1->Text = L"";
	if (editorDlg->ShowModal() == mrOk)
    {
		//todo: добавить новую команду
		control_table->AddRecord(editorDlg);
	}
}
//---------------------------------------------------------------------------
void __fastcall TDifficult_command::FormCreate(TObject *Sender)
{
control_table = new TCommandsTable(StringGrid1, &mm_options);
//mm_clipFormat = clipFormat;
}
//---------------------------------------------------------------------------
void __fastcall TDifficult_command::editAddAction2Excute(TObject *Sender)
{
editorDlg->ComboBox1->ItemIndex = 0;
	editorDlg->SpinEdit2->Value = 0;
	editorDlg->SpinEdit1->Value = 100;
	editorDlg->Edit1->Text = L"";
	if (editorDlg->ShowModal() == mrOk)
	{
		control_table->InsertRecord(StringGrid1->Row, editorDlg);
	}
}
//---------------------------------------------------------------------------
void __fastcall TDifficult_command::editDeleteAction2(TObject *Sender)
{
control_table->DeleteRecord(StringGrid1->Row);
}
//---------------------------------------------------------------------------
void __fastcall TDifficult_command::editEditActionExcute(TObject *Sender)
{
	TList* list = control_table->list;
	expEvent* e = (expEvent*)list->Items[StringGrid1->Row-1];
	assert(e != NULL);

	editorDlg->ComboBox1->ItemIndex = e->command;
	editorDlg->SpinEdit2->Value = e->pinStatus;
	editorDlg->SpinEdit1->Value = e->pinDelay;
	editorDlg->Edit1->Text = StringGrid1->Cells[4][StringGrid1->Row];


	if (editorDlg->ShowModal() == mrOk)
	{
		//todo: добавить новую команду
		control_table->EditRecord(StringGrid1->Row, editorDlg);
	}
}
//-------------------------------------------------------------------------
void __fastcall TDifficult_command::editUpActionExecute2(TObject *Sender)
{
control_table->Up(StringGrid1->Row);
}
//---------------------------------------------------------------------------
void __fastcall TDifficult_command::editDownActionExecute(TObject *Sender)
{
  control_table->Down(StringGrid1->Row);
}
//---------------------------------------------------------------------------

void __fastcall TDifficult_command::EditCopyActionExecute(TObject *Sender)
{
 	if (!OpenClipboard(this->Handle))
	{
		ShowMessage(L"Не могу открыть буфер обмена.");
		return;
	}
	EmptyClipboard();
// 1. Get Command
	TList* list = control_table->list;
	expEvent* e = (expEvent*)list->Items[StringGrid1->Row-1];

// 2. Copy commnad to global memory block
	HGLOBAL hglb2Copy;
	hglb2Copy = GlobalAlloc(GMEM_MOVEABLE,sizeof(expEvent));
	if (hglb2Copy == NULL)
	{
		CloseClipboard();
		ShowMessage(L"Не могу скопировать в буфер обмена.");
		return;
	}
	expEvent* copy = (expEvent*)GlobalLock(hglb2Copy);
	memcpy(copy, e, sizeof(expEvent));
	GlobalUnlock(hglb2Copy);
// 3. Отправим данные в буфер обмена
   SetClipboardData(mainPAM->clipFormat, hglb2Copy);
   CloseClipboard();
}
//---------------------------------------------------------------------------

void __fastcall TDifficult_command::EditCopyActionUpdate(TObject *Sender)
{
 N5->Enabled = StringGrid1->Row > 0;
}
//---------------------------------------------------------------------------

void __fastcall TDifficult_command::EditPastActionExecute(TObject *Sender)
{
	 HGLOBAL   hglb2;
	 if (!OpenClipboard(this->Handle))
		return;
	 hglb2 = GetClipboardData(mainPAM->clipFormat);
	 if(hglb2 != NULL)
	 {
		expEvent* e =  (expEvent*)GlobalLock(hglb2);
		if (e != NULL)
		{
			editorDlg->ComboBox1->ItemIndex = e->command;
			editorDlg->SpinEdit2->Value = e->pinStatus;
			editorDlg->SpinEdit1->Value = e->pinDelay;
			editorDlg->Edit1->Text = "";
			GlobalUnlock(hglb2);
			control_table->InsertRecord(StringGrid1->Row, editorDlg);
		}
	 }
	 CloseClipboard();
}
//---------------------------------------------------------------------------


void __fastcall TDifficult_command::EditPastActionUpdate(TObject *Sender)
{
N6->Enabled = IsClipboardFormatAvailable(mainPAM->clipFormat);
}
//---------------------------------------------------------------------------

void __fastcall TDifficult_command::EditCopyToFileExecute(TObject *Sender)
{
	awpImage* img = NULL;


   if (control_table->fileName == c_FileName)
	  FileSaveAsActionExecute(NULL);
   else
	  control_table->Save();
}
//---------------------------------------------------------------------------

void __fastcall TDifficult_command::EditCopyToFileUpdate(TObject *Sender)
{
		N5->Enabled = StringGrid1->Row > 0;
}
//---------------------------------------------------------------------------

void __fastcall TDifficult_command::FileSaveAsActionExecute(TObject *Sender)
{
	UnicodeString strFilter = L"Файлы PAM|*.pam";
	if (SaveDialog1->Execute())
	{
		UnicodeString ustr = SaveDialog1->FileName.c_str();
		if(ExtractFileExt(ustr) != L".pam")
			ustr += L".pam";
		AnsiString str = ustr;
		control_table->SaveTable(str.c_str());
	}
}
//---------------------------------------------------------------------------

void __fastcall TDifficult_command::FileSaveAsActionUpdate(TObject *Sender)
{
EditCopyToFile->Enabled = StringGrid1->RowCount > 1;
}
//---------------------------------------------------------------------------


void __fastcall TDifficult_command::PastFromeFileExecute(TObject *Sender)
{
   if (OpenDialog1->Execute())
    {
        AnsiString str = OpenDialog1->FileName.c_str();
		control_table->LoadTable(str.c_str());
        PageControl1->TabIndex = 0;
	}
}
//---------------------------------------------------------------------------


