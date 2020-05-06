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

//    _inputs getInputs() const;

    char *getInputs();

    char *getOutputs();
    output_state getOutputState(int number);
    input_state getInputState(int number);

private:
    _is3 IS3;
    _is4 IS4;
    _is5 IS5;
    _rcv_data rcv;

    ManageInputsOutputs manageIO;
};

#endif // FORMINGIM_BUSEP_H
