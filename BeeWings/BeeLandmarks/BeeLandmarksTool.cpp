//---------------------------------------------------------------------------

#pragma hdrstop

#include "BeeLandmarksTool.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


__fastcall TPhBeeLandmarksTool::TPhBeeLandmarksTool(TComponent* Owner): TPhImageTool(Owner)
{
	m_points[0].X = 26.630311;
	m_points[0].Y = 29.036995;

	m_points[1].X = 79.292189;
	m_points[1].Y = 27.278273;

	m_points[2].X = 49.054636;
	m_points[2].Y = 33.093616;

	m_points[3].X = 35.557874;
	m_points[3].Y = 35.099718;

	m_points[4].X = 50.0000;
	m_points[4].Y = 50.0000;

	m_points[5].X = 57.519525;
	m_points[5].Y = 55.686925;

	m_points[6].X = 61.804425;
	m_points[6].Y = 54.376162;

	m_points[7].X = 50.0000;
	m_points[7].Y = 75.0000;

	memcpy(m_out, m_points, sizeof(m_out));

	m_p4.X = 50;
	m_p4.Y = 50;
	m_p7.X = 50;
	m_p7.Y = 75;


	m_selected = -1;
}
__fastcall TPhBeeLandmarksTool::~TPhBeeLandmarksTool()
{

}

void TPhBeeLandmarksTool::Draw(TCanvas* Canvas)
{
	if (this->m_pImage == NULL) {
		return;
	}

	TBrushStyle oldStyle = Canvas->Brush->Style;
	TColor oldColor = Canvas->Pen->Color;
	int    oldWidth = Canvas->Pen->Width;


	Canvas->Brush->Style = bsClear;
	Canvas->Pen->Color = clRed;
	Canvas->Pen->Width = 1;


	int w = m_pImage->Bitmap->Width;
	int h = m_pImage->Bitmap->Height;

	double L0  = sqrt((m_p4.X - m_p7.X)*(m_p4.X - m_p7.X) + (m_p4.Y - m_p7.Y)*(m_p4.Y - m_p7.Y));
	double L1  = sqrt((m_points[4].X - m_points[7].X)*(m_points[4].X - m_points[7].X) + (m_points[4].Y - m_points[7].Y)*(m_points[4].Y - m_points[7].Y));
	double alfa = L0 / L1;
	double tanfi = (m_p7.X - m_p4.X) / (m_p7.Y - m_p4.Y);
	double fi = atan(tanfi);

	double sinfi = sin(fi);
	double cosfi = cos(fi);

	awpImage* mtx = NULL;
	awpImage* imtx = NULL;
	awpCreateImage(&mtx, 2,2,1,AWP_DOUBLE);
	awpCreateImage(&imtx, 2,2,1,AWP_DOUBLE);
	double* pmtx = (double*)mtx->pPixels;

	pmtx[0] = cosfi;
	pmtx[1] = -sinfi;
	pmtx[2] = sinfi;
	pmtx[3] = cosfi;

	awpMatrixInvert(mtx, imtx);
	double* pimtx = (double*)imtx->pPixels;
	for (int i = 0; i < 8; i++) {
		awpImage* dst = NULL;
		awpImage* src = NULL;
		awpCreateImage(&src, 1,2,1,AWP_DOUBLE);
		double* psrc = (double*)src->pPixels;
		psrc[0] = m_points[i].X - m_points[4].X;
		psrc[1] = m_points[i].Y - m_points[4].Y;
		awpMulMatrix(imtx, src, &dst);
		double* pdst = (double*)dst->pPixels;
		m_out[i].X = pdst[0];
		m_out[i].Y = pdst[1];
		awp2DPoint p;

		p.X = alfa*m_out[i].X;
		p.Y = alfa*m_out[i].Y;
		p.X += m_p4.X;
		p.Y += m_p4.Y;

		awp2DPoint lt;
		awp2DPoint rb;
		double radiusx = 8;
		double radiusy = ((double)w/(double)h)*radiusx;

		lt.X = p.X - radiusx;
		lt.Y = p.Y - radiusy;
		rb.X = p.X + radiusx;
		rb.Y = p.Y + radiusy;

		TRect srcRect;
		srcRect.Left = w*lt.X / 100;
		srcRect.top  = h*lt.Y / 100;
		srcRect.bottom = h*rb.Y / 100;
		srcRect.right = w*rb.X / 100;
		double rx = 0.5;
		if (i == 4 || i == 7) {
			rx = 2;
		}

		DrawCross(p, Canvas, rx);

		p.X = w*p.X / 100.;
		p.Y = h*p.Y / 100.;

		awpReleaseImage(&dst);



		TRect rr = m_pImage->GetScreenRect(srcRect);
		Canvas->Ellipse(rr);
	}

	awpReleaseImage(&mtx);
	awpReleaseImage(&imtx);

	Canvas->Brush->Style = oldStyle;
	Canvas->Pen->Color = oldColor;
	Canvas->Pen->Width = oldWidth;

}
int TPhBeeLandmarksTool::_is_near(int X, int Y)
{
	TPoint p = m_pImage->GetImagePoint(X, Y);
	awp2DPoint pp;
	int w = m_pImage->Bitmap->Width;
	int h = m_pImage->Bitmap->Height;
	pp.X = 100.*p.x/ (double)w;
	pp.Y = 100.*p.y/ (double)h;

	if (sqrt((pp.X - m_p4.X)*(pp.X - m_p4.X) + ((pp.Y - m_p4.Y)*((pp.Y - m_p4.Y)))) < 0.5) {
		return 4;
	}
	else if (sqrt((pp.X - m_p7.X)*(pp.X - m_p7.X) + ((pp.Y - m_p7.Y)*((pp.Y - m_p7.Y)))) < 0.5) {
		return 7;
	}
	else
		return -1;
}

void TPhBeeLandmarksTool::MouseDown(int X, int Y, TMouseButton Button)
{
	 m_selected =  _is_near(X, Y);
	 if (m_selected > 0) {
		TPoint p = m_pImage->GetImagePoint(X, Y);
		awp2DPoint pp;
		int w = m_pImage->Bitmap->Width;
		int h = m_pImage->Bitmap->Height;
		pp.X = 100.*p.x/ (double)w;
		pp.Y = 100.*p.y/ (double)h;
		if (m_selected == 4) {
		   m_p4 = pp;
		}
		else if (m_selected == 7) {
		   m_p7 = pp;
		}
	 }
}
void TPhBeeLandmarksTool::MouseUp(int X, int Y, TMouseButton Button)
{
	m_selected = -1;
	m_pImage->Paint();
}
void TPhBeeLandmarksTool::MouseMove(int X, int Y, TShiftState Shift)
{
	if (_is_near(X, Y) > 0)
		m_pImage->Cursor = crHandPoint;
	else
		m_pImage->Cursor = crArrow;

	if (m_selected > 0) {
		TPoint p = m_pImage->GetImagePoint(X, Y);
		awp2DPoint pp;
		int w = m_pImage->Bitmap->Width;
		int h = m_pImage->Bitmap->Height;
		pp.X = 100.*p.x/ (double)w;
		pp.Y = 100.*p.y/ (double)h;
		if (m_selected == 4) {
		   m_p4 = pp;
		}
		else if (m_selected == 7) {
		   m_p7 = pp;
		}
	}
	m_pImage->Paint();
}
void TPhBeeLandmarksTool::Reset()
{

}

void TPhBeeLandmarksTool::DrawCross(awp2DPoint& p, TCanvas* c, double radius)
{
	int w = m_pImage->Bitmap->Width;
	int h = m_pImage->Bitmap->Height;

	double rx = radius;
	double ry = ((double)w/(double)h)*rx;

	awp2DPoint p1;
	awp2DPoint p2;
	awp2DPoint p3;
	awp2DPoint p4;

	p1.X = p.X - rx;
	p1.Y = p.Y;

	p2.X = p.X + rx;
	p2.Y = p.Y;

	p3.X = p.X;
	p3.Y = p.Y - ry;

	p4.X = p.X;
	p4.Y = p.Y + ry;

	TPoint _p1;
	TPoint _p2;
	TPoint _p3;
	TPoint _p4;

	p1.X = w*p1.X / 100;
	p1.Y = h*p1.Y / 100;

	p2.X = w*p2.X / 100;
	p2.Y = h*p2.Y / 100;

	p3.X = w*p3.X / 100;
	p3.Y = h*p3.Y / 100;

	p4.X = w*p4.X / 100;
	p4.Y = h*p4.Y / 100;

	_p1 = m_pImage->GetScreenPoint((int)p1.X, (int)p1.Y);
	_p2 = m_pImage->GetScreenPoint((int)p2.X, (int)p2.Y);
	_p3 = m_pImage->GetScreenPoint((int)p3.X, (int)p3.Y);
	_p4 = m_pImage->GetScreenPoint((int)p4.X, (int)p4.Y);

	TColor oldColor = c->Pen->Color;
	int    oldWidth = c->Pen->Width;

	c->Pen->Color = clLime;
	c->Pen->Width = 2;

	c->MoveTo(_p1.x, _p1.Y);
	c->LineTo(_p2.x, _p2.Y);

	c->MoveTo(_p3.x, _p3.Y);
	c->LineTo(_p4.x, _p4.Y);

	c->Pen->Color = oldColor;
	c->Pen->Width = oldWidth;
}

