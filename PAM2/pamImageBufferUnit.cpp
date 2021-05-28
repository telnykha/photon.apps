//---------------------------------------------------------------------------
#pragma hdrstop
#include "pamMainUnit.h"
#include "pamImageBufferUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

TPamImageBuffer::TPamImageBuffer(int size)
{
	m_count = 0;
	m_size = size;
}

void __fastcall TPamImageBuffer::AddFrame(int width, int height, unsigned char* data)
{
	 awpImage* img =  Convert12BitToAwpFloat(width, height, data);
	 if (img != NULL && m_count < m_size)
	 {
		TLFImage* _img = new TLFImage();
		_img->SetImage(img);
		m_list.AddImage(_img);

	 }
	 m_count++;
	 if (m_count >= m_size) {
		// Подготовка результирующего изображения
		// и обновление экрана
		Process();
		pamMainForm->SetPicture(getImage(0));
	 }
}

awpImage* TPamImageBuffer::getImage(int index)
{
	if (index < 0 || index >= m_list.GetCount()) {
		return NULL;
	}
	return m_list.GetImage(index)->GetImage();
}

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

void __fastcall TPamImageBuffer::Process()
{
	for (int i = 0; i < m_list.GetCount(); i++) {
		awpImage* img = m_list.GetImage(i)->GetImage();
		awpConvert(img, AWP_CONVERT_TO_BYTE_WITH_NORM);
	}
}




