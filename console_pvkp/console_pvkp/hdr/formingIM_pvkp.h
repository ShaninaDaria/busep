#ifndef FORMINGIM_PVKP_H
#define FORMINGIM_PVKP_H

#include <QDebug>
#include "../../common/hdr/inputs_outputs.h"
#include "../../common/hdr/informationmessages.h"


class FormingIM_pvkp
{
public:
    FormingIM_pvkp() {}
    ~FormingIM_pvkp() {}
    _is1 createIS1();
    _is2 createIS2(unsigned char device_number, output_cntrl cntrl);

    _is1 getIS1() const;

    _is2 getIS2() const;

    void copyIS3fromRcvData(_rcv_data *rcv_data, _is3 &IS3);
    void parsingIS3(_is3 *IS3, bool &ok);
    void copyIS4fromRcvData(_rcv_data *rcv_data, _is4 &IS4);
    void parsingIS4(_is4 *IS4, bool &ok);
    void copyIS5fromRcvData(_rcv_data *rcv_data, _is5 &IS5);
    void parsingIS5(_is5 *IS5, bool &ok);

    char *getInputs();

    char *getOutputs();

    output_state getOutputState(int number);

    input_state getInputState(int number);

    input_state getInputState2(unsigned char word);

    _is1 createIS1WithError();
    _is2 createIS2WithError(unsigned char number, output_cntrl cntrl);


private:
    void clearIS1();
    void clearIS2();
    void parsingWords(_is3 *IS3);

    void parsingStates(_is4 *IS4);


    output_state getOutputState2(unsigned char state);

    _is1 IS1;
    _is2 IS2;

    InformationMessages im;
    InputsOutputs io;
};

#endif // FORMINGIM_PVKP_H
