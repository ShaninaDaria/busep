#include "../../common/hdr/datatransmit.h"

DataTransmit::DataTransmit(QObject *parent) : QObject (parent)
{
    //    _rs485 = new rs485();
    //    _rs485->receive();
    //    _rs485->close();
}

//----------------------------------------------------------

DataTransmit::~DataTransmit()
{
    //    delete  _rs485;
}

//----------------------------------------------------------

void DataTransmit::createServer()
{
    if ((server = socket(AF_UNIX, SOCK_DGRAM, 0)) < 0)
    {
        perror("-socket error\n");
        exit(1);
    }
    else
    {
        std::cout << "create server socket" << std::endl;
    }

    unlink(file_server);
    bzero(&server_addr, sizeof(server_addr));

    server_addr.sun_family = AF_UNIX/*AF_LOCAL*/;
    strcpy(server_addr.sun_path, file_server);

    if (bind (server, (struct sockaddr *)&server_addr, /*server_add_len*/ SUN_LEN (&server_addr)) < 0)
    {
        perror("-bind error");

        exit(1);
    }
    else
    {
        std::cout << "bind ok " << std::endl;
    }

//    if (listen (server, 1) == -1)
//    {
//        perror("-listen error");
//        exit(1);
//    }
//    else
//    {
//        std::cout << "listen ok " << std::endl;
//    }

//    socklen_t client_add_len = sizeof (server_addr);
//    fd_socket = accept (server, (struct sockaddr*)&client_addr, &client_add_len);
//    if (fd_socket < 0)
//    {
//        perror("-accept error\n");
//        exit(1);
//    }
//    else
//    {
//        std::cout << "accept ok " << fd_socket << std::endl;
//    }

    if (fcntl(server, F_SETFL, O_NONBLOCK) != 0)
    {
        perror("-fcntl error\n");
        exit(1);
    }
}

//----------------------------------------------------------

void DataTransmit::createClient()
{
    bzero(&server_addr, sizeof (server_addr));
    server_addr.sun_family = AF_UNIX;
    strcpy(server_addr.sun_path, file_server);

    if ((client = socket(AF_LOCAL, SOCK_DGRAM, 0)) < 0)
    {
        perror("-socket error\n");
        exit(1);
    }
    else
    {
        std::cout << "create client socket" << std::endl;
        bzero(&client_addr, sizeof (client_addr));
        client_addr.sun_family = AF_UNIX;
        strcpy(client_addr.sun_path, file_client);
        mkstemp(client_addr.sun_path);
    }


    if (bind (client, (struct sockaddr *)&client_addr, /*server_add_len*/ SUN_LEN (&client_addr)) < 0)
    {
        perror("-bind error");
        endTransmitClient();
        exit(1);

//        if ((client = socket(AF_LOCAL, SOCK_DGRAM, 0)) < 0)
//        {
//            perror("-socket error\n");
//            exit(1);
//        }
//        else
//        {
//            std::cout << "create client socket" << std::endl;
//            bzero(&client_addr, sizeof (client_addr));
//            client_addr.sun_family = AF_UNIX/*AF_LOCAL*/;
//            strcpy(client_addr.sun_path, file_client);
//            mkstemp(client_addr.sun_path);
//        }
    }
    else
    {
        std::cout << "bind ok " << std::endl;
    }

//    if (connect (fd_socket, (struct sockaddr*)&client_addr, SUN_LEN (&client_addr)) < 0)
//    {
//        perror("-connect error\n");
//        exit(1);
//    }
//    else
//    {
//        std::cout << "connect ok" << std::endl;
//    }

    if (fcntl(client, F_SETFL, O_NONBLOCK) != 0)
    {
        perror("-fcntl error\n");
        exit(1);
    }
}

//----------------------------------------------------------

int DataTransmit::srvReceive(void *buf, size_t size)
{
    socklen_t addr_len = sizeof(struct sockaddr_un);

    int bytes_recv(0);

    bytes_recv = recvfrom(server, buf, size, 0,
                          (struct sockaddr *)&client_addr, &addr_len);

    return bytes_recv;
}

//----------------------------------------------------------

int DataTransmit::srvSend(const void *buf, size_t size)
{
    socklen_t addr_len = sizeof(struct sockaddr_un);

    int bytes_send(0);
    bytes_send = sendto(server, buf, size, 0,
                        (struct sockaddr*)&client_addr, addr_len);

    return bytes_send;
}

//----------------------------------------------------------

int DataTransmit::clntReceive(void *buf, size_t size)
{
//    socklen_t addr_len = SUN_LEN(&server_addr);

    int bytes_recv(0);

    bytes_recv = recvfrom(client, buf, size, 0,
                          /*(struct sockaddr *)&server_addr*/ NULL, /*&addr_len*/0);

    return bytes_recv;
}

//----------------------------------------------------------

int DataTransmit::clntSend(const void *buf, size_t size)
{
    int bytes_send(0);
    bytes_send = sendto(client, buf, size, 0,
                        (struct sockaddr*)&server_addr, SUN_LEN(&server_addr));

    return bytes_send;
}

//----------------------------------------------------------

void DataTransmit::endTransmitServer()
{
    close(server);
    unlink (file_server);
}

//----------------------------------------------------------

void DataTransmit::endTransmitClient()
{
    close(client);
    unlink(file_client);
}

//----------------------------------------------------------

QList<QSerialPortInfo> DataTransmit::getAllSerialPorts()
{
    QSerialPortInfo sp_i;
    return sp_info = sp_i.availablePorts();
}

//----------------------------------------------------------

void DataTransmit::setOneSerialPort(int number_serial_port)
{
    serial_port->setPort(sp_info.at(number_serial_port));
}

//----------------------------------------------------------

bool DataTransmit::openSerialPort()
{
    return serial_port->open(QSerialPort::ReadWrite);
}

//----------------------------------------------------------

void DataTransmit::initSerialPort(QString port_name, int baud_rate)
{
    serial_port = new QSerialPort(this);
    serial_port->setPortName(port_name);
    serial_port->setBaudRate(baud_rate, QSerialPort::AllDirections);
    serial_port->setDataBits(QSerialPort::Data8);
    serial_port->setParity(QSerialPort::NoParity);
    serial_port->setStopBits(QSerialPort::OneStop);
    serial_port->setFlowControl(QSerialPort::NoFlowControl);
}

//----------------------------------------------------------

qint64 DataTransmit::receive(void *buf, size_t size, int wait_ms)
{
//    int bytes_recv = read(client, buf, sizeof(size));
//    return bytes_recv;

    serial_port->waitForReadyRead(wait_ms);
    qint64 bytes = serial_port->read(static_cast<char *>(buf), size);

    return bytes;
}

//----------------------------------------------------------

qint64 DataTransmit::send(const void *buf, size_t size, int wait_ms)
{
//    int bytes_send = write(client, buf, size);
//    return bytes_send;

    qint64 bytes_send = serial_port->write(static_cast<const char *>(buf), size);
//    qDebug() << "bytesToWrite1" << serial_port->bytesToWrite();
    while (serial_port->bytesToWrite() != 0)
    {
//        qDebug() << "waitForBytesWritten" << serial_port->waitForBytesWritten(wait_ms);
        serial_port->waitForBytesWritten(wait_ms);
    }
//    qDebug() << "bytesToWrite2" << serial_port->bytesToWrite();

    return bytes_send;
}

//----------------------------------------------------------

void DataTransmit::closeSerialPort()
{
    serial_port->close();
}

//----------------------------------------------------------
