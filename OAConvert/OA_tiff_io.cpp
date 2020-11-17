//---------------------------------------------------------------------------

#pragma hdrstop

#include "OA_tiff_io.h"
#include "tiff.h"
#include "tifflibio.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)


bool CheckOAOpenTIFFImage(const char*  fileName)
{
	TIFF* tif = NULL;
	tif = TIFFOpen(fileName, "r");
	if (tif == NULL)
		return false;
	int dircount = 0;
	do {
		dircount++;
	} while (TIFFReadDirectory(tif));
	if (dircount != TIFF_NUM_DIRS)
		return false;


	return true;
}
