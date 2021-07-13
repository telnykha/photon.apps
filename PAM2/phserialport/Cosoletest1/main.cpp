#include <vcl.h>
#include <windows.h>

#pragma hdrstop
#pragma argsused

#include <tchar.h>
#include <stdio.h>
#include "../phserialport.h"

extern "C"
{
	#pragma link "../phserialport.lib"
}


int _tmain(int argc, _TCHAR* argv[])
{
	int c = 0;
	SetConsoleOutputCP(1251);

	phserialPortInit();
	phserialPortCount(c);
	printf("���������� ���������������� ������: %i \n", c);
	for (int i = 0; i < c; i++)
	{
		char buf[PHSERIAL_BUF];
        printf("-------------------------------------------\n");
		printf("��� �����: %s\n", phserialPortName(buf, i));
		printf("��������� ������������: %s\n", phserialPortLocation(buf, i));
		printf("��������: %s\n", phserialPortDescription(buf, i));
		printf("�������������: %s\n", phserialPortManufacturer(buf, i));
		printf("�������� �����: %s\n", phserialPortSerialNumber(buf, i));
		bool value = false;
		phserialPortHasVendorIdentifier(value, i);
		printf("������� ������������� ����������: %s\n", value?"��":"���");
		unsigned short value1;
		if (value) {

			phserialPortVendorIdentifier(value1, i);
			printf("������������� ����������: %hu \n", value1);
		}
		phserialPortHasProductIdentifier(value, i);
		printf("������� ������������� ��������: %s\n", value?"��":"���");
		if (value) {

			phserialPortProductIdentifier(value1, i);
			printf("������������� ��������: %hu \n", value1);
		}

	}
	phserialPortFree();
	return 0;
}
