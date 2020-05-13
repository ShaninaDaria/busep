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

    bytes_send_IS1 = -1;
    bytes_rcv_IS3_IS5 = -1;
    bytes_send_IS2 = -1;
    bytes_rcv_IS4_IS5 = -1;

    _parse_IS3 = false;
    _parse_IS4 = false;

    createIS1();
    /// NOTE по умолчанию шлю ИС2 с запросом "включить все выходы"
    createIS2(all_outputs, cntrl_on);

    bzero(&IS3, sizeof(_is3));
    bzero(&IS4, sizeof(_is4));

//    createTimer();

    timerIS1_IS3 = new QTimer(this);
    connect(timerIS1_IS3, SIGNAL(timeout()), this, SLOT(slotWaitingForIS3()));

    timerIS2_IS4 = new QTimer(this);
    connect(timerIS2_IS4, SIGNAL(timeout()), this, SLOT(slotWaitingForIS4()));

}

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
    dataTransnmit->endTransmitClient();
    delete dataTransnmit;
    delete formingIMpvkp;
}

void messageExchange::initTransmit()
{
    dataTransnmit->createClient();
}


void messageExchange::createIS1()
{
//    std::cout << __FUNCTION__ << std::endl;
    IS1 = formingIMpvkp->createIS1();
}

void messageExchange::createIS2(char number, output_cntrl cntrl)
{
//    printf("%s number %02x\n", __FUNCTION__, number);
    IS2 = formingIMpvkp->createIS2(number, cntrl);
}

void messageExchange::startExchange()
{
    bytes_send_IS1 = sendIS1(&IS1);
    timerIS1_IS3->setSingleShot(true);
    timerIS1_IS3->start(100);
    qDebug() << "1 timer start; remainingTime" << timerIS1_IS3->remainingTime();
}

void messageExchange::slotWaitingForIS3()
{
    qDebug() << "remainingTime" << timerIS1_IS3->remainingTime();
    if (bytes_send_IS1 > 0)
    {
        do
        {
            bytes_rcv_IS3_IS5 = receiveIS3(_parse_IS3);
            if (bytes_rcv_IS3_IS5 > 0)
            {
                bytes_send_IS1 = 0;
                qDebug() << "remainingTime after" << timerIS1_IS3->remainingTime() << "\n";
            }
//        } while (bytes_rcv_IS3 > 0);
          }  while ((timerIS1_IS3->remainingTime() > 0) && (timerIS1_IS3->remainingTime() < 100));
    }
    else
    {
        if (timerIS1_IS3->isActive())
        {
            timerIS1_IS3->stop();
        }
        qDebug() << "not send IS1!";
    }

    if (timerIS1_IS3->remainingTime() == 0)
    {
        qDebug() << "IT`S NO TIME FOR IS3!";
        timerIS1_IS3->stop();
    }

    if (timerIS1_IS3->remainingTime() == -1)
    {
        qDebug() << "timerIS1_IS3 is inactive!";
    }
    if (!_parse_IS3)
    {
        // раз я повторяю посылку до прихода корректного сообщения,
        // другое сообщение мне посылать не нужно
        if (timerIS2_IS4->isActive())
        {
            timerIS2_IS4->stop();
        }

//        if (!timerIS1_IS3->isActive())
//        {
//            timerIS1_IS3->setSingleShot(false);
//            timerIS1_IS3->start(100);
//        }
    }
    emit signalReceiveIS3();
}

void messageExchange::usualExchange()
{
    qDebug() << __FUNCTION__;
    //    while (1)
    //    {
    //        bytes_send = sendIS1(&IS1);
    //        if (bytes_send > 0)
    //        {
    //            do
    //            {
    //                bytes_rcv = receiveIS3();
    //            } while (bytes_rcv > 0);
    //        }
    bytes_send_IS1 = sendIS1(&IS1);
    if (!timerIS1_IS3->isActive())
    {
        if (timerIS1_IS3->isSingleShot())
        {
            timerIS1_IS3->setSingleShot(false);
        }
        timerIS1_IS3->start(100);
        qDebug() << "2 timer start; remainingTime" << timerIS1_IS3->remainingTime();
    }

//            bytes_send_IS2 = sendIS2(&IS2);
//            if (!timerIS2_IS4->isActive())
//            {
//                timerIS2_IS4->start(10);
//            }

//            if (bytes_send_IS2 > 0)
//            {
//                do
//                {
//                    bytes_rcv_IS4 = receiveIS4();
//                } while (bytes_rcv_IS4 > 0);
//            }
//        }
}

void messageExchange::slotWaitingForIS4()
{
    if (bytes_send_IS2 > 0)
    {
        do
        {
            bytes_rcv_IS4_IS5 = receiveIS4();
            if (bytes_rcv_IS4_IS5 > 0)
            {
                bytes_send_IS2 = 0;
            }
            qDebug() << "rt" << timerIS2_IS4->remainingTime();
//        } while (bytes_rcv_IS4 > 0);
        }  while ((timerIS2_IS4->remainingTime() > 0) && (timerIS2_IS4->remainingTime() < 10));
    }

    if (timerIS2_IS4->remainingTime() <= 0)
    {
        qDebug() << "IT`S NO TIME FOR IS4!";
    }

    if (_parse_IS4)
    {
        emit signalReceiveIS4();
    }
    else
    {
        // раз я повторяю посылку до прихода корректного сообщения,
        // другое сообщение мне посылать не нужно
        if (timerIS1_IS3->isActive())
        {
            timerIS1_IS3->stop();
        }

        timerIS2_IS4->start();
        emit signalReceiveIS5();
    }
}

int messageExchange::sendIS1(_is1 *IS1)
{
    ;
//    int bytes_send = dataTransnmit->send(IS1, sizeof(_is1));
    int bytes_send = dataTransnmit->clntSend(IS1, sizeof(_is1));

//    if (bytes_send > 0)
//    {
        qDebug() << __FUNCTION__ << "send " << bytes_send << " bytes;";
//    }
    return bytes_send;
}

int messageExchange::receiveIS3(bool &ok)
{
    _is3 rcv_IS3;
    bzero(&rcv_IS3, sizeof (_is3));
//    int bytes_rcv = dataTransnmit->receive(&rcv_IS3, sizeof (_rcv_data));
//    int bytes_rcv = dataTransnmit->clntReceive(&rcv_IS3, sizeof (_rcv_data));
    int bytes_rcv = dataTransnmit->clntReceive(&rcv_IS3, sizeof (_is3));

    if (bytes_rcv > 0)
    {
        qDebug() << __FUNCTION__ << " receive " << bytes_rcv << " bytes; ";

        if (bytes_rcv == sizeof(_is3))
        {
            IS3 = rcv_IS3;
            formingIMpvkp->parsingIS3(&IS3, ok);
        }
        else
        {
            if (bytes_rcv == sizeof(_is5))
            {
                IS5.header = IS3.header;
                IS5.managed = IS3.managed;
                IS5.crc = IS3.crc;
                formingIMpvkp->parsingIS5(IS5);
            }
            else
            {
                receiveIS3inParts(bytes_rcv, rcv_IS3, ok);
            }
        }
    }

    return bytes_rcv;
}

void messageExchange::receiveIS3inParts(int bytes_rcv, _is3 &rcv_IS3, bool &ok)
{
    static int summ_bytes(0);
    summ_bytes += bytes_rcv;

    if ((bytes_rcv == 8) || (bytes_rcv == 2))
    {
        if (rcv_IS3.header == header_and_managed::header)
        {
            // начало посылки
            IS3.header = rcv_IS3.header;
            IS3.managed = rcv_IS3.managed;
            IS3.word00 = rcv_IS3.word00;
            IS3.word01 = rcv_IS3.word01;
            IS3.word02 = rcv_IS3.word02;
            IS3.word03 = rcv_IS3.word03;
            IS3.word04 = rcv_IS3.word04;
            IS3.word05 = rcv_IS3.word05;
        }
        else
        {
            switch (summ_bytes)
            {
            case 16:
            {
                // т.к. всегда заполнены первые 8 байт
                IS3.word06 = rcv_IS3.header;
                IS3.word07 = rcv_IS3.managed;
                IS3.word08 = rcv_IS3.word00;
                IS3.word09 = rcv_IS3.word01;
                IS3.word10 = rcv_IS3.word02;
                IS3.word11 = rcv_IS3.word03;
                IS3.word12 = rcv_IS3.word04;
                IS3.word13 = rcv_IS3.word05;
            }
                break;

            case 24:
            {
                IS3.word14 = rcv_IS3.header;
                IS3.word15 = rcv_IS3.managed;
                IS3.word16 = rcv_IS3.word00;
                IS3.word17 = rcv_IS3.word01;
                IS3.word18 = rcv_IS3.word02;
                IS3.word19 = rcv_IS3.word03;
                IS3.word20 = rcv_IS3.word04;
                IS3.word21 = rcv_IS3.word05;
            }
                break;

            case 32:
            {
                IS3.word22 = rcv_IS3.header;
                IS3.word23 = rcv_IS3.managed;
                IS3.word24 = rcv_IS3.word00;
                IS3.word25 = rcv_IS3.word01;
                IS3.word26 = rcv_IS3.word02;
                IS3.word27 = rcv_IS3.word03;
                IS3.word28 = rcv_IS3.word04;
                IS3.word29 = rcv_IS3.word05;
            }
                break;

            case 34:
            {
                IS3.word30 = rcv_IS3.header;
                IS3.crc = rcv_IS3.managed;
            }
                break;
            }
        }

        if (summ_bytes == sizeof(_is3))
        {
            summ_bytes = 0;
            formingIMpvkp->parsingIS3(&IS3, ok);
        }
    }
}

int messageExchange::sendIS2(_is2 *IS2)
{

//    int bytes_send = dataTransnmit->send(IS2, sizeof(_is2));
    int bytes_send = dataTransnmit->clntSend(IS2, sizeof(_is2));

    if (bytes_send > 0)
    {
        std::cout << __FUNCTION__ << " send " << bytes_send << " bytes; " << std::endl;
//        printf("       header \t%02x\n", IS2->header);
//        printf("      managed \t%02x\n", IS2->managed);
//        printf("device_number \t%02x\n", IS2->device_number);
//        printf("        state \t%02x\n", IS2->state);
//        printf("          crc \t%02x\n", IS2->crc);
    }
    return bytes_send;
}

int messageExchange::receiveIS4()
{
    std::cout << __FUNCTION__ << std::endl;

    _is4 rcv_IS4;
    bzero(&rcv_IS4, sizeof (_is4));
//    int bytes_rcv = dataTransnmit->receive(&rcv_IS4, sizeof (_rcv_data));
    int bytes_rcv = dataTransnmit->clntReceive(&rcv_IS4, sizeof (_is4));

    if (bytes_rcv > 0)
    {
        if (bytes_rcv == sizeof(_is4))
        {
            std::cout << "receive " << bytes_rcv << " bytes; " << std::endl;
            IS4 = rcv_IS4;
            formingIMpvkp->parsingIS4(IS4, _parse_IS4);
        }
        else
        {
            if (bytes_rcv == sizeof (_is5))
            {
                IS5.header = IS4.header;
                IS5.managed = IS4.managed;
                IS5.crc = IS4.crc;
                formingIMpvkp->parsingIS5(IS5);
            }
            else
            {
                receiveIS4inParts(bytes_rcv, rcv_IS4);
            }
        }
    }

    return bytes_rcv;
}

void messageExchange::receiveIS4inParts(int bytes_rcv, _is4 &rcv_IS4)
{
    static int bytes(0);
    bytes += bytes_rcv;

    if ((bytes_rcv == 8) || (bytes_rcv == 3))
    {
        if (rcv_IS4.header == header_and_managed::header)
        {
            // начало посылки
            IS4.header = rcv_IS4.header;
            IS4.managed = rcv_IS4.managed;
            IS4.state00 = rcv_IS4.state00;
            IS4.state01 = rcv_IS4.state01;
            IS4.state02 = rcv_IS4.state02;
            IS4.state03 = rcv_IS4.state03;
            IS4.state04 = rcv_IS4.state04;
            IS4.state05 = rcv_IS4.state05;
        }
        else
        {
            switch (bytes)
            {
            case 16:
            {
                // т.к. всегда заполнены первые 8 байт
                IS4.state06 = rcv_IS4.header;
                IS4.state07 = rcv_IS4.managed;
                IS4.state08 = rcv_IS4.state00;
                IS4.state09 = rcv_IS4.state01;
                IS4.state10 = rcv_IS4.state02;
                IS4.state11 = rcv_IS4.state03;
                IS4.state12 = rcv_IS4.state04;
                IS4.state13 = rcv_IS4.state05;
            }
                break;

            case 19:
            {
                IS4.state14 = rcv_IS4.header;
                IS4.state15 = rcv_IS4.managed;
                IS4.crc = rcv_IS4.state00;
            }
                break;
            }
        }

        if (bytes == sizeof(_is4))
        {
            bytes = 0;
            formingIMpvkp->parsingIS4(IS4, _parse_IS4);
        }
    }
}

bool messageExchange::parse_IS4() const
{
    return _parse_IS4;
}

bool messageExchange::parse_IS3() const
{
    return _parse_IS3;
}

void messageExchange::createTimer()
{
    struct sigaction sa;
    struct itimerval timer;
    /* Назначение функции timer_handler обработчиком сигнала SIGVTALRM. */

    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = &timer_handler;
    sigaction(SIGVTALRM, &sa, NULL);

    /* Таймер сработает через 100 миллисекунд... */

    timer.it_value.tv_sec = 0;
    timer.it_value.tv_usec = 500000;

    /* ... и будет продолжать активизироваться каждые 100 миллисекунд. */

    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 500000;

    /* Запуск виртуального таймера. Он подсчитывает фактическое время работы процесса. */

    setitimer(ITIMER_VIRTUAL, &timer, NULL);

    /* Переход в бесконечный цикл. */

    while (1);
}

void messageExchange::timer_handler(int signum)
{

    static int count = 0;

//    printf("timer expired %d times ", ++count);

    qDebug() << signum << " one timer expired" << ++count << "times ";

}

char *messageExchange::getInputsValue()
{
    return formingIMpvkp->getInputs();
}

input_state messageExchange::getInputState(int number)
{
    return formingIMpvkp->getInputState(number);
}

char *messageExchange::getOutputsValue()
{
    return formingIMpvkp->getOutputs();
}

output_state messageExchange::getOutputState(int number)
{
    return formingIMpvkp->getOutputState(number);
}

int messageExchange::getBytes_rcv_IS3_IS5() const
{
    return bytes_rcv_IS3_IS5;
}

int messageExchange::getBytes_rcv_IS4_IS5() const
{
    return bytes_rcv_IS4_IS5;
}

void messageExchange::addErrorToIS1()
{
    std::cout << __FUNCTION__ << std::endl;
    IS1 = formingIMpvkp->createIS1WithError();
}

void messageExchange::addErrorToIS2(char number, output_cntrl cntrl)
{
    std::cout << __FUNCTION__ << std::endl;
    IS2 = formingIMpvkp->createIS2WithError(number, cntrl);
}
