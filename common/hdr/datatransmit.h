#ifndef DATATRANSMIT_H
#define DATATRANSMIT_H

#include <sys/socket.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <fcntl.h>

#include <QObject>
#include <QDebug>
#include <QSerialPort>
#include <QSerialPortInfo>

#include "../hdr/common.h"

//#define socket_name "/tmp/socket"
const char *const file_server = "/tmp/socket";
const char *const file_client = "/tmp/client";

const char *const port_busep = "/dev/ttyAP1";
const char *const port_pvkp = "/dev/ttyAP2";
const int baud_rate = 9600;

class DataTransmit : public QObject
{
public:
    explicit DataTransmit(QObject *parent = NULL);
    ~DataTransmit();

    void createServer();
    void createClient();

    int srvReceive(void *buf, size_t size);
    int srvSend(const void *buf, size_t size);
    int clntReceive(void *buf, size_t size);
    int clntSend(const void *buf, size_t size);

    void endTransmitServer();
    void endTransmitClient();

    QList <QSerialPortInfo> getAllSerialPorts();
    void setOneSerialPort(int number_serial_port);
    bool openSerialPort();
    void initSerialPort(QString port_name, int baud_rate);
    qint64 receive(void *buf, size_t size, int wait_ms);
    qint64 send(const void *buf, size_t size, int wait_ms);
    void closeSerialPort();
private:
//    rs485 *_rs485;

    QSerialPort *serial_port;
    QList <QSerialPortInfo> sp_info;

    int server;
    int client;
    struct sockaddr_un server_addr;
    struct sockaddr_un client_addr;
};

#endif // DATATRANSMIT_H
