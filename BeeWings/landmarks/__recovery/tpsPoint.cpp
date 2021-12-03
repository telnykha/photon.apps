//---------------------------------------------------------------------------
#pragma hdrstop
#pragma argsused

/*#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif
                */
#include "tpsPoint.h"
//#include <stdio.h>

//#include <io.h>
//#include <string>

//#include "_LF.h"
#include "fvlcore.h"

/*extern "C"
{
	#pragma link "awpipl2b.lib"
	#pragma link "JPEGLIB.lib"

}
#pragma link "TinyXML.lib"
#pragma link "awplflibb.lib"  */


void Detector(const char* fileName, const char* optionsFile)
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
        return;
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
	if (strcmp(name, "Detect") != 0)
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
	string format = ".awp";
	string removeDir = "true";

	pElem->QueryIntAttribute("ImageWidth", &ImageWidth);
	pElem->QueryIntAttribute("ImageHeight", &ImageHeight);
	pElem->QueryIntAttribute("width", &Width);
	pElem->QueryIntAttribute("height", &Height);
	ClassName=  pElem->Attribute("ClassName");
	Path = LFGetFilePath(fileName);//pElem->Attribute("src");
	format = pElem->Attribute("format");
	removeDir = pElem->Attribute("removeDir");
	string tmplName = pElem->Attribute("tmpl_name");

	printf("Export landmark images\n");
	printf("with format: %s\n", format.c_str());
	printf("landmark width = %i landmark height = %i\n", Width, Height);
	printf("source resize to: %i x %i\n", ImageWidth, ImageHeight);
	printf("remove directory = %s\n", removeDir.c_str());
	printf("\n\n");
	TLFAllScanner scanner;
	scanner.SetBaseWidth(Width);
	scanner.SetBaseHeight(Height);
	scanner.Scan(ImageWidth, ImageHeight);
	printf("image has %i fragments.\n", scanner.GetFragmentsCount());

	LFCreateDir("export");
	TLFString exportDir = "export";

	if (removeDir == "true") {
		LFRemoveDir(exportDir.c_str());
	}

	LFCreateDir(exportDir.c_str());

	FvcTemplate* tmpl = NULL;
	if (fvcLoadTemplate(tmplName.c_str(), &tmpl) != FVC_OK)
	{
		printf("error: cannot load template.\n");
		return;
	}

	//printf("template width %i:\n", tmpl->nVectorWidth);
	//printf("template height %i:\n", tmpl->nVectorHeight);
	//printf("template num vectors %i:\n", tmpl->nNumVectors);



	for (int i = 0; i < src.Files()->Count(); i++) {
	  TLFLandmarkFile* f = src.Files()->File(i);
	  awpImage* img = NULL;
	  string fileName = /*Path + "\\" +*/ f->FileName();
	  printf("Load image: %s .........", fileName.c_str());
	  if (awpLoadImage(fileName.c_str(), &img) != AWP_OK) {
		printf("error.\n");
		continue;
	  }
	  else
		printf("done.\n");
	  awpResizeBilinear(img, ImageWidth, ImageHeight);
	  awpConvert(img, AWP_CONVERT_3TO1_BYTE);

	  //for (int j = 0; j < f->Count(); j++) {
		  //TLFLandmark* lm = f->Landmark(j);
		  //awp2DPoint  p = lm->landmark();
		  //string lmClassName = lm->ClassName();
			// поиск пересечеий
	  awpImage* outImg = NULL;
	  awpCreateImage(&outImg, 960, 540, 1, AWP_DOUBLE);
	  double* d = (double*)outImg->pPixels;
	  for (int k = 0; k < scanner.GetFragmentsCount(); k++)
		{
		awpRect  r = scanner.GetFragmentRect(k);
		awpPoint p2;
		p2.X = (r.left+r.right)/2;
		p2.Y = (r.top + r.bottom)/2;
		awpImage* fgt = NULL;
		awpImage* normalize = NULL;
		double ro = 0;
		awpCopyRect(img, &fgt, &r);
		//awpSaveImage("outJP.jpg", fgt);
		awpNormalize(fgt, &normalize, AWP_NORM_L2);
		awpConvert(normalize, AWP_CONVERT_TO_FLOAT);
		fvcCompare(normalize, tmpl, &ro, FVC_COMPARE_EUCLID);
		d[p2.Y*960 + p2.X] = ro;
		if (k % 1000 == 0)
			printf("%lf\n", ro);
		awpConvert(normalize, AWP_CONVERT_TO_BYTE_WITH_NORM);

		awpSaveImage("outJp.jpg", normalize);


		awpReleaseImage(&fgt);
		awpReleaseImage(&normalize);
		//awpFillRect(img, &r, 0, 128););
		}
	  awpConvert(outImg, AWP_CONVERT_TO_BYTE_WITH_NORM);
	  UUID id;
	  LF_UUID_CREATE(id)
	  TLFString strUUID = LFGUIDToString(&id);
	  TLFString strNewFileName = exportDir + "\\" + strUUID + ".jpg";
	  awpSaveImage(strNewFileName.c_str(), outImg);
	  awpReleaseImage(&outImg);
	  awpReleaseImage(&img);
	  //}

	}
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
