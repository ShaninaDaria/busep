#ifndef DUMMYMESSAGES_H
#define DUMMYMESSAGES_H

#include "../../common/hdr/informationmessages.h"
#include "../../common/hdr/datatransmit.h"
#include "formingIM_busep.h"


class DummyMessages
{
public:
    DummyMessages();
    ~DummyMessages();

    void startExchange();

    void setInputsValue();

    void createIS3(input_state state);
//    int receiveIS1();
    void sendIS3(_is3 *IS3);

    void createIS4(char device_number, unsigned char cnrtl);
//    int receiveIS2();
    void sendIS4(_is4 *IS4);

    _inputs getInputs() const;
    char *getOutputs();

    output_state getOutputState(int number);

private:
    header_and_managed receiveSmth();

    FormingIM_busep *formingIM_busep;
    DataTransmit *dataTransnmit;
    _is1 IS1;
    _is2 IS2;
    _is3 *IS3;
    _is4 *IS4;
};

#endif // DUMMYMESSAGES_H
