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
		psrc[0] = m_points[i].X;
		psrc[1] = m_points[i].Y;
		awpMulMatrix(imtx, src, &dst);
		double* pdst = (double*)dst->pPixels;
		m_out[i].X = pdst[0];
		m_out[i].Y = pdst[1];
		awp2DPoint p;
		p.X = w*alfa*(m_out[i].X) / 100;
		p.Y = h*alfa*(m_out[i].Y) / 100;
		awpReleaseImage(&dst);

		TPoint pp = m_pImage->GetScreenPoint((int)p.X, (int)p.Y);
		TRect rr;
		rr.init(pp.X - 16, pp.y -16, pp.x+16, pp.y + 16);
		Canvas->Brush->Style = bsClear;
		Canvas->Pen->Color = clRed;
		Canvas->Ellipse(rr);
	}

	awpReleaseImage(&mtx);
	awpReleaseImage(&imtx);
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
