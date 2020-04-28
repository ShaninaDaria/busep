#ifndef MANAGEINPUTSOUTPUTS_H
#define MANAGEINPUTSOUTPUTS_H

#include "../../common/hdr/inputs_outputs.h"

class ManageInputsOutputs
{
public:
    ManageInputsOutputs();

    void changeInputs(_inputs &inputs);
    void changeOutputs(_outputs &outputs, char device_number, unsigned char cntrl);
    void allOutputsOn(_outputs &outputs);
    void allOutputsOff(_outputs &outputs);
    void oneOutputOn(_outputs &outputs, char device_number);
    void oneOutputOff(_outputs &outputs, char device_number);
    void setOutputs(const _outputs &value);
};

#endif // MANAGEINPUTSOUTPUTS_H
