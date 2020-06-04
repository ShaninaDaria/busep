#ifndef DATATRANSMIT_H
#define DATATRANSMIT_H

#include <QObject>
#include <QDebug>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QFile>

#include "../hdr/common.h"

//const char *const port_busep = "/dev/ttyAP1";
//const int baud_rate = 9600;

class DataTransmit : public QObject
{
public:
    explicit DataTransmit(QObject *parent = NULL);
    ~DataTransmit();

//    bool readConfigFile();

    QList <QSerialPortInfo> getAllSerialPorts();
    bool openSerialPort(QString port_name, int baud_rate);
    qint64 receive(void *buf, size_t size, int wait_ms);
    qint64 send(const void *buf, size_t size, int wait_ms);
    void closeSerialPort();

    QSerialPort *serial_port() const;

private:
    void initSerialPort(QString port_name, int baud_rate);

    QSerialPort *_serial_port;
    QList <QSerialPortInfo> sp_info;
};

#endif // DATATRANSMIT_H
