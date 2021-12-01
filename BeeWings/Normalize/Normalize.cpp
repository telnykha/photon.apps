#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include <stdio.h>

#include <io.h>
#include <string>

#include "_LF.h"
#include "fvlcore.h"

extern "C"
{
	#pragma link "awpipl2b.lib"
	#pragma link "JPEGLIB.lib"

}
#pragma link "TinyXML.lib"
#pragma link "awplflibb.lib"

 void Usage()
{
	printf("Usage:  reference.xml\n");
}
 int _tmain(int argc, _TCHAR* argv[])
{
	if (argc < 2)
	{
		Usage();
		return 1;
	}

	// main program

	TiXmlDocument doc;
	if (!doc.LoadFile(argv[1]))
	{
		printf("error: cannot load configuration.\n");
		return 1;
	}

	TiXmlHandle hDoc(&doc);
	TiXmlElement* pElem = NULL;
	pElem = hDoc.FirstChildElement().Element();
	if (!pElem)
	{
		printf("error: invalid configuration file.\n");
		return 1;
	}
   const char* name = pElem->Value();
   if (strcmp(name, "Normalize") != 0)
	{
		printf("error: invalid configuration file.\n");
		return 1;
	}

	string ClassName = "Wing-1";
	string removeDir = "true";

	ClassName=  pElem->Attribute("ClassName");
	string path = pElem->Attribute("in_database");
	removeDir = pElem->Attribute("removeDir");

	LFCreateDir("awpNormalize");
	TLFString exportDir = "awpNormalize\\" + ClassName;

	if (removeDir == "true") {
		LFRemoveDir(exportDir.c_str());;
	}
	LFCreateDir(exportDir.c_str());

	_finddata_t filesInfo;
	int num_images = 0;
	long handle = 0;
	FILE* f = fopen(path.c_str(), "w+t");
	if ( (handle = _findfirst( (char*)((path+"*.jpg").c_str()), &filesInfo)) != -1 )
	{
		do
		{
			string name = path + filesInfo.name;
			TLFImage image;
			if (!image.LoadFromFile((char*)name.c_str()))
			{
				printf("cannot load image %s \n", name.c_str());
				continue;
			}
			num_images++;
			//double ro = 0;

			awpImage* img = image.GetImage();
			awpImage* norm = NULL;
			awpImage* normalize = NULL;
			/*UUID id;
			LF_UUID_CREATE(id)
			TLFString strUUID = LFGUIDToString(&id);
			TLFString strNewFileName = exportDir + "\\" + strUUID + ".jpg";
			awpSaveImage(strNewFileName.c_str(), img);  */

			if (awpNorm(img, &norm, AWP_NORM_L2) != AWP_OK) {
				printf("error.\n");
				continue;
			}

			if (awpNormalize(img, &normalize, AWP_NORM_L2) != AWP_OK) {
				printf("error.\n");
				continue;
			}

			awpNormalize(img, &normalize, AWP_NORM_L2);
			//awpConvert(normalize, AWP_CONVERT_TO_BYTE_WITH_NORM);
			awpConvert(normalize, AWP_CONVERT_TO_FLOAT);
			UUID id;
			LF_UUID_CREATE(id)
			TLFString strUUID = LFGUIDToString(&id);
			TLFString strNewFileName = exportDir + "\\" + strUUID + ".awp";
			awpSaveImage(strNewFileName.c_str(), normalize);

			//awpNorm(normalize, &norm, AWP_NORM_L2);
			//awpConvert(normalize, AWP_CONVERT_TO_FLOAT);

			//double* ddd = (double*)norm->pPixels;
			//printf("norm = %lf\n", ddd[0]);
			//double* nnn = (double*)normalize->pPixels;
			//printf("normalize = %lf\n", nnn[0]);

			awpReleaseImage(&normalize);
			awpReleaseImage(&norm);
			//awpReleaseImage(&img);
			//awpConvert(img, AWP_CONVERT_TO_FLOAT);
			//fvcCompare(img, tmpl, &ro, FVC_COMPARE_EUCLID);
			//float ro1 = ro;
			//fprintf(f, "%s\t%f\n", filesInfo.name, ro1);
/*			awpImage* rec = NULL;
			if (fvcGetReconstruction(tmpl, img, &rec) != FVC_OK)
				printf("reconstruction error.\n");
			if (rec != NULL)
			{
				awpImage* norm = NULL;
				awpNormalize(rec, &norm, AWP_NORM_L2);
				awpConvert(norm, AWP_CONVERT_TO_FLOAT);
				//
				double ro = 0;
				if (awpDistance(img, rec, AWP_DIST_L2 ,&ro) != AWP_OK)
					printf("distance error.\n");
				float ro1 = ro;
				fprintf(f, "%s\t%f\n", filesInfo.name, ro1);
				awpReleaseImage(&rec);
				awpReleaseImage(&norm);
			}*/

			if (num_images % 100 == 0)
				printf(">");

		}while(!_findnext( handle, &filesInfo ));
	}
	_findclose( handle );
	fclose(f);


	printf("\ndone.\n");
	return 0;
}
