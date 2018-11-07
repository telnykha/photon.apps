//---------------------------------------------------------------------------

#ifndef DataModuleUnitH
#define DataModuleUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
//---------------------------------------------------------------------------
class TDataModule1 : public TDataModule
{
__published:	// IDE-managed Components
	TADOConnection *ADOConnection1;
	TDataSource *DataSource1;
	TADOTable *ADOTable10;
	TWideStringField *ADOTable10FirstName;
	TWideStringField *ADOTable10LastName;
	TWideStringField *ADOTable10Gender;
	TIntegerField *ADOTable10Age;
	TWideStringField *ADOTable10WorkType;
	TWideStringField *ADOTable10PsyTestType;
	TADOTable *ADOTable2;
	TDataSource *DataSource2;
	TAutoIncField *ADOTable2UserId;
	TWideStringField *ADOTable2FirstName;
	TWideStringField *ADOTable2LastName;
	TIntegerField *ADOTable2Age;
	TIntegerField *ADOTable2WorkTypeId;
	TIntegerField *ADOTable2GenderId;
	TDataSource *DataSource3;
	TADOTable *ADOTable3;
	TAutoIncField *ADOTable3GenderId;
	TWideStringField *ADOTable3Gender;
	TDataSource *DataSource4;
	TADOTable *ADOTable4;
	TAutoIncField *ADOTable4WorkTypeId;
	TWideStringField *ADOTable4WorkType;
	TDataSource *DataSource5;
	TADOTable *ADOTable5;
	TAutoIncField *ADOTable5PsyTestId;
	TWideStringField *ADOTable5ImageName;
	TIntegerField *ADOTable5UserId;
	TIntegerField *ADOTable5TestId;
	TIntegerField *ADOTable5left_top_x;
	TIntegerField *ADOTable5left_top_y;
	TIntegerField *ADOTable5right_top_x;
	TIntegerField *ADOTable5right_top_y;
	TIntegerField *ADOTable5right_bottom_x;
	TIntegerField *ADOTable5right_bottom_y;
	TIntegerField *ADOTable5left_bottom_x;
	TIntegerField *ADOTable5left_bottom_y;
	TIntegerField *ADOTable5point1_x;
	TIntegerField *ADOTable5point1_y;
	TIntegerField *ADOTable5point2_x;
	TIntegerField *ADOTable5point2_y;
	TIntegerField *ADOTable5point3_x;
	TIntegerField *ADOTable5point3_y;
	TDataSource *DataSource6;
	TADOTable *ADOTable6;
	TAutoIncField *ADOTable6PsyTestTypesId;
	TWideStringField *ADOTable6PsyTestType;
	TWideStringField *ADOTable10ImageName;
	TIntegerField *ADOTable10left_top_x;
	TIntegerField *ADOTable10left_top_y;
	TIntegerField *ADOTable10right_top_x;
	TIntegerField *ADOTable10right_top_y;
	TIntegerField *ADOTable10right_bottom_x;
	TIntegerField *ADOTable10right_bottom_y;
	TIntegerField *ADOTable10left_bottom_x;
	TIntegerField *ADOTable10left_bottom_y;
	TIntegerField *ADOTable10point3_x;
	TIntegerField *ADOTable10point2_x;
	TIntegerField *ADOTable10point2_y;
	TIntegerField *ADOTable10point3_y;
	TIntegerField *ADOTable10point1_y;
	TIntegerField *ADOTable10point1_x;
	TAutoIncField *ADOTable10PsyTestId;
	TADOQuery *ADOTable1;
	TWideStringField *ADOTable1FirstName;
	TWideStringField *ADOTable1LastName;
	TWideStringField *ADOTable1Gender;
	TIntegerField *ADOTable1Age;
	TWideStringField *ADOTable1WorkType;
	TWideStringField *ADOTable1PsyTestType;
	TWideStringField *ADOTable1ImageName;
	TIntegerField *ADOTable1left_top_x;
	TIntegerField *ADOTable1left_top_y;
	TIntegerField *ADOTable1right_top_x;
	TIntegerField *ADOTable1right_top_y;
	TIntegerField *ADOTable1right_bottom_x;
	TIntegerField *ADOTable1right_bottom_y;
	TIntegerField *ADOTable1left_bottom_x;
	TIntegerField *ADOTable1left_bottom_y;
	TIntegerField *ADOTable1point3_x;
	TIntegerField *ADOTable1point2_x;
	TIntegerField *ADOTable1point2_y;
	TIntegerField *ADOTable1point3_y;
	TIntegerField *ADOTable1point1_y;
	TIntegerField *ADOTable1point1_x;
	TAutoIncField *ADOTable1PsyTestId;
	void __fastcall DataSource1DataChange(TObject *Sender, TField *Field);
	void __fastcall ADOTable4AfterOpen(TDataSet *DataSet);
	void __fastcall ADOTable4AfterPost(TDataSet *DataSet);
	void __fastcall ADOTable6AfterOpen(TDataSet *DataSet);
	void __fastcall ADOTable6AfterPost(TDataSet *DataSet);
	void __fastcall ADOTable2AfterOpen(TDataSet *DataSet);
private:	// User declarations

public:		// User declarations
	__fastcall TDataModule1(TComponent* Owner);

	void __fastcall UpdateWorkTypeCombo();
    void __fastcall UpdatePsyTestTypeCombo();
    void __fastcall UpdateNamesCombo();
};
//---------------------------------------------------------------------------
extern PACKAGE TDataModule1 *DataModule1;
//---------------------------------------------------------------------------
#endif
