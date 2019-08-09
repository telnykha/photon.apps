//----------------------------------------------------------------------------
#ifndef optionsUnitH
#define optionsUnitH
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
#include <Vcl.ComCtrls.hpp>
#include <Vcl.FileCtrl.hpp>
//----------------------------------------------------------------------------
class TOptionsDlg : public TForm
{
__published:
	TButton *OKBtn;
	TButton *CancelBtn;
	TBevel *Bevel1;
	TLabel *Label2;
	TDirectoryListBox *DirectoryListBox1;
	TDriveComboBox *DriveComboBox1;
	TCheckBox *CheckBox1;
private:
public:
	virtual __fastcall TOptionsDlg(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern PACKAGE TOptionsDlg *OptionsDlg;
//----------------------------------------------------------------------------
#endif    
