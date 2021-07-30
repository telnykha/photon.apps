//---------------------------------------------------------------------------

#ifndef mainUnitH
#define mainUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.FileCtrl.hpp>
#include "FImage41.h"
#include "_LF.h"
//---------------------------------------------------------------------------
class TForm9 : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TPanel *Panel2;
	TPhImage *PhImage1;
	TDirectoryListBox *DirectoryListBox1;
	TSplitter *Splitter1;
	TPanel *Panel3;
	TDriveComboBox *DriveComboBox1;
	TFileListBox *FileListBox1;
	TSplitter *Splitter2;
	void __fastcall FileListBox1Change(TObject *Sender);
	void __fastcall PhImage1AfterOpen(TObject *Sender);
	void __fastcall DirectoryListBox1Change(TObject *Sender);
	void __fastcall PhImage1Paint(TObject *Sender);
private:	// User declarations
	TLFDBLandmarks m_db;
	void __fastcall DrawLandmarks();
public:		// User declarations
	__fastcall TForm9(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm9 *Form9;
//---------------------------------------------------------------------------
#endif
