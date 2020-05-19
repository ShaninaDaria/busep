#include "hdr/manageinputsoutputs.h"

ManageInputsOutputs::ManageInputsOutputs()
{

}

void ManageInputsOutputs::changeInputs(int device_number, input_state state)
{
    /// TODO сделать генерацию ошибок

    if (device_number == all_inputs)
    {
        allInputsOnOff(state);
    }
    else
    {
        // еще моя реализация "жесткая", т.е. без пересборки не удастся изменить кол-во входов/выходов
        oneInputOnOff(device_number, state);
    }
}

void ManageInputsOutputs::allInputsOnOff(input_state state)
{
    io.setAllInputs(state);
}

void ManageInputsOutputs::oneInputOnOff(char device_number, input_state state)
{
    io.setOneInput(device_number, state);
}

char *ManageInputsOutputs::getInputs2()
{
    return io.getAllInputs();
}

void ManageInputsOutputs::changeOutputs(char device_number, unsigned char cntrl)
{
    /// TODO сделать генерацию ошибок

    if (device_number == all_outputs)
    {
        allOutputsOnOff(cntrl);
    }
    else
    {
        // говнокод - теперь придется делать switch и кучу одинаковых функций
        // массив был бы удобнее, но не так наглядно
        // еще моя реализация "жесткая", т.е. без пересборки не удастся изменить кол-во входов/выходов
        oneOutputOnOff(device_number, cntrl);
    }
}

void ManageInputsOutputs::allOutputsOnOff(unsigned char cntrl)
{
    output_state state(error_output);
    if (cntrl == cntrl_on)
    {
        state = output_on;
    }
    else
    {
        state = output_off;
    }

    io.setAllOutputs(state);
/*
    outputs.setOutput1(state);
    outputs.setOutput2(state);
    outputs.setOutput3(state);
    outputs.setOutput4(state);

    outputs.setOutput5(state);
    outputs.setOutput6(state);
    outputs.setOutput7(state);
    outputs.setOutput8(state);

    outputs.setOutput9(state);
    outputs.setOutput10(state);
    outputs.setOutput11(state);
    outputs.setOutput12(state);

    outputs.setOutput13(state);
    outputs.setOutput14(state);
    outputs.setOutput15(state);
    outputs.setOutput16(state);

    outputs.setOutput17(state);
    outputs.setOutput18(state);
    outputs.setOutput19(state);
    outputs.setOutput20(state);

    outputs.setOutput21(state);
    outputs.setOutput22(state);
    outputs.setOutput23(state);
    outputs.setOutput24(state);

    outputs.setOutput25(state);
    outputs.setOutput26(state);
    outputs.setOutput27(state);
    outputs.setOutput28(state);

    outputs.setOutput29(state);
    outputs.setOutput30(state);
    outputs.setOutput31(state);
    outputs.setOutput32(state);

    outputs.setOutput33(state);
    outputs.setOutput34(state);
    outputs.setOutput35(state);
    outputs.setOutput36(state);

    outputs.setOutput37(state);
    outputs.setOutput38(state);
    outputs.setOutput39(state);
    outputs.setOutput40(state);

    outputs.setOutput41(state);
    outputs.setOutput42(state);
    outputs.setOutput43(state);
    outputs.setOutput44(state);

    outputs.setOutput45(state);
    outputs.setOutput46(state);
    outputs.setOutput47(state);
    outputs.setOutput48(state);

    outputs.setOutput49(state);
    outputs.setOutput50(state);
    outputs.setOutput51(state);
    outputs.setOutput52(state);

    outputs.setOutput53(state);
    outputs.setOutput54(state);
    outputs.setOutput55(state);
    outputs.setOutput56(state);

    outputs.setOutput57(state);
    outputs.setOutput58(state);
    outputs.setOutput59(state);
    outputs.setOutput60(state);

    outputs.setOutput61(state);
    outputs.setOutput62(state);
*/
}

void ManageInputsOutputs::oneOutputOnOff(char device_number, unsigned char cntrl)
{
    output_state state(error_output);
    if (cntrl == cntrl_on)
    {
        state = output_on;
    }
    else
    {
        state = output_off;
    }

    io.setOneOutput(device_number, state);
/*
    switch (device_number)
    {
    case 0x01: outputs.setOutput1(state); break;
    case 0x02: outputs.setOutput2(state); break;
    case 0x03: outputs.setOutput3(state); break;
    case 0x04: outputs.setOutput4(state); break;

    case 0x05: outputs.setOutput5(state); break;
    case 0x06: outputs.setOutput6(state); break;
    case 0x07: outputs.setOutput7(state); break;
    case 0x08: outputs.setOutput8(state); break;

    case 0x09: outputs.setOutput9(state); break;
    case 0x0a: outputs.setOutput10(state); break;
    case 0x0b: outputs.setOutput11(state); break;
    case 0x0c: outputs.setOutput12(state); break;

    case 0x0d: outputs.setOutput13(state); break;
    case 0x0e: outputs.setOutput14(state); break;
    case 0x0f: outputs.setOutput15(state); break;
    case 0x10: outputs.setOutput16(state); break;

    case 0x11: outputs.setOutput17(state); break;
    case 0x12: outputs.setOutput18(state); break;
    case 0x13: outputs.setOutput19(state); break;
    case 0x14: outputs.setOutput20(state); break;

    case 0x15: outputs.setOutput21(state); break;
    case 0x16: outputs.setOutput22(state); break;
    case 0x17: outputs.setOutput23(state); break;
    case 0x18: outputs.setOutput24(state); break;

    case 0x19: outputs.setOutput25(state); break;
    case 0x1a: outputs.setOutput26(state); break;
    case 0x1b: outputs.setOutput27(state); break;
    case 0x1c: outputs.setOutput28(state); break;

    case 0x1d: outputs.setOutput29(state); break;
    case 0x1e: outputs.setOutput30(state); break;
    case 0x1f: outputs.setOutput31(state); break;
    case 0x20: outputs.setOutput32(state); break;

    case 0x21: outputs.setOutput33(state); break;
    case 0x22: outputs.setOutput34(state); break;
    case 0x23: outputs.setOutput35(state); break;
    case 0x24: outputs.setOutput36(state); break;

    case 0x25: outputs.setOutput37(state); break;
    case 0x26: outputs.setOutput38(state); break;
    case 0x27: outputs.setOutput39(state); break;
    case 0x28: outputs.setOutput40(state); break;

    case 0x29: outputs.setOutput41(state); break;
    case 0x2a: outputs.setOutput42(state); break;
    case 0x2b: outputs.setOutput43(state); break;
    case 0x2c: outputs.setOutput44(state); break;

    case 0x2d: outputs.setOutput45(state); break;
    case 0x2e: outputs.setOutput46(state); break;
    case 0x2f: outputs.setOutput47(state); break;
    case 0x30: outputs.setOutput48(state); break;

    case 0x31: outputs.setOutput49(state); break;
    case 0x32: outputs.setOutput50(state); break;
    case 0x33: outputs.setOutput51(state); break;
    case 0x34: outputs.setOutput52(state); break;

    case 0x35: outputs.setOutput53(state); break;
    case 0x36: outputs.setOutput54(state); break;
    case 0x37: outputs.setOutput55(state); break;
    case 0x38: outputs.setOutput56(state); break;

    case 0x39: outputs.setOutput57(state); break;
    case 0x3a: outputs.setOutput58(state); break;
    case 0x3b: outputs.setOutput59(state); break;
    case 0x3c: outputs.setOutput60(state); break;

    case 0x3d: outputs.setOutput61(state); break;
    case 0x3e: outputs.setOutput62(state); break;
    }
*/
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
