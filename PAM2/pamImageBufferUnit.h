//---------------------------------------------------------------------------
#ifndef pamImageBufferUnitH
#define pamImageBufferUnitH
#include "_LF.h"
//---------------------------------------------------------------------------
class TPamImageBuffer
{
protected:
	int m_count;
    int m_size;
	TLFImageList m_list;
	awpImage* Convert12BitToAwpFloat(int width, int height, unsigned char* data);
public:
	TPamImageBuffer(int size = 1);
	void __fastcall AddFrame(int width, int height, unsigned char* data);
	awpImage* getImage(int index);
	void __fastcall Clear();
	virtual void __fastcall Process();
};
#endif
