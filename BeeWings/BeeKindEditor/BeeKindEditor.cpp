//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "BeeKindEditor.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#include "DiaKIND.h"
extern "C"
{
	#pragma link "awpipl2b.lib"
	#pragma link "JPEGLIB.lib"
}
#pragma link "awplflibb.lib"
#pragma link "tinyxml.lib"

TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm1::SpeedButton2Click(TObject *Sender)
{
	 KindEdit->Edit1->Text = "Kind Name";
	 KindEdit->Edit2->Text = 0;
	 KindEdit->Edit3->Text = 0;
	 KindEdit->Edit4->Text = 0;
	 KindEdit->Edit5->Text = 0;
	 KindEdit->Edit6->Text = 0;
	 KindEdit->Edit7->Text = 0;
	 if (KindEdit->ShowModal() == mrOk)
	 {
		BeeKind* kind = new BeeKind("", 0, 0, 0, 0, 0, 0, 0);
		AnsiString a = KindEdit->Edit1->Text;
		int c = KindEdit->ColorGrid1->ForegroundColor;
		kind->SetKindName(a.c_str());
		kind->SetMinCi(StrToFloat(KindEdit->Edit2->Text));
		kind->SetMaxCi(StrToFloat(KindEdit->Edit3->Text));
		kind->SetMinDsA(StrToFloat(KindEdit->Edit4->Text));
		kind->SetMaxDsA(StrToFloat(KindEdit->Edit5->Text));
		kind-> SetMinhi(StrToFloat(KindEdit->Edit6->Text));
		kind->SetmaxHi(StrToFloat(KindEdit->Edit7->Text));
		kind->SetColor(c);
		kind->SetColor(StrToInt(KindEdit->Edit8->Text));
		b.AddBeeKind(kind);
		UpdateTable();
		b.SaveXml("BeeKinds.xml");
	 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton3Click(TObject *Sender)
{
	b.Delete(StringGrid1->Row-1);

	UpdateTable();
    b.SaveXml("BeeKinds.xml");

}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormCreate(TObject *Sender)
{

	StringGrid1->Cells[0][0] = "№";
	StringGrid1->Cells[1][0] = "Порода";
	StringGrid1->Cells[2][0] = "Ci";
	StringGrid1->Cells[3][0] = "DsA";
	StringGrid1->Cells[4][0] = "Hi";


	if (!b.LoadXml("BeeKinds.XML"))
		ShowMessage("Не могу загрузить породы пчел.");
	/*
	BeeKind* bk1 = new BeeKind("Mellifera", 0.76, 2.16, -15.31,0, 0.616, 0.923, 0);

	b.AddBeeKind(bk1);
	UpdateTable();

	BeeKind* bk2 = new BeeKind("Caucasica",1.73,2.75,-2.88,2.88,0.704,1.027,0);
	//BeeKind* bk = new BeeKind("Caucasica", 1.73, 2.75, -2.88,2.88, 0.704, 1.027, 0);
	b.AddBeeKind(bk2);
	UpdateTable();

	BeeKind* bk3 = new BeeKind("Ligustica",2.00,3.29,0.00,4.81,0.923,1.206,0);
	//BeeKind* bk = new BeeKind("Caucasica", 1.73, 2.75, -2.88,2.88, 0.704, 1.027, 0);
	b.AddBeeKind(bk3);
	UpdateTable();

	BeeKind* bk4 = new BeeKind("Carnica",2.16,5.67,0.00,12.39,0.923,1.420,0);
	//BeeKind* bk = new BeeKind("Caucasica", 1.73, 2.75, -2.88,2.88, 0.704, 1.027, 0);
	b.AddBeeKind(bk4);*/
	UpdateTable();

}
//---------------------------------------------------------------------------
void TForm1::UpdateTable(){

	StringGrid1->RowCount = b.GetCount() + 1;
	for (int i = 0; i<b.GetCount();i++)
	{

	   StringGrid1->Cells[0][i+1] = IntToStr(i+1);
	   BeeKind* bk = b.GetBeeKind(i);

	   UnicodeString str = L"("+FormatFloat("0.###", bk->GetMinCi())+ L":" + FormatFloat("0.###", bk->GetMaxCi()) + L")";
	   StringGrid1->Cells[1][i+1] = bk->GetKindName();
	   StringGrid1->Cells[2][i+1] = str;
	   str = L"("+FormatFloat("0.###", bk->GetMinDsA())+ L":" + FormatFloat("0.###", bk->GetMaxDsA()) + L")";
	   StringGrid1->Cells[3][i+1] = str;
	   str = L"("+FormatFloat("0.###", bk->GetMinHi())+ L":" + FormatFloat("0.###", bk->GetMaxHi()) + L")";
	   StringGrid1->Cells[4][i+1] = str;
	   //StringGrid1->Cells[2][i+1] = bk->GetMinCi();

	}
   StringGrid1->Cells[0][0] = "№";
   StringGrid1->Cells[1][0] = "Порода";
   StringGrid1->Cells[2][0] = "Ci";
   StringGrid1->Cells[3][0] = "DsA";
   StringGrid1->Cells[4][0] = "Hi";
   //UpdateTable();
}

void __fastcall TForm1::SpeedButton1Click(TObject *Sender)
{
	double Ci = Edit1->Text.ToDouble();
	double DsA = Edit2->Text.ToDouble();
	double Hi = Edit3->Text.ToDouble();
	BeeKind* result = b.Classify(Ci,DsA,Hi);
	if (result == NULL){
		ShowMessage("Порода не определена!");
	}
	else{
		UnicodeString str = "Ппринадлежность к породе: ";
		str+=result->GetKindName();
		ShowMessage(str);
	}
}
//---------------------------------------------------------------------------






void __fastcall TForm1::Button1Click(TObject *Sender)
{
	int index = StringGrid1->Row-1;
	BeeKind* kind = b.GetBeeKind(index);
	if (kind == NULL){
		return;
	}
	 KindEdit->Edit1->Text = kind->GetKindName();
	 KindEdit->Edit2->Text = kind->GetMinCi();
	 KindEdit->Edit3->Text = kind->GetMaxCi();
	 KindEdit->Edit4->Text = kind->GetMinDsA();
	 KindEdit->Edit5->Text = kind->GetMaxDsA();
	 KindEdit->Edit6->Text = kind->GetMinHi();
	 KindEdit->Edit7->Text = kind->GetMaxHi();
	 KindEdit->ColorGrid1->ForegroundIndex = KindEdit->ColorGrid1->ColorToIndex((TColor)kind->GetColor());
	 if (KindEdit->ShowModal() == mrOk)
	 {
		AnsiString a = KindEdit->Edit1->Text;

		kind->SetKindName(a.c_str());
		kind->SetMinCi(StrToFloat(KindEdit->Edit2->Text));
		kind->SetMaxCi(StrToFloat(KindEdit->Edit3->Text));
		kind->SetMinDsA(StrToFloat(KindEdit->Edit4->Text));
		kind->SetMaxDsA(StrToFloat(KindEdit->Edit5->Text));
		kind-> SetMinhi(StrToFloat(KindEdit->Edit6->Text));
		kind->SetmaxHi(StrToFloat(KindEdit->Edit7->Text));
		kind->SetColor(KindEdit->ColorGrid1->ForegroundColor);
		UpdateTable();
		b.SaveXml("BeeKinds.xml");

	 }
}
//---------------------------------------------------------------------------

