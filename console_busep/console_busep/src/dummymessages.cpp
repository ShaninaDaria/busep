#include "hdr/dummymessages.h"

// ----------------------------------------------------------

DummyMessages::DummyMessages(QObject *parent) : QObject(parent)
{
    formingIM_busep = new FormingIM_busep();
    dataTransnmit = new DataTransmit();
    /// TODO переподключение, если ПВКП отвалился
    dataTransnmit->createServer();

    createIS3(is_signal_27v);
//    createIS3(no_signal_27v);
//    createIS4(0x00, output_off);
}

// ----------------------------------------------------------

DummyMessages::~DummyMessages()
{
    dataTransnmit->endTransmitServer();
    delete formingIM_busep;
}

// ----------------------------------------------------------

void DummyMessages::createIS3(input_state state)
{
    IS3 = formingIM_busep->createIS3(state);
}

// ----------------------------------------------------------

void DummyMessages::createIS4(char device_number, unsigned char cnrtl, bool add_error, bool no_state)
{
    std::cout << __FUNCTION__ << std::endl;

    IS4 = formingIM_busep->createIS4(device_number, cnrtl, add_error, no_state);
}

// ----------------------------------------------------------

void DummyMessages::createIS5()
{
    std::cout << __FUNCTION__ << std::endl;
    IS5 = formingIM_busep->createIS5();
}

// ----------------------------------------------------------

void DummyMessages::startExchange(bool add_error, bool no_state)
{
//    int recv_bytes(-1);
    header_and_managed code(empty);
//    std::cout << __FUNCTION__ << " waiting for message... ";
//    while (1)
//    {
        do
        {
            code = receiveSmth();

            switch (code)
            {
            case request:
            {
                sendIS3(IS3);
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
                sendIS4(IS4);
                emit signalUsualExchange();
            }
                break;
            case error:
            {
                sendIS5(IS5);
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

header_and_managed DummyMessages::receiveSmth()
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

//    int bytes = dataTransnmit->receive(&data, sizeof (_data));
    int bytes = dataTransnmit->srvReceive(&data, sizeof (_data));
    if (bytes > 0)
    {
        qDebug() << "receive " << bytes << " bytes;";

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

                if (formingIM_busep->parseIS1(&IS1))
                {
                    code = request;
                }
            }
                break;

            case change_state:
            {
                bzero(&IS2, sizeof (_is2));

                IS2.header = data.header;
                IS2.managed = data.managed;
                IS2.device_number = data.byte0;
                IS2.state = data.byte1;
                IS2.crc = data.crc;

                if (formingIM_busep->parseIS2(&IS2))
                {
                    code = change_state;
                }
            }
                break;

            default:
                code = error;
                break;
            }

        }
        else
        {
            code = error;
        }

    }

    return code;
}

// ----------------------------------------------------------

void DummyMessages::sendIS3(_is3 *IS3)
{


//    int bytes = dataTransnmit->send(IS3, sizeof(_is3));
    int bytes = dataTransnmit->srvSend(IS3, sizeof(_is3));

    if (bytes > 0)
    {
        qDebug() << __FUNCTION__ << " send " << bytes << " bytes; ";
    }
}

// ----------------------------------------------------------

void DummyMessages::sendIS4(_is4 *IS4)
{
    std::cout << __FUNCTION__ << std::endl;

//    int bytes = dataTransnmit->send(IS4, sizeof(_is4));
    int bytes = dataTransnmit->srvSend(IS4, sizeof(_is4));

    if (bytes > 0)
    {
        std::cout << "send " << bytes << " bytes; " << std::endl;
    }
}

// ----------------------------------------------------------

void DummyMessages::sendIS5(_is5 *IS5)
{
    std::cout << __FUNCTION__ << std::endl;

    createIS5();

//    int bytes = dataTransnmit->send(IS5, sizeof(_is5));
    int bytes = dataTransnmit->srvSend(IS5, sizeof(_is5));

    if (bytes > 0)
    {
        std::cout << "send " << bytes << " bytes; " << std::endl;
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

