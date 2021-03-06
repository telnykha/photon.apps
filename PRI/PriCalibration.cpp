//---------------------------------------------------------------------------
#pragma hdrstop

#include "PriCalibration.h"
#include "PriProcessor.h"
#include "ArchiveUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

TPriCalibration::TPriCalibration()
{
	m_531 = NULL;
	m_531f  = NULL;
	m_531c = NULL;
	m_531cf = NULL;
	m_570 = NULL;
	m_570f = NULL;
	m_570c = NULL;
	m_570cf = NULL;
	// ������������ ���������� �������� 1280x960 ��������.
	// �� ��������� ������ ������������� ���� �� 10% � ������ �������.
	m_zone.left = IMAGE_WIDTH / 10;
	m_zone.top  = IMAGE_WIDTH / 10;
	m_zone.right = IMAGE_WIDTH - m_zone.left; // 1280 - 128
	m_zone.bottom = IMAGE_HEIGHT - m_zone.top; // 960 - 96
}
TPriCalibration::~TPriCalibration()
{
	ClearData();
}

void TPriCalibration::ClearData()
{
	_AWP_SAFE_RELEASE_(m_531)
	_AWP_SAFE_RELEASE_(m_531f)
	_AWP_SAFE_RELEASE_(m_531c)
	_AWP_SAFE_RELEASE_(m_531cf)
	_AWP_SAFE_RELEASE_(m_570)
	_AWP_SAFE_RELEASE_(m_570f)
	_AWP_SAFE_RELEASE_(m_570c)
	_AWP_SAFE_RELEASE_(m_570cf)
}

bool TPriCalibration::DoCalibration(TPriProcessor* processor)
{

	if(m_531c == NULL || m_570c == NULL || m_531cf == NULL || m_570cf)
		return false;

	assert(processor);
	assert(processor->_570);
	assert(processor->_570b);
	assert(processor->_531);
	assert(processor->_531b);

	if (awpCalcImage(m_531c, processor->_531b, NULL, AWP_CALC_INPLACE, AWP_CALC_MLTIMAGES) != AWP_OK)
		return false;

	if (awpCalcImage(m_531cf, processor->_531, NULL, AWP_CALC_INPLACE, AWP_CALC_MLTIMAGES) != AWP_OK)
		return false;

	if (awpCalcImage(m_570c, processor->_570b, NULL, AWP_CALC_INPLACE, AWP_CALC_MLTIMAGES) != AWP_OK)
		return false;

	if (awpCalcImage(m_570cf, processor->_570, NULL, AWP_CALC_INPLACE, AWP_CALC_MLTIMAGES) != AWP_OK)
		return false;

	return true;
}
/*
	������ � ���������� ��������� � ��������� �����.
	����� ������ ��������� 8 �����������
	4 ������� (��� �� ������ ����� ����� �� �������� � ��� �������)
	4 ����� (�� ��� �� ������ ����� �����, �� �������� � ��� �������)
	� xml ����, � ������� ��������� ���������� � ������� �������
	��������� ����������.
*/

#define _LOAD_IMAGE_( a )\
if (awpLoadImage(_fn.c_str(), &a) != AWP_OK) \
{ \
	result = false; \
	goto cleanup; \
}

bool TPriCalibration::LoadCalibration(UnicodeString path)
{
	ClearData();

	if (!DirectoryExists(path))
		return false;

	bool result = true;

	// ����������� � �������� 531 nm
	AnsiString _fn = path+"\\531.awp";
	_LOAD_IMAGE_(m_531)

	_fn = path+"\\531f.awp";
	_LOAD_IMAGE_(m_531f)

	_fn = path+"\\531c.awp";
	_LOAD_IMAGE_(m_531c)

	_fn = path+"\\531cf.awp";
	_LOAD_IMAGE_(m_531cf)

	// ����������� � �������� 570 nm
	_fn = path+"\\570.awp";
	_LOAD_IMAGE_(m_570)

	_fn = path+"\\570f.awp";
	_LOAD_IMAGE_(m_570f)

	_fn = path+"\\570c.awp";
	_LOAD_IMAGE_(m_570c)

	_fn = path+"\\531cf.awp";
	_LOAD_IMAGE_(m_570cf)

	// �������� ���� ����������
    result = this->LoadSettings(path);
cleanup:
	return result;
}
// ���������� ������������� ���������� � ����� path
bool TPriCalibration::SaveCalibration(UnicodeString path)
{
	if (!DirectoryExists(path))
	{
		if (!CreateDir(path))
			return false;
	}

	// ��������� �����������
	AnsiString _fn = path+"\\531.awp";
	if (awpSaveImage(_fn.c_str(), m_531) != AWP_OK)
		return false;

	_fn = path+"\\531f.awp";
	if (awpSaveImage(_fn.c_str(), m_531f) != AWP_OK)
		return false;

	_fn = path+"\\531c.awp";
	if (awpSaveImage(_fn.c_str(), m_531c) != AWP_OK)
		return false;

	_fn = path+"\\531cf.awp";
	if (awpSaveImage(_fn.c_str(), m_531cf) != AWP_OK)
		return false;


	_fn = path+"\\570.awp";
	if (awpSaveImage(_fn.c_str(), m_531) != AWP_OK)
		return false;

	_fn = path+"\\570f.awp";
	if (awpSaveImage(_fn.c_str(), m_531f) != AWP_OK)
		return false;

	_fn = path+"\\570c.awp";
	if (awpSaveImage(_fn.c_str(), m_531c) != AWP_OK)
		return false;

	_fn = path+"\\570cf.awp";
	if (awpSaveImage(_fn.c_str(), m_531cf) != AWP_OK)
		return false;

	// ��������� ����, ��� ��������� ������������� ����������.

	return SaveSettings(path);
}

bool TPriCalibration::LoadArchive(UnicodeString path)
{
	TPRIArchive archive;
	awpImage* m531 = NULL;
	awpImage* m531f = NULL;
	awpImage* m570 = NULL;
	awpImage* m570f = NULL;
	if (!archive.LoadImages(path, &m531, &m570, &m531f, &m570f))
		return false;

	awpConvert(m531, AWP_CONVERT_TO_DOUBLE);
	awpConvert(m531f, AWP_CONVERT_TO_DOUBLE);
	awpConvert(m570, AWP_CONVERT_TO_DOUBLE);
	awpConvert(m570f, AWP_CONVERT_TO_DOUBLE);

	ClearData();
	if (awpCopyImage(m531, &m_531) != AWP_OK)
		return false;
	if (awpCopyImage(m531f, &m_531f) != AWP_OK)
		return false;
	if (awpCopyImage(m570, &m_570) != AWP_OK)
		return false;
	if (awpCopyImage(m570f, &m_570f) != AWP_OK)
		return false;

	_AWP_SAFE_RELEASE_(m531)
	_AWP_SAFE_RELEASE_(m531f)
	_AWP_SAFE_RELEASE_(m570)
	_AWP_SAFE_RELEASE_(m570f)

	return MakeCalibrationImages();
}
// ������� ������������� ���������� m_531c  m_531cf m_570c  m_570cf
bool TPriCalibration::MakeCalibrationImages()
{
	_AWP_SAFE_RELEASE_(m_531c)
	_AWP_SAFE_RELEASE_(m_531cf)
	_AWP_SAFE_RELEASE_(m_570c)
	_AWP_SAFE_RELEASE_(m_570cf)


	if (awpCreateImage(&m_531c, IMAGE_WIDTH, IMAGE_HEIGHT, 1, AWP_DOUBLE) != AWP_OK)
		return false;

	if (awpCreateImage(&m_531cf, IMAGE_WIDTH, IMAGE_HEIGHT, 1, AWP_DOUBLE) != AWP_OK)
		return false;

	if (awpCreateImage(&m_570c, IMAGE_WIDTH, IMAGE_HEIGHT, 1, AWP_DOUBLE) != AWP_OK)
		return false;

	if (awpCreateImage(&m_570cf, IMAGE_WIDTH, IMAGE_HEIGHT, 1, AWP_DOUBLE) != AWP_OK)
		return false;

	awpFill(m_531c, 1);
	awpFill(m_531cf, 1);
	awpFill(m_570c, 1);
	awpFill(m_570cf, 1);

	MakeCalibration(m_531, m_531c);
	MakeCalibration(m_531f, m_531cf);
	MakeCalibration(m_570, m_570c);
	MakeCalibration(m_570f, m_570cf);

	return true;
}

bool TPriCalibration::SaveSettings(UnicodeString path)
{
	AnsiString _fn = path+"\\settings.txt";

	FILE* f = fopen(_fn.c_str(), "w+t");
	if (f == NULL)
		return false;
	fprintf(f, "%u\t%u\t%u\t%u\n", m_zone.left, m_zone.top, m_zone.right, m_zone.bottom);
	fclose(f);
	return true;
}

bool TPriCalibration::LoadSettings(UnicodeString path)
{
	AnsiString _fn = path+"\\settings.txt";

	FILE* f = fopen(_fn.c_str(), "r+t");
	if (f == NULL)
		return false;

	fscanf(f,"%i\t%i\t%i\t%i\n", &m_zone.left, &m_zone.top, &m_zone.right, &m_zone.bottom);

	return true;
}

bool TPriCalibration::CreateCalibration()
{
	ClearData();


	if (awpCreateImage(&m_531, IMAGE_WIDTH, IMAGE_HEIGHT, 1, AWP_DOUBLE) != AWP_OK)
		return false;

	if (awpCreateImage(&m_531f, IMAGE_WIDTH, IMAGE_HEIGHT, 1, AWP_DOUBLE) != AWP_OK)
		return false;

	if (awpCreateImage(&m_570, IMAGE_WIDTH, IMAGE_HEIGHT, 1, AWP_DOUBLE) != AWP_OK)
		return false;

	if (awpCreateImage(&m_570f, IMAGE_WIDTH, IMAGE_HEIGHT, 1, AWP_DOUBLE) != AWP_OK)
		return false;

	awpFill(m_531, 1);
	awpFill(m_531f, 1);
	awpFill(m_570, 1);
	awpFill(m_570f, 1);

	return MakeCalibrationImages();
}

double TPriCalibration::AverageImage(awpImage* image)
{
	AWPDOUBLE* d = (AWPDOUBLE*)image->pPixels;
	AWPDOUBLE result = 0;
	AWPDOUBLE s = (m_zone.bottom - m_zone.top)*(m_zone.right - m_zone.left);

	// �������� ����� ������ ROI
	for (int i = m_zone.top; i < m_zone.bottom; i++)
	{
		for (int j = m_zone.left; j < m_zone.right; j++)
		{
			result += d[i*image->sSizeX + j];
		}
	}
	result /= s;
	return result;
}


void   TPriCalibration::MakeCalibration(awpImage* src, awpImage* dst)
{
	double a =  AverageImage(src);
	AWPDOUBLE* d = (AWPDOUBLE*)dst->pPixels;
	AWPDOUBLE* s = (AWPDOUBLE*)src->pPixels;

	//
	for (int i = m_zone.top; i < m_zone.bottom; i++)
	{
		for (int j = m_zone.left; j < m_zone.right; j++)
		{
			d[i*dst->sSizeX + j] = a / (1 + s[i*dst->sSizeX + j]);
		}
	}
}

void __fastcall TPriCalibration::SetZone(awpRect Value)
{
	if (Value.left < 0 || Value.top < 0 || Value.right >= IMAGE_WIDTH || Value.bottom >= IMAGE_HEIGHT)
		return;
	m_zone = Value;
	MakeCalibrationImages();
}
