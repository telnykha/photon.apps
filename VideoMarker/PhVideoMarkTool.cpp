//---------------------------------------------------------------------------
#pragma hdrstop
#include "Dialogs.hpp"
#include "ImageUtils.h"
#include "PhVideoMarkTool.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "tinyxml.lib"
#define _IM_MIN_WIDTH_ 12
#define _IM_MIN_HEIGHT_ 12
//---------------------------------------------------------------------------
TFrameItem::~TFrameItem()
{
}
//---------------------------------------------------------------------------
TLFSemanticImageDescriptor* TFrameItem::GetDescriptor(int w, int h)
{
	TLFSemanticImageDescriptor* sdscr = new TLFSemanticImageDescriptor(w,h);
	for (int j = 0; j < GetCount(); j++)
	{
		TLFDetectedItem* mi = (TLFDetectedItem*)Get(j);

		TLFDetectedItem* di = new TLFDetectedItem(mi);
		sdscr->AddDetectedItem(di);
	}
	return sdscr;
}
//---------------------------------------------------------------------------
TiXmlElement* TFrameItem::SaveXML(int w, int h)
{
		TiXmlElement* element= new TiXmlElement("TFrameItem");
		element->SetDoubleAttribute("frame", (double)m_frame);
		TLFSemanticImageDescriptor* sdscr = GetDescriptor(w,h);
		TiXmlElement* ee = sdscr->SaveXML();
		element->LinkEndChild(ee);
		delete sdscr;
		return element;
}
//---------------------------------------------------------------------------
bool TFrameItem::LoadXML(TiXmlElement* parent)
{
	this->Clear();
	if (parent == NULL)
		return false;
	if (strcmp(parent->Value(), "TFrameItem") != 0)
		return false;

	double value;
	parent->QueryDoubleAttribute("frame", &value);
	this->m_frame = (int)value;
	TiXmlElement* e = parent->FirstChildElement();
	if (e != NULL)
	{
		TLFSemanticImageDescriptor d;
		if (d.LoadXML(e))
		{
		   for (int i = 0; i < d.GetCount(); i++)
		   {
				TLFDetectedItem* di = new TLFDetectedItem(d.GetDetectedItem(i));
				this->Add(di);
		   }
		}
	}

	return true;
}

//---------------------------------------------------------------------------
__fastcall TPhVideoMarkTool::TPhVideoMarkTool(TComponent* Owner): TPhImageTool(Owner)
{
	//m_classes = new TList();
	m_down = false;
	m_newRect = NULL;
	m_OnChange = NULL;
	m_OnAddData = NULL;
    m_OnDelFrame = NULL;
	m_OnLoad = NULL;
    m_OnProgress = NULL;
	m_edited = false;
    PopupMenu = NULL;
    m_selected = -1;
	m_dictinary = new TLFSemanticDictinary();
	m_mode = MTRect;
	m_X = 0;
	m_Y = 0;
	m_rdown = false;
	m_startPoint = NULL;
}
//---------------------------------------------------------------------------
__fastcall TPhVideoMarkTool::~TPhVideoMarkTool()
{
    SaveData();
    delete m_dictinary;

	if (m_newRect != NULL)
		delete m_newRect;
}
//---------------------------------------------------------------------------
double TPhVideoMarkTool::_2D_Dist(double x1,double y1,double x2,double y2)
{
	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}
//---------------------------------------------------------------------------
bool   TPhVideoMarkTool::_is_near_vertex(int X, int Y, int& idx1, int& idx2)
{
   bool res = false;

   if (m_pImage == NULL)
		return res;

   TPoint p = m_pImage->GetImagePoint(X, Y);

	for (int i = 0; i < m_data.GetCount(); i++)
	{
		TLFDetectedItem* item = (TLFDetectedItem*)m_data.Get(i);
		if (item != NULL)
		{
			TLFZone* z = item->GetZone();
			if (z != NULL)
			{
				 if (z->GetZoneType() == ZTRect && m_mode == MTRect)
				 {
					TRect rect = awpRect2TRect(item->GetBounds()->GetRect());
					for (int j = 0; j < 4; j++)
					{
						TPoint vertex = GetRectPoint(j, rect);
						if  (_2D_Dist(vertex.x, vertex.y, p.x, p.y) < 4)//
						{
						   res = true;
						   idx1 = i;
						   idx2 = j;
						   break;
						}
					}
				 }
				 else if (z->GetZoneType() == ZTLineSegment && m_mode == MTVector)
				 {
					 awp2DPoint p1;
					 awp2DPoint p2;
					 p1 = z->GetLineSegmnet()->GetStart();
					 p2 = z->GetLineSegmnet()->GetFinish();

					 TPoint _p1;
					 TPoint _p2;

					 _p1.x = p1.X*m_pImage->Bitmap->Width / 100.;
					 _p1.y = p1.Y*m_pImage->Bitmap->Height / 100.;

					 _p2.x = p2.X*m_pImage->Bitmap->Width / 100.;
					 _p2.y = p2.Y*m_pImage->Bitmap->Height / 100.;

						if  (_2D_Dist(_p1.x, _p1.y, p.x, p.y) < 4)//
						{
						   res = true;
						   idx1 = i;
						   idx2 = 0;
						   break;
						}

						if  (_2D_Dist(_p2.x, _p2.y, p.x, p.y) < 4)//
						{
						   res = true;
						   idx1 = i;
						   idx2 = 1;
						   break;
						}

					 res = false;
				 }
				 else if (z->GetZoneType() == ZTContour && m_mode == MTContour)
				 {
					TLF2DContour* contour = z->GetContour();
					for (int j = 0; j < contour->GetNumPoints(); j++)
					{
						TPoint vertex;// = GetRectPoint(j, rect);
						awp2DPoint _p = contour->GetPoint(j);
						vertex.x = _p.X*m_pImage->Bitmap->Width / 100.;
						vertex.y = _p.Y*m_pImage->Bitmap->Height / 100.;
						if  (_2D_Dist(vertex.x, vertex.y, p.x, p.y) < 4)//
						{
						   res = true;
						   idx1 = i;
						   idx2 = j;
						   break;
						}
					}
				 }
				 delete z;
			}
			else
			{
				TRect rect = awpRect2TRect(item->GetBounds()->GetRect());
				for (int j = 0; j < 4; j++)
				{
					TPoint vertex = GetRectPoint(j, rect);
					if  (_2D_Dist(vertex.x, vertex.y, p.x, p.y) < 4)//
					{
					   res = true;
					   idx1 = i;
					   idx2 = j;
					   break;
					}
				}
			}
		}
	}
	return res;
}
//---------------------------------------------------------------------------
TPoint TPhVideoMarkTool::GetRectPoint(int index, TRect& rect)
{
	TPoint result;
	if (index == 0)
	{
		result = rect.TopLeft();
	}
	else if (index == 1)
	{
		result.x = rect.BottomRight().X;
		result.y = rect.TopLeft().Y;
	}
	else if (index == 2)
	{
		result = rect.BottomRight();
	}
	else
	{
		result.x = rect.TopLeft().X;
		result.y = rect.BottomRight().Y;
	}
	return result;
}

bool TPhVideoMarkTool::CheckZoneType(TLFSemanticDictinaryItem* sdi)
{
	if (m_mode == MTRect && sdi->GetZoneType() == ZTRect)
		return true;
	if (m_mode == MTVector && sdi->GetZoneType() == ZTLineSegment)
		return true;
	if (m_mode == MTContour && sdi->GetZoneType() == ZTContour)
		return true;

	return false;
}
//---------------------------------------------------------------------------
void __fastcall TPhVideoMarkTool::SetVertex(int x, int y)
{
   TLFDetectedItem* item = (TLFDetectedItem*)m_data.Get(m_si);
   TPoint p = m_pImage->GetImagePoint(x, y);
   if (item)
   {
	 TLFZone* z = item->GetZone();
	 if (z == NULL || (z->GetZoneType() == ZTRect && m_mode == MTRect))
	 {
		 TRect rect = awpRect2TRect(item->GetBounds()->GetRect());
		 if (m_sv == 0)
		 {
			rect.Left = p.x;
			rect.Top  = p.y;
		 }
		 else if (m_sv == 1)
		 {
			rect.right = p.x;
			rect.Top  = p.y;
		 }
		 else if (m_sv == 2)
		 {
			rect.right = p.x;
			rect.bottom  = p.y;
		 }
		 else if (m_sv == 3)
		 {
			rect.left = p.x;
			rect.bottom  = p.y;
		 }
		 awpRect _rect = TRect2awpRect(rect);
		 item->SetBounds(_rect, m_pImage->Bitmap->Width, m_pImage->Bitmap->Height);
	 }
	 else if (z->GetZoneType() == ZTLineSegment && m_mode == MTVector)
	 {
		   awp2DPoint p1;
		   p1.X = 100.0*p.x /(double) m_pImage->Bitmap->Width;
		   p1.Y = 100.0*p.y /(double) m_pImage->Bitmap->Height;
			if (m_sv == 0)
			{
				z->GetLineSegmnet()->SetStart(p1);
			}
			else if (m_sv == 1)
			{
				z->GetLineSegmnet()->SetFihish(p1);
			}
			item->SetZone(z, m_pImage->Bitmap->Width, m_pImage->Bitmap->Height);
	 }
	 else if (z->GetZoneType() == ZTContour && m_mode == MTContour)
	 {
		   awp2DPoint p1;
		   p1.X = 100.0*p.x /(double) m_pImage->Bitmap->Width;
		   p1.Y = 100.0*p.y /(double) m_pImage->Bitmap->Height;
		   z->GetContour()->SetPoint(m_sv, p1);
		   item->SetZone(z, m_pImage->Bitmap->Width, m_pImage->Bitmap->Height);
	 }
	 delete z;
   }

}

TColor TPhVideoMarkTool::GetItemColor(TLFDetectedItem* itm)
{
	if (itm == NULL)
		return clBlack;
	for (int i = 0; i < this->m_dictinary->GetCount(); i++)
	{
		TLFSemanticDictinaryItem* ci = (TLFSemanticDictinaryItem*)this->m_dictinary->Get(i);

		if (strcmp(itm->GetType().c_str(), ci->GetId().c_str()) == 0)
		{
			int color = ci->GetColor();
			return color;
		}
	}
	return clBlack;
}

TEZoneTypes TPhVideoMarkTool::GetItemZoneType(TLFDetectedItem* itm)
{
	if (itm == NULL)
		return ZTRect;
	for (int i = 0; i < this->m_dictinary->GetCount(); i++)
	{
		TLFSemanticDictinaryItem* ci = (TLFSemanticDictinaryItem*)this->m_dictinary->Get(i);

		if (strcmp(itm->GetType().c_str(), ci->GetId().c_str()) == 0)
		{
			TLFZone* z = itm->GetZone();
			if (z != NULL)
			{
				TEZoneTypes zt = z->GetZoneType();
				delete z;
				return zt;
			}
		}
	}
	return ZTRect;
}

//---------------------------------------------------------------------------
void TPhVideoMarkTool::Draw(TCanvas* Canvas)
{
	if (Canvas == NULL)
		return;

	TColor oldColor =  Canvas->Pen->Color;
	TBrushStyle oldStyle = Canvas->Brush->Style;

	int delta = 5;

	for (int i = 0; i < this->m_data.GetCount(); i++)
	{
		Canvas->Brush->Style = bsSolid;

		TLFDetectedItem* item = m_data.GetDetectedItem(i);
		awpRect r = item->GetBounds()->GetRect();
		TRect rect;
		rect.Left = r.left;
		rect.top = r.top;
		rect.right = r.right;
		rect.bottom = r.bottom;

		TColor _color = GetItemColor(item);
		TRect rect1 = this->m_pImage->GetScreenRect(rect);
		Canvas->Brush->Color = _color;
        if (i == m_selected)
			Canvas->Pen->Width = 4;
		else
			Canvas->Pen->Width = 1;
		Canvas->Pen->Color = _color;



		TEZoneTypes zt =  GetItemZoneType(item);
		if (zt == ZTRect)
		{
			TRect rect = awpRect2TRect(item->GetBounds()->GetRect());
			TRect rect1 = this->m_pImage->GetScreenRect(rect);
			Canvas->Brush->Color = _color;

			TPoint p1 = rect1.TopLeft();
			TPoint p2 = rect1.BottomRight();
			AnsiString _tmp;
			std::string str = m_dictinary->GetWordByUUID(item->GetType().c_str());
			str += " :";
			_tmp = IntToStr(rect.Width());
			str += _tmp.c_str();
			str += ":";
			_tmp = IntToStr(rect.Height());
			str += _tmp.c_str();
			Canvas->TextOutW(p1.x + delta/2, p1.y - 4*delta, str.c_str());


			Canvas->Ellipse(p1.x-delta, p1.y - delta, p1.x + delta, p1.y + delta);
			Canvas->Ellipse(p2.x-delta, p2.y - delta, p2.x + delta, p2.y + delta);


			p1.x = p2.x;
			Canvas->Ellipse(p1.x-delta, p1.y - delta, p1.x + delta, p1.y + delta);
			p1 = rect1.TopLeft();
			p1.y = p2.y;
			Canvas->Ellipse(p1.x-delta, p1.y - delta, p1.x + delta, p1.y + delta);


			Canvas->Brush->Style = bsClear;
			Canvas->Rectangle(rect1);
		}
		else if (zt == ZTLineSegment)
		{
			awp2DPoint s = item->GetZone()->GetLineSegmnet()->GetStart();
			awp2DPoint f = item->GetZone()->GetLineSegmnet()->GetFinish();

			TPoint p1;
			TPoint p2;

			p1.x = s.X * m_pImage->Bitmap->Width / 100;
			p1.y = s.Y * m_pImage->Bitmap->Height / 100;

			p2.x = f.X * m_pImage->Bitmap->Width / 100;
			p2.y = f.Y * m_pImage->Bitmap->Height / 100;

			p1 = m_pImage->GetScreenPoint(p1.x, p1.y);
			p2 = m_pImage->GetScreenPoint(p2.x, p2.y);


			Canvas->MoveTo(p1.x, p1.y);
			Canvas->LineTo(p2.x, p2.y);
			Canvas->Brush->Color = clRed;
			Canvas->Ellipse(p1.x-delta, p1.y - delta, p1.x + delta, p1.y + delta);
			Canvas->Brush->Color = clBlue;
			Canvas->Ellipse(p2.x-delta, p2.y - delta, p2.x + delta, p2.y + delta);


			AnsiString _tmp;
			std::string str = m_dictinary->GetWordByUUID(item->GetType().c_str());
			Canvas->TextOutW(p2.x + delta/2, p2.y - 4*delta, str.c_str());

		}
		else if (zt == ZTContour)
		{
			AnsiString _tmp;
			std::string str = m_dictinary->GetWordByUUID(item->GetType().c_str());

			DrawContour(item->GetZone(), Canvas, _color, Canvas->Pen->Width, str.c_str());
		}
	}

	if (m_newRect != NULL)
	{
		Canvas->Pen->Color = clLime;
		Canvas->Brush->Color = clLime;

		TRect rect2 = *m_newRect;
		TRect rect3 = this->m_pImage->GetScreenRect(rect2);


		TPoint p1 = rect3.TopLeft();
		TPoint p2 = rect3.BottomRight();

		Canvas->Ellipse(p1.x-delta, p1.y - delta, p1.x + delta, p1.y + delta);
		Canvas->Ellipse(p2.x-delta, p2.y - delta, p2.x + delta, p2.y + delta);


		p1.x = p2.x;
		Canvas->Ellipse(p1.x-delta, p1.y - delta, p1.x + delta, p1.y + delta);
		p1 = rect3.TopLeft();
		p1.y = p2.y;
		Canvas->Ellipse(p1.x-delta, p1.y - delta, p1.x + delta, p1.y + delta);

		Canvas->Brush->Style = bsClear;
		Canvas->Rectangle(rect3);

		Canvas->Pen->Color = oldColor;
		Canvas->Brush->Color = oldColor;
		Canvas->Brush->Style = oldStyle;
	}

	if (m_newZone != NULL)
	{
		Canvas->Pen->Color = clLime;
		Canvas->Brush->Color = clLime;
		if (m_newZone->IsLineSegment())
		{
			awp2DPoint s = m_newZone->GetLineSegmnet()->GetStart();
			awp2DPoint f = m_newZone->GetLineSegmnet()->GetFinish();

			TPoint p1;
			TPoint p2;

			p1.x = s.X * m_pImage->Bitmap->Width / 100;
			p1.y = s.Y * m_pImage->Bitmap->Height / 100;

			p2.x = f.X * m_pImage->Bitmap->Width / 100;
			p2.y = f.Y * m_pImage->Bitmap->Height / 100;

			p1 = m_pImage->GetScreenPoint(p1.x, p1.y);
			p2 = m_pImage->GetScreenPoint(p2.x, p2.y);


			Canvas->MoveTo(p1.x, p1.y);
			Canvas->LineTo(p2.x, p2.y);
			Canvas->Brush->Color = clRed;
			Canvas->Ellipse(p1.x-delta, p1.y - delta, p1.x + delta, p1.y + delta);
			Canvas->Brush->Color = clBlue;
			Canvas->Ellipse(p2.x-delta, p2.y - delta, p2.x + delta, p2.y + delta);

		}
		else
		   DrawContour(m_newZone, Canvas, Canvas->Pen->Color, Canvas->Pen->Width);
	}

}

void __fastcall TPhVideoMarkTool::DrawContour(TLFZone* z, TCanvas* Canvas, TColor cc, int width,const char* text)
{
	 if (z == NULL || Canvas == NULL || m_pImage == NULL || m_pImage->Bitmap->Empty)
		return;
	 TLF2DContour* c = z->GetContour();
	 if (c == NULL || c->GetNumPoints() == 0)
		return;

	 int w, h;
	 w = m_pImage->Bitmap->Width;
	 h = m_pImage->Bitmap->Height;

	 Canvas->Pen->Color = cc;
	 Canvas->Brush->Style = bsClear;
	 Canvas->Pen->Width = width;

	 int X1, Y1;
	 int m_radius = 4;
	 TPoint p1;
	 X1 = w*c->GetPoint(0).X / 100;
	 Y1 = h*c->GetPoint(0).Y / 100;
	 p1 = m_pImage->GetScreenPoint(X1, Y1);

	 Canvas->MoveTo(p1.X, p1.Y);

	 Canvas->Pen->Width = width;

	 Canvas->Brush->Style = bsSolid;
	 Canvas->Brush->Color = cc;
	 Canvas->Ellipse(p1.X - m_radius, p1.Y - m_radius, p1.X + m_radius, p1.Y + m_radius);

	 Canvas->Brush->Style = bsClear;
	 Canvas->Pen->Width = width;
	 int delta = 10;


	 for (int i = 1; i < c->GetNumPoints(); i++)
	 {
		 TPoint p1;
		 X1 = w*c->GetPoint(i).X / 100;
		 Y1 = h*c->GetPoint(i).Y / 100;
		 p1 = m_pImage->GetScreenPoint(X1, Y1);
		 Canvas->LineTo(p1.X, p1.Y);

		 Canvas->Brush->Style = bsSolid;
		 Canvas->Brush->Color = cc;
		 Canvas->Ellipse(p1.X - m_radius, p1.Y - m_radius, p1.X + m_radius, p1.Y + m_radius);

		 Canvas->Brush->Style = bsClear;
		 Canvas->Pen->Width = width;

	 }
	 X1 = w*c->GetPoint(0).X / 100;
	 Y1 = h*c->GetPoint(0).Y / 100;
	 p1 = m_pImage->GetScreenPoint(X1, Y1);

	 Canvas->LineTo(p1.X, p1.Y);

	 if (text != NULL)
	 {
		Canvas->Brush->Color = cc;
			Canvas->TextOutW(p1.x + delta/2, p1.y - 4*delta, text);
	 }
}

//---------------------------------------------------------------------------
void TPhVideoMarkTool::MouseDown(int X, int Y, TMouseButton Button)
{
   if (m_pImage == NULL)
		return;
   if (Button == mbLeft)
   {
	  int idx1, idx2;
	  if (_is_near_vertex(X, Y, idx1, idx2))
	  {
		  m_si = idx1;
		  m_sv = idx2;
	  }
	  else
	  {
		if (m_mode == MTRect)
		{
			// new rect
			m_newRect = new TRect();
			TPoint p = m_pImage->GetImagePoint(X, Y);
			m_newRect->Left = p.x;
			m_newRect->top  = p.y;
		}
		else if (m_mode == MTVector)
		{
		  m_newZone = new TLFZone(ZTLineSegment);
		  TPoint p = m_pImage->GetImagePoint(X, Y);
		  awp2DPoint p2d;
		  p2d.X = 100.0*(double)p.x/(double)m_pImage->Bitmap->Width;
		  p2d.Y = 100.0*(double)p.y/(double)m_pImage->Bitmap->Height;

		  m_newZone->GetLineSegmnet()->SetStart(p2d);
		}
		else if (m_mode == MTContour)
		{
		  if (m_newZone == NULL)
			  m_newZone = new TLFZone(ZTContour);

		}

	  }
	  m_edited = true;
	  m_down = true;
   }
   else
   {
		m_rdown = true;
		m_X      = X;
		m_Y      = Y;
   }
}
//---------------------------------------------------------------------------
void TPhVideoMarkTool::MouseUp(int X, int Y, TMouseButton Button)
{
   if (m_pImage == NULL)
		return;

  if (Button == mbLeft)
   {
	  if (m_newRect != NULL || m_newZone != NULL)
	  {
		 if (m_mode == MTRect)
		 {
			 // process new rect
			  TPoint p = m_pImage->GetImagePoint(X, Y);
			  m_newRect->right = p.x;
			  m_newRect->bottom = p.y;

			  if (m_newRect->Width() > _IM_MIN_WIDTH_ && m_newRect->Height() > _IM_MIN_HEIGHT_)
				  DoPopup(X, Y);
			  else
			  {
				 delete m_newRect;
				 m_newRect = NULL;
				 m_pImage->Paint();
			  }
		 }
		 else if (m_mode == MTVector)
		 {

				TPoint p = m_pImage->GetImagePoint(X, Y);
				awp2DPoint p2d;
				p2d.X = 100.0*(double)p.x/m_pImage->Bitmap->Width;
				p2d.Y = 100.0*(double)p.y/m_pImage->Bitmap->Height;

				m_newZone->GetLineSegmnet()->SetFihish(p2d);
				DoPopup(X, Y);
		 }
		 else if (m_mode == MTContour)
		 {
			 ContourMouseUp(X, Y, Button);
		 }

	  }
	  else
	  {
		// process vertex
		//m_descriptor.SaveXML(m_strName.c_str());
		if (this->m_OnChange != NULL)
			m_OnChange(this);
	  }
	  m_pImage->Paint();
	  m_down = false;
   }
   else
   {
		if (m_mode == MTContour &&  m_newZone != NULL)
		{
		   ContourMouseUp(X, Y, Button);
		}
		m_X = 0;
		m_Y = 0;
		m_rdown = false;
   }
}
//---------------------------------------------------------------------------
void TPhVideoMarkTool::MouseMove(int X, int Y, TShiftState Shift)
{
   if (m_pImage == NULL)
		return;
   if (m_pImage == NULL)
		return;
	m_pImage->Cursor = crArrow;
	int idx1, idx2;
	if (_is_near_vertex(X, Y, idx1, idx2))
		m_pImage->Cursor = crHandPoint;
	else
		m_pImage->Cursor = crArrow;

   if (m_down)
   {
	   if (m_newRect != NULL || m_newZone != NULL)
	   {
			TPoint p = m_pImage->GetImagePoint(X, Y);
			if (m_mode == MTRect)
			{
				m_newRect->right = p.x;
				m_newRect->bottom = p.y;
			}
			else if (m_mode == MTVector)
			{
				awp2DPoint p2d;
				p2d.X = 100.0*(double)p.x/(double)m_pImage->Bitmap->Width;
				p2d.Y = 100.0*(double)p.y/(double)m_pImage->Bitmap->Height;

				m_newZone->GetLineSegmnet()->SetFihish(p2d);
			}
	   }
	   else
	   {
			// process vertex
			this->SetVertex(X,Y);
	   }
	   m_pImage->Paint();
   }

   if (m_rdown)
   {
	  m_pImage->MoveBy( m_X-X, m_Y-Y );

	  m_X = X;
  	  m_Y = Y;
   }
}
//---------------------------------------------------------------------------
void TPhVideoMarkTool::Reset()
{
   if (m_pImage == NULL)
		return;
	m_data.Clear();
	m_pImage->Paint();

	TFrameItem* item = this->GetFrameItem(m_mediaSource->CurrentFrame);
    if (item != NULL)
       this->DeleteEntry(m_mediaSource->CurrentFrame);

	if (this->m_OnChange != NULL)
		m_OnChange(this);
}
//---------------------------------------------------------------------------
__fastcall TPhVideoMarkTool::SetMediaSource(TPhMediaSource* source)
{
	SaveData();
	this->m_mediaSource = source;
	LoadData();
}
//---------------------------------------------------------------------------
void __fastcall TPhVideoMarkTool::SaveData()
{
	if (this->m_mediaSource == NULL)
		return;

	TiXmlDocument doc;
	TiXmlDeclaration* decl = new TiXmlDeclaration("1.0", "", "");
	doc.LinkEndChild(decl);
	TiXmlElement* dscr = new TiXmlElement("TPhVideoMarkTool");

	TiXmlElement* e = m_dictinary->SaveXML();
	dscr->LinkEndChild(e);
	int iw = this->m_pImage->Bitmap->Width;
	int ih = this->m_pImage->Bitmap->Height;
	for (int i = 0; i < m_frames.GetCount(); i++)
	{
		TFrameItem* fitem = (TFrameItem*)m_frames.Get(i);
		TiXmlElement* ee = fitem->SaveXML(iw, ih);
		dscr->LinkEndChild(ee);
	}

	doc.LinkEndChild(dscr);

	String strName = ChangeFileExt(this->m_mediaSource->Source, L".mark");
	AnsiString _ansi = strName;
	doc.SaveFile(_ansi.c_str());
}
//---------------------------------------------------------------------------
void __fastcall TPhVideoMarkTool::LoadData()
{
	if (this->m_mediaSource == NULL)
		return;
	String strName = ChangeFileExt(this->m_mediaSource->Source, L".mark");
	AnsiString _ansi = strName;

   TiXmlDocument doc;
   if (!doc.LoadFile(_ansi.c_str()))
	return;
   TiXmlHandle hDoc(&doc);
   TiXmlElement* pElem = NULL;

   pElem = hDoc.FirstChildElement().Element();
   if (pElem == NULL)
	return;

   if (strcmp(pElem->Value(), "TPhVideoMarkTool") != 0)
	return;

	pElem = pElem->FirstChildElement();
	if (pElem != NULL)
	{
		m_dictinary = new TLFSemanticDictinary();
		if (!m_dictinary->LoadXML(pElem))
			return;
		this->m_frames.Clear();
		while (pElem = pElem->NextSiblingElement())
		{
			TFrameItem* fi = new TFrameItem();
			if (fi->LoadXML(pElem))
				m_frames.Add(fi);
		}
	}
	if (m_OnLoad != NULL)
		m_OnLoad(this);
}
//---------------------------------------------------------------------------
void __fastcall  TPhVideoMarkTool::NewFrame(bool keepData)
{

	if (m_mediaSource == NULL || m_mediaSource->CurrentFrame == 0)
		return;
    this->m_selected = -1;
	if (m_edited || keepData)
	{
		// save data to prev. frame
		int idx = -1;
		for(int i = 0; i < m_frames.GetCount(); i++)
		{
			TFrameItem* frame = (TFrameItem*)m_frames.Get(i);
			if (frame->FrameNum == m_mediaSource->CurrentFrame-1)
			{
				idx = i;
			}
		}

		if (idx < 0)
		{
			// add data
			if (m_data.GetCount() > 0)
				{
					TFrameItem* frame = new TFrameItem();
					frame->FrameNum =  m_mediaSource->CurrentFrame - 1;
					for (int i = 0; i < m_data.GetCount(); i++)
					{
						TLFDetectedItem* item = m_data.GetDetectedItem(i);
						if (item)
						{
							TLFDetectedItem* out = new TLFDetectedItem(item);
							frame->Add(out);
						}
					}
					m_frames.Add(frame);
					if (m_OnAddData != NULL)
						m_OnAddData(this, frame);
				}
		}
		else
		{
			// change data
			TFrameItem* frame = (TFrameItem*)m_frames.Get(idx);
			frame->Clear();
			frame->FrameNum =  m_mediaSource->CurrentFrame - 1;

			for (int i = 0; i < m_data.GetCount(); i++)
			{
				TLFDetectedItem* item = (TLFDetectedItem*)m_data.Get(i);
				if (item)
				{
					TLFDetectedItem* out = new TLFDetectedItem(item);
					frame->Add(out);
				}
			}

		}
		this->m_edited = false;
	}


	// find data for this frame
	int idx = -1;
	for(int i = 0; i < m_frames.GetCount(); i++)
	{
		TFrameItem* frame = (TFrameItem*)m_frames.Get(i);
		if (frame->FrameNum == m_mediaSource->CurrentFrame)
		{
			// copy items
			idx = i;
			m_data.Clear();
			for (int j = 0; j < frame->GetCount(); j++)
			{
			   TLFDetectedItem* item = (TLFDetectedItem*)frame->Get(j);
			   TLFDetectedItem* out = new TLFDetectedItem(item);
			   m_data.Add(out);
			}
			break;
		}
	}

	if (idx < 0 && !keepData)
		Reset();

}
//---------------------------------------------------------------------------
TLFObjectList* __fastcall TPhVideoMarkTool::GetData()
{
	return &this->m_data;
}
//---------------------------------------------------------------------------
TLFObjectList* __fastcall TPhVideoMarkTool::GetFrames()
{
	return &this->m_frames;

}
//---------------------------------------------------------------------------
void __fastcall  TPhVideoMarkTool::SetFrame(int index)
{

	TFrameItem* itm = (TFrameItem*)m_frames.Get(index);
	if (itm != NULL)
		m_mediaSource->CurrentFrame = itm->FrameNum;
}
//---------------------------------------------------------------------------
void __fastcall  TPhVideoMarkTool::DeleteEntry(int index)
{
	for (int i = m_frames.GetCount() - 1; i >= 0; i--)
	{
		TFrameItem* itm = (TFrameItem*)m_frames.Get(i);
		if (itm && itm->FrameNum == index)
		{
            if (this->OnDelFrame)
                this->OnDelFrame(this, itm);
            m_frames.Delete(i);
        }
	}
    this->SaveData();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall  TPhVideoMarkTool::ExportToLFDatabase(const char* path)
{
	 TPhAddDataEvent ee = this->m_OnAddData;
     randomize();
	 m_OnAddData = NULL;
	 if (!LFDirExist(path))
		LFFileExists(path);

	 // Save dictionary

	 if (m_dictinary != NULL)
	 {
		string fname = path;
		fname += "\\dictinary.xml";
		m_dictinary->SaveXML(fname.c_str());
	 }

	 int rnd = rand();

	 for (int i= 0; i < m_frames.GetCount(); i++)
	 {
		TFrameItem* fi = (TFrameItem*)m_frames.Get(i);
		TLFSemanticImageDescriptor* sd = fi->GetDescriptor(m_pImage->Bitmap->Width,
		m_pImage->Bitmap->Height);
		if (sd != NULL)
		{
			// save data
			this->m_mediaSource->CurrentFrame = fi->FrameNum;
			UnicodeString str = path;
            str += "\\";
            str += IntToStr(rnd);
			str += L"_frame_";
			str += IntToStr(fi->FrameNum);
			str += ".png";
			m_pImage->SaveToFile(str.c_str());
			str = ChangeFileExt(str, L".xml");
			AnsiString _ansi = str;
            int progress = 100*i / m_frames.GetCount();
			sd->SaveXML(_ansi.c_str());
            if (m_OnProgress != NULL)
                m_OnProgress(this, progress, str);
			delete sd;
		}
		Application->ProcessMessages();
	 }
	 m_OnAddData = ee;
}

void __fastcall TPhVideoMarkTool::DoPopup(int X, int Y)
{
    PopupMenu = new TPopupMenu(NULL);
    PopupMenu->AutoPopup = false;
	for (int i = 0; i < m_dictinary->GetCount(); i++)
    {
		TLFSemanticDictinaryItem* mi = (TLFSemanticDictinaryItem*)m_dictinary->Get(i);
		if (!CheckZoneType(mi))
			continue;
		TMenuItem* item = new TMenuItem(PopupMenu);
		item->Caption = mi->GetItemLabel();
		item->OnClick = PopupClick;
        item->Tag = i+1;
		PopupMenu->Items->Add(item);
	}

    TMenuItem* item = new TMenuItem(PopupMenu);
    item->Caption = L"Отменить";
    item->OnClick = PopupClick;
    item->Tag = 0;
    PopupMenu->Items->Add(item);


    TPoint p = Application->MainForm->ClientOrigin;

    PopupMenu->Popup(p.X + X, p.Y + Y);
}

void __fastcall TPhVideoMarkTool::PopupClick(TObject* sender)
{
    TMenuItem* item = (TMenuItem*)sender;
    if (item->Tag - 1 < 0)
    {
		if (m_newRect != NULL)
		{
			delete m_newRect;
			m_newRect = NULL;
		}
		if (m_newZone != NULL)
		{
			delete m_newZone;
			m_newZone = NULL;
		}
		m_pImage->Paint();
		delete  PopupMenu;
		return;
    }


	TLFDetectedItem* di = new TLFDetectedItem();
	TLFSemanticDictinaryItem* dict_item = m_dictinary->GetWordFromDictinary(item->Tag - 1);
	if (m_mode == MTRect)
	{
		awpRect bounds = TRect2awpRect(*m_newRect);
		di->SetBounds(bounds, m_pImage->Bitmap->Width, m_pImage->Bitmap->Height);
		delete m_newRect;
		m_newRect = NULL;
	}
	else if (m_mode == MTVector)
	{
		di->SetZone(m_newZone, m_pImage->Bitmap->Width, m_pImage->Bitmap->Height);
		delete m_newZone;
		m_newZone = NULL;
	}
	else if (m_mode == MTContour)
	{
 		di->SetZone(m_newZone, m_pImage->Bitmap->Width, m_pImage->Bitmap->Height);
		delete m_newZone;
		m_newZone = NULL;
	}


	di->SetDetectorName("Human marked");
	di->SetType(dict_item->GetId().c_str());
	ILFScanner* s = dict_item->GetScanner();
	di->m_bh = s->GetBaseHeight();
	di->m_bw = s->GetBaseWidth();

	m_data.Add(di);


	if (this->m_OnChange != NULL)
		m_OnChange(this);

    m_pImage->Paint();
    delete  PopupMenu;
}


void __fastcall  TPhVideoMarkTool::SetSelected(int index)
{
   m_selected = index;
   m_pImage->Paint();
}

void __fastcall  TPhVideoMarkTool::DeleteObject(int index)
{
    if (index >= 0 && index < m_data.GetCount())
    {
		m_data.Delete(index);
        TFrameItem* itm = GetFrameItem(m_mediaSource->CurrentFrame);
        if (itm != NULL)
        {
            itm->Delete(index);
            if (itm->GetCount() == 0)
            {
				DeleteEntry(m_mediaSource->CurrentFrame);
            }
        }
        m_pImage->Paint();
        SaveData();
    }
}

int frames_compare(void* item1, void* item2)
{
    TFrameItem* a1 = (TFrameItem*)item1;
	TFrameItem* a2 = (TFrameItem*)item2;

    if (a1->FrameNum == a2->FrameNum)
		return 0;
    if (a1->FrameNum > a2->FrameNum)
        return 1;
    else
		return -1;
}
void __fastcall TPhVideoMarkTool::SortData()
{
    m_frames.Sort(frames_compare);
}

TFrameItem* TPhVideoMarkTool::GetFrameItem(int index)
{
	for (int i = m_frames.GetCount()-1; i>=0; i--)
    {
		TFrameItem* itm = (TFrameItem*)m_frames.Get(i);
        if (itm->FrameNum == index)
        {
			return itm;
        }
	}
   return NULL;
}
/*
    создает словарь по умолчанию. В случае, если

*/
void __fastcall TPhVideoMarkTool::CreateDefaultDictinary()
{
	if (this->m_dictinary != NULL)
	{
		delete m_dictinary;
		m_dictinary = NULL;
	}

}

void __fastcall TPhVideoMarkTool::ChangeLabel(String& src_label, String& dst_label)
{
	UnicodeString src = src_label;
	UnicodeString dst = dst_label;

/*
	for (int i = 0; i < m_dictinaty->GetCount(); i++)
	{
		//TMarkItem* ci = (TMarkItem*)this->m_classes->Items[i];
		TLFSemanticDictinaryItem* word = GetWordFromDictinary(i);

		if (ci->label == src)
			ci->label = dst;
	}

	for (int i = 0; i < m_frames.GetCount(); i++)
	{
		TFrameItem* fitem = (TFrameItem*)m_frames.Get(i);
		for (int j = 0; j < fitem->GetCount(); j++)
		{
			TMarkItem* item = (TMarkItem*)fitem->Get(j);
			if (item->label == src)
				item->label = dst;
		}
	}*/
	SaveData();
}

void __fastcall TPhVideoMarkTool::DeleteLabel(String label)
{
	AnsiString _ansi = label;
	std::string uuid = m_dictinary->GetUUIDByWord(_ansi.c_str());

	for (int i = m_frames.GetCount() - 1; i >=0 ; i--)
	{
		TFrameItem* fitem = (TFrameItem*)m_frames.Get(i);
		TLFSemanticImageDescriptor* sd = fitem->GetDescriptor(m_pImage->Bitmap->Width,
		m_pImage->Bitmap->Height);

		for (int j = sd->GetCount() -1; j >=0; j--)
		{
			TLFDetectedItem* di = sd->GetDetectedItem(j);
			if (uuid == di->GetType())
				 sd->Delete(j);
		}
		if(sd->GetCount() == 0)
			m_frames.Delete(i);
	}

    m_dictinary->DelWordForomDictinary(_ansi.c_str());

	SaveData();
	if (m_OnLoad != NULL)
		m_OnLoad(this);
}

void __fastcall TPhVideoMarkTool::LabelStatistics(String label, int& numFrames, int& numEntries)
{
	numFrames = 0;
	numEntries = 0;
	AnsiString _ansi = label;
	std::string uuid = m_dictinary->GetUUIDByWord(_ansi.c_str());
	for (int i = m_frames.GetCount() - 1; i >=0 ; i--)
	{
		TFrameItem* fitem = (TFrameItem*)m_frames.Get(i);
		bool f = false;
		TLFSemanticImageDescriptor* sd = fitem->GetDescriptor(m_pImage->Bitmap->Width,
		m_pImage->Bitmap->Height);

		for (int j = sd->GetCount() -1; j >=0; j--)
		{
			TLFDetectedItem* di = sd->GetDetectedItem(j);
			if (uuid == di->GetType())
			{
				numEntries++;
				f = true;
			}
		}
		if (f)
			numFrames++;
	}
}

void __fastcall TPhVideoMarkTool::Commit()
{

   delete m_startPoint;
   m_startPoint = NULL;
}

void __fastcall TPhVideoMarkTool::Rollback()
{
   delete m_startPoint;
   m_startPoint = NULL;
}

void __fastcall TPhVideoMarkTool::ContourMouseUp(int x, int y, TMouseButton Button)
{
	if (m_pImage->Bitmap->Empty)
		return;

	int w, h , _x, _y;

	w = m_pImage->Bitmap->Width;
	h = m_pImage->Bitmap->Height;
	_x = m_pImage->GetImageX(x);
	_y = m_pImage->GetImageY(y);

	if (_x < 0 || _y < 0)
		return;


	awp2DPoint p;
	p.X = 100.*(double)_x/(double)w;
	p.Y = 100.*(double)_y/(double)h;
	TLF2DContour* c = m_newZone->GetContour();

	if (m_startPoint == NULL)
	{
		m_startPoint = new TLF2DPoint(p);
		c->AddPoint(p);
	}
	else
	{
		c->AddPoint(p);
	}

	if (Button == mbRight)
	{
		DoPopup(x,y);
		Commit();
		return;
	}
	m_pImage->Paint();
}


