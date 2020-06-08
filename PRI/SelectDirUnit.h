//----------------------------------------------------------------------------
#ifndef SelectDirUnitH
#define SelectDirUnitH
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
class TSelectDirDlg : public TForm
{
__published:
	TButton *OKBtn;
	TButton *CancelBtn;
	TDirectoryListBox *DirectoryListBox1;
	TDriveComboBox *DriveComboBox1;
	TButton *Button1;
	void __fastcall Button1Click(TObject *Sender);
private:
public:
	virtual __fastcall TSelectDirDlg(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern PACKAGE TSelectDirDlg *SelectDirDlg;
//----------------------------------------------------------------------------
#endif    
