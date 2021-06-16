//---------------------------------------------------------------------------

#pragma hdrstop

#include "pam2ROIEditor.h"
#include "ImageUtils.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

__fastcall TPhPam2RoiTool::TPhPam2RoiTool(TComponent* Owner): TPhImageTool(Owner)
{
	m_down;
	m_si = 0; // selected index
	m_sv = 0; // selectes vertex
	m_selected = -1;
	m_newZone = NULL;
	m_mode = TMRect;
    m_OnAddRoi = NULL;
}

__fastcall TPhPam2RoiTool::~TPhPam2RoiTool()
{

}

double TPhPam2RoiTool::_2D_Dist(double x1,double y1,double x2,double y2)
{
	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}
TPoint TPhPam2RoiTool::GetRectPoint(int index, TRect& rect)
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
TRect __fastcall TPhPam2RoiTool::GetBoundsRect(TLFZone* zone)
{
	TLF2DRect* r = zone->GetBounds();
	awpRect _rect;
	_rect.left =   r->GetLeftTop().X*m_pImage->Bitmap->Width / 100.;
	_rect.top  =   r->GetLeftTop().Y*m_pImage->Bitmap->Height / 100.;
	_rect.right =  r->GetRightBottom().X*m_pImage->Bitmap->Width / 100.;
	_rect.bottom = r->GetRightBottom().Y*m_pImage->Bitmap->Height / 100.;
	TRect rect = awpRect2TRect(_rect);
	return rect;
}

//---------------------------------------------------------------------------
bool   TPhPam2RoiTool::_is_near_vertex(int X, int Y, int& idx1, int& idx2)
{
   bool res = false;

   if (m_pImage == NULL)
		return res;

   TPoint p = m_pImage->GetImagePoint(X, Y);

	for (int i = 0; i < m_rois.GetCount(); i++)
	{
		TPam2ROI* item = (TPam2ROI*)m_rois.Get(i);
		if (item != NULL)
		{
			TLFZone* z = item->zone;
			if (z != NULL)
			{
				 if (z->GetZoneType() == ZTRect && m_mode == TMRect)
				 {
					TRect rect = GetBoundsRect(z);
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
				 else if (z->GetZoneType() == ZTLineSegment && m_mode == TMCircle)
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
				// delete z;
			}
		}
	}
	return res;
}

void __fastcall TPhPam2RoiTool::SetVertex(int x, int y)
{
   TPam2ROI* item = (TPam2ROI*)m_rois.Get(m_si);
   TPoint p = m_pImage->GetImagePoint(x, y);
   if (item)
   {
	 TLFZone* z = new TLFZone(*item->zone);
	 if (z == NULL || (z->GetZoneType() == ZTRect && m_mode == TMRect))
	 {
		 TRect rect = this->GetBoundsRect(z); //awpRect2TRect(item->GetBounds()->GetRect());
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
		 TLF2DRect* _r = z->GetRect();
		 double x1,x2,y1, y2;
		 x1 = 100.*_rect.left / (double)m_pImage->Bitmap->Width;
		 x2 = 100.*_rect.right / (double)m_pImage->Bitmap->Width;
		 y1 = 100.*_rect.top / (double)m_pImage->Bitmap->Height;
		 y2 = 100.*_rect.bottom / (double)m_pImage->Bitmap->Height;
		 _r->SetVertexes(x1,x2,y1,y2);
	 }
	 else if (z->GetZoneType() == ZTLineSegment && m_mode == TMCircle)
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

	 }
	 item->SetZone(z);
	 if (this->m_OnChangeRoi) {
		 this->OnChangeRoi(this, m_si);
	 }
	 delete z;
   }
}



void TPhPam2RoiTool::Draw(TCanvas* Canvas)
{
	if (Canvas == NULL)
		return;

	TColor oldColor =  Canvas->Pen->Color;
	TBrushStyle oldStyle = Canvas->Brush->Style;

	int delta = 4;

	for (int i = 0; i < m_rois.GetCount(); i++)
	{
		Canvas->Brush->Style = bsSolid;
		//TLFDetectedItem* item = (TLFDetectedItem*)m_descriptor.Get(i);
		TPam2ROI* item = (TPam2ROI*)m_rois.Get(i);
		TColor color = clWhite;//GetItemColor(item);
		if (i == m_selected)
		{
			Canvas->Pen->Width = 1;
            Canvas->Pen->Color = clLime;
		}
		else
		{
			Canvas->Pen->Width = 1;
			Canvas->Pen->Color = color;
        }

		TEZoneTypes zt =  item->zone->GetZoneType();//GetItemZoneType(item);
		if (zt == ZTRect)
		{
			TRect rect = this->GetBoundsRect(item->zone);//awpRect2TRect(item->GetBounds()->GetRect());
			TRect rect1 = this->m_pImage->GetScreenRect(rect);
			Canvas->Brush->Color = color;

			TPoint p1 = rect1.TopLeft();
			TPoint p2 = rect1.BottomRight();

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
			awp2DPoint s = item->zone->GetLineSegmnet()->GetStart();
			awp2DPoint f = item->zone->GetLineSegmnet()->GetFinish();

			TPoint p1;
			TPoint p2;

			p1.x = s.X * m_pImage->Bitmap->Width / 100;
			p1.y = s.Y * m_pImage->Bitmap->Height / 100;

			p2.x = f.X * m_pImage->Bitmap->Width / 100;
			p2.y = f.Y * m_pImage->Bitmap->Height / 100;

			p1 = m_pImage->GetScreenPoint(p1.x, p1.y);
			p2 = m_pImage->GetScreenPoint(p2.x, p2.y);

			double r = sqrt(double(p1.x - p2.x)*(p1.x - p2.x) + (double)(p1.y - p2.y)*(p1.y-p2.y));
            Canvas->Brush->Style = bsClear;
			Canvas->Ellipse(p1.x-r, p1.y - r, p1.x + r, p1.y + r);

			Canvas->MoveTo(p1.x, p1.y);
			Canvas->LineTo(p2.x, p2.y);
			Canvas->Brush->Color = clRed;
			Canvas->Ellipse(p1.x-delta, p1.y - delta, p1.x + delta, p1.y + delta);
			Canvas->Brush->Color = clBlue;
			Canvas->Ellipse(p2.x-delta, p2.y - delta, p2.x + delta, p2.y + delta);

		}
	}

	if (m_newZone != NULL)
	{
		if (m_newZone->IsLineSegment())
		{
			Canvas->Pen->Color = clLime;
			Canvas->Brush->Style = bsClear;
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

			double r = sqrt(double(p1.x - p2.x)*(p1.x - p2.x) + (double)(p1.y - p2.y)*(p1.y-p2.y));
			Canvas->Ellipse(p1.x-r, p1.y - r, p1.x + r, p1.y + r);

			Canvas->Brush->Color = clLime;
			Canvas->MoveTo(p1.x, p1.y);
			Canvas->LineTo(p2.x, p2.y);
			Canvas->Brush->Color = clRed;
			Canvas->Ellipse(p1.x-delta, p1.y - delta, p1.x + delta, p1.y + delta);
			Canvas->Brush->Color = clBlue;
			Canvas->Ellipse(p2.x-delta, p2.y - delta, p2.x + delta, p2.y + delta);

		}
		else if (m_newZone->IsRect())
		{
			Canvas->Pen->Color = clLime;
			Canvas->Brush->Color = clLime;

			TRect rect2 = this->GetBoundsRect(m_newZone);
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
	}

}
void TPhPam2RoiTool::MouseDown(int X, int Y, TMouseButton Button)
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
		if (m_mode == TMRect)
		{
			// new rect
			m_newZone = new TLFZone(ZTRect);
			TPoint p = m_pImage->GetImagePoint(X, Y);
			double x1, x2, y1, y2;
			  x1 = 100.*p.x / (double)m_pImage->Bitmap->Width;
			  y1 = 100.*p.y /(double)m_pImage->Bitmap->Height;
			  x2 = 100.*p.x / (double)m_pImage->Bitmap->Width;
			  y2 = 100.*p.y /(double)m_pImage->Bitmap->Height;

              m_newZone->GetRect()->SetVertexes(x1, x2, y1, y2);

/*			m_newZone->GetRect()->GetLeftTop().X = 100.*p.x / (double)m_pImage->Bitmap->Width;
			m_newZone->GetRect()->GetLeftTop().Y = 100.*p.y / (double)m_pImage->Bitmap->Height;
			m_newZone->GetRect()->GetRightBottom().X = 100.*p.x / (double)m_pImage->Bitmap->Width;
			m_newZone->GetRect()->GetRightBottom().Y = 100.*p.y / (double)m_pImage->Bitmap->Height;*/
		}
		else if (m_mode == TMCircle)
		{
		  m_newZone = new TLFZone(ZTLineSegment);
		  TPoint p = m_pImage->GetImagePoint(X, Y);
		  awp2DPoint p2d;
		  p2d.X = 100.0*(double)p.x/(double)m_pImage->Bitmap->Width;
		  p2d.Y = 100.0*(double)p.y/(double)m_pImage->Bitmap->Height;

		  m_newZone->GetLineSegmnet()->SetStart(p2d);
		}

	  }
	 // m_edited = true;
	  m_down = true;
   }
}
void TPhPam2RoiTool::MouseUp(int X, int Y, TMouseButton Button)
{
   if (m_pImage == NULL)
		return;
   if (Button == mbLeft)
   {
	  if ( m_newZone != NULL)
	  {
		 if (m_mode == TMRect)
		 {
			 // process new rect
			  TPoint p = m_pImage->GetImagePoint(X, Y);
			  double x1, x2, y1, y2;
			  x1 = m_newZone->GetRect()->GetLeftTop().X;
			  y1 = m_newZone->GetRect()->GetLeftTop().Y;
			  x2 = 100.*p.x / (double)m_pImage->Bitmap->Width;
			  y2 = 100.*p.y /(double)m_pImage->Bitmap->Height;

			  m_newZone->GetRect()->SetVertexes(x1,x2,y1,y2);

		 }
		 else if (m_mode == TMCircle)
		 {

				TPoint p = m_pImage->GetImagePoint(X, Y);
				awp2DPoint p2d;
				p2d.X = 100.0*(double)p.x/m_pImage->Bitmap->Width;
				p2d.Y = 100.0*(double)p.y/m_pImage->Bitmap->Height;

				m_newZone->GetLineSegmnet()->SetFihish(p2d);
			   //	DoPopup(X, Y);
		 }

		 // добавляем новый элемент
		 TPam2ROI* roi = new TPam2ROI() ;
		 roi->SetZone(m_newZone);
		 this->m_rois.Add(roi);
		 if (m_OnAddRoi) {
            m_OnAddRoi(this, roi);
		 }
		 delete  m_newZone;
         m_newZone = NULL;

	  }
	  else
	  {
		// process vertex
		//m_descriptor.SaveXML(m_strName.c_str());
		//if (this->m_OnChange != NULL)
        //    m_OnChange(this);
	  }
	  m_pImage->Paint();
	  m_down = false;
   }
}
void TPhPam2RoiTool::MouseMove(int X, int Y, TShiftState Shift)
{
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
	   if (m_newZone != NULL)
	   {
			TPoint p = m_pImage->GetImagePoint(X, Y);
			if (m_mode == TMRect)
			{
			  TPoint p = m_pImage->GetImagePoint(X, Y);
			  double x1, x2, y1, y2;
			  x1 = m_newZone->GetRect()->GetLeftTop().X;
			  y1 = m_newZone->GetRect()->GetLeftTop().Y;
			  x2 = 100.*p.x / (double)m_pImage->Bitmap->Width;
			  y2 = 100.*p.y /(double)m_pImage->Bitmap->Height;

			  m_newZone->GetRect()->SetVertexes(x1,x2,y1,y2);
			}
			else if (m_mode == TMCircle)
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
}
void TPhPam2RoiTool::Reset()
{

}

int __fastcall TPhPam2RoiTool::GetRoiCount()
{
	return m_rois.GetCount();
}

TPam2ROI* __fastcall TPhPam2RoiTool::GetRoi(int index)
{
	if (index < 0 || index >= m_rois.GetCount()) {
		return NULL;
	}

	TPam2ROI* roi = (TPam2ROI*)m_rois.Get(index);
	return roi;

}

void __fastcall TPhPam2RoiTool::SetSelected(int value)
{
	m_selected = value;
	m_pImage->Paint();
}

void __fastcall TPhPam2RoiTool::Clear()
{
	 m_selected = -1;
	 m_rois.Clear();
     m_pImage->Paint();
}

void __fastcall TPhPam2RoiTool::DeleteRoi(int index)
{
	if (index <0 || index >= m_rois.GetCount()) {
		return;
	}
	m_rois.Delete(index);
    m_pImage->Paint();
}


