#ifndef MANAGEINPUTSOUTPUTS_H
#define MANAGEINPUTSOUTPUTS_H

#include "../../common/hdr/inputs_outputs.h"

class ManageInputsOutputs
{
public:
    ManageInputsOutputs();
    ~ManageInputsOutputs() {}

    void changeInputs(_inputs &inputs, input_state state);
    void changeOutputs(_outputs &outputs, char device_number, unsigned char cntrl);
    void allOutputsOnOff(_outputs &outputs, unsigned char cntrl);
    void oneOutputOnOff(_outputs &outputs, char device_number, unsigned char cntrl);
    void setOutputs(const _outputs &value);
};

#endif // MANAGEINPUTSOUTPUTS_H
