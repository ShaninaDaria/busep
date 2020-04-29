#include "hdr/manageinputsoutputs.h"

ManageInputsOutputs::ManageInputsOutputs()
{

}

void ManageInputsOutputs::changeInputs(_inputs &inputs, input_state state)
{
    inputs.setInput1(state);
    inputs.setInput2(state);
    inputs.setInput3(state);
    inputs.setInput4(state);

    inputs.setInput5(state);
    inputs.setInput6(state);
    inputs.setInput7(state);
    inputs.setInput8(state);

    inputs.setInput9(state);
    inputs.setInput10(state);
    inputs.setInput11(state);
    inputs.setInput12(state);

    inputs.setInput13(state);
    inputs.setInput14(state);
    inputs.setInput15(state);
    inputs.setInput16(state);

    inputs.setInput17(state);
    inputs.setInput18(state);
    inputs.setInput19(state);
    inputs.setInput20(state);

    inputs.setInput21(state);
    inputs.setInput22(state);
    inputs.setInput23(state);
    inputs.setInput24(state);

    inputs.setInput25(state);
    inputs.setInput26(state);
    inputs.setInput27(state);
    inputs.setInput28(state);

    inputs.setInput29(state);
    inputs.setInput30(state);
    inputs.setInput31(state);
    inputs.setInput32(state);

    inputs.setInput33(state);
    inputs.setInput34(state);
    inputs.setInput35(state);
    inputs.setInput36(state);

    inputs.setInput37(state);
    inputs.setInput38(state);
    inputs.setInput39(state);
    inputs.setInput40(state);

    inputs.setInput41(state);
    inputs.setInput42(state);
    inputs.setInput43(state);
    inputs.setInput44(state);

    inputs.setInput45(state);
    inputs.setInput46(state);
    inputs.setInput47(state);
    inputs.setInput48(state);

    inputs.setInput49(state);
    inputs.setInput50(state);
    inputs.setInput51(state);
    inputs.setInput52(state);

    inputs.setInput53(state);
    inputs.setInput54(state);
    inputs.setInput55(state);
    inputs.setInput56(state);

    inputs.setInput57(state);
    inputs.setInput58(state);
    inputs.setInput59(state);
    inputs.setInput60(state);

    inputs.setInput61(state);
    inputs.setInput62(state);
    inputs.setInput63(state);
    inputs.setInput64(state);

    inputs.setInput65(state);
    inputs.setInput66(state);
    inputs.setInput67(state);
    inputs.setInput68(state);

    inputs.setInput69(state);
    inputs.setInput70(state);
    inputs.setInput71(state);
    inputs.setInput72(state);

    inputs.setInput73(state);
    inputs.setInput74(state);
    inputs.setInput75(state);
    inputs.setInput76(state);

    inputs.setInput77(state);
    inputs.setInput78(state);
    inputs.setInput79(state);
    inputs.setInput80(state);

    inputs.setInput81(state);
    inputs.setInput82(state);
    inputs.setInput83(state);
    inputs.setInput84(state);

    inputs.setInput85(state);
    inputs.setInput86(state);
    inputs.setInput87(state);
    inputs.setInput88(state);

    inputs.setInput89(state);
    inputs.setInput90(state);
    inputs.setInput91(state);
    inputs.setInput92(state);

    inputs.setInput93(state);
    inputs.setInput94(state);
    inputs.setInput95(state);
    inputs.setInput96(state);

    inputs.setInput97(state);
    inputs.setInput98(state);
    inputs.setInput99(state);
    inputs.setInput100(state);

    inputs.setInput101(state);
    inputs.setInput102(state);
    inputs.setInput103(state);
    inputs.setInput104(state);

    inputs.setInput105(state);
    inputs.setInput106(state);
    inputs.setInput107(state);
    inputs.setInput108(state);

    inputs.setInput109(state);
    inputs.setInput110(state);
    inputs.setInput111(state);
    inputs.setInput112(state);

    inputs.setInput113(state);
    inputs.setInput114(state);
    inputs.setInput115(state);
    inputs.setInput116(state);

    inputs.setInput117(state);
    inputs.setInput118(state);
    inputs.setInput119(state);
    inputs.setInput120(state);

    inputs.setInput121(state);
    inputs.setInput122(state);
    inputs.setInput123(state);
    inputs.setInput124(state);
}

void ManageInputsOutputs::changeOutputs(_outputs &outputs, char device_number, unsigned char cntrl)
{
    /// TODO сделать генерацию ошибок

    if (device_number == all_outputs)
    {
        allOutputsOnOff(outputs, cntrl);
    }
    else
    {
        // говнокод - теперь придется делать switch и кучу одинаковых функций
        // массив был бы удобнее, но не так наглядно
        // еще моя реализация "жесткая", т.е. без пересборки не удастся изменить кол-во входов/выходов
        oneOutputOnOff(outputs, device_number, cntrl);
    }
/*
    outputs.setOutput1(output_on);
    outputs.setOutput2(output_off);
    outputs.setOutput3(no_output_state);
    outputs.setOutput4(error_output);

    outputs.setOutput5(output_on);
    outputs.setOutput6(output_off);
    outputs.setOutput7(no_output_state);
    outputs.setOutput8(error_output);

    outputs.setOutput9(output_on);
    outputs.setOutput10(output_off);
    outputs.setOutput11(no_output_state);
    outputs.setOutput12(error_output);

    outputs.setOutput13(output_on);
    outputs.setOutput14(output_off);
    outputs.setOutput15(no_output_state);
    outputs.setOutput16(error_output);

    outputs.setOutput17(output_on);
    outputs.setOutput18(output_off);
    outputs.setOutput19(no_output_state);
    outputs.setOutput20(error_output);

    outputs.setOutput21(output_on);
    outputs.setOutput22(output_off);
    outputs.setOutput23(no_output_state);
    outputs.setOutput24(error_output);

    outputs.setOutput25(output_on);
    outputs.setOutput26(output_off);
    outputs.setOutput27(no_output_state);
    outputs.setOutput28(error_output);

    outputs.setOutput29(output_on);
    outputs.setOutput30(output_off);
    outputs.setOutput31(no_output_state);
    outputs.setOutput32(error_output);

    outputs.setOutput33(output_on);
    outputs.setOutput34(output_off);
    outputs.setOutput35(no_output_state);
    outputs.setOutput36(error_output);

    outputs.setOutput37(output_on);
    outputs.setOutput38(output_off);
    outputs.setOutput39(no_output_state);
    outputs.setOutput40(error_output);

    outputs.setOutput41(output_on);
    outputs.setOutput42(output_off);
    outputs.setOutput43(no_output_state);
    outputs.setOutput44(error_output);

    outputs.setOutput45(output_on);
    outputs.setOutput46(output_off);
    outputs.setOutput47(no_output_state);
    outputs.setOutput48(error_output);

    outputs.setOutput49(output_on);
    outputs.setOutput50(output_off);
    outputs.setOutput51(no_output_state);
    outputs.setOutput52(error_output);

    outputs.setOutput53(output_on);
    outputs.setOutput54(output_off);
    outputs.setOutput55(no_output_state);
    outputs.setOutput56(error_output);

    outputs.setOutput57(output_on);
    outputs.setOutput58(output_off);
    outputs.setOutput59(no_output_state);
    outputs.setOutput60(error_output);

    outputs.setOutput61(output_on);
    outputs.setOutput62(output_off);
*/
}

void ManageInputsOutputs::allOutputsOnOff(_outputs &outputs, unsigned char cntrl)
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
}

void ManageInputsOutputs::oneOutputOnOff(_outputs &outputs, char device_number, unsigned char cntrl)
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
}
