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
	result.X = m_model[0][0]*p.X + m_model[0][1]*p.Y + m_model[0][2];
	result.Y = m_model[1][0]*p.X + m_model[1][1]*p.Y + m_model[1][2];
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

		_mm[3*i] = _x.X;
		_mm[3*i + 1] = _x.Y;
		_mm[3*i + 2] = 1;


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
/*
	сохранение пространственной колибровки.
	сохраняются исходные изображения в файлы awp фомата
	 531s.awp  и 570s.awp
*/
bool TPriSpatialCalibration::SaveCalibration(UnicodeString path)
{
	AnsiString _name = path;
	_name = path + "\\531s.awp";
	if (awpSaveImage(_name.c_str(), m_531f) != AWP_OK)
		return false;
	_name = path + "\\570s.awp";
	if (awpSaveImage(_name.c_str(), m_570f) != AWP_OK)
		return false;
	awpImage* model = NULL;
	if (awpCreateImage(&model, 3,2, 1, AWP_DOUBLE) != AWP_OK)
		return false;
	return true;
}
/*
	загрузка пространственной калибровки.
	по пути указанному в переменной path считывается
	три изображения 531s.awp 570s.awp
	в случае удачной загрузки эти изображения копируются
	во внутренние переменные класса
*/
bool TPriSpatialCalibration::LoadCalibration(UnicodeString path)
{
	awpImage* i531 = NULL;
	awpImage* i570 = NULL;
	AnsiString _name;
	_name = path + "\\531s.awp";
	if (awpLoadImage(_name.c_str(), &i531) != AWP_OK)
		return false;
	_name = path + "\\570s.awp";
	if (awpLoadImage(_name.c_str(), &i570) != AWP_OK)
	{
		_AWP_SAFE_RELEASE_(i531)
		return false;
	}

	// копирование
	_AWP_SAFE_RELEASE_(m_531f)
	_AWP_SAFE_RELEASE_(m_570f)


	awpCopyImage(i531, &m_531f);
	awpCopyImage(i570, &m_570f);

	_AWP_SAFE_RELEASE_(i531)
	_AWP_SAFE_RELEASE_(i570)
	return findPoints();
}

awpImage* TPriSpatialCalibration::invTransform(awpImage* src)
{
	awpImage* result = NULL;
	if (src == NULL)
		return result;
	if (awpCreateImage(&result, src->sSizeX, src->sSizeY, src->bChannels, src->dwType) != AWP_OK)
		return result;

	AWPDOUBLE* s = (AWPDOUBLE*)src->pPixels;
	AWPDOUBLE* r = (AWPDOUBLE*)result->pPixels;

	double k = m_model[1][0]/m_model[0][0];
	double m = m_model[1][1] - m_model[1][0]*m_model[0][1]/m_model[0][0];

	double n = m_model[0][1]/m_model[1][1];
	double l = m_model[0][0] - m_model[0][1]*m_model[1][0]/m_model[1][1];
	for (int y = 0; y < result->sSizeY; y++)
	{
		for (int x = 0; x < result->sSizeX; x++)
		{
			int _x = floor(((double)x - m_model[0][2] - n*((double)y - m_model[1][2])) / l + 0.5);
			int _y = floor(((double)y - m_model[1][2] - k*((double)x - m_model[0][2])) /m + 0.5);
			if (_x < 0 || _x > src->sSizeX || _y < 0 || _y > src->sSizeY)
				continue;
			r[y*result->sSizeX + x] = s[_y*src->sSizeX + _x];
		}
	}

	return result;
}

awpImage* TPriSpatialCalibration::Transform(awpImage* src)
{
	awpImage* result = NULL;

	if (awpCreateImage(&result, src->sSizeX, src->sSizeY, src->bChannels, src->dwType) != AWP_OK)
		return result;

	AWPDOUBLE* s = (AWPDOUBLE*)src->pPixels;
	AWPDOUBLE* r = (AWPDOUBLE*)result->pPixels;

	for (int y = 0; y < result->sSizeY; y++)
	{
		for (int x = 0; x < result->sSizeX; x++)
		{
			awp2DPoint p;
			awp2DPoint _p;
			awpPoint pp;

			p.X = x;
			p.Y = y;

			_p = Correct(p);
			pp.X = floor(_p.X + 0.5);
			pp.Y = floor(_p.Y + 0.5);

			if (pp.X < 0 || pp.X > result->sSizeX || pp.Y < 0 || pp.Y > result->sSizeY)
				continue;

			r[pp.Y*result->sSizeX + pp.X] = s[y*src->sSizeX + x];
		}
	}
	return result;
}


awpImage* TPriSpatialCalibration::GetInvModel()
{
	awpImage* inv = NULL;
	awpImage* src = NULL;
	if (awpCreateImage(&src, 2,2, 1, AWP_DOUBLE) != AWP_OK)
		return NULL;

	if (awpCreateImage(&inv, 2,2, 1, AWP_DOUBLE) != AWP_OK)
	{
	_AWP_SAFE_RELEASE_(src)
		return NULL;
	}

	AWPDOUBLE* s = (AWPDOUBLE*)src->pPixels;

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			s[i*2 + j] = m_model[i][j];
		}
	}

	awpMatrixInvert(src, inv);


	_AWP_SAFE_RELEASE_(src)

	return 	inv;
}


#pragma package(smart_init)
