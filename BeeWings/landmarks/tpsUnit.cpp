//---------------------------------------------------------------------------
#pragma hdrstop

#include "tpsUnit.h"

//#include <stdio.h>
//#include "_LF.h"
#include "BeeFeatures.h"



static char asciitolower(char in) {
	if (in <= 'Z' && in >= 'A')
		return in - ('Z' - 'z');
	return in;
}

/*
	Преобразование tps файла разметки в файл XML Landmarks API

*/
void ConvertTPSTolandmarks(const char* fileTPS, const char* fileXML)
{
	TLFLandmarkAttributes attrs;
	//1
	TLFString strID = ATTRUUIDS[0];
	TLFString className = "wing-1";
	int color;
	awpRGBtoWeb(0,128,255,&color);
	TLFLandmarkAttr* wing = new TLFLandmarkAttr(strID, color, className.c_str());
	attrs.Append(wing);
	//2
	strID = ATTRUUIDS[1];
	className = "wing-2";
	awpRGBtoWeb(255,255,255,&color);
	wing = new TLFLandmarkAttr(strID, color, className.c_str());
	attrs.Append(wing);
	//3
	strID = ATTRUUIDS[2];
	className = "wing-3";
	awpRGBtoWeb(0,255,255,&color);
	wing = new TLFLandmarkAttr(strID, color, className.c_str());
	attrs.Append(wing);
	//4
	strID = ATTRUUIDS[3];
	className = "wing-4";
	awpRGBtoWeb(255,0,255,&color);
	wing = new TLFLandmarkAttr(strID, color, className.c_str());
	attrs.Append(wing);
	//5
	strID = ATTRUUIDS[4];
	className = "wing-5";
	awpRGBtoWeb(255,255,0,&color);
	wing = new TLFLandmarkAttr(strID, color, className.c_str());
	attrs.Append(wing);
	//6
	strID = ATTRUUIDS[5];
	className = "wing-6";
	awpRGBtoWeb(255,0,0,&color);
	wing = new TLFLandmarkAttr(strID, color, className.c_str());
	attrs.Append(wing);
	//7
	strID = ATTRUUIDS[6];
	className = "wing-7";
	awpRGBtoWeb(0,255,0,&color);
	wing = new TLFLandmarkAttr(strID, color, className.c_str());
	attrs.Append(wing);
	//8
	strID = ATTRUUIDS[7];
	className = "wing-8";
	awpRGBtoWeb(0,0,255,&color);
	wing = new TLFLandmarkAttr(strID, color, className.c_str());
	attrs.Append(wing);

	TLFDBLandmarks* db = TLFDBLandmarks::CreateDatabase(attrs, fileXML);

	FILE* f = fopen(fileTPS, "r+t");
	// read line
	char buf0[255];
	char buf1[255];
	int object = 0;
	int count = 0;
	char ch;
	TLFString str = "";
	double xx[8];
	double yy[8];
	while (fscanf(f, "%c", &ch) != EOF)
	{
		str += ch;
		if (ch == '\n' || ch == '\r') {
		  str += '\0';
		  TLFString s = str;
		  str = "";

		  if (s.find("LM") != string::npos) {
			//printf("object = %i\n", object);
			object++;
			continue;
			}
			if (s.find("IMAGE") != string::npos) {
				TLFString tmp = "IMAGE=";
				tmp = s.substr(tmp.length(), s.length() - tmp.length() - 2);
				tmp += '\0';
				TLFLandmarkFiles* files = db->Files();
				std::transform(tmp.begin(), tmp.end(), tmp.begin(), asciitolower);
				/*
					Load image
				*/
				TLFImage img;
				bool res = img.LoadFromFile(tmp.c_str());
				if (!res) {
					printf("File %s not found!\n", tmp.c_str());
					continue;
				}
				awpImage* _img = img.GetImage();
				TLFLandmarkFile* file = new TLFLandmarkFile(tmp.c_str());
				for (int i = 0; i < 8; i++) {
				   TLFLandmarkAttr* attr = db->Attributes()->Attribute(i);
				   awp2DPoint p;
				   p.X = 100.f*xx[i]/(double)_img->sSizeX;
				   p.Y = 100.f*yy[i]/(double)_img->sSizeY;
				   TLFLandmark* land = new TLFLandmark(attr, p, 0.5);
				   file->Append(land);
				}
				files->Append(file);
				printf("%s\n", tmp.c_str());
				continue;
			}
			if (s.find("ID") != string::npos) {
				continue;
			}
			float x,y,a;
			sscanf(s.c_str(), "%s%s\n", buf0,  buf1);
			sscanf(buf0, "%f%f\n", &x,  &a);
			sscanf(buf1, "%f%f\n", &y,  &a);
			printf("x = %f\t y = %f\n", x,y);
			xx[count] = x;
			yy[count] = y;
			count++;
			if (count >=8) {
				count = 0;
			}
		}
	}

	fclose(f);
	delete db;
}

/*
   Вывод признаков
*/
void takeSigns(const char* fileName)
{
	/*double ptsX[8], ptsY[8];
	double DE, CD, CE, AB, X, Y, Xab, Yab, Xcd, Ycd;
	const double PI = 3.141592653589793; */
	double DsA, Ci, Hi;
	TLFDBLandmarks kd;

	if (!kd.Connect(fileName)) {
		printf("cannot connet to database: %s\n", fileName);
		return;
	}
	for (int i = 0; i < kd.Files()->Count(); i++) {
		//TLFLandmarkFile* f = src.Files()->File(i);
		GetBeeFeatures(kd.Files()->File(i), Ci, DsA, Hi);
		printf("Ci=%lf DsA=%lf Hi=%lf\n", Ci, DsA, Hi);
	}
	kd.Close();
}



void FlipLandmarks(const char* fileName)
{
	TLFDBLandmarks src;
	if (!src.Connect(fileName)) {
		printf("cannot connet to database: %s\n", fileName);
		return;
	}
	for (int i = 0; i < src.Files()->Count(); i++) {
	  TLFLandmarkFile* f = src.Files()->File(i);
	  for (int j = 0; j < f->Count(); j++) {
		  TLFLandmark* lm = f->Landmark(j);
		  awp2DPoint  p = lm->landmark();
		  p.Y = 100 - p.Y;
		  lm->SetPoint(p);
	  }
	}
	src.Close();
}

/*
	переименование базы данных landmarks
*/
void RenameLandmarks(const char* fileName)
{
	TLFString strPath = "";
	strPath = LFGetFilePath(fileName);
	if (strPath == fileName) {
		strPath = "";
	}
	else
		strPath += c_separator;
	TLFDBLandmarks db;
	if (!db.Connect(fileName)) {
		printf("cannot connet to database: %s\n", fileName);
		return;
	}

	for (int i = 0; i < db.Files()->Count(); i++)
	{
		TLFLandmarkFile* f = db.Files()->File(i);
		TLFString strFileName = strPath + f->FileName();
        printf("filename = %s\n", strFileName.c_str());
		UUID id;
		LF_UUID_CREATE(id)
		TLFString strUUID = LFGUIDToString(&id);
		TLFString strNewFileName = strPath +  strUUID + ".jpg";
		if (rename(strFileName.c_str(), strNewFileName.c_str())!=0)
		{
			printf("cannot rename file: %s\n", strFileName.c_str());
			continue;
		}
		TLFString strName = strUUID + ".jpg";
		f->SetFileName(strName.c_str());
		remove( strFileName.c_str());
	}
}

/*
	слияние двух баз данных.
	Базы данных должны содержать особые точки в формате WINGS
*/

void Mergelandmarks(const char* dbSrc, const char* dbDst)
{
	TLFDBLandmarks src;
	TLFDBLandmarks dst;

	if (!src.Connect(dbSrc)) {
		printf("cannot connet to database: %s\n", dbSrc);
		return;
	}

	if (!dst.Connect(dbDst)) {
		printf("cannot connet to database: %s\n", dbDst);
		return;
	}
	// цикл по всем файлам базы данных
	for (int i = 0; i < src.Files()->Count(); i++) {
		TLFLandmarkFile* f = src.Files()->File(i);
		// цикл по всем
		TLFLandmarkFile* f1 = new TLFLandmarkFile(f->FileName());
		for (int j = 0; j < f->Count(); j++) {
		   TLFLandmark* lm = f->Landmark(j);
		   TLFLandmark* lmdst = new TLFLandmark(dst.Attributes()->Attribute(j), lm->landmark());
		   f1->Append(lmdst);
		}
        dst.Files()->Append(f1);
	}
}

void LandmarksToSemantic(const char* fileName)
{
	TLFDBLandmarks src;
	if (!src.Connect(fileName)) {
		printf("cannot connet to database: %s\n", fileName);
		return;
	}
	// создадим словарь
	TLFSemanticDictinary dict;
	for (int i = 0; i < src.Attributes()->Count(); i++) {
		TLFLandmarkAttr* a = src.Attributes()->Attribute(i);
		TLFSemanticDictinaryItem* item = new TLFSemanticDictinaryItem(a->ClassName());

		item->SetColor(a->Color());
		dict.AddWordToDictinary(item);
	}
	if (!dict.SaveXML("dictionary.xml"))
	{
		printf("cannot save dictionary\n");
		return;
	}
	for (int i = 0; i < src.Files()->Count(); i++) {
		TLFLandmarkFile* f = src.Files()->File(i);
		TLFSemanticImageDescriptor desc;
		TLFString str = f->FileName();
		printf("processing.... %s", f->FileName());
		TLFString xmlName = LFChangeFileExt(str, ".xml");
		TLFImage image;
		image.LoadFromFile(f->FileName());
		for (int j = 0; j < f->Count(); j++)
		{
			TLFDetectedItem* item = new TLFDetectedItem();
			TLFSemanticDictinaryItem* dict_item = dict.GetWordFromDictinary(f->Landmark(j)->ClassName());
			awpRect 	rect;
			awp2DPoint  p = f->Landmark(j)->landmark();
			//p.Y = 100 - p.Y;
			awpPoint    pp;
			pp.X = p.X*image.GetImage()->sSizeX / 100.;
			pp.Y = p.Y*image.GetImage()->sSizeY / 100.;
			rect.left = pp.X - 48;
			rect.right = pp.X + 48;
			rect.top = pp.Y - 48;
			rect.bottom = pp.Y + 48;
			item->SetBounds(rect, image.GetImage()->sSizeX, image.GetImage()->sSizeY);
			TLFString uuid =  dict_item->GetId();
			item->SetType(uuid.c_str());
			ILFScanner* s = dict_item->GetScanner();
			item->m_bh = s->GetBaseHeight();
			item->m_bw = s->GetBaseWidth();
			item->SetDetectorName("Landmark to LF convertor");
			desc.AddDetectedItem(item);
		}
		desc.SaveXML(xmlName.c_str());
		printf(" - done.\n");
	}
}
void DrawFix5landmarks(TLFDBLandmarks &src, awpImage* dst)
{
	for (int i = 0; i < src.Files()->Count(); i++) {
	  TLFLandmarkFile* f = src.Files()->File(i);
	  TLFLandmark* lm = f->Landmark(4);
	  awp2DPoint  p0 = lm->landmark();
	  for (int j = 0; j < f->Count(); j++) {
		  TLFLandmark* lm = f->Landmark(j);
		  awp2DPoint  p = lm->landmark();
		  p.X = 50 + (p.X - p0.X);
		  p.Y = 50 + (p.Y - p0.Y);
		  awpPoint    pp;
		  pp.X = p.X*dst->sSizeX / 100;
		  pp.Y = p.Y*dst->sSizeY / 100;
		  AWPBYTE R,G,B;
		  awpWebtoRGB(lm->Color(), &R, &G, &B);
		  awpRect cross;
		  cross.left = pp.X - 8;
		  cross.right = pp.X + 8;
		  cross.top = pp.Y - 8;
		  cross.bottom = pp.Y+8;
		  awpDrawCCross(dst, &cross, R,G,B,1);
	  }
	}
}

void DrawFix58Landmarks(TLFDBLandmarks &src, awpImage* dst)
{
	for (int i = 0; i < src.Files()->Count(); i++) {
	  TLFLandmarkFile* f = src.Files()->File(i);
	  TLFLandmark* lm4 = f->Landmark(4);
	  awp2DPoint  p4 = lm4->landmark();
	  TLFLandmark* lm7 = f->Landmark(7);
	  awp2DPoint  p7 = lm7->landmark();
	  double tanfi = (p7.X - p4.X) / (p7.Y - p4.Y);
	  //printf("tabfi = %lf\n", tanfi);
	  double fi = atan(tanfi);
	  double L = sqrt((p7.X - p4.X)*(p7.X - p4.X) + (p7.Y - p4.Y)*(p7.Y - p4.Y));


	  for (int j = 0; j < f->Count(); j++) {
		  TLFLandmark* lm = f->Landmark(j);
		  awp2DPoint  p = lm->landmark();
		  double a =  50 + 25*(cos(fi)*(p.X - p4.X)/L - sin(fi)*(p.Y - p4.Y)/L);
		  double b =  50 + 25*(sin(fi)*(p.X - p4.X)/L + cos(fi)*(p.Y - p4.Y)/L);
		  p.X = a;
          p.Y = b;

		  awpPoint    pp;
		  pp.X = p.X*dst->sSizeX / 100;
		  pp.Y = p.Y*dst->sSizeY / 100;
		  AWPBYTE R,G,B;
		  awpWebtoRGB(lm->Color(), &R, &G, &B);
		  awpRect cross;
		  cross.left = pp.X - 8;
		  cross.right = pp.X + 8;
		  cross.top = pp.Y - 8;
		  cross.bottom = pp.Y+8;
		  awpDrawCCross(dst, &cross, R,G,B,1);
	  }
	}
}

void DrawLandmarks(const char* fileName, const char* imageFileName)
{
	const image_scale = 1;
	const image_width = 1980 / image_scale;
	const image_height = 1080 / image_scale;


	TLFDBLandmarks src;
	if (!src.Connect(fileName)) {
		printf("cannot connet to database: %s\n", fileName);
		return;
	}
	awpImage* dst = NULL;
	if (awpCreateImage(&dst, image_width, image_height, 3, AWP_BYTE) != AWP_OK) {
		printf("cannot create image\n");
		return;
	}
 //    DrawFix5landmarks(src, dst);

	TLF2DRect rects[8];
	for (int i = 0; i < 8; i++) {
		rects[i].SetVertexes(-1,-1,-1,-1);
	}
	for (int i = 0; i < src.Files()->Count(); i++) {
	  TLFLandmarkFile* f = src.Files()->File(i);
	  for (int j = 0; j < f->Count(); j++) {
		  TLFLandmark* lm = f->Landmark(j);
		  awp2DPoint  p = lm->landmark();
		  if (rects[j].left() < 0) {
			   rects[j].SetVertexes(p.X, p.X +1, p.Y, p.Y+1);
		  }else
		  {
			if (p.X < rects[j].left()) {
				awp2DPoint _pl = rects[j].GetLeftTop();
				awp2DPoint _pr = rects[j].GetRightBottom();
				rects[j].SetVertexes(p.X, _pr.X, _pl.Y, _pr.Y);
			}
			if (p.X > rects[j].right()) {
				awp2DPoint _pl = rects[j].GetLeftTop();
				awp2DPoint _pr = rects[j].GetRightBottom();
				rects[j].SetVertexes(_pl.X, p.X, _pl.Y, _pr.Y);
			}
			if (p.Y < rects[j].top()) {
				awp2DPoint _pl = rects[j].GetLeftTop();
				awp2DPoint _pr = rects[j].GetRightBottom();
				rects[j].SetVertexes(_pl.X, _pr.X, p.Y, _pr.Y);
			}
			if (p.Y > rects[j].bottom()) {
				awp2DPoint _pl = rects[j].GetLeftTop();
				awp2DPoint _pr = rects[j].GetRightBottom();
				rects[j].SetVertexes(_pl.X, _pr.X, _pl.Y, p.Y);
			}
		  }
		  awpPoint    pp;
		  pp.X = p.X*dst->sSizeX / 100;
		  pp.Y = p.Y*dst->sSizeY / 100;
		  AWPBYTE R,G,B;
		  awpWebtoRGB(lm->Color(), &R, &G, &B);
		  awpRect cross;
		  cross.left = pp.X - 8;
		  cross.right = pp.X + 8;
		  cross.top = pp.Y - 8;
		  cross.bottom = pp.Y+8;
		  awpDrawCCross(dst, &cross, R,G,B,1);
	  }
	}
	// отрисовка прямоугольников и создание файла зон
	TLFZones zones;

	for (int i = 0; i < 8; i++) {
	   TLFZone* z = new TLFZone(rects[i]);
	   zones.AddZone(z);
	   awpRect r;
	   r.left = image_width*rects[i].left() / 100 - 48/image_scale;
	   r.top  = image_height*rects[i].top() / 100 - 48/image_scale;
	   r.right = image_width*rects[i].right() / 100 + 48/image_scale;
	   r.bottom  = image_height*rects[i].bottom() / 100 + 48/image_scale;
	  // awpDrawCRect(dst, &r, 128,128,128,2);
	   TLFAllScanner s;
	   s.Scan(image_width,image_height);
	   printf("%d wing index, total items = %d", i, s.GetFragmentsCount());
	   if (!s.Filter(r))
	   {
			printf("\n cannot filter bounds \n");
	   }
	   else
		   printf(" items to test = %d \n", s.GetFragmentsCount());
	}

	if (awpSaveImage(imageFileName, dst) != AWP_OK) {
		printf("cannot save image %s:\n", imageFileName);
	}
	awpReleaseImage(&dst);
	// сохраняем зоны в файл.
	//TLFString str = imageFileName;
	//str = LFChangeFileExt(str, ".xml");
	//zones.Save(str.c_str());
}
/*
	Экспорт производится в папки
	export/className/
	export/className/bg

	параметры экспорта:
	ImageWidth   - ширина изображения для экспорта
	ImageHeight  - высота изображения для экспорта
	Radius       - максимальное расстояние от особой точки
	при котором осуществляется экспорт
	ClassName    - имя класса для экспорта
*/
void ExportLandmarks(const char* fileName, const char* optionsFile)
{
	TLFDBLandmarks src;
	if (!src.Connect(fileName)) {
		printf("cannot connet to database: %s\n", fileName);
		return;
	}
	TiXmlDocument doc;
	if(!doc.LoadFile(optionsFile))
	{
		printf("Cannot load options file: + %s\n", optionsFile);
	}
	TiXmlHandle hDoc(&doc);
	TiXmlElement* pElem = NULL;
	pElem = hDoc.FirstChildElement().Element();
	if (!pElem)
	{
		printf("error: invalid configuration file.\n");
		return;
	}
	const char* name = pElem->Value();
	if (strcmp(name, "LFDbExport") != 0)
	{
		printf("error: invalid configuration file.\n");
		return;
	}
	int ImageWidth = 240;
	int ImageHeight = 135;
	int Width = 24;
	int Height = 24;
	string ClassName = "Wing-1";
	string Path = "1";
	double Radius = 0;

	pElem->QueryIntAttribute("ImageWidth", &ImageWidth);
	pElem->QueryIntAttribute("ImageHeight", &ImageHeight);
	pElem->QueryIntAttribute("width", &Width);
	pElem->QueryIntAttribute("height", &Height);
	pElem->QueryDoubleAttribute("Radius", &Radius);
	ClassName=  pElem->Attribute("ClassName");
	Path = LFGetFilePath(fileName);//pElem->Attribute("src");

	printf("Export landmark images\n");
	printf("for class = %s\n", ClassName.c_str());
	printf("with radius: %i\n", Radius);
	printf("landmark width = %i landmark height = %i\n", Width, Height);
	printf("source resize to: %i x %i\n", ImageWidth, ImageHeight);
	printf("\n\n");
	TLFAllScanner scanner;
	scanner.SetBaseWidth(Width);
	scanner.SetBaseHeight(Height);
	scanner.Scan(ImageWidth, ImageHeight);
	printf("image has %i fragments.\n", scanner.GetFragmentsCount());

	LFCreateDir("export");
	TLFString exportDir = "export\\" + ClassName;
	TLFString exportBgDir = exportDir + "\\bg";
	//LFRemoveDir(exportDir.c_str());
	LFCreateDir(exportDir.c_str());
	//LFRemoveDir(exportBgDir.c_str());
	LFCreateDir(exportBgDir.c_str());

	for (int i = 0; i < src.Files()->Count(); i++) {
	  TLFLandmarkFile* f = src.Files()->File(i);
	  awpImage* img = NULL;
	  string fileName = Path + "\\" + f->FileName();
	  printf("Load image: %s .........", fileName.c_str());
	  if (awpLoadImage(fileName.c_str(), &img) != AWP_OK) {
		printf("error.\n");
		continue;
	  }
	  else
		printf("done.\n");
	  awpResizeBilinear(img, ImageWidth, ImageHeight);
	  awpConvert(img, AWP_CONVERT_3TO1_BYTE);
	  for (int j = 0; j < f->Count(); j++) {
		  TLFLandmark* lm = f->Landmark(j);
		  awp2DPoint  p = lm->landmark();
		  string lmClassName = lm->ClassName();
		  if (lmClassName == ClassName)
		  {
			awpPoint p1;
			p1.X = ImageWidth*p.X/ 100.;
			p1.Y = ImageHeight*p.Y/100.;
			// поиск пересечеий
			for (int k = 0; k < scanner.GetFragmentsCount(); k++)
			{
				awpRect  r = scanner.GetFragmentRect(k);
				awpPoint p2;
				p2.X = (r.left+r.right)/2;
				p2.Y = (r.top + r.bottom)/2;
				if (sqrt(float((p1.X-p2.X)*(p1.X-p2.X)+(p1.Y-p2.Y)*(p1.Y-p2.Y))) <= Radius)
				{
					//printf("............Save image around landmark.\n");
					awpImage* fgt = NULL;
					awpCopyRect(img, &fgt, &r);
					//awpFillRect(img, &r, 0, 128);
					UUID id;
					LF_UUID_CREATE(id)
					TLFString strUUID = LFGUIDToString(&id);
					TLFString strNewFileName = exportDir + "\\" + strUUID + ".jpg";
					awpSaveImage(strNewFileName.c_str(), fgt);
					awpReleaseImage(&fgt);

				}
			}
			awpRect r;
			r.left = p1.X - Width / 2;
			r.right = p1.X + Width /2;
			r.top = p1.Y - Height /2 ;
			r.bottom = p1.Y + Height / 2;
            awpFillRect(img, &r, 0, 128);
		  }
	  }
	  // save image
	  UUID id;
	  LF_UUID_CREATE(id)
	  TLFString strUUID = LFGUIDToString(&id);
	  TLFString strNewFileName = exportBgDir + "\\" + strUUID + ".awp";
	  awpSaveImage(strNewFileName.c_str(), img);
	  awpReleaseImage(&img);
	}
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
