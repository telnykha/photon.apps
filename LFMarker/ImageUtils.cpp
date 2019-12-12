//---------------------------------------------------------------------------
#include <vcl.h>

#pragma hdrstop
#include "ImageUtils.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

awpRect TRect2awpRect(TRect& rect)
{
	awpRect result;
    result.left = (AWPWORD)rect.Left;
    result.top  = (AWPWORD)rect.top;
    result.right = (AWPWORD)rect.Right;
    result.bottom = (AWPWORD)rect.bottom;
    return result;
}

