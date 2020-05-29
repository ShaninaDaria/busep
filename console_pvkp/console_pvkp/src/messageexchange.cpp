#include <signal.h>
//#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>
#include "hdr/messageexchange.h"

messageExchange::messageExchange(QObject *parent) : QObject(parent)
{
    formingIMpvkp = new FormingIM_pvkp();
    dataTransnmit = new DataTransmit();

//    thread = new QThread(this);
//    dataTransnmit->moveToThread(thread);
//    connect(thread, SIGNAL(finished()), dataTransnmit, SLOT(deleteLater()));
//    thread->start();

    bytes_send_IS1 = -1;
    bytes_send_IS2 = -1;

    _parse_IS3 = _parse_IS4 = false;
    _parse_IS5 = false;
    _start_exchange = false;

    createIS1();

    bzero(&IS3, sizeof(_is3));
    bzero(&IS4, sizeof(_is4));

    timerIS1_IS3 = new QTimer(this);
    connect(timerIS1_IS3, SIGNAL(timeout()), this, SLOT(slotWaitingForIS3()));

    timerIS2_IS4 = new QTimer(this);
    connect(timerIS2_IS4, SIGNAL(timeout()), this, SLOT(slotWaitingForIS4()));
}

//----------------------------------------------------------

messageExchange::~messageExchange()
{
    if (timerIS1_IS3->isActive())
    {
        timerIS1_IS3->stop();
    }
    if (timerIS2_IS4->isActive())
    {
        timerIS2_IS4->stop();
    }
//    dataTransnmit->endTransmitClient();
    dataTransnmit->closeSerialPort();
    delete dataTransnmit;
//    delete thread;
    delete formingIMpvkp;
}

//----------------------------------------------------------

void messageExchange::initTransmit()
{
    dataTransnmit->createClient();
}

//----------------------------------------------------------

QList<QSerialPortInfo> messageExchange::getAllSerialPorts()
{
    return dataTransnmit->getAllSerialPorts();
}

//----------------------------------------------------------

bool messageExchange::openSerialPort(QString port_name, int baud_rate)
{
    dataTransnmit->initSerialPort(port_name, baud_rate);

    return dataTransnmit->openSerialPort();
}

//----------------------------------------------------------

void messageExchange::createIS1()
{
    IS1 = formingIMpvkp->createIS1();
}

//----------------------------------------------------------

void messageExchange::createIS2(int number, output_cntrl cntrl)
{
//    qDebug() << number;
    IS2 = formingIMpvkp->createIS2(static_cast<unsigned char>(number), cntrl);
}

//----------------------------------------------------------

void messageExchange::startExchange()
{
    qDebug() << __FUNCTION__;
    // надо допринять остатки
    qint64 bytes(0);
    do
    {
        bytes = dataTransnmit->receive(&rcv_data, sizeof (_rcv_data), wait100ms);
    } while (bytes > 0);

    _start_exchange = true;
    bytes_send_IS1 = sendIS1();
    timerIS1_IS3->setSingleShot(true);
    timerIS1_IS3->start(wait100ms);
}

//----------------------------------------------------------

void messageExchange::usualExchange()
{
//    qDebug() << __FUNCTION__;
    _start_exchange = false;

    bytes_send_IS1 = sendIS1();
    if (!timerIS1_IS3->isActive())
    {
        if (timerIS1_IS3->isSingleShot())
        {
            timerIS1_IS3->setSingleShot(false);
        }
        timerIS1_IS3->start(wait100ms);
        qDebug() << "timerIS1_IS3->start(wait100ms)";
    }
}

//----------------------------------------------------------

void messageExchange::stopExchange()
{
    qDebug() << __FUNCTION__;
    if (timerIS1_IS3->isActive())
    {
        timerIS1_IS3->stop();
    }

    if (timerIS2_IS4->isActive())
    {
        timerIS2_IS4->stop();
    }

    bytes_send_IS1 = bytes_send_IS2 = -1;
    _parse_IS3 = _parse_IS4 = _parse_IS5 = false;
}

//----------------------------------------------------------
// для проверки приема на БУСЭП - только отправка по таймеру
void messageExchange::slotWaitingForIS3()
{
//    qDebug() << __FUNCTION__ << wait100ms;
    exchange(timerIS1_IS3, bytes_send_IS1, wait100ms, is1_is3);
}

//----------------------------------------------------------
// для проверки приема на БУСЭП - только отправка по таймеру
void messageExchange::slotWaitingForIS4()
{
    qDebug() << __FUNCTION__ << wait10ms;
    exchange(timerIS2_IS4, bytes_send_IS2, wait10ms, is2_is4);
}

//----------------------------------------------------------

void messageExchange::exchange(QTimer *main_timer,
                               qint64 &bytes_send, int wait_ms, type_exchange var_exch)
{
//    qDebug() << __FUNCTION__ << bytes_send << wait_ms << var_exch;
    if (bytes_send > 0)
    {
        qint64 bytes_rcv(-1);
        bytes_rcv = receiveSmth(wait_ms);
        if (bytes_rcv > 0)
        {
//            bytes_send = 0;
//            qDebug() << "bytes_send" << bytes_send_IS1 << bytes_send_IS2;

            if (!_parse_IS5)
            {
                if (var_exch == is1_is3)
                {
                    qDebug() << "emit signalReceiveIS3()";
                    emit signalReceiveIS3();
                }
                if (var_exch == is2_is4)
                {
                    qDebug() << "emit signalReceiveIS4()";
                    emit signalReceiveIS4();
                }
            }
            else
            {
                qDebug() << "emit signalReceiveIS5()";
                emit signalReceiveIS5();
            }
        }
    }
    else
    {
        if (main_timer->isActive())
        {
            main_timer->stop();
        }
    }
}

//----------------------------------------------------------

qint64 messageExchange::sendIS1()
{
    // на отправку даю 10 мс
    bytes_send_IS1 = dataTransnmit->send(&IS1, sizeof(_is1), wait10ms);
//    int bytes_send = dataTransnmit->clntSend(IS1, sizeof(_is1));

//    if (bytes_send > 0)
//    {
        qDebug() << __FUNCTION__ << "send " << bytes_send_IS1 << " bytes;";
//    }
    return bytes_send_IS1;
}

//----------------------------------------------------------

qint64 messageExchange::sendIS2()
{
    // на отправку даю 10 мс
    bytes_send_IS2 = dataTransnmit->send(&IS2, sizeof(_is2), wait10ms);
//    int bytes_send = dataTransnmit->clntSend(IS2, sizeof(_is2));

//    if (bytes_send > 0)
//    {
        qDebug() << __FUNCTION__ << " send " << bytes_send_IS2 << " bytes;\n";
//    }

    if (timerIS1_IS3->isActive())
    {
        timerIS1_IS3->stop();
    }
    timerIS2_IS4->start(wait10ms);

    return bytes_send_IS2;
}

//----------------------------------------------------------

qint64 messageExchange::receiveSmth(int wait_ms)
{
    bzero(&rcv_data, sizeof (_rcv_data));
    qint64 bytes_rcv = dataTransnmit->receive(&rcv_data, sizeof (_rcv_data), wait_ms);
//    int bytes_rcv = dataTransnmit->clntReceive(&rcv_data, sizeof (_rcv_data));

    if (bytes_rcv > 0)
    {
        if (rcv_data.byte00 == header)
        {
            qDebug() << __FUNCTION__ << " wait_ms " << wait_ms << "; managed" << rcv_data.byte01 << "; receive " << bytes_rcv << " bytes;";

            if (rcv_data.byte01 == response_state)
            {
                formingIMpvkp->parsingIS3(&rcv_data, IS3, _parse_IS3);
            }

            if (rcv_data.byte01 == response_change)
            {
                if (timerIS2_IS4->isActive())
                {
                    timerIS2_IS4->stop();
                }

                formingIMpvkp->parsingIS4(&rcv_data, IS4, _parse_IS4);
            }

            if (rcv_data.byte01 == integrity_violation)
            {
                if (timerIS2_IS4->isActive())
                {
                    timerIS2_IS4->stop();
                }
                formingIMpvkp->parsingIS5(&rcv_data, IS5, _parse_IS5);
            }
        }
        else
        {
            bytes_rcv = -1;
        }
    }
    else
    {
        qDebug() << "not received bytes for " << wait_ms << " ms";
    }

    return bytes_rcv;
}

//----------------------------------------------------------

bool messageExchange::start_exchange() const
{
    return _start_exchange;
}

//----------------------------------------------------------

bool messageExchange::parse_IS4() const
{
    return _parse_IS4;
}

//----------------------------------------------------------

bool messageExchange::parse_IS3() const
{
    return _parse_IS3;
}

//----------------------------------------------------------

char *messageExchange::getInputsValue()
{
    return formingIMpvkp->getInputs();
}

//----------------------------------------------------------

input_state messageExchange::getInputState(int number)
{
    return formingIMpvkp->getInputState(number);
}

//----------------------------------------------------------

char *messageExchange::getOutputsValue()
{
    return formingIMpvkp->getOutputs();
}

//----------------------------------------------------------

output_state messageExchange::getOutputState(int number)
{
    return formingIMpvkp->getOutputState(number);
}

//----------------------------------------------------------

void messageExchange::addErrorToIS1()
{
    std::cout << __FUNCTION__ << std::endl;
    IS1 = formingIMpvkp->createIS1WithError();
}

//----------------------------------------------------------

void messageExchange::addErrorToIS2(int number, output_cntrl cntrl)
{
    std::cout << __FUNCTION__ << std::endl;
    IS2 = formingIMpvkp->createIS2WithError(static_cast<unsigned char>(number), cntrl);
}

//----------------------------------------------------------
