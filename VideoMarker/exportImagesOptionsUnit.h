//----------------------------------------------------------------------------
#ifndef exportImagesOptionsUnitH
#define exportImagesOptionsUnitH
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
#include <Vcl.FileCtrl.hpp>
//----------------------------------------------------------------------------
class TexportImagesDlg : public TForm
{
__published:
	TButton *OKBtn;
	TButton *CancelBtn;
	TDriveComboBox *DriveComboBox1;
	TDirectoryListBox *DirectoryListBox1;
	TRadioGroup *RadioGroup1;
	TGroupBox *GroupBox1;
	TLabel *Label1;
	TEdit *Edit1;
	TLabel *Label2;
	TEdit *Edit2;
	void __fastcall Edit1Exit(TObject *Sender);
	void __fastcall Edit1Enter(TObject *Sender);
	void __fastcall Edit1Change(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall DirectoryListBox1Change(TObject *Sender);
private:
    int m_oldValue;
    int m_value;
    void __fastcall ValueChanged();
    UnicodeString __fastcall GetExportDir();
    UnicodeString __fastcall GetExt();
public:
	virtual __fastcall TexportImagesDlg(TComponent* AOwner);

    __property UnicodeString exportDir = {read = GetExportDir};
    __property int value = {read = m_value};
    __property UnicodeString ext = {read = GetExt};
};
//----------------------------------------------------------------------------
extern PACKAGE TexportImagesDlg *exportImagesDlg;
//----------------------------------------------------------------------------
#endif    
