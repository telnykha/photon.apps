//---------------------------------------------------------------------------

#ifndef diff_tableH
#define diff_tableH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Menus.hpp>
#include "cammandsTable.h"
#include "MainUnit.h"
#include "editorUnit.h"
#include <System.Actions.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
class TDifficult_command : public TForm
{
__published:	// IDE-managed Components
	TPageControl *PageControl1;
	TStringGrid *StringGrid1;
	TPopupMenu *PopupMenu1;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *N3;
	TMenuItem *N4;
	TMenuItem *N5;
	TMenuItem *N6;
	TMenuItem *N7;
	TMenuItem *N8;
	TMenuItem *N9;
	TMenuItem *N10;
	TActionList *ActionList1;
	TAction *EditCopyAction;
	TAction *EditPastAction;
	TAction *EditCopyToFile;
	TAction *FileSaveAsAction;
	TSaveDialog *SaveDialog1;
	TMenuItem *EditCopyToFile1;
	TAction *PastFromeFile;
	TMenuItem *N11;
	TOpenDialog *OpenDialog1;
	void __fastcall Add_command(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall editAddAction2Excute(TObject *Sender);
	void __fastcall editDeleteAction2(TObject *Sender);
	void __fastcall editEditActionExcute(TObject *Sender);
	void __fastcall editUpActionExecute2(TObject *Sender);
	void __fastcall editDownActionExecute(TObject *Sender);
	void __fastcall EditCopyActionExecute(TObject *Sender);
	void __fastcall EditCopyActionUpdate(TObject *Sender);
	void __fastcall EditPastActionExecute(TObject *Sender);
	void __fastcall EditPastActionUpdate(TObject *Sender);
	void __fastcall EditCopyToFileExecute(TObject *Sender);
	void __fastcall EditCopyToFileUpdate(TObject *Sender);
	void __fastcall FileSaveAsActionExecute(TObject *Sender);
	void __fastcall FileSaveAsActionUpdate(TObject *Sender);
	void __fastcall PastFromeFileExecute(TObject *Sender);

private:	// User declarations
TCommandsTable* control_table;
TPAMOptions 	mm_options;
UINT            mm_clipFormat;
public:		// User declarations
	__fastcall TDifficult_command(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDifficult_command *Difficult_command;
//---------------------------------------------------------------------------
#endif
