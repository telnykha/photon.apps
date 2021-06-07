//---------------------------------------------------------------------------
#pragma hdrstop
#include "pamMainUnit.h"
#include "pamImageBufferUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

TPamImageBuffer::TPamImageBuffer(EPam2BufferType bufferType)
{
	m_count = 0;
	m_bufferType = bufferType;
	switch(m_bufferType)
	{
		case pam2bfDark:
		case pam2bfFlash:
			m_size = 1;
		break;
		case pam2bfFoFm:
		case pam2bfFtFm1:
			m_size = 7;
		break;
	}
}

TPamImageBuffer::TPamImageBuffer(TPamImageBuffer& other)
{
	this->m_count = other.m_count;
	this->m_size  = other.m_size;
	this->m_bufferType = other.m_bufferType;
	for (int i = 0; i < m_size; i++)
	{
		TLFImage* _img = new TLFImage();
		_img->SetImage(other.getImage(i));
		m_list.AddImage(_img);
	}
}

TPamImageBuffer& TPamImageBuffer::operator=(TPamImageBuffer& buffer)
{
   if (this != &buffer)
   {
        m_list.Clear();
		this->m_count = buffer.m_count;
		this->m_size  = buffer.m_size;
		this->m_bufferType = buffer.m_bufferType;
		for (int i = 0; i < m_count; i++)
		{
			TLFImage* _img = new TLFImage();
			_img->SetImage(buffer.getImage(i));
			m_list.AddImage(_img);
		}
   }
   return *this;
}


void __fastcall TPamImageBuffer::AddFrame(int width, int height, unsigned char* data)
{
	 awpImage* img =  Convert12BitToAwpFloat(width, height, data);
	 if (img != NULL && m_count < m_size)
	 {
		TLFImage* _img = new TLFImage();
		_img->SetImage(img);
		m_list.AddImage(_img);
        _AWP_SAFE_RELEASE_(img)
	 }
	 m_count++;
	 if (m_count >= m_size) {
		// в буфере закончились кадры, отправляем его в документ
		pamMainForm->doc->SetBuffer(this);
#ifdef _DEBUG
     _DebugSave(ExtractFilePath(Application->ExeName));
#endif
	 }
}

#ifdef _DEBUG
void __fastcall TPamImageBuffer::_DebugSave(const UnicodeString path )
{
	for (int i ; i < m_list.GetCount(); i++)
	{
		TLFImage* img = m_list.GetImage(i);
		AnsiString fname = path + "\\" + IntToStr(i) + ".awp";
        img->SaveToFile(fname.c_str());
	}
}

#endif

awpImage* TPamImageBuffer::getImage(int index)
{
	if (index < 0 || index >= m_list.GetCount()) {
		return NULL;
	}
	return m_list.GetImage(index)->GetImage();
}
// преобразование 12ти битного изображения с видеокамеры Mightex
// в awpImage типа AWP_FLOAT
awpImage* TPamImageBuffer::Convert12BitToAwpFloat(int width, int height, unsigned char* data)
{
   awpImage* img = NULL;
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
		   dst[i] = (float)value;
		   i++;
	   }

   }
   return img;
}

void __fastcall TPamImageBuffer::Clear()
{
	m_list.Clear();
	m_count = 0;
}



