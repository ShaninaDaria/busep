#include "../../common/hdr/inputs_outputs.h"

//----------------------------------------------------------

InputsOutputs::InputsOutputs()
{
#ifdef QNX
    bzero(outputs2, sizeof (outputs2));
    bzero(inputs2, sizeof (inputs2));
#else
    memset(outputs2, 0, sizeof (outputs2));
    memset(outputs2, 0, sizeof (outputs2));
#endif

    for (int i = 0; i < output_size; i++)
    {
        outputs2[i] = no_output_state;
    }

    for (int i = 0; i < input_size; i++)
    {
        inputs2[i] = no_input_state;
    }
}

//----------------------------------------------------------

void InputsOutputs::setAllOutputs(output_state state)
{
    for (int i = 0; i < output_size; i++)
    {
        outputs2[i] = state;
    }
}

//----------------------------------------------------------

void InputsOutputs::setOneOutput(int number, output_state state)
{
    if (number < output_size)
    {
        outputs2[number - 1] = state;
    }
}

//----------------------------------------------------------

output_state InputsOutputs::getOutputValue(int number)
{
    if (number < output_size)
    {
        return static_cast<output_state>(outputs2[number - 1]);
    }
    return error_output;
}

//----------------------------------------------------------

char *InputsOutputs::getAllOutputs()
{
    return outputs2;
}

//----------------------------------------------------------

void InputsOutputs::setAllInputs(input_state state)
{
    for (int i = 0; i < input_size; i++)
    {
        inputs2[i] = state;
    }
}

//----------------------------------------------------------

void InputsOutputs::setOneInput(int number, input_state state)
{
    if (number < input_size)
    {
        inputs2[number - 1] = state;
    }
}

input_state InputsOutputs::getInputValue(int number)
{
    if (number < input_size)
    {
        return static_cast<input_state>(inputs2[number - 1]);
    }
    return no_input_state;
}

//----------------------------------------------------------

char *InputsOutputs::getAllInputs()
{
    return inputs2;
}

//----------------------------------------------------------
