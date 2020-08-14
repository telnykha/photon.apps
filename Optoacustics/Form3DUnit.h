//---------------------------------------------------------------------------

#ifndef Form3DUnitH
#define Form3DUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "Cube3D.h"
#include "cspin.h"
//---------------------------------------------------------------------------
class TForm3DView : public TForm
{
__published:	// IDE-managed Components
	TPaintBox *PaintBox1;
	TPanel *Panel1;
	TCSpinEdit *CSpinEdit1;
	TCheckBox *CheckBox1;
	void __fastcall FormHide(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall PaintBox1Paint(TObject *Sender);
	void __fastcall PaintBox1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall PaintBox1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall PaintBox1MouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall CSpinEdit1Change(TObject *Sender);
	void __fastcall CheckBox1Click(TObject *Sender);

private:	// User declarations
	T3DTransform 		t;

	bool 	m_mdown;
	int	    m_dx;
	int 	m_dy;

public:		// User declarations
	__fastcall TForm3DView(TComponent* Owner);

	void __fastcall DrawCube(TCanvas* cnv);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3DView *Form3DView;
//---------------------------------------------------------------------------
#endif
