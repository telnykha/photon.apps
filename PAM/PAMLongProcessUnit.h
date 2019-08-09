//---------------------------------------------------------------------------

#ifndef PAMLongProcessUnitH
#define PAMLongProcessUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Samples.Gauges.hpp>
#include "PAMThreadUnit.h"
//---------------------------------------------------------------------------
class TPAMLongProcessForm : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TGauge *Gauge1;
	TLabel *Label1;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
    bool m_cancel;
    TPAMThread* m_thread;
    bool m_success;
	void __fastcall OnTerminateHelper(TObject *Sender);
public:		// User declarations
	__fastcall TPAMLongProcessForm(TComponent* Owner);
    void __fastcall Execute();
};
//---------------------------------------------------------------------------
extern PACKAGE TPAMLongProcessForm *PAMLongProcessForm;
//---------------------------------------------------------------------------
#endif
