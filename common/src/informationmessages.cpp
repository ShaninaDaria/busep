#include "../../common/hdr/informationmessages.h"

//----------------------------------------------------------

unsigned char InformationMessages::calculateCRC(void *p, int bytes)
{
    unsigned char crc = 0x00;
    unsigned char *array = static_cast<unsigned char *>(p);
    while (bytes--)
    {
        crc = CRC8table[crc ^ *array++];
    }
    return crc;
}

//----------------------------------------------------------

bool InformationMessages::checkCRC(void *p, int bytes, unsigned char crc)
{
    unsigned char crc_check = calculateCRC(p, bytes);
    return (crc_check == crc);
}

//----------------------------------------------------------
