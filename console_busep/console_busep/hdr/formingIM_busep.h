#ifndef FORMINGIM_BUSEP_H
#define FORMINGIM_BUSEP_H

#include <QDebug>
#include "../../common/hdr/inputs_outputs.h"
#include "../../common/hdr/informationmessages.h"
#include "manageinputsoutputs.h"

class FormingIM_busep
{
public:
    FormingIM_busep();
    _is3 *createIS3();
    _is4 *createIS4(char device_number, unsigned char cnrtl);
    void createIS5();
    void calculateCS();
    bool checkCS(unsigned char _cs);

//    _is1 getIS1() const;

//    _is2 getIS2() const;

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

//    _is1 IS1;
//    _is2 IS2;
    _is3 IS3;
    _is4 IS4;
    _is5 IS5;
    _rcv_data rcv;

    ManageInputsOutputs manageIO;

    InputsOutputs io;
    _inputs inputs;
    _outputs outputs;
};

#endif // FORMINGIM_BUSEP_H
