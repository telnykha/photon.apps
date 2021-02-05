//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "MainUnit.h"
#include "About.h"
#include "optionsUnit.h"
#include "ConsoleIO.h"
#include "VerInfoUnit.h"
#include "editorUnit.h"
#include "PAMLongProcessUnit.h"
#include "Buf_USBCCDCamera_SDK.h"
#include "pam_common.h"
#include "Parametrs_light.h"
#include <Clipbrd.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FImage41"
#pragma link "BUF_USBCCDCamera_SDK_b.lib"
#pragma link "awpipl2b.lib"
#pragma link "PhImageTool"
#pragma link "PhPaneTool"
#pragma link "PhRulerTool"
#pragma link "PhSelectRectTool"
#pragma link "PhZoomToRectTool"
#pragma resource "*.dfm"
TmainPAM *mainPAM;

void CamHook(TProcessedDataProperty* Attributes, unsigned char *BytePtr)
{
     if (mainPAM != NULL)
     {
        MSG msg;
        if(GetMessage(&msg,NULL,NULL,NULL))
        {
				TranslateMessage(&msg);
                DispatchMessage(&msg);
        }
        if (mainPAM->CameraMode == 1)
	        mainPAM->SetFrame(Attributes->Column, Attributes->Row, BytePtr, Attributes->CameraID);
        else
	        mainPAM->PreviewFrame(Attributes->Column, Attributes->Row, BytePtr, Attributes->CameraID);
     }
}

int serial_params(HANDLE hSerial)
{
	 DWORD testWrote = 0;
     DWORD testRead = 0;
     DCB dcbSerialParams = {0};
     COMMTIMEOUTS timeouts = {0};

     dcbSerialParams.DCBlength = sizeof(dcbSerialParams);

	 if(!GetCommState(hSerial, &dcbSerialParams))
	 {
		   mainPAM->Memo2->Lines->Add("\nError Getting Com Port State!\n\n");
		   printf("\nError Getting Com Port State!\n\n");
		   return (-1);
	 }

	 dcbSerialParams.BaudRate = CBR_9600;
	 dcbSerialParams.ByteSize = 8;
	 dcbSerialParams.StopBits = ONESTOPBIT;
	 dcbSerialParams.Parity = FALSE;

	 if(!SetCommState(hSerial, &dcbSerialParams)) {
		   printf("\n\nError Setting Serial Port STATE!\n\n");
		   mainPAM->Memo2->Lines->Add("\n\nError Setting Serial Port STATE!\n\n");
		   return(-1);
	 }

	 // To Prevent Timing out the serial port Tell Windows not to wait up for us
	 timeouts.ReadIntervalTimeout = 50;
	 timeouts.ReadTotalTimeoutConstant = 50;
	 timeouts.ReadTotalTimeoutMultiplier = 10;
	 timeouts.WriteTotalTimeoutConstant = 50;
	 timeouts.WriteTotalTimeoutMultiplier = 10;

	 if(!SetCommTimeouts(hSerial, &timeouts)){
		   printf("\n\n Serious Timeout error occured!!\n\n");
		   mainPAM->Memo2->Lines->Add("\n\n Serious Timeout error occured!!\n\n");
		   return(-1);
	 }

	 return 0;
}

int Wait_Ready(HANDLE hSerial)
{
	 /* This function waits for the ready Status of the Arduino Board */
	 // TODO ERROR HANDLING FOR WRITE AND READFILE FUNCTIONS

		   int Read_Timeout = 0;
		   DWORD testRead = 0;
		   DWORD testWrote = 0;
		   char readystatus;
		   char command = '9';

		   if (!WriteFile(hSerial, &command, sizeof(char), &testWrote, NULL))
		   {
			 printf("error write port: %i\n", GetLastError());
			 mainPAM->Memo2->Lines->Add("Error write port.");
			 return 0;
		   }

		   if (!FlushFileBuffers(hSerial)) // flush buffers to tell Ardunio to bark it's data
		   {
			 printf("error flush port: %i\n", GetLastError());
			 mainPAM->Memo2->Lines->Add("Error flush port.");
			 return 0;
		   }
		   do
           {
				 if (!ReadFile(hSerial, &readystatus, 1, &testRead, NULL))
				 {
					 printf("error read port: %i\n", GetLastError());
					 mainPAM->Memo2->Lines->Add("Error read port.");
					 return 0;
                 }
                 Read_Timeout++;
           }while((testRead < 1) && (Read_Timeout <= 10));

//         readystatus = '\0';
		 if(readystatus == '5')
               return 1; // Board Detected
		 else
               return 0; // Board not here
}


static int find_arduino()
{
    // вывод списка доступных на компьютере портов.
	char port_name[32];
	int board = -1;
	char buffer[256];
	for (int i = 1; i < 255; i++)
	{
		sprintf(port_name, "\\\\.\\COM%i\0", i);
		HANDLE comPort = CreateFile( port_name, GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, FILE_FLAG_NO_BUFFERING, 0);
		if(comPort != INVALID_HANDLE_VALUE)
		{
			if (serial_params(comPort) == 0)
			{
				if (!Wait_Ready(comPort))
				{
					printf("COM%i\n", i);
					sprintf(buffer, "Проверка порта %s false.\n", port_name);
					mainPAM->Memo2->Lines->Add(buffer);
				}
                else
				{
					//printf("COM%i board detected.\n", i);
					sprintf(buffer, "Устройство подключено к порту %s.\n", port_name);
					mainPAM->Memo2->Lines->Add(buffer);
                    board = i;
                }
            }
            CloseHandle(comPort);
		}
    }
	return board;
}

void DoCommand(int board, char command)
{
	char port_name[32];
	sprintf(port_name, "\\\\.\\COM%i\0", board);
	char readystatus[8] = {0};
	DWORD testRead = 0;
	DWORD testWrote = 0;
	DWORD st;
	HANDLE comPort = CreateFile( port_name, GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, FILE_FLAG_NO_BUFFERING, 0);
	if(comPort != INVALID_HANDLE_VALUE)
	{
	   st = ::GetTickCount();
	   if (command == '0')
	   {
		 UnicodeString t = IntToStr(__int64(::GetTickCount() - st));
		 mainPAM->Memo2->Lines->Add(t + L" ожидание остановки микропрограммы.");
	   }
	   if (!WriteFile(comPort, &command, sizeof(char), &testWrote, NULL))
	   {
		 printf("error write port: %i\n", GetLastError());
		 mainPAM->Memo2->Lines->Add("Error write port.");
		 return;
	   }

	   if (!FlushFileBuffers(comPort)) // flush buffers to tell Ardunio to bark it's data
	   {
		 printf("error flush port: %i\n", GetLastError());
		 mainPAM->Memo2->Lines->Add("Error flush port.");
		 return;
	   }
	   do
	   {
			 if (!ReadFile(comPort, readystatus, 1, &testRead, NULL))
			 {
				 printf("error read port: %i\n", GetLastError());
				 mainPAM->Memo2->Lines->Add("Error flush port.");
				 break;
			 }
			 Application->ProcessMessages();
			 if (command == '0')
			 {
				UnicodeString t = IntToStr(__int64(::GetTickCount() - st));
				mainPAM->Memo2->Lines->Strings[mainPAM->Memo2->Lines->Count-1] = t + L" ms ожидание остановки микропрограммы.";
			 }
			 if (readystatus[0] == '5')
				break;
	   }while(true);
	}
	else
	{
	   char  buffer[256];
	   sprintf(buffer, "Не могу открыть COM порт для записи данных. %i\n", GetLastError());
	   mainPAM->Memo2->Lines->Add(buffer);
	}
	CloseHandle(comPort);
}
void experiment(int board)
{
	   mainPAM->Memo2->Lines->Add(L"Начало эксперимента.");
	   DoCommand(board, '1');
	   mainPAM->Memo2->Lines->Add(L"Эксперимент завершен.");
}

void Turn460On(int board, unsigned char bright)
{
	   unsigned char command = '4';
       unsigned char b = bright << 4;
       command = command | b;
       DoCommand(board, command);
       mainPAM->Memo2->Lines->Add(L"Прожектор 460 nm включен. ");
}

void Turn460Off(int board)
{
	   DoCommand(board, '5');
       mainPAM->Memo2->Lines->Add(L"Прожектор 460 nm выключен. ");
}

void Turn660On(int board, unsigned char bright)
{
	   unsigned char command = '2';
       unsigned char b = bright << 4;
       command = command | b;

       DoCommand(board, command);
       mainPAM->Memo2->Lines->Add(L"Прожектор 660 nm включен. ");
}

void Turn660Off(int board)
{
	   DoCommand(board, '3');
       mainPAM->Memo2->Lines->Add(L"Прожектор 660 nm выключен. ");
}
//---------------------------------------------------------------------------
__fastcall TmainPAM::TmainPAM(TComponent* Owner)
	: TForm(Owner)
{
    m_camera = NULL;
    m_table  = NULL;
    m_mode   = 0;
    m_currentArchive = m_options.ArchivePath;
    m_archive = NULL;
	m_tableArchive = NULL;
	m_clipFormat = 0;
}
//---------------------------------------------------------------------------
void __fastcall TmainPAM::N2Click(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TmainPAM::FormCreate(TObject *Sender)
{
    CheckSketch();

    TConsoleIO console(Memo2);
    console.Run("arduino_debug.exe --version");


    Memo1->Lines->LoadFromFile("sketch_jul18b//config.h");
    this->CheckArduino();
    this->SpeedButton10->Caption = L"";
    this->SpeedButton11->Caption = L"";
    this->SpeedButton12->Caption = L"";

	m_table = new TCommandsTable(StringGrid1, &m_options);
	m_tableArchive = new TCommandsTable(this->StringGrid2, &m_options, false);

    m_numCameras = BUFCCDUSB_InitDevice();
    Memo2->Lines->Add(L"Обнаружено " + IntToStr(m_numCameras) + L" видеокамер.");
    if (m_numCameras == 0)
    {
        Memo2->Lines->Add(L"Подключите видеокамеру.");
    }
	else
    {
        m_camera = 1;
        BUFCCDUSB_AddDeviceToWorkingSet(m_camera);
        BUFCCDUSB_InstallFrameHooker( 0, CamHook );
        BUFCCDUSB_StartCameraEngine(this->Handle, 12);
    }
	ComboBox1->ItemIndex = m_options.exploshureIndex;
	TrackBar1->Position = m_options.exploshureValue;
    TrackBar5->Position = m_options.Gain;
    SpinEdit2->Value = m_options.Delay;
	SpinEdit1->Value = m_options.Length;
	m_options.freeze = false;


	 m_clipFormat = RegisterClipboardFormat("PAMCOMMAND");
	 if (m_clipFormat == 0)
	 {
		ShowMessage("Не могу зарегистрировать фомат данных для обмена через clipboard.");
		Application->Terminate();
	 }
}
//---------------------------------------------------------------------------
void   __fastcall TmainPAM::StartExperiment()
{
    experiment(m_board);
}
//---------------------------------------------------------------------------
static UnicodeString GetPathToPictures()
{
    LPITEMIDLIST pidl;
    LPMALLOC pShellMalloc;
	char szDir[MAX_PATH];
	UnicodeString PathStr ;

	if (SUCCEEDED(SHGetMalloc(&pShellMalloc)))
    {
		if (SUCCEEDED(SHGetSpecialFolderLocation(NULL, CSIDL_MYPICTURES, &pidl)))
        {
			if (SHGetPathFromIDList(pidl, szDir))
            {
				PathStr = szDir ;
				PathStr = PathStr + "\\" ;
			}
			pShellMalloc->Free(pidl);
		}
		pShellMalloc->Release();
	}

    PathStr += L"\\PAM\\";
    if (!DirectoryExists(PathStr))
        CreateDir(PathStr);

    return PathStr;

}
static bool CheckExtention(int index, UnicodeString str)
{
	UnicodeString strExt = ExtractFileExt(str);
    if (strExt == L"")
        return false;
    if (index == 1 && strExt == L".jpg")
        return true;
    if (index == 2 && strExt == L".awp")
        return true;
    if (index == 3 && strExt == L".png")
        return true;
    if (index == 4 && strExt == L".tif")
        return true;
    return false;
}
static UnicodeString SetExtention(int index, UnicodeString str)
{
    if (CheckExtention(index, str))
        return str;
    if (index == 1 )
        return str + L".jpg";
    if (index == 2)
        return str + L".awp";
    if (index == 3)
        return str + L".png";
    if (index == 4)
        return str + L".tiff";
}
//---------------------------------------------------------------------------
void __fastcall TmainPAM::Button1Click(TObject *Sender)
{
	//
	UnicodeString strFilter = L"Jpeg images|*.jpg|Awp imges|*.awp|PNG images|*.png|TIFF images |*.tif";
    awpImage* img = NULL;
    PhImage1->GetAwpImage(&img);
    if (img != NULL)
    {
        UnicodeString strCurrentDir = GetCurrentDir();
        SaveDialog1->Filter = strFilter;
        SaveDialog1->InitialDir = GetPathToPictures();
        if (SaveDialog1->Execute())
        {
            UnicodeString str = SetExtention(SaveDialog1->FilterIndex, SaveDialog1->FileName);
            PhImage1->SaveToFile(str.c_str());
        }
        awpReleaseImage(&img);
        SetCurrentDir(strCurrentDir);
    }
    else
        Memo2->Lines->Add(L"Ошибка: изображение отсутствует.");
}
//---------------------------------------------------------------------------
 // OnIdle
void __fastcall TmainPAM::ApplicationEvents1Idle(TObject *Sender, bool &Done)
{
    UnicodeString str = L"";
    if (m_table->changed)
        str = L"P.A.M.* [";
    else
        str = L"P.A.M. [";
    str += m_table->fileName;
	str += L"]";
	Caption = str;
    Button2->Enabled = m_tableArchive != NULL && m_tableArchive->list->Count > 0;
}
//---------------------------------------------------------------------------

void __fastcall TmainPAM::fileNewActionExecute(TObject *Sender)
{
    AskSaveTable();
    m_table->NewTable();
}
//---------------------------------------------------------------------------


void __fastcall TmainPAM::fileOpenActionExecute(TObject *Sender)
{
	if (OpenDialog1->Execute())
    {
        AnsiString str = OpenDialog1->FileName.c_str();
		m_table->LoadTable(str.c_str());
        PageControl1->TabIndex = 0;
    }
}
//---------------------------------------------------------------------------

void __fastcall TmainPAM::fileOpenActionUpdate(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------
void __fastcall TmainPAM::fileSaveActionExecute(TObject *Sender)
{
	awpImage* img = NULL;


   if (m_table->fileName == c_FileName)
	  fileSaveAsActionExecute(NULL);
   else
	  m_table->Save();
}
//---------------------------------------------------------------------------
void __fastcall TmainPAM::fileSaveActionUpdate(TObject *Sender)
{
	fileSaveAction->Enabled = StringGrid1->RowCount > 1 && m_table->changed;
}
//---------------------------------------------------------------------------
void __fastcall TmainPAM::fileSaveAsActionExecute(TObject *Sender)
{
	UnicodeString strFilter = L"Файлы PAM|*.pam";
	if (SaveDialog1->Execute())
	{
		UnicodeString ustr = SaveDialog1->FileName.c_str();
		if(ExtractFileExt(ustr) != L".pam")
			ustr += L".pam";
		AnsiString str = ustr;
		m_table->SaveTable(str.c_str());
	}
}
//---------------------------------------------------------------------------
void __fastcall TmainPAM::fileSaveAsActionUpdate(TObject *Sender)
{
	fileSaveAsAction->Enabled = StringGrid1->RowCount > 1;
}
//---------------------------------------------------------------------------
void __fastcall TmainPAM::deviceCheckActionExecute(TObject *Sender)
{
    this->CheckArduino();
}
//---------------------------------------------------------------------------
void __fastcall TmainPAM::deviceCheckActionUpdate(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------

void __fastcall TmainPAM::device460nmActionExecute(TObject *Sender)
{
    device460nmAction->Checked = !device460nmAction->Checked;
    if (device460nmAction->Checked)
    {
        int v = TrackBar3->Position * 15 / 100;
        unsigned char c = v;
        Turn460On(m_board, c);
    }
    else
        Turn460Off(m_board);
}
//---------------------------------------------------------------------------

void __fastcall TmainPAM::device460nmActionUpdate(TObject *Sender)
{
	this->BoardDetected(device460nmAction);
    SpeedButton5->Down = device460nmAction->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TmainPAM::device660nmActionExecute(TObject *Sender)
{
	device660nmAction->Checked = !device660nmAction->Checked;
    if (device660nmAction->Checked)
    {
        int v = TrackBar2->Position * 15 / 100;
        unsigned char c = v;
        Turn660On(m_board, c);
    }
    else
        Turn660Off(m_board);
}
//---------------------------------------------------------------------------

void __fastcall TmainPAM::device660nmActionUpdate(TObject *Sender)
{
    this->BoardDetected(device660nmAction);
    SpeedButton6->Down = device660nmAction->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TmainPAM::deviceVideocamActionExecute(TObject *Sender)
{
	deviceVideocamAction->Checked = !deviceVideocamAction->Checked;
    if (deviceVideocamAction->Checked)
	{
        PageControl1->TabIndex = 2;
        this->StartVideo();
    }
    else
        this->StopVideo();

}
//---------------------------------------------------------------------------

void __fastcall TmainPAM::deviceVideocamActionUpdate(TObject *Sender)
{
    this->BoardDetected(deviceVideocamAction);
    SpeedButton7->Down = deviceVideocamAction->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TmainPAM::deviceExperimentActionExecute(TObject *Sender)
{
	PAMLongProcessForm->Execute();
}
//---------------------------------------------------------------------------

void __fastcall TmainPAM::deviceExperimentActionUpdate(TObject *Sender)
{
    deviceExperimentAction->Enabled = m_board > 0 &&
    StringGrid1->RowCount > 1;
}
//---------------------------------------------------------------------------

void __fastcall TmainPAM::toolsOptionsActionExecute(TObject *Sender)
{
    OptionsDlg->CheckBox1->Checked = m_options.OpenArchive;
    OptionsDlg->DirectoryListBox1->Directory = m_options.ArchivePath;
    if (OptionsDlg->ShowModal() == mrOk)
    {
        //todo: save options
        m_options.OpenArchive =  OptionsDlg->CheckBox1->Checked;
        m_options.ArchivePath = OptionsDlg->DirectoryListBox1->Directory;
    }
}
//---------------------------------------------------------------------------

void __fastcall TmainPAM::toolsOptionsActionUpdate(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------

void __fastcall TmainPAM::helpAboutActionExecute(TObject *Sender)
{
    TVersionInfo* info = new TVersionInfo(NULL);
    AboutBox->ProductName->Caption = info->ProductName;
    AboutBox->Version->Caption = info->FileVersion;
    AboutBox->Copyright->Caption = info->LegalCopyright;

    AboutBox->ShowModal();
    delete info;
}
//---------------------------------------------------------------------------

void __fastcall TmainPAM::helpContextActionExecute(TObject *Sender)
{
    AnsiString adr = ExtractFilePath(Application->ExeName);
    adr+= "\\manual.pdf";
	ShellExecute(this->WindowHandle,"open",adr.c_str() ,NULL,NULL, SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------
void   __fastcall TmainPAM::BoardDetected(TAction* action)
{
    action->Enabled = m_board > 0;
}
//---------------------------------------------------------------------------
void  __fastcall TmainPAM::CheckArduino()
{
    int board = find_arduino();
    if (board < 0)
        Memo2->Lines->Add(L"Подключите устройство к порту USB.");
    else
    {
		UnicodeString message = L"Устройство подключено к порту COM" + IntToStr(board);
		Memo2->Lines->Add(message);
    }
    m_board = board;
}

void __fastcall TmainPAM::editInsertActionExecute(TObject *Sender)
{
	editorDlg->ComboBox1->ItemIndex = 0;
	editorDlg->SpinEdit2->Value = 0;
	editorDlg->SpinEdit1->Value = 100;
	editorDlg->Edit1->Text = L"";
	if (editorDlg->ShowModal() == mrOk)
    {
		//todo: добавить новую команду
		m_table->AddRecord(editorDlg);
    }
}
//---------------------------------------------------------------------------

void __fastcall TmainPAM::editInsertActionUpdate(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------

void __fastcall TmainPAM::editDeleteActionExecute(TObject *Sender)
{
	m_table->DeleteRecord(StringGrid1->Row);
}
//---------------------------------------------------------------------------

void __fastcall TmainPAM::editDeleteActionUpdate(TObject *Sender)
{
    editDeleteAction->Enabled = StringGrid1->RowCount > 1;
}
//---------------------------------------------------------------------------

void __fastcall TmainPAM::editEditActionExecute(TObject *Sender)
{
	TList* list = m_table->list;
	expEvent* e = (expEvent*)list->Items[StringGrid1->Row-1];
	assert(e != NULL);

	editorDlg->ComboBox1->ItemIndex = e->command;
	editorDlg->SpinEdit2->Value = e->pinStatus;
	editorDlg->SpinEdit1->Value = e->pinDelay;
	editorDlg->Edit1->Text = StringGrid1->Cells[4][StringGrid1->Row];


	if (editorDlg->ShowModal() == mrOk)
	{
		//todo: добавить новую команду
		m_table->EditRecord(StringGrid1->Row, editorDlg);
	}
}
//---------------------------------------------------------------------------

void __fastcall TmainPAM::editEditActionUpdate(TObject *Sender)
{
    editEditAction->Enabled = StringGrid1->RowCount > 1;
}
//---------------------------------------------------------------------------
void __fastcall TmainPAM::StringGrid1DblClick(TObject *Sender)
{
	editEditActionExecute(NULL);
}
//---------------------------------------------------------------------------
void   __fastcall TmainPAM::AskSaveTable()
{
	if (m_table->changed)
    {
        if (Application->MessageBox(L"Описание эксперимента было изменено. Сохранить изменения?", L"P.A.M.",
        MB_YESNO | MB_ICONQUESTION) == IDYES)
        {
           // сохраняем изменения.
		   if (m_table->fileName == c_FileName)
              fileSaveAsActionExecute(NULL);
           else
              m_table->Save();
        }
    }
}


void __fastcall TmainPAM::PageControl1Change(TObject *Sender)
{
    if (PageControl1->TabIndex == 1)
    {
        Memo1->Lines->Clear();
        Memo1->Lines->Add(m_table->script);
        StopVideo();
    }
    else if (PageControl1->TabIndex == 2)
    {
        StartVideo();
    }
    else if (PageControl1->TabIndex == 3)
    {
        StopVideo();
		//
        if (m_tableArchive != NULL && m_tableArchive->fileName != L"default.pam")
        {
            Memo2->Lines->Add(m_tableArchive->fileName);
            OpenArchivePage(m_tableArchive->fileName);
        }
        else
	        OpenArchivePage(m_options.ArchivePath);
    }
    else
        StopVideo();
}
//---------------------------------------------------------------------------

void __fastcall TmainPAM::FormClose(TObject *Sender, TCloseAction &Action)
{
   Turn460Off(m_board);
   Turn660Off(m_board);
   AskSaveTable();
   StopVideo();
   BUFCCDUSB_UnInitDevice();

}
//---------------------------------------------------------------------------
void   __fastcall TmainPAM::StartVideo()
{
     deviceVideocamAction->Checked = true;
     m_mode = 0;
     BUFCCDUSB_SetCameraWorkMode(m_camera, m_mode);
     BUFCCDUSB_SetFrameTime( m_camera, 2500);
	 BUFCCDUSB_StartFrameGrab(GRAB_FRAME_FOREVER);
 	 ExploshureTime(ComboBox1->ItemIndex,  TrackBar1->Position);
}

void   __fastcall TmainPAM::StopVideo()
{
    deviceVideocamAction->Checked = false;
    BUFCCDUSB_StopFrameGrab();
}
//запись в архив
void __fastcall TmainPAM::SetFrame(int width, int height, unsigned char* data, int cameraID)
{
    awpImage* img = NULL;
	if (cameraID == 1)
    {
	   awpCreateImage(&img, width, height, 1, AWP_FLOAT);
	   AWPFLOAT* dst = (AWPFLOAT*)img->pPixels;
       int x,y, i=0;
       for (x = 0; x < width; x++)
       {
		   for (y = 0; y < height; y++)
           {
			   AWPWORD value = data[2*y + 2*x*height+ 1];
               AWPWORD v2 = data[2*y + 2*x*height];
               v2 = v2 << 4;
			   value |= v2;
			   dst[i] = (AWPFLOAT)value;
			   i++;
		   }

	   }
        if (m_archive != NULL)
        {
			m_archive->SavePicture(img);
        }
        awpReleaseImage(&img);
    }


    UnicodeString s = TPAMArchive::GetCurrentTime();
    StatusBar1->Panels->Items[0]->Text = s;
}
// предварительный просмотр.
void __fastcall TmainPAM::PreviewFrame(int width, int height, unsigned char* data, int cameraID)
{
    int bits = 1;//this->m_pInitFile->inputData;
    int type = bits == 0 ? AWP_BYTE:AWP_DOUBLE;
    int size = bits == 0 ? sizeof(AWPBYTE):sizeof(AWPDOUBLE);
    awpImage* img = NULL;
    if (cameraID == 1)
    {
       awpCreateImage(&img, width, height, 1, AWP_BYTE);
       AWPBYTE* dst = (AWPBYTE*)img->pPixels;
       int x,y, i=0;
       for (x = 0; x < width; x++)
       {
           for (y = 0; y < height; y++)
           {
               AWPWORD value = data[2*y + 2*x*height+ 1];
               AWPWORD v2 = data[2*y + 2*x*height];
			   v2 = v2 << 4;
               value |= v2;
               dst[i] = 255*(float)value/4096.;
               i++;
           }

       }
        PhImage1->SetAwpImage(img);
        awpReleaseImage(&img);
    }
}

/*
User may set the exposure time by invoking this function.
Argument: DeviceNo – the device number which identifies the camera will be operated.
exposureTime – the Exposure Time is set in 50 Microsecond UNIT, e.g. if it’s 4,
the exposure time of the camera will be set to 200us. The valid range of exposure
time is 50us – 200,000ms, So the exposure time value here is from 1 – 4000,000.
Return:  -1 If the function fails (e.g. invalid device number)                  1
if the call succeeds. Note: Although the minimum exposure time can be set to 50us,
camera might revise it to a minimum achievable exposure time in firmware,
the minimum achievable exposure time of a certain camera is related to its current
mode (NORMAL or TRIGGER) and its current CCD main clock (frequency).
Basically, for CCX cameras, when CCD frequency is 28MHz (default),
the minimum ET is: NORMAL Mode: 1 Row Time (~68us) TRIGGER Mode: 3 Row Times (~200us)
With slower CCD frequency, the minimum achievable ET is increased proportionally
*/
double __fastcall TmainPAM::ExploshureTime(int index, int pos)
{
	double exp_start = c_expLimit[index] / 100.;
	double exp = exp_start*pos;
	int exp_mks = floor(exp*1000 + 0.5);
	int exp_units = exp_mks / 50;
	GroupBox1->Caption = L"Экспозиция " + IntToStr(exp_mks) + L" mks";

    m_options.exploshureIndex = index;
    m_options.exploshureValue = pos;

	int delay = 500 / exp_mks;

	SpinEdit2->MinValue = delay + 1;
	if (SpinEdit2->Value < SpinEdit2->MinValue)
		SpinEdit2->Value = SpinEdit2->MinValue;

	SpinEdit1Change(NULL);
	SpinEdit2Change(NULL);

    if (BUFCCDUSB_SetExposureTime(m_camera, exp_units) == -1)
		Memo2->Lines->Add(L"Не могу установить экспозицю. Подключите видеокамеру Mightex.");
    else
    {
        Memo2->Lines->Add("Exposure time = " + IntToStr(exp_mks) + " mks. Units = " + IntToStr(exp_units));
    }
	return exp;
}

void __fastcall TmainPAM::ComboBox1Change(TObject *Sender)
{
	ExploshureTime(ComboBox1->ItemIndex,  TrackBar1->Position);
	m_options.exploshureIndex = ComboBox1->ItemIndex;
	if (m_table != NULL)
        m_table->changed = true;
}
//---------------------------------------------------------------------------

void __fastcall TmainPAM::TrackBar2Change(TObject *Sender)
{
    GroupBox2->Caption = L"Интенсивновть 660 nm - " + IntToStr(TrackBar2->Position) + L" %";
    if (!device660nmAction->Checked)
        return;
    int v = TrackBar2->Position * 15 / 100;
    unsigned char c = v;
    Turn660On(m_board, c);
}
//---------------------------------------------------------------------------
void   __fastcall TmainPAM::OpenArchivePage(UnicodeString path)
{
    this->DirectoryListBox1->Directory = path;
}

void __fastcall TmainPAM::FileListBox1Change(TObject *Sender)
{

    awpImage* img = TPAMArchive::LoadPicture(FileListBox1->FileName);

    if (img != NULL)
    {
        awpConvert(img, AWP_CONVERT_TO_BYTE);
        PhImage2->SetAwpImage(img);
        awpReleaseImage(&img);
	}

    AnsiString str = ExtractFileName(FileListBox1->FileName);
    for (int i = 0; i < m_tableArchive->list->Count; i++)
    {
        expEvent* event = (expEvent*)m_tableArchive->list->Items[i];
        if (event->imageName == str)
        {
            StringGrid2->Row = i+1;
            break;
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TmainPAM::ApplicationEvents1Hint(TObject *Sender)
{
     StatusBar1->Panels->Items[0]->Text = Application->Hint;
}
//---------------------------------------------------------------------------

void __fastcall TmainPAM::DirectoryListBox1Change(TObject *Sender)
{

    m_tableArchive->NewTable();
    Label12->Caption = "";//IntToStr(m_tableArchive->options->Exposure);
    Label13->Caption = "";//IntToStr(m_tableArchive->options->Gain);
    Label14->Caption = "";//IntToStr(m_tableArchive->options->Delay);
    Label15->Caption = "";//IntToStr(m_tableArchive->options->Length);
    UnicodeString str = DirectoryListBox1->Directory;
    str += L"\\config.pam";
	if (FileExists(str, false))
    {
        AnsiString _ansi = str;
        m_tableArchive->LoadTable(_ansi.c_str());
        Label12->Caption = IntToStr(m_tableArchive->options->Exposure);
        Label13->Caption = IntToStr(m_tableArchive->options->Gain);
        Label14->Caption = IntToStr(m_tableArchive->options->Delay*m_tableArchive->options->Exposure / 100);
        Label15->Caption = IntToStr(m_tableArchive->options->Length*m_tableArchive->options->Exposure / 100);
    }
}
//---------------------------------------------------------------------------
UnicodeString __fastcall TmainPAM::GetSketchPath()
{
    LPITEMIDLIST pidl;
    LPMALLOC pShellMalloc;
	char szDir[MAX_PATH];
	UnicodeString PathStr ;

	if (SUCCEEDED(SHGetMalloc(&pShellMalloc)))
    {
		if (SUCCEEDED(SHGetSpecialFolderLocation(NULL, CSIDL_APPDATA, &pidl)))
        {
			if (SHGetPathFromIDList(pidl, szDir))
            {
				PathStr = szDir ;
				PathStr = PathStr + "\\" ;
			}
			pShellMalloc->Free(pidl);
		}
		pShellMalloc->Release();
	}

    PathStr += L"\\NNVideolab\\";
    if (!DirectoryExists(PathStr))
        CreateDir(PathStr);

    PathStr += L"\\PAM\\";
    if (!DirectoryExists(PathStr))
        CreateDir(PathStr);

    PathStr += L"\\sketch_jul18b\\";
    if (!DirectoryExists(PathStr))
        CreateDir(PathStr);

    return PathStr;
}

void   __fastcall TmainPAM::CheckSketch()
{
    UnicodeString path = GetSketchPath();
    UnicodeString sketchName = path + L"sketch_jul18b.ino";
    if (!FileExists(sketchName))
    {
        // copy default sketch
        AnsiString _newFile = sketchName;
        AnsiString _existsFile = ExtractFilePath(Application->ExeName) + L"\\sketch_jul18b\\sketch_jul18b.ino";
        CopyFile(_existsFile.c_str(), _newFile.c_str(), false);
    }
    UnicodeString codeName = path + L"config.h";
    if (!FileExists(codeName))
	{
        // copy default config
        AnsiString _newFile = codeName;
        AnsiString _existsFile = ExtractFilePath(Application->ExeName) + L"\\sketch_jul18b\\config.h";
        CopyFile(_existsFile.c_str(), _newFile.c_str(), false);
    }

}

bool __fastcall TmainPAM::StartProcess()
{
    SetCurrentDir(ExtractFilePath(Application->ExeName));

    Turn460Off(m_board);
    Turn660Off(m_board);
    device660nmAction->Checked = false;
    device460nmAction->Checked = false;

    StopVideo();

    m_archive = new TPAMArchive(m_options.ArchivePath);
    m_archive->CreateArchiveEntry(this->m_table);
    if (find_arduino() > 0)
    {
        Memo1->Lines->Clear();
        Memo1->Lines->Add(m_table->script);

         m_mode = 1;
         BUFCCDUSB_SetCameraWorkMode(m_camera, m_mode);
         BUFCCDUSB_StartFrameGrab(GRAB_FRAME_FOREVER);
		 ExploshureTime(ComboBox1->ItemIndex,  TrackBar1->Position);

        UnicodeString strPath = GetSketchPath();
        strPath += L"\\config.h";
        Memo2->Lines->Add(strPath);
        Memo1->Lines->SaveToFile(strPath);
		AnsiString strCommand = "arduino_debug.exe --upload ";
		strCommand += "\"";
		strCommand += GetSketchPath();
		strCommand += "sketch_jul18b.ino";
		strCommand += "\"";

		Memo2->Lines->Add("Загрузка микропрограммы." );
		Memo2->Lines->Add(strCommand);
        TConsoleIO console(Memo2);

        console.Run(strCommand.c_str());
        bool result = find_arduino();
        if (!result)
            m_archive->DeleteArchiveEntry();
        return result;
    }
    else
    {
        m_archive->DeleteArchiveEntry();
        Memo2->Lines->Add(L"Не могу найти устройство.");
        return false;
    }
}
void __fastcall TmainPAM::FinishProcess()
{
    m_archive->FinishSave();
    if (m_options.OpenArchive)
    {
        PageControl1->TabIndex = 3;
        OpenArchivePage(m_archive->CurrentPath);
    }
    delete m_archive;
    m_archive = NULL;
    StopVideo();
    Memo2->Lines->Add(L"Эксперимент завершен.");
}

void __fastcall TmainPAM::CancelProcess()
{
	DoCommand(m_board, '0');
    Memo2->Lines->Add("Эксперимент отменен.");
    m_archive->DeleteArchiveEntry();
    delete m_archive;
    m_archive = NULL;
}


void __fastcall TmainPAM::TrackBar3Change(TObject *Sender)
{
    GroupBox3->Caption = L"Интенсивновть 460 nm - " + IntToStr(TrackBar3->Position) + L" %";
    if (!device460nmAction->Checked)
        return;
    int v = TrackBar3->Position * 15 / 100;
    unsigned char c = v;
	Turn460On(m_board, c);
}
//---------------------------------------------------------------------------

void __fastcall TmainPAM::TrackBar1Change(TObject *Sender)
{
	ExploshureTime(ComboBox1->ItemIndex,  TrackBar1->Position);
	m_options.exploshureValue = TrackBar1->Position;
	if (m_table != NULL)
        m_table->changed = true;
}
//---------------------------------------------------------------------------

void __fastcall TmainPAM::TabSheet3Show(TObject *Sender)
{
     GroupBox3->Caption = L"Интенсивновть 460 nm - " + IntToStr(TrackBar3->Position) + L" %";
     GroupBox2->Caption = L"Интенсивновть 660 nm - " + IntToStr(TrackBar2->Position) + L" %";
}
//---------------------------------------------------------------------------

void __fastcall TmainPAM::StringGrid2Click(TObject *Sender)
{
    TList* list = m_tableArchive->list;

    expEvent* e = (expEvent*)list->Items[StringGrid2->Row-1];
    assert(e != NULL);

    if (e->imageName == "")
        return;

	AnsiString str = DirectoryListBox1->Directory;
    str += "\\";
    str += e->imageName;
    awpImage* img = TPAMArchive::LoadPicture(str);

    if (img != NULL)
    {
        awpConvert(img, AWP_CONVERT_TO_BYTE);
        PhImage2->SetAwpImage(img);
        awpReleaseImage(&img);
    }

}
//---------------------------------------------------------------------------
void __fastcall TmainPAM::TrackBar5Change(TObject *Sender)
{
	int v = TrackBar5->Position;
	GroupBox5->Caption = L"Усиление " + IntToStr(v) + L" dB";
	m_options.Gain = v;
	if (m_table != NULL)
        m_table->changed = true;

    if (BUFCCDUSB_SetGains(m_camera, v , v, v) == -1)
		Memo2->Lines->Add(L"Не могу установить усиление. Подключите видеокамеру Mightex.");
    else
    {
		Memo2->Lines->Add(L"Gain = " + IntToStr(v) + L" dB");
    }
}
//---------------------------------------------------------------------------
void __fastcall TmainPAM::SpinEdit2Change(TObject *Sender)
{
	int exp = m_options.Exposure;
	int value = exp*SpinEdit2->Value / 100;
	Label5->Caption = IntToStr(value) + L" mks";
	m_options.Delay = SpinEdit2->Value;
    if (m_table != NULL)
        m_table->changed = true;

}
//---------------------------------------------------------------------------
void __fastcall TmainPAM::SpinEdit1Change(TObject *Sender)
{
	int exp = m_options.Exposure;
	int value = exp*SpinEdit1->Value / 100;
	Label7->Caption = IntToStr(value) + L" mks";
    m_options.Length = SpinEdit1->Value;
    if (m_table != NULL)
        m_table->changed = true;
}
//---------------------------------------------------------------------------

void __fastcall TmainPAM::Button2Click(TObject *Sender)
{
    m_table->NewTable();
    m_table->fileName = c_FileName;
    for (int i = 0; i < m_tableArchive->list->Count; i++)
    {
		expEvent* e = (expEvent*)m_tableArchive->list->Items[i];
        assert (e != NULL);
		expEvent* ee = new expEvent();
        ee->command = e->command;
        ee->pinStatus = e->pinStatus;
        ee->pinDelay = e->pinDelay;
        ee->imageName = L"";
        ee->eventTime = 0;
        m_table->list->Add(ee);
    }
    m_table->UpdateGrid();
    PageControl1->ActivePageIndex = 0;
}
//---------------------------------------------------------------------------

void __fastcall TmainPAM::editAddActionExecute(TObject *Sender)
{
	editorDlg->ComboBox1->ItemIndex = 0;
	editorDlg->SpinEdit2->Value = 0;
	editorDlg->SpinEdit1->Value = 100;
	editorDlg->Edit1->Text = L"";
	if (editorDlg->ShowModal() == mrOk)
	{
		m_table->InsertRecord(StringGrid1->Row, editorDlg);
	}
}
//---------------------------------------------------------------------------

void __fastcall TmainPAM::editAddActionUpdate(TObject *Sender)
{
    editAddAction->Enabled = StringGrid1->RowCount > 1 && StringGrid1->Row > 0;
}
//---------------------------------------------------------------------------

void __fastcall TmainPAM::editUpActionExecute(TObject *Sender)
{
	m_table->Up(StringGrid1->Row);
}
//---------------------------------------------------------------------------

void __fastcall TmainPAM::editUpActionUpdate(TObject *Sender)
{
	editUpAction->Enabled = StringGrid1->RowCount > 1 && StringGrid1->Row > 1;
}
//---------------------------------------------------------------------------

void __fastcall TmainPAM::editDownActionUpdate(TObject *Sender)
{
	editDownAction->Enabled = StringGrid1->RowCount > 1 && StringGrid1->Row < StringGrid1->RowCount-1;
}
//---------------------------------------------------------------------------

void __fastcall TmainPAM::editDownActionExecute(TObject *Sender)
{
	m_table->Down(StringGrid1->Row);
}
//---------------------------------------------------------------------------

void __fastcall TmainPAM::editCopyActionExecute(TObject *Sender)
{
	if (!OpenClipboard(this->Handle))
	{
		ShowMessage(L"Не могу открыть буфер обмена.");
		return;
	}
	EmptyClipboard();
// 1. Get Command
	TList* list = m_table->list;
	expEvent* e = (expEvent*)list->Items[StringGrid1->Row-1];

// 2. Copy commnad to global memory block
	HGLOBAL hglbCopy;
	hglbCopy = GlobalAlloc(GMEM_MOVEABLE,sizeof(expEvent));
	if (hglbCopy == NULL)
	{
		CloseClipboard();
		ShowMessage(L"Не могу скопировать в буфер обмена.");
		return;
	}
	expEvent* copy = (expEvent*)GlobalLock(hglbCopy);
	memcpy(copy, e, sizeof(expEvent));
	GlobalUnlock(hglbCopy);
// 3. Отправим данные в буфер обмена
   SetClipboardData(m_clipFormat, hglbCopy);
   CloseClipboard();
}
//---------------------------------------------------------------------------

void __fastcall TmainPAM::editCopyActionUpdate(TObject *Sender)
{
	editCopyAction->Enabled = StringGrid1->Row > 0;
}
//---------------------------------------------------------------------------

void __fastcall TmainPAM::editPasteActionUpdate(TObject *Sender)
{
	editPasteAction->Enabled = IsClipboardFormatAvailable(m_clipFormat);
}
//---------------------------------------------------------------------------

void __fastcall TmainPAM::editPasteActionExecute(TObject *Sender)
{
	 HGLOBAL   hglb;
	 if (!OpenClipboard(this->Handle))
		return;
	 hglb = GetClipboardData(m_clipFormat);
	 if(hglb != NULL)
	 {
		expEvent* e =  (expEvent*)GlobalLock(hglb);
		if (e != NULL)
		{
			editorDlg->ComboBox1->ItemIndex = e->command;
			editorDlg->SpinEdit2->Value = e->pinStatus;
			editorDlg->SpinEdit1->Value = e->pinDelay;
			editorDlg->Edit1->Text = "";
			GlobalUnlock(hglb);
			m_table->InsertRecord(StringGrid1->Row, editorDlg);
		}
	 }
	 CloseClipboard();
}
//---------------------------------------------------------------------------



void __fastcall TmainPAM::AddDiffCommExecute(TObject *Sender)
{
	Difficult_command->Show();
}
//---------------------------------------------------------------------------




void __fastcall TmainPAM::ZoomToRectExecute(TObject *Sender)
{
PhImage3->SelectPhTool(PhZoomToRectTool1);
}
//---------------------------------------------------------------------------

void __fastcall TmainPAM::ZoomToRectUpdate(TObject *Sender)
{
ZoomToRect->Enabled = !PhImage3->Bitmap->Empty;// && !Timer1->Enabled;
ZoomToRect->Checked =  dynamic_cast< TPhZoomToRectTool*>(PhImage3->PhTool) != NULL;
}
//---------------------------------------------------------------------------

void __fastcall TmainPAM::SelectRectExecute(TObject *Sender)
{
PhImage3->SelectPhTool(PhSelRectTool1);
}
//---------------------------------------------------------------------------

void __fastcall TmainPAM::SelectRectUpdate(TObject *Sender)
{
SelectRect->Enabled = !PhImage3->Bitmap->Empty;
	SelectRect->Checked = dynamic_cast< TPhSelRectTool*>(PhImage3->PhTool) != NULL;;
}
//---------------------------------------------------------------------------

void __fastcall TmainPAM::CopyActionExecute(TObject *Sender)
{
		  PhImage3->SaveToClipBoard();
}
//---------------------------------------------------------------------------

void __fastcall TmainPAM::CopyActionUpdate(TObject *Sender)
{
Copy1->Enabled = !PhImage3->Bitmap->Empty;
}



void __fastcall TmainPAM::PastActionExecute(TObject *Sender)
{
   PhImage3->LoadFromClipboard();
	PhImage3->BestFit();
}
//---------------------------------------------------------------------------

void __fastcall TmainPAM::PastActionUpdate(TObject *Sender)
{
TClipboard *cb = Clipboard();
PastAction->Enabled = cb->HasFormat(CF_BITMAP);
}
//---------------------------------------------------------------------------

void __fastcall TmainPAM::ZoomToActualSizeExecute(TObject *Sender)
{
PhImage3->BestFit();
}
//---------------------------------------------------------------------------

void __fastcall TmainPAM::ZoomToActualSizeUpdate(TObject *Sender)
{
ZoomToActualSize->Enabled = !PhImage3->Bitmap->Empty;
}
//---------------------------------------------------------------------------

void __fastcall TmainPAM::ZoomToBestFitExecute(TObject *Sender)
{
PhImage3->BestFit();
}
//---------------------------------------------------------------------------

void __fastcall TmainPAM::ZoomToBestFitUpdate(TObject *Sender)
{
ZoomToBestFit->Enabled = !PhImage3->Empty;
}
//---------------------------------------------------------------------------

void __fastcall TmainPAM::ViewPanActionExecute(TObject *Sender)
{
PhImage3->SelectPhTool(PhPaneTool1);
}
//---------------------------------------------------------------------------

void __fastcall TmainPAM::ViewPanActionUpdate(TObject *Sender)
{
ViewPanAction->Enabled = !PhImage3->Empty;
}
//---------------------------------------------------------------------------

void __fastcall TmainPAM::ViewZoomExecute(TObject *Sender)
{
PhImage3->SelectPhTool(PhZoomToRectTool1);
}
//---------------------------------------------------------------------------

void __fastcall TmainPAM::ViewZoomUpdate(TObject *Sender)
{
ViewZoom->Enabled = !PhImage3->Empty;
}
//---------------------------------------------------------------------------

void __fastcall TmainPAM::RightDocPanelDockDrop(TObject *Sender, TDragDockObject *Source,
          int X, int Y)
{
ShowLeftDockPanel(RightDocPanel, true, NULL);
}
//---------------------------------------------------------------------------

void __fastcall TmainPAM::RightDocPanelUnDock(TObject *Sender, TControl *Client, TWinControl *NewTarget,
          bool &Allow)
{
ShowLeftDockPanel(RightDocPanel, false, NULL);
}
//---------------------------------------------------------------------------

void __fastcall TmainPAM::RightDocPanelDockOver(TObject *Sender, TDragDockObject *Source,
          int X, int Y, TDragState State, bool &Accept)
{
   Accept = (Source->Control) != NULL;
  if (Accept)
  {
	// Modify the DockRect to preview dock area.
	Types::TPoint TopLeft = RightDocPanel->ClientToScreen(Point(0, 0));
	Types::TPoint BottomRight = RightDocPanel->ClientToScreen(Point(PhImage1->Width / 3, RightDocPanel->Height));
	Source->DockRect = Types::TRect(TopLeft, BottomRight);
  }
}

void TmainPAM::ShowLeftDockPanel(TWinControl* APanel, bool MakeVisible, TControl* Client)
{
  if (APanel == NULL || (!MakeVisible && (APanel->VisibleDockClientCount > 1)))
	return;
  if (MakeVisible)
  {
	  APanel->Width = ClientWidth / 3;
  }
  else
  {
	  APanel->Width = 5;
  }

  if (MakeVisible && (Client != NULL))
	Client->Show();
}
//---------------------------------------------------------------------------

void __fastcall TmainPAM::LeftDocPanelDockDrop(TObject *Sender, TDragDockObject *Source,
          int X, int Y)
{
    ShowLeftDockPanel(LeftDocPanel, true, NULL);
}
//---------------------------------------------------------------------------

void __fastcall TmainPAM::LeftDocPanelDockOver(TObject *Sender, TDragDockObject *Source,
          int X, int Y, TDragState State, bool &Accept)
{
    Accept = (Source->Control) != NULL;
  if (Accept)
  {
	// Modify the DockRect to preview dock area.
	Types::TPoint TopLeft = LeftDocPanel->ClientToScreen(Point(0, 0));
	Types::TPoint BottomRight = LeftDocPanel->ClientToScreen(Point(PhImage1->Width / 3, LeftDocPanel->Height));
	Source->DockRect = Types::TRect(TopLeft, BottomRight);
  }
}


//---------------------------------------------------------------------------


void __fastcall TmainPAM::LeftDocPanelUnDock(TObject *Sender, TControl *Client, TWinControl *NewTarget,
          bool &Allow)
{
 ShowLeftDockPanel(LeftDocPanel, false, NULL);
}
//---------------------------------------------------------------------------


void __fastcall TmainPAM::ShowMightexExecute(TObject *Sender)
{
Panel6->Show();
}
//---------------------------------------------------------------------------

void __fastcall TmainPAM::ShowMightexUpdate(TObject *Sender)
{
ShowMightex->Enabled = !Panel6->Showing;
}
//---------------------------------------------------------------------------

void __fastcall TmainPAM::ShowPanelResultExecute(TObject *Sender)
{
Panel12->Show() ;
}
//---------------------------------------------------------------------------

void __fastcall TmainPAM::ShowPanelResultUpdate(TObject *Sender)
{
ShowPanelResult->Enabled = !Panel12->Showing;
}
//---------------------------------------------------------------------------

void __fastcall TmainPAM::ShowPanelParametrsExecute(TObject *Sender)
{
Panel9->Show();
}
//---------------------------------------------------------------------------

void __fastcall TmainPAM::ShowPanelParametrsUpdate(TObject *Sender)
{
ShowPanelParametrs->Enabled = !Panel9->Showing;
}
//---------------------------------------------------------------------------


void __fastcall TmainPAM::SpeedButton20Click(TObject *Sender)
{
FormLight->Show();
}
//---------------------------------------------------------------------------

