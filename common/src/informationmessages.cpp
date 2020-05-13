#include "../../common/hdr/informationmessages.h"

char InformationMessages::calculateCRC(void *p, int bytes)
{
    char crc = 0xff;
    char *array = (char *)p;
    bytes--;
    while (bytes--)
    {
        crc = CRC8table[crc ^ *array++];
    }
    return crc;
}

bool InformationMessages::checkCRC(void *p, int bytes, unsigned char crc)
{
    char crc_check = calculateCRC(p, bytes);
    return (crc_check == crc);
}
