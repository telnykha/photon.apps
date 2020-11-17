//---------------------------------------------------------------------------

#ifndef LongProcessFormH
#define LongProcessFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "PhVideoMarkTool.h"
#include "ExportVideoThread.h"
#include "ExportImagesThread.h"
//---------------------------------------------------------------------------
typedef enum {
    nothing,
    exportVideo,
    exportImages,
    exportToLFDatabase,
}ELongJob;

class TLongProcDlg : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TProgressBar *ProgressBar1;
	TTimer *Timer1;
	TLabel *Label2;
	TButton *Button1;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
    TPhVideoMarkTool* m_tool;
    AnsiString m_str;
    TExportVideoThread* 	m_exportVideo;
    TExportImagesThread*    m_exportImages;
    ELongJob    m_job;
public:		// User declarations
	__fastcall TLongProcDlg(TComponent* Owner);
    void __fastcall DoIt(TPhVideoMarkTool* tool, const char* path);
    void __fastcall DoExportVideo(UnicodeString fileName);
    void __fastcall DoExportImages(UnicodeString outDir, UnicodeString ext, int frequency);
	void __fastcall ProgressHandler(TObject *Sender, int Progress, String& aComment);
};
//---------------------------------------------------------------------------
extern PACKAGE TLongProcDlg *LongProcDlg;
//---------------------------------------------------------------------------
#endif
