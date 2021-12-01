#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include <stdio.h>
#include "_LF.h"
#include "BeeFeatures.h"
  extern "C"
{
	#pragma link "awpipl2b.lib"
	#pragma link "JPEGLIB.lib"
}
#pragma link "awplflibb.lib"
#pragma link "tinyxml.lib"

int _tmain(int argc, _TCHAR* argv[])
{
	TLFDBLandmarks db;
	double ptsX,ptsY;
	if (!db.Connect(argv[1]))
	{

		printf("cannot connect to database %s\n", argv[1]);
		return 0;
	}
	printf ("argc=%d FileName=%s\n", argc, argv[1]);



	printf ("count=%d\n", db.Files()->Count());
	for (int i=0; i<db.Files()->Count();i++)
	{
		double Ci, DsA, Hi;
		Ci = 0;
		DsA = 0;
		Hi = 0;
		printf("%s\n", db.Files()->File(i)->FileName());
		//
		GetBeeFeatures(db.Files()->File(i), Ci, DsA, Hi);
		//for (int j=0;j<db.Files()->File(i)->Count();j++)
		//{
		//	printf("x=%lf y =%lf\n", db.Files()->File(i)->Landmark(j)->x(), db.Files()->File(i)->Landmark(j)->y());
		//}
		printf("Ci=%lf DsA=%lf Hi=%lf\n", Ci, DsA, Hi);
	}
	return 0;
}
