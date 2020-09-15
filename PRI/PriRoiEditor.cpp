//---------------------------------------------------------------------------

#pragma hdrstop

#include "PriRoiEditor.h"
//---------------------------------------------------------------------------

TPriRoiItem::TPriRoiItem()
{
	m_x = 0;
	m_y = 0;
	m_r = 0;
	m_checked = false;
}
TPriRoiItem::TPriRoiItem(double x, double y, double r)
{
	m_x = x;
	m_y = y;
	m_r = r;
	m_checked = false;
}
TPriRoiItem::TPriRoiItem(TPriRoiItem& item)
{
	m_x = item.m_x;
	m_y = item.m_y;
	m_r = item.m_r;
	m_checked = item.m_checked;
}

TPriRoiItem::~TPriRoiItem()
{

}
const char* TPriRoiItem::GetName()
{
	return "TPriRoiItem";
}

double TPriRoiItem::GetX()
{
	return m_x;
}
double TPriRoiItem::GetY()
{
	return m_y;
}
double TPriRoiItem::GetR()
{
	return m_r;
}

void TPriRoiItem::SetX(double value)
{
	m_x = value;
}
void TPriRoiItem::SetY(double value)
{
	m_y = value;
}
void TPriRoiItem::SetR(double value)
{
	m_r = value;
}

bool TPriRoiItem::LoadXML(TiXmlElement* parent)
{
	if (parent == NULL)
		return false;
	const char* name = parent->Value();
	if (strcmp(name, this->GetName()) != 0)
		return false;
	double x,y,r;

	parent->QueryDoubleAttribute("x", &x);
	parent->QueryDoubleAttribute("y", &y);
	parent->QueryDoubleAttribute("r", &r);

	m_x = x;
	m_y = y;
	m_r = r;
	return true;
}
bool TPriRoiItem::SaveXML(TiXmlElement* parent)
{
	if (parent == NULL)
		return false;
	TiXmlElement* f = new TiXmlElement(this->GetName());
	f->SetDoubleAttribute("x", m_x);
	f->SetDoubleAttribute("y", m_y);
	f->SetDoubleAttribute("r", m_r);
	parent->LinkEndChild(f);
	return true;
}


void TPriRoiItem::SetChecked(bool value)
{
	m_checked = value;
}
bool TPriRoiItem::GetChecked()
{
	return m_checked;
}

void TPriRoiItem::Draw(TPhImage* image)
{
	// здесь пускай рисуется.
}


//---------------------------------------------------------------------------
__fastcall TPhPriRoiEditor::TPhPriRoiEditor(TComponent* Owner): TPhImageTool(Owner)
{
   m_down = false;
   m_newItem = NULL;
   m_selectedIndex = -1;
   m_OnAddRoi = NULL;
}

__fastcall TPhPriRoiEditor::~TPhPriRoiEditor()
{
   if (m_newItem != NULL)
	 delete m_newItem;
}
TRect TPhPriRoiEditor::GetRoiRect(TPriRoiItem* ri)
{
	TRect result;
	TPoint center = m_pImage->GetScreenPoint(ri->GetX(), ri->GetY());
	TPoint edge = m_pImage->GetScreenPoint(ri->GetX()+ri->GetR(), ri->GetY());
	int w = fabs((float)edge.x - (float)center.x);
	result.Left = center.x - w;
	result.Right = center.x + w;
	result.top = center.y - w;
	result.bottom = center.y + w;
	return result;
}
void TPhPriRoiEditor::Draw(TCanvas* Canvas)
{
	if (Canvas == NULL)
		return;
	// draw rois
	Canvas->Pen->Color = clLime;
	Canvas->Pen->Width = 2;
	Canvas->Brush->Style = bsClear;
	for (int i = 0; i < m_rois.GetCount(); i++)
	{
	   TPriRoiItem* ri = (TPriRoiItem*)m_rois.Get(i);
	   TRect rect =  GetRoiRect(ri);
	   Canvas->Ellipse(rect);
	}
	// draw edited
	Canvas->Pen->Color = clYellow;
	if (m_newItem != NULL)
	{
	   TRect rect =  GetRoiRect(m_newItem);
	   Canvas->Ellipse(rect);
	}
	// draw selected
	Canvas->Pen->Color = clRed;
	if (m_selectedIndex >= 0 && m_selectedIndex < m_rois.GetCount())
	{
	   TPriRoiItem* ri = (TPriRoiItem*)m_rois.Get(m_selectedIndex);
	   TRect rect =  GetRoiRect(ri);
	   Canvas->Ellipse(rect);
	}
}

void __fastcall TPhPriRoiEditor::SetSelected(int value)
{
	if (value >= 0 && value < m_rois.GetCount())
	{
		m_selectedIndex = value;
		m_pImage->Paint();
	}
}


void TPhPriRoiEditor::MouseDown(int X, int Y, TMouseButton Button)
{
	m_down = true;
	int x = m_pImage->GetImageX(X);
	int y = m_pImage->GetImageY(Y);
	m_newItem = new TPriRoiItem(x,y,1);
}
void TPhPriRoiEditor::MouseUp(int X, int Y, TMouseButton Button)
{
   if (m_down)
   {
		m_down = false;
		TPriRoiItem* item = new TPriRoiItem(*m_newItem);
		m_rois.Add(item);
		m_pImage->Paint();
		if (m_OnAddRoi)
		{
			m_OnAddRoi(this, m_newItem);
		}
		delete m_newItem;
		m_newItem = NULL;
        m_pImage->Paint();
   }
}
void TPhPriRoiEditor::MouseMove(int X, int Y, TShiftState Shift)
{
  if (m_down)
  {
	int x = m_pImage->GetImageX(X);
	int y = m_pImage->GetImageY(Y);
	double xx = m_newItem->GetX();
	double yy = m_newItem->GetY();
	double r = sqrt((x-xx)*(x-xx)+(y-yy)*(y - yy));
	m_newItem->SetR(r);
	m_pImage->Paint();
  }
}
void TPhPriRoiEditor::Reset()
{
	if (m_newItem != NULL)
		 delete m_newItem;
	m_rois.Clear();
	m_selectedIndex =-1;
	this->m_pImage->Paint();
}

bool TPhPriRoiEditor::Load(UnicodeString path)
{
   UnicodeString FileName = path;
   FileName += L"\\rois.xml";
   if (!FileExists(FileName))
	return false;
   AnsiString _ansi = FileName;
	TiXmlDocument doc(_ansi.c_str());
	if (!doc.LoadFile())
		return false;
	TiXmlHandle hDoc(&doc);
	TiXmlElement* pElem = NULL;
	TiXmlHandle hRoot(0);
	pElem = hDoc.FirstChildElement().Element();
	return LoadXML(pElem);
}
bool TPhPriRoiEditor::Save(UnicodeString path)
{
   UnicodeString FileName = path;
   FileName += L"\\rois.xml";
   AnsiString _ansi = FileName;
	TiXmlDocument doc;
	TiXmlDeclaration* decl = new TiXmlDeclaration("1.0", "", "");
	doc.LinkEndChild(decl);
	TiXmlElement* PriRois = new TiXmlElement("TPhPriRoiEditor");
	if (PriRois == NULL)
		return false;
	if (!this->SaveXML(PriRois))
	{
		delete PriRois;
		return false;
	}
	doc.LinkEndChild(PriRois);
	return doc.SaveFile(_ansi.c_str());
}

void TPhPriRoiEditor::Delete(int index)
{
	if (index < 0 || index >= m_rois.GetCount())
	{
		return;
	}

	m_selectedIndex = -1;
	m_rois.Delete(index);
	m_pImage->Paint();
}

void TPhPriRoiEditor::ClearAll()
{
	m_rois.Clear();
	m_pImage->Paint();
}


bool __fastcall TPhPriRoiEditor::LoadXML(TiXmlElement* parent)
{
	if (parent == NULL)
		return false;
	const char* name = parent->Value();
	if (strcmp(name, "TPhPriRoiEditor") != 0)
		return false;
	Reset();
	for (TiXmlNode* child = parent->FirstChild(); child; child = child->NextSibling())
	{
		TPriRoiItem* item = new TPriRoiItem();
		if (item == NULL)
			return false;
		if (!item->LoadXML(child->ToElement()))
		{
			Reset();
			delete item;
			return false;
		}
		m_rois.Add(item);
	}
	return true;
}

bool __fastcall TPhPriRoiEditor::SaveXML(TiXmlElement* parent)
{
	if (parent == NULL)
		return false;

	int c = m_rois.GetCount();
	for (int i = 0; i < c; i++)
	{
	   TPriRoiItem* ri = (TPriRoiItem*)m_rois.Get(i);
	   ri->SaveXML(parent);
	}

	return true;
}

int TPhPriRoiEditor::GetItemsCount()
{
	return m_rois.GetCount();
}
TPriRoiItem* TPhPriRoiEditor::GetItem(int index)
{
	if (index < 0 || index >= m_rois.GetCount()) {
		return NULL;
	}

	return (TPriRoiItem*)m_rois.Get(index);
}

void __fastcall TPhPriRoiEditor::EditSelected(double x, double y, double r)
{
  TPriRoiItem* item = GetItem(m_selectedIndex);
  if (item != NULL)
  {
	item->SetX(x);
	item->SetY(y);
	item->SetR(r);
	m_pImage->Paint();
  }
}

void TPhPriRoiEditor::SetChecked(int index, bool value)
{
	//
	TPriRoiItem* ri = (TPriRoiItem*)m_rois.Get(index);
	if (ri != NULL)
	{
		ri->SetChecked(value);
	}

}





#pragma package(smart_init)
