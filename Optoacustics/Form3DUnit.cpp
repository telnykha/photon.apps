//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Form3DUnit.h"
#include "MainFormUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cspin"
#pragma resource "*.dfm"
TForm3DView *Form3DView;
//---------------------------------------------------------------------------
__fastcall TForm3DView::TForm3DView(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm3DView::FormHide(TObject *Sender)
{
	// здесь мы должны вы€снить, к какой панели подсоединен компонент.
	if (Parent != NULL)
	{
		MainForm->ShowLeftDockPanel(Parent, false, NULL);
	}

}
//---------------------------------------------------------------------------
void __fastcall TForm3DView::FormShow(TObject *Sender)
{
	if (Parent != NULL)
	{
		MainForm->ShowLeftDockPanel(Parent, true, NULL);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm3DView::DrawCube(TCanvas* cnv)
{
	TCube cube(&t);
	cube.Draw(cnv);
}

void __fastcall TForm3DView::PaintBox1Paint(TObject *Sender)
{
	Graphics::TBitmap* bmp = new Graphics::TBitmap();
	bmp->Width = PaintBox1->Width;
	bmp->Height= PaintBox1->Height;
	TCanvas* cnv = bmp->Canvas;

	cnv->Brush->Color = clBlack;

	TRect rect;  rect.left = 0; rect.top = 0;
	rect.Bottom = ClientHeight;
	rect.right =  ClientWidth;
	cnv->FillRect(rect);
	if (CheckBox1->Checked)
	{
		DrawCube(cnv);
	}
	cnv->Pen->Color = clRed;
	if (MainForm->m_3DSource.GetCount() > 0)
	{
		double z = 1- (double)MainForm->PhImage1->Frames->CurrentFrame / 281.;
		for (int i = 0; i < MainForm->m_3DSource.GetCount(); i+=CSpinEdit1->Value)
		{

			TLFZones* zones = (TLFZones*)MainForm->m_3DSource.Get(i);
			double zz = 1 - (double)i/281. ;
			for (int j = 0; j < zones->GetCount(); j++)
			{
				TLFZone* z = zones->GetZone(j);
				TLF2DContour* cc  = z->GetContour();
				awp2DPoint p = cc->GetPoint(0);
				T3DPoint p3d;
				p3d.x = p.X / 500.;
				p3d.y = p.Y / 500.;
				p3d.z = zz;
				TPoint p1 = t.GetProjection(p3d);
				cnv->MoveTo(p1.x, p1.y);
				for(int k = 0; k < cc->GetNumPoints(); k++)
				{
					p = cc->GetPoint(k);
					T3DPoint p3d;
					p3d.x = p.X / 500.;
					p3d.y = p.Y / 500.;
					p3d.z = zz;
					p1 = t.GetProjection(p3d);
					cnv->LineTo(p1.x, p1.y);
				}
			}
		}
	}


	cnv->Pen->Color = clLime;
	if (MainForm->m_p.GetNumContours() > 0)
	{
		double z = 1- (double)MainForm->PhImage1->Frames->CurrentFrame / 281.;
		for (int i = 0; i < MainForm->m_p.GetNumContours(); i++)
		{
			TLF2DContour* cc  = MainForm->m_p.GetContour(i);
			awp2DPoint p = cc->GetPoint(0);
			T3DPoint p3d;
			p3d.x = p.X / 500.;
			p3d.y = p.Y / 500.;
			p3d.z = z;
			TPoint p1 = t.GetProjection(p3d);
			cnv->MoveTo(p1.x, p1.y);
			for(int j = 0; j < cc->GetNumPoints(); j++)
			{
				p = cc->GetPoint(j);
				T3DPoint p3d;
				p3d.x = p.X / 500.;
				p3d.y = p.Y / 500.;
				p3d.z = z;
				p1 = t.GetProjection(p3d);
				cnv->LineTo(p1.x, p1.y);
			}
		}
	}


	PaintBox1->Canvas->Draw(0,0,bmp);
	delete bmp;
}
//---------------------------------------------------------------------------

void __fastcall TForm3DView::PaintBox1MouseDown(TObject *Sender, TMouseButton Button,
		  TShiftState Shift, int X, int Y)
{
	this->m_mdown = true;
	m_dx = X;
	m_dy = Y;
}
//---------------------------------------------------------------------------

void __fastcall TForm3DView::PaintBox1MouseUp(TObject *Sender, TMouseButton Button,
		  TShiftState Shift, int X, int Y)
{
	m_mdown = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm3DView::PaintBox1MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y)
{
	 if (m_mdown)
	 {
		m_dx -= X;
		m_dy -= Y;
		t.ay = t.ay + m_dy;
		t.az = t.az + m_dx;
		PaintBox1Paint(NULL);
		m_dx = X;
		m_dy = Y;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TForm3DView::CSpinEdit1Change(TObject *Sender)
{
	PaintBox1Paint(NULL);
}
//---------------------------------------------------------------------------

void __fastcall TForm3DView::CheckBox1Click(TObject *Sender)
{
   PaintBox1Paint(NULL);
}
//---------------------------------------------------------------------------

