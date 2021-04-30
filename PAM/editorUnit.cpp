//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "editorUnit.h"
#include "Parametrs_light.h"

#define FRAME_CAPTURE_TIME 70
#define COMMAND_MIN_TIME   1
#define COMMAND_MAX_TIME   100000

const char* commands_descr[9] =
{
    "Нсыщающий свет: источник излучения 470 нм включается на Длительность (мс) с заданной интенсивностью (%).\
    Минимальная интенсивность - 10% Максимальная интенсивность - 100% Интенсивность регулируется длительностью\
    свечения источника внутри промежутка времени 1000 мкс. ",
    "Дополнительный свет: источник излучения 660 нм включается на Длительность (мс) с заданной интенсивностью (%).\
    Минимальная интенсивность - 0% Максимальная интенсивность - 100% Интенсивность регулируется длительностью\
    свечения источника внутри промежутка времени 1000 мкс.",
	"Кадр в дополнительном свете: Включается видеокамера на время экспозиции. Через время задержки \
    включается источник дополнительного излучения на время длительности импульса. После включается источник\
    дополнительного излучения на длительность (мс) с заданной интенсивностью.",
    "Темновой кадр: выключаются все источники излучения и включается видеокамера на время экспозиции.",
    "Выключить все: выключаются все источники излучения на длительность (мс)",
    "Измерительный кадр в насыщающем свете: Включается видеокамера на время экспозиции. Через время задержки включается\
    источник излучения 470 нм на время длительности импульса. Затем включается насыщающий свет на длительность не менее 70 мс.",
    "Измерительный кадр в актиничном свете: Включается видеокамера на время экспозиции. Через время задержки включается\
    источник излучения 470 нм на время длительности импульса. Затем включается актиничный свет на длительность не менее 70 мс.",
    "Актиничный свет: источник излучения 470 нм включаетя на длительность (мс) в заданной интенсивностью в (%). Минимальная интенсивность - 0%,\
    максимальная интенсивность - 10%. Установка интенсивности в 100% соответствует 10% времени свечения источника излучения\
    внутри промежутка времени 1000 мкс.",
	"Измерительный кадр: Включается видеокамера на время экспозиции. Через время задержки включается\
	источник излучения 470 нм на время длительности импульса."
};

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
    this->SetupControls();
}
//---------------------------------------------------------------------------
void __fastcall TeditorDlg::SpinEdit2Change(TObject *Sender)
{
    if (SpinEdit2->Value > SpinEdit2->MaxValue)
        SpinEdit2->Value = SpinEdit2->MaxValue;
}
//---------------------------------------------------------------------------
void __fastcall TeditorDlg::SetupControls()
{
    // измерительный кадр
    if (ComboBox1->ItemIndex == 8)
    {
        SpinEdit1->Value = FRAME_CAPTURE_TIME;
        SpinEdit2->Value = 100;
        SpinEdit1->Enabled = false;
        SpinEdit2->Enabled = false;
    }
    // актиничный свет [0..10%] максимальной яркости
    else if (ComboBox1->ItemIndex == 7)
    {
        SpinEdit1->Enabled = true;
        SpinEdit2->Enabled = true;
        SpinEdit1->MinValue = COMMAND_MIN_TIME;
        SpinEdit1->MaxValue = COMMAND_MAX_TIME;
    }
    // кадр в актиничном свете
    else if (ComboBox1->ItemIndex == 6)
    {
        SpinEdit1->Value    = FRAME_CAPTURE_TIME;
        SpinEdit1->MinValue = FRAME_CAPTURE_TIME;
        SpinEdit1->MaxValue = COMMAND_MAX_TIME;
        SpinEdit1->Enabled = true;
        SpinEdit2->Enabled = true;
    }
    // Кадр в насыщающем свете
    else if (ComboBox1->ItemIndex == 5)
    {
         SpinEdit1->Value    = FRAME_CAPTURE_TIME;
        SpinEdit1->MinValue = FRAME_CAPTURE_TIME;
        SpinEdit1->MaxValue = COMMAND_MAX_TIME;
        SpinEdit1->Enabled = true;
        SpinEdit2->Enabled = true;
    }
    // выключить все источники
    else if (ComboBox1->ItemIndex == 4)
    {
        SpinEdit1->MinValue = COMMAND_MIN_TIME;
        SpinEdit1->MaxValue = COMMAND_MAX_TIME;
        SpinEdit1->Enabled = true;

        SpinEdit2->Value = 0;
        SpinEdit2->Enabled = false;
    }
    // темновой кадр
    else if (ComboBox1->ItemIndex == 3)
    {
        SpinEdit1->Value = FRAME_CAPTURE_TIME;
        SpinEdit1->MinValue = FRAME_CAPTURE_TIME;
        SpinEdit1->MaxValue = FRAME_CAPTURE_TIME;

        SpinEdit2->Value = 0;
        SpinEdit2->Enabled = false;
    }
    // кадр в дополнительном свете
    else if (ComboBox1->ItemIndex == 2)
    {
        SpinEdit1->Value = FRAME_CAPTURE_TIME;
        SpinEdit1->MinValue = FRAME_CAPTURE_TIME;
        SpinEdit1->MaxValue = COMMAND_MAX_TIME;

        SpinEdit1->Enabled = true;
        SpinEdit2->Enabled = true;
    }
    // Дополнительный свет
    else if (ComboBox1->ItemIndex == 1)
    {
        SpinEdit1->Enabled = true;
        SpinEdit2->Enabled = true;
        SpinEdit1->MinValue = COMMAND_MIN_TIME;
        SpinEdit1->MaxValue = COMMAND_MAX_TIME;
    }
    // насыщающий свет
    else
    {
        SpinEdit1->Enabled = true;
        SpinEdit2->Enabled = true;
        SpinEdit1->MinValue = COMMAND_MIN_TIME;
        SpinEdit1->MaxValue = COMMAND_MAX_TIME;
    }
    Label5->Caption = commands_descr[ComboBox1->ItemIndex];
}

void __fastcall TeditorDlg::FormShow(TObject *Sender)
{
    this->SetupControls();
}
//---------------------------------------------------------------------------

void __fastcall TeditorDlg::ShowSettingsLightExecute(TObject *Sender)
{
  FormLight->Show();
}
//---------------------------------------------------------------------------

