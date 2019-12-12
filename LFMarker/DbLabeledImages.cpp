//---------------------------------------------------------------------------
// database of labeled images
// ver 1.0
// implementation of TDbLabeledImages

#pragma hdrstop
#include <math.h>
#include "DbLabeledImages.h"
#include "_LF.h"
#include "MainForm.h"
#include "awpipl.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)

static bool _IsImageFile(UnicodeString& strFileName)
{
	UnicodeString strExt = ExtractFileExt(strFileName);
	strExt = strExt.LowerCase();

	if (strExt == ".awp")
		return true;
	if (strExt == ".jpg")
		return true;
	if (strExt == ".jpeg")
		return true;
	if (strExt == ".png")
		return true;
	if (strExt == ".bmp")
		return true;
	return false;
}
/*
	проверяет, имеет ли файл изображения strFileName
	какое-либо из описаний.
*/
static bool _HasDescription(UnicodeString& strFileName)
{
  if (!_IsImageFile(strFileName))
	return false;

  if (FileExists(ChangeFileExt(strFileName, ".ieye")))
	  return true;
  if (FileExists(ChangeFileExt(strFileName, ".xml")))
	  return true;
  if (FileExists(ChangeFileExt(strFileName, ".face")))
	  return true;

  return false;
}

// очищает каталог.
static bool ClearDir(AnsiString& strDir)
{
  if (DirectoryExists(strDir))
  {
	// удалим все файлы в каталоге
	TSearchRec sr;
	AnsiString strPath = strDir;
	strPath += "\\*.*";
	int iAttr =0;
	iAttr |= faAnyFile;
	if (FindFirst(strPath, iAttr, sr) == 0)
	{
		do
		{
		  AnsiString strName =  strDir + "\\" + sr.Name;
		  DeleteFile(strName);
		}while(FindNext(sr) == 0);
		FindClose(sr);
	}
  }
  else
	CreateDir(strDir);
  return true;

}

static bool ClearDirWithSubdirs(AnsiString& strDir, TStringList* subdirs)
{
	AnsiString strMessage = "All files in the \n";
	strMessage += strDir;
	strMessage += "\n will be deteled. Are You sure?";
	if (MessageDlg(strMessage, mtWarning, TMsgDlgButtons() << mbYes << mbNo,0 ) == mrNo)
		return true;

  if (DirectoryExists(strDir))
  {
    for (int i = 0; i < subdirs->Count; i++)
    {
    	AnsiString strPath = strDir + "\\" + subdirs->Strings[i] + "\\";
        if (DirectoryExists(strPath))
        {
            ClearDir(strPath);
          //  RemoveDir(strPath);
        }
        else
			CreateDir(strPath);
    }
  }
  else
  {
	CreateDir(strDir);
    for (int i = 0; i < subdirs->Count; i++)
    {
    	AnsiString strPath = strDir + "\\" + subdirs->Strings[i] + "\\";
		CreateDir(strPath);
    }
  }
  return true;
}

TLFDbItem::TLFDbItem()
{
	m_strFileName = "";
	m_hasXml = false;
	m_hasIeye = false;
	m_hasFace = false;
	m_selected = false;
}
TLFDbItem::~TLFDbItem()
{

}
const char* TLFDbItem::GetFileName()
{
	return m_strFileName.c_str();
}

bool __fastcall TLFDbItem::Init(const char* lpFileName)
{
	if (lpFileName == NULL)
		return false;
	UnicodeString str = lpFileName;
	if (!FileExists(str))
		return false;
	this->m_hasFace = FileExists(ChangeFileExt(str, L".face"));
	this->m_hasIeye = FileExists(ChangeFileExt(str, L".ieye"));
	this->m_hasXml  = FileExists(ChangeFileExt(str, L".xml"));
	this->m_selected = false;
	this->m_strFileName = lpFileName;
}

void __fastcall TLFDbItem::Delete()
{
	UnicodeString str = m_strFileName.c_str();
	if (FileExists(str))
		DeleteFile(str);
	if (FileExists(ChangeFileExt(str, L".face")))
		DeleteFile(ChangeFileExt(str, L".face"));
	if (FileExists(ChangeFileExt(str, L".ieye")))
		DeleteFile(ChangeFileExt(str, L".ieye"));
	if (FileExists(ChangeFileExt(str, L".xml")))
		DeleteFile(ChangeFileExt(str, L".xml"));
}


TLFDbSemanticItem::TLFDbSemanticItem()
{
	m_item = NULL;
	m_strFileName = "";
	m_selected = false;
}
TLFDbSemanticItem::~TLFDbSemanticItem()
{
	if (m_item != NULL)
		delete m_item;
}

bool __fastcall TLFDbSemanticItem::Init(const char* lpFileName, TLFDetectedItem* itm)
{
	if (lpFileName == NULL || itm == NULL)
		return false;

	m_strFileName = lpFileName;
	m_selected = false;
	if (m_item != NULL)
		delete m_item;
	m_item = new TLFDetectedItem(itm);
	return true;
}

const char* TLFDbSemanticItem::GetFileName()
{
	return m_strFileName.c_str();
}
awpImage*   TLFDbSemanticItem::GetImage()
{
	awpImage* source = NULL;
	if (awpLoadImage(m_strFileName.c_str(), &source) != AWP_OK)
		return NULL;
	 awpRect rect = m_item->GetBounds()->GetRect();
	 awpImage* result = NULL;
	 awpCopyRect(source, &result, &rect);
	_AWP_SAFE_RELEASE_(source)

	return result;
}
////////////////////////////////////////////////////////////////////////////////
TDbLabeledImages::TDbLabeledImages()
{
	Clear();
	m_ProgressEvent = NULL;
}
/////////////////////////////////////
TDbLabeledImages::~TDbLabeledImages()
{
}
////////////////////////////////////////
void __fastcall TDbLabeledImages::Clear()
{
    m_strDbName = "";
	m_NumImages = 0;
    m_NumEyeFiles =0;
    m_NumEyeItems =0;
    m_NumFaceFiles = 0;
    m_NumXmlFiles =0;
    m_NumXmlItems =0;
	m_engine = NULL;
	m_dataFiles.Clear();
	m_dataItems.Clear();
}
//////////////////////////////////////////////////////////////////////////////////////
void __fastcall TDbLabeledImages::Init(AnsiString& strDbPath, ILFDetectEngine* engine)
{
     //Init dictionary
     AnsiString strDictionaryName = strDbPath;
	 strDictionaryName += "\\";
     strDictionaryName += "dictionary.xml";

     this->m_dictionary.Clear();
     UnicodeString str =  strDictionaryName;
     if (FileExists(str))
     {
		  this->m_dictionary.LoadXML(strDictionaryName.c_str());
     }

    Clear();
    m_strDbName = strDbPath;
    TSearchRec sr;
    AnsiString strPath = m_strDbName;
	strPath += "\\*.*";
    int iAttr =0;
    iAttr |= faAnyFile;

    float baseWidth = 0;
	float baseHeight = 0;
    float base_a = 0;

    if (engine != NULL)
    {
       m_engine = engine;
       ILFObjectDetector* detector = engine->GetDetector();
       if (detector != NULL)
       {
			baseWidth  = detector->GetBaseWidth();
            baseHeight = detector->GetBaseHeight();

			base_a = baseWidth / baseHeight;
       }
    }


    if (FindFirst(strPath, iAttr, sr) == 0)
    {
      do
      {
         Application->ProcessMessages();
		 AnsiString str = sr.Name;
		 if (_IsImageFile(sr.Name))
		 {
			 TLFDbItem* item = new TLFDbItem();
			 if (item->Init(str.c_str()))
				this->m_dataFiles.Add(item);
			 else
				delete item;

			 m_NumImages++;
			 AnsiString strTmpFile = ChangeFileExt(sr.Name, ".xml");
			 if (FileExists(ChangeFileExt(sr.Name, ".ieye")))
				m_NumEyeFiles++;
			 if (FileExists(ChangeFileExt(sr.Name, ".face")))
				m_NumFaceFiles++;
			 if (FileExists(strTmpFile))
			 {
				m_NumXmlFiles++;
				TLFSemanticImageDescriptor d;
				if(d.LoadXML(strTmpFile.c_str()))
				{
				  for (int i = 0; i < d.GetItemsCount(); i++)
				  {
					 TLFDetectedItem* item = d.GetDetectedItem(i);
					 TLFDbSemanticItem* sitem = new TLFDbSemanticItem();
					 if (sitem->Init(str.c_str(), item))
						m_dataItems.Add(sitem);
					 else
						delete sitem;

				  }
				}
			 }
		 }
	  }while(FindNext(sr) == 0);
	  FindClose(sr);
	}
	m_NumXmlItems = m_dataItems.GetCount();


}
AnsiString __fastcall TDbLabeledImages::GetDbMetadata(AnsiString& strDbPath)
{
    AnsiString strFileName = strDbPath;
	strFileName += "\\metadata";
    FILE* f = fopen(strFileName.c_str(), "r+t");
    if (f == NULL)
        return "\\*.jp*g";
    char buf[32];
    fscanf(f, "%s", buf);
    AnsiString result = buf;
    fclose(f);
    return result;
}

void __fastcall TDbLabeledImages::MakeDbMetadata(AnsiString& strDbPath, const char* lpMetadata)
{
	AnsiString strFileName = strDbPath;
    strFileName += "\\metadata";
    FILE* f = fopen(strFileName.c_str(), "w+t");
    if (f == NULL)
        return;
	fprintf(f, "%s", lpMetadata);
    fclose(f);
}
/////////////////////////////////////////////////////////////////
void __fastcall TDbLabeledImages::ConvertEyeToXml(bool removeEye,  bool saveFace, bool saveEyes)
{
   TSearchRec sr;
   AnsiString strPath = m_strDbName;
   strPath += "\\*.*eye";

   int iAttr =0;
   iAttr |= faAnyFile;
   int num = 0;
    if (FindFirst(strPath, iAttr, sr) == 0)
    {
      do
      {
         TLFSemanticImageDescriptor sd;
         num++;
         awpImage* img = NULL;
         bool exist = false;
         AnsiString strTmpFile = ChangeFileExt(sr.Name, ".jpg");
         AnsiString strFullName = m_strDbName;
         strFullName += "\\";
		 if (FileExists(strTmpFile))
         {
           exist = true;
           strFullName += strTmpFile;
           awpLoadImage(strFullName.c_str(), &img);
         }
         else
         {
            strTmpFile = ChangeFileExt(sr.Name, ".jpeg");
            if (FileExists(strTmpFile))
            {
                strFullName += strTmpFile;
                awpLoadImage(strFullName.c_str(), &img);
                exist = true;
            }
            else
            {
              strTmpFile = ChangeFileExt(sr.Name, ".awp");

              if (FileExists(strTmpFile))
              {
                strFullName += strTmpFile;
                awpLoadImage(strFullName.c_str(), &img);
                exist = true;
			  }
            }
         }
         if (!exist)
            continue;
		 AnsiString str0 = sr.Name;
		 TLFRoiImageDescriptor rd(str0.c_str());
         sd.SetImage(img);

         for (int i = 0; i < rd.GetNumRois(); i++)
         {
            TLFRoi* roi = rd.GetRoi(i);
			TROI rr =  roi->GetRoi();
			UUID id;
            if (saveFace)
            {
                LF_NULL_UUID_CREATE(id);
				TLFDetectedItem*  di = new TLFDetectedItem(&rr.r, 0, "is marked by a person", 0, 0, 24, 24, "",id);
                sd.AddDetectedItem(di);
            }
            if (saveEyes)
            {
                awpRect er;
                double l = rr.EyeDistance();
				er.left = rr.p.X - 0.25*l;
                er.top = rr.p.Y - 0.25*l;
                er.right = rr.p.X + 0.25*l;
                er.bottom = rr.p.Y + 0.25*l;

                LF_NULL_UUID_CREATE(id);
				TLFDetectedItem*  di = new TLFDetectedItem(&er, 0, "is marked by a person", 0, 0, 24, 24, "",id);
                sd.AddDetectedItem(di);

                er.left = rr.p1.X - 0.25*l;
                er.top = rr.p1.Y - 0.25*l;
                er.right = rr.p1.X + 0.25*l;
                er.bottom = rr.p1.Y + 0.25*l;


				LF_NULL_UUID_CREATE(id);
				di = new TLFDetectedItem(&er, 0, "is marked by a person", 0, 0, 24, 24, "",id);
				sd.AddDetectedItem(di);
			}


		 }
         strTmpFile = ChangeFileExt(sr.Name, ".xml");
		 AnsiString str = m_strDbName;
		 str += "\\";
         str += strTmpFile;
         sd.SaveXML(str.c_str());
         if (removeEye)
            DeleteFile(sr.Name);
         awpReleaseImage(&img);

         if (m_ProgressEvent != NULL)
         {
			AnsiString str = "";
			m_ProgressEvent(int(100 *num / m_NumEyeFiles), str );
         }

         Application->ProcessMessages();

      }while(FindNext(sr) == 0);
      FindClose(sr);
    }
}

void __fastcall TDbLabeledImages::ConvertFaceToEye()
{
   TSearchRec sr;
   AnsiString strPath = m_strDbName;
   strPath += "\\*.face";

   int iAttr =0;
   iAttr |= faAnyFile;
   int num = 0;
    if (FindFirst(strPath, iAttr, sr) == 0)
    {
      do                        
      {
         num++;
         awpImage* img = NULL;
         bool exist = false;
         AnsiString strTmpFile = ChangeFileExt(sr.Name, ".jpg");
         AnsiString strFullName = m_strDbName;
         strFullName += "\\";
         if (FileExists(strTmpFile))
         {
           exist = true;
           strFullName += strTmpFile;
          // awpLoadImage(strFullName.c_str(), &img);
         }
         else
         {
            strTmpFile = ChangeFileExt(sr.Name, ".jpeg");
			if (FileExists(strTmpFile))
            {
                strFullName += strTmpFile;
               // awpLoadImage(strFullName.c_str(), &img);
                exist = true;
            }
            else
            {
              strTmpFile = ChangeFileExt(sr.Name, ".awp");
              if (FileExists(strTmpFile))
              {
                exist = true;
              }
            }
         }
         if (img)
            awpReleaseImage(&img);
         if (!exist)
            continue;
		 AnsiString _ansi = sr.Name;
		 TLFFaceImageDescriptor fd(_ansi.c_str());
         TLFRoi* roi = fd.GetRoi();
         TLFRoiImageDescriptor rd;
         rd.AddRoi(roi->GetRoi().p, roi->GetRoi().p1);

         strTmpFile = ChangeFileExt(sr.Name, ".ieye");
         AnsiString str = m_strDbName;
         str += "\\";
         str += strTmpFile;
         rd.SaveToFile(str.c_str());

         if (m_ProgressEvent != NULL)
         {
			AnsiString _ansi0 = "";
			m_ProgressEvent(int(100 *num / m_NumFaceFiles),_ansi0 );
         }

         Application->ProcessMessages();

      }while(FindNext(sr) == 0);
      FindClose(sr);
    }
}
void __fastcall TDbLabeledImages::SaveFragment(awpImage* img, SDbExportOptions& options, int count, TLFRect& scanBox, TLFRoiImageDescriptor* roid, const char* lpClassLabel)
{
      srand((unsigned)time(NULL));

      bool save = true;
	  if (options.copyRandom)
			save =  rand() % 100 < options.random;

      if (!save)
      	return;

      awpImage* pFragment = NULL;
      awpRect rr = scanBox.GetRect();
      awpCopyRect(img, &pFragment, &rr);
      if (pFragment == NULL)
      {
			return;
      }
      awpConvert(pFragment, AWP_CONVERT_3TO1_BYTE);
      AnsiString strFileName = MakeExportFileName(options, count, false, lpClassLabel);

      if (roid != NULL)
      {
		AnsiString strEyeName = ChangeFileExt(strFileName, ".ieye");
        TLFRoiImageDescriptor rd;
        for (int i = 0; i < roid->GetNumRois(); i++)
        {
			TLFRoi* roi = roid->GetRoi(i);
            int dx = -scanBox.Left();
			int dy = -scanBox.Top();
            roi->Shift(dx,dy);
            TROI r = roi->GetRoi();
            if (options.needResize)
            {
                double alfa = (double)options.baseSize / (double)pFragment->sSizeX;
                r.p.X *= alfa;
                r.p.Y *= alfa;
                r.p1.X *= alfa;
                r.p1.Y *= alfa;
            }

                rd.AddRoi(r.p, r.p1);
        }
        rd.SaveToFile(strEyeName.c_str());
	  }
      if (options.needResize)
      {
		 int w = options.baseSize;
         int h = (int)floor((double)w*(double)pFragment->sSizeY / (double)pFragment->sSizeX + 0.5);

		 awpResizeBilinear(pFragment, w,h);
      }


      	awpSaveImage(strFileName.c_str(), pFragment);


      if (options.needFlip)
      {
          strFileName = MakeExportFileName(options, count, true, lpClassLabel);

          if (roid != NULL)
          {
            AnsiString strEyeName = ChangeFileExt(strFileName, ".ieye");
            TLFRoiImageDescriptor rd;
            for (int i = 0; i < roid->GetNumRois(); i++)
            {
                TLFRoi* roi = roid->GetRoi(i);
                int dx = -scanBox.Left();
                int dy = -scanBox.Top();
                roi->Shift(dx,dy);
                if (options.needResize)
                {
                    double alfa = (double)options.baseSize / (double)pFragment->sSizeX;
                    roi->Scale(alfa);
                }
                    TROI r = roi->GetRoi();
					r.p.X = pFragment->sSizeX - r.p.X;
                    r.p1.X = pFragment->sSizeX - r.p1.X;
                    rd.AddRoi(r.p, r.p1);
            }
            rd.SaveToFile(strEyeName.c_str());
           }

		  awpFlip(&pFragment, AWP_FLIP_HRZT);
          if (options.needResize)
          {
             int w = options.baseSize;
             int h = (int)floor((double)w*(double)pFragment->sSizeY / (double)pFragment->sSizeX + 0.5);
               awpResizeBilinear(pFragment, w,h);
          }
          awpConvert(pFragment, AWP_CONVERT_3TO1_BYTE);
          awpSaveImage(strFileName.c_str(), pFragment);

      }
      awpReleaseImage(&pFragment);

}
void __fastcall TDbLabeledImages::ExportFragments(SDbExportOptions& options)
{
	if (!ClearDirWithSubdirs(options.strPathToExport, options.ClassLabels))
		return;
   TLFDBLabeledImages db(options.strPathToExport.c_str());
   TSearchRec sr;
   AnsiString strPath = m_strDbName;
   strPath += "\\*.xml";

   int iAttr =0;
   iAttr |= faAnyFile;
   int num = 0;
   int count = 0;

	if (FindFirst(strPath, iAttr, sr) == 0)
	{
	  do
	  {
		 TLFSemanticImageDescriptor sd;
		 num++;
		 awpImage* img = NULL;
		 bool exist = false;
		 AnsiString strTmpFile = ChangeFileExt(sr.Name, ".jpg");
		 AnsiString strFullName = m_strDbName;
		 strFullName += "\\";
		 if (FileExists(strTmpFile))
		 {
		   exist = true;
		   strFullName += strTmpFile;
		   awpLoadImage(strFullName.c_str(), &img);
		 }
		 else
		 {
			strTmpFile = ChangeFileExt(sr.Name, ".jpeg");
			if (FileExists(strTmpFile))
			{
				strFullName += strTmpFile;
				awpLoadImage(strFullName.c_str(), &img);
				exist = true;
			}
			else
			{
			  strTmpFile = ChangeFileExt(sr.Name, ".awp");
			  if (FileExists(strTmpFile))
			  {
				  strFullName += strTmpFile;
				  awpLoadImage(strFullName.c_str(), &img);
				  exist = true;
			  }
			}
		 }
		 if (!exist)
			continue;

		 TLFRoiImageDescriptor* rd = NULL;
		 if (options.copyIeye)
		 {
			rd = new TLFRoiImageDescriptor();
			AnsiString strIeyeFile = ChangeFileExt(sr.Name, ".ieye");
			rd->LoadFromFile(strIeyeFile.c_str());
			if (rd->GetNumRois() == 0)
			{
				delete rd;
				rd = NULL;
			}
		 }

		 AnsiString _ansi = sr.Name;
		 sd.LoadXML(_ansi.c_str());
		 sd.SetImage(img);

		 for (int i = 0; i < sd.GetItemsCount(); i++)
		 {
			TLFDetectedItem*  di = sd.GetDetectedItem(i);
			if (di == NULL)
				continue;
			if (di->GetRacurs() != options.racurs)
				continue;
            UnicodeString strClassLabel = di->GetType().c_str();
            if (options.ClassLabels->IndexOf(strClassLabel) < 0)
            	continue;
            AnsiString _ansi = strClassLabel;
			TLFRect* bounds = di->GetBounds();
			awpRect r = bounds->GetRect();
			if (options.useScanner)
			{
			  TLFScanner scanner;
			  TLFImage   lfimg;

   		     scanner.SetBaseWidth(di->GetBW());
			 scanner.SetBaseHeight(di->GetBH());


			  lfimg.SetImage(img);
			  scanner.Scan(lfimg.GetImage()->sSizeX, lfimg.GetImage()->sSizeY);
			  if (!options.exportNearlest)
			  {
				for (int j = 0; j < scanner.GetFragmentsCount(); j++)
				{
				  awpRect r = scanner.GetFragmentRect(j);
				  TLFRect scanBox; scanBox.SetRect(r);
				  if (options.exportCovered && !scanBox.IsCover(*bounds))
				  {
                      continue;
				  }
				  if (bounds->RectOverlap(scanBox) > options.scannerThreshold)
				  {
					  count++;
					  SaveFragment(img, options, count, scanBox, rd, _ansi.c_str());
				  }
				}
			  }
			  else
			  {
				float maxOverlap = 0;
				TLFRect maxRect;
				for (int j = 0; j < scanner.GetFragmentsCount(); j++)
				{
				  awpRect r = scanner.GetFragmentRect(j);
				  TLFRect scanBox; scanBox.SetRect(r);
				  float overlap = bounds->RectOverlap(scanBox);
				  if (overlap > maxOverlap)
				  {
					  maxOverlap = overlap;
					  maxRect = scanBox;
				  }
				}
			  //  if (maxOverlap >= options.scannerThreshold)
				{
					count++;
					SaveFragment(img, options, count, maxRect, rd,  _ansi.c_str());
				}
			  }
			}
			else
			{
				count++;
				TLFRect scanBox;
				scanBox.SetRect(r);
				SaveFragment(img, options, count, scanBox, rd,  _ansi.c_str());
			}
		 }
		 if (rd != NULL)
		 {
			delete rd;
			rd = NULL;
		 }
		 awpReleaseImage(&img);
		 if (m_ProgressEvent != NULL)
		 {
			AnsiString strComment = "Processed ";
			strComment += IntToStr (num);
			strComment += " of ";
			strComment += IntToStr(m_NumXmlFiles);
			m_ProgressEvent(int(100 *num / m_NumXmlFiles),strComment);
		 }

		 Application->ProcessMessages();

	  }while(FindNext(sr) == 0);
	  FindClose(sr);
	}

    if (options.copyBackground)
    {
    	this->SaveBackground(options);
    }
}
char * guid_to_str(GUID* id, char * out) {
	int i;
	char * ret = out;
	out += sprintf(out, "%.8lX-%.4hX-%.4hX-", id->Data1, id->Data2, id->Data3);
	for (i = 0; i < sizeof(id->Data4); ++i) {
		out += sprintf(out, "%.2hhX", id->Data4[i]);
		if (i == 1) *(out++) = '-';
	}
	return ret;
}

AnsiString  TDbLabeledImages::MakeExportFileName(SDbExportOptions& options, int num, bool fliped, const char* lpClassLabel)
{

	char uuid_buf[130];
	UUID id;

	UuidCreate(&id);
	guid_to_str(&id, uuid_buf);

	AnsiString strName;
	strName = options.strPathToExport;
	strName += "\\";
    if (lpClassLabel != NULL)
	{
		strName += lpClassLabel;
		strName += "\\";
    }
	if (fliped)
		strName += "fliped_";
	strName += uuid_buf;
	strName += options.exportFormat == jpeg?".jpg":".awp";
	return strName;
}

void __fastcall TDbLabeledImages::CalculatePerfomance(float& far1, float& frr, float& ffar, float& time, float thr, TProgressBar* bar)
{

   bar->Min = 0;
   bar->Max = m_NumImages;
   bar->Position = 0;
	TSearchRec sr;
	AnsiString strPath = m_strDbName;
	strPath += "*.awp";//GetDbMetadata(strPath);
	int iAttr =0;
	iAttr |= faAnyFile;

	far1 = 0;
	frr = 0;
	ffar = 0;
	time = 0;

	float baseWidth = 0;
	float baseHeight = 0;
	float base_a = 0;
	if (m_engine != NULL)
	{
	   ILFObjectDetector* detector = m_engine->GetDetector();
	   if (detector != NULL)
	   {
			baseWidth  = detector->GetBaseWidth();
			baseHeight = detector->GetBaseHeight();

			base_a = baseWidth / baseHeight;
	   }
	}
	else
		return;

	float NumObjects = 0;
	float farCounter = 0;
	float frrCounter = 0;
	float fragmentsCounter = 0;
	float totalTime = 0;
	if (FindFirst(strPath, iAttr, sr) == 0)
	{
	  do
	  {
		 bar->Position = bar->Position +1;
		 Application->ProcessMessages();
		 AnsiString strTmpFile = ChangeFileExt(sr.Name, ".xml");
		 if (FileExists(strTmpFile))
		 {
			m_NumXmlFiles++;
			TLFSemanticImageDescriptor d;
			if(d.LoadXML(strTmpFile.c_str()))
			{
				TLFObjectList markedObjects;
				for (int i = 0; i < d.GetItemsCount(); i++)
				{
				   TLFDetectedItem* item = d.GetDetectedItem(i);
				   float bw = item->GetBW();
				   float  bh = item->GetBH();
				   float a  = bw / bh;
				   if (fabs(a - base_a) < 0.01)
				   {
						TLFDetectedItem* itm = new  TLFDetectedItem(item);
						markedObjects.Add(itm);
				   }
				 NumObjects += markedObjects.GetCount();
				}


				if (markedObjects.GetCount() > 0)
				{
					TLFImage image;
					AnsiString _ansi = sr.Name;
					image.LoadFromFile(_ansi.c_str());
					DWORD tt = GetTickCount();
					m_engine->SetSourceImage(&image, true);
					totalTime += (GetTickCount() - tt);
					fragmentsCounter += m_engine->GetScanner()->GetFragmentsCount();

					Application->ProcessMessages();

					if (m_engine->GetItemsCount() > 0)
					{
						// вычисляем far
						for (int i = 0; i < m_engine->GetItemsCount(); i++)
						{
							TLFDetectedItem* itm = m_engine->GetItem(i);
							TLFRect* sr = itm->GetBounds();
							bool found = false;
							for (int j = 0; j < markedObjects.GetCount(); j++)
							{
								TLFDetectedItem* it = (TLFDetectedItem*)markedObjects.Get(j);
								TLFRect* mr = it->GetBounds();
								if (sr->RectOverlap(*mr) > thr)
									found = true;
							}
							if (!found)
								farCounter++;
						}


						//вычисляем frr
						for (int i = 0; i < markedObjects.GetCount(); i++)
						{
							TLFDetectedItem* it = (TLFDetectedItem*)markedObjects.Get(i);
							TLFRect* mr = it->GetBounds();
							bool found = false;
							for (int j = 0; j < m_engine->GetItemsCount(); j++)
							{
								 TLFDetectedItem* itm = m_engine->GetItem(j);
								 TLFRect* sr = itm->GetBounds();
								 if (sr->RectOverlap(*mr) > thr)
									 found = true;
							}
							if (!found)
							  frrCounter++;
						}
					}
					else
						frrCounter += markedObjects.GetCount();

				}
			}
		 }
	  }while(FindNext(sr) == 0);
	  FindClose(sr);
	}
	if (fragmentsCounter > 0)
	{
		far1 = 100*farCounter / fragmentsCounter;
		time = totalTime / fragmentsCounter;
	}
	if (NumObjects > 0)
	{
	  frr = 100*frrCounter / NumObjects;
	  ffar = 100*farCounter / NumObjects;
	}


	bar->Position = 0;
}
void __fastcall TDbLabeledImages::GetFaceStatisctics(SDBFaceStatistics& stat)
{
   TSearchRec sr;
   AnsiString strPath = m_strDbName;
   strPath += "\\*.face";

   int iAttr =0;
   iAttr |= faAnyFile;
   int num = 0;
	memset(&stat, 0, sizeof(SDBFaceStatistics));
	if (FindFirst(strPath, iAttr, sr) == 0)
	{
	  do
	  {
		 num++;
		 stat.NumItems = num;
		 awpImage* img = NULL;
		 bool exist = false;
		 AnsiString strTmpFile = ChangeFileExt(sr.Name, ".jpg");
		 AnsiString strFullName = m_strDbName;
		 strFullName += "\\";
		 if (FileExists(strTmpFile))
		 {
		   exist = true;
		   strFullName += strTmpFile;
		   awpLoadImage(strFullName.c_str(), &img);
		 }
		 else
		 {
			strTmpFile = ChangeFileExt(sr.Name, ".jpeg");
			if (FileExists(strTmpFile))
			{
				strFullName += strTmpFile;
				awpLoadImage(strFullName.c_str(), &img);
				exist = true;
			}
			else
		   {
			  strTmpFile = ChangeFileExt(sr.Name, ".awp");
			  if (FileExists(strTmpFile))
			  {
				strFullName += strTmpFile;
				awpLoadImage(strFullName.c_str(), &img);
				exist = true;
			  }
			}
		 }


		 if (!exist || img == NULL)
			continue;

		 int w = img->sSizeX;
		 if (img)
			awpReleaseImage(&img);
		 AnsiString _ansi = sr.Name;
		 TLFFaceImageDescriptor fd(_ansi.c_str());
		 TLFRoi* roi = fd.GetRoi();
		 TLFRoiImageDescriptor rd;
		 rd.AddRoi(roi->GetRoi().p, roi->GetRoi().p1);

		 double s = 100*roi->GetRoi().EyeDistance() / (double)w;
		 if (s > 20 )
			stat.NumBig ++;
		 else if (s > 12)
			stat.NumMedium++;
		 else
			stat.NumSmall++;
		 double angle = roi->GetRoi().OprientationGrad();
		 if (fabs(angle) > 10)
		 {
			stat.NumRotated++;
			if (angle > 0)
				stat.NumRotatedLeft++;
			else
				stat.NumRotatedRight++;
		 }
		 if (fd.IsGlasses())
			stat.NumGlasses++;
		 if (fd.IsBread())
			stat.NumBread++;
		if (fd.IsTurnLeft() || fd.IsTurnRight())
			stat.NumTurn++;
		if (fd.IsTurnLeft())
			stat.NumTurnLeft++;
		if (fd.IsTurnRight())
			stat.NumTurnRight++;

		 if (m_ProgressEvent != NULL)
		 {
			AnsiString _ansi = "";
			m_ProgressEvent(int(100 *num / m_NumFaceFiles), _ansi );
		 }

		 Application->ProcessMessages();

	  }while(FindNext(sr) == 0);
	  FindClose(sr);
	}
}

static bool _HasAttributes(TLFFaceImageDescriptor& fd)
{
	return fd.IsBread() || fd.IsGlasses() || fd.IsTurnLeft() || fd.IsTurnRight();
}


bool static _NeedExport1(SDbExportFaceOptions& o, TLFFaceImageDescriptor& fd)
{
	bool result = false;
	switch (o.attrToSave)
	{
		case eAll:
			result = true;
		break;
		case eAll_w_Glasses:
			result = !fd.IsGlasses();
		break;
		case eAll_w_Breads:
			result = !fd.IsBread();
		break;
		case eAll_w_Breads_a_Glasses:
			result = !(fd.IsBread() && fd.IsGlasses());
		break;
		case eFront:
			result = !(fd.IsTurnLeft() || fd.IsTurnRight());
		break;
		case eFront_w_Glasses:
			result = !(fd.IsTurnLeft() || fd.IsTurnRight() || fd.IsGlasses());
		break;
		case eFront_w_Breads:
			result = !(fd.IsTurnLeft() || fd.IsTurnRight() || fd.IsBread());
		break;
		case eFront_w_Glasses_a_Breads:
			result = !(fd.IsTurnLeft() || fd.IsTurnRight() || fd.IsBread() || fd.IsGlasses());
		break;
		case eTurn:
			result = fd.IsTurnLeft() || fd.IsTurnRight();
		break;
		case eTurn_w_Glasses:
			result = fd.IsTurnLeft() || fd.IsTurnRight() && !fd.IsGlasses();
		break;
		case eTurn_w_Breads:
			result = fd.IsTurnLeft() || fd.IsTurnRight() && !fd.IsBread();
		break;
		case eTurn_w_Glasses_a_Breads:
			result = fd.IsTurnLeft() || fd.IsTurnRight() && !fd.IsBread() && !fd.IsGlasses();
		break;
		case eGlasses:
			result = fd.IsGlasses();
		break;
		case eGlasses_a_Front:
			result = fd.IsGlasses() && !(fd.IsTurnLeft() || fd.IsTurnRight());
		break;
		case eGlasses_a_Turn:
			result = fd.IsTurnLeft() || fd.IsTurnRight() && fd.IsGlasses();
		break;
		case eGlasses_a_Breads:
			result = fd.IsGlasses() && fd.IsBread();
		break;
		case eBreads:
			result = fd.IsBread();
		break;
		case eBreads_a_Front:
			result = fd.IsBread() && !(fd.IsTurnLeft() || fd.IsTurnRight());
		break;
		case eBreads_a_Turn:
			result = fd.IsTurnLeft() || fd.IsTurnRight() && fd.IsBread();
		break;
		default:
			result = false;
	}
	return result;
}

void __fastcall TDbLabeledImages::ExportFaceDatabase(SDbExportFaceOptions& options)
{
}
static bool _HasImage(UnicodeString& strFileName)
{
   if (FileExists(ChangeFileExt(strFileName, ".jpg")))
	return true;
   if (FileExists(ChangeFileExt(strFileName, ".jpeg")))
	return true;
   if (FileExists(ChangeFileExt(strFileName, ".awp")))
	return true;
   return false;
}
//////////////////////////////////////////////////////////////////////////
static AnsiString GetImageName(AnsiString& strFileName)
{
   if (FileExists(ChangeFileExt(strFileName, ".jpg")))
	return ChangeFileExt(strFileName, ".jpg");
   if (FileExists(ChangeFileExt(strFileName, ".jpeg")))
	return ChangeFileExt(strFileName, ".jpeg");
   if (FileExists(ChangeFileExt(strFileName, ".awp")))
	return ChangeFileExt(strFileName, ".awp");
   return "";
}
//////////////////////////////////////////////////////////////////////////
int __fastcall TDbLabeledImages::GetWithoutOverlaps(SDBWhithoutOverapsOptions& options, int& NumOverlaps)
{
	return 0;
}
/*
	Находит изображения, к которым нет вообще никакого описания.
*/
void __fastcall TDbLabeledImages::FindEmptyFiles()
{
}
//////////////////////////////////////////////////////////////////////////
static TiXmlElement* SaveShapedImage(const char* lpFileName, awpImage* img, TLFFaceImageDescriptor& fd)
{
	  awpImage* img1 = fd.GetFaceImageForPredictor(img, NULL);
	  if (img1 == NULL)
		return NULL;

	  awpSaveImage(lpFileName, img1);
	  awpReleaseImage(&img1);
	  AnsiString _ansi = ChangeFileExt(lpFileName, ".face");
	  fd.SaveToFile(_ansi.c_str());
	  _ansi = ExtractFileName(ChangeFileExt(lpFileName, ".face"));
	  return fd.SaveXML(_ansi.c_str(), NULL);
}
//////////////////////////////////////////////////////////////////////////
static TiXmlElement* SaveFoundImage(const char* lpFileName, awpImage* img, TLFFaceImageDescriptor& fd, awpRect faceBox)
{
	  awpImage* img1 = fd.GetFaceImageForPredictor(img, &faceBox);
	  if (img1 == NULL)
		return NULL;

	  awpSaveImage(lpFileName, img1);
	  AnsiString _ansi = ChangeFileExt(lpFileName, ".face");
	  fd.SaveToFile(_ansi.c_str());
	  awpRect r; r.left = 0; r.right = img1->sSizeX;
	  r.top = 0; r.bottom = img1->sSizeY;
	  awpReleaseImage(&img1);
	  _ansi = ExtractFileName(ChangeFileExt(lpFileName, ".face"));
	  return fd.SaveXML(_ansi.c_str(), &r);
}
////////////////////////////////////////////////////////////////////////////////
void __fastcall TDbLabeledImages::MakeShapeDatabase(AnsiString& strPathToSave)
{
   TSearchRec sr;
   AnsiString strPath = m_strDbName;
  // MakeDbMetadata(strPath, "\\*.jpg");

   strPath += "\\*.face";
   int iAttr =0;
   iAttr |= faAnyFile;
   int num = 0;
   int count = 0;
	TiXmlDocument doc;
	TiXmlDeclaration* decl = new TiXmlDeclaration( "1.0", "", "" );

	doc.LinkEndChild( decl );
	TiXmlElement* e0 = new TiXmlElement("dataset");
	TiXmlElement* e1 = new TiXmlElement("name");
	TiXmlText* t = new TiXmlText("Training faces");
	e1->LinkEndChild(t);
	e0->LinkEndChild(e1);

	TiXmlElement* e2 = new TiXmlElement("images");

	if (FindFirst(strPath, iAttr, sr) == 0)
	{
	  do
	  {
		 num++;
		 awpImage* img = NULL;
		 bool exist = false;
		 AnsiString strTmpFile = ChangeFileExt(sr.Name, ".jpg");
		 AnsiString strFullName = m_strDbName;
		 strFullName += "\\";
		 if (FileExists(strTmpFile))
		 {
		   exist = true;
		   strFullName += strTmpFile;
		   awpLoadImage(strFullName.c_str(), &img);
		 }
		 else
		 {
			strTmpFile = ChangeFileExt(sr.Name, ".jpeg");
			if (FileExists(strTmpFile))
			{
				strFullName += strTmpFile;
				awpLoadImage(strFullName.c_str(), &img);
				exist = true;
			}
			else
		   {
			  strTmpFile = ChangeFileExt(sr.Name, ".awp");
			  if (FileExists(strTmpFile))
			  {
				strFullName += strTmpFile;
				awpLoadImage(strFullName.c_str(), &img);
				exist = true;
			  }
			}
		 }
		 if (!img)
			continue;

		 AnsiString _ansi = sr.Name;
		 TLFFaceImageDescriptor fd(_ansi.c_str());

		 AnsiString strNewFileName;
		 strNewFileName = strPathToSave;
		 strNewFileName += "\\";
		 strNewFileName += ChangeFileExt(sr.Name, ".jpg");
		 TiXmlElement* e = SaveShapedImage(strNewFileName.c_str(), img, fd);
		 if (e != NULL)
			e2->LinkEndChild(e);

		 awpReleaseImage(&img);
		 if (m_ProgressEvent != NULL)
		 {
			AnsiString strComment = "Processed ";
			strComment += IntToStr (num);
			strComment += " of ";
			strComment += IntToStr(m_NumXmlFiles);
				m_ProgressEvent(int(100 *num / this->NumImages),strComment);
		 }

		 Application->ProcessMessages();

	  }while(FindNext(sr) == 0);
	  FindClose(sr);
	}
	 e0->LinkEndChild(e2);
	 doc.LinkEndChild(e0);
	 doc.SaveFile("database.xml");

}
////////////////////////////////////////////////////////////////////////////////
void __fastcall TDbLabeledImages::ConvertDatabase(SDbConvertOptions& options)
{
   TSearchRec sr;
   AnsiString strPath = m_strDbName;

   strPath += "\\*.*";
   int iAttr =0;
   iAttr |= faAnyFile;
   int num = 0;
   if (FindFirst(strPath, iAttr, sr) == 0)
   {
	  do
	  {
		 if (_IsImageFile(sr.Name))
		 {
			num++;

			Form1->FImage2->Init(sr.Name, NULL);
			awpImage* img = NULL;
			Form1->FImage2->Bitmap->GetAWPImage(&img);
			if (img)
			{
			  TLFSemanticImageDescriptor* sd = NULL;
			  AnsiString strXml = ChangeFileExt(sr.Name, ".xml");
			  if (FileExists(ChangeFileExt(sr.Name, ".xml")))
			  {
				sd = new TLFSemanticImageDescriptor();
				sd->LoadXML(strXml.c_str());
			  }
			  if (options.needResize)
			  {
				  // resize
				  int width  = options.baseWidth;
				  double factor = (double)width / (double)img->sSizeX;
				  int height = floor(factor*img->sSizeY + 0.5);
				  if (!options.interpolation)
					awpResize(img, width, height);
				  else
					awpResizeBilinear(img, width, height);
				  if (sd != NULL)
				  {

					sd->Resize(factor);
					sd->SetImage(img);
				  }
			  }
			  if (options.RenameToUUID)
			  {
              	  //////////////////////
                  UUID id;
                  LF_UUID_CREATE(id);
                  std::string strUUID = LFGUIDToString(&id);
                  AnsiString strFileName = m_strDbName + "\\";
                  strFileName += strUUID.c_str();
                  AnsiString strExt = options.format == awp ? ".awp" : ".jpg";
                  strFileName += strExt;
                  awpSaveImage(strFileName.c_str(), img);
                  strFileName = ChangeFileExt(strFileName, ".xml");
                  if (sd != NULL)
                  {
                  	sd->SaveXML(strFileName.c_str());
                    DeleteFile(strXml);
                  }
                  DeleteFile(sr.Name);

              }
              else
              {
                  if (sd != NULL)
                    sd->SaveXML(strXml.c_str());
                  // make new filename
                  AnsiString strFileName = m_strDbName + "\\" + sr.Name;
				  AnsiString strExt = options.format == awp ? ".awp" : ".jpg";
                  strFileName = ChangeFileExt(strFileName, strExt);
				  if (strExt != ExtractFileExt(sr.Name))
                    DeleteFile(sr.Name);
                  awpSaveImage(strFileName.c_str(), img);
              }
			  awpReleaseImage(&img);

			  if (m_ProgressEvent != NULL)
			  {
				AnsiString _ansi = sr.Name;
				m_ProgressEvent(int(100 *num / this->m_NumImages),_ansi );
			  }
			}
		 }

		 Application->ProcessMessages();

	  }while(FindNext(sr) == 0);
	  FindClose(sr);
   }
}
// копирование базы данных, в соответствии с опициями.
void __fastcall TDbLabeledImages::CopyDatabase(SDbCopyOptions& options)
{
   if (m_NumImages==0)
	  return;
   if (this->DbName == options.strPathToCopy)
	  return;

//	if (!ClearDir(options.strPathToCopy))
//		return;

   TSearchRec sr;
   AnsiString strPath = m_strDbName;

   strPath += "\\*.*";
   int iAttr =0;
   iAttr |= faAnyFile;
   int num = 0;

   if (FindFirst(strPath, iAttr, sr) == 0)
   {
	  do
	  {
		 num++;
		 bool was_copy = false;
		 if (options.copyImages && _IsImageFile(sr.Name))
		 {
			String strFileName = options.strPathToCopy;
			strFileName += "\\";
			strFileName += ExtractFileName(sr.Name);
			String _ansi = this->m_strDbName;
			_ansi += "\\";
			_ansi+= sr.Name;
			CopyFile(_ansi.c_str(), strFileName.c_str(), true);
			was_copy = true;
		 }

		 AnsiString strExt = ExtractFileExt(sr.Name);
		 strExt.LowerCase();
		 if (options.copySemantic && strExt == ".xml")
		 {
			String strFileName = options.strPathToCopy;
			strFileName += "\\";
			strFileName += ExtractFileName(sr.Name);
			String _ansi = this->m_strDbName;
			_ansi += "\\";
			_ansi+= sr.Name;
			CopyFile(_ansi.c_str(), strFileName.c_str(), true);
			was_copy = true;
		 }
		 if (options.copyIeye && strExt == ".ieye")
		 {
			String strFileName = options.strPathToCopy;
			strFileName += "\\";
			strFileName += ExtractFileName(sr.Name);
			String _ansi = this->m_strDbName;
			_ansi += "\\";
			_ansi+= sr.Name;
			CopyFile(_ansi.c_str(), strFileName.c_str(), true);
			was_copy = true;
		 }

		 if (options.copyFace && strExt == ".face")
		 {
			String strFileName = options.strPathToCopy;
			strFileName += "\\";
			strFileName += ExtractFileName(sr.Name);
			String _ansi = this->m_strDbName;
			_ansi += "\\";
			_ansi+= sr.Name;
			CopyFile(_ansi.c_str(), strFileName.c_str(), true);
			was_copy = true;
		 }

		 if (m_ProgressEvent != NULL && was_copy)
		 {
			AnsiString _ansi = sr.Name;
			m_ProgressEvent(int(100 *num / this->m_NumImages),_ansi );
		 }

		 Application->ProcessMessages();

	  }while(FindNext(sr) == 0);
	  FindClose(sr);
   }
}

awpImage* FitImage(awpRect rect, awpImage* img)
{
	int W = rect.right - rect.left;
	int H = rect.bottom - rect.top;

	double ar1 = (double) W / (double) H;
	double ar2 = (double) img->sSizeX / (double)img->sSizeY;

	awpImage* result = NULL;
	awpCreateImage(&result, W, H, img->bChannels, AWP_BYTE);



	if (result != NULL)
	{
	  int sx = 0;
	  int sy = 0;
	  int w  = img->sSizeX;
	  int h  = img->sSizeY;
	  int w1, h1;
	  double alfa = 1;

	  if (ar1 > ar2)
	  {
		 h1 = H;
		 alfa = (double)H/(double)h;
		 w1 = floor(alfa*w );
		 sx = (W - w1) /2;
		 if (sx < 0) sx = 0;
		 sy = 0;
	  }
	  else
	  {
		w1 = W;
		alfa = (double)W / (double)w;
		h1 = floor((double)h*alfa );
		sx = 0;
		sy = (H-h1) /2;
		if (sy < 0) sy = 0;
	  }
	  awpPoint p;
	  p.X = sx;
	  p.Y = sy;
	  awpImage* dst = NULL;

	  awpCopyImage(img, &dst);
	  awpResizeBilinear(dst, w1, h1);

	  if (dst != NULL)
	  {
		awpPasteRect( dst, result,  p);
		_AWP_SAFE_RELEASE_(dst)
	  }
	  else
	  {
		_AWP_SAFE_RELEASE_(result)
	  }

	}
	return result;
}

awpImage* __fastcall TDbLabeledImages::GetDbThumbinals(int thmbWidth, int thmbHeight)
{
   if (this->m_NumImages == 0)
	return NULL;
   int imgCount =  floor(sqrt((float)this->m_NumImages) + 0.5);
   int imgWidth  = thmbWidth*imgCount;
   int imgHeight = thmbHeight*imgCount;
   awpImage* result = NULL;
   awpCreateImage(&result, imgWidth, imgHeight, 3, AWP_BYTE);

   TSearchRec sr;
   AnsiString strPath = m_strDbName;

   strPath += "\\*.*";
   int iAttr =0;
   iAttr |= faAnyFile;
   int num = 0;
   awpRect rect;
   rect.left = 0;
   rect.top = 0;
   rect.right = thmbWidth;
   rect.bottom = thmbHeight;
   if (FindFirst(strPath, iAttr, sr) == 0)
   {
	  do
	  {

		 if (_IsImageFile(sr.Name))
		 {
			Form1->FImage2->Init(sr.Name, NULL);
			awpImage* img = NULL;
			Form1->FImage2->Bitmap->GetAWPImage(&img);
			if (img)
			{
				awpImage* fit = FitImage(rect, img);
				if (fit && FileExists(ChangeFileExt(sr.Name, ".xml")))
				{
					awpRect rect1;
					rect1.left = rect.left + 1;
					rect1.top  = rect.top+1;
					rect1.right = rect.right -2;
					rect1.bottom = rect.bottom - 2;
					awpDrawCRect(fit, &rect1, 255,255,255, 1);
				}

				if (fit)
				{
					 awpPoint p;
					 p.Y = (num / imgCount)*thmbHeight;
					 p.X = (num % imgCount)*thmbWidth;

					 awpPasteRect(fit, result, p);

					_AWP_SAFE_RELEASE_(fit)
				}
				_AWP_SAFE_RELEASE_(img)
			}
			 num++;
		 }

		 if (m_ProgressEvent != NULL)
		 {
			AnsiString _ansi = "";
			m_ProgressEvent(int(100 *num / this->m_NumImages),_ansi );
		 }

		 Application->ProcessMessages();

	  }while(FindNext(sr) == 0);
	  FindClose(sr);
   }


   return result;
}

void __fastcall TDbLabeledImages::MakeSemanticAnalysis(bool save_old)
{
   if (this->m_NumImages == 0)
	return;
   if (this->m_engine == NULL)
	return;

   TSearchRec sr;
   AnsiString strPath = m_strDbName;

   strPath += "\\*.*";
   int iAttr =0;
   iAttr |= faAnyFile;
   int num = 0;
   awpRect rect;
   rect.left = 0;
   rect.top = 0;
   rect.right = 32;
   rect.bottom = 32;
   if (FindFirst(strPath, iAttr, sr) == 0)
   {
	  do
	  {

		 if (_IsImageFile(sr.Name))
		 {
			 num++;
			 AnsiString strSemantic = ChangeFileExt(sr.Name, ".xml");
			 AnsiString strImage    = sr.Name;
			 TLFSemanticImageDescriptor descr;
			 if (FileExists(strSemantic.c_str()))
			 {
				   if (!save_old)
					DeleteFile(strSemantic);
				   else
					descr.LoadXML(strSemantic.c_str());
			 }
			 TLFImage image;
			 if (!image.LoadFromFile(strImage.c_str()))
				continue;

			 m_engine->SetSourceImage(&image, true);
			 if (m_engine->GetItemsCount() > 0)
			 {

				descr.SetImage(image.GetImage());

				 for (int i = 0; i < m_engine->GetItemsCount(); i++)
				 {
					TLFDetectedItem* item = (TLFDetectedItem*)m_engine->GetItem(i);
					if (item != NULL)
						descr.AddDetectedItem(item);
				 }
			 }
			 else
				DeleteFile(strImage.c_str());

			 if (descr.GetItemsCount() > 0)
				descr.SaveXML(strSemantic.c_str());

		 }

		 if (m_ProgressEvent != NULL)
		 {
			AnsiString _ansi = "";
			m_ProgressEvent(int(100 *num / this->m_NumImages),_ansi );
		 }

		 Application->ProcessMessages();

	  }while(FindNext(sr) == 0);
	  FindClose(sr);
   }

}
awpImage* __fastcall TDbLabeledImages::MakeSemanticThumbinals(int thmbWidth, int thmbHeight)
{
   if (this->m_NumImages == 0)
	return NULL;
   if (this->m_NumXmlFiles == 0)
	return NULL;
   if (this->m_NumXmlItems == 0)
	return NULL;

   int imgCount =  floor(sqrt((float)this->m_NumXmlItems) + 0.5);
   int imgWidth  = thmbWidth*imgCount;
   int imgHeight = thmbHeight*imgCount;
   awpImage* result = NULL;
   awpCreateImage(&result, imgWidth, imgHeight, 3, AWP_BYTE);


   TSearchRec sr;
   AnsiString strPath = m_strDbName;

   strPath += "\\*.*";
   int iAttr =0;
   iAttr |= faAnyFile;
   int num = 0;
   awpRect rect;
   rect.left = 0;
   rect.top = 0;
   rect.right = thmbWidth;
   rect.bottom = thmbHeight;
   if (FindFirst(strPath, iAttr, sr) == 0)
   {
	  do
	  {

		 if (_IsImageFile(sr.Name))
		 {
			Form1->FImage2->Init(sr.Name, NULL);
			awpImage* img = NULL;
			Form1->FImage2->Bitmap->GetAWPImage(&img);
			if (img)
			{
				awpImage* fit = NULL;
				if (FileExists(ChangeFileExt(sr.Name, ".xml")))
				{

					AnsiString strXmlName = ChangeFileExt(sr.Name, ".xml");
					TLFSemanticImageDescriptor descr;
					descr.LoadXML(strXmlName.c_str());
					for (int i = 0; i < descr.GetItemsCount(); i++)
					{
						TLFDetectedItem* item = descr.GetDetectedItem(i);
						if (item)
						{
							awpRect item_rect = item->GetBounds()->GetRect();
							awpImage* image1 = NULL;
							awpCopyRect(img, &image1, &item_rect);
							if (image1)
							{
								fit = FitImage(rect, image1);
								if (fit)
								{
									 awpPoint p;
									 p.Y = (num / imgCount)*thmbHeight;
									 p.X = (num % imgCount)*thmbWidth;

									 awpPasteRect(fit, result, p);

									_AWP_SAFE_RELEASE_(fit)
									 num++;
								}
								_AWP_SAFE_RELEASE_(image1)
							}


						}

					}

				}

				_AWP_SAFE_RELEASE_(img)
			}

		 }

		 if (m_ProgressEvent != NULL)
		 {
			AnsiString _ansi = "";
			m_ProgressEvent(int(100 *num / this->m_NumImages),_ansi );
		 }

		 Application->ProcessMessages();

	  }while(FindNext(sr) == 0);
	  FindClose(sr);
   }


   return result;
}

const char* __fastcall TDbLabeledImages::GetFileName(int index)
{
	if (index < 0 || index >= this->m_dataFiles.GetCount())
		return NULL;
	TLFDbItem* item = (TLFDbItem*)this->m_dataFiles.Get(index);
	return item->FileName;
}

awpImage*	__fastcall TDbLabeledImages::GetSemanticImage(int index)
{
	if (index < 0 || index >= this->m_dataItems.GetCount())
		return NULL;
	 TLFDbSemanticItem* item = (TLFDbSemanticItem*)m_dataItems.Get(index);
	 if (item)
	 {
		return item->image;
	 }
	 else
		return NULL;
}
void __fastcall TDbLabeledImages::DeleteSementicItem(int index)
{
	if (index < 0 || index >= this->m_dataItems.GetCount())
		return;

	TLFDbSemanticItem* item = (TLFDbSemanticItem*)m_dataItems.Get(index);
	if (item)
	{
		awpRect rect1 = item->Item->GetBounds()->GetRect();
		UnicodeString str = item->FileName;
		AnsiString _ansi = str;
		TLFImage image;
		image.LoadFromFile(_ansi.c_str());
		str = ChangeFileExt(str, L".xml");
		_ansi = str;
		TLFSemanticImageDescriptor descr;
		descr.LoadXML(_ansi.c_str());
		descr.SetImage(image.GetImage());
		for (int i = 0; i < descr.GetItemsCount(); i++)
		{
			TLFDetectedItem* di = descr.GetDetectedItem(i);
			if (di)
			{
				awpRect rect2 = di->GetBounds()->GetRect();

				if (rect1.left == rect2.left && rect1.top == rect2.top &&
				rect1.right == rect2.right && rect1.bottom == rect2.bottom)
					descr.DeleteDetectedItem(i);
			}
		}
		descr.SaveXML(_ansi.c_str());
	}
}
// удаление элемента базы данных.
void 	   __fastcall TDbLabeledImages::DeleteDatabaseItem(int index)
{
//	if (index < 0 || index >= this->m_dataItems.GetCount())
//		return;
	TLFDbItem* item = (TLFDbItem*)m_dataFiles.Get(index);
	if (item)
		item->Delete();
}
////////////////////////////////////////////////////////////////////////////////
void __fastcall TDbLabeledImages::ConvertSemanticBW()
{
   TSearchRec sr;
   AnsiString strPath = m_strDbName;

   strPath += "\\*.*";
   int iAttr =0;
   iAttr |= faAnyFile;
   int num = 0;
   awpRect rect;
   rect.left = 0;
   rect.top = 0;
   if (FindFirst(strPath, iAttr, sr) == 0)
   {
	  do
	  {
		 AnsiString str = sr.Name;

		 if (_IsImageFile(sr.Name))
		 {
			TLFImage img;
			img.LoadFromFile(str.c_str());
			if (img.GetImage() != NULL)
			{
				AnsiString strXmlName = ChangeFileExt(sr.Name, ".xml");
				TLFSemanticImageDescriptor descr;
				descr.LoadXML(strXmlName.c_str());
				descr.SetImage(img.GetImage());
				for (int i = 0; i < descr.GetItemsCount(); i++)
				{
					TLFDetectedItem* item = descr.GetDetectedItem(i);
					if (item)
					{
						// todo: set bw
					   //	item->m_bw = 16;
					}
				}
				descr.SaveXML(strXmlName.c_str());
			}
		}
	  }
	  while(FindNext(sr) == 0);
	  FindClose(sr);
   }
}
////////////////////////////////////////////////////////////////////////////////
void __fastcall TDbLabeledImages::DoMarking(ILFDetectEngine* engine)
{
   TSearchRec sr;
   AnsiString strPath = m_strDbName;

   strPath += "\\*.*";
   int iAttr =0;
   iAttr |= faAnyFile;
   int num = 0;
   awpRect rect;
   rect.left = 0;
   rect.top = 0;
   if (FindFirst(strPath, iAttr, sr) == 0)
   {
	  do
	  {
		 AnsiString str = sr.Name;
		 Application->ProcessMessages();

		 if (_IsImageFile(sr.Name))
		 {
			num++;
			TLFImage img;

			img.LoadFromFile(str.c_str());
			if (img.GetImage() != NULL)
			{
				engine->SetSourceImage(img.GetImage(), true);
				if (engine->GetItemsCount() > 0)
				{
				   TLFSemanticImageDescriptor* d = engine->GetSemantic();
				   AnsiString strXmlName = ChangeFileExt(sr.Name, ".xml");
				   d->SaveXML(strXmlName.c_str());
				}

				 if (m_ProgressEvent != NULL)
				 {
					AnsiString _ansi = sr.Name;
					m_ProgressEvent(int(100 *num / this->m_NumImages),_ansi );
				 }

			}
		}
	  }
	  while(FindNext(sr) == 0);
	  FindClose(sr);
   }
}

TLFSemanticDictinary* __fastcall TDbLabeledImages::GetDictionary()
{
	return &m_dictionary;
}

void __fastcall TDbLabeledImages::SaveBackground(SDbExportOptions& options)
{
    //
    if (options.ClassLabels == NULL)
    	return;
    for(int i = 0; i < options.ClassLabels->Count; i++)
    {
		AnsiString strPath = options.strPathToExport;
        strPath += "\\";
        strPath += options.ClassLabels->Strings[i];
        strPath += "\\";
        strPath += "bkg\\";
	    // clear old background
        if (DirectoryExists(strPath))
			ClearDir(strPath);
        else
			CreateDir(strPath);

        // copty data to this path
       TSearchRec sr;
       AnsiString strSourcePath = m_strDbName;
       strSourcePath += "\\*.xml";

       int iAttr =0;
       iAttr |= faAnyFile;
       int num = 0;
       int count = 0;
       AnsiString strClassLabel = options.ClassLabels->Strings[i];
        if (FindFirst(strSourcePath, iAttr, sr) == 0)
        {
          do
          {
             TLFSemanticImageDescriptor sd;
             num++;
             awpImage* img = NULL;
             bool exist = false;
             AnsiString strTmpFile = ChangeFileExt(sr.Name, ".jpg");
             AnsiString strFullName = m_strDbName;
             strFullName += "\\";
             if (FileExists(strTmpFile))
             {
               exist = true;
               strFullName += strTmpFile;
               awpLoadImage(strFullName.c_str(), &img);
             }
             else
             {
                strTmpFile = ChangeFileExt(sr.Name, ".jpeg");
                if (FileExists(strTmpFile))
                {
                    strFullName += strTmpFile;
                    awpLoadImage(strFullName.c_str(), &img);
                    exist = true;
                }
                else
                {
                  strTmpFile = ChangeFileExt(sr.Name, ".awp");
                  if (FileExists(strTmpFile))
                  {
                      strFullName += strTmpFile;
                      awpLoadImage(strFullName.c_str(), &img);
                      exist = true;
                  }
                }
             }
             if (!exist)
                continue;

             AnsiString _ansi = sr.Name;
             sd.LoadXML(_ansi.c_str());
             sd.SetImage(img);

             for (int i = sd.GetItemsCount() - 1; i >= 0 ; i--)
             {
                TLFDetectedItem*  di = sd.GetDetectedItem(i);
                if (di == NULL)
                    continue;

                UnicodeString strClassLabel0 = di->GetType().c_str();
                if (options.ClassLabels->IndexOf(strClassLabel0) < 0)
                    continue;
                AnsiString _ansi = strClassLabel0;
                if (_ansi != strClassLabel)
                {
					sd.Delete(i);
                }
             }

             AnsiString strOutFileName = strPath;
             strOutFileName += ExtractFileName(strTmpFile);
             awpSaveImage(strOutFileName.c_str(), img);
             strOutFileName = ChangeFileExt(strOutFileName, ".xml");
             sd.SaveXML(strOutFileName.c_str());

             awpReleaseImage(&img);
             if (m_ProgressEvent != NULL)
             {
                AnsiString strComment = "Processed ";
                strComment += IntToStr (num);
                strComment += " of ";
                strComment += IntToStr(m_NumXmlFiles);
                strComment += " for class label ";
                strComment +=  strClassLabel;
                m_ProgressEvent(int(100 *num / m_NumXmlFiles),strComment);
             }

             Application->ProcessMessages();

          }while(FindNext(sr) == 0);
          FindClose(sr);
        }
    }
}


void __fastcall TDbLabeledImages::SplitDatabase(UnicodeString strPath, UnicodeString strPath1, UnicodeString strpath2, double propValue )
{

	srand ( time(NULL) );
    AnsiString str = strPath.c_str();
	string path 	     =  str.c_str();
	path += "\\";
    str  = strPath1.c_str();
	string g_path1       =  str.c_str();
    str  = strpath2.c_str();
	string g_path2       =  str.c_str();;
	int g_proc = propValue;


	if (!LFDirExist(g_path1.c_str()))
		LFCreateDir(g_path1.c_str());
	if (!LFDirExist(g_path2.c_str()))
		LFCreateDir(g_path2.c_str());
	AnsiString _ansi = g_path1.c_str();
	ClearDir(_ansi);
	_ansi = g_path2.c_str();
	ClearDir(_ansi);

	_finddata_t filesInfo;
	int num_images = 0;
	long handle = 0;

	if ( (handle = _findfirst( (char*)((path+"*.*").c_str()), &filesInfo)) != -1 )
	{
		do
		{
			string name = path + filesInfo.name;
			TLFImage image;
			UnicodeString _unicode = name.c_str();
			if (!_IsImageFile(_unicode))
				continue;

			if (!image.LoadFromFile(name.c_str()))
			{
				printf("cannot load image %s \n", name.c_str());
				continue;
			}
			num_images++;
			std::string FileName;

			int value = rand() % 100;
			if (value < g_proc)
				FileName = g_path1;
			else
				FileName = g_path2;

			FileName += LFGetFileName(name);//LFIntToStr(num_images);
			FileName += ".awp";
			printf("%s\n", FileName.c_str());
			image.SaveToFile(FileName.c_str());

			name = LFChangeFileExt(name, ".xml");
			if (LFFileExists(name))
			{
				TLFSemanticImageDescriptor d;
				d.LoadXML(name.c_str());
				FileName = LFChangeFileExt(FileName, ".xml");
				d.SaveXML(FileName.c_str());
			}

			  if (m_ProgressEvent != NULL)
			  {
				AnsiString _ansi = FileName.c_str();
				m_ProgressEvent(int(100 *num_images / this->m_NumImages),_ansi );
			  }
			   Application->ProcessMessages();

		}while(!_findnext( handle, &filesInfo ));
	}
	_findclose( handle );


}

