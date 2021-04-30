#include "ArduinoSerial.h"
#include <QSerialPortInfo>
#include <QDebug>

ArduinoSerial::ArduinoSerial(QObject *parent)
{
    m_serial = new QSerialPort(nullptr);
    connect(m_serial, &QSerialPort::readyRead, this, &ArduinoSerial::readData);
}
ArduinoSerial::~ArduinoSerial()
{
    delete m_serial;
    qDebug("By in Thread!");
    emit finished_Port();//Сигнал о завершении работы
}

bool ArduinoSerial::OpenArduino()
{
    bool result = false;

    const QString c_description = "Arduino Uno";
    const QString c_manufaturer = "Arduino LLC (www.arduino.cc)";


    const auto serialPortInfos = QSerialPortInfo::availablePorts();
    for(const QSerialPortInfo &serialPortInfo:serialPortInfos)
    {
        QString description = serialPortInfo.description();
        QString manufacturer = serialPortInfo.manufacturer();
        QString serialNumber = serialPortInfo.serialNumber();
        if (description.contains(c_description) && manufacturer.contains(c_manufaturer))
        {
            result = true;
            m_currentSettings.name = serialPortInfo.portName();
            m_currentSettings.baudRate = 9600;
            m_currentSettings.stringBaudRate = QString::number(m_currentSettings.baudRate);
            m_currentSettings.dataBits = QSerialPort::Data8;
            m_currentSettings.stringDataBits = "8";
            m_currentSettings.parity = QSerialPort::NoParity;
            m_currentSettings.stringParity = "No parity";
            m_currentSettings.stopBits = QSerialPort::OneStop;
            m_currentSettings.stringStopBits = "1";
            m_currentSettings.flowControl = QSerialPort::NoFlowControl;
            m_currentSettings.stringFlowControl = "None";
            break;
        }
    }
    if (!result)
    {
        qDebug() << "ERROR: Cannot find Arduino.";
        return result;
    }
    // open serial port
    m_serial->setPortName(m_currentSettings.name);
    m_serial->setBaudRate(m_currentSettings.baudRate);
    //m_serial->setDataBits(m_currentSettings.dataBits);
    //m_serial->setParity(m_currentSettings.parity);
    //m_serial->setStopBits(m_currentSettings.stopBits);
    //m_serial->setFlowControl(m_currentSettings.flowControl);
    result = m_serial->open(QIODevice::ReadWrite);
    if (!result)
        qDebug() << "ERROR: cannot connect to Arduino.";
    else
    {
        qDebug() << "INFO: connected to " + m_currentSettings.name;
    }
    return result;
}
void ArduinoSerial::CloseArduino()
{
    if (m_serial->isOpen())
    {
        m_serial->close();
    }
}

bool ArduinoSerial::WriteData(const char* data, int len)
{
     bool result = false;
     QByteArray d(data, len);
     if (m_serial->isOpen())
     {
         qDebug() << "Write to arduino: " << d;
         int size =  m_serial->write(data, len);
         qDebug() << "Sending " << size << " bytes";
         result = size > 0;
         if (!result)
             qDebug() << "Error writing to port:  " << d;

     }
     else
         qDebug() << "port is not open!";
     return result;
}

void ArduinoSerial::readData()
{
  const QByteArray d = m_serial->readAll();
  QString dataAsString = QString(d);
  qDebug() << "Read from arduino: " + dataAsString;
  emit outPort(dataAsString);
}
