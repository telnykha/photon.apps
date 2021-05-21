//---------------------------------------------------------------------------
#pragma hdrstop
#include "pam2DocINode.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
 ILFPam2docNode::ILFPam2docNode(ILFPam2docNode* parent)
 {
    m_parent = parent;
 }
 const char* ILFPam2docNode::GetName()
 {
	return "ILFPam2docNode";
 }

int __fastcall ILFPam2docNode::GetChildCount()
{
	return this->m_childs.GetCount();
}

ILFPam2docNode* __fastcall ILFPam2docNode::GetChild(int index)
{
	 if (index < 0 || index >= this->m_childs.GetCount())
		return NULL;
	ILFPam2docNode* node = (ILFPam2docNode*)m_childs.Get(index);
	return node;
}

void __fastcall ILFPam2docNode::AddChild(ILFPam2docNode* child)
{
	m_childs.Add(child);
}

void __fastcall ILFPam2docNode::DeleteChild(int index)
{
	 if (index < 0 || index >= this->m_childs.GetCount())
		return;
	 m_childs.Delete(index);
}

void __fastcall ILFPam2docNode::RemoveChild(ILFPam2docNode* child)
{
	 m_childs.Remove(child);
}


