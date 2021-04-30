#include <QtCore/qglobal.h>
#include <QApplication>
#include <QSerialPortInfo>
#include <QSerialPort>
#include <QTextStream>
#include <QTextCodec>
#include <QDebug>
#include "phserialport.h"
#include "ArduinoSerial.h"
#include "arduinocontroller.h"
#include <iostream>
using namespace std;



/*
    c - API
*/
// global
int * argc = nullptr;
char ** argv = nullptr;
QApplication * app = nullptr;

const QList<QSerialPortInfo> *ginfos = NULL;
void PHSERIALPORT_API phserialPortInit()
{
    const auto infos = QSerialPortInfo::availablePorts();
    ginfos = new QList<QSerialPortInfo>(infos);
}

void PHSERIALPORT_API phserialPortFree()
{
    delete ginfos;
}

void PHSERIALPORT_API phserialPortCount(int& count)
{
    count = 0;
    if (ginfos == NULL)
        return;
    count = ginfos->count();
}
PHSERIALPORT_API const char* phserialPortName(char* buf, int index)
{
    memset(buf,0,PHSERIAL_BUF);

    if (ginfos == NULL)
        return NULL;
    if (index < 0 || index > ginfos->count())
        return NULL;
    QSerialPortInfo info = ginfos->at(index);
    QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
    QByteArray encodedString = codec->fromUnicode(ginfos->at(index).portName());
    sprintf(buf, "%s", encodedString.data());
    return buf;
}

PHSERIALPORT_API const char* phserialPortLocation(char* buf, int index)
{
    memset(buf,0,PHSERIAL_BUF);

    if (ginfos == NULL)
        return NULL;
    if (index < 0 || index > ginfos->count())
        return NULL;
    QSerialPortInfo info = ginfos->at(index);
    QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
    QByteArray encodedString = codec->fromUnicode(ginfos->at(index).systemLocation());
    sprintf(buf, "%s", encodedString.data());
    return buf;
}

PHSERIALPORT_API const char* phserialPortDescription(char* buf, int index)
{
    memset(buf,0,PHSERIAL_BUF);
    if (ginfos == NULL)
        return NULL;
    if (index < 0 || index > ginfos->count())
        return NULL;
    QSerialPortInfo info = ginfos->at(index);
    QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
    QByteArray encodedString = codec->fromUnicode(ginfos->at(index).description());
    sprintf(buf, "%s", encodedString.data());
    return buf;
}

PHSERIALPORT_API const char* phserialPortManufacturer(char* buf, int index)
{
    memset(buf,0,PHSERIAL_BUF);
    if (ginfos == NULL)
        return NULL;
    if (index < 0 || index > ginfos->count())
        return NULL;
    QSerialPortInfo info = ginfos->at(index);
    QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
    QByteArray encodedString = codec->fromUnicode(ginfos->at(index).manufacturer());
    sprintf(buf, "%s", encodedString.data());
    return buf;
}

PHSERIALPORT_API const char* phserialPortSerialNumber(char* buf, int index)
{
    memset(buf,0,PHSERIAL_BUF);
    if (ginfos == NULL)
        return NULL;
    if (index < 0 || index > ginfos->count())
        return NULL;
    QSerialPortInfo info = ginfos->at(index);
    QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
    QByteArray encodedString = codec->fromUnicode(ginfos->at(index).serialNumber());
    sprintf(buf, "%s", encodedString.data());
    return buf;
}

PHSERIALPORT_API void phserialPortHasVendorIdentifier(bool& value, int index)
{
    value = false;
    if (ginfos == NULL)
        return;
    if (index < 0 || index > ginfos->count())
        return;
    value = ginfos->at(index).hasVendorIdentifier();
}
PHSERIALPORT_API void phserialPortHasProductIdentifier(bool& value, int index)
{
    value = false;
    if (ginfos == NULL)
        return;
    if (index < 0 || index > ginfos->count())
        return;
    value = ginfos->at(index).hasProductIdentifier();
}

PHSERIALPORT_API void phserialPortVendorIdentifier(unsigned short& value, int index)
{
    value = 0;
    if (ginfos == NULL)
        return;
    if (index < 0 || index > ginfos->count())
        return;
    value = ginfos->at(index).vendorIdentifier();
}
PHSERIALPORT_API void phserialPortProductIdentifier(unsigned short& value, int index)
{
    value = 0;
    if (ginfos == NULL)
        return;
    if (index < 0 || index > ginfos->count())
        return;
    value = ginfos->at(index).productIdentifier();
}
//////////
PHSERIALPORT_API HANDLE arduinoCreate(ArduinoCallback read, ArduinoCallback error)
{
    if (app != nullptr)
        return NULL;

    argc = new int(1);
    argv = new char*[1];
    argv[0] = strdup("dummy");
    app = new QApplication(*argc, argv);


    ArduinoController* a = new ArduinoController(NULL);
    if (!a->Connect())
    {
        delete a;
        return NULL;
    }
    a->OnError = error;
    a->OnRead  = read;

//    app->processEvents();
    return (HANDLE)a;
}
PHSERIALPORT_API void   arduinoFree(HANDLE arduino)
{
    if (arduino == NULL)
        return;
    ArduinoController* a = (ArduinoController*)arduino;
    a->Disconnect();
    delete a;

    delete app;
    delete argv[0];
    delete [] argv;
    delete argc;
    argc = nullptr;
    argv = nullptr;
    app = nullptr;
}
PHSERIALPORT_API bool   arduinoWrite(HANDLE arduino, char* data, int len)
{
    ArduinoController* a = (ArduinoController*)arduino;
    return a->writeData(data, len);
}







