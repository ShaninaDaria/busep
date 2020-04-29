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
    ~FormingIM_busep() {}

    _is3 *createIS3(input_state state);
    _is4 *createIS4(char device_number, unsigned char cnrtl);
    void createIS5();
    void calculateCS();
    bool checkCS(unsigned char _cs);

    _inputs getInputs() const;

    _outputs getOutputs() const;

private:
    _is3 IS3;
    _is4 IS4;
    _is5 IS5;
    _rcv_data rcv;

    ManageInputsOutputs manageIO;

//    _inputs inputs;
//    _outputs outputs;
};

#endif // FORMINGIM_BUSEP_H
