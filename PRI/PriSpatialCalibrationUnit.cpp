//---------------------------------------------------------------------------
#pragma hdrstop
#include "PriSpatialCalibrationUnit.h"
#include "ArchiveUnit.h"
#include "..\..\cvvideo\module\awpcvvideo\awpcvvideo.h"

#include "awpGauss.h"
#pragma link "awpcvvideo.lib"
//---------------------------------------------------------------------------
TPriSpatialCalibration::TPriSpatialCalibration()
{
	//
	m_531f = NULL;
	m_570f = NULL;

	m_model[0][0] = 1.03;
	m_model[0][1]   = 0;
	m_model[1][0]  = -0.01;
	m_model[1][1]  = 1.03;
}

TPriSpatialCalibration::~TPriSpatialCalibration()
{
	//
	_AWP_SAFE_RELEASE_(m_531f)
	_AWP_SAFE_RELEASE_(m_570f)
}

bool TPriSpatialCalibration::LoadArchive(UnicodeString path)
{
	TPRIArchive archive;

	awpImage* m531 = NULL;
	awpImage* m531f = NULL;
	awpImage* m570 = NULL;
	awpImage* m570f = NULL;
	if (!archive.LoadImages(path, &m531, &m570, &m531f, &m570f))
		return false;

	awpConvert(m531f, AWP_CONVERT_TO_BYTE_WITH_NORM);
	awpConvert(m570f, AWP_CONVERT_TO_BYTE_WITH_NORM);

	awpCopyImage(m531f,&m_531f);
	awpCopyImage(m570f, &m_570f);


	_AWP_SAFE_RELEASE_(m531)
	_AWP_SAFE_RELEASE_(m531f)
	_AWP_SAFE_RELEASE_(m570)
	_AWP_SAFE_RELEASE_(m570f)


	return findPoints();
}

bool TPriSpatialCalibration::findPoints()
{
	if (awpcvChessboard(m_531f, m_p531f) != S_OK)
		return false;
	if (awpcvChessboard(m_570f, m_p570f) != S_OK)
		return false;

	return MakeModel();
}

awp2DPoint* __fastcall TPriSpatialCalibration::Get531Points()
{
	return m_p531f;
}

awp2DPoint* __fastcall TPriSpatialCalibration::Get570Points()
{
	return m_p570f;
}

double __fastcall TPriSpatialCalibration::GetSourceError()
{
	double result = 0;
	for(int i = 0; i < NUM_CHESS_POINTS; i++)
	{
		result += ((m_p531f[i].X - m_p570f[i].X)*(m_p531f[i].X - m_p570f[i].X) + (m_p531f[i].Y - m_p570f[i].Y)*(m_p531f[i].Y - m_p570f[i].Y));
	}
	result /= NUM_CHESS_POINTS;
	return sqrt(result);
}
double __fastcall TPriSpatialCalibration::GetResultError()
{
	double result = 0;
	for(int i = 0; i < NUM_CHESS_POINTS; i++)
	{
		awp2DPoint p = Correct(m_p570f[i]);
		result += ((m_p531f[i].X - p.X)*(m_p531f[i].X - p.X) + (m_p531f[i].Y - p.Y)*(m_p531f[i].Y - p.Y));
	}
	result /= NUM_CHESS_POINTS;
	return sqrt(result);

	return 0;
}

awp2DPoint __fastcall TPriSpatialCalibration::Correct(awp2DPoint p)
{
	awp2DPoint result;
	result.X = m_model[0][0]*p.X + m_model[0][1]*p.Y + m_model[0][3];
	result.Y = m_model[1][0]*p.X + m_model[1][1]*p.Y + m_model[1][3];
	return result;
}


/*
	преобразует два набора точек на плоскости в два awp изображения.
	в соответствии с заданной координатой (index)
	index = 0 - X
	index = 1 - Y
	matrix - матрица измеренных значений координат точки
	yy - матрица истинных значений координат точки

	истинные значения 531 нм измеренные - 570 нм

*/
static bool points2images(awp2DPoint* ps, awp2DPoint* pm, awpImage* matrix, awpImage* yy, int index)
{

	AWPDOUBLE* _mm = (AWPDOUBLE*)matrix->pPixels;
	AWPDOUBLE* _yy = (AWPDOUBLE*)yy->pPixels;

	for (int i = 0; i < NUM_CHESS_POINTS; i++)
	{
		awp2DPoint _x = pm[i];
		awp2DPoint _y = ps[i];

		_mm[2*i] = _x.X;
		_mm[2*i + 1] = _x.Y;
		_mm[2*i + 2] = 1;


		if (index == 0)
			_yy[i] = _y.X;
		else if (index == 1)
			_yy[i] = _y.Y;
	}
	return true;
}

bool TPriSpatialCalibration::MakeModel()
{
	awpImage* mtrx = NULL;
	awpImage* yv   = NULL;
	awpImage* bi   = NULL;

	if (awpCreateImage(&mtrx, 3, NUM_CHESS_POINTS, 1, AWP_DOUBLE) != AWP_OK)
		return false;
	if (awpCreateImage(&yv,   1, NUM_CHESS_POINTS, 1, AWP_DOUBLE) != AWP_OK)
		return false;
	if (awpCreateImage(&bi, 1, 3, 1, AWP_DOUBLE) != AWP_OK)
		return false;

	bool result = true;
	AWPDOUBLE* _bi = (AWPDOUBLE*)bi->pPixels;
	try
	{
		for (int i = 0; i < 2; i++)
		{
			if (!points2images(m_p531f, m_p570f, mtrx, yv, i))
				throw 0;
			if (awpLinearRegress(mtrx, yv, bi) != AWP_OK)
				throw 0;
			for (int j = 0; j < 3; j++)
				m_model[i][j] = _bi[j];

			awpZeroImage(mtrx);
			awpZeroImage(yv);
			awpZeroImage(bi);
		}
	}
	catch(...)
	{
		result = false;
	}

	_AWP_SAFE_RELEASE_(mtrx)
	_AWP_SAFE_RELEASE_(yv)
	_AWP_SAFE_RELEASE_(bi)

	return result;
}
#pragma package(smart_init)
