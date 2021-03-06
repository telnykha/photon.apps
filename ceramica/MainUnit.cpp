//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainUnit.h"
#include "CeramUtils.h"
#include "PhVideo.h"
#include "PhSlideShow.h"
#include "Ph3iCube.h"
#include "SelDirUnit.h"
#include "IpAddress.h"
#include "Bitmap2Dib.h"
#include "VideoControlUnit.h"
#include "VerInfoUnit.h"
#include "AboutUnit.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FImage41"
#pragma link "PhImageTool"
#pragma link "PhRulerTool"
#pragma link "PhPaneTool"
#pragma link "PhSelectRectTool"
#pragma link "PhTrackBar"
#pragma resource "*.dfm"
TMainForm *MainForm;
extern "C"
{
    #pragma link "awpipl2b.lib"
    #pragma link "JPEGLIB.lib"
}
    #pragma link "awplflibb.lib"

//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
    m_videoSource = NULL;
    m_modeAction  = NULL;
    m_buffer = new TLFBuffer(256, 0);
    m_archive = NULL;
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::fileExitActionExecute(TObject *Sender)
{
    delete m_buffer;
    Close();
}
#define _MODE_ENABLED_(v) \
    v->Enabled = m_videoSource != NULL && m_videoSource->NumFrames >= 0;

//---------------------------------------------------------------------------
void __fastcall TMainForm::modeExperimentActionExecute(TObject *Sender)
{
    if (m_modeAction != modeExperimentAction)
		SetMode(modeExperimentAction);
    else
        SetMode(modeAutoAnalysisAction);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::modeExperimentActionUpdate(TObject *Sender)
{
    _MODE_ENABLED_(modeExperimentAction)
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::modeAutoAnalysisActionExecute(TObject *Sender)
{
    if (this->m_modeAction)
	SetMode(modeAutoAnalysisAction);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::modeAutoAnalysisActionUpdate(TObject *Sender)
{
    _MODE_ENABLED_(modeAutoAnalysisAction)
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::modeHandActionExecute(TObject *Sender)
{
	SetMode(modeHandAction);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::modeHandActionUpdate(TObject *Sender)
{
    _MODE_ENABLED_(modeHandAction)
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::viewAnalysisAreaActionExecute(TObject *Sender)
{
	viewAnalysisAreaAction->Checked = !viewAnalysisAreaAction->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::viewAnalysisAreaActionUpdate(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::viewObjectContourActionExecute(TObject *Sender)
{
    viewObjectContourAction->Checked = !viewObjectContourAction->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::viewObjectContourActionUpdate(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::viewCenterActionExecute(TObject *Sender)
{
    viewCenterAction->Checked = !viewCenterAction->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::viewCenterActionUpdate(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::viewAxisActionExecute(TObject *Sender)
{
    viewAxisAction->Checked = !viewAxisAction->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::viewAxisActionUpdate(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::viewEllipseActionExecute(TObject *Sender)
{
    viewEllipseAction->Checked = !viewEllipseAction->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::viewEllipseActionUpdate(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::fileOpenImagesActionExecute(TObject *Sender)
{
    Reset();
	AnsiString cstrImages = "Jpeg images|*.jpeg;*.jpg|AWP images|*.awp";
    OpenDialog1->Filter = cstrImages;
    if (OpenDialog1->Execute())
    {
        TPhMediaSource* videoSource = new TPhSlideShowSource(PhImage1);
        videoSource->Open(OpenDialog1->Files);
        this->SetSource(videoSource);
    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::fileOpenVideoActionExecute(TObject *Sender)
{
    Reset();
    SetMode(modeHandAction);
	AnsiString cstrVideos = "Videos |*.avi;*.mp4;*.mpg;|Avi videos|*.avi;|MP4 videos|*.mp4|mpeg files|*.mpg";
    OpenDialog1->Filter = cstrVideos;
    if (OpenDialog1->Execute())
    {
        TPhMediaSource* videoSource= new TPhVideoSource(PhImage1);
        videoSource->Open(OpenDialog1->Files);
        if (videoSource->NumFrames == 0)
        {
            ShowMessage(L"�� ���� ������� ����: " + OpenDialog1->FileName);
            SetSource(NULL);
            return;
        }
        else
        {
			SetSource(videoSource);
			SetMode(modeHandAction);
		}
    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::fileConnectToCameraActionExecute(TObject *Sender)
{
      Reset();
      TPhMediaSource* videoSource = NULL;
      try
      {
  		videoSource= new TPh3iCubeSource(PhImage1);
        videoSource->Open(NULL);
        if (videoSource->NumFrames == 0)
            SetSource(videoSource);
        else
        {
            SetSource(NULL);
            fileCloseActionExecute(NULL);
        }

	  }
      catch(...)
      {
			ShowMessage("�� ���� ������������ � 3iCube.");
			SetSource(NULL);
            fileCloseActionExecute(NULL);
      }
 	  SetMode(modeHandAction);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::fileCloseActionExecute(TObject *Sender)
{
    PhImage1->Close();
	PhImage1->Refresh();
    this->SetSource(NULL);
	SetMode(modeHandAction);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormClose(TObject *Sender, TCloseAction &Action)
{
	IdTCPServer1->Active = false;
    if (m_videoSource != NULL)
        delete m_videoSource;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PhImage1AfterOpen(TObject *Sender)
{
    PhImage1->BestFit();
}
//---------------------------------------------------------------------------
#define _CHECK_SOURCE_     \
if (m_videoSource == NULL) \
    return;                \

#define _NAV_ENABLED_(v) \
    v->Enabled = m_videoSource != NULL && m_videoSource->NumFrames > 1 && !this->m_videoSource->IsPlaying;

void __fastcall TMainForm::viewFirstActionExecute(TObject *Sender)
{
	_CHECK_SOURCE_
    m_videoSource->First();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::viewFirstActionUpdate(TObject *Sender)
{
    _NAV_ENABLED_(viewFirstAction)
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::viewPrevActionExecute(TObject *Sender)
{
	_CHECK_SOURCE_
    m_videoSource->Prev();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::viewPrevActionUpdate(TObject *Sender)
{
    _NAV_ENABLED_(viewPrevAction)
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::viewNextActionExecute(TObject *Sender)
{
	_CHECK_SOURCE_
    m_videoSource->Next();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::viewNextActionUpdate(TObject *Sender)
{
    _NAV_ENABLED_(viewNextAction)
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::viewLastActionExecute(TObject *Sender)
{
	_CHECK_SOURCE_
    m_videoSource->Last();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::viewLastActionUpdate(TObject *Sender)
{
    _NAV_ENABLED_(viewLastAction)
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::viewPlayActionExecute(TObject *Sender)
{
	_CHECK_SOURCE_
    if (!m_videoSource->IsPlaying)
    {
	    m_videoSource->Play();
        viewPlayAction->Caption = L"����";
        SpeedButton9->Down = true;
    }
    else
    {
        m_videoSource->Stop();
        viewPlayAction->Caption = L"�������������";
        SpeedButton9->Down = false;
    }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::viewPlayActionUpdate(TObject *Sender)
{
    viewPlayAction->Enabled = m_videoSource != NULL && (m_videoSource->NumFrames > 1 || m_videoSource->NumFrames == 0);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SetMode(TAction* action)
{
    if (this->CheckBox3->Checked && action != modeHandAction)
    {
        TRect r = PhImage1->GetSelRect();
        if (r.Width() == 0)
        {
            ShowMessage(L"������ ����� ��������� � �������� ����������, �� ������� ���������� �� ������. ������� ������� ����������!");
            //m_modeAction = modeHandAction;
            SetMode(modeHandAction);
            return;
        }

        awpPoint p;
        p.X = r.Left + r.Width() / 2;
        p.Y = r.Top  + r.Height() / 2;
        int rd = AWP_MIN(r.Width(), r.Height()) / 2;
        this->m_engine.maskRadius = rd;
        this->m_engine.maskCener = p;
    }
    else
    {
        this->m_engine.maskRadius = 0;
    }

   Reset();
   if (m_modeAction == modeExperimentAction)
    this->StopExperiment();

   m_modeAction = action;

   if (m_modeAction == modeExperimentAction)
   try
   {
    this->StartExperiment();
   }
   catch(...)
   {
      SetMode(modeHandAction);
   }


   action->Checked = true;
   StatusBar1->Panels->Items[0]->Text = L"�����: " + action->Caption;

   Label6->Enabled  = m_modeAction != modeHandAction;
   Label7->Enabled  = m_modeAction != modeHandAction;
   Label8->Enabled  = m_modeAction != modeHandAction;
   Label10->Enabled = m_modeAction != modeHandAction;


    for (int i = 0; i < GroupBox2->ControlCount; i++)
    {
        TControl* c = GroupBox2->Controls[i];
        if (c != NULL)
            c->Enabled = m_modeAction == modeHandAction && m_videoSource != NULL;
            if (c->Name == L"SpeedButton8")
                c->Enabled = this->CheckBox3->Checked && m_modeAction == modeHandAction && m_videoSource != NULL;
    }

    CheckBox4->Enabled =  m_modeAction == modeHandAction;
   if (m_modeAction == modeHandAction)
   {
      Reset();
      this->ShowResult();
//      IdTCPServer1->Active = false;
      this->SpeedButton12->Down = true;
      this->SpeedButton13->Down = false;
   }
   else
   {
//
      this->SpeedButton13->Down = true;
      this->SpeedButton12->Down = false;
   }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormCreate(TObject *Sender)
{
	SetMode(modeHandAction);
    SetSource(NULL);
    LoadParams();

    TStringList* l = new TStringList();
    GetMyIpAddressList(l);
    this->ComboBox1->Items->Clear();
    for (int i = 0; i < l->Count; i++)
        this->ComboBox1->Items->Add(l->Strings[i]);
    if (l->Count > 0)
	    this->ComboBox1->ItemIndex = 0;
    delete l;

  	IdTCPServer1->Bindings->Add()->IP =  this->ComboBox1->Items->Strings[0];
  	IdTCPServer1->Bindings->Add()->Port = this->SpinEdit3->Value;
    IdTCPServer1->Active = true;

}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SetSource(TPhMediaSource* source)
{
   Reset();
   if (m_videoSource != NULL)
   {
      delete m_videoSource;
      m_videoSource = NULL;
   }

   m_videoSource = source;
   if (m_videoSource  != NULL)
   {
	   StatusBar1->Panels->Items[2]->Text = L"�������� ������: " + m_videoSource->SourceName;
       UnicodeString cap = L"Ceramica [";
       cap += m_videoSource->Source;
       cap  += L"]";
       this->Caption = cap;

        PhTrackBar1->Min = 0;
        PhTrackBar1->Max = m_videoSource->NumFrames;

   }
   else
   {
	   StatusBar1->Panels->Items[1]->Text = L"";
	   StatusBar1->Panels->Items[2]->Text = L"�������� ������: NULL";
       this->Caption = L"Ceramica";
   }
}

void __fastcall TMainForm::PhImage1MouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y)
{
   if (m_modeAction == modeHandAction)
   {
     Label13->Caption = FormatFloat(L"####.##",this->PhRulerTool1->Lendth);
     double mm = m_c.ValueMM(this->PhRulerTool1->Lendth);
     Edit1->Text = FormatFloat("###.##", mm);
   }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::PhImage1FrameData(TObject *Sender, int w, int h, int c,
          BYTE *data)
{
    if (m_videoSource != NULL)
    {
		StatusBar1->Panels->Items[1]->Text = L"���� "  + IntToStr( m_videoSource->CurrentFrame) +
   		" of " + IntToStr(m_videoSource->NumFrames);
	    StatusBar1->Panels->Items[3]->Text = L"�����������: " + IntToStr(w) + L":" + IntToStr(h) + L":" + IntToStr(c);
    }
    else
		StatusBar1->Panels->Items[1]->Text = L" ";



    if (w > 0 && h > 0 && c > 0 && data != NULL)
    {
       awpImage img;
       img.nMagic = AWP_MAGIC2;
       img.bChannels = c;
       img.sSizeX =  w;
       img.sSizeY = h;
       img.dwType = AWP_BYTE;
       img.pPixels = data;
       DrawRuler(&img);
       if (m_modeAction == modeHandAction)
         return;
       // ����� ���, ��� ������ ��������� ������� �����
       // �����������

       m_copy.SetImage(&img);
       // ��������� �����������.
       m_engine.Process(&img);
       // ����������� ����������� ��������� ��
       // �����������
       RenderScene(&img);
       // ����������� ����������� ��������� ��
       // ���������������� ����������
       ShowResult();
    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::RenderScene(awpImage* img)
{
   if (!m_engine.acceptable)
    return;

   DrawSource(img);
   DrawMask(img);
   DrawAxis(img);
   DrawCenter(img);
   DrawObject(img);
   DrawRawContour(img);
   DrawEllipce(img);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DrawSource(awpImage* img)
{
    if (!viewSourceImageAction->Checked)
	    this->DrawBinary(img);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DrawCenter(awpImage* img)
{
    if (!viewCenterAction->Checked)
        return;

    awpPoint p;
    awpRect  r;

    int delta = 20;

    p.X = m_engine.center.X;
    p.Y = m_engine.center.Y;

    r.left = p.X - delta;
    r.right = p.X + delta;
    r.top = p.Y - delta;
    r.bottom = p.Y + delta;

    awpDrawCCross(img, &r, 0,0, 255, 3);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DrawObject(awpImage* img)
{
    if (!viewObjectContourAction->Checked)
        return;

    awpPoint p;

    AWPSHORT r = m_engine.diam / 2;
    p.X = m_engine.center.X;
    p.Y = m_engine.center.Y;

#if 0
    for (int alfa = 45; alfa <= 135; alfa += 10)
    {
        p.X = m_engine.center.X - r*cos(AWP_PI*alfa/180.);
        p.Y = m_engine.center.Y - r*sin(AWP_PI*alfa/180.);
	    awpDrawCEllipse(img, p, 5, 5, 0, 0,0,255, 1);
        if (m_engine.contour != NULL)
        {
            double min_dist = img->sSizeX*img->sSizeX;
            int    min_idx = -1;
            for (int i = 0; i < m_engine.contour->NumPoints; i++)
            {
                double d;
                awpDistancePoints(p, m_engine.contour->Points[i], &d);
                if (d < min_dist)
                {
                    min_dist = d;
                    min_idx = i;
                }
            }
		    awpDrawCEllipse(img, m_engine.contour->Points[min_idx], 5, 5, 0, 255,0,0, 1);
        }
    }
#else
    awpDrawCEllipse(img, p, r, r, 0, 0,0,255, 3);
#endif
}

void __fastcall TMainForm::DrawEllipce(awpImage* img)
{
    if (!viewEllipseAction->Checked)
        return;

    awpPoint p;
    p.X = m_engine.center.X;
    p.Y = m_engine.center.Y;

    awpDrawCEllipse2(img, p, m_engine.major/2, m_engine.minor/2, -AWP_PI*m_engine.angle/180., 255,0,255, 1);
}

void __fastcall TMainForm::DrawAxis(awpImage* img)
{
    if (!viewAxisAction->Checked)
        return;

    awpPoint p;
    p.X = m_engine.center.X;
    p.Y = m_engine.center.Y;

   awpDrawCEllipseCross(img, p, m_engine.major, m_engine.minor, m_engine.angle, 255,0,0, 1);
}

void __fastcall TMainForm::DrawRawContour(awpImage* img)
{
   if (!viewRawContourAction->Checked)
    return;

   if (m_engine.contour != NULL)
	awpDrawCPolygon(img, m_engine.contour, 0, 255, 0, 1);
}


void __fastcall TMainForm::DrawBinary(awpImage* img)
{
    if (!viewBinaryAction->Checked)
        return;

    if (m_engine.process != NULL)
    {
        AWPBYTE* p = (AWPBYTE*)m_engine.process->pPixels;
        AWPBYTE* b = (AWPBYTE*)img->pPixels;
        for (int i = 0; i < m_engine.process->sSizeX*m_engine.process->sSizeY; i++)
        {
           b[3*i] = p[i];
           b[3*i+1] = p[i];
           b[3*i+2] = p[i];
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DrawMask(awpImage* img)
{
    if (!viewAnalysisAreaAction->Checked)
        return;
    if (m_engine.mask == NULL)
        return;

    AWPBYTE* m = (AWPBYTE*)m_engine.mask->pPixels;
    AWPBYTE* b = (AWPBYTE*)img->pPixels;
    for (int i = 0; i < img->sSizeX*img->sSizeY; i++)
    {
        if (m[i] != 0)
        {
	        b[3*i] = 255;
	        b[3*i + 1] /= 2;
	        b[3*i + 2] /= 2;
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DrawRuler(awpImage* img)
{
    int w = img->sSizeX;
    int h = img->sSizeY;

    const int sx = 40;
    const int sy = 40;

    awpPoint p1;
    awpPoint p2;

    int _length = this->m_c.ValuePix(2);
    int _delta  = 20;

    awpRect rect;
    rect.left = sx;
    rect.top  = h - sy - 20;
    rect.right = sx + _length;
    rect.bottom = h - sy;

    awpDrawCRect(img, &rect, 0,255,0, 1);
    rect.right = sx + _length / 2;
   	awpFillRect(img, &rect, 1, 255);

    awpRect r;
    r.left = 0;
    r.top  = 0;
    r.right = img->sSizeX;
    r.bottom = 40;
    AnsiString _str = DateToStr(Now());
    _str += " ";
    _str += TimeToStr(Now());
    _str += " d=";
    _str += FormatFloat("000.00  mm", m_c.ValueMM(m_engine.diam));
    awpwinDrawStatusText(img, _str.c_str(), r);

}
void __fastcall TMainForm::FormResize(TObject *Sender)
{
    this->PhImage1->BestFit();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ShowResult()
{
    m_buffer->Push(m_c.ValueMM(m_engine.diam));

    Label5->Caption = FormatFloat("000.00  mm", m_c.ValueMM(m_engine.diam));
    Label6->Caption = FormatFloat("000.00  mm", m_c.ValueMM(m_engine.major));
    Label7->Caption = FormatFloat("000.00  mm", m_c.ValueMM(m_engine.minor));
    Label8->Caption = FormatFloat("000.00  grad",m_engine.angle);
    Label10->Caption = FormatFloat("000.00", m_c.ValueMM(m_engine.center.X)) + L":" + FormatFloat("000.00", m_c.ValueMM(m_engine.center.Y));
    Series1->Clear();
    for (int i = 0; i < m_buffer->GetSize(); i++)
        Series1->Add(m_buffer->GetValue(i));
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::viewSourceImageActionExecute(TObject *Sender)
{
    viewSourceImageAction->Checked = !viewSourceImageAction->Checked;
}
//---------------------------------------------------------------------------
void  __fastcall TMainForm::SaveParams()
{
	UnicodeString str = GetEnvironmentVariable(L"APPDATA");
    str += L"\\ceramica\\";
    if (!DirectoryExists(str))
        CreateDir(str);
    str += L"ceramica.ini";
    AnsiString _ansi = str;
    FILE* f = fopen(_ansi.c_str(), "w+t");
     // ����. ���������������
    float dv = m_c.alfa;
    fprintf(f, "%f\n", dv);
    // ������������ �� �����������
    int  iv = (int)CheckBox1->Checked;
    fprintf(f, "%i\n", iv);
    // ������ ������
    iv = SpinEdit1->Value;
    fprintf(f, "%i\n", iv);

    // ������������ �� ������������
     iv = (int)CheckBox2->Checked;
    fprintf(f, "%i\n", iv);

    // ���� ��� ������ ������
    _ansi = Edit2->Text;
    fprintf(f, "%s\n", _ansi.c_str());
    // ���������� ������
    iv = SpinEdit2->Value;
    fprintf(f, "%i\n", iv);
    // ����� ����������
    //iv = StrToInt(Edit3->Text);
    //fprintf(f, "%i\n", iv);

    fclose(f);
    LoadParams();
}
//---------------------------------------------------------------------------
void  __fastcall TMainForm::LoadParams()
{
	UnicodeString str = GetEnvironmentVariable(L"APPDATA");
    str += L"\\ceramica\\";
    UnicodeString FileName = str;
    FileName += L"ceramica.ini";
    if (DirectoryExists(str))
    {
        if (FileExists(FileName))
        {
            AnsiString _ansi = FileName;
            FILE* f = fopen(_ansi.c_str(), "r+t");
            float dv = 0;
            int   iv = 0;
            // ����������
            fscanf(f, "%f\n", &dv);
            m_c.alfa = dv;
            Label15->Caption = L"� ����� �� " + IntToStr(m_c.ValuePix(1)) + L" ��������";
            // ������������� �����������
            fscanf(f, "%i\n",&iv);
            CheckBox1->Checked = (bool)iv;
            // ������ ������
            fscanf(f, "%i\n", &iv);
            SpinEdit1->Value = iv;
            // ������������� ������������
            fscanf(f, "%i\n",&iv);
            CheckBox2->Checked = (bool)iv;
            // ���� � ������
            char buf[1024];
            fscanf(f, "%s\n", buf);
            _ansi = buf;
            Edit2->Text = _ansi;
            // ���������� ������
            fscanf(f, "%i\n", &iv);
            SpinEdit2->Value = iv;
            // ����� ����������
            //fscanf(f, "%i\n", &iv);
            //Edit3->Text = IntToStr(iv);
            fclose(f);
        }
        else
            SaveParams();
    }
    else
        SaveParams();
}


void __fastcall TMainForm::CheckBox1Click(TObject *Sender)
{
    SaveParams();
    this->m_engine.useBuffer = CheckBox1->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SpinEdit1Change(TObject *Sender)
{
    SaveParams();
    this->m_engine.bufferSize = SpinEdit1->Value;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Edit2Change(TObject *Sender)
{
	SaveParams();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SpinEdit2Change(TObject *Sender)
{
	SaveParams();
}
//---------------------------------------------------------------------------



void __fastcall TMainForm::viewBinaryActionExecute(TObject *Sender)
{
    viewBinaryAction->Checked = !viewBinaryAction->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::viewBinaryActionUpdate(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Edit1Change(TObject *Sender)
{
    if (this->m_videoSource == NULL)
        return;

    float v = 10;
    if (TryStrToFloat(Edit1->Text, v))
    {
        m_c.Init(this->PhRulerTool1->Lendth, v);
	    SaveParams();
    }
    else
        Edit1->Text = m_e1ov;

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Edit1Enter(TObject *Sender)
{
    m_e1ov = StrToFloat(Edit1->Text);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Timer1Timer(TObject *Sender)
{
    if (this->m_videoSource == NULL || !this->m_videoSource->IsPlaying)
        return;
 	// ���������� � �����
    if (m_archive != NULL)
    {
        TCeramArchiveRecord r;
        r.acceptable = m_engine.acceptable ? 1:0;
        r.diam = m_c.ValueMM(m_engine.diam);
        r.xpos = m_c.ValueMM(m_engine.center.X);
        r.ypos = m_c.ValueMM(m_engine.center.Y);
        r.mi = m_c.ValueMM(m_engine.minor);
        r.ma = m_c.ValueMM(m_engine.major);
        r.angle = m_engine.angle;
        r.img = m_copy.GetImage();
        m_archive->AddRecord(r);
    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::UpdateRuler()
{

}

void __fastcall TMainForm::Button1Click(TObject *Sender)
{
    String DirName;
	if (GetDirNamePreview(DirName))
    {
        Edit2->Text = DirName;
	    SaveParams();
    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Panel4Click(TObject *Sender)
{
    Panel1->Visible = !Panel1->Visible;
    PhImage1->BestFit();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::StartExperiment()
{
    if (this->m_archive != NULL)
        delete m_archive;
    AnsiString _ansi = Edit2->Text;
    m_archive = new TCeramArchive(_ansi.c_str());
    m_archive->bmpFormat = CheckBox4->Checked;
    TCeramArchiveHeader header;
    header.alfa = m_c.alfa;
    header.bufferSize = m_engine.bufferSize;
    header.dutyRatio  = SpinEdit2->Value;
    if (!m_archive->Create(header))
    {
        ShowMessage("�� ���� ������� �����: " + Edit2->Text);
        throw 0;
    }
    this->Timer1->Interval = SpinEdit2->Value;
    this->Timer1->Enabled  = true;
}
void __fastcall TMainForm::StopExperiment()
{
    this->Timer1->Enabled  = false;
    m_archive->Close();
}
static void GetCS(unsigned char* buf, unsigned short qty)
{
    unsigned short fl1 = 0, fl2 = 0;
    short int i = 0;

    fl1 = fl2 = 0;
    for (i = 0; i < qty; i++)
    {
        fl1 = (fl1 + *buf++) % 0xFF;
        fl2 = (fl2+fl1) % 0xFF;
    }

    *buf = (unsigned char)(0xFF - ((fl2 + fl1) %0xFF));
    fl2 = *buf++;
    *buf = (unsigned char)(0xFF - ((fl2 + fl1)% 0xFF));
}


void __fastcall TMainForm::IdTCPServer1Execute(TIdContext *AContext)
{
  UnicodeString LLine = AContext->Connection->IOHandler->ReadLn();
  Memo1->Lines->Add(LLine);
  TDateTime dt = Now();
  unsigned short year, month, day;
  dt.DecodeDate(&year, &month, &day);
  unsigned short hour, min, sec, msec;
  dt.DecodeTime(&hour, &min, &sec, &msec);

    TCeramArchiveRecord r;
    r.diam = m_c.ValueMM(m_engine.diam);
    r.xpos = m_c.ValueMM(m_engine.center.X);
    r.ypos = m_c.ValueMM(m_engine.center.Y);
    r.mi = m_c.ValueMM(m_engine.minor);
    r.ma = m_c.ValueMM(m_engine.major);
    r.angle = m_engine.angle;

/*
  AContext->Connection->IOHandler->WriteLn(IntToStr(1945) + " : " +
  IntToStr(year) + " : " +
  IntToStr(month) + " : " +
  IntToStr(day) + " : " +
  IntToStr(hour) + " : " +
  IntToStr(min) + " : " +
  IntToStr(sec) + " : " +
  FormatFloat("000.00  mm", r.diam) + " : " +
  FormatFloat("000.00  mm", r.ma) + " : " +
  FormatFloat("000.00  mm", r.mi) + " : " +
  FormatFloat("000.00  mm", r.xpos) + " : " +
  FormatFloat("000.00  mm", r.ypos) + " : " +
  FormatFloat("000.00  grad", r.angle)
  );

  AContext->Connection->IOHandler->WriteLn(IntToStr(1945)+
  IntToStr(year) +
  IntToStr(month) +
  IntToStr(day) +
  IntToStr(hour) +
  IntToStr(min) +
  IntToStr(sec) +
  FormatFloat("000.00", r.diam) +
  FormatFloat("000.00", r.ma) +
  FormatFloat("000.00", r.mi) +
  FormatFloat("000.00", r.xpos)+
  FormatFloat("000.00", r.ypos)+
  FormatFloat("000.00", 90+r.angle)
  );
*/

  // �������� ������
  TByteDynArray a;
  a.set_length(56);
  unsigned char status = 0;
  unsigned char* byte = &a[0];
  unsigned int* tmp = (unsigned int*)&byte[6];
  byte[0] = 0xFF;
  byte[1] = 0x88;
  byte[2] = 0x88;
  byte[3] = 0x14;
  byte[4] = 0x3C;
  byte[5] = status;

  tmp[0] = year;
  tmp[1] = month;
  tmp[2] = day;
  tmp[3] = hour;
  tmp[4] = min;
  tmp[5] = sec;

  float* f = (float*)&tmp[6];
  f[0] = r.diam;
  f[1] = r.xpos;
  f[2] = r.ypos;
  f[3] = r.ma;
  f[4] = r.mi;
  f[5] = r.angle;

  GetCS(byte, 54);

  AContext->Connection->IOHandler->WriteDirect(a);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::IdTCPServer1Connect(TIdContext *AContext)
{
    Memo1->Lines->Add("����������� �������. ");
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::IdTCPServer1Disconnect(TIdContext *AContext)
{
    Memo1->Lines->Add("���������� �������. ");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::fileClientActionExecute(TObject *Sender)
{
   WinExec("CeramClient.exe", SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::helpAboutActionExecute(TObject *Sender)
{
  TVersionInfo* vi = new TVersionInfo(NULL);
  AboutBox->ProductName->Caption = vi->ProductName;
  AboutBox->Version->Caption = vi->FileVersion;
  AboutBox->Copyright->Caption = vi->LegalCopyright;
  AboutBox->Comments->Caption = vi->Comments;
  AboutBox->ShowModal();
  delete vi;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::CheckBox2Click(TObject *Sender)
{
    SaveParams();
    this->m_engine.useAprox = CheckBox2->Checked;
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::viewVideoControlActionExecute(TObject *Sender)
{
	VideoControlDlg->Visible = !VideoControlDlg->Visible;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::viewVideoControlActionUpdate(TObject *Sender)
{
	viewVideoControlAction->Enabled = dynamic_cast<TPh3iCubeSource* >(m_videoSource) != NULL;
	viewVideoControlAction->Checked = VideoControlDlg->Visible;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::viewRawContourActionExecute(TObject *Sender)
{
    viewRawContourAction->Checked = !viewRawContourAction->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::viewRawContourActionUpdate(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Reset()
{
    m_engine.Reset();
    if (m_buffer != NULL)
	    m_buffer->Clear();
	ShowResult();

    //todo:
    if (m_videoSource != NULL)
    {
	    m_videoSource->Next();
	    m_videoSource->Prev();
    }
}

void __fastcall TMainForm::helpManualActionExecute(TObject *Sender)
{
    UnicodeString adr = ExtractFilePath(Application->ExeName);
    adr+= "\\manual.pdf";
	ShellExecute(this->WindowHandle,L"open",adr.c_str() ,NULL,NULL, SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::toolPaneActionExecute(TObject *Sender)
{
	PhImage1->SelectPhTool(PhPaneTool1);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::toolPaneActionUpdate(TObject *Sender)
{
    toolPaneAction->Checked =  dynamic_cast< TPhPaneTool*>(PhImage1->PhTool) != NULL;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::toolRulerActionExecute(TObject *Sender)
{
	PhImage1->SelectPhTool(PhRulerTool1);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::toolRulerActionUpdate(TObject *Sender)
{
    toolRulerAction->Checked =  dynamic_cast< TPhRulerTool*>(PhImage1->PhTool) != NULL;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::toolSelRectActionExecute(TObject *Sender)
{
	PhImage1->SelectPhTool(PhSelRectTool1);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::toolSelRectActionUpdate(TObject *Sender)
{
    toolSelRectAction->Enabled = this->CheckBox3->Checked;
    toolSelRectAction->Checked = dynamic_cast< TPhSelRectTool*>(PhImage1->PhTool) != NULL;
}
//---------------------------------------------------------------------------



void __fastcall TMainForm::CheckBox3Click(TObject *Sender)
{
	if (!this->CheckBox3->Checked)
    {
        TRect r(0,0,0,0);
        PhImage1->SetSelRect(r);
    }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ApplicationEvents1Idle(TObject *Sender, bool &Done)
{
	if (VideoControlDlg->Visible && VideoControlDlg->CheckBox1->Checked )
	{
		//iCube SDK_GetExposure
		TPh3iCubeSource* c = dynamic_cast<TPh3iCubeSource* >(m_videoSource);
		if (c != NULL)
			  VideoControlDlg->Edit8->Text = FormatFloat("###.#", c->ExploshureTime);
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::PhTrackBar1MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
    if (this->m_videoSource != NULL)
        m_videoSource->CurrentFrame = PhTrackBar1->Position;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::PhTrackBar1Change(TObject *Sender)
{
    if (this->m_videoSource != NULL)
    {
		StatusBar1->Panels->Items[1]->Text = L"���� "  + IntToStr( PhTrackBar1->Position ) +
   		" of " + IntToStr(m_videoSource->NumFrames);

    }
}
//---------------------------------------------------------------------------


