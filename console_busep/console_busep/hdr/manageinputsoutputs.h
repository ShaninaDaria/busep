#ifndef MANAGEINPUTSOUTPUTS_H
#define MANAGEINPUTSOUTPUTS_H

#include "../../common/hdr/inputs_outputs.h"

class ManageInputsOutputs
{
public:
    ManageInputsOutputs();
    ~ManageInputsOutputs() {}

    void changeInputs(input_state state);
    void changeOutputs(char device_number, unsigned char cntrl);
    void allOutputsOnOff(unsigned char cntrl);
    void oneOutputOnOff(char device_number, unsigned char cntrl);

    _inputs getInputs() const;

//    void setOutputs(const _outputs &value);
//    _outputs getOutputs() const;
    char *getOutputs2();
    output_state getOutputState(int number);

private:
    InputsOutputs io;

    _inputs inputs;
//    _outputs outputs;
};

#endif // MANAGEINPUTSOUTPUTS_H
