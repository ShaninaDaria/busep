#include "hdr/formingIM_busep.h"

FormingIM_busep::FormingIM_busep()
{

}

_is3 *FormingIM_busep::createIS3(input_state state)
{
    bzero(&IS3, (sizeof (_is3)));

    qDebug() << __FUNCTION__ << " IS3";
    IS3.header = header; printf("    header \t%02x\n", IS3.header);
    IS3.managed = response_state; printf("    managed \t%02x\n", IS3.managed);

    manageIO.changeInputs(state);

    IS3.word00 |= manageIO.getInputs().input4(); IS3.word00 = IS3.word00 << 2;
    IS3.word00 |= manageIO.getInputs().input3(); IS3.word00 = IS3.word00 << 2;
    IS3.word00 |= manageIO.getInputs().input2(); IS3.word00 = IS3.word00 << 2;
    IS3.word00 |= manageIO.getInputs().input1();
    printf("    word0 \t%02x\n", IS3.word00);
    qDebug() << "IS3.word00" << IS3.word00;

    IS3.word01 |= manageIO.getInputs().input8(); IS3.word01 = IS3.word01 << 2;
    IS3.word01 |= manageIO.getInputs().input7(); IS3.word01 = IS3.word01 << 2;
    IS3.word01 |= manageIO.getInputs().input6(); IS3.word01 = IS3.word01 << 2;
    IS3.word01 |= manageIO.getInputs().input5();
    printf("    word1 \t%02x\n", IS3.word01);

    IS3.word02 |= manageIO.getInputs().input12(); IS3.word02 = IS3.word02 << 2;
    IS3.word02 |= manageIO.getInputs().input11(); IS3.word02 = IS3.word02 << 2;
    IS3.word02 |= manageIO.getInputs().input10(); IS3.word02 = IS3.word02 << 2;
    IS3.word02 |= manageIO.getInputs().input9();
    printf("    word2 \t%02x\n", IS3.word02);

    IS3.word03 |= manageIO.getInputs().input16(); IS3.word03 = IS3.word03 << 2;
    IS3.word03 |= manageIO.getInputs().input15(); IS3.word03 = IS3.word03 << 2;
    IS3.word03 |= manageIO.getInputs().input14(); IS3.word03 = IS3.word03 << 2;
    IS3.word03 |= manageIO.getInputs().input13();
    printf("    word3 \t%02x\n", IS3.word03);

    IS3.word04 |= manageIO.getInputs().input20(); IS3.word04 = IS3.word04 << 2;
    IS3.word04 |= manageIO.getInputs().input19(); IS3.word04 = IS3.word04 << 2;
    IS3.word04 |= manageIO.getInputs().input18(); IS3.word04 = IS3.word04 << 2;
    IS3.word04 |= manageIO.getInputs().input17();
    printf("    word4 \t%02x\n", IS3.word04);

    IS3.word05 |= manageIO.getInputs().input24(); IS3.word05 = IS3.word05 << 2;
    IS3.word05 |= manageIO.getInputs().input23(); IS3.word05 = IS3.word05 << 2;
    IS3.word05 |= manageIO.getInputs().input22(); IS3.word05 = IS3.word05 << 2;
    IS3.word05 |= manageIO.getInputs().input21();
    printf("    word5 \t%02x\n", IS3.word05);

    IS3.word06 |= manageIO.getInputs().input28(); IS3.word06 = IS3.word06 << 2;
    IS3.word06 |= manageIO.getInputs().input27(); IS3.word06 = IS3.word06 << 2;
    IS3.word06 |= manageIO.getInputs().input26(); IS3.word06 = IS3.word06 << 2;
    IS3.word06 |= manageIO.getInputs().input25();
    printf("    word6 \t%02x\n", IS3.word06);

    IS3.word07 |= manageIO.getInputs().input32(); IS3.word07 = IS3.word07 << 2;
    IS3.word07 |= manageIO.getInputs().input31(); IS3.word07 = IS3.word07 << 2;
    IS3.word07 |= manageIO.getInputs().input30(); IS3.word07 = IS3.word07 << 2;
    IS3.word07 |= manageIO.getInputs().input29();
    printf("    word7 \t%02x\n", IS3.word07);

    IS3.word08 |= manageIO.getInputs().input36(); IS3.word08 = IS3.word08 << 2;
    IS3.word08 |= manageIO.getInputs().input35(); IS3.word08 = IS3.word08 << 2;
    IS3.word08 |= manageIO.getInputs().input34(); IS3.word08 = IS3.word08 << 2;
    IS3.word08 |= manageIO.getInputs().input33();
    printf("    word8 \t%02x\n", IS3.word08);

    IS3.word09 |= manageIO.getInputs().input40(); IS3.word09 = IS3.word09 << 2;
    IS3.word09 |= manageIO.getInputs().input39(); IS3.word09 = IS3.word09 << 2;
    IS3.word09 |= manageIO.getInputs().input38(); IS3.word09 = IS3.word09 << 2;
    IS3.word09 |= manageIO.getInputs().input37();
    printf("    word9 \t%02x\n", IS3.word09);

    IS3.word10 |= manageIO.getInputs().input44(); IS3.word10 = IS3.word10 << 2;
    IS3.word10 |= manageIO.getInputs().input43(); IS3.word10 = IS3.word10 << 2;
    IS3.word10 |= manageIO.getInputs().input42(); IS3.word10 = IS3.word10 << 2;
    IS3.word10 |= manageIO.getInputs().input41();
    printf("    word10 \t%02x\n", IS3.word10);

    IS3.word11 |= manageIO.getInputs().input48(); IS3.word11 = IS3.word11 << 2;
    IS3.word11 |= manageIO.getInputs().input47(); IS3.word11 = IS3.word11 << 2;
    IS3.word11 |= manageIO.getInputs().input46(); IS3.word11 = IS3.word11 << 2;
    IS3.word11 |= manageIO.getInputs().input45();
    printf("    word11 \t%02x\n", IS3.word11);

    IS3.word12 |= manageIO.getInputs().input52(); IS3.word12 = IS3.word12 << 2;
    IS3.word12 |= manageIO.getInputs().input51(); IS3.word12 = IS3.word12 << 2;
    IS3.word12 |= manageIO.getInputs().input50(); IS3.word12 = IS3.word12 << 2;
    IS3.word12 |= manageIO.getInputs().input49();
    printf("    word12 \t%02x\n", IS3.word12);

    IS3.word13 |= manageIO.getInputs().input56(); IS3.word13 = IS3.word13 << 2;
    IS3.word13 |= manageIO.getInputs().input55(); IS3.word13 = IS3.word13 << 2;
    IS3.word13 |= manageIO.getInputs().input54(); IS3.word13 = IS3.word13 << 2;
    IS3.word13 |= manageIO.getInputs().input53();
    printf("    word13 \t%02x\n", IS3.word13);

    IS3.word14 |= manageIO.getInputs().input60(); IS3.word14 = IS3.word14 << 2;
    IS3.word14 |= manageIO.getInputs().input59(); IS3.word14 = IS3.word14 << 2;
    IS3.word14 |= manageIO.getInputs().input58(); IS3.word14 = IS3.word14 << 2;
    IS3.word14 |= manageIO.getInputs().input57();
    printf("    word14 \t%02x\n", IS3.word14);

    IS3.word15 |= manageIO.getInputs().input64(); IS3.word15 = IS3.word15 << 2;
    IS3.word15 |= manageIO.getInputs().input63(); IS3.word15 = IS3.word15 << 2;
    IS3.word15 |= manageIO.getInputs().input62(); IS3.word15 = IS3.word15 << 2;
    IS3.word15 |= manageIO.getInputs().input61();
    printf("    word15 \t%02x\n", IS3.word15);

    IS3.word16 |= manageIO.getInputs().input68(); IS3.word16 = IS3.word16 << 2;
    IS3.word16 |= manageIO.getInputs().input67(); IS3.word16 = IS3.word16 << 2;
    IS3.word16 |= manageIO.getInputs().input66(); IS3.word16 = IS3.word16 << 2;
    IS3.word16 |= manageIO.getInputs().input65();
    printf("    word16 \t%02x\n", IS3.word16);

    IS3.word17 |= manageIO.getInputs().input72(); IS3.word17 = IS3.word17 << 2;
    IS3.word17 |= manageIO.getInputs().input71(); IS3.word17 = IS3.word17 << 2;
    IS3.word17 |= manageIO.getInputs().input70(); IS3.word17 = IS3.word17 << 2;
    IS3.word17 |= manageIO.getInputs().input69();
    printf("    word17 \t%02x\n", IS3.word17);

    IS3.word18 |= manageIO.getInputs().input76(); IS3.word18 = IS3.word18 << 2;
    IS3.word18 |= manageIO.getInputs().input75(); IS3.word18 = IS3.word18 << 2;
    IS3.word18 |= manageIO.getInputs().input74(); IS3.word18 = IS3.word18 << 2;
    IS3.word18 |= manageIO.getInputs().input73();
    printf("    word18 \t%02x\n", IS3.word18);

    IS3.word19 |= manageIO.getInputs().input80(); IS3.word19 = IS3.word19 << 2;
    IS3.word19 |= manageIO.getInputs().input79(); IS3.word19 = IS3.word19 << 2;
    IS3.word19 |= manageIO.getInputs().input78(); IS3.word19 = IS3.word19 << 2;
    IS3.word19 |= manageIO.getInputs().input77();
    printf("    word19 \t%02x\n", IS3.word19);

    IS3.word20 |= manageIO.getInputs().input84(); IS3.word20 = IS3.word20 << 2;
    IS3.word20 |= manageIO.getInputs().input83(); IS3.word20 = IS3.word20 << 2;
    IS3.word20 |= manageIO.getInputs().input82(); IS3.word20 = IS3.word20 << 2;
    IS3.word20 |= manageIO.getInputs().input81();
    printf("    word20 \t%02x\n", IS3.word20);

    IS3.word21 |= manageIO.getInputs().input88(); IS3.word21 = IS3.word21 << 2;
    IS3.word21 |= manageIO.getInputs().input87(); IS3.word21 = IS3.word21 << 2;
    IS3.word21 |= manageIO.getInputs().input86(); IS3.word21 = IS3.word21 << 2;
    IS3.word21 |= manageIO.getInputs().input85();
    printf("    word21 \t%02x\n", IS3.word21);

    IS3.word22 |= manageIO.getInputs().input92(); IS3.word22 = IS3.word22 << 2;
    IS3.word22 |= manageIO.getInputs().input91(); IS3.word22 = IS3.word22 << 2;
    IS3.word22 |= manageIO.getInputs().input90(); IS3.word22 = IS3.word22 << 2;
    IS3.word22 |= manageIO.getInputs().input89();
    printf("    word22 \t%02x\n", IS3.word22);

    IS3.word23 |= manageIO.getInputs().input96(); IS3.word23 = IS3.word23 << 2;
    IS3.word23 |= manageIO.getInputs().input95(); IS3.word23 = IS3.word23 << 2;
    IS3.word23 |= manageIO.getInputs().input94(); IS3.word23 = IS3.word23 << 2;
    IS3.word23 |= manageIO.getInputs().input93();
    printf("    word23 \t%02x\n", IS3.word23);

    IS3.word24 |= manageIO.getInputs().input100(); IS3.word24 = IS3.word24 << 2;
    IS3.word24 |= manageIO.getInputs().input99(); IS3.word24 = IS3.word24 << 2;
    IS3.word24 |= manageIO.getInputs().input98(); IS3.word24 = IS3.word24 << 2;
    IS3.word24 |= manageIO.getInputs().input97();
    printf("    word24 \t%02x\n", IS3.word24);

    IS3.word25 |= manageIO.getInputs().input104(); IS3.word25 = IS3.word25 << 2;
    IS3.word25 |= manageIO.getInputs().input103(); IS3.word25 = IS3.word25 << 2;
    IS3.word25 |= manageIO.getInputs().input102(); IS3.word25 = IS3.word25 << 2;
    IS3.word25 |= manageIO.getInputs().input101();
    printf("    word25 \t%02x\n", IS3.word25);

    IS3.word26 |= manageIO.getInputs().input108(); IS3.word26 = IS3.word26 << 2;
    IS3.word26 |= manageIO.getInputs().input107(); IS3.word26 = IS3.word26 << 2;
    IS3.word26 |= manageIO.getInputs().input106(); IS3.word26 = IS3.word26 << 2;
    IS3.word26 |= manageIO.getInputs().input105();
    printf("    word26 \t%02x\n", IS3.word26);

    IS3.word27 |= manageIO.getInputs().input112(); IS3.word27 = IS3.word27 << 2;
    IS3.word27 |= manageIO.getInputs().input111(); IS3.word27 = IS3.word27 << 2;
    IS3.word27 |= manageIO.getInputs().input110(); IS3.word27 = IS3.word27 << 2;
    IS3.word27 |= manageIO.getInputs().input109();
    printf("    word27 \t%02x\n", IS3.word27);

    IS3.word28 |= manageIO.getInputs().input116(); IS3.word28 = IS3.word28 << 2;
    IS3.word28 |= manageIO.getInputs().input115(); IS3.word28 = IS3.word28 << 2;
    IS3.word28 |= manageIO.getInputs().input114(); IS3.word28 = IS3.word28 << 2;
    IS3.word28 |= manageIO.getInputs().input113();
    printf("    word28 \t%02x\n", IS3.word28);

    IS3.word29 |= manageIO.getInputs().input120(); IS3.word29 = IS3.word29 << 2;
    IS3.word29 |= manageIO.getInputs().input119(); IS3.word29 = IS3.word29 << 2;
    IS3.word29 |= manageIO.getInputs().input118(); IS3.word29 = IS3.word29 << 2;
    IS3.word29 |= manageIO.getInputs().input117();
    printf("    word29 \t%02x\n", IS3.word29);

    IS3.word30 |= manageIO.getInputs().input124(); IS3.word30 = IS3.word30 << 2;
    IS3.word30 |= manageIO.getInputs().input123(); IS3.word30 = IS3.word30 << 2;
    IS3.word30 |= manageIO.getInputs().input122(); IS3.word30 = IS3.word30 << 2;
    IS3.word30 |= manageIO.getInputs().input121();
    printf("    word30 \t%02x\n", IS3.word30);

    IS3.cs = 0x00;
    printf("    cs \t%02x\n", IS3.cs);


    qDebug() << "-----\n";

    return &IS3;
}

_is4 *FormingIM_busep::createIS4(char device_number, unsigned char cnrtl)
{
    bzero(&IS4, (sizeof (_is4)));

    qDebug() << "IS4";
    IS4.header = header; printf("    header \t%02x\n", IS4.header);
    IS4.managed = response_change; printf("    managed \t%02x\n", IS4.managed);

    // записываю в "номер входа - 1"
    manageIO.changeOutputs(device_number, cnrtl);

    // посылаю как есть - с нулевого входа
    IS4.state00 |= manageIO.getOutputs2()[3]; IS4.state00 = IS4.state00 << 2;
    IS4.state00 |= manageIO.getOutputs2()[2]; IS4.state00 = IS4.state00 << 2;
    IS4.state00 |= manageIO.getOutputs2()[1]; IS4.state00 = IS4.state00 << 2;
    IS4.state00 |= manageIO.getOutputs2()[0];
    printf("    state00 \t%02x\n", IS4.state00);

    IS4.state01 |= manageIO.getOutputs2()[7]; IS4.state01 = IS4.state01 << 2;
    IS4.state01 |= manageIO.getOutputs2()[6]; IS4.state01 = IS4.state01 << 2;
    IS4.state01 |= manageIO.getOutputs2()[5]; IS4.state01 = IS4.state01 << 2;
    IS4.state01 |= manageIO.getOutputs2()[5];
    printf("    state01 \t%02x\n", IS4.state01);

    IS4.state02 |= manageIO.getOutputs2()[11]; IS4.state02 = IS4.state02 << 2;
    IS4.state02 |= manageIO.getOutputs2()[10]; IS4.state02 = IS4.state02 << 2;
    IS4.state02 |= manageIO.getOutputs2()[9]; IS4.state02 = IS4.state02 << 2;
    IS4.state02 |= manageIO.getOutputs2()[8];
    printf("    state02 \t%02x\n", IS4.state02);

    IS4.state03 |= manageIO.getOutputs2()[15]; IS4.state03 = IS4.state03 << 2;
    IS4.state03 |= manageIO.getOutputs2()[14]; IS4.state03 = IS4.state03 << 2;
    IS4.state03 |= manageIO.getOutputs2()[13]; IS4.state03 = IS4.state03 << 2;
    IS4.state03 |= manageIO.getOutputs2()[12];
    printf("    state03 \t%02x\n", IS4.state03);

    IS4.state04 |= manageIO.getOutputs2()[19]; IS4.state04 = IS4.state04 << 2;
    IS4.state04 |= manageIO.getOutputs2()[18]; IS4.state04 = IS4.state04 << 2;
    IS4.state04 |= manageIO.getOutputs2()[17]; IS4.state04 = IS4.state04 << 2;
    IS4.state04 |= manageIO.getOutputs2()[16];
    printf("    state04 \t%02x\n", IS4.state04);

    IS4.state05 |= manageIO.getOutputs2()[23]; IS4.state05 = IS4.state05 << 2;
    IS4.state05 |= manageIO.getOutputs2()[22]; IS4.state05 = IS4.state05 << 2;
    IS4.state05 |= manageIO.getOutputs2()[21]; IS4.state05 = IS4.state05 << 2;
    IS4.state05 |= manageIO.getOutputs2()[20];
    printf("    state05 \t%02x\n", IS4.state05);

    IS4.state06 |= manageIO.getOutputs2()[27]; IS4.state06 = IS4.state06 << 2;
    IS4.state06 |= manageIO.getOutputs2()[26]; IS4.state06 = IS4.state06 << 2;
    IS4.state06 |= manageIO.getOutputs2()[25]; IS4.state06 = IS4.state06 << 2;
    IS4.state06 |= manageIO.getOutputs2()[24];
    printf("    state06 \t%02x\n", IS4.state06);

    IS4.state07 |= manageIO.getOutputs2()[31]; IS4.state07 = IS4.state07 << 2;
    IS4.state07 |= manageIO.getOutputs2()[30]; IS4.state07 = IS4.state07 << 2;
    IS4.state07 |= manageIO.getOutputs2()[29]; IS4.state07 = IS4.state07 << 2;
    IS4.state07 |= manageIO.getOutputs2()[28];
    printf("    state07 \t%02x\n", IS4.state07);

    IS4.state08 |= manageIO.getOutputs2()[35]; IS4.state08 = IS4.state08 << 2;
    IS4.state08 |= manageIO.getOutputs2()[34]; IS4.state08 = IS4.state08 << 2;
    IS4.state08 |= manageIO.getOutputs2()[33]; IS4.state08 = IS4.state08 << 2;
    IS4.state08 |= manageIO.getOutputs2()[32];
    printf("    state08 \t%02x\n", IS4.state08);

    IS4.state09 |= manageIO.getOutputs2()[39]; IS4.state09 = IS4.state09 << 2;
    IS4.state09 |= manageIO.getOutputs2()[38]; IS4.state09 = IS4.state09 << 2;
    IS4.state09 |= manageIO.getOutputs2()[37]; IS4.state09 = IS4.state09 << 2;
    IS4.state09 |= manageIO.getOutputs2()[36];
    printf("    state09 \t%02x\n", IS4.state09);

    IS4.state10 |= manageIO.getOutputs2()[43]; IS4.state10 = IS4.state10 << 2;
    IS4.state10 |= manageIO.getOutputs2()[42]; IS4.state10 = IS4.state10 << 2;
    IS4.state10 |= manageIO.getOutputs2()[41]; IS4.state10 = IS4.state10 << 2;
    IS4.state10 |= manageIO.getOutputs2()[40];
    printf("    state10 \t%02x\n", IS4.state10);

    IS4.state11 |= manageIO.getOutputs2()[47]; IS4.state11 = IS4.state11 << 2;
    IS4.state11 |= manageIO.getOutputs2()[46]; IS4.state11 = IS4.state11 << 2;
    IS4.state11 |= manageIO.getOutputs2()[45]; IS4.state11 = IS4.state11 << 2;
    IS4.state11 |= manageIO.getOutputs2()[44];
    printf("    state11 \t%02x\n", IS4.state11);

    IS4.state12 |= manageIO.getOutputs2()[51]; IS4.state12 = IS4.state12 << 2;
    IS4.state12 |= manageIO.getOutputs2()[50]; IS4.state12 = IS4.state12 << 2;
    IS4.state12 |= manageIO.getOutputs2()[49]; IS4.state12 = IS4.state12 << 2;
    IS4.state12 |= manageIO.getOutputs2()[48];
    printf("    state12 \t%02x\n", IS4.state12);

    IS4.state13 |= manageIO.getOutputs2()[55]; IS4.state13 = IS4.state13 << 2;
    IS4.state13 |= manageIO.getOutputs2()[54]; IS4.state13 = IS4.state13 << 2;
    IS4.state13 |= manageIO.getOutputs2()[53]; IS4.state13 = IS4.state13 << 2;
    IS4.state13 |= manageIO.getOutputs2()[52];
    printf("    state13 \t%02x\n", IS4.state13);

    IS4.state14 |= manageIO.getOutputs2()[59]; IS4.state14 = IS4.state14 << 2;
    IS4.state14 |= manageIO.getOutputs2()[58]; IS4.state14 = IS4.state14 << 2;
    IS4.state14 |= manageIO.getOutputs2()[57]; IS4.state14 = IS4.state14 << 2;
    IS4.state14 |= manageIO.getOutputs2()[56];
    printf("    state14 \t%02x\n", IS4.state14);

    IS4.state15 |= manageIO.getOutputs2()[61]; IS4.state15 = IS4.state15 << 2;
    IS4.state15 |= manageIO.getOutputs2()[60];

//    IS4.state15 |= manageIO.getOutputs2()[62]; IS4.state15 = IS4.state15 << 2;
    printf("    state15 \t%02x\n", IS4.state15);

    IS4.cs = 0x00; printf("    cs \t%02x\n", IS4.cs);

    qDebug() << "-----\n";

    return &IS4;
}

void FormingIM_busep::createIS5()
{
    qDebug() << "IS5";
    IS5.header = header; printf("    header \t%02x\n", IS5.header);
    IS5.managed = integrity_violation; printf("    managed \t%02x\n", IS5.managed);
}

void FormingIM_busep::calculateCS()
{

}

bool FormingIM_busep::checkCS(unsigned char _cs)
{
    return true;
}

char *FormingIM_busep::getOutputs()
{
    return manageIO.getOutputs2();
}

output_state FormingIM_busep::getOutputState(int number)
{
    return manageIO.getOutputState(number);
}

_inputs FormingIM_busep::getInputs() const
{
    return manageIO.getInputs();
}
