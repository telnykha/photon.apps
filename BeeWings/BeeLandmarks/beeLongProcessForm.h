//---------------------------------------------------------------------------

#ifndef beeLongProcessFormH
#define beeLongProcessFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TProgressBar *ProgressBar1;
	TTimer *Timer1;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
private:	// User declarations
	bool    m_replace;
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
    __property bool replace = {read = m_replace, write= m_replace};

};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
