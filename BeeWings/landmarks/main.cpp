#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif
#include <string>
#include <stdio.h>
#include "_LF.h"

extern "C"
{
	#pragma link "awpipl2b.lib"
	#pragma link "JPEGLIB.lib"
}
#pragma link "awplflibb.lib"
#pragma link "tinyxml.lib"

const TLFString ATTRUUIDS[8] =
{
"65FE75D4-B829-4117-8076-0A6D116F6EE5",
"AAF4E336-75AE-4802-BF5B-5A054968DC84",
"DA50F8EA-E59A-480D-98F9-55710235D1B7",
"5F86768E-E0BA-45B2-BE5E-BB5A1F28C919",
"B3CF6567-2FEA-4169-B9EA-229652889D69",
"2C9C044F-73B6-4D31-B3B3-4645493B3745",
"CD5DE575-CD69-4349-89E4-2DCEFC47930E",
"7BFF3331-C358-461B-968E-F8ABB18A4C97"
};


char asciitolower(char in) {
	if (in <= 'Z' && in >= 'A')
		return in - ('Z' - 'z');
	return in;
}
/*
	Использование утилиты:
	tps2landmarks -c filename.tps filename.xml - проеборазование tps в   TLFDBLandmarks
	tps2landmarks -r filename.xml - переименование файлов в бд TLFDBLandmarks
	tps2landmarks -m filename1.xml filename2.xml - слияние двух файлов TLFDBLandmarks
	tps2landmarks -s filename.xml преобразование TLFDBLandmarks в TLFDBLabeledImages
	tps2landmarks -d filename.xml image.jpg отрисовка  TLFDBLandmarks на image.jpg и сохрание найденных зон в image.xml
*/
void Usage()
{
	 printf("tps2landmarks is a part of BEE WINGS project.\n");
	 printf("Copyright (c) 2021 NN-Videolab.net\n");
	 printf("Usage: tps2landmarks -key [file1] [file2]\n");
	 printf("Convert TPS to landmarks     : tps2landmarks -c filename.tps filename.xml\n");
	 printf("Set unique names to files    : tps2landmarks -r filename.xml\n");
	 printf("Merge two files              : tps2landmarks -m filename1.xml filename2.xml\n");
	 printf("Convert landmarks to semantic: tps2landmarks -s filename.xml\n");
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
	awpRGBtoWeb(128,128,128,&color);
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
				   TLFLandmark* land = new TLFLandmark(attr, p);
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
	переименование базы данных landmarks
*/
void RenameLandmarks(const char* fileName)
{
	TLFDBLandmarks db;
	if (!db.Connect(fileName)) {
		printf("cannot connet to database: %s\n", fileName);
		return;
	}
	for (int i = 0; i < db.Files()->Count(); i++)
	{
		TLFLandmarkFile* f = db.Files()->File(i);
		TLFString strFileName =    f->FileName();

		UUID id;
		LF_UUID_CREATE(id)
		TLFString strUUID = LFGUIDToString(&id);
		TLFString strNewFileName = strUUID + ".jpg";
		//std::transform(strNewFileName.begin(), strNewFileName.end(), strNewFileName.begin(), asciitolower);
		if (rename(strFileName.c_str(), strNewFileName.c_str())!=0)
		{
			printf("cannot rename file: %s\n", strFileName.c_str());
			continue;
		}
		f->SetFileName(strNewFileName.c_str());
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
            p.Y = 100 - p.Y;
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

void DrawLandmarks(const char* fileName, const char* imageFileName)
{
	const image_scale = 4;
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
	TLF2DRect rects[8];
	for (int i = 0; i < 8; i++) {
		rects[i].SetVertexes(-1,-1,-1,-1);
	}
	for (int i = 0; i < src.Files()->Count(); i++) {
	  TLFLandmarkFile* f = src.Files()->File(i);
	  for (int j = 0; j < f->Count(); j++) {
		  TLFLandmark* lm = f->Landmark(j);
		  awp2DPoint  p = lm->landmark();
		  p.Y = 100 - p.Y;
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
		  awpDrawCCross(dst, &cross, B,G,R,2);
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
	   awpDrawCRect(dst, &r, 128,128,128,2);
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
	TLFString str = imageFileName;
	str = LFChangeFileExt(str, ".xml");
    zones.Save(str.c_str());
}

int _tmain(int argc, _TCHAR* argv[])
{
	if (argc < 3) {
		Usage();
		return 0;
	}

	TLFString key = argv[1];
	if (key == "-c") {
		if (argc != 4) {
			Usage();
			return 0;
		}
		else
		   ConvertTPSTolandmarks(argv[2], argv[3]);
	}
	else if (key == "-r") {
			if (argc != 3) {
				Usage();
				return 0;
			}
			else
				RenameLandmarks(argv[2]);
		 }
	else if (key == "-m") {
		if (argc != 4) {
			Usage();
			return 0;
		}
		else
		   Mergelandmarks(argv[2], argv[3]);

				}
	else if (key == "-s") {
			if (argc != 3) {
				Usage();
				return 0;
			}
			else
				LandmarksToSemantic(argv[2]);
	}
	else if (key == "-d") {
			if (argc != 4) {
				Usage();
				return 0;
			}
			else
				DrawLandmarks(argv[2], argv[3]);
	}
	else
		Usage();

	return 0;
}
