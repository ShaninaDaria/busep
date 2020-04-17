#ifndef DUMMYMESSAGES_H
#define DUMMYMESSAGES_H

#include "../../common/hdr/informationmessages.h"


class dummyMessages
{
public:
    dummyMessages();
    ~dummyMessages();

    void setInputsValue();

    void createIS3();
    void receiveIS1();
    void sendIS3();

    void createIS4();
    void receiveIS2();
    void sendIS4();

private:
    informationMessages *IM;
};

#endif // DUMMYMESSAGES_H
