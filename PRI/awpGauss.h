//---------------------------------------------------------------------------
#ifndef awpGaussH
#define awpGaussH

//---------------------------------------------------------------------------
AWPRESULT awpGaussLinear(awpImage* matrix, awpImage* y, awpImage* result);
AWPRESULT awpMatrixTranspose (awpImage* matrix, awpImage* result);
AWPRESULT awpMulMatrix(awpImage* matrix1, awpImage* matrix2, awpImage** ppDst);
AWPRESULT awpMatrixInvert(awpImage* matrix, awpImage* invert);
AWPRESULT awpLinearRegress(awpImage* matrix, awpImage* y, awpImage* b);
#endif
