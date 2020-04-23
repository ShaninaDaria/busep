#include "../../common/hdr/informationmessages.h"

informationMessages::informationMessages()
{

}

_is1 informationMessages::createIS1()
{
    qDebug() << "IS1";
    IS1.header = header_and_managed::header;
    qDebug() << "header" << IS1.header;
    IS1.managed = header_and_managed::request;
    qDebug() << "managed" << IS1.managed;
    IS1.cs = 0x00;
    qDebug() << "cs" << IS1.cs;
    qDebug() << "-----\n";

    return IS1;
}

void informationMessages::createIS2(char number)
{
    qDebug() << "IS2";
    IS2.header = header_and_managed::header; printf("    header \t%02x\n", IS2.header);
    IS2.managed = header_and_managed::change_state; qDebug() << "managed" << IS2.managed;
    IS2.device_number = number; qDebug() << "device_number" << IS2.device_number;
    IS2.state = output_cntrl::cntrl_on; qDebug() << "state" << IS2.state;
    qDebug() << "-----\n";
}

_is3 *informationMessages::createIS3()
{
    qDebug() << "IS3";
    IS3.header = header_and_managed::header; printf("    header \t%02x\n", IS3.header);
    IS3.managed = header_and_managed::response_state; printf("    managed \t%02x\n", IS3.managed);

    inputs = io.changeInputs();

    IS3.word00 |= io.getInputs().input4(); IS3.word00 = IS3.word00 << 2;
    IS3.word00 |= io.getInputs().input3(); IS3.word00 = IS3.word00 << 2;
    IS3.word00 |= io.getInputs().input2(); IS3.word00 = IS3.word00 << 2;
    IS3.word00 |= io.getInputs().input1();
    printf("    word0 \t%02x\n", IS3.word00);

    IS3.word01 |= io.getInputs().input8(); IS3.word01 = IS3.word01 << 2;
    IS3.word01 |= io.getInputs().input7(); IS3.word01 = IS3.word01 << 2;
    IS3.word01 |= io.getInputs().input6(); IS3.word01 = IS3.word01 << 2;
    IS3.word01 |= io.getInputs().input5();
    printf("    word1 \t%02x\n", IS3.word01);

    IS3.word02 |= io.getInputs().input12(); IS3.word02 = IS3.word02 << 2;
    IS3.word02 |= io.getInputs().input11(); IS3.word02 = IS3.word02 << 2;
    IS3.word02 |= io.getInputs().input10(); IS3.word02 = IS3.word02 << 2;
    IS3.word02 |= io.getInputs().input9();
    printf("    word2 \t%02x\n", IS3.word02);

    IS3.word03 |= io.getInputs().input16(); IS3.word03 = IS3.word03 << 2;
    IS3.word03 |= io.getInputs().input15(); IS3.word03 = IS3.word03 << 2;
    IS3.word03 |= io.getInputs().input14(); IS3.word03 = IS3.word03 << 2;
    IS3.word03 |= io.getInputs().input13();
    printf("    word3 \t%02x\n", IS3.word03);

    IS3.word04 |= io.getInputs().input20(); IS3.word04 = IS3.word04 << 2;
    IS3.word04 |= io.getInputs().input19(); IS3.word04 = IS3.word04 << 2;
    IS3.word04 |= io.getInputs().input18(); IS3.word04 = IS3.word04 << 2;
    IS3.word04 |= io.getInputs().input17();
    printf("    word4 \t%02x\n", IS3.word04);

    IS3.word05 |= io.getInputs().input24(); IS3.word05 = IS3.word05 << 2;
    IS3.word05 |= io.getInputs().input23(); IS3.word05 = IS3.word05 << 2;
    IS3.word05 |= io.getInputs().input22(); IS3.word05 = IS3.word05 << 2;
    IS3.word05 |= io.getInputs().input21();
    printf("    word5 \t%02x\n", IS3.word05);

    IS3.word06 |= io.getInputs().input28(); IS3.word06 = IS3.word06 << 2;
    IS3.word06 |= io.getInputs().input27(); IS3.word06 = IS3.word06 << 2;
    IS3.word06 |= io.getInputs().input26(); IS3.word06 = IS3.word06 << 2;
    IS3.word06 |= io.getInputs().input25();
    printf("    word6 \t%02x\n", IS3.word06);

    IS3.word07 |= io.getInputs().input32(); IS3.word07 = IS3.word07 << 2;
    IS3.word07 |= io.getInputs().input31(); IS3.word07 = IS3.word07 << 2;
    IS3.word07 |= io.getInputs().input30(); IS3.word07 = IS3.word07 << 2;
    IS3.word07 |= io.getInputs().input29();
    printf("    word7 \t%02x\n", IS3.word07);

    IS3.word08 |= io.getInputs().input36(); IS3.word08 = IS3.word08 << 2;
    IS3.word08 |= io.getInputs().input35(); IS3.word08 = IS3.word08 << 2;
    IS3.word08 |= io.getInputs().input34(); IS3.word08 = IS3.word08 << 2;
    IS3.word08 |= io.getInputs().input33();
    printf("    word8 \t%02x\n", IS3.word08);

    IS3.word09 |= io.getInputs().input40(); IS3.word09 = IS3.word09 << 2;
    IS3.word09 |= io.getInputs().input39(); IS3.word09 = IS3.word09 << 2;
    IS3.word09 |= io.getInputs().input38(); IS3.word09 = IS3.word09 << 2;
    IS3.word09 |= io.getInputs().input37();
    printf("    word9 \t%02x\n", IS3.word09);

    IS3.word10 |= io.getInputs().input44(); IS3.word10 = IS3.word10 << 2;
    IS3.word10 |= io.getInputs().input43(); IS3.word10 = IS3.word10 << 2;
    IS3.word10 |= io.getInputs().input42(); IS3.word10 = IS3.word10 << 2;
    IS3.word10 |= io.getInputs().input41();
    printf("    word10 \t%02x\n", IS3.word10);

    IS3.word11 |= io.getInputs().input48(); IS3.word11 = IS3.word11 << 2;
    IS3.word11 |= io.getInputs().input47(); IS3.word11 = IS3.word11 << 2;
    IS3.word11 |= io.getInputs().input46(); IS3.word11 = IS3.word11 << 2;
    IS3.word11 |= io.getInputs().input45();
    printf("    word11 \t%02x\n", IS3.word11);

    IS3.word12 |= io.getInputs().input52(); IS3.word12 = IS3.word12 << 2;
    IS3.word12 |= io.getInputs().input51(); IS3.word12 = IS3.word12 << 2;
    IS3.word12 |= io.getInputs().input50(); IS3.word12 = IS3.word12 << 2;
    IS3.word12 |= io.getInputs().input49();
    printf("    word12 \t%02x\n", IS3.word12);

    IS3.word13 |= io.getInputs().input56(); IS3.word13 = IS3.word13 << 2;
    IS3.word13 |= io.getInputs().input55(); IS3.word13 = IS3.word13 << 2;
    IS3.word13 |= io.getInputs().input54(); IS3.word13 = IS3.word13 << 2;
    IS3.word13 |= io.getInputs().input53();
    printf("    word13 \t%02x\n", IS3.word13);

    IS3.word14 |= io.getInputs().input60(); IS3.word14 = IS3.word14 << 2;
    IS3.word14 |= io.getInputs().input59(); IS3.word14 = IS3.word14 << 2;
    IS3.word14 |= io.getInputs().input58(); IS3.word14 = IS3.word14 << 2;
    IS3.word14 |= io.getInputs().input57();
    printf("    word14 \t%02x\n", IS3.word14);

    IS3.word15 |= io.getInputs().input64(); IS3.word15 = IS3.word15 << 2;
    IS3.word15 |= io.getInputs().input63(); IS3.word15 = IS3.word15 << 2;
    IS3.word15 |= io.getInputs().input62(); IS3.word15 = IS3.word15 << 2;
    IS3.word15 |= io.getInputs().input61();
    printf("    word15 \t%02x\n", IS3.word15);

    IS3.word16 |= io.getInputs().input68(); IS3.word16 = IS3.word16 << 2;
    IS3.word16 |= io.getInputs().input67(); IS3.word16 = IS3.word16 << 2;
    IS3.word16 |= io.getInputs().input66(); IS3.word16 = IS3.word16 << 2;
    IS3.word16 |= io.getInputs().input65();
    printf("    word16 \t%02x\n", IS3.word16);

    IS3.word17 |= io.getInputs().input72(); IS3.word17 = IS3.word17 << 2;
    IS3.word17 |= io.getInputs().input71(); IS3.word17 = IS3.word17 << 2;
    IS3.word17 |= io.getInputs().input70(); IS3.word17 = IS3.word17 << 2;
    IS3.word17 |= io.getInputs().input69();
    printf("    word17 \t%02x\n", IS3.word17);

    IS3.word18 |= io.getInputs().input76(); IS3.word18 = IS3.word18 << 2;
    IS3.word18 |= io.getInputs().input75(); IS3.word18 = IS3.word18 << 2;
    IS3.word18 |= io.getInputs().input74(); IS3.word18 = IS3.word18 << 2;
    IS3.word18 |= io.getInputs().input73();
    printf("    word18 \t%02x\n", IS3.word18);

    IS3.word19 |= io.getInputs().input80(); IS3.word19 = IS3.word19 << 2;
    IS3.word19 |= io.getInputs().input79(); IS3.word19 = IS3.word19 << 2;
    IS3.word19 |= io.getInputs().input78(); IS3.word19 = IS3.word19 << 2;
    IS3.word19 |= io.getInputs().input77();
    printf("    word19 \t%02x\n", IS3.word19);

    IS3.word20 |= io.getInputs().input84(); IS3.word20 = IS3.word20 << 2;
    IS3.word20 |= io.getInputs().input83(); IS3.word20 = IS3.word20 << 2;
    IS3.word20 |= io.getInputs().input82(); IS3.word20 = IS3.word20 << 2;
    IS3.word20 |= io.getInputs().input81();
    printf("    word20 \t%02x\n", IS3.word20);

    IS3.word21 |= io.getInputs().input88(); IS3.word21 = IS3.word21 << 2;
    IS3.word21 |= io.getInputs().input87(); IS3.word21 = IS3.word21 << 2;
    IS3.word21 |= io.getInputs().input86(); IS3.word21 = IS3.word21 << 2;
    IS3.word21 |= io.getInputs().input85();
    printf("    word21 \t%02x\n", IS3.word21);

    IS3.word22 |= io.getInputs().input92(); IS3.word22 = IS3.word22 << 2;
    IS3.word22 |= io.getInputs().input91(); IS3.word22 = IS3.word22 << 2;
    IS3.word22 |= io.getInputs().input90(); IS3.word22 = IS3.word22 << 2;
    IS3.word22 |= io.getInputs().input89();
    printf("    word22 \t%02x\n", IS3.word22);

    IS3.word23 |= io.getInputs().input96(); IS3.word23 = IS3.word23 << 2;
    IS3.word23 |= io.getInputs().input95(); IS3.word23 = IS3.word23 << 2;
    IS3.word23 |= io.getInputs().input94(); IS3.word23 = IS3.word23 << 2;
    IS3.word23 |= io.getInputs().input93();
    printf("    word23 \t%02x\n", IS3.word23);

    IS3.word24 |= io.getInputs().input100(); IS3.word24 = IS3.word24 << 2;
    IS3.word24 |= io.getInputs().input99(); IS3.word24 = IS3.word24 << 2;
    IS3.word24 |= io.getInputs().input98(); IS3.word24 = IS3.word24 << 2;
    IS3.word24 |= io.getInputs().input97();
    printf("    word24 \t%02x\n", IS3.word24);

    IS3.word25 |= io.getInputs().input104(); IS3.word25 = IS3.word25 << 2;
    IS3.word25 |= io.getInputs().input103(); IS3.word25 = IS3.word25 << 2;
    IS3.word25 |= io.getInputs().input102(); IS3.word25 = IS3.word25 << 2;
    IS3.word25 |= io.getInputs().input101();
    printf("    word25 \t%02x\n", IS3.word25);

    IS3.word26 |= io.getInputs().input108(); IS3.word26 = IS3.word26 << 2;
    IS3.word26 |= io.getInputs().input107(); IS3.word26 = IS3.word26 << 2;
    IS3.word26 |= io.getInputs().input106(); IS3.word26 = IS3.word26 << 2;
    IS3.word26 |= io.getInputs().input105();
    printf("    word26 \t%02x\n", IS3.word26);

    IS3.word27 |= io.getInputs().input112(); IS3.word27 = IS3.word27 << 2;
    IS3.word27 |= io.getInputs().input111(); IS3.word27 = IS3.word27 << 2;
    IS3.word27 |= io.getInputs().input110(); IS3.word27 = IS3.word27 << 2;
    IS3.word27 |= io.getInputs().input109();
    printf("    word27 \t%02x\n", IS3.word27);

    IS3.word28 |= io.getInputs().input116(); IS3.word28 = IS3.word28 << 2;
    IS3.word28 |= io.getInputs().input115(); IS3.word28 = IS3.word28 << 2;
    IS3.word28 |= io.getInputs().input114(); IS3.word28 = IS3.word28 << 2;
    IS3.word28 |= io.getInputs().input113();
    printf("    word28 \t%02x\n", IS3.word28);

    IS3.word29 |= io.getInputs().input120(); IS3.word29 = IS3.word29 << 2;
    IS3.word29 |= io.getInputs().input119(); IS3.word29 = IS3.word29 << 2;
    IS3.word29 |= io.getInputs().input118(); IS3.word29 = IS3.word29 << 2;
    IS3.word29 |= io.getInputs().input117();
    printf("    word29 \t%02x\n", IS3.word29);

    IS3.word30 |= io.getInputs().input124(); IS3.word30 = IS3.word30 << 2;
    IS3.word30 |= io.getInputs().input123(); IS3.word30 = IS3.word30 << 2;
    IS3.word30 |= io.getInputs().input122(); IS3.word30 = IS3.word30 << 2;
    IS3.word30 |= io.getInputs().input121();
    printf("    word30 \t%02x\n", IS3.word30);

    IS3.cs = 0x00;
    printf("    cs \t%02x\n", IS3.cs);


    qDebug() << "-----\n";

    return &IS3;
}

void informationMessages::createIS4()
{
    qDebug() << "IS4";
    IS4.header = header_and_managed::header;
    qDebug() << "header" << IS3.header;
    IS4.managed = 0x03;
    qDebug() << "managed" << IS3.managed;

    io.changeOutputs();

    IS4.state0 |= io.getOutputs().output4();
    IS4.state0 = IS4.state0 << 2;
    IS4.state0 |= io.getOutputs().output3();
    IS4.state0 = IS4.state0 << 2;
    IS4.state0 |= io.getOutputs().output2();
    IS4.state0 = IS4.state0 << 2;
    IS4.state0 |= io.getOutputs().output1();
    qDebug() << "state0" << IS4.state0;

    IS4.state1 |= io.getOutputs().output8();
    IS4.state1 = IS4.state1 << 2;
    IS4.state1 |= io.getOutputs().output7();
    IS4.state1 = IS4.state1 << 2;
    IS4.state1 |= io.getOutputs().output6();
    IS4.state1 = IS4.state1 << 2;
    IS4.state1 |= io.getOutputs().output5();
    qDebug() << "state1" << IS4.state1;

    IS4.state2 |= io.getOutputs().output12();
    IS4.state2 = IS4.state2 << 2;
    IS4.state2 |= io.getOutputs().output11();
    IS4.state2 = IS4.state2 << 2;
    IS4.state2 |= io.getOutputs().output10();
    IS4.state2 = IS4.state2 << 2;
    IS4.state2 |= io.getOutputs().output9();
    qDebug() << "state2" << IS4.state2;

    IS4.state3 |= io.getOutputs().output16();
    IS4.state3 = IS4.state3 << 2;
    IS4.state3 |= io.getOutputs().output15();
    IS4.state3 = IS4.state3 << 2;
    IS4.state3 |= io.getOutputs().output14();
    IS4.state3 = IS4.state3 << 2;
    IS4.state3 |= io.getOutputs().output13();
    qDebug() << "state3" << IS4.state3;

    IS4.state4 |= io.getOutputs().output20();
    IS4.state4 = IS4.state4 << 2;
    IS4.state4 |= io.getOutputs().output19();
    IS4.state4 = IS4.state4 << 2;
    IS4.state4 |= io.getOutputs().output18();
    IS4.state4 = IS4.state4 << 2;
    IS4.state4 |= io.getOutputs().output17();
    qDebug() << "state4" << IS4.state4;

    IS4.state5 |= io.getOutputs().output24();
    IS4.state5 = IS4.state5 << 2;
    IS4.state5 |= io.getOutputs().output23();
    IS4.state5 = IS4.state5 << 2;
    IS4.state5 |= io.getOutputs().output22();
    IS4.state5 = IS4.state5 << 2;
    IS4.state5 |= io.getOutputs().output21();
    qDebug() << "state5" << IS4.state5;

    IS4.state6 |= io.getOutputs().output28();
    IS4.state6 = IS4.state5 << 2;
    IS4.state6 |= io.getOutputs().output27();
    IS4.state6 = IS4.state5 << 2;
    IS4.state6 |= io.getOutputs().output26();
    IS4.state6 = IS4.state5 << 2;
    IS4.state6 |= io.getOutputs().output25();
    qDebug() << "state5" << IS4.state5;

    IS4.state7 |= io.getOutputs().output32();
    IS4.state7 = IS4.state7 << 2;
    IS4.state7 |= io.getOutputs().output31();
    IS4.state7 = IS4.state7 << 2;
    IS4.state7 |= io.getOutputs().output30();
    IS4.state7 = IS4.state7 << 2;
    IS4.state7 |= io.getOutputs().output29();
    qDebug() << "state7" << IS4.state7;

    IS4.state8 |= io.getOutputs().output36();
    IS4.state8 = IS4.state8 << 2;
    IS4.state8 |= io.getOutputs().output35();
    IS4.state8 = IS4.state8 << 2;
    IS4.state8 |= io.getOutputs().output34();
    IS4.state8 = IS4.state8 << 2;
    IS4.state8 |= io.getOutputs().output33();
    qDebug() << "state8" << IS4.state8;

    IS4.state9 |= io.getOutputs().output40();
    IS4.state9 = IS4.state9 << 2;
    IS4.state9 |= io.getOutputs().output39();
    IS4.state9 = IS4.state9 << 2;
    IS4.state9 |= io.getOutputs().output38();
    IS4.state9 = IS4.state9 << 2;
    IS4.state9 |= io.getOutputs().output37();
    qDebug() << "state9" << IS4.state9;

    IS4.state10 |= io.getOutputs().output44();
    IS4.state10 = IS4.state10 << 2;
    IS4.state10 |= io.getOutputs().output43();
    IS4.state10 = IS4.state10 << 2;
    IS4.state10 |= io.getOutputs().output42();
    IS4.state10 = IS4.state10 << 2;
    IS4.state10 |= io.getOutputs().output41();
    qDebug() << "state10" << IS4.state10;

    IS4.state11 |= io.getOutputs().output48();
    IS4.state11 = IS4.state11 << 2;
    IS4.state11 |= io.getOutputs().output47();
    IS4.state11 = IS4.state11 << 2;
    IS4.state11 |= io.getOutputs().output46();
    IS4.state11 = IS4.state11 << 2;
    IS4.state11 |= io.getOutputs().output45();
    qDebug() << "state11" << IS4.state11;

    IS4.state12 |= io.getOutputs().output52();
    IS4.state12 = IS4.state12 << 2;
    IS4.state12 |= io.getOutputs().output51();
    IS4.state12 = IS4.state12 << 2;
    IS4.state12 |= io.getOutputs().output50();
    IS4.state12 = IS4.state12 << 2;
    IS4.state12 |= io.getOutputs().output49();
    qDebug() << "state12" << IS4.state12;

    IS4.state13 |= io.getOutputs().output56();
    IS4.state13 = IS4.state13 << 2;
    IS4.state13 |= io.getOutputs().output55();
    IS4.state13 = IS4.state13 << 2;
    IS4.state13 |= io.getOutputs().output54();
    IS4.state13 = IS4.state13 << 2;
    IS4.state13 |= io.getOutputs().output53();
    qDebug() << "state13" << IS4.state13;

    IS4.state14 |= io.getOutputs().output60();
    IS4.state14 = IS4.state14 << 2;
    IS4.state14 |= io.getOutputs().output59();
    IS4.state14 = IS4.state14 << 2;
    IS4.state14 |= io.getOutputs().output58();
    IS4.state14 = IS4.state14 << 2;
    IS4.state14 |= io.getOutputs().output57();
    qDebug() << "state14" << IS4.state14;

    IS4.state15 |= io.getOutputs().output62();
    IS4.state15 = IS4.state15 << 2;
    IS4.state15 |= io.getOutputs().output61();
    qDebug() << "state15" << IS4.state15;

    qDebug() << "-----\n";
}

void informationMessages::createIS5()
{
    qDebug() << "IS5";
    IS5.header = header_and_managed::header;
    qDebug() << "header" << IS3.header;
    IS5.managed = 0x09;
    qDebug() << "managed" << IS3.managed;
}

_is1 informationMessages::getIS1() const
{
    return IS1;
}

_is2 informationMessages::getIS2() const
{
    return IS2;
}

void informationMessages::setIS3(const _is3 &value)
{
    IS3 = value;
    parsingIS3(IS3);
}

void informationMessages::setIS4(const _is4 &value)
{
    IS4 = value;
}

void informationMessages::parsingIS3(_is3 &IS3)
{
    printf("    header \t%02x\n", IS3.header);
    printf("  managed \t%02x\n", IS3.managed);

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

unsigned informationMessages::getInputState(unsigned char word)
{
    unsigned input = 0x00;

    if ((word & input_state::no_signal_27v) == input_state::no_signal_27v)
    {
        input = input_state::no_signal_27v;
    }
    if ((word & input_state::is_signal_27v) == input_state::is_signal_27v)
    {
        input = (input_state::is_signal_27v);
    }
    if ((word & input_state::no_input_state) == input_state::no_input_state)
    {
        input = (input_state::no_input_state);
    }

    printInputState(input);
    return input;
}

void informationMessages::printInputState(const unsigned &input)
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
        printf("  input1 \t%02x %s\n", input, "no data");
        break;
    }
}
