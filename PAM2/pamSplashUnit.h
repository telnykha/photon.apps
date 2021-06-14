//---------------------------------------------------------------------------

#ifndef pamSplashUnitH
#define pamSplashUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.GIFImg.hpp>
#include <Vcl.Imaging.jpeg.hpp>
//---------------------------------------------------------------------------
class TpamSplashForm : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
	TPanel *Panel1;
	TPanel *Panel2;
private:	// User declarations
public:		// User declarations
	__fastcall TpamSplashForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TpamSplashForm *pamSplashForm;
//---------------------------------------------------------------------------
#endif
