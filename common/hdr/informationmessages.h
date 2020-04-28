#ifndef INFORMATIONMESSAGES_H
#define INFORMATIONMESSAGES_H

#include <QDebug>
#include "inputs_outputs.h"

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
    empty = 0x00,               // для меня
    header = 0xff,              // заголовок
    request = 0x01,             // ИС1
    change_state = 0x02,        // ИС2
    response_change = 0x03,     // ИС4
    integrity_violation = 0x09, // ИС5
    response_state = 0x10       // ИС3
};
/*
class informationMessages
{
public:
    informationMessages();
    _is1 createIS1();
    _is2 createIS2(char device_number, output_cntrl cntrl);
    _is3 *createIS3();
    _is4 *createIS4(char device_number, unsigned char cnrtl);
    void createIS5();
    void calculateCS();
    bool checkCS(unsigned char _cs);

    _is1 getIS1() const;

    _is2 getIS2() const;

    void setIS3(const _is3 &IS3);

    void setIS4(const _is4 &value);

    void parsingIS3(_is3 &IS3);
    void parsingIS4(_is4 &IS4);

    _inputs &getInputs();

    _outputs &getOutputs();

private:
    unsigned getInputState(unsigned char word);
    void printInputState(const unsigned &input);

    unsigned getOutputState(unsigned char state);
    void printOutputState(const unsigned &output);

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
*/
#endif // INFORMATIONMESSAGES_H
