#include "hdr/dummymessages.h"

// ----------------------------------------------------------

DummyMessages::DummyMessages()
{
    formingIM_busep = new FormingIM_busep();
    dataTransnmit = new DataTransmit();
    /// TODO переподключение, если ПВКП отвалился
    dataTransnmit->createServer();

    createIS3(no_input_state);
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

void DummyMessages::createIS4(char device_number, unsigned char cnrtl)
{
    std::cout << __FUNCTION__ << std::endl;

    IS4 = formingIM_busep->createIS4(device_number, cnrtl);
}

// ----------------------------------------------------------

void DummyMessages::createIS5()
{
    std::cout << __FUNCTION__ << std::endl;
    IS5 = formingIM_busep->createIS5();
}

// ----------------------------------------------------------

void DummyMessages::startExchange()
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
                sendIS3(IS3);
                break;
            case change_state:
                sendIS4(IS4);
                break;
            case error:
                sendIS5(IS5);
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
    bzero(&data, sizeof (_data));

    header_and_managed code(empty);

//    int bytes = dataTransnmit->receive(&data, sizeof (_data));
    int bytes = dataTransnmit->srvReceive(&data, sizeof (_data));
    if (bytes > 0)
    {
        std::cout << "receive " << bytes << " bytes; " << std::endl;

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

        default:
            code = error;
            break;
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
        std::cout << __FUNCTION__ << " send " << bytes << " bytes; " << std::endl;
    }
}

// ----------------------------------------------------------

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

