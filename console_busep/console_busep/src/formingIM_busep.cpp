#include "hdr/formingIM_busep.h"

FormingIM_busep::FormingIM_busep()
{

}

_is3 *FormingIM_busep::createIS3(input_state state)
{
    bzero(&IS3, (sizeof (_is3)));

    qDebug() << __FUNCTION__ << state;
    IS3.header = header; // printf("    header \t%02x\n", IS3.header);
    IS3.managed = response_state; // printf("    managed \t%02x\n", IS3.managed);
    // printf("    state \t%02x\n", state);

    manageIO.changeInputs(all_inputs, state);
    setWordsIS3(IS3);

    IS3.crc = im.calculateCRC(&IS3, sizeof (_is3)); // printf("    crc \t%02x\n", IS3.crc);

    qDebug() << "   header" << IS3.header;
    qDebug() << "  managed" << IS3.managed;
    qDebug() << "   inputs" << all_inputs;
    qDebug() << "    state" << state;
    qDebug() << "      crc" << IS3.crc;

    return &IS3;
}


void FormingIM_busep::setWordsIS3(_is3 &IS3)
{
    IS3.word00 |= manageIO.getInputs2()[3]; IS3.word00 = IS3.word00 << 2;
    IS3.word00 |= manageIO.getInputs2()[2]; IS3.word00 = IS3.word00 << 2;
    IS3.word00 |= manageIO.getInputs2()[1]; IS3.word00 = IS3.word00 << 2;
    IS3.word00 |= manageIO.getInputs2()[0];
//    printf("    word0 \t%02x\n", IS3.word00);

    IS3.word01 |= manageIO.getInputs2()[7]; IS3.word01 = IS3.word01 << 2;
    IS3.word01 |= manageIO.getInputs2()[6]; IS3.word01 = IS3.word01 << 2;
    IS3.word01 |= manageIO.getInputs2()[5]; IS3.word01 = IS3.word00 << 2;
    IS3.word01 |= manageIO.getInputs2()[4];
//    printf("    word1 \t%02x\n", IS3.word01);

    IS3.word02 |= manageIO.getInputs2()[11]; IS3.word02 = IS3.word02 << 2;
    IS3.word02 |= manageIO.getInputs2()[10]; IS3.word02 = IS3.word02 << 2;
    IS3.word02 |= manageIO.getInputs2()[9]; IS3.word02 = IS3.word02 << 2;
    IS3.word02 |= manageIO.getInputs2()[8];
//    printf("    word2 \t%02x\n", IS3.word02);

    IS3.word03 |= manageIO.getInputs2()[15]; IS3.word03 = IS3.word03 << 2;
    IS3.word03 |= manageIO.getInputs2()[14]; IS3.word03 = IS3.word03 << 2;
    IS3.word03 |= manageIO.getInputs2()[13]; IS3.word03 = IS3.word03 << 2;
    IS3.word03 |= manageIO.getInputs2()[12];
//    printf("    word3 \t%02x\n", IS3.word03);

    IS3.word04 |= manageIO.getInputs2()[19]; IS3.word04 = IS3.word04 << 2;
    IS3.word04 |= manageIO.getInputs2()[18]; IS3.word04 = IS3.word04 << 2;
    IS3.word04 |= manageIO.getInputs2()[17]; IS3.word04 = IS3.word04 << 2;
    IS3.word04 |= manageIO.getInputs2()[16];
//    printf("    word4 \t%02x\n", IS3.word04);

    IS3.word05 |= manageIO.getInputs2()[23]; IS3.word05 = IS3.word05 << 2;
    IS3.word05 |= manageIO.getInputs2()[22]; IS3.word05 = IS3.word05 << 2;
    IS3.word05 |= manageIO.getInputs2()[21]; IS3.word05 = IS3.word05 << 2;
    IS3.word05 |= manageIO.getInputs2()[20];
//    printf("    word5 \t%02x\n", IS3.word05);

    IS3.word06 |= manageIO.getInputs2()[27]; IS3.word06 = IS3.word06 << 2;
    IS3.word06 |= manageIO.getInputs2()[26]; IS3.word06 = IS3.word06 << 2;
    IS3.word06 |= manageIO.getInputs2()[25]; IS3.word06 = IS3.word06 << 2;
    IS3.word06 |= manageIO.getInputs2()[24];
//    printf("    word6 \t%02x\n", IS3.word06);

    IS3.word07 |= manageIO.getInputs2()[31]; IS3.word07 = IS3.word07 << 2;
    IS3.word07 |= manageIO.getInputs2()[30]; IS3.word07 = IS3.word07 << 2;
    IS3.word07 |= manageIO.getInputs2()[29]; IS3.word07 = IS3.word07 << 2;
    IS3.word07 |= manageIO.getInputs2()[28];
//    printf("    word7 \t%02x\n", IS3.word07);

    IS3.word08 |= manageIO.getInputs2()[35]; IS3.word08 = IS3.word08 << 2;
    IS3.word08 |= manageIO.getInputs2()[34]; IS3.word08 = IS3.word08 << 2;
    IS3.word08 |= manageIO.getInputs2()[33]; IS3.word08 = IS3.word08 << 2;
    IS3.word08 |= manageIO.getInputs2()[32];
//    printf("    word8 \t%02x\n", IS3.word08);

    IS3.word09 |= manageIO.getInputs2()[39]; IS3.word09 = IS3.word09 << 2;
    IS3.word09 |= manageIO.getInputs2()[38]; IS3.word09 = IS3.word09 << 2;
    IS3.word09 |= manageIO.getInputs2()[37]; IS3.word09 = IS3.word09 << 2;
    IS3.word09 |= manageIO.getInputs2()[36];
//    printf("    word9 \t%02x\n", IS3.word09);

    IS3.word10 |= manageIO.getInputs2()[43]; IS3.word10 = IS3.word10 << 2;
    IS3.word10 |= manageIO.getInputs2()[42]; IS3.word10 = IS3.word10 << 2;
    IS3.word10 |= manageIO.getInputs2()[41]; IS3.word10 = IS3.word10 << 2;
    IS3.word10 |= manageIO.getInputs2()[40];
//    printf("    word10 \t%02x\n", IS3.word10);

    IS3.word11 |= manageIO.getInputs2()[47]; IS3.word11 = IS3.word11 << 2;
    IS3.word11 |= manageIO.getInputs2()[46]; IS3.word11 = IS3.word11 << 2;
    IS3.word11 |= manageIO.getInputs2()[45]; IS3.word11 = IS3.word11 << 2;
    IS3.word11 |= manageIO.getInputs2()[44];
//    printf("    word11 \t%02x\n", IS3.word11);

    IS3.word12 |= manageIO.getInputs2()[51]; IS3.word12 = IS3.word12 << 2;
    IS3.word12 |= manageIO.getInputs2()[50]; IS3.word12 = IS3.word12 << 2;
    IS3.word12 |= manageIO.getInputs2()[49]; IS3.word12 = IS3.word12 << 2;
    IS3.word12 |= manageIO.getInputs2()[48];
//    printf("    word12 \t%02x\n", IS3.word12);

    IS3.word13 |= manageIO.getInputs2()[55]; IS3.word13 = IS3.word13 << 2;
    IS3.word13 |= manageIO.getInputs2()[54]; IS3.word13 = IS3.word13 << 2;
    IS3.word13 |= manageIO.getInputs2()[53]; IS3.word13 = IS3.word13 << 2;
    IS3.word13 |= manageIO.getInputs2()[52];
//    printf("    word13 \t%02x\n", IS3.word13);

    IS3.word14 |= manageIO.getInputs2()[59]; IS3.word14 = IS3.word14 << 2;
    IS3.word14 |= manageIO.getInputs2()[58]; IS3.word14 = IS3.word14 << 2;
    IS3.word14 |= manageIO.getInputs2()[57]; IS3.word14 = IS3.word14 << 2;
    IS3.word14 |= manageIO.getInputs2()[56];
//    printf("    word14 \t%02x\n", IS3.word14);

    IS3.word15 |= manageIO.getInputs2()[63]; IS3.word15 = IS3.word15 << 2;
    IS3.word15 |= manageIO.getInputs2()[62]; IS3.word15 = IS3.word15 << 2;
    IS3.word15 |= manageIO.getInputs2()[61]; IS3.word15 = IS3.word15 << 2;
    IS3.word15 |= manageIO.getInputs2()[60];
//    printf("    word15 \t%02x\n", IS3.word15);

    IS3.word16 |= manageIO.getInputs2()[67]; IS3.word16 = IS3.word16 << 2;
    IS3.word16 |= manageIO.getInputs2()[66]; IS3.word16 = IS3.word16 << 2;
    IS3.word16 |= manageIO.getInputs2()[65]; IS3.word16 = IS3.word16 << 2;
    IS3.word16 |= manageIO.getInputs2()[64];
//    printf("    word16 \t%02x\n", IS3.word16);

    IS3.word17 |= manageIO.getInputs2()[71]; IS3.word17 = IS3.word17 << 2;
    IS3.word17 |= manageIO.getInputs2()[70]; IS3.word17 = IS3.word17 << 2;
    IS3.word17 |= manageIO.getInputs2()[69]; IS3.word17 = IS3.word17 << 2;
    IS3.word17 |= manageIO.getInputs2()[68];
//    printf("    word17 \t%02x\n", IS3.word17);

    IS3.word18 |= manageIO.getInputs2()[75]; IS3.word18 = IS3.word18 << 2;
    IS3.word18 |= manageIO.getInputs2()[74]; IS3.word18 = IS3.word18 << 2;
    IS3.word18 |= manageIO.getInputs2()[73]; IS3.word18 = IS3.word18 << 2;
    IS3.word18 |= manageIO.getInputs2()[72];
//    printf("    word18 \t%02x\n", IS3.word18);

    IS3.word19 |= manageIO.getInputs2()[79]; IS3.word19 = IS3.word19 << 2;
    IS3.word19 |= manageIO.getInputs2()[78]; IS3.word19 = IS3.word19 << 2;
    IS3.word19 |= manageIO.getInputs2()[77]; IS3.word19 = IS3.word19 << 2;
    IS3.word19 |= manageIO.getInputs2()[76];
//    printf("    word19 \t%02x\n", IS3.word19);

    IS3.word20 |= manageIO.getInputs2()[83]; IS3.word20 = IS3.word20 << 2;
    IS3.word20 |= manageIO.getInputs2()[82]; IS3.word20 = IS3.word20 << 2;
    IS3.word20 |= manageIO.getInputs2()[81]; IS3.word20 = IS3.word20 << 2;
    IS3.word20 |= manageIO.getInputs2()[80];
//    printf("    word20 \t%02x\n", IS3.word20);

    IS3.word21 |= manageIO.getInputs2()[87]; IS3.word21 = IS3.word21 << 2;
    IS3.word21 |= manageIO.getInputs2()[86]; IS3.word21 = IS3.word21 << 2;
    IS3.word21 |= manageIO.getInputs2()[85]; IS3.word21 = IS3.word21 << 2;
    IS3.word21 |= manageIO.getInputs2()[84];
//    printf("    word21 \t%02x\n", IS3.word21);

    IS3.word22 |= manageIO.getInputs2()[91]; IS3.word22 = IS3.word22 << 2;
    IS3.word22 |= manageIO.getInputs2()[90]; IS3.word22 = IS3.word22 << 2;
    IS3.word22 |= manageIO.getInputs2()[89]; IS3.word22 = IS3.word22 << 2;
    IS3.word22 |= manageIO.getInputs2()[88];
//    printf("    word22 \t%02x\n", IS3.word22);

    IS3.word23 |= manageIO.getInputs2()[95]; IS3.word23 = IS3.word23 << 2;
    IS3.word23 |= manageIO.getInputs2()[94]; IS3.word23 = IS3.word23 << 2;
    IS3.word23 |= manageIO.getInputs2()[93]; IS3.word23 = IS3.word23 << 2;
    IS3.word23 |= manageIO.getInputs2()[92];
//    printf("    word23 \t%02x\n", IS3.word23);

    IS3.word24 |= manageIO.getInputs2()[99]; IS3.word24 = IS3.word24 << 2;
    IS3.word24 |= manageIO.getInputs2()[98]; IS3.word24 = IS3.word24 << 2;
    IS3.word24 |= manageIO.getInputs2()[97]; IS3.word24 = IS3.word24 << 2;
    IS3.word24 |= manageIO.getInputs2()[96];
//    printf("    word24 \t%02x\n", IS3.word24);

    IS3.word25 |= manageIO.getInputs2()[103]; IS3.word25 = IS3.word25 << 2;
    IS3.word25 |= manageIO.getInputs2()[102]; IS3.word25 = IS3.word25 << 2;
    IS3.word25 |= manageIO.getInputs2()[101]; IS3.word25 = IS3.word25 << 2;
    IS3.word25 |= manageIO.getInputs2()[100];
//    printf("    word25 \t%02x\n", IS3.word25);

    IS3.word26 |= manageIO.getInputs2()[107]; IS3.word26 = IS3.word26 << 2;
    IS3.word26 |= manageIO.getInputs2()[106]; IS3.word26 = IS3.word26 << 2;
    IS3.word26 |= manageIO.getInputs2()[105]; IS3.word26 = IS3.word26 << 2;
    IS3.word26 |= manageIO.getInputs2()[104];
//    printf("    word26 \t%02x\n", IS3.word26);

    IS3.word27 |= manageIO.getInputs2()[111]; IS3.word27 = IS3.word27 << 2;
    IS3.word27 |= manageIO.getInputs2()[110]; IS3.word27 = IS3.word27 << 2;
    IS3.word27 |= manageIO.getInputs2()[109]; IS3.word27 = IS3.word27 << 2;
    IS3.word27 |= manageIO.getInputs2()[108];
//    printf("    word27 \t%02x\n", IS3.word27);

    IS3.word28 |= manageIO.getInputs2()[115]; IS3.word28 = IS3.word28 << 2;
    IS3.word28 |= manageIO.getInputs2()[114]; IS3.word28 = IS3.word28 << 2;
    IS3.word28 |= manageIO.getInputs2()[113]; IS3.word28 = IS3.word28 << 2;
    IS3.word28 |= manageIO.getInputs2()[112];
//    printf("    word28 \t%02x\n", IS3.word28);

    IS3.word29 |= manageIO.getInputs2()[119]; IS3.word29 = IS3.word29 << 2;
    IS3.word29 |= manageIO.getInputs2()[118]; IS3.word29 = IS3.word29 << 2;
    IS3.word29 |= manageIO.getInputs2()[117]; IS3.word29 = IS3.word29 << 2;
    IS3.word29 |= manageIO.getInputs2()[116];
//    printf("    word29 \t%02x\n", IS3.word29);

    IS3.word30 |= manageIO.getInputs2()[123]; IS3.word30 = IS3.word30 << 2;
    IS3.word30 |= manageIO.getInputs2()[122]; IS3.word30 = IS3.word30 << 2;
    IS3.word30 |= manageIO.getInputs2()[121]; IS3.word30 = IS3.word30 << 2;
    IS3.word30 |= manageIO.getInputs2()[120];
//    printf("    word30 \t%02x\n", IS3.word30);
}

_is4 *FormingIM_busep::createIS4(char device_number, unsigned char cnrtl)
{
    qDebug() << __FUNCTION__;

    bzero(&IS4, (sizeof (_is4)));

    IS4.header = header; printf("    header \t%02x\n", IS4.header);
    IS4.managed = response_change; printf("    managed \t%02x\n", IS4.managed);
    printf("    cnrtl \t%02x\n", cnrtl);

    // записываю в "номер входа - 1"
    manageIO.changeOutputs(device_number, cnrtl);

    setStatesIS4(IS4);

    IS4.crc = im.calculateCRC(&IS4, sizeof (_is4)); // printf("    crc \t%02x\n", IS4.crc);

    return &IS4;
}

void FormingIM_busep::setStatesIS4(_is4 &IS4)
{
    // посылаю как есть - с нулевого входа
    IS4.state00 |= manageIO.getOutputs2()[3]; IS4.state00 = IS4.state00 << 2;
    IS4.state00 |= manageIO.getOutputs2()[2]; IS4.state00 = IS4.state00 << 2;
    IS4.state00 |= manageIO.getOutputs2()[1]; IS4.state00 = IS4.state00 << 2;
    IS4.state00 |= manageIO.getOutputs2()[0];
//    printf("    state00 \t%02x\n", IS4.state00);

    IS4.state01 |= manageIO.getOutputs2()[7]; IS4.state01 = IS4.state01 << 2;
    IS4.state01 |= manageIO.getOutputs2()[6]; IS4.state01 = IS4.state01 << 2;
    IS4.state01 |= manageIO.getOutputs2()[5]; IS4.state01 = IS4.state01 << 2;
    IS4.state01 |= manageIO.getOutputs2()[5];
//    printf("    state01 \t%02x\n", IS4.state01);

    IS4.state02 |= manageIO.getOutputs2()[11]; IS4.state02 = IS4.state02 << 2;
    IS4.state02 |= manageIO.getOutputs2()[10]; IS4.state02 = IS4.state02 << 2;
    IS4.state02 |= manageIO.getOutputs2()[9]; IS4.state02 = IS4.state02 << 2;
    IS4.state02 |= manageIO.getOutputs2()[8];
//    printf("    state02 \t%02x\n", IS4.state02);

    IS4.state03 |= manageIO.getOutputs2()[15]; IS4.state03 = IS4.state03 << 2;
    IS4.state03 |= manageIO.getOutputs2()[14]; IS4.state03 = IS4.state03 << 2;
    IS4.state03 |= manageIO.getOutputs2()[13]; IS4.state03 = IS4.state03 << 2;
    IS4.state03 |= manageIO.getOutputs2()[12];
//    printf("    state03 \t%02x\n", IS4.state03);

    IS4.state04 |= manageIO.getOutputs2()[19]; IS4.state04 = IS4.state04 << 2;
    IS4.state04 |= manageIO.getOutputs2()[18]; IS4.state04 = IS4.state04 << 2;
    IS4.state04 |= manageIO.getOutputs2()[17]; IS4.state04 = IS4.state04 << 2;
    IS4.state04 |= manageIO.getOutputs2()[16];
//    printf("    state04 \t%02x\n", IS4.state04);

    IS4.state05 |= manageIO.getOutputs2()[23]; IS4.state05 = IS4.state05 << 2;
    IS4.state05 |= manageIO.getOutputs2()[22]; IS4.state05 = IS4.state05 << 2;
    IS4.state05 |= manageIO.getOutputs2()[21]; IS4.state05 = IS4.state05 << 2;
    IS4.state05 |= manageIO.getOutputs2()[20];
//    printf("    state05 \t%02x\n", IS4.state05);

    IS4.state06 |= manageIO.getOutputs2()[27]; IS4.state06 = IS4.state06 << 2;
    IS4.state06 |= manageIO.getOutputs2()[26]; IS4.state06 = IS4.state06 << 2;
    IS4.state06 |= manageIO.getOutputs2()[25]; IS4.state06 = IS4.state06 << 2;
    IS4.state06 |= manageIO.getOutputs2()[24];
//    printf("    state06 \t%02x\n", IS4.state06);

    IS4.state07 |= manageIO.getOutputs2()[31]; IS4.state07 = IS4.state07 << 2;
    IS4.state07 |= manageIO.getOutputs2()[30]; IS4.state07 = IS4.state07 << 2;
    IS4.state07 |= manageIO.getOutputs2()[29]; IS4.state07 = IS4.state07 << 2;
    IS4.state07 |= manageIO.getOutputs2()[28];
//    printf("    state07 \t%02x\n", IS4.state07);

    IS4.state08 |= manageIO.getOutputs2()[35]; IS4.state08 = IS4.state08 << 2;
    IS4.state08 |= manageIO.getOutputs2()[34]; IS4.state08 = IS4.state08 << 2;
    IS4.state08 |= manageIO.getOutputs2()[33]; IS4.state08 = IS4.state08 << 2;
    IS4.state08 |= manageIO.getOutputs2()[32];
//    printf("    state08 \t%02x\n", IS4.state08);

    IS4.state09 |= manageIO.getOutputs2()[39]; IS4.state09 = IS4.state09 << 2;
    IS4.state09 |= manageIO.getOutputs2()[38]; IS4.state09 = IS4.state09 << 2;
    IS4.state09 |= manageIO.getOutputs2()[37]; IS4.state09 = IS4.state09 << 2;
    IS4.state09 |= manageIO.getOutputs2()[36];
//    printf("    state09 \t%02x\n", IS4.state09);

    IS4.state10 |= manageIO.getOutputs2()[43]; IS4.state10 = IS4.state10 << 2;
    IS4.state10 |= manageIO.getOutputs2()[42]; IS4.state10 = IS4.state10 << 2;
    IS4.state10 |= manageIO.getOutputs2()[41]; IS4.state10 = IS4.state10 << 2;
    IS4.state10 |= manageIO.getOutputs2()[40];
//    printf("    state10 \t%02x\n", IS4.state10);

    IS4.state11 |= manageIO.getOutputs2()[47]; IS4.state11 = IS4.state11 << 2;
    IS4.state11 |= manageIO.getOutputs2()[46]; IS4.state11 = IS4.state11 << 2;
    IS4.state11 |= manageIO.getOutputs2()[45]; IS4.state11 = IS4.state11 << 2;
    IS4.state11 |= manageIO.getOutputs2()[44];
//    printf("    state11 \t%02x\n", IS4.state11);

    IS4.state12 |= manageIO.getOutputs2()[51]; IS4.state12 = IS4.state12 << 2;
    IS4.state12 |= manageIO.getOutputs2()[50]; IS4.state12 = IS4.state12 << 2;
    IS4.state12 |= manageIO.getOutputs2()[49]; IS4.state12 = IS4.state12 << 2;
    IS4.state12 |= manageIO.getOutputs2()[48];
//    printf("    state12 \t%02x\n", IS4.state12);

    IS4.state13 |= manageIO.getOutputs2()[55]; IS4.state13 = IS4.state13 << 2;
    IS4.state13 |= manageIO.getOutputs2()[54]; IS4.state13 = IS4.state13 << 2;
    IS4.state13 |= manageIO.getOutputs2()[53]; IS4.state13 = IS4.state13 << 2;
    IS4.state13 |= manageIO.getOutputs2()[52];
//    printf("    state13 \t%02x\n", IS4.state13);

    IS4.state14 |= manageIO.getOutputs2()[59]; IS4.state14 = IS4.state14 << 2;
    IS4.state14 |= manageIO.getOutputs2()[58]; IS4.state14 = IS4.state14 << 2;
    IS4.state14 |= manageIO.getOutputs2()[57]; IS4.state14 = IS4.state14 << 2;
    IS4.state14 |= manageIO.getOutputs2()[56];
//    printf("    state14 \t%02x\n", IS4.state14);

    IS4.state15 |= manageIO.getOutputs2()[61]; IS4.state15 = IS4.state15 << 2;
    IS4.state15 |= manageIO.getOutputs2()[60];

//    IS4.state15 |= manageIO.getOutputs2()[62]; IS4.state15 = IS4.state15 << 2;
//    printf("    state15 \t%02x\n", IS4.state15);
}

_is5 *FormingIM_busep::createIS5()
{
    qDebug() << "IS5";
    IS5.header = header; printf("    header \t%02x\n", IS5.header);
    IS5.managed = integrity_violation; printf("    managed \t%02x\n", IS5.managed);
    IS5.crc = im.calculateCRC(&IS5, sizeof (_is5));    printf("    crc \t%02x\n", IS5.crc);

    return &IS5;
}

bool FormingIM_busep::parseIS1(_is1 *IS1)
{
    if (im.checkCRC(&IS1, sizeof (_is1), IS1->crc))
    {
        printf("    header \t%02x\n", IS1->header);
        printf("    managed \t%02x\n", IS1->managed);
        printf("    crc \t%02x\n", IS1->crc);

        return true;
    }
    return false;
}

bool FormingIM_busep::parseIS2(_is2 *IS2)
{
    if (im.checkCRC(&IS2, sizeof (_is2), IS2->crc))
    {
        printf("       header \t%02x\n", IS2->header);
        printf("      managed \t%02x\n", IS2->managed);
        printf("device_number \t%02x\n", IS2->device_number);
        printf("        state \t%02x\n", IS2->state);
        printf("          crc \t%02x\n", IS2->crc);

        return true;
    }
    return false;
}
/*
char FormingIM_busep::calculateCRC(void *p, int bytes)
{
    char crc = 0x00;
    char *array = (char *)p;
    bytes--;
    while (bytes--)
    {
        crc = CRC8table[crc ^ *array++];
    }
    return crc;
}

bool FormingIM_busep::checkCRC(void *p, int bytes, unsigned char crc)
{
    char crc_check = calculateCRC(p, bytes);
    return (crc_check == crc);
}
*/
char *FormingIM_busep::getInputs()
{
    return manageIO.getOutputs2();
}

char *FormingIM_busep::getOutputs()
{
    return manageIO.getOutputs2();
}

output_state FormingIM_busep::getOutputState(int number)
{
    return manageIO.getOutputState(number);
}

input_state FormingIM_busep::getInputState(int number)
{
    return  manageIO.getInputState(number);
}

//_inputs FormingIM_busep::getInputs() const
//{
//    return manageIO.getInputs();
//}
