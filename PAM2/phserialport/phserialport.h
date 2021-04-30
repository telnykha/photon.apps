/*
    c -api for qt serial port engine
*/
#ifndef PHSERIALPORT_H
#define PHSERIALPORT_H

#define PHSERIAL_BUF 2048
typedef void* HANDLE;

#if defined(PHSERIALPORT_LIBRARY)
#  define PHSERIALPORT_API  __declspec(dllexport)
#else
#  define PHSERIALPORT_API  __declspec(dllimport)
#endif

extern "C"
{
// serial port enumerator
void PHSERIALPORT_API phserialPortInit();
void PHSERIALPORT_API phserialPortFree();

void PHSERIALPORT_API phserialPortCount(int& count);
PHSERIALPORT_API const char* phserialPortName(char* buf, int index);
PHSERIALPORT_API const char* phserialPortLocation(char* buf, int index);
PHSERIALPORT_API const char* phserialPortDescription(char* buf, int index);
PHSERIALPORT_API const char* phserialPortManufacturer(char* buf, int index);
PHSERIALPORT_API const char* phserialPortSerialNumber(char* buf, int index);
PHSERIALPORT_API void phserialPortHasVendorIdentifier(bool& value, int index);
PHSERIALPORT_API void phserialPortHasProductIdentifier(bool& value, int index);
PHSERIALPORT_API void phserialPortVendorIdentifier(unsigned short& value, int index);
PHSERIALPORT_API void phserialPortProductIdentifier(unsigned short& value, int index);

// arduino serial
typedef void (* ArduinoCallback)(const char *BytePtr, int len);
// arduino interface
PHSERIALPORT_API HANDLE arduinoCreate(ArduinoCallback read, ArduinoCallback error);
PHSERIALPORT_API void   arduinoFree(HANDLE arduino);
PHSERIALPORT_API bool   arduinoWrite(HANDLE arduino, char* data, int len);



}
#endif // PHSERIALPORT_H
