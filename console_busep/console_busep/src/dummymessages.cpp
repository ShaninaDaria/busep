#include "hdr/dummymessages.h"

DummyMessages::DummyMessages()
{
    formingIM_busep = new FormingIM_busep();
    dataTransnmit = new DataTransmit();
    dataTransnmit->createServer();

    createIS3(no_input_state);
}

DummyMessages::~DummyMessages()
{
    dataTransnmit->endTransmitServer();
    delete formingIM_busep;
}

void DummyMessages::startExchange()
{
//    int recv_bytes(-1);
    header_and_managed code(empty);
//    while (1)
//    {
        do
        {
        /*
                recv_bytes = receiveIS1();
                if (recv_bytes > 0)
                {
                    sendIS3(IS3);
                }
        */

            code = receiveSmth();

            switch (code)
            {
            case request:
                sendIS3(IS3);
                break;
            case change_state:
                sendIS4(IS4);
                break;
            default:
                break;
            }

        } while (code != empty) /*(recv_bytes > 0)*/;

//    }
/*
    recv_bytes = -1;
    do
    {
        recv_bytes = receiveIS2();
        if (recv_bytes > 0)
        {
            sendIS4(IS4);
        }
    } while (recv_bytes > 0);
*/
}

void DummyMessages::setInputsValue()
{

}

void DummyMessages::createIS3(input_state state)
{
    std::cout << __FUNCTION__ << " " << state << std::endl;
    IS3 = formingIM_busep->createIS3(state);
}
/*
int dummyMessages::receiveIS1()
{
    std::cout << __FUNCTION__ << std::endl;

    bzero(&IS1, sizeof (_is1));
    int bytes = dataTransnmit->receive(&IS1, sizeof (_is1));

    std::cout << "receive " << bytes << " bytes; " << std::endl;
    if (bytes > 0)
    {
        printf("    header \t%02x\n", IS1.header);
        printf("    managed \t%02x\n", IS1.managed);
        printf("    cs \t%02x\n", IS1.cs);
    }

    return bytes;
}
*/
void DummyMessages::sendIS3(_is3 *IS3)
{
    std::cout << __FUNCTION__ << std::endl;

//    int bytes = dataTransnmit->send(IS3, sizeof(_is3));
    int bytes = dataTransnmit->srvSend(IS3, sizeof(_is3));

    if (bytes > 0)
    {
        std::cout << "send " << bytes << " bytes; " << std::endl;
    }
}

void DummyMessages::createIS4(char device_number, unsigned char cnrtl)
{
    std::cout << __FUNCTION__ << std::endl;

    IS4 = formingIM_busep->createIS4(device_number, cnrtl);
}
/*
int dummyMessages::receiveIS2()
{
    std::cout << __FUNCTION__ << std::endl;

    bzero(&IS2, sizeof (_is2));
    int bytes = dataTransnmit->receive(&IS1, sizeof (_is2));

    std::cout << "receive " << bytes << " bytes; " << std::endl;
    if (bytes > 0)
    {
        printf("    header \t%02x\n", IS2.header);
        printf("    managed \t%02x\n", IS2.managed);
        printf("    device_number \t%02x\n", IS2.device_number);
        printf("    state \t%02x\n", IS2.state);
        printf("    cs \t%02x\n", IS1.cs);
    }

    return bytes;
}
*/
void DummyMessages::sendIS4(_is4 *IS4)
{
    std::cout << __FUNCTION__ << std::endl;

    createIS4(IS2.device_number, IS2.state);

//    int bytes = dataTransnmit->send(IS4, sizeof(_is4));
    int bytes = dataTransnmit->srvSend(IS4, sizeof(_is4));

    if (bytes > 0)
    {
        std::cout << "send " << bytes << " bytes; " << std::endl;
    }
}

_inputs DummyMessages::getInputs() const
{
    return formingIM_busep->getInputs();
}

_outputs DummyMessages::getOutputs() const
{
    return formingIM_busep->getOutputs();
}

header_and_managed DummyMessages::receiveSmth()
{
    std::cout << __FUNCTION__ << " waiting for message... " << std::endl;


    struct _data
    {
        unsigned char header:8;
        unsigned char managed:8;
        unsigned char byte0:8;
        unsigned char byte1:8;
        unsigned char cs:8;
    } data;
    bzero(&data, sizeof (_data));

    header_and_managed code(empty);

//    int bytes = dataTransnmit->receive(&data, sizeof (_data));
    int bytes = dataTransnmit->srvReceive(&data, sizeof (_data));
    if (bytes > 0)
    {
        std::cout << "receive " << bytes << " bytes; " << std::endl;
    }

    if (bytes > 0)
    {
        switch (data.managed)
        {
        case request:
        {
            bzero(&IS1, sizeof (_is1));
            /// TODO checkCS!

            code = request;

            IS1.header = data.header;
            IS1.managed = data.managed;
            IS1.cs = data.cs;

            printf("    header \t%02x\n", IS1.header);
            printf("    managed \t%02x\n", IS1.managed);
            printf("    cs \t%02x\n", IS1.cs);
        }
            break;

        case change_state:
        {
            bzero(&IS2, sizeof (_is2));
            /// TODO checkCS!

            code = change_state;

            IS2.header = data.header;
            IS2.managed = data.managed;
            IS2.device_number = data.byte0;
            IS2.state = data.byte1;
            IS2.cs = data.cs;

            printf("       header \t%02x\n", IS2.header);
            printf("      managed \t%02x\n", IS2.managed);
            printf("device_number \t%02x\n", IS2.device_number);
            printf("        state \t%02x\n", IS2.state);
            printf("           cs \t%02x\n", IS1.cs);
        }
            break;
        }
    }

    return code;
}
