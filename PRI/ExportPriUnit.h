//----------------------------------------------------------------------------
#ifndef ExportPriUnitH
#define ExportPriUnitH
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
#include "PriProcessor.h"
//----------------------------------------------------------------------------
class TExportPriDlg : public TForm
{
__published:
	TButton *OKBtn;
	TButton *CancelBtn;
	TBevel *Bevel1;
	TDriveComboBox *DriveComboBox1;
	TDirectoryListBox *DirectoryListBox1;
	TButton *Button1;
	TRadioGroup *RadioGroup1;
	TCheckBox *CheckBox1;
	TCheckBox *CheckBox2;
	void __fastcall Button1Click(TObject *Sender);
private:
public:
	virtual __fastcall TExportPriDlg(TComponent* AOwner);
	EPriBlurMode GetPriBlurMode();

};
//----------------------------------------------------------------------------
extern PACKAGE TExportPriDlg *ExportPriDlg;
//----------------------------------------------------------------------------
#endif    
