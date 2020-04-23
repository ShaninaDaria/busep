#ifndef DUMMYMESSAGES_H
#define DUMMYMESSAGES_H

#include "../../common/hdr/informationmessages.h"
#include "../../common/hdr/datatransmit.h"


class dummyMessages
{
public:
    dummyMessages();
    ~dummyMessages();

    void startExchange();

    void setInputsValue();

    void createIS3();
    int receiveIS1();
    void sendIS3(_is3 *IS3);

    void createIS4();
    int receiveIS2();
    void sendIS4(_is4 *IS4);

private:
    header_and_managed receiveSmth();

    informationMessages *IM;
    DataTransmit *dataTransnmit;
    _is1 IS1;
    _is2 IS2;
    _is3 *IS3;
    _is4 *IS4;
};

#endif // DUMMYMESSAGES_H
