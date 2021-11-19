//---------------------------------------------------------------------------

#include <cmath>
#include <string>

#pragma hdrstop

#include "BeeFeatures.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

bool GetBeeFeatures(TLFLandmarkFile* file, double& Ci, double& DsA, double& Hi)
{
	double x, y, DE, CD, CE, AB, X, Y, K2, K3, ATAN, POW;
	double ptsX[8], ptsY[8];
	const double PI = 3.141592653589793;
	double Xhc, Yhc, Xab, Yab, alp, Xcd, Ycd;

	TLFImage image;
	image.LoadFromFile(file->FileName());
	double sX = image.GetImage()->sSizeX;
	double sY = image.GetImage()->sSizeY;
	y = 0;
	int j = 0;
	for (j; j<8; j++)
	{
	ptsX[j] = file->Landmark(j)->x();
	ptsY[j] = 100 - file->Landmark(j)->y();
	//x = file->Landmark(j)->x();
	//y = file->Landmark(j)->y();
	//printf("ptsX=%lf ptsY=%lf\n", ptsX[j], ptsY[j]);
	ptsX[j] = ptsX[j] * sX / 100;
	ptsY[j] = ptsY[j] * sY / 100;
	//printf("ptsX=%lf ptsY=%lf\n", ptsX[j], ptsY[j]);
	}


	Xcd = ptsX[7] - ptsX[2];
	Ycd = ptsY[7] - ptsY[2];
	Xhc = ptsX[7] - 0.5 * (ptsX[0] + ptsX[1]);
	Yhc = ptsY[7] - 0.5 * (ptsY[0] + ptsY[1]);
	Xab = ptsX[1] - ptsX[0];
	Yab = ptsY[1] - ptsY[0];


	DE = sqrt(pow((ptsX[6]-ptsX[5]),2)+(pow((ptsY[6]-ptsY[5]),2)));
	CD = sqrt(pow((ptsX[5]-ptsX[4]),2)+(pow((ptsY[5]-ptsY[4]),2)));
	CE = sqrt(pow((ptsX[6]-ptsX[4]),2)+(pow((ptsY[6]-ptsY[4]),2)));
	AB = sqrt(pow((ptsX[3]-ptsX[2]),2)+(pow((ptsY[3]-ptsY[2]),2)));

    Ci = CD / DE;
	Hi = CE / AB;
	DsA = asin((Xcd * Xab + Ycd * Yab) / (sqrt(pow(Xcd,2) + pow(Ycd,2)) * (sqrt(pow(Xab,2) + pow(Yab,2))))) * 180 / PI;

	/* X = (pow(ptsY[1],2)*ptsX[0] - ptsY[0]*ptsY[1]*ptsX[0] - ptsY[1]*ptsX[0]*ptsY[2] - ptsY[1]*ptsY[0]*ptsX[1] + ptsY[1]*ptsX[1]*ptsY[2] - ptsY[0]*ptsX[1]*ptsY[2] + pow(ptsY[0],2)*ptsX[1] + ptsX[2]*pow(ptsX[1],2) + pow(ptsX[0],2)*ptsX[2] - 2*ptsX[1]*ptsX[2]*ptsX[0] + ptsX[0]*ptsY[2]*ptsY[0]) / (pow(ptsX[1],2) - 2*ptsX[0]*ptsX[1] + pow(ptsX[0],2) + pow(ptsY[1],2) - 2*ptsY[1]*ptsY[0] + pow(ptsY[0],2));
	Y = (ptsY[0]*pow(ptsX[1],2) - ptsX[1]*ptsY[1]*ptsX[0] + ptsY[1]*pow(ptsX[0],2) - ptsX[0]*ptsY[0]*ptsX[1] + pow(ptsY[1],2)*ptsY[2] - 2*ptsY[1]*ptsY[2]*ptsY[0] + pow(ptsY[0],2)*ptsY[2] + ptsX[2]*ptsX[1]*ptsY[1] - ptsX[2]*ptsY[0]*ptsX[1] - ptsX[2]*ptsY[1]*ptsX[0] + ptsX[0]*ptsX[2]*ptsY[0]) / (pow(ptsX[1],2) - 2*ptsX[0]*ptsX[1] + pow(ptsX[0],2) + pow(ptsY[1],2) - 2*ptsY[1]*ptsY[0] + pow(ptsY[0],2));
	K2 = (Y - ptsY[2]) / (X - ptsX[2]);
	K3 = (Y - ptsY[7]) / (X - ptsX[7]);

	DsA = atan((K2 - K3) / (1 + K3*K2)) * 180 / PI;    */
	if (file == NULL)
		return false;

	return true;
}
