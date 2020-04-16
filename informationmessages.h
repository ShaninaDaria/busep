#ifndef INFORMATIONMESSAGES_H
#define INFORMATIONMESSAGES_H

#include <QDebug>
#include "inputs_outputs.h"

struct _is1
{
    unsigned header:8;
    unsigned managed:8;
    unsigned cs:8;
};

struct _is2
{
    unsigned header:8;
    unsigned managed:8;
    unsigned device_number:8;
    unsigned state:8;
    unsigned cs:8;
};

struct _is3
{
    unsigned header:8;
    unsigned managed:8;
    unsigned word0:8;
    unsigned word1:8;
    unsigned word2:8;
    unsigned word3:8;
    unsigned word4:8;
    unsigned word5:8;
    unsigned word6:8;
    unsigned word7:8;
    unsigned word8:8;
    unsigned word9:8;
    unsigned word10:8;
    unsigned word11:8;
    unsigned word12:8;
    unsigned word13:8;
    unsigned word14:8;
    unsigned word15:8;
    unsigned word16:8;
    unsigned word17:8;
    unsigned word18:8;
    unsigned word19:8;
    unsigned word20:8;
    unsigned word21:8;
    unsigned word22:8;
    unsigned word23:8;
    unsigned word24:8;
    unsigned word25:8;
    unsigned word26:8;
    unsigned word27:8;
    unsigned word28:8;
    unsigned word29:8;
    unsigned word30:8;
    unsigned cs:8;
};

struct _is4
{
    unsigned header:8;
    unsigned managed:8;
    unsigned state:16;
    unsigned cs:1;
};

struct _is5
{
    unsigned header:8;
    unsigned managed:8;
    unsigned cs:1;
};

class informationMessages
{
public:
    informationMessages();
    void createIS1();
    void createIS2(char number);
    void createIS3();
    void createIS4();

    _is1 getIS1() const;

    _is2 getIS2() const;

    void setIS3(const _is3 &value);

    void setIS4(const _is4 &value);

private:
    void parsingIS3();

    _is1 IS1;
    _is2 IS2;
    _is3 IS3;
    _is4 IS4;

    inputs_outputs io;
    _inputs inputs;
    _outputs outputs;
};

#endif // INFORMATIONMESSAGES_H
