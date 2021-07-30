//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "mainUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

 extern "C"
{
    #pragma link "awpipl2b.lib"
	#pragma link "JPEGLIB.lib"
}
#pragma link "awplflibb.lib"
#pragma link "TinyXML.lib"
TForm9 *Form9;
//---------------------------------------------------------------------------
__fastcall TForm9::TForm9(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm9::FileListBox1Change(TObject *Sender)
{
	if (FileListBox1->FileName != "") {
		TStringList* list = new TStringList();
		list->Add(FileListBox1->FileName);
		PhImage1->Init(list);
		delete list;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm9::PhImage1AfterOpen(TObject *Sender)
{
	PhImage1->BestFit();


}
//---------------------------------------------------------------------------

void __fastcall TForm9::DirectoryListBox1Change(TObject *Sender)
{
	UnicodeString str = DirectoryListBox1->Directory;
	str += "\\landmarks.xml";
	 if (FileExists(str)) {
		AnsiString _ansi = str;
		if (!m_db.Connect(_ansi.c_str()))
		{
			// Draw landmarks
			ShowMessage(L"Error");
		}
	 }
	 else
        m_db.Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm9::DrawLandmarks()
{

}

void __fastcall TForm9::PhImage1Paint(TObject *Sender)
{
	if (m_db.Files()->Count() > 0) {
		 AnsiString _ansi = ExtractFileName(FileListBox1->FileName.LowerCase());
		 TLFLandmarkFile* f = m_db.Files()->File(_ansi.c_str());
		 //
		 if (f) {
			 // draw landmarks
			 awpImage* img = NULL;
			 PhImage1->GetAwpImage(&img);
			 for (int i = 0; i < f->Count(); i++) {
				 TLFLandmark* ll = f->Landmark(i);
				 if (ll) {
					   double x,y;
					   x = ll->x();
					   y = ll->y();
					   int xx = x*img->sSizeX / 100;
					   int yy = (100 - y)*img->sSizeY / 100;
					   TCanvas* cnv = PhImage1->Canvas;

					   TPoint p = PhImage1->GetScreenPoint(xx, yy);

					   TRect r;
					   TRect rr;


					   cnv->Brush->Color = ll->Color();
					   cnv->Pen->Color = ll->Color();
					   cnv->TextOutW(p.x, p.y - 30, ll->ClassName());
					   r.init(xx - 8, yy-8,xx+8, yy+8 );
					   rr= PhImage1->GetScreenRect(r);
					   cnv->Ellipse(rr);
					   cnv->Brush->Style = bsClear;
					   r.init(xx - 48, yy-48,xx+48, yy+48 );
					   rr= PhImage1->GetScreenRect(r);
					   cnv->Rectangle(rr);
				 }
			 }
			 awpReleaseImage(&img);
		 }
	}
}
//---------------------------------------------------------------------------

