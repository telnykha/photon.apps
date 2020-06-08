//---------------------------------------------------------------------------

#pragma hdrstop

#include "PriCalibration.h"
#include "PriProcessor.h"
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
	m_zone.left = 128;
	m_zone.top  = 96;
	m_zone.right = 1152; // 1280 - 128
	m_zone.bottom = 864; // 960 - 96
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
	_LOAD_IMAGE_(m_531)

	_fn = path+"\\570f.awp";
	_LOAD_IMAGE_(m_531f)

	_fn = path+"\\570c.awp";
	_LOAD_IMAGE_(m_570c)

	_fn = path+"\\531cf.awp";
	_LOAD_IMAGE_(m_570cf)

	// �������� ���� ����������

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
	//
	return false;
}
//
bool TPriCalibration::MakeCalibrationImages()
{

}

bool TPriCalibration::SaveSettings(UnicodeString path)
{
	AnsiString _fn = path+"\\settings.txt";

	FILE* f = fopen(_fn.c_str(), "w+t");
	if (f == NULL)
		return false;
	fprintf(f, "%uh\t%uh\t%uh\t%uh\n", m_zone.left, m_zone.top, m_zone.right, m_zone.bottom);
	fclose(f);
	return true;
}

bool TPriCalibration::LoadSettings(UnicodeString path)
{
	AnsiString _fn = path+"\\settings.txt";

	FILE* f = fopen(_fn.c_str(), "w+t");
	if (f == NULL)
		return false;

	fscanf(f,"%uh\t%uh\t%uh\t%uh\n", &m_zone.left, &m_zone.top, &m_zone.right, &m_zone.bottom);

	return true;
}


