#ifndef INFORMATIONMESSAGES_H
#define INFORMATIONMESSAGES_H

#include <QDebug>
#include "inputs_outputs.h"

//union Register32
//{
    struct bytes
    {
        unsigned char byte1:8;
        unsigned char byte2:8;
        unsigned char byte3:8;
//        unsigned char byte4:8;
    } ;
//    struct
//    {
//        unsigned short low;
//        unsigned short high;
//    } words;
//    unsigned dword;
//};

//typedef union Register32 EAX;

// ИС1
struct _is1
{
    unsigned char header:8;
    unsigned char managed:8;
    unsigned char cs:8;
};

// ИС2
struct _is2
{
    unsigned char header:8;
    unsigned char managed:8;
    unsigned char device_number:8;
    unsigned char state:8;
    unsigned char cs:8;
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
    unsigned char cs:8;
};

// ИС4
struct _is4
{
    unsigned char header:8;
    unsigned char managed:8;
    unsigned char state0:8;
    unsigned char state1:8;
    unsigned char state2:8;
    unsigned char state3:8;
    unsigned char state4:8;
    unsigned char state5:8;
    unsigned char state6:8;
    unsigned char state7:8;
    unsigned char state8:8;
    unsigned char state9:8;
    unsigned char state10:8;
    unsigned char state11:8;
    unsigned char state12:8;
    unsigned char state13:8;
    unsigned char state14:8;
    unsigned char state15:8;
    unsigned char cs:8;
};

// ИС5
struct _is5
{
    unsigned char header:8;
    unsigned char managed:8;
    unsigned char cs:8;
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
    header = 0xff,
    request = 0x01,
    change_state = 0x02,
    response_change = 0x03,
    integrity_violation = 0x09,
    response_state = 0x10
};

class informationMessages
{
public:
    informationMessages();
    _is1 createIS1();
    void createIS2(char number);
    _is3 *createIS3();
    void createIS4();
    void createIS5();

    _is1 getIS1() const;

    _is2 getIS2() const;

    void setIS3(const _is3 &IS3);

    void setIS4(const _is4 &value);

    void parsingIS3(_is3 &IS3);

private:
    unsigned getInputState(unsigned char word);
    void printInputState(const unsigned &input);

    _is1 IS1;
    _is2 IS2;
    _is3 IS3;
    _is4 IS4;
    _is5 IS5;
    _rcv_data rcv;


    InputsOutputs io;
    _inputs inputs;
    _outputs outputs;
};

#endif // INFORMATIONMESSAGES_H