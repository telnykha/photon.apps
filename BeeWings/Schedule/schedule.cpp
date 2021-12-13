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
	printf("Usage: schedule schedule.xml\n");
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
   if (strcmp(name, "schedule") != 0)
	{
		printf("error: invalid configuration file.\n");
		return 1;
	}

	string path 	     =  pElem->Attribute("in_database");
	string tmplName      =  pElem->Attribute("tmpl_name");
	string outSchedule   =  pElem->Attribute("out_schedule");


	printf("params:\n");

	printf("input database: %s\n", path.c_str());
	printf("tmpl name: %s\n", tmplName.c_str());
	printf("out schedule: %s\n", outSchedule.c_str());

	FvcTemplate* tmpl = NULL;
	if (fvcLoadTemplate(tmplName.c_str(), &tmpl) != FVC_OK)
	{
        printf("error: cannot load template.\n");
		return 1;
	}

	printf("template width %i:\n", tmpl->nVectorWidth);
	printf("template height %i:\n", tmpl->nVectorHeight);
	printf("template num vectors %i:\n", tmpl->nNumVectors);


	int max = 125;

	FILE* s = fopen(outSchedule.c_str(), "w+t");

	for (int jay = 0; jay < max; jay++) {
		int counter = 0;
        _finddata_t filesInfo;
		int num_images = 0;
		long handle = 0;
		if ( (handle = _findfirst( (char*)((path+"*.awp").c_str()), &filesInfo)) != -1 )
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
				double ro = 0;

				awpImage* img = image.GetImage();
				//awpConvert(img, AWP_CONVERT_TO_FLOAT);
				fvcCompare(img, tmpl, &ro, FVC_COMPARE_EUCLID);
				float ro1 = ro;
				if (ro1 * 1000 <= jay)
					counter ++;
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
		fprintf(s, "%d\n", counter);
		_findclose( handle );
	}

	fclose(s);


	printf("\ndone.\n");
	return 0;
}
