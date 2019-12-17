//----------------------------------------------------------------------------
#ifndef dictinaryEditorH
#define dictinaryEditorH
//----------------------------------------------------------------------------
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Graphics.hpp>
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <Winapi.Windows.hpp>
#include <System.hpp>
#include "_LF.h"
#include "PhImageMarkTool.h"
//----------------------------------------------------------------------------
class TdictinaryEditDlg : public TForm
{
__published:
	TButton *OKBtn;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TListBox *ListBox1;
	TButton *Button4;
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
private:
    TLFSemanticDictinary m_dictionary;
    TLFSemanticDictinary* __fastcall GetSemanticDictionary();
public:
	virtual __fastcall TdictinaryEditDlg(TComponent* AOwner);
    bool    __fastcall CreateDatabase();
    bool    __fastcall EditDatabase(const char* lpFileName);

    __property TLFSemanticDictinary* Dictionary = {read = GetSemanticDictionary};
};
//----------------------------------------------------------------------------
extern PACKAGE TdictinaryEditDlg *dictinaryEditDlg;
//----------------------------------------------------------------------------
#endif
