#include "../../common/hdr/datatransmit.h"

DataTransmit::DataTransmit(QObject *parent) : QObject (parent)
{
    _serial_port = new QSerialPort(this);
}

//----------------------------------------------------------

DataTransmit::~DataTransmit()
{
    delete _serial_port;
}

//----------------------------------------------------------
/*
bool DataTransmit::readConfigFile()
{
    QFile file;
    file.setFileName("config.ini");
    QString port_name;
    int baud_rate;
    if (file.exists())
    {
        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
//        if (file.isOpen())
        {
            qDebug() << file.fileName();
            while (!file.atEnd())
            {
                port_name = file.readLine();
                baud_rate = file.readLine().toInt();
                qDebug() << port_name << baud_rate;
            }

            file.close();

            if (!port_name.isEmpty() && (baud_rate != 0))
            {
                return openSerialPort(port_name, baud_rate);
            }
        }
        else
        {
            qDebug() << "Error open file 'config.ini'";
        }
    }
    else
    {
        qDebug() << "No file 'config.ini'";
    }

    return false;
}
*/
//----------------------------------------------------------

QList<QSerialPortInfo> DataTransmit::getAllSerialPorts()
{
    QSerialPortInfo sp_i;
    return sp_info = sp_i.availablePorts();
}

//----------------------------------------------------------

bool DataTransmit::openSerialPort(QString port_name, int baud_rate)
{
#ifdef QNX
    initSerialPort(port_name, baud_rate);
//    if (_serial_port->open(QSerialPort::ReadWrite))
    _serial_port->open(QSerialPort::ReadWrite);
    if (_serial_port->isOpen())
    {
        qDebug() << "open true";
        return true;
    }
    else
    {
        qDebug() << "open false";
        _serial_port->close();
    }
    return false;
#else
    _serial_port->open(QSerialPort::ReadWrite);
    if (_serial_port->isOpen())
    {
        initSerialPort(port_name, baud_rate);
        return true;
    }
    else
    {
        _serial_port->close();
    }
    return false;
#endif
}

//----------------------------------------------------------

void DataTransmit::initSerialPort(QString port_name, int baud_rate)
{
    _serial_port->setPortName(port_name);
    _serial_port->setBaudRate(baud_rate, QSerialPort::AllDirections);
    _serial_port->setDataBits(QSerialPort::Data8);
    _serial_port->setParity(QSerialPort::NoParity);
    _serial_port->setStopBits(QSerialPort::OneStop);
    _serial_port->setFlowControl(QSerialPort::NoFlowControl);
}

//----------------------------------------------------------

QSerialPort *DataTransmit::serial_port() const
{
    return _serial_port;
}

//----------------------------------------------------------

qint64 DataTransmit::receive(void *buf, size_t size, int wait_ms)
{
    _serial_port->waitForReadyRead(wait_ms);
    qint64 bytes_rcv = _serial_port->read(static_cast<char *>(buf), size);
    if (bytes_rcv < 0)
    {
        qDebug() << _serial_port->errorString();
    }
//    qDebug() << "bytes " << bytes << " for " << wait_ms << "ms";

    return bytes_rcv;
}

//----------------------------------------------------------

qint64 DataTransmit::send(const void *buf, size_t size, int wait_ms)
{
    qint64 bytes_send = _serial_port->write(static_cast<const char *>(buf), size);
//    qDebug() << "bytesToWrite1" << serial_port->bytesToWrite();
    while (_serial_port->bytesToWrite() != 0)
    {
        /*qDebug() << "waitForBytesWritten" <<*/ _serial_port->waitForBytesWritten(wait_ms);
    }

    if (bytes_send < 0)
    {
        qDebug() << _serial_port->errorString();
    }

    return bytes_send;
}

//----------------------------------------------------------

void DataTransmit::closeSerialPort()
{
    _serial_port->close();
}

//----------------------------------------------------------
