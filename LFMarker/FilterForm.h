//----------------------------------------------------------------------------
#ifndef FilterFormH
#define FilterFormH
//----------------------------------------------------------------------------
#include <System.hpp>
#include <Windows.hpp>
#include <SysUtils.hpp>
#include <Classes.hpp>
#include <Graphics.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Controls.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include "FImage.h"
#include <ComCtrls.hpp>
#include "CSPIN.h"
//----------------------------------------------------------------------------
class TFilterDlg : public TForm
{
__published:        
	TButton *OKBtn;
	TButton *CancelBtn;
	TBevel *Bevel1;
        TFImage *FImage1;
	TListBox *ListBox1;
        void __fastcall FormShow(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ListBox1Click(TObject *Sender);
private:
    awpImage* m_image;
public:
	virtual __fastcall TFilterDlg(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern PACKAGE TFilterDlg *FilterDlg;
//----------------------------------------------------------------------------
#endif    
