#include "hdr/formingIM_pvkp.h"

FormingIM_pvkp::FormingIM_pvkp()
{
    inputs = io.initInputs();
    outputs = io.initOutputs();
}

_is1 FormingIM_pvkp::createIS1()
{
    bzero(&IS1, (sizeof (_is1)));

    qDebug() << "IS1";
    IS1.header = header; printf("    header \t%02x\n", IS1.header);
    IS1.managed = request; printf("    managed \t%02x\n", IS1.managed);
    IS1.cs = 0x00; printf("    cs \t%02x\n", IS1.cs);
    qDebug() << "-----\n";

    return IS1;
}

_is2 FormingIM_pvkp::createIS2(char device_number, output_cntrl cntrl)
{
    bzero(&IS2, (sizeof (_is2)));

    qDebug() << "IS2";
    IS2.header = header; printf("    header \t%02x\n", IS2.header);
    IS2.managed = change_state; printf("    managed \t%02x\n", IS2.managed);
    IS2.device_number = device_number; printf("    device_number \t%d\n", IS2.device_number);
    IS2.state = cntrl; printf("    state \t%02x\n", IS2.state);
    IS1.cs = 0x00;  printf("    cs \t%02x\n", IS2.cs);
    qDebug() << "-----\n";

    return IS2;
}

void FormingIM_pvkp::calculateCS()
{

}

bool FormingIM_pvkp::checkCS(unsigned char _cs)
{
    return true;
}

_is1 FormingIM_pvkp::getIS1() const
{
    return IS1;
}

_is2 FormingIM_pvkp::getIS2() const
{
    return IS2;
}

void FormingIM_pvkp::parsingIS3(_is3 &IS3)
{
    printf("    header \t%02x\n", IS3.header);
    printf("  managed \t%02x\n", IS3.managed);

    qDebug() << "IS3.word00" << IS3.word00;
    printf("    word00 \t%02x\n", IS3.word00);
    inputs.setInput1(getInputState(IS3.word00)); IS3.word00 = IS3.word00 >> 2;
    inputs.setInput2(getInputState(IS3.word00)); IS3.word00 = IS3.word00 >> 2;
    inputs.setInput3(getInputState(IS3.word00)); IS3.word00 = IS3.word00 >> 2;
    inputs.setInput4(getInputState(IS3.word00));

    printf("    word01 \t%02x\n", IS3.word01);
    inputs.setInput5(getInputState(IS3.word01)); IS3.word01 = IS3.word01 >> 2;
    inputs.setInput6(getInputState(IS3.word01)); IS3.word01 = IS3.word01 >> 2;
    inputs.setInput7(getInputState(IS3.word01)); IS3.word01 = IS3.word01 >> 2;
    inputs.setInput8(getInputState(IS3.word01));

    printf("    word02 \t%02x\n", IS3.word02);
    inputs.setInput9(getInputState(IS3.word02)); IS3.word02 = IS3.word02 >> 2;
    inputs.setInput10(getInputState(IS3.word02)); IS3.word02 = IS3.word02 >> 2;
    inputs.setInput11(getInputState(IS3.word02)); IS3.word02 = IS3.word02 >> 2;
    inputs.setInput12(getInputState(IS3.word02));

    printf("    word03 \t%02x\n", IS3.word03);
    inputs.setInput13(getInputState(IS3.word03)); IS3.word03 = IS3.word03 >> 2;
    inputs.setInput14(getInputState(IS3.word03)); IS3.word03 = IS3.word03 >> 2;
    inputs.setInput15(getInputState(IS3.word03)); IS3.word03 = IS3.word03 >> 2;
    inputs.setInput16(getInputState(IS3.word03));

    printf("    word04 \t%02x\n", IS3.word04);
    inputs.setInput17(getInputState(IS3.word04)); IS3.word04 = IS3.word04 >> 2;
    inputs.setInput18(getInputState(IS3.word04)); IS3.word04 = IS3.word04 >> 2;
    inputs.setInput19(getInputState(IS3.word04)); IS3.word04 = IS3.word04 >> 2;
    inputs.setInput20(getInputState(IS3.word04));

    printf("    word05 \t%02x\n", IS3.word05);
    inputs.setInput21(getInputState(IS3.word05)); IS3.word05 = IS3.word05 >> 2;
    inputs.setInput22(getInputState(IS3.word05)); IS3.word05 = IS3.word05 >> 2;
    inputs.setInput23(getInputState(IS3.word05)); IS3.word05 = IS3.word05 >> 2;
    inputs.setInput24(getInputState(IS3.word05));

    printf("    word06 \t%02x\n", IS3.word06);
    inputs.setInput25(getInputState(IS3.word06)); IS3.word06 = IS3.word06 >> 2;
    inputs.setInput26(getInputState(IS3.word06)); IS3.word06 = IS3.word06 >> 2;
    inputs.setInput27(getInputState(IS3.word06)); IS3.word06 = IS3.word06 >> 2;
    inputs.setInput28(getInputState(IS3.word06));

    printf("    word07 \t%02x\n", IS3.word07);
    inputs.setInput29(getInputState(IS3.word07)); IS3.word07 = IS3.word07 >> 2;
    inputs.setInput30(getInputState(IS3.word07)); IS3.word07 = IS3.word07 >> 2;
    inputs.setInput31(getInputState(IS3.word07)); IS3.word07 = IS3.word07 >> 2;
    inputs.setInput32(getInputState(IS3.word07));

    printf("    word08 \t%02x\n", IS3.word08);
    inputs.setInput33(getInputState(IS3.word08)); IS3.word08 = IS3.word08 >> 2;
    inputs.setInput34(getInputState(IS3.word08)); IS3.word08 = IS3.word08 >> 2;
    inputs.setInput35(getInputState(IS3.word08)); IS3.word08 = IS3.word08 >> 2;
    inputs.setInput36(getInputState(IS3.word08));

    printf("    word09 \t%02x\n", IS3.word09);
    inputs.setInput37(getInputState(IS3.word09)); IS3.word09 = IS3.word09 >> 2;
    inputs.setInput38(getInputState(IS3.word09)); IS3.word09 = IS3.word09 >> 2;
    inputs.setInput39(getInputState(IS3.word09)); IS3.word09 = IS3.word09 >> 2;
    inputs.setInput40(getInputState(IS3.word09));

    printf("    word10 \t%02x\n", IS3.word10);
    inputs.setInput41(getInputState(IS3.word10)); IS3.word10 = IS3.word10 >> 2;
    inputs.setInput42(getInputState(IS3.word10)); IS3.word10 = IS3.word10 >> 2;
    inputs.setInput43(getInputState(IS3.word10)); IS3.word10 = IS3.word10 >> 2;
    inputs.setInput44(getInputState(IS3.word10));

    printf("    word11 \t%02x\n", IS3.word11);
    inputs.setInput45(getInputState(IS3.word11)); IS3.word11 = IS3.word11 >> 2;
    inputs.setInput46(getInputState(IS3.word11)); IS3.word11 = IS3.word11 >> 2;
    inputs.setInput47(getInputState(IS3.word11)); IS3.word11 = IS3.word11 >> 2;
    inputs.setInput48(getInputState(IS3.word11));

    printf("    word12 \t%02x\n", IS3.word12);
    inputs.setInput49(getInputState(IS3.word12)); IS3.word12 = IS3.word12 >> 2;
    inputs.setInput50(getInputState(IS3.word12)); IS3.word12 = IS3.word12 >> 2;
    inputs.setInput51(getInputState(IS3.word12)); IS3.word12 = IS3.word12 >> 2;
    inputs.setInput52(getInputState(IS3.word12));

    printf("    word13 \t%02x\n", IS3.word13);
    inputs.setInput53(getInputState(IS3.word13)); IS3.word13 = IS3.word13 >> 2;
    inputs.setInput54(getInputState(IS3.word13)); IS3.word13 = IS3.word13 >> 2;
    inputs.setInput55(getInputState(IS3.word13)); IS3.word13 = IS3.word13 >> 2;
    inputs.setInput56(getInputState(IS3.word13));

    printf("    word14 \t%02x\n", IS3.word14);
    inputs.setInput57(getInputState(IS3.word14)); IS3.word14 = IS3.word14 >> 2;
    inputs.setInput58(getInputState(IS3.word14)); IS3.word14 = IS3.word14 >> 2;
    inputs.setInput59(getInputState(IS3.word14)); IS3.word14 = IS3.word14 >> 2;
    inputs.setInput60(getInputState(IS3.word14));

    printf("    word15 \t%02x\n", IS3.word15);
    inputs.setInput61(getInputState(IS3.word15)); IS3.word15 = IS3.word15 >> 2;
    inputs.setInput62(getInputState(IS3.word15)); IS3.word15 = IS3.word15 >> 2;
    inputs.setInput63(getInputState(IS3.word15)); IS3.word15 = IS3.word15 >> 2;
    inputs.setInput64(getInputState(IS3.word15));

    printf("    word16 \t%02x\n", IS3.word16);
    inputs.setInput65(getInputState(IS3.word16)); IS3.word16 = IS3.word16 >> 2;
    inputs.setInput66(getInputState(IS3.word16)); IS3.word16 = IS3.word16 >> 2;
    inputs.setInput67(getInputState(IS3.word16)); IS3.word16 = IS3.word16 >> 2;
    inputs.setInput68(getInputState(IS3.word16));

    printf("    word17 \t%02x\n", IS3.word17);
    inputs.setInput69(getInputState(IS3.word17)); IS3.word17 = IS3.word17 >> 2;
    inputs.setInput70(getInputState(IS3.word17)); IS3.word17 = IS3.word17 >> 2;
    inputs.setInput71(getInputState(IS3.word17)); IS3.word17 = IS3.word17 >> 2;
    inputs.setInput72(getInputState(IS3.word17));

    printf("    word18 \t%02x\n", IS3.word18);
    inputs.setInput73(getInputState(IS3.word18)); IS3.word18 = IS3.word18 >> 2;
    inputs.setInput74(getInputState(IS3.word18)); IS3.word18 = IS3.word18 >> 2;
    inputs.setInput75(getInputState(IS3.word18)); IS3.word18 = IS3.word18 >> 2;
    inputs.setInput76(getInputState(IS3.word18));

    printf("    word19 \t%02x\n", IS3.word19);
    inputs.setInput77(getInputState(IS3.word19)); IS3.word19 = IS3.word19 >> 2;
    inputs.setInput78(getInputState(IS3.word19)); IS3.word19 = IS3.word19 >> 2;
    inputs.setInput79(getInputState(IS3.word19)); IS3.word19 = IS3.word19 >> 2;
    inputs.setInput80(getInputState(IS3.word19));

    printf("    word20 \t%02x\n", IS3.word20);
    inputs.setInput81(getInputState(IS3.word20)); IS3.word20 = IS3.word20 >> 2;
    inputs.setInput82(getInputState(IS3.word20)); IS3.word20 = IS3.word20 >> 2;
    inputs.setInput83(getInputState(IS3.word20)); IS3.word20 = IS3.word20 >> 2;
    inputs.setInput84(getInputState(IS3.word20));

    printf("    word21 \t%02x\n", IS3.word21);
    inputs.setInput85(getInputState(IS3.word21)); IS3.word21 = IS3.word21 >> 2;
    inputs.setInput86(getInputState(IS3.word21)); IS3.word21 = IS3.word21 >> 2;
    inputs.setInput87(getInputState(IS3.word21)); IS3.word21 = IS3.word21 >> 2;
    inputs.setInput88(getInputState(IS3.word21));

    printf("    word22 \t%02x\n", IS3.word22);
    inputs.setInput89(getInputState(IS3.word22)); IS3.word22 = IS3.word22 >> 2;
    inputs.setInput90(getInputState(IS3.word22)); IS3.word22 = IS3.word22 >> 2;
    inputs.setInput91(getInputState(IS3.word22)); IS3.word22 = IS3.word22 >> 2;
    inputs.setInput92(getInputState(IS3.word22));

    printf("    word23 \t%02x\n", IS3.word23);
    inputs.setInput93(getInputState(IS3.word23)); IS3.word23 = IS3.word23 >> 2;
    inputs.setInput94(getInputState(IS3.word23)); IS3.word23 = IS3.word23 >> 2;
    inputs.setInput95(getInputState(IS3.word23)); IS3.word23 = IS3.word23 >> 2;
    inputs.setInput96(getInputState(IS3.word23));

    printf("    word24 \t%02x\n", IS3.word24);
    inputs.setInput97(getInputState(IS3.word24)); IS3.word24 = IS3.word24 >> 2;
    inputs.setInput98(getInputState(IS3.word24)); IS3.word24 = IS3.word24 >> 2;
    inputs.setInput99(getInputState(IS3.word24)); IS3.word24 = IS3.word24 >> 2;
    inputs.setInput100(getInputState(IS3.word24));

    printf("    word25 \t%02x\n", IS3.word25);
    inputs.setInput101(getInputState(IS3.word25)); IS3.word25 = IS3.word25 >> 2;
    inputs.setInput102(getInputState(IS3.word25)); IS3.word25 = IS3.word25 >> 2;
    inputs.setInput103(getInputState(IS3.word25)); IS3.word25 = IS3.word25 >> 2;
    inputs.setInput104(getInputState(IS3.word25));

    printf("    word26 \t%02x\n", IS3.word26);
    inputs.setInput105(getInputState(IS3.word26)); IS3.word26 = IS3.word26 >> 2;
    inputs.setInput106(getInputState(IS3.word26)); IS3.word26 = IS3.word26 >> 2;
    inputs.setInput107(getInputState(IS3.word26)); IS3.word26 = IS3.word26 >> 2;
    inputs.setInput108(getInputState(IS3.word26));

    printf("    word27 \t%02x\n", IS3.word27);
    inputs.setInput109(getInputState(IS3.word27)); IS3.word27 = IS3.word27 >> 2;
    inputs.setInput110(getInputState(IS3.word27)); IS3.word27 = IS3.word27 >> 2;
    inputs.setInput111(getInputState(IS3.word27)); IS3.word27 = IS3.word27 >> 2;
    inputs.setInput112(getInputState(IS3.word27));

    printf("    word28 \t%02x\n", IS3.word28);
    inputs.setInput113(getInputState(IS3.word28)); IS3.word28 = IS3.word28 >> 2;
    inputs.setInput114(getInputState(IS3.word28)); IS3.word28 = IS3.word28 >> 2;
    inputs.setInput115(getInputState(IS3.word28)); IS3.word28 = IS3.word28 >> 2;
    inputs.setInput116(getInputState(IS3.word28));

    printf("    word29 \t%02x\n", IS3.word29);
    inputs.setInput117(getInputState(IS3.word29)); IS3.word29 = IS3.word29 >> 2;
    inputs.setInput118(getInputState(IS3.word29)); IS3.word29 = IS3.word29 >> 2;
    inputs.setInput119(getInputState(IS3.word29)); IS3.word29 = IS3.word29 >> 2;
    inputs.setInput120(getInputState(IS3.word29));

    printf("    word30 \t%02x\n", IS3.word30);
    inputs.setInput121(getInputState(IS3.word30)); IS3.word30 = IS3.word30 >> 2;
    inputs.setInput122(getInputState(IS3.word30)); IS3.word30 = IS3.word30 >> 2;
    inputs.setInput123(getInputState(IS3.word30)); IS3.word30 = IS3.word30 >> 2;
    inputs.setInput124(getInputState(IS3.word30));

    printf("        cs \t%02x\n", IS3.cs);
}

void FormingIM_pvkp::parsingIS4(_is4 &IS4)
{
    printf("    header \t%02x\n", IS4.header);
    printf("   managed \t%02x\n", IS4.managed);

    printf("   state00 \t%02x\n", IS4.state00);
    outputs.setOutput1(getOutputState(IS4.state00)); IS4.state00 = IS4.state00 >> 2;
    outputs.setOutput2(getOutputState(IS4.state00)); IS4.state00 = IS4.state00 >> 2;
    outputs.setOutput3(getOutputState(IS4.state00)); IS4.state00 = IS4.state00 >> 2;
    outputs.setOutput4(getOutputState(IS4.state00));

    printf("   state01 \t%02x\n", IS4.state01);
    outputs.setOutput5(getOutputState(IS4.state01)); IS4.state01 = IS4.state01 >> 2;
    outputs.setOutput6(getOutputState(IS4.state01)); IS4.state01 = IS4.state01 >> 2;
    outputs.setOutput7(getOutputState(IS4.state01)); IS4.state01 = IS4.state01 >> 2;
    outputs.setOutput8(getOutputState(IS4.state01));

    printf("   state02 \t%02x\n", IS4.state02);
    outputs.setOutput9(getOutputState(IS4.state02)); IS4.state02 = IS4.state02 >> 2;
    outputs.setOutput10(getOutputState(IS4.state02)); IS4.state02 = IS4.state02 >> 2;
    outputs.setOutput11(getOutputState(IS4.state02)); IS4.state02 = IS4.state02 >> 2;
    outputs.setOutput12(getOutputState(IS4.state02));

    printf("   state03 \t%02x\n", IS4.state03);
    outputs.setOutput13(getOutputState(IS4.state03)); IS4.state03 = IS4.state03 >> 2;
    outputs.setOutput14(getOutputState(IS4.state03)); IS4.state03 = IS4.state03 >> 2;
    outputs.setOutput15(getOutputState(IS4.state03)); IS4.state03 = IS4.state03 >> 2;
    outputs.setOutput16(getOutputState(IS4.state03));

    printf("   state04 \t%02x\n", IS4.state04);
    outputs.setOutput17(getOutputState(IS4.state04)); IS4.state04 = IS4.state04 >> 2;
    outputs.setOutput18(getOutputState(IS4.state04)); IS4.state04 = IS4.state04 >> 2;
    outputs.setOutput19(getOutputState(IS4.state04)); IS4.state04 = IS4.state04 >> 2;
    outputs.setOutput20(getOutputState(IS4.state04));

    printf("   state05 \t%02x\n", IS4.state05);
    outputs.setOutput21(getOutputState(IS4.state05)); IS4.state05 = IS4.state05 >> 2;
    outputs.setOutput22(getOutputState(IS4.state05)); IS4.state05 = IS4.state05 >> 2;
    outputs.setOutput23(getOutputState(IS4.state05)); IS4.state05 = IS4.state05 >> 2;
    outputs.setOutput24(getOutputState(IS4.state05));

    printf("   state06 \t%02x\n", IS4.state06);
    outputs.setOutput25(getOutputState(IS4.state06)); IS4.state06 = IS4.state06 >> 2;
    outputs.setOutput26(getOutputState(IS4.state06)); IS4.state06 = IS4.state06 >> 2;
    outputs.setOutput27(getOutputState(IS4.state06)); IS4.state06 = IS4.state06 >> 2;
    outputs.setOutput28(getOutputState(IS4.state06));

    printf("   state07 \t%02x\n", IS4.state07);
    outputs.setOutput29(getOutputState(IS4.state07)); IS4.state07 = IS4.state07 >> 2;
    outputs.setOutput30(getOutputState(IS4.state07)); IS4.state07 = IS4.state07 >> 2;
    outputs.setOutput31(getOutputState(IS4.state07)); IS4.state07 = IS4.state07 >> 2;
    outputs.setOutput32(getOutputState(IS4.state07));

    printf("   state08 \t%02x\n", IS4.state08);
    outputs.setOutput33(getOutputState(IS4.state08)); IS4.state08 = IS4.state08 >> 2;
    outputs.setOutput34(getOutputState(IS4.state08)); IS4.state08 = IS4.state08 >> 2;
    outputs.setOutput35(getOutputState(IS4.state08)); IS4.state08 = IS4.state08 >> 2;
    outputs.setOutput36(getOutputState(IS4.state08));

    printf("   state09 \t%02x\n", IS4.state09);
    outputs.setOutput37(getOutputState(IS4.state09)); IS4.state09 = IS4.state09 >> 2;
    outputs.setOutput38(getOutputState(IS4.state09)); IS4.state09 = IS4.state09 >> 2;
    outputs.setOutput39(getOutputState(IS4.state09)); IS4.state09 = IS4.state09 >> 2;
    outputs.setOutput40(getOutputState(IS4.state09));

    printf("   state10 \t%02x\n", IS4.state10);
    outputs.setOutput41(getOutputState(IS4.state10)); IS4.state10 = IS4.state10 >> 2;
    outputs.setOutput42(getOutputState(IS4.state10)); IS4.state10 = IS4.state10 >> 2;
    outputs.setOutput43(getOutputState(IS4.state10)); IS4.state10 = IS4.state10 >> 2;
    outputs.setOutput44(getOutputState(IS4.state10));

    printf("   state11 \t%02x\n", IS4.state11);
    outputs.setOutput45(getOutputState(IS4.state11)); IS4.state11 = IS4.state11 >> 2;
    outputs.setOutput46(getOutputState(IS4.state11)); IS4.state11 = IS4.state11 >> 2;
    outputs.setOutput47(getOutputState(IS4.state11)); IS4.state11 = IS4.state11 >> 2;
    outputs.setOutput48(getOutputState(IS4.state11));

    printf("   state12 \t%02x\n", IS4.state12);
    outputs.setOutput49(getOutputState(IS4.state12)); IS4.state12 = IS4.state12 >> 2;
    outputs.setOutput50(getOutputState(IS4.state12)); IS4.state12 = IS4.state12 >> 2;
    outputs.setOutput51(getOutputState(IS4.state12)); IS4.state12 = IS4.state12 >> 2;
    outputs.setOutput52(getOutputState(IS4.state12));

    printf("   state13 \t%02x\n", IS4.state13);
    outputs.setOutput53(getOutputState(IS4.state13)); IS4.state13 = IS4.state13 >> 2;
    outputs.setOutput54(getOutputState(IS4.state13)); IS4.state13 = IS4.state13 >> 2;
    outputs.setOutput55(getOutputState(IS4.state13)); IS4.state13 = IS4.state13 >> 2;
    outputs.setOutput56(getOutputState(IS4.state13));

    printf("   state14 \t%02x\n", IS4.state14);
    outputs.setOutput57(getOutputState(IS4.state14)); IS4.state14 = IS4.state14 >> 2;
    outputs.setOutput58(getOutputState(IS4.state14)); IS4.state14 = IS4.state14 >> 2;
    outputs.setOutput59(getOutputState(IS4.state14)); IS4.state14 = IS4.state14 >> 2;
    outputs.setOutput60(getOutputState(IS4.state14));

    printf("   state15 \t%02x\n", IS4.state15);
    outputs.setOutput61(getOutputState(IS4.state15)); IS4.state15 = IS4.state15 >> 2;
    outputs.setOutput62(getOutputState(IS4.state15));

    printf("        cs \t%02x\n", IS4.cs);
}

unsigned FormingIM_pvkp::getInputState(unsigned char word)
{
    unsigned input = 0x00;

    if ((word & input_state::no_signal_27v) == input_state::no_signal_27v)
    {
        input = input_state::no_signal_27v;
    }
    if ((word & input_state::is_signal_27v) == input_state::is_signal_27v)
    {
        input = input_state::is_signal_27v;
    }
    if ((word & input_state::no_input_state) == input_state::no_input_state)
    {
        input = input_state::no_input_state;
    }

    printInputState(input);
    return input;
}

void FormingIM_pvkp::printInputState(const unsigned &input)
{
    switch (input)
    {
    case input_state::no_signal_27v:
        printf("  input \t%02x %s\n", input, "no_signal_27v");
        break;

    case input_state::is_signal_27v:
        printf("  input \t%02x %s\n", input, "is_signal_27v");
        break;

    case input_state::no_input_state:
        printf("  input \t%02x %s\n", input, "no_input_state");
        break;

    default:
        printf("  input \t%02x %s\n", input, "no data");
        break;
    }
}

unsigned FormingIM_pvkp::getOutputState(unsigned char state)
{
    unsigned output = 0x00;

    if ((state & output_on) == output_on)
    {
        output = output_on;
    }
    if ((state & output_off) == output_off)
    {
        output = output_off;
    }
    if ((state & no_output_state) == no_output_state)
    {
        output = no_output_state;
    }
    if ((state ^ error_output) == error_output)
    {
        output = error_output;
    }

    printOutputState(output);
    return output;
}

void FormingIM_pvkp::printOutputState(const unsigned &output)
{
    switch (output)
    {
    case output_on:
        printf("  output \t%02x %s\n", output, "output_on");
        break;

    case output_off:
        printf("  output \t%02x %s\n", output, "output_off");
        break;

    case no_output_state:
        printf("  output \t%02x %s\n", output, "no_output_state");
        break;

    case error_output:
        printf("  output \t%02x %s\n", output, "error_output");
        break;

    default:
        printf("  output \t%02x %s\n", output, "no data");
        break;
    }
}

_outputs &FormingIM_pvkp::getOutputs()
{
    return outputs;
}

void FormingIM_pvkp::setOutputs(_outputs values)
{
    outputs = values;
}

_inputs &FormingIM_pvkp::getInputs()
{
    return inputs;
}
