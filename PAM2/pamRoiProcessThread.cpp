//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop

#include "pamRoiProcessThread.h"
#include "pamImageProcessor.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall Tpam2RoiProcessThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall Tpam2RoiProcessThread::Tpam2RoiProcessThread(bool CreateSuspended)
	: TThread(CreateSuspended)
{
	m_pdoc= NULL;
	m_roi = NULL;
}
//---------------------------------------------------------------------------
void __fastcall Tpam2RoiProcessThread::Execute()
{
	//---- Place thread code here ----
	if (m_pdoc == NULL || m_roi == NULL) {
		return;
	}
	m_roi->Locked = true;
	awpImage* fo = NULL;
	awpImage* fm = NULL;

	TPam2ImageProcessor proc;

	AnsiString strfo = m_pdoc->GetFoName();
	AnsiString strfm = m_pdoc->GetFmName();

	awpLoadImage(strfo.c_str(), &fo);
	awpLoadImage(strfm.c_str(), &fm);
	proc.SetFoFm(fo,fm);

	for(int i = 0; i < m_pdoc->NumFrames; i++)
	{
		awpImage* ft = NULL;
		awpImage* fm1 = NULL;
		AnsiString strft = m_pdoc->GetFtName(i);
		AnsiString strfm1 = m_pdoc->GetFm1Name(i);

		awpLoadImage(strfo.c_str(), &ft);
		awpLoadImage(strfm.c_str(), &fm1);
		proc.SetFtFm1(ft,fm1);

		awpImage* img = proc.GetFo();
		awpReleaseImage(&img);

		img = proc.GetFm();
		awpReleaseImage(&img);

		img = proc.GetFt();
		awpReleaseImage(&img);

		img = proc.GetFm1();
		awpReleaseImage(&img);

		img = proc.GetFv();
		awpReleaseImage(&img);

		img = proc.GetFv1();
		awpReleaseImage(&img);

		img = proc.GetFq1();
		awpReleaseImage(&img);

		img = proc.GetFo1();
		awpReleaseImage(&img);

		img = proc.GetYII1();
		awpReleaseImage(&img);

		img = proc.GetNPQ1();
		awpReleaseImage(&img);


		awpReleaseImage(&ft);
		awpReleaseImage(&fm1);

	}

	awpReleaseImage(&fo);
	awpReleaseImage(&fm);

}
//---------------------------------------------------------------------------
