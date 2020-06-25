//---------------------------------------------------------------------------
#ifndef PriSpatialCalibrationUnitH
#define PriSpatialCalibrationUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include "_LF.h"
#define NUM_CHESS_POINTS 48
class TPriSpatialCalibration
{
private:
	double m_model[2][3];
	bool MakeModel();
	awpImage* GetInvModel();
protected:
	awpImage* m_531f;
	awpImage* m_570f;
	awp2DPoint m_p531f[NUM_CHESS_POINTS];
	awp2DPoint m_p570f[NUM_CHESS_POINTS];

	bool findPoints();

	awp2DPoint* __fastcall Get531Points();
	awp2DPoint* __fastcall Get570Points();

	double __fastcall GetSourceError();
	double __fastcall GetResultError();

   //	awp2DPoint __fastcall Correct(awp2DPoint p);
public:
	TPriSpatialCalibration();
	~TPriSpatialCalibration();

	bool LoadArchive(UnicodeString path);
	awp2DPoint __fastcall Correct(awp2DPoint p);

	bool SaveCalibration(UnicodeString path);
	bool LoadCalibration(UnicodeString path);

	// выполняет преобразование изображения src
	// в соответствии с моделью пространственной калибровки.
	awpImage* invTransform(awpImage* src);
	awpImage* Transform(awpImage* src);

	__property awpImage* image531f = {read = m_531f};
	__property awpImage* image570f = {read = m_570f};
	__property awp2DPoint* points531 = {read = Get531Points};
	__property awp2DPoint* points570 = {read = Get570Points};
	__property double sourceError = {read = GetSourceError};
	__property double resultError = {read = GetResultError};
};
#endif
