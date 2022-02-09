//---------------------------------------------------------------------------

#ifndef priMainUnitH
#define priMainUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <System.Actions.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Menus.hpp>
#include "FImage41.h"
#include "_LF.h"
#include "Comm.h"
#include "EFW_filter.h"
#include "priInitUnit.h"


	// efw
	struct EFW_Cap{
		HANDLE Thr_getSlotNum;
		bool bThrGetSlotNumRun;
		HANDLE Thr_getPos;
		bool bThrGetPosRun;

	} ;

//---------------------------------------------------------------------------
class TpriMainForm : public TForm
{
__published:	// IDE-managed Components
	TActionList *ActionList1;
	TMainMenu *MainMenu1;
	TStatusBar *StatusBar1;
	TAction *fileCloseAction;
	TMenuItem *N1;
	TMenuItem *N2;
	TPhImage *PhImage1;
	TAction *startAction;
	TAction *stopAction;
	TMenuItem *Start1;
	TMenuItem *Stop1;
	TMenuItem *N3;
	TComm *Comm1;
	TMenuItem *N4;
	TMenuItem *N5;
	TAction *modeTuningAction;
	TAction *modeExperimentAction;
	TMenuItem *N6;
	TComm *Comm2;
	void __fastcall fileCloseActionExecute(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall startActionExecute(TObject *Sender);
	void __fastcall stopActionExecute(TObject *Sender);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall Comm1RxChar(TObject *Sender, DWORD Count);
	void __fastcall modeTuningActionExecute(TObject *Sender);
	void __fastcall modeTuningActionUpdate(TObject *Sender);
	void __fastcall modeExperimentActionExecute(TObject *Sender);
	void __fastcall modeExperimentActionUpdate(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Comm2RxChar(TObject *Sender, DWORD Count);
private:	// User declarations

    BEGIN_MESSAGE_MAP
	VCL_MESSAGE_HANDLER(WM_USER+1, TMessage, WMUSER1)
	VCL_MESSAGE_HANDLER(WM_USER+2, TMessage, WMUSER2)
	END_MESSAGE_MAP(TForm)
	void __fastcall WMUSER1(TMessage & msg);
	void __fastcall WMUSER2(TMessage & msg);


	UnicodeString __fastcall FindArduinoDevice();
	UnicodeString __fastcall FindASCOMDevice();

	bool             m_hardware_ready;

	enum EProgramMode{
		pmTuning,
		pmExperiment
	} m_programMode;

	// arduino
	UnicodeString m_arduinoPort;
	UnicodeString m_arduinoStatus;
	UnicodeString m_arduinoSN;
	// ascom
	UnicodeString m_ascomPort;

	// pylon
	HANDLE camera;
	int m_exposure;

	void __fastcall SetExposure(const int value);

	int  __fastcall GetVideoMode();
	void __fastcall SetVideoMode(int value);

	// led
	int m_ledState;
	void __fastcall SetLedState(int value);
	AnsiString rs;

	// ascom
	UnicodeString m_strAscomStatus;
	AnsiString ars;
	UnicodeString m_strFocus;
	int           m_ascomAperture;
	void __fastcall SetFocus(const UnicodeString value);
	void __fastcall SetAperture(const int value);

	// efw
	UnicodeString m_strEFWStatus;
	EFW_INFO m_info;
	int     m_efwPosition;
	EFW_Cap m_cap;

	void __fastcall SetEFWSlot(int num);
	void __fastcall refreshPosStatus();

	//
	bool m_setupInProgress;


	// ini file
	TPriInitFile m_iniFile;
	TPriInitFile* __fastcall GetIniFile();
public:		// User declarations
	__fastcall TpriMainForm(TComponent* Owner);
	void __fastcall TakePicture();
	void __fastcall AscomCommand(AnsiString& command);

	void __fastcall SetupFilter(int filter);

	TLFImage m_Image;


	__property UnicodeString arduinoPort = {read = m_arduinoPort};
	__property UnicodeString arduinoStatus = {read = m_arduinoStatus};
	__property UnicodeString arduinoSN = {read = m_arduinoSN};


	__property int exposure = {read = m_exposure, write = SetExposure};
	__property int videoMode = {read = GetVideoMode, write = SetVideoMode};

	__property int ledState = {read = m_ledState, write = SetLedState};

	__property UnicodeString ascomStatus = {read = m_strAscomStatus};
	__property UnicodeString ascomPort 	 = {read = m_ascomPort};
	__property UnicodeString ascomFocus	 = {read = m_strFocus, write = SetFocus};
	__property int ascomAperture = {read = m_ascomAperture, write = SetAperture};
	__property EFW_INFO info = {read = m_info};
	__property int efwPosition = {read = m_efwPosition, write = SetEFWSlot};
	__property EFW_Cap cap = {read = m_cap};
	__property UnicodeString efwStatus = {read = m_strEFWStatus};

	__property TPriInitFile* iniFile = {read = GetIniFile};
};
//---------------------------------------------------------------------------
extern PACKAGE TpriMainForm *priMainForm;
//---------------------------------------------------------------------------
#endif
