//---------------------------------------------------------------------------

#ifndef ProfListUnitH
#define ProfListUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TProfForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TDBNavigator *DBNavigator1;
	TDBGrid *DBGrid1;
private:	// User declarations
public:		// User declarations
	__fastcall TProfForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TProfForm *ProfForm;
//---------------------------------------------------------------------------
#endif
