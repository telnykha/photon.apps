//---------------------------------------------------------------------------

#ifndef TableViewFormH
#define TableViewFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include "LF.h"
#include <AppEvnts.hpp>
#include <ActnList.hpp>
#include <System.Actions.hpp>
//---------------------------------------------------------------------------
class TTableForm : public TForm
{
__published:	// IDE-managed Components
    TPanel *Panel1;
    TListView *ListView1;
    TSpeedButton *SpeedButton2;
    TSpeedButton *SpeedButton3;
    TSpeedButton *SpeedButton6;
    TActionList *ActionList1;
    TAction *FragmentViewAction;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall SpeedButton2Click(TObject *Sender);
    void __fastcall SpeedButton3Click(TObject *Sender);
    void __fastcall SpeedButton4Click(TObject *Sender);
    void __fastcall SpeedButton5Click(TObject *Sender);
    void __fastcall ListView1Change(TObject *Sender, TListItem *Item,
          TItemChange Change);
    void __fastcall FormHide(TObject *Sender);
    void __fastcall FragmentViewActionExecute(TObject *Sender);
    void __fastcall FragmentViewActionUpdate(TObject *Sender);
	void __fastcall ListView1SelectItem(TObject *Sender, TListItem *Item, bool Selected);

private:	// User declarations
public:		// User declarations
    __fastcall TTableForm(TComponent* Owner);

    void __fastcall AddNewItem(TLFDetectedItem* di);
    void __fastcall UpdateTable();
    void __fastcall ChangeItem(int index, const char* value);
};
//---------------------------------------------------------------------------
extern PACKAGE TTableForm *TableForm;
//---------------------------------------------------------------------------
#endif
