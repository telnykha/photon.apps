//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "PriMain.h"
#include "Buf_USBCCDCamera_SDK.h"
#include "ComReaderUnit.h"
#include "About.h"
#include "VerInfoUnit.h"
#include "OptionsUnit.h"
#include "VCLTee.TeePrevi.hpp"
#include "PriRoiEditor.h"
#include "PriCalibrationForm.h"
#include "CaptureDataUnit.h"
#include "SelectDirUnit.h"
#include "ExportPriUnit.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FImage41"
#pragma link "PhImageTool"
#pragma link "PhPaneTool"
#pragma link "PhZoomToRectTool"
#pragma link "photon41.lib"
#pragma resource "*.dfm"

#pragma link "BUF_USBCCDCamera_SDK_b.lib"
#pragma link "awpipl2b.lib"
#pragma link "awplflibb.lib"
#pragma link "JPEGLIB.lib"
#pragma link "TinyXML.lib"

TMainForm *MainForm;

extern HANDLE COMport;
extern unsigned char bufrd1[BUFSIZE];
extern unsigned char bufwr[BUFSIZE];

void CamHook(TProcessedDataProperty* Attributes, unsigned char *BytePtr)
{
	 if (MainForm != NULL)
	 {
		MSG msg;
		if(GetMessage(&msg,NULL,NULL,NULL))
		{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
		}
		if (MainForm->CameraMode == 1)
			MainForm->SetFrame(Attributes->Column, Attributes->Row, BytePtr, Attributes->CameraID);
		else if (MainForm->CameraMode == 0)
			MainForm->PreviewFrame(Attributes->Column, Attributes->Row, BytePtr, Attributes->CameraID);
	 }
}


//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
	m_frameNum1 = 0;
	m_frameNum2 = 0;
	m_pInitFile = NULL;
	m_cameras = NULL;
	m_numCameras = 0;
	m_mode = 1;

	m_roiTool = NULL;
	m_roiTool = new TPhPriRoiEditor(NULL);
	m_roiTool->PhImage = PhImage4;
	m_seriesCounter = 0;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SetFrame(int width, int height, unsigned char* data, int cameraID)
{
	int type = AWP_DOUBLE;
	if (cameraID == 1)
	{
		m_frameNum1++;
		if (m_frameNum1 % 2 != 0)
		{
			if (m_image1 == NULL)
				awpCreateImage(&m_image1, width, height, 1, type);
		   AWPDOUBLE* d = (AWPDOUBLE*)m_image1->pPixels;
		   int x,y, i=0;
		   for (x = 0; x < width; x++)
		   {
			   for (y = 0; y < height; y++)
			   {
				   AWPWORD value = data[2*y + 2*x*height+ 1];
				   AWPWORD v2 = data[2*y + 2*x*height];
				   v2 = v2 << 4;
				   value |= v2;
				   d[i] = (AWPDOUBLE)value;
				   i++;
			   }

		   }
		}
		else
		{
		   if (m_image11 == NULL)
				awpCreateImage(&m_image11, width, height, 1, type);
		   AWPDOUBLE* d = (AWPDOUBLE*)m_image11->pPixels;
		   int x,y, i=0;
		   for (x = 0; x < width; x++)
		   {
			   for (y = 0; y < height; y++)
			   {
				   AWPWORD value = data[2*y + 2*x*height+ 1];
				   AWPWORD v2 = data[2*y + 2*x*height];
				   v2 = v2 << 4;
				   value |= v2;
				   d[i] = value;
				   i++;
			   }

		   }
		}
	}
	else
	{
	   m_frameNum2++;
	   if (m_frameNum2 % 2 != 0)
	   {
		   if (m_image2 == NULL)
				awpCreateImage(&m_image2, width, height, 1, type);
		   AWPDOUBLE* d = (AWPDOUBLE*)m_image2->pPixels;
		   int x,y, i=0;
		   for (x = 0; x < width; x++)
		   {
			   for (y = 0; y < height; y++)
			   {
				   AWPWORD value = data[2*y + 2*x*height+ 1];
				   AWPWORD v2 = data[2*y + 2*x*height];
				   v2 = v2 << 4;
				   value |= v2;
				   d[i] = value;
				   i++;
			   }

		   }
		   awpFlip(&m_image2, AWP_FLIP_HRZT);
	   }
	   else
	   {
		   if (m_image22 == NULL)
				awpCreateImage(&m_image22, width, height, 1, type);

		   AWPDOUBLE* d = (AWPDOUBLE*)m_image22->pPixels;
		   int x,y, i=0;
		   for (x = 0; x < width; x++)
		   {
			   for (y = 0; y < height; y++)
			   {
				   AWPWORD value = data[2*y + 2*x*height+ 1];
				   AWPWORD v2 = data[2*y + 2*x*height];
				   v2 = v2 << 4;
				   value |= v2;
				   d[i] = value;
				   i++;
			   }

		   }
		   awpFlip(&m_image22, AWP_FLIP_HRZT);
	   }
	}
}
void __fastcall TMainForm::PreviewFrame(int width, int height, unsigned char* data, int cameraID)
{
	int type = AWP_DOUBLE;
	int size = sizeof(AWPDOUBLE);
	awpImage* img = NULL;
	awpCreateImage(&img, width, height, 1, AWP_BYTE);
	AWPBYTE* dst = (AWPBYTE*)img->pPixels;
	memcpy(dst, data, width*height);
	awpResize(img, width, height);

	if (cameraID == 1)
	{
			PhImage3->SetAwpImage(img);
			if(m_viewCamera == 0)
				PhImage1->SetAwpImage(img);
	}
	else
	{
		   awpFlip(&img, AWP_FLIP_HRZT);
		   PhImage2->SetAwpImage(img);
			if(m_viewCamera == 1)
				PhImage1->SetAwpImage(img);

	}
	awpReleaseImage(&img);

}
void __fastcall TMainForm::FormCreate(TObject *Sender)
{
	this->ClearTable();
	m_viewCamera = 0;
	m_pInitFile = new TPriInitFile();
	if (!COMOpen(m_pInitFile->strCom)) {
	   //ShowMessage(L"Не могу найти плату Arduino.");
	}
	m_arcive.path = m_pInitFile->strArchive;

	m_numCameras = BUFCCDUSB_InitDevice();
	if (m_numCameras == 0)
	{
	   BUFCCDUSB_UnInitDevice();
	   PageControl1->Pages[0]->TabVisible = false;
	}
	else
	{
		m_cameras = new int[m_numCameras];
		for (int i = 0; i < m_numCameras; i++)
		{
			m_cameras[i] = i+1;
			BUFCCDUSB_AddDeviceToWorkingSet(m_cameras[i]);
		}
		BUFCCDUSB_InstallFrameHooker( 0, CamHook );
		int bits = this->m_pInitFile->inputData == 0 ? 8 : 12;
		int ret = BUFCCDUSB_StartCameraEngine(this->Handle, bits);
		for (int i = 0; i < m_numCameras; i++)
		{
			BUFCCDUSB_SetCameraWorkMode(m_cameras[i], m_mode);
			BUFCCDUSB_SetFrameTime( m_cameras[i], 1000);
		}
		BUFCCDUSB_StartFrameGrab(GRAB_FRAME_FOREVER);
		StopVideoEngine();

		//
		SpinEdit1->Value = m_pInitFile->dx;
		SpinEdit2->Value = m_pInitFile->dy;
		SpinEdit3->Value = (int)(m_pInitFile->scale * 1000);
	}

	SpeedButton8->Caption = L"";
	SpeedButton9->Caption = L"";
	SpeedButton10->Caption = L"";
	SpeedButton11->Caption = L"";
	SpeedButton12->Caption = L"";

	TNotifyEvent e1 = TrackBar1->OnChange;
	TNotifyEvent e2 = ComboBox1->OnChange;

	TrackBar1->OnChange = NULL;
	ComboBox1->OnChange = NULL;

	TrackBar1->Position  = iniFile->exploshureValue;
	ComboBox1->ItemIndex = iniFile->exploshureIndex;

	TrackBar1->OnChange = e1;
    ComboBox1->OnChange = e2;
}
EPriBlurMode __fastcall TMainForm::GetBlurMode()
{
	EPriBlurMode result = modeNone;
	if (viewPRIAction->Checked)
	{
		result = modeNone;
	}
	else if (viewPRI3x3Action->Checked)
	{
		result = modeBlur;
	}
	else if (viewPRI5x5Action->Checked)
	{
		result = modeBlurMore;
	}
	else
		result = modeNone;
	return result;
}


//---------------------------------------------------------------------------
void __fastcall TMainForm::ProcessData(bool saveArchive)
{
	if (m_image11 ==0) {
		return;
	}

	_AWP_SAFE_RELEASE_(m_pri)
	m_processor.blurMode =  GetBlurMode();
	if (!m_processor.PriProcessImages(m_image11, m_image22, m_image1, m_image2 ))
	{
		ShowMessage("Ошибка алгоритма.");
	}

	awpCopyImage(m_processor.pri, &m_pri);



	if (saveArchive)
		m_arcive.Save(this);

	RenderImage();
	UpdateChart();
}

void __fastcall TMainForm::SaveData()
{
	if (m_image11 ==0) {
		return;
	}


	m_seriesCounter++;
	CaptureForm->CGauge1->Progress = m_seriesCounter;
	CaptureForm->Label1->Caption = L"Общее время записи " +
	IntToStr(this->m_pInitFile->seriesInterval*this->m_pInitFile->seriesTotal) +
	L" секунд. Осталось: " + IntToStr(m_pInitFile->seriesInterval*m_pInitFile->seriesTotal-m_seriesCounter*m_pInitFile->seriesInterval)+
	L" секунд ";
	CaptureForm->Label2->Caption = L"Измерение " + IntToStr(m_seriesCounter) + L" из " + IntToStr(this->m_pInitFile->seriesTotal);

	awpImage* _531 = NULL;
	awpImage* _570 = NULL;

	awpCopyImage(m_image11, &_531);
	awpCopyImage(m_image22, &_570);

	awpConvert(_531, AWP_CONVERT_TO_BYTE_WITH_NORM);

	CaptureForm->PhImage1->SetAwpImage(_531);

	awpConvert(_570, AWP_CONVERT_TO_BYTE_WITH_NORM);

	CaptureForm->PhImage3->SetAwpImage(_570);

	awpReleaseImage(&_531);
	awpReleaseImage(&_570);

	m_arcive.Save(this);

	ClearPictures();

	if (m_seriesCounter >= m_pInitFile->seriesTotal)
	{
		CaptureForm->Button1Click(NULL);
		TabSheet3Show(NULL);
		ListBox1->ItemIndex = ListBox1->Items->Count - 1;
        ReadArchive();
	}

}


void   __fastcall TMainForm::NormAndSetPri()
{
	if (m_pri == NULL)
		return;

	awpConvert(m_pri, AWP_CONVERT_TO_FLOAT);

    awpImage* _pri_norm = NULL;
	awpCreateImage(&_pri_norm, m_pri->sSizeX, m_pri->sSizeY, 1, AWP_BYTE);
    AWPBYTE* _pri = (AWPBYTE*)_pri_norm->pPixels;
    AWPFLOAT* pri0 = (AWPFLOAT*)m_pri->pPixels;

    for (int i = 0; i < m_pri->sSizeX*m_pri->sSizeY; i++) {
        _pri[i] = 127*(1+pri0[i]);
	}

    PhImage4->SetAwpImage(_pri_norm);
	_AWP_SAFE_RELEASE_(_pri_norm);
}
void __fastcall TMainForm::CloseButtonClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::fileCloseActionExecute(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::deviceCalibrationActionExecute(TObject *Sender)
{
//Переключение программы в режим калибровки.
	if (CalibrationDlg->ShowModal() == mrOk)
	{
		// сохраняем калибровочную информацию
#ifdef _DEBUG
		ShowMessage("Save calibration.");
#endif
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::deviceCalibrationActionUpdate(TObject *Sender)
{
	//deviceCalibrationAction->Enabled = m_numCameras > 0;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::deviceExperimentActionExecute(TObject *Sender)
{
	this->StopVideoEngine();

	m_seriesCounter = 0;
	CaptureForm->CGauge1->MinValue = 0;

	CaptureForm->CGauge1->MaxValue = this->iniFile->seriesTotal;
	CaptureForm->CGauge1->Progress = 0;
	Timer1->Interval= m_pInitFile->seriesInterval*1000;
	CaptureForm->Button1->Caption = L"Начать запись";
	CaptureForm->Label1->Caption  = L"Общее время записи:";
	CaptureForm->Label2->Caption = L"Измерение:";
	StartVideoEngine();
	CaptureForm->ShowModal();
}

void __fastcall TMainForm::StartVideoEngine()
{
	m_mode = 1;
	m_numCameras = BUFCCDUSB_InitDevice();
	m_cameras = new int[m_numCameras];
	for (int i = 0; i < m_numCameras; i++)
	{
		m_cameras[i] = i+1;
		BUFCCDUSB_AddDeviceToWorkingSet(m_cameras[i]);
	}
	BUFCCDUSB_InstallFrameHooker( 0, CamHook );
	int ret = BUFCCDUSB_StartCameraEngine(this->Handle, 12);
	for (int i = 0; i < m_numCameras; i++)
	{
		BUFCCDUSB_SetCameraWorkMode(m_cameras[i], m_mode);
		BUFCCDUSB_SetFrameTime( m_cameras[i], 1000);
	}
	BUFCCDUSB_StartFrameGrab(GRAB_FRAME_FOREVER);
	ExploshureTime(ComboBox1->ItemIndex, TrackBar1->Position);
}

void __fastcall TMainForm::StopVideoEngine()
{
	if (m_cameras == NULL)
		return;

	BUFCCDUSB_StopFrameGrab();
	BUFCCDUSB_StopCameraEngine();
	for (int i = 0; i < m_numCameras; i++)
	{
		BUFCCDUSB_RemoveDeviceFromWorkingSet(m_cameras[i]);
	}
	BUFCCDUSB_UnInitDevice();
	m_mode = 2;
	delete m_cameras;
	m_cameras = NULL;
}

//---------------------------------------------------------------------------

void __fastcall TMainForm::deviceExperimentActionUpdate(TObject *Sender)
{
	deviceExperimentAction->Enabled = m_numCameras > 0;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::toolsOptionsActionExecute(TObject *Sender)
{
// Вызвать диалог настройки параметров программы.
    Form3->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::helpAboutActionExecute(TObject *Sender)
{
// вызвать диалог "о программе..."
	TVersionInfo* info = new TVersionInfo(NULL);
    AboutBox->ProductName->Caption = info->ProductName;
    AboutBox->Version->Caption = info->FileVersion;
    AboutBox->Copyright->Caption = info->LegalCopyright;

    AboutBox->ShowModal();
	delete info;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::helpContestsActionExecute(TObject *Sender)
{
	UnicodeString adr = ExtractFilePath(Application->ExeName);
    adr+= "\\manual.pdf";
	ShellExecute(this->WindowHandle,L"open",adr.c_str() ,NULL,NULL, SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------
// отображаем архив
void __fastcall TMainForm::TabSheet3Show(TObject *Sender)
{
	TSearchRec serchmas;//класс для хранения результата поиска
	AnsiString S,str="";
	this->ListBox1->Clear();
	UnicodeString path = m_arcive.path;
	path += "\\*.*";
	if (FindFirst(path, faDirectory, serchmas)==0)//ищем каталог(faDirectory)без маски('*')-то есть все какие есть
	{
		//do
		while (FindNext(serchmas) != -1)
		{
			if(serchmas.Name==str)
				break;//если каталог уже встречался -выходим
			str=serchmas.Name;//запоминаем имя текущего каталога
			if((serchmas.Name==".")||(serchmas.Name==".."))
				continue;//пропускаем
			if (serchmas.Attr & faDirectory)
				ListBox1->Items->Add(serchmas.Name);

		}
		FindClose(serchmas);//закрываем экземпляр класса, освобождаем ресурсы
	}
}
//---------------------------------------------------------------------------
// чтение эксперимертальных данных
void __fastcall TMainForm::ListBox1Click(TObject *Sender)
{
	ReadArchive();
}
//---------------------------------------------------------------------------
// выбор измерения для отображения
void __fastcall TMainForm::ListBox2Click(TObject *Sender)
{
	if (!LoadArchiveEntry())
	{
		ShowMessage(L"Не могу считать архив!");
	}
}
//---------------------------------------------------------------------------
bool __fastcall TMainForm::LoadArchiveEntry()
{
	ClearPictures();
	UnicodeString path = m_arcive.path;
	path += L"\\";
	path += ListBox1->Items->Strings[ListBox1->ItemIndex];
	path += L"\\";
	path += ListBox2->Items->Strings[ListBox2->ItemIndex];
	path += L"\\";
	if (!m_arcive.Load(path))
	{
		if (!m_arcive.LoadPRI(path)) {
			ClearPictures();
			return false;
		}
		NormAndSetPri();
	}
	ProcessData(false);
	return true;
}

void __fastcall TMainForm::ClearPictures()
{
     if (m_image1 != NULL)
    {
        _AWP_SAFE_RELEASE_(m_image1)
        m_image1 = NULL;
    }
    if (m_image2 != NULL)
	{
		_AWP_SAFE_RELEASE_(m_image2)
		m_image2 = NULL;
	}

	if (m_image11 != NULL)
	{
		_AWP_SAFE_RELEASE_(m_image11)
		m_image11 = NULL;
	}
	if (m_image22 != NULL)
	{
		_AWP_SAFE_RELEASE_(m_image22)
		m_image22 = NULL;
	}
	if (m_pri != NULL)
	{
		_AWP_SAFE_RELEASE_(m_pri)
		m_pri = NULL;
	}
	m_frameNum1  = 0;
	m_frameNum2 = 0;
}

void __fastcall TMainForm::viewPRIActionExecute(TObject *Sender)
{
	if (viewPRIAction->Checked && m_pri != NULL)
	{
		return;
	}

	viewPRIAction->Checked = true;
	ProcessData(false);
	RenderImage();
    ClearTable();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::viewPRIActionUpdate(TObject *Sender)
{
	viewPRIAction->Enabled = m_pri != NULL;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::view531ActionExecute(TObject *Sender)
{
	view531Action->Checked = true;
	RenderImage();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::view531ActionUpdate(TObject *Sender)
{
	view531Action->Enabled = m_image1 != NULL;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::view570ActionExecute(TObject *Sender)
{
	view570Action->Checked = true;
	RenderImage();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::view570ActionUpdate(TObject *Sender)
{
	view570Action->Enabled = m_image2 != NULL;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::view531fActionExecute(TObject *Sender)
{
	view531fAction->Checked = true;
	RenderImage();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::view531fActionUpdate(TObject *Sender)
{
	view531fAction->Enabled = m_image11 != NULL;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::view570fActionExecute(TObject *Sender)
{
    view570fAction->Checked = true;
	RenderImage();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::view570fActionUpdate(TObject *Sender)
{
	view570fAction->Enabled = m_image22 != NULL;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::RenderImage()
{
	if ((/*viewPRIAction->Enabled &&*/ viewPRIAction->Checked) ||
	(/*viewPRI3x3Action->Enabled &&*/ viewPRI3x3Action->Checked) ||
	(/*viewPRI5x5Action->Enabled && */viewPRI5x5Action->Checked))
	{
		NormAndSetPri();
		return;
	}

	if (view531Action->Enabled && view531Action->Checked)
	{
		NormAndSetImage(m_image1);
		return;
	}
	if (view531fAction->Enabled && view531fAction->Checked)
	{
		NormAndSetImage(m_image11);
		return;
	}
	if (view570Action->Enabled && view570Action->Checked)
	{
		NormAndSetImage(m_image2);
		return;
	}
	if (view570fAction->Enabled && view570fAction->Checked)
	{
		NormAndSetImage( m_image22);
		return;
	}
}

void __fastcall TMainForm::NormAndSetImage(awpImage* img)
{
	awpImage* _display = NULL;
	awpImage* _display_cut = NULL;

	awpCopyImage(img, &_display);

	awpConvert(_display, AWP_CONVERT_TO_BYTE_WITH_NORM);

   // вырезаем фрагменты изображения в соответствии с параметрами калибровки.
   awpRect r;
   r.left   = BORDER_SIZE;
   r.top    = BORDER_SIZE;
   r.right  = _display->sSizeX - BORDER_SIZE;
   r.bottom = _display->sSizeY - BORDER_SIZE;

   awpCopyRect(_display, &_display_cut, &r);

	PhImage4->SetAwpImage(_display_cut);

	_AWP_SAFE_RELEASE_(_display)
	_AWP_SAFE_RELEASE_(_display_cut)
}

void __fastcall TMainForm::fileExportTableActionExecute(TObject *Sender)
{
	if (SaveDialog1->Execute())
	{
		//Save table
		AnsiString _ansi = SaveDialog1->FileName;
		FILE* file = fopen(_ansi.c_str(), "w+t");
		for (int i = 0; i < StringGrid1->RowCount; i++)
		{
			for(int j = 0; j < StringGrid1->ColCount; j++)
			{
			  double d = StrToFloat(StringGrid1->Cells[j][i]);
			  float  f = (float)d;
			  fprintf(file, "%f\t",f);
			}
			fprintf(file, "\n");
		}
		fclose(file);
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::fileExportTableActionUpdate(TObject *Sender)
{
	fileExportTableAction->Enabled = StringGrid1->RowCount > 1;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::fileExportImageActionExecute(TObject *Sender)
{
	if (SaveDialog2->Execute())
	{
		PhImage4->SaveToFile(SaveDialog2->FileName.c_str());
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::fileExportImageActionUpdate(TObject *Sender)
{
    fileExportImageAction->Enabled = !PhImage4->Empty;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::filePrintActionExecute(TObject *Sender)
{
  TeePreview(this, Chart1);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::filePrintActionUpdate(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::editCopyImageActionExecute(TObject *Sender)
{
	PhImage4->SaveToClipBoard();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::editCopyImageActionUpdate(TObject *Sender)
{
	editCopyImageAction->Enabled = !PhImage4->Empty;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::editCopyChartActionExecute(TObject *Sender)
{
   Chart1->CopyToClipboardBitmap();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::editCopyChartActionUpdate(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::editCopyTableActionExecute(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::editCopyTableActionUpdate(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::viewBestFitActionExecute(TObject *Sender)
{
	PhImage4->BestFit();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::viewBestFitActionUpdate(TObject *Sender)
{
	viewBestFitAction->Enabled = !PhImage4->Empty;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::viewActualSizeActionUpdate(TObject *Sender)
{
	viewActualSizeAction->Enabled = !PhImage4->Empty;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::viewActualSizeActionExecute(TObject *Sender)
{
	PhImage4->ActualSize();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::viewPRI3x3ActionExecute(TObject *Sender)
{

	if (viewPRI3x3Action->Checked && m_pri != NULL)
	{
		return;
	}

	viewPRI3x3Action->Checked = true;
	ProcessData(false);
	RenderImage();
	ClearTable();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::viewPRI3x3ActionUpdate(TObject *Sender)
{
	viewPRI3x3Action->Enabled = m_image11 != NULL;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::viewPRI5x5ActionExecute(TObject *Sender)
{
	if (viewPRI5x5Action->Checked && m_pri != NULL)
	{
		return;
	}

	viewPRI5x5Action->Checked = true;
	ProcessData(false);
	RenderImage();
	ClearTable();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::viewPRI5x5ActionUpdate(TObject *Sender)
{
	viewPRI5x5Action->Enabled = m_image11 != NULL;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::viewPaneActionExecute(TObject *Sender)
{
	 PhImage4->SelectPhTool(PhPaneTool1);
	 GroupBox3->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::viewPaneActionUpdate(TObject *Sender)
{
	viewPaneAction->Enabled = !PhImage4->Empty;
	viewPaneAction->Checked =  dynamic_cast< TPhPaneTool*>(PhImage4->PhTool) != NULL;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::viewZoomActionExecute(TObject *Sender)
{
		 PhImage4->SelectPhTool(PhZoomToRectTool1);
		 GroupBox3->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::viewZoomActionUpdate(TObject *Sender)
{
	viewZoomAction->Enabled = !PhImage4->Empty;
	viewZoomAction->Checked = dynamic_cast< TPhZoomToRectTool*>(PhImage4->PhTool) != NULL;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::viewEditRoiActionExecute(TObject *Sender)
{
	m_roiTool->PhImage = PhImage4;
    m_roiTool->OnAddRoi = OnAddRoi;
	PhImage4->SelectPhTool(m_roiTool);
    GroupBox3->Enabled = m_roiTool->GetItemsCount() > 0;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::viewEditRoiActionUpdate(TObject *Sender)
{
	viewEditRoiAction->Enabled = !PhImage4->Empty;
	viewEditRoiAction->Checked = dynamic_cast< TPhPriRoiEditor*>(PhImage4->PhTool) != NULL;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::UpdateImageStatus()
{
	// если изображения нет, то и суда нет
	if (PhImage4->Empty)
	{

	}
}

void __fastcall TMainForm::OnAddRoi(TObject *Sender, TPriRoiItem* item)
{
	UnicodeString str;
	str = FormatFloat("x=000.0:", item->GetX());
	str += FormatFloat("y=000.0:", item->GetY());
	str += FormatFloat("r=000.0:", item->GetR());

	CheckListBox1->Items->Add(str);

	UnicodeString path = m_arcive.path;
	path += L"\\";
	path += ListBox1->Items->Strings[ListBox1->ItemIndex];
	path += "\\";
	m_roiTool->Save(path);
	this->ClearTable();
    GroupBox3->Enabled = true;
}


void __fastcall TMainForm::CheckListBox1Click(TObject *Sender)
{

	m_roiTool->Selected = CheckListBox1->ItemIndex;
   //	if (dynamic_cast< TPhPriRoiEditor*>(PhImage4->PhTool) != NULL)
	{
         PhImage4->Paint();
		 TPriRoiItem* item = m_roiTool->GetItem(CheckListBox1->ItemIndex);
		 if (item != NULL)
		 {
			TNotifyEvent e = SpinEdit4->OnChange;
			SpinEdit4->OnChange = NULL;
			SpinEdit4->Value = item->GetX();
			SpinEdit4->OnChange = e;

			e = SpinEdit5->OnChange;
			SpinEdit5->OnChange = NULL;
			SpinEdit5->Value = item->GetY();
			SpinEdit5->OnChange = e;

			e = SpinEdit6->OnChange;
			SpinEdit6->OnChange = NULL;
			SpinEdit6->Value = item->GetR();
			SpinEdit6->OnChange = e;
		 }
	}
	UpdateChart();
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::PhImage4ToolChange(TObject *Sender)
{
	PhImage4->Paint();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::roisDeleteActionExecute(TObject *Sender)
{
	m_roiTool->Delete(CheckListBox1->ItemIndex);

	UnicodeString path = m_arcive.path;
	path += L"\\";
	path += ListBox1->Items->Strings[ListBox1->ItemIndex];
	path += "\\";


	m_roiTool->Save(path);
	UpdateCheckList();
    this->ClearTable();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::roisDeleteActionUpdate(TObject *Sender)
{
	roisDeleteAction->Enabled = CheckListBox1->Count > 0 && CheckListBox1->ItemIndex >= 0;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::UpdateCheckList()
{
	CheckListBox1->Clear();
	for (int i = 0; i < m_roiTool->GetItemsCount(); i++)
	{
	   TPriRoiItem* item = m_roiTool->GetItem(i);
	   if (item != NULL)
	   {
			UnicodeString str;
			str = FormatFloat("x=000.0:", item->GetX());
			str += FormatFloat("y=000.0:", item->GetY());
			str += FormatFloat("r=000.0:", item->GetR());

			CheckListBox1->Items->Add(str);
	   }
	}
	GroupBox3->Enabled = m_roiTool->GetItemsCount() > 0 && dynamic_cast< TPhPriRoiEditor*>(PhImage4->PhTool) != NULL;
}


void __fastcall TMainForm::roisClearActionExecute(TObject *Sender)
{
	m_roiTool->ClearAll();

	UnicodeString path = m_arcive.path;
	path += L"\\";
	path += ListBox1->Items->Strings[ListBox1->ItemIndex];
	path += "\\";


	m_roiTool->Save(path);
	UpdateCheckList();
	GroupBox3->Enabled = false;
	this->ClearTable();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::roisClearActionUpdate(TObject *Sender)
{
    roisDeleteAction->Enabled = CheckListBox1->Count > 0;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::roisCalcActionExecute(TObject *Sender)
{
	ListBox1->Enabled = false;
	ListBox2->Enabled = false;
	CheckListBox1->Enabled = false;
	Panel1->Enabled = false;
	Panel11->Enabled = false;
	N1->Enabled = false;
	N4->Enabled = false;
	N15->Enabled = false;
	N28->Enabled = false;
	N3->Enabled = false;
	N5->Enabled = false;
	N6->Enabled = false;

	Calculation();

	ListBox1->Enabled = true;
	ListBox2->Enabled = true;
	CheckListBox1->Enabled = true;
	Panel1->Enabled = true;
	Panel11->Enabled = true;
	N1->Enabled = true;
	N4->Enabled = true;
	N15->Enabled = true;
	N28->Enabled = true;
	N3->Enabled = true;
	N5->Enabled = true;
	N6->Enabled = true;

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::roisCalcActionUpdate(TObject *Sender)
{
	bool enabled = StringGrid1->ColCount == 1;
	enabled = enabled && m_roiTool->GetItemsCount() > 0;
	// && edited
    roisCalcAction->Enabled = enabled;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SpinEdit4Change(TObject *Sender)
{
	 if (dynamic_cast< TPhPriRoiEditor*>(PhImage4->PhTool) != NULL)
	 {
		m_roiTool->EditSelected(SpinEdit4->Value, SpinEdit5->Value, SpinEdit6->Value);
		UnicodeString path = m_arcive.path;
		path += L"\\";
		path += ListBox1->Items->Strings[ListBox1->ItemIndex];
		path += "\\";


		m_roiTool->Save(path);
        this->ClearTable();
	 }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SpinEdit5Change(TObject *Sender)
{
	 if (dynamic_cast< TPhPriRoiEditor*>(PhImage4->PhTool) != NULL)
	 {
		m_roiTool->EditSelected(SpinEdit4->Value, SpinEdit5->Value, SpinEdit6->Value);

		UnicodeString path = m_arcive.path;
		path += L"\\";
		path += ListBox1->Items->Strings[ListBox1->ItemIndex];
		path += "\\";


		m_roiTool->Save(path);
        this->ClearTable();
	 }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SpinEdit6Change(TObject *Sender)
{
	 if (dynamic_cast< TPhPriRoiEditor*>(PhImage4->PhTool) != NULL)
	 {
		m_roiTool->EditSelected(SpinEdit4->Value, SpinEdit5->Value, SpinEdit6->Value);

		UnicodeString path = m_arcive.path;
		path += L"\\";
		path += ListBox1->Items->Strings[ListBox1->ItemIndex];
		path += "\\";


		m_roiTool->Save(path);
        this->ClearTable();
	 }
}

void __fastcall TMainForm::PhImage4Paint(TObject *Sender)
{
	if (dynamic_cast< TPhPriRoiEditor*>(PhImage4->PhTool) == NULL)
	{
		TCanvas* c = PhImage4->Canvas;
		c->Pen->Color = clWhite;
		c->Pen->Width = 2;
		c->Brush->Style = bsClear;
		for (int i = 0; i < m_roiTool->GetItemsCount(); i++)
		{
		   TPriRoiItem* ri = m_roiTool->GetItem(i);
		   TRect rect =  m_roiTool->GetRoiRect(ri);
		   c->Ellipse(rect);
		}

		if (m_roiTool->Selected >= 0)
		{
		   c->Pen->Color = clRed;
		   TPriRoiItem* ri = m_roiTool->GetItem(m_roiTool->Selected);
		   TRect rect =  m_roiTool->GetRoiRect(ri);
		   c->Ellipse(rect);
		}

		c->Pen->Width = 1;
	}

	if (PhImage4->Bitmap != NULL)
	{
		StatusBar1->Panels->Items[1]->Text = FormatFloat("Zoom: ###.##", PhImage4->Scale);
	}
}
static _awpAverageStdDev(awpImage* img, double& a, double& s)
{
	AWPDOUBLE* d = (AWPDOUBLE*)img->pPixels;
	AWPDOUBLE  _a = 0;
	AWPDOUBLE  _s = 0;
	for (int i = 0; i < img->sSizeX*img->sSizeY; i++) {
		_a += d[i];
		_s += (d[i]*d[i]);
	}
	a  = _a / (img->sSizeX*img->sSizeY);
	_s = _s / (img->sSizeX*img->sSizeY);
	s = sqrt(_s - a*a);
}
//---------------------------------------------------------------------------
// эта функция выполняет расчет по заданным пользователем параметрам.
void __fastcall TMainForm::Calculation()
{
	if (m_roiTool->GetItemsCount() == 0)
		return;
	if (ListBox2->Items->Count == 0)
		return;

	StringGrid1->ColCount = 2*m_roiTool->GetItemsCount();
	StringGrid1->RowCount = ListBox2->Items->Count;

	awpImage* result = NULL;
	awpCreateImage(&result, 2*m_roiTool->GetItemsCount(), ListBox2->Items->Count, 1, AWP_DOUBLE);
	AWPDOUBLE* data = (AWPDOUBLE*)result->pPixels;

	int w = 2*m_roiTool->GetItemsCount();
	int h = ListBox2->Items->Count;
	// выполняем цикл по всем элементам ListBox2
	// результат записываем в изображение формата awp
	for (int i = 0; i < ListBox2->Items->Count; i++)
	{
		// формирование имени файла
		UnicodeString path = m_arcive.path;
		path += L"\\";
		path += ListBox1->Items->Strings[ListBox1->ItemIndex];
		path += L"\\";
		path += ListBox2->Items->Strings[i];
		path += L"\\";
		// загрузка изображений
		awpImage* i531 = NULL;
		awpImage* i570 = NULL;
		awpImage* i531f = NULL;
		awpImage* i570f = NULL;
		if (!m_arcive.LoadImages(path, &i531, &i570, &i531f, &i570f))
		{
			_AWP_SAFE_RELEASE_(i531)
			_AWP_SAFE_RELEASE_(i570)
			_AWP_SAFE_RELEASE_(i531f)
			_AWP_SAFE_RELEASE_(i570f)
			ShowMessage(L"Не могу загрузить архив!");
			return;
		}

		// вычисление pri
		m_processor.blurMode =  GetBlurMode();
		if (!m_processor.PriProcessImages(i531f, i570f, i531, i570 ))
		{
			_AWP_SAFE_RELEASE_(i531)
			_AWP_SAFE_RELEASE_(i570)
			_AWP_SAFE_RELEASE_(i531f)
			_AWP_SAFE_RELEASE_(i570f)
			ShowMessage("Ошибка алгоритма.");
			return;
		}

		// вычисление средних значений и дисперсии внутри ROI
		awpImage* pri = m_processor.pri;
		for (int j = 0; j < m_roiTool->GetItemsCount(); j++)
		{
		   TPriRoiItem* ri = m_roiTool->GetItem(j);
		   awpRect roi;
		   roi.left = ri->GetX() - ri->GetR();
		   roi.right = ri->GetX() + ri->GetR();
		   roi.top = ri->GetY() - ri->GetR();
		   roi.bottom = ri->GetY() + ri->GetR();
		   // вырезаем изображение
		   awpImage* fragment = NULL;
		   awpCopyRect(pri, &fragment, &roi);
		   double a, s;
		   _awpAverageStdDev(fragment, a, s);
		   data[i*w + 2*j] = a;
		   data[i*w + 2*j+1] = s;
		   _AWP_SAFE_RELEASE_(fragment)
		}

		Application->ProcessMessages();
		Gauge1->Progress =  100*(i+1) / ListBox2->Items->Count;

		_AWP_SAFE_RELEASE_(i531)
		_AWP_SAFE_RELEASE_(i570)
		_AWP_SAFE_RELEASE_(i531f)
		_AWP_SAFE_RELEASE_(i570f)
	}
	Gauge1->Progress = 0;
	// данные из результата переписываем в таблицу StringGrid1
	for (int y = 0; y < result->sSizeY; y++)
	{
		for (int x = 0; x < result->sSizeX; x++)
		{
			StringGrid1->Cells[2*x][y] = FormatFloat("0.00000",data[y*result->sSizeX + 2*x]);
			StringGrid1->Cells[2*x+1][y] = FormatFloat("0.00000",data[y*result->sSizeX + 2*x+1]);
		}
	}
	_AWP_SAFE_RELEASE_(result)
	UpdateChart();
}


void __fastcall TMainForm::PhImage4MouseMove(TObject *Sender, TShiftState Shift, int X,
		  int Y)
{

   if (m_pri != NULL)
   {
		AWPFLOAT* d = (AWPFLOAT*)m_pri->pPixels;
		int x = PhImage4->GetImageX(X);
		int y = PhImage4->GetImageY(Y);
		if (x >= 0 && y >= 0)
		{
			double v = d[y*m_pri->sSizeX + x];
			UnicodeString str = L"X:Y ";
			str += IntToStr(x);
			str += L":" + IntToStr(y);
			str += L"  VALUE: " + FormatFloat("0.###", v);
			StatusBar1->Panels->Items[0]->Text = str;
		}

   }
}
//---------------------------------------------------------------------------
awpImage* __fastcall GetVisibleImage()
{
	awpImage* result = NULL;
	return result;
}

void __fastcall TMainForm::UpdateChart()
{
	// Обновление графика.
	Series1->Clear();
	Series2->Clear();
	Chart1->Title->Clear();
	if (StringGrid1->RowCount > 1)
	{
		if (CheckListBox1->ItemIndex < 0) {
          CheckListBox1->ItemIndex = 0;
		}
		int col = roiViewAverageAction->Checked ? 2*CheckListBox1->ItemIndex : 2*CheckListBox1->ItemIndex+1;
		for(int i = 0; i < StringGrid1->RowCount; i++)
		{
			double v = StrToFloat(StringGrid1->Cells[col][i]);
			Series1->Add(v);
		}
		Chart1->Title->Clear();
		if (roiViewAverageAction->Checked) {
			Chart1->Title->Text->Add(L"Среднее значение для: ");
		}
		else
			Chart1->Title->Text->Add(L"Стандартное отклонение для: ");

		Chart1->Title->Text->Add(CheckListBox1->Items->Strings[CheckListBox1->ItemIndex]);
		double y_min = Series1->MinYValue();
		double y_max = Series1->MaxYValue();
		Series2->AddXY(ListBox2->ItemIndex, y_min);
		Series2->AddXY(ListBox2->ItemIndex, y_max);
	}
}

void __fastcall TMainForm::ClearTable()
{
	StringGrid1->ColCount = 1;
	StringGrid1->RowCount = 1;
	StringGrid1->Cells[0][0] = L"";
	UpdateChart();
}

void __fastcall TMainForm::roiViewAverageActionExecute(TObject *Sender)
{
	roiViewAverageAction->Checked = true;
	UpdateChart();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::roiViewAverageActionUpdate(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::roiViewStddevActionExecute(TObject *Sender)
{
	roiViewStddevAction->Checked = true;
	UpdateChart();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::roiViewStddevActionUpdate(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::deviceSpatialCalibrationExecute(TObject *Sender)
{
 //
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::deviceSpatialCalibrationUpdate(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------
void   __fastcall TMainForm::SwitchLightOn()
{
     memset(bufwr,0,BUFSIZE); //очистить программный передающий буфер, чтобы данные не накладывались друг на друга
     PurgeComm(COMport, PURGE_TXCLEAR);             //очистить передающий буфер порта
     strcpy(bufwr,"2");

     writer = new WriteThread(false);               //создать и активировать поток записи данных в порт
     writer->FreeOnTerminate = true;                //установить это свойство, чтобы поток автоматически уничтожался после завершения
}

void   __fastcall TMainForm::SwitchLightOff()
{
     memset(bufwr,0,BUFSIZE); //очистить программный передающий буфер, чтобы данные не накладывались друг на друга
	 PurgeComm(COMport, PURGE_TXCLEAR);             //очистить передающий буфер порта
     strcpy(bufwr,"3");

     writer = new WriteThread(false);               //создать и активировать поток записи данных в порт
     writer->FreeOnTerminate = true;                //установить это свойство, чтобы поток автоматически уничтожался после завершения
}

void __fastcall TMainForm::CheckBox1Click(TObject *Sender)
{
	if (CheckBox1->Checked)
	{
		SwitchLightOn();
	}
	else
	{
		SwitchLightOff();
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::PageControl1Change(TObject *Sender)
{
	   if (PageControl1->TabIndex == 0)
	   {
		 // camera on
			m_numCameras = BUFCCDUSB_InitDevice();
			m_cameras = new int[m_numCameras];
			for (int i = 0; i < m_numCameras; i++)
			{
				m_cameras[i] = i+1;
				BUFCCDUSB_AddDeviceToWorkingSet(m_cameras[i]);
			}
			BUFCCDUSB_InstallFrameHooker( 0, CamHook );
			int ret = BUFCCDUSB_StartCameraEngine(this->Handle, 8);


			m_mode = 0;
			for (int i = 0; i < m_numCameras; i++)
			{
				BUFCCDUSB_SetCameraWorkMode(m_cameras[i], m_mode);
				if (m_mode == 0)
					BUFCCDUSB_SetFrameTime( m_cameras[i], 3000);
			}
			BUFCCDUSB_StartFrameGrab(GRAB_FRAME_FOREVER);
			ExploshureTime(ComboBox1->ItemIndex,  TrackBar1->Position);
	   }
	   else
	   {
			StopVideoEngine();
			CheckBox1->Checked = false;
	   }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormClose(TObject *Sender, TCloseAction &Action)
{
	this->SwitchLightOff();

	this->StartVideoEngine();

	ClearPictures();
	COMClose();
	if (m_pInitFile != NULL)
		delete m_pInitFile;
}
//---------------------------------------------------------------------------
const double c_expLimit[5] = {5, 10, 100, 200, 300};
double __fastcall TMainForm::ExploshureTime(int index, int pos)
{
	m_pInitFile->exploshureIndex = index;
	m_pInitFile->exploshureValue = pos;
	double result = c_expLimit[index] / 10;
	double delta = (c_expLimit[index] - result) / 100.;
	result += pos*delta;
	GroupBox1->Caption = L"Экспозиция " + FormatFloat("000.00 мс", result);
	for (int i = 0; i < m_numCameras; i++)
	{
		BUFCCDUSB_SetExposureTime(m_cameras[i], result*1000/50);
	}
	return result;

}
void __fastcall TMainForm::ComboBox1Change(TObject *Sender)
{
	ExploshureTime(ComboBox1->ItemIndex,  TrackBar1->Position);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::TrackBar1Change(TObject *Sender)
{
	ExploshureTime(ComboBox1->ItemIndex,  TrackBar1->Position);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::PhImage3MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
     m_viewCamera = 1;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::PhImage2MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	m_viewCamera = 0;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Timer1Timer(TObject *Sender)
{
	TakePicture();
}
//---------------------------------------------------------------------------
void   __fastcall TMainForm::TakePicture()
{
     this->ClearPictures();
	 memset(bufwr,0,BUFSIZE); //очистить программный передающий буфер, чтобы данные не накладывались друг на друга
	 PurgeComm(COMport, PURGE_TXCLEAR);             //очистить передающий буфер порта
     strcpy(bufwr,"1");

     writer = new WriteThread(false);               //создать и активировать поток записи данных в порт
     writer->FreeOnTerminate = true;                //установить это свойство, чтобы поток автоматически уничтожался после завершения
}


void __fastcall TMainForm::PhImage4ScaleChange(TObject *Sender)
{
	if (PhImage4->Bitmap != NULL)
	{
		StatusBar1->Panels->Items[1]->Text = FormatFloat("Zoom: ###.##", PhImage4->Scale);
	}
}
//---------------------------------------------------------------------------
void  __fastcall TMainForm::ReadArchive()
{
	TSearchRec serchmas;//класс для хранения результата поиска
	AnsiString S,str="";
	ListBox2->Clear();
	UnicodeString path = m_arcive.path;
	path += L"\\";
	path += ListBox1->Items->Strings[ListBox1->ItemIndex];
	path += "\\*.*";
	if (FindFirst(path, faDirectory, serchmas)==0)//ищем каталог(faDirectory)без маски('*')-то есть все какие есть
	{
		//do
		while (FindNext(serchmas) != -1)
		{
			if(serchmas.Name==str)
				break;//если каталог уже встречался -выходим
			str=serchmas.Name;//запоминаем имя текущего каталога
			if((serchmas.Name==".")||(serchmas.Name==".."))
				continue;//пропускаем
			if (serchmas.Attr & faDirectory)
				ListBox2->Items->Add(serchmas.Name);

		}
		FindClose(serchmas);//закрываем экземпляр класса, освобождаем ресурсы
	}
	ClearPictures();
	CheckListBox1->Clear();
	m_roiTool->Reset();
	if (m_roiTool->Load(m_arcive.path + L"\\" + ListBox1->Items->Strings[ListBox1->ItemIndex]))
	{
		UpdateCheckList();
	}
	this->ClearTable();
	if (ListBox2->Items->Count > 0)
	{
		ListBox2->ItemIndex = 0;
		ListBox2Click(NULL);
	}
	UpdateChart();
	SpinEdit4->Value = 0;
	SpinEdit5->Value = 0;
	SpinEdit6->Value = 0;
	if (CheckListBox1->Items->Count > 0)
	{
		CheckListBox1->ItemIndex = 0;
		CheckListBox1Click(NULL);
	}
}

void __fastcall TMainForm::fileExportDataActionExecute(TObject *Sender)
{
	UnicodeString path = m_arcive.path;
	path += L"\\";
	path += ListBox1->Items->Strings[ListBox1->ItemIndex];

	SelectDirDlg->DirectoryListBox1->Directory = path;
	if (SelectDirDlg->ShowModal() == mrOk)
	{
		UnicodeString dst = SelectDirDlg->DirectoryListBox1->Directory;
		dst += L"\\";
		m_arcive.ExportData(dst, path);
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::fileExportDataActionUpdate(TObject *Sender)
{
	fileExportDataAction->Enabled = ListBox2->Items->Count > 0;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::fileExportPRIActionExecute(TObject *Sender)
{

	UnicodeString path = m_arcive.path;
	path += L"\\";
	path += ListBox1->Items->Strings[ListBox1->ItemIndex];

	ExportPriDlg->DirectoryListBox1->Directory = path;

	if (ExportPriDlg->ShowModal() == mrOk)
	{
		UnicodeString dst = ExportPriDlg->DirectoryListBox1->Directory;
		dst += L"\\";

		if (ListBox2->Items->Count == 0)
			return;

		ListBox1->Enabled = false;
		ListBox2->Enabled = false;
		CheckListBox1->Enabled = false;
		Panel1->Enabled = false;
		Panel11->Enabled = false;
		N1->Enabled = false;
		N4->Enabled = false;
		N15->Enabled = false;
		N28->Enabled = false;
		N3->Enabled = false;
		N5->Enabled = false;
		N6->Enabled = false;


		// выполняем цикл по всем элементам ListBox2
		for (int i = 0; i < ListBox2->Items->Count; i++)
		{
			// формирование имени файла
			UnicodeString path = m_arcive.path;
			path += L"\\";
			path += ListBox1->Items->Strings[ListBox1->ItemIndex];
			path += L"\\";
			path += ListBox2->Items->Strings[i];
			path += L"\\";
			// загрузка изображений
			awpImage* i531 = NULL;
			awpImage* i570 = NULL;
			awpImage* i531f = NULL;
			awpImage* i570f = NULL;
			if (!m_arcive.LoadImages(path, &i531, &i570, &i531f, &i570f))
			{
				_AWP_SAFE_RELEASE_(i531)
				_AWP_SAFE_RELEASE_(i570)
				_AWP_SAFE_RELEASE_(i531f)
				_AWP_SAFE_RELEASE_(i570f)
				ShowMessage(L"Не могу загрузить архив!");

				ListBox1->Enabled = true;
				ListBox2->Enabled = true;
				CheckListBox1->Enabled = true;
				Panel1->Enabled = true;
				Panel11->Enabled = true;
				N1->Enabled = true;
				N4->Enabled = true;
				N15->Enabled = true;
				N28->Enabled = true;
				N3->Enabled = true;
				N5->Enabled = true;
				N6->Enabled = true;

				return;
			}

			// вычисление pri
			m_processor.blurMode =  ExportPriDlg->GetPriBlurMode();
			if (!m_processor.PriProcessImages(i531f, i570f, i531, i570 ))
			{
				_AWP_SAFE_RELEASE_(i531)
				_AWP_SAFE_RELEASE_(i570)
				_AWP_SAFE_RELEASE_(i531f)
				_AWP_SAFE_RELEASE_(i570f)
				ShowMessage("Ошибка алгоритма.");

				ListBox1->Enabled = true;
				ListBox2->Enabled = true;
				CheckListBox1->Enabled = true;
				Panel1->Enabled = true;
				Panel11->Enabled = true;
				N1->Enabled = true;
				N4->Enabled = true;
				N15->Enabled = true;
				N28->Enabled = true;
				N3->Enabled = true;
				N5->Enabled = true;
				N6->Enabled = true;

				return;
			}

			awpImage* pri = m_processor.pri;
			AnsiString out = dst;
			out += ListBox2->Items->Strings[i];
			out += "___pri";
			m_arcive.SaveRAW(pri, out.c_str());

			Application->ProcessMessages();
			Gauge1->Progress =  100*(i+1) / ListBox2->Items->Count;

			_AWP_SAFE_RELEASE_(i531)
			_AWP_SAFE_RELEASE_(i570)
			_AWP_SAFE_RELEASE_(i531f)
			_AWP_SAFE_RELEASE_(i570f)
		}
		Gauge1->Progress = 0;
		m_processor.blurMode = this->GetBlurMode();

		ListBox1->Enabled = true;
		ListBox2->Enabled = true;
		CheckListBox1->Enabled = true;
		Panel1->Enabled = true;
		Panel11->Enabled = true;
		N1->Enabled = true;
		N4->Enabled = true;
		N15->Enabled = true;
		N28->Enabled = true;
		N3->Enabled = true;
		N5->Enabled = true;
		N6->Enabled = true;

		if (ExportPriDlg->CheckBox2->Checked)
		{
			AnsiString strCommand = "explorer.exe ";
			strCommand += dst;
			WinExec(strCommand.c_str(), SW_SHOWNORMAL);
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::fileExportPRIActionUpdate(TObject *Sender)
{
	fileExportPRIAction->Enabled = ListBox2->Items->Count > 0;
}
//---------------------------------------------------------------------------

