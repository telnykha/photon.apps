#ifndef ARDUINOCONTROLLER_H
#define ARDUINOCONTROLLER_H

#include <QObject>
#include <QThread>
#include "ArduinoSerial.h"
#include "phserialport.h"

class ArduinoController : public QObject
{
    Q_OBJECT
    QThread workerThread;
public:
    explicit ArduinoController(QObject *parent = nullptr);
    ~ArduinoController();
    bool Connect();
    bool Disconnect();
    bool isOpen();
    bool writeData(const char* data, int len);
    ArduinoCallback OnError;
    ArduinoCallback OnRead;
public slots:
    void _OnError(QString& error);
    void _OnRead(QString& data);
private:
    ArduinoSerial* m_port;
};

#endif // ARDUINOCONTROLLER_H
