#include "hdr/messageexchange.h"

messageExchange::messageExchange()
{
    IM = new informationMessages();
    dataTransnmit = new DataTransmit();
    dataTransnmit->createServer();

    createIS1();
//    createIS2();
}

messageExchange::~messageExchange()
{
    delete dataTransnmit;
    delete IM;
}


void messageExchange::createIS1()
{
    IS1 = IM->createIS1();
    std::cout << __FUNCTION__ << " " << IS1.header << " " << IS1.managed << std::endl;
}

void messageExchange::createIS2()
{
    char number = 0x18;
    IM->createIS2(number);
}

int messageExchange::sendText()
{
//    char data[100];
//    strcpy(data, "Hello");

//    int data = 5;
//    data = htonl(data);

//    bytes reg;
//    reg.dword = 0x0011C0FF;
//    reg.byte1 = 0xff;  // ff
//    reg.byte2 = 0xc0;  // c0
//    reg.byte3 = 0x11;  // 11
//    reg.byte4 = 0x00;  // 00
//    printf("    dword \t%08x\n", reg.dword);
//    printf("    byte1 \t%02x\n", reg.byte1);  // ff
//    printf("    byte2 \t%02x\n", reg.byte2);  // c0
//    printf("    byte3 \t%02x\n", reg.byte3);  // 11
//    printf("    byte4 \t%02x\n", reg.byte4);  // 00
//    int bytes = dataTransnmit->send(&reg, sizeof (reg));

    IS1.header = 0xff;
    IS1.managed = 0x01;
    IS1.cs = 0x05;

    printf("    byte1 \t%02x\n", IS1.header);  // ff
    printf("    byte2 \t%02x\n", IS1.managed);  // c0
    printf("    byte3 \t%02x\n", IS1.cs);  // 11

    int bytes = dataTransnmit->send(&IS1, sizeof (_is1));
    std::cout << "send " << bytes << " bytes; " << std::endl;

    return bytes;
}

void messageExchange::startExchange()
{
//    sendText();
    sendIS1(&IS1);
//    while (1)
//    {
//        receiveIS3(IS3);
//    }
}

void messageExchange::sendIS1(_is1 *IS1)
{
    std::cout << IS1->header << std::endl;
    int bytes = dataTransnmit->send(IS1, sizeof(_is1));

    std::cout << "send " << bytes << " bytes; " << std::endl;
    printf("    header \t%02x\n", IS1->header);  // ff
    printf("    managed \t%02x\n", IS1->managed);  // c0
    printf("    cs \t%02x\n", IS1->cs);  // 11
}

void messageExchange::receiveIS3(_is3 *IS3)
{
    int bytes = dataTransnmit->receive(IS3, sizeof (_is3));

    std::cout << "receive " << bytes << " bytes; " << IS3->managed << std::endl;
}

void messageExchange::sendIS2()
{
    // rs485->send(IM->getIS2());
}

void messageExchange::receiveIS4()
{
    // IM->setIS4(rs485->receive());
}
