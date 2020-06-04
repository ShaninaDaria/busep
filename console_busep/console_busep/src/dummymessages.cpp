#include "hdr/dummymessages.h"

// ----------------------------------------------------------

DummyMessages::DummyMessages(QObject *parent) : QObject(parent)
{
    formingIM_busep = new FormingIM_busep();
//    thread = new QThread(this);
    dataTransnmit = new DataTransmit();

//    dataTransnmit->moveToThread(thread);
//    connect(thread, SIGNAL(finished()), dataTransnmit, SLOT(deleteLater()));
//    thread->start();


//    dataTransnmit->createServer();

    // по умолчанию все входы выключены
    createIS3(all_inputs, no_signal_27v);
}

// ----------------------------------------------------------

DummyMessages::~DummyMessages()
{
//    dataTransnmit->endTransmitServer();
    dataTransnmit->closeSerialPort();
    delete dataTransnmit;
//    delete thread;
    delete formingIM_busep;
}

// ----------------------------------------------------------

bool DummyMessages::openSerialPort(QString port_name, int baud_rate)
{
    return dataTransnmit->openSerialPort(port_name, baud_rate);
}

// ----------------------------------------------------------

void DummyMessages::createIS3(int device_number, input_state state)
{
    IS3 = formingIM_busep->createIS3(device_number, state);
}

// ----------------------------------------------------------

void DummyMessages::createIS4(unsigned char device_number, unsigned char cnrtl, bool add_error, bool no_state)
{
    IS4 = formingIM_busep->createIS4(device_number, cnrtl, add_error, no_state);
}

// ----------------------------------------------------------

void DummyMessages::createIS5()
{
    IS5 = formingIM_busep->createIS5();
}

// ----------------------------------------------------------

void DummyMessages::startExchange(bool add_error, bool no_state, int wait_ms)
{
    static bool start = true;
//    int recv_bytes(-1);
    header_and_managed code(empty);
//    std::cout << __FUNCTION__ << " waiting for message... ";
//    while (1)
//    {
        do
        {
            code = receiveSmth(wait_ms);
//            qDebug() << "receive code" << code;

            switch (code)
            {
            case request:
            {
                if (start)
                {
                    qDebug() << "HANGUP";
                    start = false;
                }
                sendIS3();
                emit signalUsualExchange();
            }
                break;

            case change_state:
            {
                if (!add_error && !no_state)
                {
                    createIS4(IS2.device_number, IS2.state);
                }
                else
                {
                    createIS4(IS2.device_number, IS2.state, add_error, no_state);
                }
                sendIS4();
                emit signalUsualExchange();
            }
                break;

            case error:
            {
                sendIS5();
                emit signalSendIS5();
            }
                break;

            default:
                break;
            }

        } while (code != empty) /*(recv_bytes > 0)*/;

//    }

}

// ----------------------------------------------------------

header_and_managed DummyMessages::receiveSmth(int wait_ms)
{
    struct _data
    {
        unsigned char header:8;
        unsigned char managed:8;
        unsigned char byte0:8;
        unsigned char byte1:8;
        unsigned char crc:8;
    } data;
    bzero(&data, sizeof (_data));

    header_and_managed code(empty);

    static bool start = true;

    qint64 bytes = dataTransnmit->receive(&data, sizeof (_data), wait_ms);
//    int bytes = dataTransnmit->srvReceive(&data, sizeof (_data));
    if (bytes > 0)
    {
        if (data.header == header)
        {
            switch (data.managed)
            {
            case request:
            {
                bzero(&IS1, sizeof (_is1));

                IS1.header = data.header;
                IS1.managed = data.managed;
                IS1.crc = data.byte0;

                if (formingIM_busep->parsingIS1(&IS1))
                {
                    code = request;

                    if  (start) start = false;
                }
            }
                break;

            case change_state:
            {
                // надо допринять остатки
                if (start)
                {
                    while (bytes > 0)
                    {
                        bytes = dataTransnmit->receive(&data, sizeof (_data), wait_ms);
                    }
                }
                else
                {
                    bzero(&IS2, sizeof (_is2));

                    IS2.header = data.header;
                    IS2.managed = data.managed;
                    IS2.device_number = data.byte0;
                    IS2.state = data.byte1;
                    IS2.crc = data.crc;

                    if (formingIM_busep->parsingIS2(&IS2))
                    {
                        code = change_state;
                    }
                }

            }
                break;

            default:
            {
                qDebug() << " header" << data.header;
                qDebug() << "managed" << data.managed;
                qDebug() << "  byte0" << data.byte0;
                qDebug() <<   "byte1" << data.byte1;
                qDebug() << "    crc" << data.crc;
                qDebug() << "Unknown managed byte " << data.managed << "! Send ERROR";
                code = error;
            }
                break;
            }

        }
        /// FIXME а если заголовок - не заголовок? что за 1 или 3 байта я принимаю?
        else
        {
            code = error;
        }

    }

    return code;
}

// ----------------------------------------------------------

void DummyMessages::sendIS3()
{
    qint64 bytes = dataTransnmit->send(IS3, sizeof(_is3), wait10ms);
//    int bytes = dataTransnmit->srvSend(IS3, sizeof(_is3));

    if (bytes > 0)
    {
//        qDebug() << __FUNCTION__ << " send " << bytes << " bytes;\n";
    }
}

// ----------------------------------------------------------

void DummyMessages::sendIS4()
{
    qint64 bytes = dataTransnmit->send(IS4, sizeof(_is4), wait100ms);
//    int bytes = dataTransnmit->srvSend(IS4, sizeof(_is4));

    if (bytes > 0)
    {
        qDebug() << __FUNCTION__ << " send " << bytes << " bytes;\n";
    }
}

// ----------------------------------------------------------

void DummyMessages::sendIS5()
{
    createIS5();

    /// NOTE IS2_IS4_wait
    qint64 bytes = dataTransnmit->send(IS5, sizeof(_is5), wait100ms);
//    int bytes = dataTransnmit->srvSend(IS5, sizeof(_is5));

    if (bytes > 0)
    {
        qDebug() << __FUNCTION__ << " send " << bytes << " bytes;";
    }
}

// ----------------------------------------------------------

char *DummyMessages::getInputs()
{
    return formingIM_busep->getInputs();
}

// ----------------------------------------------------------

char *DummyMessages::getOutputs()
{
    return formingIM_busep->getOutputs();
}

// ----------------------------------------------------------

output_state DummyMessages::getOutputState(int number)
{
    return formingIM_busep->getOutputState(number);
}

// ----------------------------------------------------------

input_state DummyMessages::getInputState(int number)
{
    return formingIM_busep->getInputState(number);
}

// ----------------------------------------------------------

