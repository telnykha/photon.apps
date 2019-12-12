//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "FilterForm.h"
#include "MainForm.h"
//---------------------------------------------------------------------
#pragma link "FImage"
#pragma link "CSPIN"
#pragma resource "*.dfm"
TFilterDlg *FilterDlg;
//---------------------------------------------------------------------
__fastcall TFilterDlg::TFilterDlg(TComponent* AOwner)
	: TForm(AOwner)
{
}
//---------------------------------------------------------------------

void __fastcall TFilterDlg::FormShow(TObject *Sender)
{
    _AWP_SAFE_RELEASE_(m_image)
    Form1->FImage1->Bitmap->GetAWPImage(&m_image);

    FImage1->Bitmap->SetAWPImage(m_image);
    FImage1->BestFit();
}
//---------------------------------------------------------------------------

void __fastcall TFilterDlg::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    _AWP_SAFE_RELEASE_(m_image)
}
//---------------------------------------------------------------------------


void __fastcall TFilterDlg::ListBox1Click(TObject *Sender)
{
   awpImage* src = NULL;
   awpImage* dst = NULL;
   awpCopyImage(m_image, &src);
   awpCopyImage(m_image, &dst);

   awpFilter(src, dst,  ListBox1->ItemIndex);

   FImage1->Bitmap->SetAWPImage(dst);
   FImage1->BestFit();
   awpReleaseImage(&src);
   awpReleaseImage(&dst);
}
//---------------------------------------------------------------------------

