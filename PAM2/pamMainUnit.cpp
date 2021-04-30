/*
*/
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "pamMainUnit.h"
#include "pamConsoleUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FImage41"
#pragma link "Comm"
#pragma resource "*.dfm"
TpamMainForm *pamMainForm;
//---------------------------------------------------------------------------
__fastcall TpamMainForm::TpamMainForm(TComponent* Owner)
	: TForm(Owner)
{
}
void TpamMainForm::ShowDockPanel(TWinControl* APanel, bool MakeVisible, TControl* Client)
{
  if (APanel == NULL || (!MakeVisible && (APanel->VisibleDockClientCount > 1)))
	return;
  if (MakeVisible)
  {
	  if (APanel->Name == L"BottomDocPanel")
		  APanel->Height = ClientHeight / 3;
	  else
		  APanel->Width = ClientWidth / 3;
  }
  else
  {
	  if (APanel->Name == L"BottomDocPanel")
		  APanel->Height = 5;
	  else
		  APanel->Width = 5;
  }

  if (MakeVisible && (Client != NULL))
	Client->Show();
}
//---------------------------------------------------------------------------
void __fastcall TpamMainForm::filesClosActionExecute(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TpamMainForm::LeftDocPanelDockOver(TObject *Sender, TDragDockObject *Source,
		  int X, int Y, TDragState State, bool &Accept)
{
  Accept = (Source->Control) != NULL;
  if (Accept)
  {
	// Modify the DockRect to preview dock area.
	Types::TPoint TopLeft = LeftDocPanel->ClientToScreen(Point(0, 0));
	Types::TPoint BottomRight = LeftDocPanel->ClientToScreen(Point(PhImage1->Width / 3, LeftDocPanel->Height));
	Source->DockRect = Types::TRect(TopLeft, BottomRight);
  }
}
//---------------------------------------------------------------------------
void __fastcall TpamMainForm::RightDocPanelDockOver(TObject *Sender, TDragDockObject *Source,
		  int X, int Y, TDragState State, bool &Accept)
{
  Accept = (Source->Control) != NULL;
  if (Accept)
  {
	// Modify the DockRect to preview dock area.
	Types::TPoint TopLeft = LeftDocPanel->ClientToScreen(Point(ClientWidth, 0));
	Types::TPoint BottomRight = LeftDocPanel->ClientToScreen(Point(ClientWidth - PhImage1->Width / 3, RightDocPanel->Height));
	Source->DockRect = Types::TRect(TopLeft, BottomRight);
  }
}
//---------------------------------------------------------------------------
void __fastcall TpamMainForm::BottomDocPanelDockOver(TObject *Sender, TDragDockObject *Source,
          int X, int Y, TDragState State, bool &Accept)
{
  Accept = (Source->Control) != NULL;
  if (Accept)
  {
	// Modify the DockRect to preview dock area.
	Types::TPoint TopLeft = BottomDocPanel->ClientToScreen(Point(BottomDocPanel->Left, -PhImage1->Height/3));
	Types::TPoint BottomRight = BottomDocPanel->ClientToScreen(Point(BottomDocPanel->Width, BottomDocPanel->Height));
	Source->DockRect = Types::TRect(TopLeft, BottomRight);
  }

}
//---------------------------------------------------------------------------
void __fastcall TpamMainForm::windowConsoleActionExecute(TObject *Sender)
{
	ConsoleForm->Visible = !ConsoleForm->Visible;
}
//---------------------------------------------------------------------------
void __fastcall TpamMainForm::LeftDocPanelUnDock(TObject *Sender, TControl *Client, TWinControl *NewTarget,
          bool &Allow)
{
	ShowDockPanel(LeftDocPanel, false, NULL);
}
//---------------------------------------------------------------------------
void __fastcall TpamMainForm::LeftDocPanelDockDrop(TObject *Sender, TDragDockObject *Source,
		  int X, int Y)
{
	ShowDockPanel(LeftDocPanel, true, NULL);
}
//---------------------------------------------------------------------------
void __fastcall TpamMainForm::RightDocPanelDockDrop(TObject *Sender, TDragDockObject *Source,
		  int X, int Y)
{
	ShowDockPanel(RightDocPanel, true, NULL);
}
//---------------------------------------------------------------------------
void __fastcall TpamMainForm::RightDocPanelUnDock(TObject *Sender, TControl *Client,
		  TWinControl *NewTarget, bool &Allow)
{
	ShowDockPanel(RightDocPanel, false, NULL);
}
//---------------------------------------------------------------------------
void __fastcall TpamMainForm::BottomDocPanelDockDrop(TObject *Sender, TDragDockObject *Source,
		  int X, int Y)
{
	ShowDockPanel(BottomDocPanel, true, NULL);
}
//---------------------------------------------------------------------------
void __fastcall TpamMainForm::BottomDocPanelUnDock(TObject *Sender, TControl *Client,
		  TWinControl *NewTarget, bool &Allow)
{
	ShowDockPanel(BottomDocPanel, false, NULL);
}
//---------------------------------------------------------------------------
void __fastcall TpamMainForm::FormCreate(TObject *Sender)
{
	Comm1->DeviceName = L"COM5";
	Comm1->Open();
	Comm1->SetRTSState(true);
	Comm1->SetDTRState(true);
}
//---------------------------------------------------------------------------
void __fastcall TpamMainForm::Comm1RxChar(TObject *param_0, DWORD Count)
{
	int i , Bytes ;
	char rb[5000], ts[5000];
	memset(rb, 0, sizeof(rb));
	memset(ts, 0, sizeof(ts));
	//if (ShowCommEvent->Checked) Memo1->Lines->Add("Before Read : " + IntToStr(Comm1->InQueCount()));
	Bytes = Comm1->Read(rb, Count);

	if (Bytes>0)
	{
		//if (ShowCommEvent->Checked) Memo1->Lines->Add("Received character bytes : "+IntToStr(Bytes)) ;
		for (i=0;i<Bytes;i++)
		{
			if ((rb[i] ==  0))
			  { ; }
			 else if (/*rb[i]=='\n' ||*/ rb[i] == '\r')
				{ ConsoleForm->Memo1->Lines->Add(TimeToStr(Time()) +L">" + rs); rs="" ;}
			  else
			  {
				sprintf(ts,"%c",rb[i]); rs=rs+ts;
			  }
		}
	}

}
//---------------------------------------------------------------------------

