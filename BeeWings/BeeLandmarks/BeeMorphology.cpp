//---------------------------------------------------------------------------

#pragma hdrstop
#include "BeeMorphology.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

const awp2DPoint gpoints[8] =
{
{26.630311, 29.036995},
{79.292189,27.278273},
{49.054636,33.093616},
{35.557874,35.099718},
{50,50},
{57.519525,55.686925},
{61.804425,54.376162},
{50,75}
};

static void ConvertCoordinats(awp2DPoint p4, awp2DPoint p7, awp2DPoint* out)
{
	double L0  = sqrt((p4.X - p7.X)*(p4.X - p7.X) + (p4.Y - p7.Y)*(p4.Y - p7.Y));
	double L1  = sqrt((gpoints[4].X - gpoints[7].X)*(gpoints[4].X - gpoints[7].X) + (gpoints[4].Y - gpoints[7].Y)*(gpoints[4].Y - gpoints[7].Y));
	double alfa = L0 / L1;
	double tanfi = (p7.X - p4.X) / (p7.Y - p4.Y);
	double fi = atan(tanfi);

	double sinfi = sin(fi);
	double cosfi = cos(fi);

	awpImage* mtx = NULL;
	awpImage* imtx = NULL;
	awpCreateImage(&mtx, 2,2,1,AWP_DOUBLE);
	awpCreateImage(&imtx, 2,2,1,AWP_DOUBLE);
	double* pmtx = (double*)mtx->pPixels;

	pmtx[0] = cosfi;
	pmtx[1] = -sinfi;
	pmtx[2] = sinfi;
	pmtx[3] = cosfi;

	awpMatrixInvert(mtx, imtx);
	double* pimtx = (double*)imtx->pPixels;
	for (int i = 0; i < 8; i++) {
		awpImage* dst = NULL;
		awpImage* src = NULL;
		awpCreateImage(&src, 1,2,1,AWP_DOUBLE);
		double* psrc = (double*)src->pPixels;
		psrc[0] = gpoints[i].X - gpoints[4].X;
		psrc[1] = gpoints[i].Y - gpoints[4].Y;
		awpMulMatrix(imtx, src, &dst);
		double* pdst = (double*)dst->pPixels;
		out[i].X = pdst[0];
		out[i].Y = pdst[1];
		awp2DPoint p;

		out[i].X = alfa*out[i].X;
		out[i].Y = alfa*out[i].Y;
		out[i].X += p4.X;
		out[i].Y += p4.Y;
	}

	awpReleaseImage(&mtx);
	awpReleaseImage(&imtx);
}

TBeeMorphology::TBeeMorphology()
{
	m_points = NULL;
	m_width = 960;
	m_height = 540;
}

TBeeMorphology::~TBeeMorphology()
{
	if (m_points != NULL)
		delete m_points;
}

bool TBeeMorphology::Init(const char* lpConfigFile)
{
	TiXmlDocument doc;
	if (!doc.LoadFile(lpConfigFile))
		return false;

	TiXmlElement* e = doc.FirstChildElement("TBeeMorphology");
	if (e == NULL)
		return false;
	if (e->QueryIntAttribute("width", &m_width) !=   TIXML_SUCCESS)
		return false;
	if (e->QueryIntAttribute("height", &m_height) !=   TIXML_SUCCESS)
		return false;
	int count = 0;
	if (e->QueryIntAttribute("count", &count) !=   TIXML_SUCCESS)
		return false;

	TLFString strPath =   LFGetFilePath(lpConfigFile);
    strPath += "\\";
	m_detectors.Clear();
	for(TiXmlNode* child = e->FirstChild("BeePointDector"); child; child = child->NextSibling() )
	{

		TiXmlElement* detector = child->ToElement();
		TLFString className = detector->Attribute("class");
		TLFString detectorName = strPath + detector->Attribute("detector");
		TLFString templateName = strPath + detector->Attribute("template");

		TBeePointDector* bpd = new TBeePointDector(className.c_str());
		if (!bpd->Init(detectorName.c_str(), templateName.c_str()))
		{
			m_detectors.Clear();
			return false;
		}

		m_detectors.Add(bpd);
	}


	return m_detectors.GetCount() == count;
}

bool TBeeMorphology::ProcessImage(const char* lpFileName, awp2DPoint* points,  bool* status)
{
	TLFImage img;
	if (!img.LoadFromFile(lpFileName))
		return false;
	return ProcessImage(&img, points, status);
}
bool TBeeMorphology::ProcessImage(TLFImage* image, awp2DPoint* points, bool* status)
{
	for (int i = 0; i < 8; i++)
	{
		points[i] = gpoints[i];
		status[i] = false;
	}

	if (image == NULL)
		return false;

	// преобразование исходного изображения
	awpImage* img = image->GetImage();
	if (awpResizeBilinear(img, 960, 540) != AWP_OK)
		return false;
	if (awpConvert(img, AWP_CONVERT_3TO1_BYTE) != AWP_OK)
		return false;

	TBeePointDector* wing5 = GetDetector("wing5");
	TBeePointDector* wing8 = GetDetector("wing8");

	if (wing5 == NULL || wing8 == NULL)
		return false;

	int w = image->GetImage()->sSizeX;
	int h = image->GetImage()->sSizeY;


	// поиск точки №5 и №8
	awp2DPoint p5;
	awp2DPoint p8;

	awpRect r;
	r.left   = w*50 / 100 - 256;
	r.right  = w*50 / 100 + 256;
	r.top    = h*50 / 100 - 256;
	r.bottom = h*50 / 100 + 256;

	if (!wing5->Detect(image, p5, &r))
		return false;

	r.left   = w*p5.X / 100 - 128;
	r.right  = w*p5.X / 100 + 128;
	r.top    = h*(p5.Y + 25) / 100 - 128;
	r.bottom = h*(p5.Y + 25) / 100 + 128;

	if (!wing8->Detect(image, p8, &r))
		return false;

	// преобразование координат
	awp2DPoint out[8];
	ConvertCoordinats(p5,p8, out);

	points[4] = p5;
	points[7] = p8;

	// детектирование остальных точек
	status[4] = true;
	status[7] = true;
	for (int i = 0; i < 8; i++)
	{
		if (i == 4 || i == 7)
			continue;

		char buf[32];
		sprintf(buf, "wing%i", i+1);
		TBeePointDector* wing = GetDetector(buf);
		if (wing != NULL)
		{
			r.left   = w*out[i].X / 100 - 64;
			r.right  = w*out[i].X / 100 + 64;
			r.top    = h*out[i].Y / 100 - 64;
			r.bottom = h*out[i].Y / 100 + 64;
			status[i] = wing->Detect(image, points[i], &r);
			if (!status[i])
				points[i] = out[i];
		}

	}

	return true;
}

TBeePointDector* TBeeMorphology::GetDetector(const char* lpClassName)
{
	TBeePointDector* result = NULL;
	for (int i = 0; i < m_detectors.GetCount(); i++)
	{
		TBeePointDector* d = (TBeePointDector*)m_detectors.Get(i);
		TLFString className = d->GetClassName();
		if (className == lpClassName)
		{
			result = d;
			break;
		}
	}
	return result;
}
