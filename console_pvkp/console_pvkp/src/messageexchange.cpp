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

    int recv_bytes(-1);
    sendIS1(&IS1);
    do
    {
        recv_bytes = receiveIS3(&IS3);
    } while (recv_bytes > 0);
}

void messageExchange::sendIS1(_is1 *IS1)
{
    std::cout << IS1->header << std::endl;
    int bytes = dataTransnmit->send(IS1, sizeof(_is1));

    std::cout << "send " << bytes << " bytes; " << std::endl;
    printf("    header \t%02x\n", IS1->header);
    printf("    managed \t%02x\n", IS1->managed);
    printf("    cs \t%02x\n", IS1->cs);
}

int messageExchange::receiveIS3(_is3 *IS3)
{
    /// TODO 8 КАКИХ БАЙТ ПРИНЯТО??? КАКОЕ СЛОВО?
    bzero(IS3, sizeof (_is3));
    int bytes = dataTransnmit->receive(IS3, sizeof (_is3));

    std::cout << "receive " << bytes << " bytes; " << std::endl;
    printf("    header \t%02x\n", IS3->header);
    printf("    managed \t%02x\n", IS3->managed);
    printf("    word0 \t%02x\n", IS3->word0);
    printf("    word1 \t%02x\n", IS3->word1);
    printf("    word2 \t%02x\n", IS3->word2);
    printf("    word3 \t%02x\n", IS3->word3);
    printf("    word4 \t%02x\n", IS3->word4);
    printf("    word5 \t%02x\n", IS3->word5);
    printf("    word6 \t%02x\n", IS3->word6);
    printf("    word7 \t%02x\n", IS3->word7);
    printf("    word8 \t%02x\n", IS3->word8);
    printf("    word9 \t%02x\n", IS3->word9);
    printf("    word10 \t%02x\n", IS3->word10);
    printf("    word11 \t%02x\n", IS3->word11);
    printf("    word12 \t%02x\n", IS3->word12);
    printf("    word13 \t%02x\n", IS3->word13);
    printf("    word14 \t%02x\n", IS3->word14);
    printf("    word15 \t%02x\n", IS3->word15);
    printf("    word16 \t%02x\n", IS3->word16);
    printf("    word17 \t%02x\n", IS3->word17);
    printf("    word18 \t%02x\n", IS3->word18);
    printf("    word19 \t%02x\n", IS3->word19);
    printf("    word20 \t%02x\n", IS3->word20);
    printf("    word21 \t%02x\n", IS3->word21);
    printf("    word22 \t%02x\n", IS3->word22);
    printf("    word23 \t%02x\n", IS3->word23);
    printf("    word24 \t%02x\n", IS3->word24);
    printf("    word25 \t%02x\n", IS3->word25);
    printf("    word26 \t%02x\n", IS3->word26);
    printf("    word27 \t%02x\n", IS3->word27);
    printf("    word28 \t%02x\n", IS3->word28);
    printf("    word29 \t%02x\n", IS3->word29);
    printf("    word30 \t%02x\n", IS3->word30);
    printf("    cs \t%02x\n", IS3->cs);

    return bytes;
}

void messageExchange::sendIS2()
{
    // rs485->send(IM->getIS2());
}

void messageExchange::receiveIS4()
{
    // IM->setIS4(rs485->receive());
}
