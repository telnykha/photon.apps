//---------------------------------------------------------------------------
#ifndef pam2DocINodeH
#define pam2DocINodeH
//---------------------------------------------------------------------------
#include "_LF.h"

class ILFPam2docNode : public TLFObject
{
private:
	  ILFPam2docNode* m_parent;
	  TLFObjectList   m_childs;
	  int __fastcall GetChildCount();
	  ILFPam2docNode* __fastcall GetChild(int index);
public:
	 ILFPam2docNode(ILFPam2docNode* parent);
	 virtual bool SaveXMLNode(TiXmlNode* node) = 0;
	 virtual TiXmlNode* LoadXMLNode(TiXmlNode* node) = 0;
	 virtual const char* GetName();

	 void __fastcall AddChild(ILFPam2docNode* child);
	 void __fastcall DeleteChild(int index);
	 void __fastcall RemoveChild(ILFPam2docNode* child);

	 __property ILFPam2docNode* parent = {read = m_parent};
	 __property int ChildCount = {read = GetChildCount};
	 __property ILFPam2docNode* Child[int index] = {read = GetChild};
};
#endif
