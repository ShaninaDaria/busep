#ifndef MANAGEINPUTSOUTPUTS_H
#define MANAGEINPUTSOUTPUTS_H

#include "../../common/hdr/inputs_outputs.h"

class ManageInputsOutputs
{
public:
    ManageInputsOutputs();
    ~ManageInputsOutputs() {}

    void changeInputs(int device_number, input_state state);
    void allInputsOnOff(input_state state);
    void oneInputOnOff(char device_number, input_state state);
    char *getInputs2();

    void changeOutputs(char device_number, unsigned char cntrl);
    void allOutputsOnOff(unsigned char cntrl);
    void oneOutputOnOff(char device_number, unsigned char cntrl);

//    _inputs getInputs() const;

//    void setOutputs(const _outputs &value);
//    _outputs getOutputs() const;
    char *getOutputs2();
    output_state getOutputState(int number);
    input_state getInputState(int number);

private:
    InputsOutputs io;

//    _inputs inputs;
//    _outputs outputs;
};

#endif // MANAGEINPUTSOUTPUTS_H
