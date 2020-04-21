#include "hdr/dummymessages.h"

dummyMessages::dummyMessages()
{
    IM = new informationMessages();
    dataTransnmit = new DataTransmit();
    dataTransnmit->createClient();

    createIS3();
//    createIS4();
}

dummyMessages::~dummyMessages()
{
    delete  IM;
}

void dummyMessages::startExchange()
{
//    while (1)
    int recv_bytes(-1);
    do
    {
//        recv_bytes = receiveText();
        recv_bytes = receiveIS1();
        if (recv_bytes > 0)
        {
            sendIS3(IS3);
        }
    } while (recv_bytes > 0);
}

void dummyMessages::setInputsValue()
{

}

void dummyMessages::createIS3()
{
    IS3 = IM->createIS3();
}

int dummyMessages::receiveIS1()
{
    bzero(&IS1, sizeof (_is1));
    int bytes = dataTransnmit->receive(&IS1, sizeof (_is1));

    std::cout << "receive " << bytes << " bytes; " << std::endl;
    if (bytes > 0)
    {
        printf("    header \t%02x\n", IS1.header);  // ff
        printf("    managed \t%02x\n", IS1.managed);  // c0
        printf("    cs \t%02x\n", IS1.cs);  // 11
    }

    return bytes;
}

void dummyMessages::sendIS3(_is3 *IS3)
{
    int bytes = dataTransnmit->send(IS3, sizeof(_is3));

    std::cout << "send " << bytes << " bytes; " << IS3->managed << std::endl;
}

void dummyMessages::createIS4()
{
    IM->createIS4();
}

int dummyMessages::receiveText()
{
//    char data[100];
//    bzero(data, '0');
//    int data = -1;
//    bytes reg;
//    int bytes = dataTransnmit->receive(&reg, sizeof(reg));
//    data = ntohl(data);
//    printf("    dword \t%08x\n", reg.dword);
//    printf("    byte1 \t%02x\n", reg.byte1);  // ff
//    printf("    byte2 \t%02x\n", reg.byte2);  // c0
//    printf("    byte3 \t%02x\n", reg.byte3);  // 11
//    printf("    byte4 \t%02x\n", reg.byte4);  // 00

    int bytes = dataTransnmit->receive(&IS1, sizeof(_is1));
//    data = ntohl(data);
//    printf("    dword \t%08x\n", reg.dword);
    printf("    byte1 \t%02x\n", IS1.header);  // ff
    printf("    byte2 \t%02x\n", IS1.managed);  // c0
    printf("    byte3 \t%02x\n", IS1.cs);  // 11

    std::cout << "receive " << bytes << " bytes; " << std::endl;

    return bytes;
}
