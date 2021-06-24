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
    m_roi->ClearFrames();
	for(int i = 0; i < m_pdoc->NumFrames; i++)
	{
		TPam2ROIFrame* frame = new TPam2ROIFrame();
		awpImage* ft = NULL;
		awpImage* fm1 = NULL;
		AnsiString strft = m_pdoc->GetFtName(i);
		AnsiString strfm1 = m_pdoc->GetFm1Name(i);

		awpLoadImage(strft.c_str(), &ft);
		awpLoadImage(strfm1.c_str(), &fm1);
		proc.SetFtFm1(ft,fm1);
		//Fo
		awpImage* img = proc.GetFo();
		m_roi->Calculate(img);
		TPam2ROIData* data = m_roi->Data;
		frame->Fo = data;
		awpReleaseImage(&img);
		// Fm
		img = proc.GetFm();
		m_roi->Calculate(img);
		data = m_roi->Data;
		frame->Fm = data;
		awpReleaseImage(&img);
		// Ft
		img = proc.GetFt();
		m_roi->Calculate(img);
		data = m_roi->Data;
		frame->Ft = data;
		awpReleaseImage(&img);
		//Fm1
		img = proc.GetFm1();
		m_roi->Calculate(img);
		data = m_roi->Data;
		frame->Fm1 = data;
		awpReleaseImage(&img);
		//Fv
		img = proc.GetFv();
		m_roi->Calculate(img);
		data = m_roi->Data;
		frame->Fv = data;
		awpReleaseImage(&img);
		//Fv
		img = proc.GetFv1();
		m_roi->Calculate(img);
		data = m_roi->Data;
		frame->Fv1 = data;
		awpReleaseImage(&img);
		//Fq1
		img = proc.GetFq1();
		m_roi->Calculate(img);
		data = m_roi->Data;
		frame->Fq1 = data;
		awpReleaseImage(&img);
		//Fo1
		img = proc.GetFo1();
		m_roi->Calculate(img);
		data = m_roi->Data;
		frame->Fo1 = data;
		awpReleaseImage(&img);
		//YII
		img = proc.GetYII1();
		m_roi->Calculate(img);
		data = m_roi->Data;
		frame->YII1 = data;
		awpReleaseImage(&img);
		//NPQ
		img = proc.GetNPQ1();
		m_roi->Calculate(img);
		data = m_roi->Data;
		frame->NPQ1= data;
		awpReleaseImage(&img);

		m_roi->AddFrame(frame);

		awpReleaseImage(&ft);
		awpReleaseImage(&fm1);

	}

	awpReleaseImage(&fo);
	awpReleaseImage(&fm);

}
//---------------------------------------------------------------------------
