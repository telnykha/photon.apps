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

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FImage41"
#pragma link "BUF_USBCCDCamera_SDK_b.lib"
#pragma link "awpipl2b.lib"
#pragma link "PhImageTool"
#pragma link "PhPaneTool"
#pragma link "PhRulerTool"
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

     if(!GetCommState(hSerial, &dcbSerialParams)) {
           printf("\nError Getting Com Port State!\n\n");
           return (-1);
     }

     dcbSerialParams.BaudRate = CBR_9600;
     dcbSerialParams.ByteSize = 8;
     dcbSerialParams.StopBits = ONESTOPBIT;
     dcbSerialParams.Parity = FALSE;

     if(!SetCommState(hSerial, &dcbSerialParams)) {
           printf("\n\nError Setting Serial Port STATE!\n\n");
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
           char readystatus[8] = {0};

           if (!WriteFile(hSerial, "9", sizeof(char), &testWrote, NULL))
           {
             printf("error write port: %i\n", GetLastError());
             return 0;
           }

           if (!FlushFileBuffers(hSerial)) // flush buffers to tell Ardunio to bark it's data
           {
             printf("error flush port: %i\n", GetLastError());
             return 0;
           }
           do
           {
                 if (!ReadFile(hSerial, readystatus, 1, &testRead, NULL))
                 {
                     printf("error read port: %i\n", GetLastError());
                     return 0;
                 }
                 Read_Timeout++;
           }while((testRead < 1) && (Read_Timeout <= 10));

         readystatus[1] = '\0';
         if(readystatus[0] == 0x05)
               return 1; // Board Detected
         else
               return 0; // Board not here
}


static int find_arduino()
{
    // ����� ������ ��������� �� ���������� ������.
    char port_name[32];
    int board = -1;
    for (int i = 1; i < 255; i++)
    {
        sprintf(port_name, "\\\\.\\COM%i\0", i);
        HANDLE comPort = CreateFile( port_name, GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, FILE_FLAG_NO_BUFFERING, 0);
		if(comPort != INVALID_HANDLE_VALUE)
        {
            if (serial_params(comPort) == 0)
            {
				if (!Wait_Ready(comPort))
			        printf("COM%i\n", i);
                else
                {
                    printf("COM%i board detected.\n", i);
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

    HANDLE comPort = CreateFile( port_name, GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, FILE_FLAG_NO_BUFFERING, 0);
    if(comPort != INVALID_HANDLE_VALUE)
    {
       if (!WriteFile(comPort, &command, sizeof(char), &testWrote, NULL))
       {
         printf("error write port: %i\n", GetLastError());
         return;
       }

       if (!FlushFileBuffers(comPort)) // flush buffers to tell Ardunio to bark it's data
       {
         printf("error flush port: %i\n", GetLastError());
         return;
       }
       do
       {
             if (!ReadFile(comPort, readystatus, 1, &testRead, NULL))
             {
                 printf("error read port: %i\n", GetLastError());
                 break;
             }
             Application->ProcessMessages();
             if (readystatus[0] == 0x05)
                break;
       }while(true);
    }
    CloseHandle(comPort);
}
void experiment(int board)
{
       mainPAM->Memo2->Lines->Add(L"������ ������������.");
       DoCommand(board, '1');
       mainPAM->Memo2->Lines->Add(L"����������� ��������.");
}

void Turn460On(int board, unsigned char bright)
{
       unsigned char command = 0x04;
       unsigned char b = bright << 4;
       command = command | b;
       DoCommand(board, command);
       mainPAM->Memo2->Lines->Add(L"��������� 460 nm �������. ");
}

void Turn460Off(int board)
{
       DoCommand(board, 0x05);
       mainPAM->Memo2->Lines->Add(L"��������� 460 nm ��������. ");
}

void Turn660On(int board, unsigned char bright)
{
       unsigned char command = 0x02;
       unsigned char b = bright << 4;
       command = command | b;

       DoCommand(board, command);
       mainPAM->Memo2->Lines->Add(L"��������� 660 nm �������. ");
}

void Turn660Off(int board)
{
       DoCommand(board, 0x03);
       mainPAM->Memo2->Lines->Add(L"��������� 660 nm ��������. ");
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

    m_table = new TCommandsTable(this->StringGrid1);
    m_tableArchive = new TCommandsTable(this->StringGrid2);

    m_numCameras = BUFCCDUSB_InitDevice();
    Memo2->Lines->Add(L"���������� " + IntToStr(m_numCameras) + L" ����������.");
    if (m_numCameras == 0)
    {
        Memo2->Lines->Add(L"���������� �����������.");
    }
    else
    {
        m_camera = 1;
        BUFCCDUSB_AddDeviceToWorkingSet(m_camera);
        BUFCCDUSB_InstallFrameHooker( 0, CamHook );
        BUFCCDUSB_StartCameraEngine(this->Handle, 12);

        ComboBox1->ItemIndex = m_options.exploshureIndex;
        TrackBar1->Position = m_options.exploshureValue;
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
        Memo2->Lines->Add(L"������: ����������� �����������.");
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
    UnicodeString strFilter = L"����� PAM|*.pam";
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
    // todo: setup options
//    TPAMOptions options;
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
        Memo2->Lines->Add(L"���������� ���������� � ����� USB.");
    else
    {
        UnicodeString message = L"���������� ���������� � ����� COM" + IntToStr(board);
        Memo2->Lines->Add(message);
    }
    m_board = board;
}

void __fastcall TmainPAM::editInsertActionExecute(TObject *Sender)
{
    if (editorDlg->ShowModal() == mrOk)
    {
        //todo: �������� ����� �������
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
    editorDlg->ComboBox2->ItemIndex = e->pinStatus;
    editorDlg->SpinEdit1->Value = e->pinDelay;
    editorDlg->Edit1->Text = StringGrid1->Cells[4][StringGrid1->Row];


    if (editorDlg->ShowModal() == mrOk)
    {
        //todo: �������� ����� �������
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
        if (Application->MessageBox(L"�������� ������������ ���� ��������. ��������� ���������?", L"P.A.M.",
        MB_YESNO | MB_ICONQUESTION) == IDYES)
        {
           // ��������� ���������.
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

void __fastcall TmainPAM::SetFrame(int width, int height, unsigned char* data, int cameraID)
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
        if (m_archive != NULL)
            m_archive->SavePicture(img);
        awpReleaseImage(&img);
    }


    UnicodeString s = TPAMArchive::GetCurrentTime();
    StatusBar1->Panels->Items[0]->Text = s;
}

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
const double c_expLimit[5] = {5, 10, 100, 200, 300};
double __fastcall TmainPAM::ExploshureTime(int index, int pos)
{
    double result = c_expLimit[index] / 10;
    double delta = (c_expLimit[index] - result) / 100.;
    result += pos*delta;
    GroupBox1->Caption = L"���������� " + FormatFloat("000.00 ��", result);
    for (int i = 0; i < m_numCameras; i++)
    {
        BUFCCDUSB_SetExposureTime(m_camera, result*1000/50);
    }
    return result;
}

void __fastcall TmainPAM::ComboBox1Change(TObject *Sender)
{
	ExploshureTime(ComboBox1->ItemIndex,  TrackBar1->Position);
    //TPAMOptions options;
    m_options.exploshureIndex = ComboBox1->ItemIndex;
}
//---------------------------------------------------------------------------

void __fastcall TmainPAM::TrackBar2Change(TObject *Sender)
{
    GroupBox2->Caption = L"������������� 660 nm - " + IntToStr(TrackBar2->Position) + L" %";
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
    UnicodeString str = DirectoryListBox1->Directory;
    str += L"\\config.pam";
    if (FileExists(str, false))
    {
        AnsiString _ansi = str;
        m_tableArchive->LoadTable(_ansi.c_str());
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

    m_archive = new TPAMArchive(m_options.ArchivePath);//&archive;
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
        strCommand += GetSketchPath();
        strCommand += "sketch_jul18b.ino";
        Memo2->Lines->Add("�������� ��������������." );
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
        Memo2->Lines->Add(L"�� ���� ����� ����������.");
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
    Memo2->Lines->Add(L"����������� ��������.");
}

void __fastcall TmainPAM::CancelProcess()
{
    DoCommand(m_board, '0');
    Memo2->Lines->Add("����������� �������.");
    m_archive->DeleteArchiveEntry();
    delete m_archive;
    m_archive = NULL;
}


void __fastcall TmainPAM::TrackBar3Change(TObject *Sender)
{
    GroupBox3->Caption = L"������������� 460 nm - " + IntToStr(TrackBar3->Position) + L" %";
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
}
//---------------------------------------------------------------------------

void __fastcall TmainPAM::TabSheet3Show(TObject *Sender)
{
     GroupBox3->Caption = L"������������� 460 nm - " + IntToStr(TrackBar3->Position) + L" %";
     GroupBox2->Caption = L"������������� 660 nm - " + IntToStr(TrackBar2->Position) + L" %";
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


