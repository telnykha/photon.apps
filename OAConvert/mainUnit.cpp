//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "mainUnit.h"
#include "SelDirUnit.h"
#include "OA_tiff_io.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FImage41"
#pragma resource "*.dfm"
TForm7 *Form7;
//---------------------------------------------------------------------------
__fastcall TForm7::TForm7(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm7::Button1Click(TObject *Sender)
{
	String _dir = "";
	if (GetDirNamePreview(_dir))
	{
	   // make file list
		TSearchRec sr;
		String strPath = _dir;
		strPath += "\\*.tiff";
		int iAttr =0;
		iAttr |= faAnyFile;
		int count = 0;
		if (FindFirst(strPath, iAttr, sr) == 0)
		{
			do
			{
				AnsiString strName =  _dir + "\\" + sr.Name;
				if (CheckOAOpenTIFFImage(strName.c_str())) {
					count++;
				}
				else
				{
					ShowMessage("Invalid OA tiff database.");
				}
			}while(FindNext(sr) == 0);
			FindClose(sr);
		}

		if (count == 0) {
			ShowMessage("Invalid OA tiff database.");
		}
		else
		{
            ShowMessage("Count = " + IntToStr(count));
		}
	}
}
//---------------------------------------------------------------------------
