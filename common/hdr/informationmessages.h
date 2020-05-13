#ifndef INFORMATIONMESSAGES_H
#define INFORMATIONMESSAGES_H

#include <QDebug>
#include "inputs_outputs.h"

// ИС1
struct _is1
{
    unsigned char header:8;
    unsigned char managed:8;
    unsigned char crc:8;
};

// ИС2
struct _is2
{
    unsigned char header:8;
    unsigned char managed:8;
    unsigned char device_number:8;
    unsigned char state:8;
    unsigned char crc:8;
};

// ИС3
struct _is3
{
    unsigned char header:8;
    unsigned char managed:8;
    unsigned char word00:8;
    unsigned char word01:8;
    unsigned char word02:8;
    unsigned char word03:8;
    unsigned char word04:8;
    unsigned char word05:8;
    unsigned char word06:8;
    unsigned char word07:8;
    unsigned char word08:8;
    unsigned char word09:8;
    unsigned char word10:8;
    unsigned char word11:8;
    unsigned char word12:8;
    unsigned char word13:8;
    unsigned char word14:8;
    unsigned char word15:8;
    unsigned char word16:8;
    unsigned char word17:8;
    unsigned char word18:8;
    unsigned char word19:8;
    unsigned char word20:8;
    unsigned char word21:8;
    unsigned char word22:8;
    unsigned char word23:8;
    unsigned char word24:8;
    unsigned char word25:8;
    unsigned char word26:8;
    unsigned char word27:8;
    unsigned char word28:8;
    unsigned char word29:8;
    unsigned char word30:8;
    unsigned char crc:8;
};

// ИС4
struct _is4
{
    unsigned char header:8;
    unsigned char managed:8;
    unsigned char state00:8;
    unsigned char state01:8;
    unsigned char state02:8;
    unsigned char state03:8;
    unsigned char state04:8;
    unsigned char state05:8;
    unsigned char state06:8;
    unsigned char state07:8;
    unsigned char state08:8;
    unsigned char state09:8;
    unsigned char state10:8;
    unsigned char state11:8;
    unsigned char state12:8;
    unsigned char state13:8;
    unsigned char state14:8;
    unsigned char state15:8;
    unsigned char crc:8;
};

// ИС5
struct _is5
{
    unsigned char header:8;
    unsigned char managed:8;
    unsigned char crc:8;
};

// для приема данных
struct _rcv_data
{
    unsigned char byte0:8;
    unsigned char byte1:8;
    unsigned char byte2:8;
    unsigned char byte3:8;
};

enum header_and_managed
{
    empty = 0x00,               // для меня - инициализация
    error = 0x55,               // для меня - на случай ошибки
    header = 0xff,              // заголовок
    request = 0x01,             // ИС1
    change_state = 0x02,        // ИС2
    response_change = 0x03,     // ИС4
    integrity_violation = 0x09, // ИС5
    response_state = 0x10       // ИС3
};


const unsigned char CRC8table[256] =
{
    0, 94, 188, 226, 97, 63, 221, 131,
    194, 156, 126, 32, 163, 253, 31, 65,
    157, 195, 33, 127, 252, 162, 64, 30,
    95, 1, 227, 189, 62, 96, 130, 220,
    35, 125, 159, 193, 66, 28, 254, 160,
    225, 191, 93, 3,128, 222, 60, 98,
    190, 224, 2, 92, 223, 129, 99, 61,
    124, 34, 192,158, 29, 67, 161, 255,
    70, 24, 250, 164, 39, 121,155, 197,
    132, 218, 56, 102, 229, 187, 89, 7,
    219, 133, 103, 57, 186, 228,  6, 88,
    25, 71, 165, 251, 120, 38, 196,154,
    101, 59, 217, 135, 4, 90, 184, 230,
    167, 249, 27, 69, 198, 152, 122, 36,
    248, 166, 68, 26, 153, 199, 37, 123,
    58, 100, 134, 216, 91, 5, 231, 185,
    140, 210, 48, 110, 237, 179, 81, 15,
    78, 16, 242, 172, 47, 113, 147, 205,
    17, 79, 173, 243, 112, 46, 204, 146,
    211, 141, 111, 49, 178, 236, 14, 80,
    175,241, 19, 77,206,144,114, 44,
    109, 51, 209, 143, 12, 82, 176, 238,
    50, 108, 142, 208, 83, 13, 239, 177,
    240, 174, 76, 18, 145, 207, 45, 115,
    202, 148, 118, 40, 171, 245, 23, 73,
    8, 86, 180, 234, 105, 55, 213, 139,
    87, 9, 235, 181, 54, 104, 138, 212,
    149, 203, 41, 119, 244, 170, 72, 22,
    233, 183, 85, 11, 136, 214, 52, 106,
    43, 117, 151, 201, 74, 20, 246, 168,
    116, 42, 200, 150, 21, 75, 169, 247,
    182, 232, 10, 84, 215, 137, 107, 53
};


class InformationMessages
{
public:
    InformationMessages() {}
    ~InformationMessages() {}
//    _is1 createIS1();
//    _is2 createIS2(char device_number, output_cntrl cntrl);
//    _is3 *createIS3();
//    _is4 *createIS4(char device_number, unsigned char cnrtl);
//    void createIS5();
    char calculateCRC(void *p, int bytes);
    bool checkCRC(void *p, int bytes, unsigned char crc);

//    _is1 getIS1() const;

//    _is2 getIS2() const;

//    void setIS3(const _is3 &IS3);

//    void setIS4(const _is4 &value);

//    void parsingIS3(_is3 &IS3);
//    void parsingIS4(_is4 &IS4);

//    _inputs &getInputs();

//    _outputs &getOutputs();

//private:
//    unsigned getInputState(unsigned char word);
//    void printInputState(const unsigned &input);

//    unsigned getOutputState(unsigned char state);
//    void printOutputState(const unsigned &output);

//    _is1 IS1;
//    _is2 IS2;
//    _is3 IS3;
//    _is4 IS4;
//    _is5 IS5;
//    _rcv_data rcv;


//    InputsOutputs io;
//    _inputs inputs;
//    _outputs outputs;
};

#endif // INFORMATIONMESSAGES_H
