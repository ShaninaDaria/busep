#include "../../common/hdr/informationmessages.h"

unsigned char InformationMessages::calculateCRC(void *p, int bytes)
{
//    qDebug() << __FUNCTION__ << "; p" << p << "; bytes" << bytes;
    unsigned char crc = 0x00;
    unsigned char *array = (unsigned char *)p;
    while (bytes--)
    {
        crc = CRC8table[crc ^ *array++];
    }
    return crc;
}

bool InformationMessages::checkCRC(void *p, int bytes, unsigned char crc)
{
//    qDebug() << __FUNCTION__ << "; p" << p << "; bytes" << bytes << "; crc" << crc;
    unsigned char crc_check = calculateCRC(p, bytes);
    qDebug() << "crc_check" << crc_check;
    return (crc_check == crc);
}
