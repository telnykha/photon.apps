//---------------------------------------------------------------------------
#pragma hdrstop
#include "cammandsTable.h"
#include "tinyxml.h"
#include "dialogs.hpp"

#pragma link "TinyXML.lib"

//---------------------------------------------------------------------------
#pragma package(smart_init)

TCommandsTable::TCommandsTable(TStringGrid* grid)
{
    assert(grid != NULL);
    m_grid = grid;
    m_list = new TList();
	m_changed = false;
	m_exposure = 1000;
    m_fileName = c_FileName;
    m_grid->Cells[0][0] = L"Команда";
	m_grid->Cells[1][0] = L"Интенсивность (%)";
	m_grid->Cells[2][0] = L"Время (ms)";
	m_grid->Cells[3][0] = L"Комментарий";
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
	if (e->QueryIntAttribute("exposure", &m_exposure) == TIXML_NO_ATTRIBUTE )
        m_exposure = 1000;
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
		  m_grid->Cells[0][m_grid->RowCount-1] = GetCommandName(event->command);
		  m_grid->Cells[1][m_grid->RowCount-1] = IntToStr((int)event->pinStatus);//GetCommandIntensivity(event->pinStatus, event->command);
		  m_grid->Cells[2][m_grid->RowCount-1] = IntToStr((int)event->pinDelay);
		  m_grid->Cells[3][m_grid->RowCount-1] = e1->Attribute("comment");

		  m_list->Add(event);
	}
	m_changed = false;
	m_fileName = lpFileName;
}
void __fastcall TCommandsTable::SaveTable(const char* lpFileName)
{
    assert(m_grid != NULL);
    assert(m_list != NULL);

    TiXmlDocument doc;
	TiXmlDeclaration* decl = new TiXmlDeclaration( "1.0", "windows-1251", "" );
    doc.LinkEndChild( decl );

    TiXmlElement* e = new TiXmlElement("pam");
	e->SetAttribute("exposure", this->m_exposure);
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
        //m_grid->Cells[0][m_grid->RowCount-1] = IntToStr(m_grid->RowCount-1);
        m_grid->Cells[0][m_grid->RowCount-1] = GetCommandName(dlg->ComboBox1->ItemIndex);
		m_grid->Cells[1][m_grid->RowCount-1] = dlg->SpinEdit2->Value; //GetCommandIntensivity(dlg->ComboBox2->ItemIndex, dlg->ComboBox1->ItemIndex);
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
		m_grid->Cells[1][index] = dlg->SpinEdit2->Value;//GetCommandIntensivity(dlg->ComboBox2->ItemIndex, dlg->ComboBox1->ItemIndex);
		m_grid->Cells[2][index] = IntToStr(dlg->SpinEdit1->Value);
        m_grid->Cells[3][index] = dlg->Edit1->Text;

		expEvent* e = (expEvent*)m_list->Items[index-1];

        assert(e!=NULL);

        e->command = dlg->ComboBox1->ItemIndex;
		e->pinStatus =  dlg->SpinEdit2->Value;//dlg->ComboBox2->ItemIndex;
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
			return L"Дополнительный свет (460 nm)";
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
        default:
            return L"TURN_OFF";
    }
}

/*
Высокая
Средняя
Низкая
Недоступна
*/
UnicodeString TCommandsTable::GetCommandIntensivity(int index, int indexCommand)
{
    if (indexCommand == 4 || indexCommand == 3)
        return L"Недоступна";

    switch(index)
    {
        case 0:
            return L"Высокая";
        case 1:
            return L"Средняя";
        case 2:
            return L"Низкая";
        default:
            return L"неизвестная интенсивность";
    }
}

int TCommandsTable::GetCommandIntensivityValue(int index)
{
    switch(index)
    {
        case 0:
            return 90;
        case 1:
            return 40;
        case 2:
            return 10;
        default:
            return 0;
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
//#define TURNON460 1                   /*включить насыщающий свет*/
//#define TURNON660 2                   /*включить актиничный свет*/
//#define TURNON_CAM_660  3       /*включить актиничный свет и камеру*/
//#define TURNON_CAM 4                /*включить камеру без света*/
//#define TURN_OFF   5                    /*выключить все*/
//#define TURNON_CAM_460  6       /*включить актиничный свет и камеру*/


//const int progSize = 20;
///*
//    Описание эксперимента в формате
//     {КОМАНДА, ИНТЕНСИВНОСТЬ, ВРЕМЯ},
//
//       время задается в миллисекундах.
//*/
//expEvent Events[progSize] =
//{
//  {TURNON460, HIGH, 10},
//  {TURNON660, HIGH, 20},
//  {TURNON460, HIGH, 50},
//  {TURNON660, HIGH, 10},
//  {TURN_OFF,  HIGH, 100},
//  {TURNON460, HIGH, 100},
//  {TURNON660, HIGH, 200},
//  {TURNON460, HIGH, 500},
//  {TURNON660, HIGH, 100},
//  {TURN_OFF,  HIGH, 1000},
//  {TURNON460, HIGH, 10},
//  {TURNON660, HIGH, 20},
//  {TURNON460, HIGH, 50},
//  {TURNON660, HIGH, 10},
//  {TURN_OFF,  HIGH, 100},
//  {TURNON460, HIGH, 100},
//  {TURNON660, HIGH, 200},
//  {TURNON460, HIGH, 500},
//  {TURNON660, HIGH, 100},
//  {TURN_OFF,  HIGH, 100},
//
//};


UnicodeString __fastcall TCommandsTable::GetScript()
{
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
		str += IntToStr(e->pinStatus);//IntToStr(GetCommandIntensivityValue(e->pinStatus));//L"HIGH,";
		str += L",";
		str += IntToStr((int)e->pinDelay);
		str += L"},\r\n";
	}
	str += L"};";
	str += L"\r\n\const int exposure = ";
	str += IntToStr(m_exposure);
	str += L";";
	return str;
}
void __fastcall TCommandsTable::SetExposure(int value)
{
	m_exposure = value;
    m_changed = true;
}

