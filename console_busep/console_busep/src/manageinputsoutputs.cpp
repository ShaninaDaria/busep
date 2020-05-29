#include "hdr/manageinputsoutputs.h"

ManageInputsOutputs::ManageInputsOutputs()
{

}

void ManageInputsOutputs::changeInputs(int device_number, input_state state)
{
    if (device_number == all_inputs)
    {
        allInputsOnOff(state);
    }
    else
    {
        // еще моя реализация "жесткая", т.е. без пересборки не удастся изменить кол-во входов/выходов
        oneInputOnOff(static_cast<unsigned char>(device_number), state);
    }
}

void ManageInputsOutputs::allInputsOnOff(input_state state)
{
    io.setAllInputs(state);
}

void ManageInputsOutputs::oneInputOnOff(unsigned char device_number, input_state state)
{
    io.setOneInput(device_number, state);
}

char *ManageInputsOutputs::getInputs2()
{
    return io.getAllInputs();
}

void ManageInputsOutputs::changeOutputs(unsigned char device_number, unsigned char cntrl,
                                        bool add_error, bool no_state)
{
    if (device_number == all_outputs)
    {
        allOutputsOnOff(cntrl, add_error, no_state);
    }
    else
    {
        // говнокод - теперь придется делать switch и кучу одинаковых функций
        // массив был бы удобнее, но не так наглядно
        // еще моя реализация "жесткая", т.е. без пересборки не удастся изменить кол-во входов/выходов
        oneOutputOnOff(device_number, cntrl, add_error, no_state);
    }
}

void ManageInputsOutputs::allOutputsOnOff(unsigned char cntrl, bool add_error, bool no_state)
{
    output_state state(no_output_state);
    if (add_error) state = error_output;
    if (no_state) state = no_output_state;
    if (!add_error && !no_state)
    {
        if (cntrl == cntrl_on)
        {
            state = output_on;
        }
        if (cntrl == cntrl_off)
        {
            state = output_off;
        }
    }

    io.setAllOutputs(state);
}

void ManageInputsOutputs::oneOutputOnOff(unsigned char device_number, unsigned char cntrl,
                                         bool add_error, bool no_state)
{
    output_state state;
    if (add_error) state = error_output;
    if (no_state) state = no_output_state;
    if (!add_error && !no_state)
    {
        if (cntrl == cntrl_on)
        {
            state = output_on;
        }
        else
        {
            state = output_off;
        }
    }

    io.setOneOutput(device_number, state);
}

//_inputs ManageInputsOutputs::getInputs() const
//{
//    return inputs;
//}

//_outputs ManageInputsOutputs::getOutputs() const
//{
//    return outputs;
//}

char *ManageInputsOutputs::getOutputs2()
{
    return io.getAllOutputs();
}

output_state ManageInputsOutputs::getOutputState(int number)
{
    return io.getOutputValue(number);
}

input_state ManageInputsOutputs::getInputState(int number)
{
    return io.getInputValue(number);
}
