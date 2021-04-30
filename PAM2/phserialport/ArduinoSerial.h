#ifndef ARDUINOSERIAL_H
#define ARDUINOSERIAL_H
#include <QObject>
#include <QSerialPort>
#include "phserialport.h"
class ArduinoSerial : public QObject
{
Q_OBJECT
public:
    struct Settings {
        QString name;
        qint32 baudRate;
        QString stringBaudRate;
        QSerialPort::DataBits dataBits;
        QString stringDataBits;
        QSerialPort::Parity parity;
        QString stringParity;
        QSerialPort::StopBits stopBits;
        QString stringStopBits;
        QSerialPort::FlowControl flowControl;
        QString stringFlowControl;
        bool localEchoEnabled;
    };


    explicit ArduinoSerial(QObject *parent = nullptr);
    ~ArduinoSerial() override;
    QSerialPort* m_serial;

signals:
    void finished_Port(); //Сигнал закрытия класса
    void error_(QString& err);//Сигнал ошибок порта
    void outPort(QString& data); //Сигнал вывода полученных данных

public slots:

    bool OpenArduino();
    void CloseArduino();
    bool WriteData(const char* data, int len);
    void readData();
private:
    Settings m_currentSettings;
};

#endif // ARDUINOSERIAL_H
