#ifndef FORMINGIM_PVKP_H
#define FORMINGIM_PVKP_H

#include <QDebug>
#include "../../common/hdr/inputs_outputs.h"
#include "../../common/hdr/informationmessages.h"


class FormingIM_pvkp
{
public:
    FormingIM_pvkp();
    _is1 createIS1();
    _is2 createIS2(char device_number, output_cntrl cntrl);

//    char calculateCRC(void *p, int bytes);
//    bool checkCRC(void *p, int bytes, unsigned char crc);

    _is1 getIS1() const;

    _is2 getIS2() const;

    void parsingIS3(_rcv_data *rcv_data, _is3 &IS3, bool &ok);
    void parsingIS4(_rcv_data *rcv_data, _is4 &IS4, bool &ok);
    void parsingIS5(_rcv_data *rcv_data, _is5 &IS5, bool &ok);

    char *getInputs();

    char *getOutputs();
//    void setOutputs(_outputs values);
    output_state getOutputState(int number);

    input_state getInputState(int number);

    input_state getInputState2(unsigned char word);

    _is1 createIS1WithError();
    _is2 createIS2WithError(char number, output_cntrl cntrl);


private:
    void parsingIS3(_is3 *IS3, bool &ok);
    void parsingWords(_is3 *IS3);

    void parsingIS4(_is4 *IS4, bool &ok);
    void parsingStates(_is4 *IS4);

    void parsingIS5(_is5 *IS5, bool &ok);

    output_state getOutputState2(unsigned char state);

    _is1 IS1;
    _is2 IS2;

    InformationMessages im;
    InputsOutputs io;
};

#endif // FORMINGIM_PVKP_H
