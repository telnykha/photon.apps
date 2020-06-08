//---------------------------------------------------------------------------
// ��������� ����������
#ifndef PriCalibrationH
#define PriCalibrationH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include "_LF.h"
class TPriProcessor;
class TPriCalibration
{
private:
	bool SaveSettings(UnicodeString path);
	bool LoadSettings(UnicodeString path);
protected:
	awpImage* m_531;
	awpImage* m_531f;
	awpImage* m_531c;
	awpImage* m_531cf;
	awpImage* m_570;
	awpImage* m_570f;
	awpImage* m_570c;
	awpImage* m_570cf;
	// ��������� ���������� ������������� �����������
	// m_531c, m_531cf, m_570c, m_570cf
	bool MakeCalibrationImages();
	void ClearData();
	awpRect   m_zone;
public:
	TPriCalibration();
	~TPriCalibration();
	// ��������� ��������� ���������� �����������
	// � ���������� PRI
	bool DoCalibration(TPriProcessor* processor);
	// �������� ������������� ����������
	bool LoadCalibration(UnicodeString path);
	// ���������� ������������� ����������
	bool SaveCalibration(UnicodeString path);
	// ��������� �������� ����������� �� ������
	// � ������� ����������� ��� ����������  m_531c, m_531cf, m_570c, m_570cf
	bool LoadArchive(UnicodeString path);
};
#endif
