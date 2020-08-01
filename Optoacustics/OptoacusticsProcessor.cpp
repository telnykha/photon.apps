//---------------------------------------------------------------------------

#pragma hdrstop

#include "OptoacusticsProcessor.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

TOAProcessor::TOAProcessor()
{
	m_radius = 1.5;
	m_threshold = 0.5;
}

void TOAProcessor::SetImage(awpImage* image)
{
	m_source.SetImage(image);
	if (m_source.GetImage() == NULL)
	{
		m_result.FreeImages();
		return;
	}
	this->m_contours.Clear();
	awpConvert(m_source.GetImage(), AWP_CONVERT_3TO1_BYTE);
	awpImage* tmp = NULL;
	awpCreateImage(&tmp, m_source.GetImage()->sSizeX, m_source.GetImage()->sSizeY, 1,  AWP_BYTE);
	awpGaussianBlur(m_source.GetImage(), tmp, m_radius);
	double t = 255*this->m_threshold;
	awpMakeBinary(m_source.GetImage(),&tmp, t, AWP_BINARY, 0 , 255 , NULL);
	m_result.SetImage(tmp);
	if (m_needContours)
	{
		awpStrokeObj* s;
		int num = 0;
		awpGetStrokes(tmp, &num, &s, 128, NULL);
		for (int i = 0; i < num; i++)
		{
			awpContour* c = NULL;
			awpCreateContour(&c, s[i].Num*2, true);
			awpGetObjCountour(&s[i], c);
			TLF2DContour _c;

			for (int j = 0; j < c->NumPoints; j++)
			{
				awp2DPoint _p;
				_p.X = c->Points[j].X;
				_p.Y = c->Points[j].Y;
				_c.AddPoint(_p);
			}
			TLFZone*  z = new TLFZone(_c);
			m_contours.AddZone(z);
			awpFreeContour(&c);
		}
		awpFreeStrokes(num, &s);
	}
	awpReleaseImage(&tmp);

}

awpImage* TOAProcessor::GetImage()
{
	 m_result.GetImage();
}


double TOAProcessor::GetThreshold()
{
	return 255*this->m_threshold;
}
double TOAProcessor::GetRadius()
{
	return m_radius;
}

void TOAProcessor::SetThreshold(double value)
{
	if (value >= 0 && value <= 1)
	{
		m_threshold = value;
	}
}
void TOAProcessor::SetRadius(double value)
{
	if (value > 0 && value < 5) {
		m_radius = value;
	}
}

bool   TOAProcessor::GetNeedContours()
{
	return m_needContours;
}

void TOAProcessor::SetNeedContours(bool value)
{
   m_needContours = value;
}


