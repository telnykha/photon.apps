//---------------------------------------------------------------------------
#ifndef tpsUnitH
#define tpsUnitH
#include "_LF.h"

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

/*
	Преобразование tps файла разметки в файл XML Landmarks API

*/
void ConvertTPSTolandmarks(const char* fileTPS, const char* fileXML);
void RenameLandmarks(const char* fileName);
/*
	слияние двух баз данных.
	Базы данных должны содержать особые точки в формате WINGS
*/

void Mergelandmarks(const char* dbSrc, const char* dbDst);
void LandmarksToSemantic(const char* fileName);
void DrawLandmarks(const char* fileName, const char* imageFileName);

//---------------------------------------------------------------------------
#endif
