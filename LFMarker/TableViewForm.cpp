//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TableViewForm.h"
#include "MainForm.h"
#include "ImageViewForm.h"
#include "_LF.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TTableForm *TableForm;


static AnsiString SizeToStringHelper(int size)
{
     switch (size)
     {
        case 1:
            return "Huge";
        case 2:
            return "Big";

        case 3:
            return "Medium";
        case 4:
            return "Small";
        case 5:
            return "Very small";
        default:
            return "Unknown";
     }
}

static AnsiString PosToStringHelper(int pos)
{
     switch (pos)
     {
        case 1:
            return "Left-Top";
        case 2:
            return "Top";
        case 3:
            return "Right-Top";
        case 4:
            return "Left";
		case 5:
			return "Center";
		case 6:
			return "Right";
		case 7:
			return "Left-Bottom";
		case 8:
			return "Bottom";
		case 9:
			return "Right-Bottom";
		default:
			return "Unknown";
	 }
}

static AnsiString RacursToStringHepler(int racurs)
{
switch (racurs)
{
	case 0:
		return "Front";
	case 1:
		return "Left semi-profile";
	case 2:
		return "Left profile";
	case 3:
		return "Left back semi-profile";
	case 4:
		return "Back";
	case 5:
		return "Right back semi-profile";
	case 6:
		return "Right profile";
	case 7:
		return "Right semi-profile";
	case 8:
		return "Bottom front";
	case 9:
		return "Bottom left semi-propfile";
	case 10:
		return "Bottom left profile";
	case 11:
		return "Bottom back left semi-profile";
	case 12:
		return "Bottom back";
	case 13:
		return "Bottom back right semi profile";
	case 14:
		return "Bottom right profile";
	case 15:
		return "Bottom right semi propfile";
	case 16:
		return "Bottom";
	case 17:
		return "Up front";
	case 18:
		return "Up left semi profile";
	case 19:
		return "Up left profile";
	case 20:
		return "Up left back semi profile";
	case 21:
		return "Up back";
	case 22:
		return "Up back right semi profile";
	case 23:
		return "Up right profile";
	case 24:
		return "Up right semi profile";
	case 25:
		return "Up";
}
}

//---------------------------------------------------------------------------
__fastcall TTableForm::TTableForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTableForm::FormShow(TObject *Sender)
{
    this->ListView1->Columns->Clear();
    TListColumn  *NewColumn;
    TListItem  *ListItem;

    NewColumn = ListView1->Columns->Add();
    NewColumn->Caption = "ID";

    NewColumn = ListView1->Columns->Add();
    NewColumn->Caption = "Detector";

    NewColumn = ListView1->Columns->Add();
    NewColumn->Caption = "Class label";

    NewColumn = ListView1->Columns->Add();
    NewColumn->Caption = "Raiting";

    NewColumn = ListView1->Columns->Add();
    NewColumn->Caption = "Angle";

	NewColumn = ListView1->Columns->Add();
	NewColumn->Caption = "Racurs";


    NewColumn = ListView1->Columns->Add();
    NewColumn->Caption = "Bw";

    NewColumn = ListView1->Columns->Add();
    NewColumn->Caption = "Bh";

    NewColumn = ListView1->Columns->Add();
    NewColumn->Caption = "left";

    NewColumn = ListView1->Columns->Add();
    NewColumn->Caption = "top";

    NewColumn = ListView1->Columns->Add();
    NewColumn->Caption = "width";

    NewColumn = ListView1->Columns->Add();
    NewColumn->Caption = "height";

    NewColumn = ListView1->Columns->Add();
    NewColumn->Caption = "Size";


    NewColumn = ListView1->Columns->Add();
    NewColumn->Caption = "Position";
    this->UpdateTable();
}
//---------------------------------------------------------------------------
void __fastcall TTableForm::SpeedButton2Click(TObject *Sender)
{
   Form1->m_Descr.DeleteDetectedItem(Form1->SelectedIndex);
   AnsiString str =  ChangeFileExt(Form1->m_strFileName, ".xml");
   Form1->m_Descr.SaveXML(str.c_str());
   Form1->FImage1->Init(Form1->m_strFileName, NULL);
   Form1->FImage1->BestFit();
   ListView1->DeleteSelected();
}
//---------------------------------------------------------------------------
void __fastcall TTableForm::SpeedButton3Click(TObject *Sender)
{
	Form1->m_Descr.Clear();
   AnsiString str =  ChangeFileExt(Form1->m_strFileName, ".xml");
   Form1->m_Descr.SaveXML(str.c_str());
	Form1->FImage1->Init(Form1->m_strFileName, NULL);
    Form1->FImage1->BestFit();
    this->ListView1->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TTableForm::SpeedButton4Click(TObject *Sender)
{
//    
}
//---------------------------------------------------------------------------
void __fastcall TTableForm::SpeedButton5Click(TObject *Sender)
{
//    
}
//---------------------------------------------------------------------------
void __fastcall TTableForm::AddNewItem(TLFDetectedItem* di)
{
    TListItem  *ListItem;
    ListItem = ListView1->Items->Add();
    ListItem->Caption = IntToStr(Form1->m_Descr.GetItemsCount()-1);

    ListItem->SubItems->Add(di->GetDetectorName());
	ListItem->SubItems->Add(di->GetType().c_str());
    ListItem->SubItems->Add(FormatFloat("0.00",di->GetRaiting()));
	ListItem->SubItems->Add(IntToStr(di->GetAngle()));
	ListItem->SubItems->Add(RacursToStringHepler(di->GetRacurs()));
	ListItem->SubItems->Add(IntToStr(di->GetBW()));
    ListItem->SubItems->Add(IntToStr(di->GetBH()));

    TLFRect* rr = di->GetBounds();
    awpRect r = rr->GetRect();

    ListItem->SubItems->Add(IntToStr(r.left));
    ListItem->SubItems->Add(IntToStr(r.top));
	  ListItem->SubItems->Add(IntToStr(r.right - r.left));
	  ListItem->SubItems->Add(IntToStr(r.bottom - r.top));

    ListItem->SubItems->Add(SizeToStringHelper(Form1->m_Descr.GetItemSize(Form1->m_Descr.GetItemsCount()-1)));
    ListItem->SubItems->Add(PosToStringHelper(Form1->m_Descr.GetItemPos(Form1->m_Descr.GetItemsCount()-1)));
}


void __fastcall TTableForm::ListView1Change(TObject *Sender,
      TListItem *Item, TItemChange Change)
{ /*
    if (ListView1->Selected != NULL)
    {
	 Form1->SelectedIndex = Item->Index;
     FragmentForm->DrawSelected();
    }*/
}
//---------------------------------------------------------------------------
void __fastcall TTableForm::UpdateTable()
{
	if (!Visible)
    	return;
	ListView1->Items->Clear();

	TListColumn  *NewColumn;
	TListItem  *ListItem;

	for (int i = 0; i < Form1->m_Descr.GetItemsCount(); i++)
	{

	  TLFDetectedItem* di = Form1->m_Descr.GetDetectedItem(i);
	  ListItem = ListView1->Items->Add();
	  ListItem->Caption = IntToStr(i);
	  ListItem->SubItems->Add(di->GetDetectorName());
	  ListItem->SubItems->Add(di->GetType().c_str());
	  ListItem->SubItems->Add(FormatFloat("0.00",di->GetRaiting()));
	  ListItem->SubItems->Add(IntToStr(di->GetAngle()));
	  ListItem->SubItems->Add(RacursToStringHepler(di->GetRacurs()));
	  ListItem->SubItems->Add(IntToStr(di->GetBW()));
	  ListItem->SubItems->Add(IntToStr(di->GetBH()));

	  TLFRect* rr = di->GetBounds();
	  awpRect r = rr->GetRect();

	  ListItem->SubItems->Add(IntToStr(r.left));
	  ListItem->SubItems->Add(IntToStr(r.top));
	  ListItem->SubItems->Add(IntToStr(r.right - r.left));
	  ListItem->SubItems->Add(IntToStr(r.bottom - r.top));

	  ListItem->SubItems->Add(SizeToStringHelper(Form1->m_Descr.GetItemSize(i)));
	  ListItem->SubItems->Add(PosToStringHelper(Form1->m_Descr.GetItemPos(i)));
	}

	if (Form1->m_Descr.GetItemsCount() > 0)
	{
	   ListView1->Selected =   ListView1->Items->Item[0];
	   Form1->SelectedIndex = 0;
	}

    FragmentForm->DrawSelected();
}
void __fastcall TTableForm::FormHide(TObject *Sender)
{
    FragmentForm->Visible = false;
}
//---------------------------------------------------------------------------


void __fastcall TTableForm::FragmentViewActionExecute(TObject *Sender)
{
    FragmentForm->Visible = !FragmentForm->Visible;
    if (FragmentForm->Visible)
       FragmentForm->DrawSelected();
}
//---------------------------------------------------------------------------

void __fastcall TTableForm::FragmentViewActionUpdate(TObject *Sender)
{
    FragmentViewAction->Checked =  FragmentForm->Visible;
}
//---------------------------------------------------------------------------

void __fastcall TTableForm::ListView1SelectItem(TObject *Sender, TListItem *Item,
          bool Selected)
{
	if (!Visible)
    	return;
    if (ListView1->Selected != NULL)
    {
	 Form1->SelectedIndex = Item->Index;
     FragmentForm->DrawSelected();
    }
}
//---------------------------------------------------------------------------
void __fastcall TTableForm::ChangeItem(int index, const char* value)
{
	TListItem  *ListItem = this->ListView1->Items->Item[index];
    if (ListItem != NULL)
    {
		ListItem->SubItems->Strings[1] = value;
    }
}

