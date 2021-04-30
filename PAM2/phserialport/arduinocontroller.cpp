#include <QDebug>
#include "arduinocontroller.h"
ArduinoController::ArduinoController(QObject *parent) : QObject(parent)
{
    m_port = new ArduinoSerial(this);
    m_port->moveToThread(&workerThread);
    m_port->m_serial->moveToThread(&workerThread);

    //
    connect(m_port, SIGNAL(finished_Port()), &workerThread, SLOT(quit()));//Переназначение метода выход
    connect(m_port, SIGNAL(finished_Port()), &workerThread, SLOT(deleteLater()));//Удалить к чертям поток
    connect(m_port, SIGNAL(error_(QString&)), this, SLOT(_OnError(QString&)));//Лог ошибок
    connect(m_port, SIGNAL(outPort(QString&)), this, SLOT(_OnRead(QString&)));//Чтение данных

    OnError = nullptr;
    OnRead  = nullptr;
    workerThread.start();
}

ArduinoController::~ArduinoController()
{
    workerThread.quit();
    workerThread.wait();
}

void ArduinoController::_OnError(QString& error)
{
    qDebug() << error;
    // вызов callback
    if (OnError != nullptr)
    {
        QByteArray ba = error.toLocal8Bit();
        OnError(ba.data(), ba.length());
    }
}

void ArduinoController::_OnRead(QString& data)
{
    qDebug() << data;
    // вызов callback
    if (OnRead != nullptr)
    {
        QByteArray ba = data.toLocal8Bit();
        OnRead(ba.data(), ba.length());
    }
}

bool ArduinoController::Connect()
{
     return m_port->OpenArduino();
}
bool ArduinoController::Disconnect()
{
    m_port->CloseArduino();
    return true;
}
bool ArduinoController::isOpen()
{
    return m_port->m_serial->isOpen();
}
bool ArduinoController::writeData(const char* data, int len)
{
    return m_port->WriteData(data, len);
}
