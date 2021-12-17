// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "BeeAnalysisForm.h"
#include "BeeKinds.h"
#include "BeeFeatures.h"
// #include "Signs.cpp"

// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

extern "C" {
#pragma link "awpipl2b.lib"
#pragma link "JPEGLIB.lib"
}
#pragma link "awplflibb.lib"
#pragma link "tinyxml.lib"

TAnalysisForm *AnalysisForm;

// ---------------------------------------------------------------------------
__fastcall TAnalysisForm::TAnalysisForm(TComponent* Owner) : TForm(Owner) {

}

void __fastcall TAnalysisForm::FormCreate(TObject *Sender) {
	// WebBrowser1->Navigate(L"www.google.com");
	StringGrid1->Cells[0][0] = "Name";
	StringGrid1->Cells[1][0] = "Ci";
	StringGrid1->Cells[2][0] = "DsA";
	StringGrid1->Cells[3][0] = "Hi";
	//StringGrid3->ColCount = 1;
	UnicodeString strName = ExtractFilePath(Application->ExeName);
	strName += L"\\1.xml";
	AnsiString _ansi = strName;

	if (!b.LoadXml(_ansi.c_str()))
		ShowMessage("Не могу загрузить породы пчел.");
	else {

		for (int i = 0; i < b.GetCount(); i++) {
			TChartShape *CiDsASeries = new TChartShape(NULL);
			CiDsASeries->Clear();
			BeeKind* bk = b.GetBeeKind(i);
			CiDsASeries->Style = chasCube;
			CiDsASeries->SeriesColor = bk->GetColor();
			CiDsASeries->Legend->Visible = false;
			//Chart4->Title->Text = 1;
			CiDsASeries->Transparent = true;
			CiDsASeries->X0 = bk->GetMinDsA();
			CiDsASeries->X1 = bk->GetMaxDsA();
			CiDsASeries->Y0 = bk->GetMinCi();
			CiDsASeries->Y1 = bk->GetMaxCi();

			CiDsASeries->Pen->Color = bk->GetColor();
			CiDsASeries->Pen->Width = 3;
			Chart4->AddSeries(CiDsASeries);

		}
		for (int i = 0; i < b.GetCount(); i++) {
			TChartShape *CiHiSeries = new TChartShape(NULL);
			BeeKind* bk = b.GetBeeKind(i);
			CiHiSeries->Style = chasCube;
			CiHiSeries->Transparent = true;
			CiHiSeries->Legend->Visible = false;
			//Chart5->Title->Text = "Ci Hi";
			CiHiSeries->SeriesColor = bk->GetColor();
			CiHiSeries->X0 = bk->GetMinCi();
			CiHiSeries->X1 = bk->GetMaxCi();
			CiHiSeries->Y0 = bk->GetMinHi();
			CiHiSeries->Y1 = bk->GetMaxHi();
			Chart5->AddSeries(CiHiSeries);
			CiHiSeries->Pen->Color = bk->GetColor();
			CiHiSeries->Pen->Width = 3;
		}

		for (int i = 0; i < b.GetCount(); i++) {
			TChartShape *DsAHiSeries = new TChartShape(NULL);
			BeeKind* bk = b.GetBeeKind(i);
			DsAHiSeries->Style = chasCube;
			DsAHiSeries->Transparent = true;
			DsAHiSeries->Legend->Visible = false;
			//Chart6->Title->Text = "DsA Hi";
			DsAHiSeries->Color = bk->GetColor();
			DsAHiSeries->X0 = bk->GetMinDsA();
			DsAHiSeries->X1 = bk->GetMaxDsA();
			DsAHiSeries->Y0 = bk->GetMinHi();
			DsAHiSeries->Y1 = bk->GetMaxHi();
			DsAHiSeries->Pen->Color = bk->GetColor();
			DsAHiSeries->Pen->Width = 3;
			Chart6->AddSeries(DsAHiSeries);

		}

		// }

	}

}
// ---------------------------------------------------------------------------
void __fastcall TAnalysisForm::N2Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TAnalysisForm::PopupMenu11Click(TObject *Sender)
{
	if (OpenDialog1->Execute())
	{
	   TLFDBLandmarks d;
	   AnsiString _ansi =  OpenDialog1->FileName;
	   if (d.Connect(_ansi.c_str()))
	   {
			_ansi = ExtractFilePath(OpenDialog1->FileName);
			Update(_ansi.c_str(), &d);
	   }
	   else
		  ShowMessage(L"Не могу прочитать базу данных " + OpenDialog1->FileName);
	}
}


//---------------------------------------------------------------------------
void TAnalysisForm::Update(const char* path, TLFDBLandmarks* db)
{
	Series16->Clear();
	Series8->Clear();
	Series9->Clear();
	Series1->Clear();
	Series2->Clear();
	Series3->Clear();
	Series4->Clear();
	Series5->Clear();
	Series6->Clear();
	hstCI.Setup(26, 0.76, 5.67);
	hstDsA.Setup(29, -15.31, 12.39);
	hstHI.Setup(31, 0.616, 1.42);




	StringGrid1->RowCount = db->Files()->Count() + 1;
	StringGrid3->RowCount = db->Files()->Count() + 1;
	for (int i = 0; i < b.GetCount(); i++)
	{
		StringGrid3->Cells[i+1][0] = b.GetBeeKind(i)->GetKindName();
	}

	for (int i=0; i < db->Files()->Count();i++)
		{

			double Ci, DsA, Hi;
			Ci = 0;
			DsA = 0;
			Hi = 0;
			GetBeeFeatures(path, db->Files()->File(i), Ci, DsA, Hi);
			StringGrid1->Cells[0][i+1] = db->Files()->File(i)->FileName();
			StringGrid3->Cells[0][i+1] = db->Files()->File(i)->FileName();
			StringGrid1->Cells[1][i+1] = FormatFloat("0.###",Ci);
			StringGrid1->Cells[2][i+1] = FormatFloat("0.###",DsA);
			StringGrid1->Cells[3][i+1] = FormatFloat("0.###",Hi);
			Series16->AddXY(Ci,Hi);
			Series8->AddXY(DsA,Hi);
			Series9->AddXY(DsA,Ci);
			hstCI.AddElememt(Ci);
			hstDsA.AddElememt(DsA);
			hstHI.AddElememt(Hi);


			Series1->AddXY(i*(5.67 - 0.76) / 26 + 0.76, hstCI.GetBin(i));
			Series6->AddXY(i*(5.67 - 0.76) / 26 + 0.76, hstCI.GetBin(i));
			Series2->AddXY(i*(12.39 + 15.31) / 29 - 15.31, hstDsA.GetBin(i));
			Series3->AddXY(i*(12.39 + 15.31) / 29 - 15.31, hstDsA.GetBin(i));
			Series4->AddXY(i*(1.42 - 0.616) / 31 + 0.616, hstHI.GetBin(i));
			Series5->AddXY(i*(1.42 - 0.616) / 31 + 0.616, hstHI.GetBin(i));


			BeeKinds result;
			b.New_Classify(Ci,DsA,Hi,&result);
			StringGrid3->ColCount = b.GetCount()+1;

			if (result.GetCount() == 0){
				//ShowMessage("Порода не отпределена!");
			}
			else
			{
				for (int j = 0; j < result.GetCount(); j++)
				{

					int number = int(b.GetKindIndex(result.GetBeeKind(j)->GetKindName()));
					if (number>=0)
						StringGrid3->Cells[number+1][i+1] = result.GetBeeKind(j)->GetKindName();

				}

			}

		}

}

