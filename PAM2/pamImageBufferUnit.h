//---------------------------------------------------------------------------
#ifndef pamImageBufferUnitH
#define pamImageBufferUnitH
#include "_LF.h"
//---------------------------------------------------------------------------
typedef enum {pam2bfDark, pam2bfFlash, pam2bfFoFm, pam2bfFtFm1}EPam2BufferType;
class TPamImageBuffer
{
protected:
	EPam2BufferType m_bufferType;
	int m_count;
	int m_size;
	TLFImageList m_list;
	awpImage* Convert12BitToAwpFloat(int width, int height, unsigned char* data);
public:
	TPamImageBuffer(EPam2BufferType bufferType = pam2bfDark);
	TPamImageBuffer(TPamImageBuffer& other);
	TPamImageBuffer& operator=(TPamImageBuffer& buffer);


	void __fastcall AddFrame(int width, int height, unsigned char* data);
	awpImage* getImage(int index);
	void __fastcall Clear();

	__property EPam2BufferType BufferType = {read = m_bufferType};
};
#endif
