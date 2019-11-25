//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "editorUnit.h"

#define FRAME_CAPTURE_TIME 70
#define COMMAND_MIN_TIME   1
#define COMMAND_MAX_TIME   100000

//---------------------------------------------------------------------
#pragma resource "*.dfm"
TeditorDlg *editorDlg;

//---------------------------------------------------------------------
__fastcall TeditorDlg::TeditorDlg(TComponent* AOwner)
	: TForm(AOwner)
{
}
//---------------------------------------------------------------------

void __fastcall TeditorDlg::ComboBox1Change(TObject *Sender)
{

    // ������������� ����
    if (ComboBox1->ItemIndex == 8)
    {
        SpinEdit1->Value = FRAME_CAPTURE_TIME;
        SpinEdit2->Value = 100;
        SpinEdit1->Enabled = false;
        SpinEdit2->Enabled = false;
    }
    // ���������� ���� [0..10%] ������������ �������
    else if (ComboBox1->ItemIndex == 7)
    {
        SpinEdit1->Enabled = true;
        SpinEdit2->Enabled = true;
        SpinEdit1->MinValue = COMMAND_MIN_TIME;
        SpinEdit1->MaxValue = COMMAND_MAX_TIME;
    }
    // ���� � ���������� �����
    else if (ComboBox1->ItemIndex == 6)
    {
        SpinEdit1->Value    = FRAME_CAPTURE_TIME;
        SpinEdit1->MinValue = FRAME_CAPTURE_TIME;
        SpinEdit1->MaxValue = COMMAND_MAX_TIME;
        SpinEdit2->Value = 50;
        SpinEdit1->Enabled = true;
        SpinEdit2->Enabled = true;
    }
    // ���� � ���������� �����
    else if (ComboBox1->ItemIndex == 5)
    {
         SpinEdit1->Value    = FRAME_CAPTURE_TIME;
        SpinEdit1->MinValue = FRAME_CAPTURE_TIME;
        SpinEdit1->MaxValue = COMMAND_MAX_TIME;
        SpinEdit2->Value = 50;
        SpinEdit1->Enabled = true;
        SpinEdit2->Enabled = true;
    }
    // ��������� ��� ���������
    else if (ComboBox1->ItemIndex == 4)
    {
        SpinEdit1->MinValue = COMMAND_MIN_TIME;
        SpinEdit1->MaxValue = COMMAND_MAX_TIME;
        SpinEdit1->Enabled = true;

        SpinEdit2->Value = 0;
        SpinEdit2->Enabled = false;
    }
    // �������� ����
    else if (ComboBox1->ItemIndex == 3)
    {
        SpinEdit1->Value = FRAME_CAPTURE_TIME;
        SpinEdit1->MinValue = FRAME_CAPTURE_TIME;
        SpinEdit1->MaxValue = FRAME_CAPTURE_TIME;

        SpinEdit2->Value = 0;
        SpinEdit2->Enabled = false;
    }
    // ���� � �������������� �����
    else if (ComboBox1->ItemIndex == 2)
    {
        SpinEdit1->Value = FRAME_CAPTURE_TIME;
        SpinEdit1->MinValue = FRAME_CAPTURE_TIME;
        SpinEdit1->MaxValue = COMMAND_MAX_TIME;

        SpinEdit1->Enabled = true;
        SpinEdit2->Enabled = true;
    }
    // �������������� ����
    else if (ComboBox1->ItemIndex == 1)
    {
        SpinEdit1->Enabled = true;
        SpinEdit2->Enabled = true;
        SpinEdit1->MinValue = COMMAND_MIN_TIME;
        SpinEdit1->MaxValue = COMMAND_MAX_TIME;
    }
    // ���������� ����
    else
    {
        SpinEdit1->Enabled = true;
        SpinEdit2->Enabled = true;
        SpinEdit1->MinValue = COMMAND_MIN_TIME;
        SpinEdit1->MaxValue = COMMAND_MAX_TIME;
    }

}
//---------------------------------------------------------------------------

