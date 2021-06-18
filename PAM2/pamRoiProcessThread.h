//---------------------------------------------------------------------------

#ifndef pamRoiProcessThreadH
#define pamRoiProcessThreadH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include "pamDocumentUnit.h"
#include "pamROI.h"
//---------------------------------------------------------------------------
class Tpam2RoiProcessThread : public TThread
{
private:
	TPam2Document* m_pdoc;
	TPam2ROI* m_roi;
protected:
	void __fastcall Execute();
public:
	__fastcall Tpam2RoiProcessThread(bool CreateSuspended);

	__property TPam2Document* doc = {read = m_pdoc, write = m_pdoc};
    __property TPam2ROI* roi = {read=  m_roi, write = m_roi};
};
//---------------------------------------------------------------------------
#endif
