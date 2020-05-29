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

    _is3 *createIS3(int device_number, input_state state);
    _is4 *createIS4(unsigned char device_number, unsigned char cnrtl,
                    bool add_error = false, bool no_state = false);
    _is5 *createIS5();

//    _inputs getInputs() const;

    bool parsingIS1(_is1 *IS1);
    bool parsingIS2(_is2 *IS2);

    char *getInputs();

    char *getOutputs();
    output_state getOutputState(int number);
    input_state getInputState(int number);

private:
    void setWordsIS3(_is3 &IS3);
    void setStatesIS4(_is4 &IS4);
    _is3 IS3;
    _is4 IS4;
    _is5 IS5;
//    _rcv_data rcv;

    ManageInputsOutputs manageIO;
    InformationMessages im;
};

#endif // FORMINGIM_BUSEP_H
