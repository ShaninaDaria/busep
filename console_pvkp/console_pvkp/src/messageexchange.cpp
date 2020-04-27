#include <signal.h>
//#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>
#include "hdr/messageexchange.h"

void messageExchange::timer_handler(int signum)
{

    static int count = 0;

//    printf("timer expired %d times ", ++count);

    qDebug() << "one timer expired" << ++count << "times ";

}

_inputs &messageExchange::getInputsValue()
{
    return IM->getInputs();
}

_outputs &messageExchange::getOutputsValue()
{
    return IM->getOutputs();
}

messageExchange::messageExchange(QObject *parent) : QObject(parent)
{
    IM = new informationMessages();
    dataTransnmit = new DataTransmit();

    createIS1();
    /// NOTE по умолчанию шлю ИС2 с запросом "включить все выходы"
    createIS2(all_outputs, cntrl_on);

    bzero(&IS3, sizeof(_is3));
    bzero(&IS4, sizeof(_is4));

//    createTimer();

}

messageExchange::~messageExchange()
{
    dataTransnmit->endTransmitClient();
    delete dataTransnmit;
    delete IM;
}

void messageExchange::initTransmit()
{
    dataTransnmit->createClient();
}


void messageExchange::createIS1()
{
    std::cout << __FUNCTION__ << std::endl;
    IS1 = IM->createIS1();
}

void messageExchange::createIS2(char number, output_cntrl cntrl)
{
    printf("%s number %02x\n", __FUNCTION__, number);
    IS2 = IM->createIS2(number, cntrl);
}

void messageExchange::startExchange()
{
//    while (1)
//    {
        int bytes_send(-1), bytes_rcv(-1);

        bytes_send = sendIS1(&IS1);
        if (bytes_send > 0)
        {
            do
            {
                bytes_rcv = receiveIS3();
            } while (bytes_rcv > 0);
        }

        bytes_rcv = -1;
        bytes_send = sendIS2(&IS2);
        if (bytes_send > 0)
        {
            do
            {
                bytes_rcv = receiveIS4();
            } while (bytes_rcv > 0);
        }
//    }

}

int messageExchange::sendIS1(_is1 *IS1)
{
//    int bytes_send = dataTransnmit->send(IS1, sizeof(_is1));
    int bytes_send = dataTransnmit->clntSend(IS1, sizeof(_is1));

    if (bytes_send > 0)
    {
        std::cout << "send " << bytes_send << " bytes; " << std::endl;
        std::cout << __FUNCTION__ << std::endl;
        printf("    header \t%02x\n", IS1->header);
        printf("    managed \t%02x\n", IS1->managed);
        printf("    cs \t%02x\n", IS1->cs);
    }
    return bytes_send;
}

int messageExchange::receiveIS3()
{
    std::cout << __FUNCTION__ << std::endl;

    _is3 rcv_IS3;
    bzero(&rcv_IS3, sizeof (_is3));
//    int bytes_rcv = dataTransnmit->receive(&rcv_IS3, sizeof (_rcv_data));
//    int bytes_rcv = dataTransnmit->clntReceive(&rcv_IS3, sizeof (_rcv_data));
    int bytes_rcv = dataTransnmit->clntReceive(&rcv_IS3, sizeof (_is3));
    std::cout << "receive " << bytes_rcv << " bytes; " << std::endl;
    if (bytes_rcv > 0)
    {
        static int bytes(0);
        bytes += bytes_rcv;

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
                switch (bytes)
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
                    IS3.cs = rcv_IS3.managed;
                }
                    break;
                }
            }

            if (bytes == sizeof(_is3))
            {
                bytes = 0;
                IM->parsingIS3(IS3);
            }
        }
        else
        {
            if (bytes_rcv == sizeof(_is3))
            {
                IS3 = rcv_IS3;
                IM->parsingIS3(IS3);
            }
        }
    }

    return bytes_rcv;
}

int messageExchange::sendIS2(_is2 *IS2)
{
    std::cout << __FUNCTION__ << std::endl;

//    int bytes_send = dataTransnmit->send(IS2, sizeof(_is2));
    int bytes_send = dataTransnmit->clntSend(IS2, sizeof(_is2));

    if (bytes_send > 0)
    {
        std::cout << "send " << bytes_send << " bytes; " << std::endl;
        printf("       header \t%02x\n", IS2->header);
        printf("      managed \t%02x\n", IS2->managed);
        printf("device_number \t%02x\n", IS2->device_number);
        printf("        state \t%02x\n", IS2->state);
        printf("           cs \t%02x\n", IS2->cs);
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
    std::cout << "receive " << bytes_rcv << " bytes; " << std::endl;

    static int bytes(0);
    bytes += bytes_rcv;

    if (bytes_rcv > 0)
    {
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
                    IS4.cs = rcv_IS4.state00;
                }
                    break;
                }
            }

            if (bytes == sizeof(_is4))
            {
                bytes = 0;
                IM->parsingIS4(IS4);
            }
        }
        else
        {
            if (bytes_rcv == sizeof(_is4))
            {
                IS4 = rcv_IS4;
                IM->parsingIS4(IS4);
            }
        }
    }

    return bytes_rcv;
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

