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
    _is5 *createIS5();
//    char calculateCRC(void *p, int bytes);
//    bool checkCRC(void *p, int bytes, unsigned char crc);

//    _inputs getInputs() const;

    bool parseIS1(_is1 *IS1);
    bool parseIS2(_is2 *IS2);

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
