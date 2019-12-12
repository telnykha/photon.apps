//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ImageViewForm.h"
#include "MainForm.h"
#include "TableViewForm.h"
#include "_LF.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FImage"
#pragma resource "*.dfm"
TFragmentForm *FragmentForm;
//---------------------------------------------------------------------------
__fastcall TFragmentForm::TFragmentForm(TComponent* Owner)
    : TForm(Owner)
{
	m_descr = NULL;
}
//---------------------------------------------------------------------------
void __fastcall TFragmentForm::DrawSelected()
{
  if (!Visible)
  	return;

	Label2->Caption = "unknown";

	TLFDetectedItem* di = Form1->m_Descr.GetDetectedItem(Form1->SelectedIndex);
    if (di == NULL)
    {
        FImage1->Close();
		FImage1->Paint();
		return;
	}
	TLFRect* rr = di->GetBounds();
	awpRect  r  = rr->GetRect();

	awpImage* pImage = NULL;
	awpImage* pFragment = NULL;

	Form1->FImage1->Bitmap->GetAWPImage(&pImage);
	if (pImage == NULL)
	{
		FImage1->Close();
		FImage1->Paint();
		return;
	}

	if (this->SpeedButton2->Down)
	{

		  TLFScanner scanner;
		  TLFImage   lfimg;

		  scanner.SetBaseWidth(di->GetBW());
		  scanner.SetBaseHeight(di->GetBH());

		  lfimg.SetImage(pImage);
		  scanner.Scan(lfimg.GetImage()->sSizeX, lfimg.GetImage()->sSizeY);

		float maxOverlap = 0;
		TLFRect maxRect;
		TLFRect* bounds = di->GetBounds();
		for (int j = 0; j < scanner.GetFragmentsCount(); j++)
		{
		  awpRect r = scanner.GetFragmentRect(j);
		  TLFRect scanBox; scanBox.SetRect(r);
		  float overlap = bounds->RectOverlap(scanBox);
		  if (overlap > maxOverlap)
		  {
			  maxOverlap = overlap;
			  maxRect = scanBox;
		  }
		}
		r = maxRect.GetRect();
	}
	awpCopyRect(pImage, &pFragment, &r);
	if (this->CheckBox1->Checked)
		DoDetectionFragment(pFragment);
	else
		DoDetectionImage(pImage, r);

	FImage1->Bitmap->SetAWPImage(pFragment);
	if (this->SpeedButton1->Down)
		FImage1->BestFit();
	else
		FImage1->ActualSize();
	awpReleaseImage(&pFragment);
	awpReleaseImage(&pImage);
    ///////////////////////////////////////////////
    Edit1->Text = di->GetDetectorName();
    int index = ComboBox1->Items->IndexOf(di->GetType().c_str());
    if (index >= 0)
    {
     	ComboBox1->ItemIndex = index;
    }
   // Edit2->Text = di->GetType().c_str();
    Edit3->Text = FloatToStr(di->GetRaiting());
    Edit4->Text = IntToStr(di->GetAngle());
	Edit5->Text = IntToStr(di->GetRacurs());
	Edit2->Text = di->GetComment().c_str();
}
void __fastcall TFragmentForm::SpeedButton1Click(TObject *Sender)
{
	DrawSelected();
}
//---------------------------------------------------------------------------

void __fastcall TFragmentForm::SpeedButton2Click(TObject *Sender)
{
	DrawSelected();
}
//---------------------------------------------------------------------------
void __fastcall TFragmentForm::DoDetectionFragment(awpImage* img)
{

   if (img == NULL)
	return;
   awpConvert(img, AWP_CONVERT_3TO1_BYTE);
   TSCObjectDetector* d = (TSCObjectDetector*)Form1->Engine->GetDetector();
   if (d != NULL)
   {
	  d->Init(img);
	  double err[4];
	  int v[4];
	  awpRect r;
	  r.left = 0;
	  r.top = 0;
	  r.right = img->sSizeX;
	  r.bottom = img->sSizeY;
	  d->ClassifyRect(r, err, v);
	  if (v[0] <= 0)
		 Label2->Caption = "false";
	  else
		 Label2->Caption = "true";
   }
}

void __fastcall TFragmentForm::DoDetectionImage(awpImage* img, awpRect& rect)
{
   if (img == NULL)
	return;
   TSCObjectDetector* d = (TSCObjectDetector*)Form1->Engine->GetDetector();
   if (d != NULL)
   {
	  d->Init(img);
	  double err[4];
	  int v[4];

	  d->ClassifyRect(rect, err, v);
	  if (v[0] <= 0)
		 Label2->Caption = "false";
	  else
		 Label2->Caption = "true";
   }
}


void __fastcall TFragmentForm::CheckBox1Click(TObject *Sender)
{
	DrawSelected();
}
//---------------------------------------------------------------------------

void __fastcall TFragmentForm::Button1Click(TObject *Sender)
{
	TLFDetectedItem* di = Form1->m_Descr.GetDetectedItem(Form1->SelectedIndex);
    //
    AnsiString _ansi = ComboBox1->Text;
	di->SetType(_ansi.c_str());
	_ansi = Edit2->Text;
	di->SetComment(_ansi.c_str());
    Form1->DbSaveMarkActionExecute(NULL);
}
//---------------------------------------------------------------------------

void __fastcall TFragmentForm::FormShow(TObject *Sender)
{
	ChangeDictonary();
}
//---------------------------------------------------------------------------

void __fastcall TFragmentForm::ComboBox1Change(TObject *Sender)
{
	AnsiString strLabel = ComboBox1->Text;
	if (this->m_descr != NULL)
	{
		TLFDetectedItem* item = m_descr->GetDetectedItem(Form1->SelectedIndex);
		if (item != NULL)
		{
			 item->SetType(strLabel.c_str());
			 TableForm->ChangeItem(Form1->SelectedIndex, strLabel.c_str());
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFragmentForm::ApplicationEvents1Idle(TObject *Sender, bool &Done)

{
	SpeedButton3->Enabled = this->m_descr != NULL && this->m_descr->GetCount() > 1;
	SpeedButton4->Enabled = this->m_descr != NULL && this->m_descr->GetCount() > 1;
	SpeedButton5->Enabled = this->m_descr != NULL && this->m_descr->GetCount() > 1;
	SpeedButton6->Enabled = this->m_descr != NULL && this->m_descr->GetCount() > 1;
}
//---------------------------------------------------------------------------
void __fastcall TFragmentForm::ChangeDictonary()
{
	ComboBox1->Items->Clear();
    for (int i = 0; i < Form1->m_db.Dictionary->GetCount(); i++)
    {
        TLFSemanticDictinaryItem* word = Form1->m_db.Dictionary->GetWordFromDictinary(i);
        if (word != NULL)
        {
			ComboBox1->Items->Add(word->GetItemLabel());
        }
    }
    ComboBox1->ItemIndex = 0;
}

void __fastcall TFragmentForm::SpeedButton3Click(TObject *Sender)
{
	Form1->SelectedIndex = 0;
    TableForm->ListView1->ItemIndex = 0;
    this->DrawSelected();
}
//---------------------------------------------------------------------------

void __fastcall TFragmentForm::SpeedButton4Click(TObject *Sender)
{
	int idx = Form1->SelectedIndex;
    idx--;
    if (idx >= 0)
    {
		Form1->SelectedIndex = idx;
    }

    this->DrawSelected();
}
//---------------------------------------------------------------------------

void __fastcall TFragmentForm::SpeedButton5Click(TObject *Sender)
{
	int idx = Form1->SelectedIndex;
    idx++;
    if (idx <  Form1->m_Descr.GetCount())
    {
		Form1->SelectedIndex = idx;
    }

    this->DrawSelected();
}
//---------------------------------------------------------------------------

void __fastcall TFragmentForm::SpeedButton6Click(TObject *Sender)
{
	Form1->SelectedIndex = Form1->m_Descr.GetCount() - 1;
    this->DrawSelected();
}
//---------------------------------------------------------------------------



void __fastcall TFragmentForm::ComboBox1Exit(TObject *Sender)
{
	if (this->m_descr != NULL)
	{
		TLFDetectedItem* item = m_descr->GetDetectedItem(Form1->SelectedIndex);
		if (item != NULL)
		{
			 AnsiString _ansi = Edit2->Text;
			 item->SetComment(_ansi.c_str());
			 //TableForm->ChangeItem(Form1->SelectedIndex, strLabel.c_str());
		}
	}
}
//---------------------------------------------------------------------------

