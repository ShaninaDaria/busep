#include <QCoreApplication>
#include "hdr/dummymessages.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    dummyMessages dm;

//    dm.startExchange();

    exit(0);

/*
    union Register32
    {
        struct
        {
            unsigned char byte1;
            unsigned char byte2;
            unsigned char byte3;
            unsigned char byte4;
        } bytes;
        struct
        {
            unsigned short low;
            unsigned short high;
        } words;
        unsigned dword;
    };

    typedef union Register32 EAX;

    EAX reg;
    reg.dword = 0x0011C0FF;
    printf("    dword \t%08x\n", reg.dword);
    printf(" low word \t%04x\n", reg.words.low);    // c0ff
    printf("high word \t%04x\n", reg.words.high);   // 0011
    printf("    byte1 \t%02x\n", reg.bytes.byte1);  // ff
    printf("    byte2 \t%02x\n", reg.bytes.byte2);  // c0
    printf("    byte3 \t%02x\n", reg.bytes.byte3);  // 11
    printf("    byte4 \t%02x\n", reg.bytes.byte4);  // 00
*/


    return a.exec();
}
