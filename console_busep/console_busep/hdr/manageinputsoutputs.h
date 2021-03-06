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
    void oneInputOnOff(unsigned char device_number, input_state state);
    char *getInputs2();

    void changeOutputs(unsigned char device_number, unsigned char cntrl, bool add_error = false, bool no_state = false);
    void allOutputsOnOff(unsigned char cntrl, bool add_error = false, bool no_state = false);
    void oneOutputOnOff(unsigned char device_number, unsigned char cntrl, bool add_error = false, bool no_state = false);

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
