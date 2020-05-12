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

    void calculateCS();
    bool checkCS(unsigned char _cs);

    _is1 getIS1() const;

    _is2 getIS2() const;

    void parsingIS3(_is3 &IS3, bool &ok);
    void parsingIS4(_is4 &IS4);

    char *getInputs();

    char *getOutputs();
//    void setOutputs(_outputs values);
    output_state getOutputState(int number);

    input_state getInputState(int number);
    /// NOTE 1 byte???
    input_state getInputState2(unsigned char word);

    _is1 createIS1WithError();
    _is2 createIS2WithError();


private:
    void parsingWords(_is3 *IS3);
    void printInputState(const unsigned &input);

    /// NOTE 1 byte???
    output_state getOutputState2(unsigned char state);
    void printOutputState(const unsigned &output);

    _is1 IS1;
    _is2 IS2;

    InputsOutputs io;
};

#endif // FORMINGIM_PVKP_H
