//---------------------------------------------------------------------------
// database of labeled images
// ver 1.0
// definition of TDbLabeledImages

#ifndef DbLabeledImagesH
#define DbLabeledImagesH
#include "vcl.h"
#include <ComCtrls.hpp>
#include "_LF.h"

typedef void __fastcall (__closure *TDbProgressEvent)(int Progress, AnsiString& aComment);
enum EExportFormat {awp, jpeg};
enum EFaceExportOptions {
eAll = 0,
eAll_w_Glasses = 1,
eAll_w_Breads = 2,
eAll_w_Breads_a_Glasses = 3,
eFront = 4,
eFront_w_Glasses = 5,
eFront_w_Breads = 6,
eFront_w_Glasses_a_Breads = 7,
eTurn = 8,
eTurn_w_Glasses = 9,
eTurn_w_Breads = 10,
eTurn_w_Glasses_a_Breads = 11,
eGlasses = 12,
eGlasses_a_Front = 13,
eGlasses_a_Turn = 14,
eGlasses_a_Breads = 15,
eBreads = 16,
eBreads_a_Front = 17,
eBreads_a_Turn = 18
};
struct SDBWhithoutOverapsOptions
{
	float  Threshold;
	double minSize;
	double maxSize;
	bool   expotToSubset;
	bool   deleteEmpty;
};
///////////////////////////////////////////////////////////////////////////////
// export fragments options
struct SDbExportOptions
{
	AnsiString      strPathToExport;		//
	bool            useScanner;				//
	EExportFormat   exportFormat;           //
	float           scannerThreshold;       //
	bool            exportNearlest;         // Экспортировать ближайший
	bool 			exportCovered;			// Экспортировать только покрывающие
	bool            needFlip;               //
	int				racurs;                 //
	bool 			needResize;             //
	int				baseSize;               //
	bool 			copyIeye;               //
	bool 			copyRandom;             //
    bool 			copyBackground;			//
	int				random;                 //
	TStringList*    ClassLabels;			//
};
////////////////////////////////////////////////////////////////////////////////
// database copy options
struct SDbCopyOptions
{
	AnsiString strPathToCopy;
	bool copyImages;
	bool copySemantic;
	bool copyIeye;
	bool copyFace;
};
////////////////////////////////////////////////////////////////////////////////
// convert database options
struct SDbConvertOptions
{
	bool    needResize;
	int     baseWidth;
	bool    interpolation;
	bool    RenameToUUID;
	EExportFormat format;
};
struct SDbExportFaceOptions
{
	AnsiString strPathToExport;
	bool needResize;
	int  newWidth;
    bool needRotate;
    EFaceExportOptions attrToSave;
    // attributes
    bool needRotated;
    int  maxRotate;
    bool needTurnToLeft;
    bool ExportToSubset;
};
struct SDBFaceStatistics
{
	int NumItems;
	int NumBig;
	int NumMedium;
	int NumSmall;
	int NumRotated;
	int NumRotatedLeft;
	int NumRotatedRight;
	int NumRacurs;
	int NumTurnLeft;
	int NumTurnRight;
	int NumGlasses;
	int NumBread;
	int NumTurn;
};
/*
	Изображение в базе данных
*/
class TLFDbItem : public TLFObject
{
protected:
	std::string m_strFileName;
	bool 		m_hasXml;
	bool 		m_hasIeye;
	bool 		m_hasFace;
	bool 		m_selected;
	const char* GetFileName();
	TLFSemanticImageDescriptor m_Descriptor;

public:
	TLFDbItem();
	virtual ~TLFDbItem();

	bool __fastcall Init(const char* lpFileName);
	void __fastcall Delete();
	void __fastcall CopyTo(SDbCopyOptions& optioins);

	__property const char* FileName = {read = GetFileName};
	__property bool  HasXml =  {read = m_hasXml};
	__property bool  HasIeye = {read = m_hasIeye};
	__property bool  HasFace = {read = m_hasFace};
	__property bool  Selected = {read = m_selected, write = m_selected};
};

class TLFDbSemanticItem : public TLFObject
{
protected:
	std::string m_strFileName;
	bool 		m_selected;
	TLFDetectedItem* m_item;
	const char* GetFileName();
	awpImage*   GetImage();
public:
	TLFDbSemanticItem();
	virtual ~TLFDbSemanticItem();

	bool __fastcall Init(const char* lpFileName, TLFDetectedItem* itm);
	__property const char* FileName = {read = GetFileName};
	__property bool  Selected = {read = m_selected, write = m_selected};
	__property awpImage* image = {read = GetImage};
	__property TLFDetectedItem* Item = {read = m_item};
};
//---------------------------------------------------------------------------
// TDbLabeledImages
class TDbLabeledImages
{
protected:
	AnsiString 					m_strDbName;
	TLFObjectList       		m_dataFiles;
	TLFObjectList       		m_dataItems;
	TLFSemanticDictinary		m_dictionary;

	int        m_NumImages;
	int        m_NumEyeFiles;
	int        m_NumEyeItems;
	int        m_NumFaceFiles;
	int        m_NumXmlFiles;
	int        m_NumXmlItems;
	ILFDetectEngine* m_engine;
	TDbProgressEvent m_ProgressEvent;

	void __fastcall Clear();

	void __fastcall SaveFragment(awpImage* img, SDbExportOptions& options, int count, TLFRect& scanBox, TLFRoiImageDescriptor* roid = NULL, const char* lpClassLabel = NULL);
    void __fastcall SaveBackground(SDbExportOptions& options);
	AnsiString 		MakeExportFileName(SDbExportOptions& options, int num, bool fliped, const char* lpClassLabel = NULL);
	AnsiString __fastcall GetDbMetadata(AnsiString& strDbPath);
	void __fastcall MakeDbMetadata(AnsiString& strDbPath, const char* lpMetadata);

	TLFSemanticDictinary* __fastcall GetDictionary();
public:
	TDbLabeledImages();
	~TDbLabeledImages();

	void __fastcall Init(AnsiString& strDbPath, ILFDetectEngine* engine = NULL);
	const char* __fastcall GetFileName(int index);
	awpImage*	__fastcall GetSemanticImage(int index);
	void 		__fastcall DeleteSementicItem(int index);
	void 		__fastcall DeleteDatabaseItem(int index);

	// Convert eye image description to xml image description
	void __fastcall ConvertEyeToXml(bool removeEye, bool saveFace, bool saveEyes);
	// Convert face image description to iEye image descriptoion
	void __fastcall ConvertFaceToEye();
	//Export of image fragments to the specified directory
	void __fastcall ExportFragments(SDbExportOptions& options);
	void __fastcall ExportFaceDatabase(SDbExportFaceOptions& options);
	void __fastcall FindEmptyFiles();
	void __fastcall GetFaceStatisctics(SDBFaceStatistics& stat);
	int __fastcall  GetWithoutOverlaps(SDBWhithoutOverapsOptions& options, int& NumOverlaps);
	void __fastcall MakeShapeDatabase(AnsiString& strPath);
	void __fastcall ConvertDatabase(SDbConvertOptions& convert_options);

	void __fastcall ConvertSemanticBW();
	void __fastcall SplitDatabase(UnicodeString strPath, UnicodeString strPath1, UnicodeString strpath2, double propValue );

	// копирование всех изображений базы данных в соответствии со спецификацией   SDbCopyOptions
	void __fastcall CopyDatabase(SDbCopyOptions& options);

	awpImage* __fastcall GetDbThumbinals(int thmbWidth = 128, int thmbHeight = 96);

	void __fastcall MakeSemanticAnalysis(bool save_old);
	awpImage* __fastcall MakeSemanticThumbinals(int thmbWidth = 64, int thmbHeight = 64);

	void __fastcall CalculatePerfomance(float& far1, float& frr, float& ffar, float& time, float thr,  TProgressBar* bar);
	void __fastcall DoMarking(ILFDetectEngine* engine);
// properties
   __property AnsiString DbName = {read = m_strDbName};
   __property int NumImages    = {read = m_NumImages};
   __property int NumEyeFiles  = {read = m_NumEyeFiles};
   __property int NumXmlFiles  = {read = m_NumXmlFiles};
   __property int NumXmlItems  = {read = m_NumXmlItems};
   __property int NumEyeItems  = {read = m_NumEyeItems};
   __property int NumFaceFiles = {read = m_NumFaceFiles};
   __property TLFSemanticDictinary* Dictionary = {read =  GetDictionary};
// events
   __property  TDbProgressEvent OnProgress = {read = m_ProgressEvent, write = m_ProgressEvent};
};
#endif
