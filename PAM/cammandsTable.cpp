//---------------------------------------------------------------------------
#pragma hdrstop
#include "cammandsTable.h"
#include "tinyxml.h"
#include "dialogs.hpp"

#pragma link "TinyXML.lib"

//---------------------------------------------------------------------------
#pragma package(smart_init)

TCommandsTable::TCommandsTable(TStringGrid* grid, TPAMOptions* pOptions)
{
    assert(grid != NULL);
    assert(pOptions != NULL);
    m_options = pOptions;
    m_grid = grid;
    m_list = new TList();
	m_changed = false;
    m_fileName = c_FileName;
    m_grid->Cells[0][0] = L"Команда";
	m_grid->Cells[1][0] = L"Интенсивность (%)";
	m_grid->Cells[2][0] = L"Длительность (ms)";
	m_grid->Cells[3][0] = L"Комментарий";
	m_grid->Cells[4][0] = L"Время";
	m_grid->Cells[5][0] = L"Файл";

}
//
void __fastcall TCommandsTable::NewTable()
{
   assert(m_grid != NULL);
   m_grid->FixedRows = 0;
   m_grid->RowCount = 1;
   m_list->Clear();
   m_changed = false;
   m_fileName = c_FileName;
}
void __fastcall TCommandsTable::LoadTable(const char* lpFileName)
{
	NewTable();

	TiXmlDocument doc;
	if (!doc.LoadFile(lpFileName))
		return;
	TiXmlElement* e = doc.FirstChildElement();
	const char* name = e->Value();
	if (strcmp(name, "pam") != 0)
		return;

    int exposure;
    int exp_index;
    int exp_value;
    int delay;
    int lenght;
    int gain;

	if (e->QueryIntAttribute("exposure", &exposure) == TIXML_NO_ATTRIBUTE )
        exposure = 1000;
	if (e->QueryIntAttribute("exp_index", &exp_index) == TIXML_NO_ATTRIBUTE )
        exp_index = 0;
	if (e->QueryIntAttribute("exp_value", &exp_value) == TIXML_NO_ATTRIBUTE )
        exp_value = 10;
	if (e->QueryIntAttribute("gain", &gain) == TIXML_NO_ATTRIBUTE )
        gain = 10;
 	if (e->QueryIntAttribute("delay", &delay) == TIXML_NO_ATTRIBUTE )
        delay = 10;
	if (e->QueryIntAttribute("lenght", &lenght) == TIXML_NO_ATTRIBUTE )
        lenght = 10;


	for(TiXmlNode* child = e->FirstChild(); child; child = child->NextSibling() )
	{
		 TiXmlElement* e1 = child->ToElement();
		 const int row_count = m_grid->RowCount;

		  // (1) append a new row to the end
		  m_grid->RowCount = row_count + 1;
		  if (m_grid->RowCount == 2)
			  m_grid->FixedRows  = 1;

		  expEvent* event = new expEvent();
		  e1->Attribute("command", &event->command);
		  e1->Attribute("status", &event->pinStatus);
		  if (e1->Attribute("image") != NULL)
			  event->imageName = e1->Attribute("image");
		  else
			  event->imageName = "";

		  int v;
		  e1->Attribute("delay", &v);
		  event->pinDelay = v;
          if (e1->QueryIntAttribute("time", &v) != TIXML_SUCCESS)
            event->eventTime = 0;
          else
            event->eventTime = v;
		  m_grid->Cells[0][m_grid->RowCount-1] = GetCommandName(event->command);
		  m_grid->Cells[1][m_grid->RowCount-1] = IntToStr((int)event->pinStatus);//GetCommandIntensivity(event->pinStatus, event->command);
		  m_grid->Cells[2][m_grid->RowCount-1] = IntToStr((int)event->pinDelay);
		  m_grid->Cells[3][m_grid->RowCount-1] = e1->Attribute("comment");
		  m_grid->Cells[4][m_grid->RowCount-1] = IntToStr((int)event->eventTime);
		  m_grid->Cells[5][m_grid->RowCount-1] = event->imageName;

		  m_list->Add(event);
	}
	m_changed = false;
    // устанавливаем параметры m_options
    m_options->exploshureIndex = exp_index;
    m_options->exploshureValue = exp_value;
    m_options->Gain = gain;
    m_options->Delay = delay;
    m_options->Length = lenght;
    m_options->UpdateUI();
	m_fileName = lpFileName;
}
void __fastcall TCommandsTable::SaveTable(const char* lpFileName)
{
    assert(m_grid != NULL);
    assert(m_list != NULL);
    assert(m_options != NULL);

    TiXmlDocument doc;
	TiXmlDeclaration* decl = new TiXmlDeclaration( "1.0", "windows-1251", "" );
    doc.LinkEndChild( decl );

    TiXmlElement* e = new TiXmlElement("pam");
	e->SetAttribute("exposure", m_options->Exposure);
	e->SetAttribute("exp_index", m_options->exploshureIndex);
	e->SetAttribute("exp_value", m_options->exploshureValue);
	e->SetAttribute("gain", m_options->Gain);
    e->SetAttribute("delay", m_options->Delay);
    e->SetAttribute("lenght", m_options->Length);

    for (int i = 0; i < m_list->Count; i++)
    {
        expEvent* event = (expEvent*)m_list->Items[i];
	    TiXmlElement* e1 = new TiXmlElement("pam_entry");
        e1->SetAttribute("command", event->command);
        e1->SetAttribute("status", event->pinStatus);
        e1->SetAttribute("delay", event->pinDelay);
        AnsiString str = m_grid->Cells[4][i+1];
        e1->SetAttribute("comment", str.c_str());
        e1->SetAttribute("image", event->imageName.c_str());
        e1->SetAttribute("time", event->eventTime);
        e->LinkEndChild(e1);
    }

    doc.LinkEndChild(e);
    if (!doc.SaveFile(lpFileName))
    {
        ShowMessage("Ошибка: не могу сохранить файл описания эксперимента.");
        return;
    }
	m_changed = false;
}
//
void __fastcall TCommandsTable::AddRecord(TeditorDlg* dlg)
{
    assert(m_grid != NULL);
    assert(dlg != NULL);
    SNDMSG(m_grid->Handle, WM_SETREDRAW, false, 0);
    int AfterIndex = m_grid->RowCount;
     try
      {
        const int row_count = m_grid->RowCount;

        // (1) append a new row to the end
        m_grid->RowCount = row_count + 1;
        if (m_grid->RowCount == 2)
            m_grid->FixedRows  = 1;
        m_grid->Cells[0][m_grid->RowCount-1] = GetCommandName(dlg->ComboBox1->ItemIndex);
		m_grid->Cells[1][m_grid->RowCount-1] = dlg->SpinEdit2->Value;
        m_grid->Cells[2][m_grid->RowCount-1] = IntToStr(dlg->SpinEdit1->Value);
        m_grid->Cells[3][m_grid->RowCount-1] = dlg->Edit1->Text;
        // (2) insert contents of the trailing rows
        expEvent* e = new(expEvent);
        e->command    = dlg->ComboBox1->ItemIndex;
		e->pinStatus  = dlg->SpinEdit2->Value;
        e->pinDelay   = dlg->SpinEdit1->Value;
        m_list->Add(e);
      }
      __finally
      {
        SNDMSG(m_grid->Handle, WM_SETREDRAW, true, 0);
      }
      RECT R = m_grid->CellRect(0, AfterIndex);
      InflateRect(&R, m_grid->Width, m_grid->Height);
      InvalidateRect(m_grid->Handle, &R, false);
      m_changed = true;
}
void __fastcall TCommandsTable::DeleteRecord(int index)
{
      assert(m_grid != NULL);

      SNDMSG(m_grid->Handle, WM_SETREDRAW, false, 0);
      try
      {
        const int row_count = m_grid->RowCount;

        // (1) shift the contents of the trailing columns
        for (int row = index; row < row_count - 1; ++row)
        {
          m_grid->Rows[row] = m_grid->Rows[row + 1];
        }

        // (2) remove the last column
        m_grid->RowCount = row_count -1;
      }
      __finally
      {
        SNDMSG(m_grid->Handle, WM_SETREDRAW, true, 0);
      }

      // update (repaint) the shifted cols
      RECT R = m_grid->CellRect(0, index);
      InflateRect(&R, m_grid->Width, m_grid->Height);
      InvalidateRect(m_grid->Handle, &R, false);
      m_list->Delete(index-1);
      m_changed = true;
}

void __fastcall TCommandsTable::EditRecord(int index, TeditorDlg* dlg)
{
        m_grid->Cells[0][index] = GetCommandName(dlg->ComboBox1->ItemIndex);
		m_grid->Cells[1][index] = dlg->SpinEdit2->Value;
		m_grid->Cells[2][index] = IntToStr(dlg->SpinEdit1->Value);
        m_grid->Cells[3][index] = dlg->Edit1->Text;

		expEvent* e = (expEvent*)m_list->Items[index-1];

        assert(e!=NULL);

        e->command = dlg->ComboBox1->ItemIndex;
		e->pinStatus =  dlg->SpinEdit2->Value;
        e->pinDelay  = dlg->SpinEdit1->Value;

        m_changed = true;
}

/*
Включить прожектор 460 nm
Включить прожектор 660 nm
Включить прожектор 660 nm и фото
Получить изображение
Выключить все
*/
UnicodeString TCommandsTable::GetCommandName(int index)
{
    switch(index)
    {
        case 0:
			return L"Насыщающий свет (460 nm)";
		case 1:
			return L"Дополнительный свет (660 nm)";
		case 2:
			return L"Кадр в дополнительном свете (660 nm";
		case 3:
			return L"Темновой кадр";
        case 4:
            return L"Выключить все";
		case 5:
			return L"Измерительный кадр в насыщающем свете";
		case 6:
			return L"Измерительный кадр в актиничном свете";
		case 7:
			return L"Актиничный свет (460 nm)";
        case 8:
            return L"Измерительный кадр";
        default:
            return L"неизвестная команда";
    }
}

UnicodeString TCommandsTable::GetScriptCommandName(int index)
{
    switch(index)
    {
        case 0:
            return L"TURNON460";
        case 1:
            return L"TURNON660";
        case 2:
            return L"TURNON_CAM_660";
        case 3:
            return L"TURNON_CAM";
        case 4:
            return L"TURN_OFF";
        case 5:
			return L"TURNON_CAM_460";
		case 6:
			return L"TURNON_CAM_460_ACT";
		case 7:
			return L"TURNON460_ACT";
        case 8:
            return L"TURNON_CAM_FLASH";
        default:
            return L"TURN_OFF";
    }
}

void __fastcall TCommandsTable::Save()
{
    AnsiString str = this->m_fileName;
    SaveTable(str.c_str());
}

/***********************************************
  Команды, доступные пользователю.
**************************************************/
UnicodeString __fastcall TCommandsTable::GetScript()
{
    assert(m_options != NULL);

	UnicodeString str =
	L"\
	#define TURNON460 1                 \r\n\
	#define TURNON660 2                 \r\n\
	#define TURNON_CAM_660  3       	\r\n\
	#define TURNON_CAM 4                \r\n\
	#define TURN_OFF   5                \r\n\
	#define TURNON_CAM_460   6          \r\n\
	#define TURNON_CAM_460_ACT   7          \r\n\
	#define TURNON460_ACT   8          \r\n\
	#define TURNON_CAM_FLASH   9          \r\n\
	const int progSize =";
	str += IntToStr(m_list->Count);
	str += L";\r\n\
	expEvent Events[progSize] = {\r\n";
	for (int i = 0; i < m_list->Count; i++)
	{
		expEvent* e = (expEvent*)m_list->Items[i];

		str += L"{";
		str += this->GetScriptCommandName(e->command);
		str += L",";
		str += IntToStr(e->pinStatus);
		str += L",";
		str += IntToStr((int)e->pinDelay);
		str += L"},\r\n";
	}
	str += L"};";
	str += L"\r\n\const int exposure = ";
	str += IntToStr(m_options->Exposure);
	str += L";";
	str += L"\r\n\const int flash_delay = ";
	str += IntToStr(m_options->Exposure*m_options->Delay/100);
	str += L";";
	str += L"\r\n\const int  flash_lenght = ";
	str += IntToStr(m_options->Exposure*m_options->Length/100);
	str += L";";
	return str;
}



