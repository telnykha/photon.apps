//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "MainUnit.h"
#include "DataModuleUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma classgroup "Vcl.Controls.TControl"
#pragma resource "*.dfm"
TDataModule1 *DataModule1;
//---------------------------------------------------------------------------
__fastcall TDataModule1::TDataModule1(TComponent* Owner)
	: TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDataModule1::DataSource1DataChange(TObject *Sender, TField *Field)

{
     if (ADOTable1ImageName->Value != L"" && MainForm != NULL && MainForm->Model != NULL)
     {
     	 //
         awpPoint p;
         p.X = DataModule1->ADOTable1->FieldByName("left_top_x")->Value;
         p.Y = DataModule1->ADOTable1->FieldByName("left_top_y")->Value;
		 MainForm->Model->LeftTop = p;

         p.X = DataModule1->ADOTable1->FieldByName("right_top_x")->Value;
         p.Y = DataModule1->ADOTable1->FieldByName("right_top_y")->Value;
		 MainForm->Model->RightTop = p;

         p.X = DataModule1->ADOTable1->FieldByName("left_bottom_x")->Value;
         p.Y = DataModule1->ADOTable1->FieldByName("left_bottom_y")->Value;
		 MainForm->Model->LeftBottom = p;

         p.X = DataModule1->ADOTable1->FieldByName("right_bottom_x")->Value;
         p.Y = DataModule1->ADOTable1->FieldByName("right_bottom_y")->Value;
		 MainForm->Model->RightBottom = p;

         p.X = DataModule1->ADOTable1->FieldByName("point1_x")->Value;
         p.Y = DataModule1->ADOTable1->FieldByName("point1_y")->Value;
		 MainForm->Model->Start = p;

         p.X = DataModule1->ADOTable1->FieldByName("point2_x")->Value;
         p.Y = DataModule1->ADOTable1->FieldByName("point2_y")->Value;
		 MainForm->Model->Middle = p;

         p.X = DataModule1->ADOTable1->FieldByName("point3_x")->Value;
         p.Y = DataModule1->ADOTable1->FieldByName("point3_y")->Value;
		 MainForm->Model->End = p;

         MainForm->Model->DoMeasuremet(MainForm->ModelWidth,MainForm->ModelHeight);

        MainForm->Label12->Caption = FormatFloat("###.##", MainForm->Model->Alfa);
        MainForm->Label11->Caption = FormatFloat("###.##", MainForm->Model->X);
        MainForm->Label10->Caption = FormatFloat("###.##", MainForm->Model->Y);
        MainForm->Label9->Caption = FormatFloat("###.##", MainForm->Model->J0);
        MainForm->Label8->Caption = FormatFloat("###.##", MainForm->Model->Jn);
        MainForm->Label7->Caption = MainForm->Model->Quadrant;
        MainForm->Label30->Caption = IntToStr(MainForm->Model->Score);
        MainForm->Label31->Caption = IntToStr(MainForm->Model->Level);
        MainForm->Label32->Caption = MainForm->Model->Comment;
        MainForm->Label33->Caption = MainForm->Model->Comment2;

         UnicodeString str = MainForm->PathToImages;
         str += L"\\";
         str += ADOTable1ImageName->Value;
         AnsiString _ansi = str;
         MainForm->FImage1->Init(_ansi, NULL);
     }
}
//---------------------------------------------------------------------------


void __fastcall TDataModule1::ADOTable4AfterOpen(TDataSet *DataSet)
{
	UpdateWorkTypeCombo();
}
//---------------------------------------------------------------------------

void __fastcall TDataModule1::ADOTable4AfterPost(TDataSet *DataSet)
{
	UpdateWorkTypeCombo();
}
//---------------------------------------------------------------------------
void __fastcall TDataModule1::UpdateWorkTypeCombo()
{
	MainForm->ComboBoxWorkType->Items->Clear();
	MainForm->ComboBoxWorkType->Items->Add("Ыўсющ");
    ADOTable4->First();
    while(!ADOTable4->Eof)
    {
		MainForm->ComboBoxWorkType->Items->Add(ADOTable4->FieldByName("WorkType")->AsString);
		ADOTable4->Next();
    }
	MainForm->ComboBoxWorkType->ItemIndex = 0;
}

void __fastcall TDataModule1::UpdatePsyTestTypeCombo()
{
	MainForm->ComboBoxPsyTestType->Items->Clear();
	MainForm->ComboBoxPsyTestType->Items->Add("Ыўсющ");
    ADOTable6->First();
    while(!ADOTable6->Eof)
    {
		MainForm->ComboBoxPsyTestType->Items->Add(ADOTable6->FieldByName("PsyTestType")->AsString);
		ADOTable6->Next();
    }
	MainForm->ComboBoxPsyTestType->ItemIndex = 0;
}


void __fastcall TDataModule1::ADOTable6AfterOpen(TDataSet *DataSet)
{
	UpdatePsyTestTypeCombo();
}
//---------------------------------------------------------------------------

void __fastcall TDataModule1::ADOTable6AfterPost(TDataSet *DataSet)
{
	UpdatePsyTestTypeCombo();
}
//---------------------------------------------------------------------------
void __fastcall TDataModule1::UpdateNamesCombo()
{
	MainForm->ComboBoxNames->Items->Clear();
	MainForm->ComboBoxNames->Items->Add("Ыўсрџ");
    ADOTable2->First();
    while(!ADOTable2->Eof)
    {
		MainForm->ComboBoxNames->Items->Add(ADOTable2->FieldByName("LastName")->AsString);
		ADOTable2->Next();
    }
	MainForm->ComboBoxNames->ItemIndex = 0;

}

void __fastcall TDataModule1::ADOTable2AfterOpen(TDataSet *DataSet)
{
	UpdateNamesCombo();
}
//---------------------------------------------------------------------------

