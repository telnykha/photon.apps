//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "BeeAnalysisForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{

}




void __fastcall TForm2::FormCreate(TObject *Sender)
{
    StringGrid1->RowCount = 26;
	StringGrid1->ColCount = 4;
	StringGrid1->Cells[0][0] = "¹";
	StringGrid1->Cells[1][0] = "Ci";
	StringGrid1->Cells[2][0] = "DsA";
	StringGrid1->Cells[3][0] = "Hi";
	TStringList * Lst = new TStringList;
	Lst->LoadFromFile("D:\\StringGrid.txt");
	int Index=0;
	for(int j=1;j<StringGrid1->RowCount;j++)
	for(int i=0;i<StringGrid1->ColCount;i++)
	{
		StringGrid1->Cells[i][j]=Lst->Strings[Index];
		Index++;
	}
	delete Lst;
}
//---------------------------------------------------------------------------
