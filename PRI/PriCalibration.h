//---------------------------------------------------------------------------
// ��������� ����������
#ifndef PriCalibrationH
#define PriCalibrationH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include "_LF.h"

#define IMAGE_WIDTH 1280
#define IMAGE_HEIGHT 960
class TPriProcessor;
class TPriCalibration
{
private:
	bool SaveSettings(UnicodeString path);
	bool LoadSettings(UnicodeString path);

	double AverageImage(awpImage* image);
	void   MakeCalibration(awpImage* src, awpImage* dst);
protected:
	awpImage* m_531;       // ����������� 531 ��
	awpImage* m_531f;      // ����������� 531 ��
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

	void __fastcall SetZone(awpRect Value);
public:
	TPriCalibration();
	~TPriCalibration();
	// ������� ������������� ���������� �� ���������
	bool CreateCalibration();
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

	__property awpRect zone = {read = m_zone, write = SetZone};

	__property awpImage* img531 = {read = m_531};
	__property awpImage* img531f = {read = m_531f};
	__property awpImage* img531c = {read = m_531c};
	__property awpImage* img531cf = {read = m_531cf};
	__property awpImage* img570 = {read = m_570};
	__property awpImage* img570f = {read = m_570f};
	__property awpImage* img570c = {read = m_570c};
	__property awpImage* img570cf = {read = m_570cf};
};
#endif
