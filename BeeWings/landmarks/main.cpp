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
#include "tpsUnit.h"

extern "C"
{
	#pragma link "awpipl2b.lib"
	#pragma link "JPEGLIB.lib"
}
#pragma link "awplflibb.lib"
#pragma link "tinyxml.lib"


/*
	Использование утилиты:
	tps2landmarks -c filename.tps filename.xml - проеборазование tps в   TLFDBLandmarks
	tps2landmarks -r filename.xml - переименование файлов в бд TLFDBLandmarks
	tps2landmarks -m filename1.xml filename2.xml - слияние двух файлов TLFDBLandmarks
	tps2landmarks -s filename.xml преобразование TLFDBLandmarks в TLFDBLabeledImages
	tps2landmarks -d filename.xml image.jpg отрисовка  TLFDBLandmarks на image.jpg и сохрание найденных зон в image.xml
	tps2landmarks -f filename.xml - отражение TLFDBLandmarks по вертикали
    tps2landmarks -e filename.xml options.xml - экспорт изображений особой точки
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
	 printf("Flip landmarks vertical: tps2landmarks -f filename.xml\n");
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
	else if (key == "-f") {
			if (argc != 3) {
				Usage();
				return 0;
			}
		  FlipLandmarks(argv[2]);
		 }
	else if (key == "-e") {
			if (argc != 4) {
				Usage();
				return 0;
			}
		  ExportLandmarks(argv[2], argv[3]);
		 }
	else
		Usage();

	return 0;
}
