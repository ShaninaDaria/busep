#include <signal.h>
//#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>
#include "hdr/messageexchange.h"

//----------------------------------------------------------

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
    no_rcv_count = 0;

    _parse_IS3 = _parse_IS4 = false;
    _parse_IS5 = false;
    _start_exchange = true;

    createIS1();
#ifdef QNX
    bzero(&IS3, sizeof(_is3));
    bzero(&IS4, sizeof(_is4));
#else
    memset(&IS3, 0, sizeof (_is3));
    memset(&IS4, 0, sizeof (_is4));
#endif

    timerIS1_IS3 = new QTimer(this);
    //    connect(timerIS1_IS3, SIGNAL(timeout()), this, SLOT(slotWaitingForIS3()));
    connect(timerIS1_IS3, SIGNAL(timeout()), this, SLOT(slotUsualExchange()));

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
    dataTransnmit->closeSerialPort();
    delete dataTransnmit;
    //    delete thread;
    delete formingIMpvkp;
}

//----------------------------------------------------------

QList<QSerialPortInfo> messageExchange::getAllSerialPorts()
{
    return dataTransnmit->getAllSerialPorts();
}

//----------------------------------------------------------

bool messageExchange::openSerialPort(QString port_name, int baud_rate)
{
    if (dataTransnmit->openSerialPort(port_name, baud_rate))
    {
        return true;
    }
    return false;
}

//----------------------------------------------------------

QString messageExchange::portName()
{
    return dataTransnmit->serial_port()->portName();
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
    // надо допринять остатки
    qint64 bytes(0);
    do
    {
        bytes = dataTransnmit->receive(&rcv_data, sizeof (_rcv_data), wait100ms);
    } while (bytes > 0);

    bytes_send_IS1 = sendIS1();
    timerIS1_IS3->setSingleShot(true);
    timerIS1_IS3->start(wait100ms);
}

//----------------------------------------------------------

void messageExchange::testConnection()
{
//    // надо допринять остатки
//    qint64 bytes(0);
//    do
//    {
//        bytes = dataTransnmit->receive(&rcv_data, sizeof (_rcv_data), wait100ms);
//    } while (bytes > 0);

    bytes_send_IS1 = sendIS1();

    if (bytes_send_IS1 > 0)
    {
        qint64 bytes_rcv(-1);
        bytes_rcv = receiveSmth(wait100ms, true);

        emit signalTest(QString("Принято %1 байт").arg(bytes_rcv));
    }
    else
    {
        emit signalTest("Ошибка отправки ИС1");
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

void messageExchange::slotWaitingForIS4()
{
    //    qDebug() << __FUNCTION__ << bytes_send << wait_ms << var_exch;
    if (bytes_send_IS2 > 0)
    {
        qint64 bytes_rcv(-1);
        bytes_rcv = receiveSmth(wait10ms);
        if (bytes_rcv > 0)
        {
            if (!_parse_IS5)
            {
                if (_parse_IS4)
                {
//                    qDebug() << "emit signalReceiveIS4()";
                    emit signalReceiveIS4();
                }
            }
            else
            {
//                qDebug() << "emit signalReceiveIS5()";
                emit signalReceiveIS5();
            }
        }
        else
        {
            qDebug() << "emit signalNoReceiveIS4()";
            emit signalNoReceiveIS4();
        }
    }
    else
    {
        if (timerIS2_IS4->isActive())
        {
            timerIS2_IS4->stop();
        }
    }
}

//----------------------------------------------------------

bool messageExchange::parse_IS5() const
{
    return _parse_IS5;
}

//----------------------------------------------------------

void messageExchange::usualExchange2()
{
    _start_exchange = false;

    if (!timerIS1_IS3->isActive())
    {
        if (timerIS1_IS3->isSingleShot())
        {
            timerIS1_IS3->setSingleShot(false);
        }
        timerIS1_IS3->start(wait100ms);
    }
}

//----------------------------------------------------------

void messageExchange::slotUsualExchange()
{
    bytes_send_IS1 = sendIS1();

    if (bytes_send_IS1 > 0)
    {
        qint64 bytes_rcv(-1);
        bytes_rcv = receiveSmth(wait100ms);
        if (bytes_rcv > 0)
        {
            if (!_parse_IS5)
            {
                if (_parse_IS3)
                {
                    emit signalReceiveIS3();
                }
            }
            else
            {
                emit signalReceiveIS5();
            }
        }
        else
        {
            emit signalNoReceiveIS3();
        }
    }
    else
    {
        if (timerIS1_IS3->isActive())
        {
            timerIS1_IS3->stop();
        }
    }
}

//----------------------------------------------------------

qint64 messageExchange::sendIS1()
{
    // на отправку даю 100 мс
    bytes_send_IS1 = dataTransnmit->send(&IS1, sizeof(_is1), wait100ms);

    //    if (bytes_send > 0)
    //    {
    //        qDebug() << __FUNCTION__ << "send " << bytes_send_IS1 << " bytes;";
    //    }

    // чтобы начать отсчет итераций непришедших данных с начала
    no_rcv_count = 0;
    return bytes_send_IS1;
}

//----------------------------------------------------------

qint64 messageExchange::sendIS2()
{
    // чтобы не сообщения не отправлялись до того, как поздоровались
    if (!_start_exchange)
    {
        if (timerIS1_IS3->isActive())
        {
            timerIS1_IS3->stop();
            //        qDebug() << "timerIS1_IS3->stop();";
        }
        // на отправку даю 100 мс
        bytes_send_IS2 = dataTransnmit->send(&IS2, sizeof(_is2), wait100ms);

        //    if (bytes_send > 0)
        //    {
        qDebug() << __FUNCTION__ << " send " << bytes_send_IS2 << " bytes;\n";
        //    }

        timerIS2_IS4->start(wait10ms);
        {
            qDebug() << "timerIS2_IS4->start(wait10ms);";
        }

        // чтобы начать отсчет итераций непришедших данных с начала
        no_rcv_count = 0;
    }

    return bytes_send_IS2;
}

//----------------------------------------------------------

qint64 messageExchange::receiveSmth(int wait_ms, bool test)
{
    QByteArray ba;
    QString str;

#ifdef QNX
    bzero(&rcv_data, sizeof (_rcv_data));
#else
    memset(&rcv_data, 0, sizeof (_rcv_data));
#endif
    qint64 bytes_rcv = dataTransnmit->receive(&rcv_data, sizeof (_rcv_data), wait_ms);

    if (bytes_rcv > 0)
    {
        if (test)
        {
            qDebug() << "test connection" <<
                        rcv_data.byte00 << rcv_data.byte01 << rcv_data.byte02 << rcv_data.byte03 <<
                        rcv_data.byte04 << rcv_data.byte05 << rcv_data.byte06 << rcv_data.byte07 <<
                        rcv_data.byte08 << rcv_data.byte09 << rcv_data.byte10 << rcv_data.byte11 <<
                        rcv_data.byte12 << rcv_data.byte13 << rcv_data.byte14 << rcv_data.byte15 <<
                        rcv_data.byte16 << rcv_data.byte17 << rcv_data.byte18 << rcv_data.byte19 <<
                        rcv_data.byte20 << rcv_data.byte21 << rcv_data.byte22 << rcv_data.byte23 <<
                        rcv_data.byte24 << rcv_data.byte25 << rcv_data.byte26 << rcv_data.byte27 <<
                        rcv_data.byte28 << rcv_data.byte29 << rcv_data.byte30 << rcv_data.byte31 <<
                        rcv_data.byte32 << rcv_data.byte33;
        }
        no_rcv_count = 0;
        if (rcv_data.byte00 == header)
        {
            //            qDebug() << __FUNCTION__ << " wait_ms " << wait_ms << "; managed" << rcv_data.byte01 << "; receive " << bytes_rcv << " bytes;";

            if (rcv_data.byte01 == response_state)
            {
                formingIMpvkp->copyIS3fromRcvData(&rcv_data, IS3);
                formingIMpvkp->parsingIS3(&IS3, _parse_IS3);
                _parse_IS5 = false;
            }

            if (rcv_data.byte01 == response_change)
            {
                if (timerIS2_IS4->isActive())
                {
                    timerIS2_IS4->stop();
//                    qDebug() << "timerIS2_IS4->stop();";
                }

                formingIMpvkp->copyIS4fromRcvData(&rcv_data, IS4);
                formingIMpvkp->parsingIS4(&IS4, _parse_IS4);
                _parse_IS5 = false;
            }

            if (rcv_data.byte01 == integrity_violation)
            {
                if (timerIS2_IS4->isActive())
                {
                    timerIS2_IS4->stop();
                }
                formingIMpvkp->copyIS5fromRcvData(&rcv_data, IS5);
                formingIMpvkp->parsingIS5(&IS5, _parse_IS5);
            }

            //            qDebug() << "_parse_IS3" << _parse_IS3 << "; _parse_IS4" << _parse_IS4 << "; _parse_IS5" << _parse_IS5;
        }
        else
        {
            bytes_rcv = -1;
        }
    }
    else
    {
//        if (no_rcv_count < 3)
//        {
            qDebug() << "don`t receive bytes for " << wait_ms << " ms; repeat " << no_rcv_count;
//        }
        no_rcv_count++;
        /// NOTE если 3 раза ничего не приходит, останавливаю посылку (любую!)
        /// тут уж пусть оператор снова нажимает
        if (no_rcv_count == 3)
        {
            if (timerIS1_IS3->isActive())
            {
                timerIS1_IS3->stop();
                qDebug() << "timerIS1_IS3->stop();";
            }
            if (timerIS2_IS4->isActive())
            {
                timerIS2_IS4->stop();
                qDebug() << "timerIS2_IS4->stop();";
            }
        }
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

void messageExchange::setParse_IS4(bool parse_IS4)
{
    _parse_IS4 = parse_IS4;
}

//----------------------------------------------------------

bool messageExchange::parse_IS3() const
{
    return _parse_IS3;
}

//----------------------------------------------------------

void messageExchange::setParse_IS3(bool parse_IS3)
{
    _parse_IS3 = parse_IS3;
}

//----------------------------------------------------------

input_state messageExchange::getInputState(int number)
{
    return formingIMpvkp->getInputState(number);
}

//----------------------------------------------------------

output_state messageExchange::getOutputState(int number)
{
    return formingIMpvkp->getOutputState(number);
}

//----------------------------------------------------------

void messageExchange::addErrorToIS1()
{
    qDebug() << __FUNCTION__;
    IS1 = formingIMpvkp->createIS1WithError();
}

//----------------------------------------------------------

void messageExchange::addErrorToIS2(int number, output_cntrl cntrl)
{
    qDebug() << __FUNCTION__;
    IS2 = formingIMpvkp->createIS2WithError(static_cast<unsigned char>(number), cntrl);
}

//----------------------------------------------------------
