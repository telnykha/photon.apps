//---------------------------------------------------------------------------

#ifndef ComReaderUnitH
#define ComReaderUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#define BUFSIZE 255     		//������� ������

bool COMOpen(UnicodeString portname);             //������� ����
void COMClose(void);            //������� ����


//---------------------------------------------------------------------------
//����� ��� ������ ������������������ ������ �� COM-����� � �����
class ReadThread : public TThread
{
 private:
        void __fastcall Printing0();	//����� �������� ������ �� ����� � � ����
 protected:
        void __fastcall Execute();	//�������� ������� ������
 public:
        __fastcall ReadThread(bool CreateSuspended);	//����������� ������
};


//����� ��� ������ ������������������ ������ �� ������ � COM-����
class WriteThread : public TThread
{
private:
protected:
        void __fastcall Execute();      //�������� ������� ������
public:
        __fastcall WriteThread(bool CreateSuspended);	//����������� ������
};

extern ReadThread  *reader;     //������ ������ ReadThread
extern WriteThread *writer;     //������ ������ WriteThread

//---------------------------------------------------------------------------
#endif
