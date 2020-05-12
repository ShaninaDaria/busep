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

    void createIS3(input_state state);
    void sendIS3(_is3 *IS3);

    void createIS4(char device_number, unsigned char cnrtl);
    void sendIS4(_is4 *IS4);

    void createIS5();
    void sendIS5(_is5 *IS5);

    char *getInputs();
    char *getOutputs();

    output_state getOutputState(int number);
    input_state getInputState(int number);

private:
    header_and_managed receiveSmth();

    FormingIM_busep *formingIM_busep;
    DataTransmit *dataTransnmit;
    _is1 IS1;
    _is2 IS2;
    _is3 *IS3;
    _is4 *IS4;
    _is5 *IS5;
};

#endif // DUMMYMESSAGES_H
