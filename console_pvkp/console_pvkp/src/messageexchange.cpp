#include "hdr/messageexchange.h"

messageExchange::messageExchange()
{
    IM = new informationMessages();
    dataTransnmit = new DataTransmit();
    dataTransnmit->createServer();

    createIS1();
//    createIS2();

    bzero(&IS3, sizeof (_is3));
    std::cout << sizeof (_is3) << std::endl;

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
        recv_bytes = receiveIS3();
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

int messageExchange::receiveIS3()
{
    _is3 rcv_IS3;
    bzero(&rcv_IS3, sizeof (_is3));
    int bytes_rcv = dataTransnmit->receive(&rcv_IS3, sizeof (_rcv_data));
    std::cout << "receive " << bytes_rcv << " bytes; " << std::endl;

    static int bytes(0);
    bytes += bytes_rcv;

    if (bytes_rcv != 0)
    {
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
                bytes = 8;
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






//    bzero(IS3, sizeof (_is3));
//    int bytes = dataTransnmit->receive(IS3, sizeof (_is3));



//    IM->parsingIS3(IS3);

    return bytes_rcv;
}

void messageExchange::sendIS2()
{
    // rs485->send(IM->getIS2());
}

void messageExchange::receiveIS4()
{
    // IM->setIS4(rs485->receive());
}
