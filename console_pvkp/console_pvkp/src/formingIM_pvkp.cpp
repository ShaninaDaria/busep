#include "hdr/formingIM_pvkp.h"

FormingIM_pvkp::FormingIM_pvkp()
{

}

_is1 FormingIM_pvkp::createIS1()
{
    bzero(&IS1, sizeof(_is1));

    qDebug() << "IS1";
    IS1.header = header; // printf("    header \t%02x\n", IS1.header);
    IS1.managed = request; // printf("    managed \t%02x\n", IS1.managed);
    IS1.crc = im.calculateCRC(&IS1, (sizeof (_is1) - 1)); // printf("    crc \t%02x\n", IS1.crc);

    qDebug() << ">>>header" << IS1.header;
    qDebug() << ">>managed" << IS1.managed;
    qDebug() << ">>>>>>crc" << IS1.crc;
    qDebug() << "-----\n";

    return IS1;
}

_is2 FormingIM_pvkp::createIS2(char device_number, output_cntrl cntrl)
{
    bzero(&IS2, (sizeof (_is2)));

    qDebug() << "IS2";
    IS2.header = header; // printf("    header \t%02x\n", IS2.header);
    IS2.managed = change_state; // printf("    managed \t%02x\n", IS2.managed);
    IS2.device_number = device_number; // printf("    device_number \t%d\n", IS2.device_number);
    IS2.state = cntrl; // printf("    state \t%02x\n", IS2.state);
    IS2.crc = im.calculateCRC(&IS2, (sizeof (_is2) - 1));  // printf("    crc \t%02x\n", IS2.crc);

    qDebug() << ">>>>>>>>>>header" << IS2.header;
    qDebug() << ">>>>>>>>>managed" << IS2.managed;
    if (device_number == 0x00)
    {
        qDebug() << ">>>device_number" << 0;
    }
    else
    {
        qDebug() << ">>>device_number" << device_number;
    }
    qDebug() << ">>>>>>>>>>>state" << IS2.state;
    qDebug() << ">>>>>>>>>>>>>crc" << IS2.crc;

    qDebug() << "-----\n";

    return IS2;
}
/*
char FormingIM_pvkp::calculateCRC(void *p, int bytes)
{
    char crc = 0xff;
    char *array = (char *)p;
    bytes--;
    while (bytes--)
    {
        crc = CRC8table[crc ^ *array++];
    }
    return crc;
}

bool FormingIM_pvkp::checkCRC(void *p, int bytes, unsigned char crc)
{
    char crc_check = calculateCRC(p, bytes);
    return (crc_check == crc);
}
*/
_is1 FormingIM_pvkp::getIS1() const
{
    return IS1;
}

_is2 FormingIM_pvkp::getIS2() const
{
    return IS2;
}

void FormingIM_pvkp::parsingIS3(_is3 *IS3, bool &ok)
{
    qDebug() << "<<<" << __FUNCTION__ << "<<<";

    char crc = im.calculateCRC(IS3, (sizeof (_is3) - 1));

    if ((IS3->header == header) &&
        (IS3->managed == response_state) &&
        im.checkCRC(IS3, (sizeof (_is3) - 1), IS3->crc))
    {
        ok = true;
//        printf("   header \t%02x\n", IS3.header);
//        printf("  managed \t%02x\n", IS3.managed);

        parsingWords(IS3);


//        printf("      crc \t%02x\n", IS3.crc);

        qDebug() << "<<<header" << IS3->header;
        qDebug() << "<<managed" << IS3->managed;
        qDebug() << "<<<<<<crc" << IS3->crc;
        qDebug() << crc;
        qDebug() << "<<<<<<<<<<<<";
    }
    else
    {
        ok = false;
        qDebug() << "<<<NO PARSE IS3"
                 << IS3->header
                 << IS3->managed
                 << IS3->crc
                 << crc;
    }
}

void FormingIM_pvkp::parsingWords(_is3 *IS3)
{
    //    printf("    word00 \t%02x\n", IS3->word00);
    io.setOneInput(input1, getInputState2(IS3->word00)); IS3->word00 = IS3->word00 >> 2;
    io.setOneInput(input2, getInputState2(IS3->word00)); IS3->word00 = IS3->word00 >> 2;
    io.setOneInput(input3, getInputState2(IS3->word00)); IS3->word00 = IS3->word00 >> 2;
    io.setOneInput(input4, getInputState2(IS3->word00));

    qDebug() << "<<<input1" << io.getInputValue(input1);

    //    printf("    word01 \t%02x\n", IS3->word01);
    io.setOneInput(input5, getInputState2(IS3->word01)); IS3->word01 = IS3->word01 >> 2;
    io.setOneInput(input6, getInputState2(IS3->word01)); IS3->word01 = IS3->word01 >> 2;
    io.setOneInput(input7, getInputState2(IS3->word01)); IS3->word01 = IS3->word01 >> 2;
    io.setOneInput(input8, getInputState2(IS3->word01));

    //    printf("    word02 \t%02x\n", IS3->word02);
    io.setOneInput(input9, getInputState2(IS3->word02)); IS3->word02 = IS3->word02 >> 2;
    io.setOneInput(input10, getInputState2(IS3->word02)); IS3->word02 = IS3->word02 >> 2;
    io.setOneInput(input11, getInputState2(IS3->word02)); IS3->word02 = IS3->word02 >> 2;
    io.setOneInput(input12, getInputState2(IS3->word02));

    //    printf("    word03 \t%02x\n", IS3->word03);
    io.setOneInput(input13, getInputState2(IS3->word03)); IS3->word03 = IS3->word03 >> 2;
    io.setOneInput(input14, getInputState2(IS3->word03)); IS3->word03 = IS3->word03 >> 2;
    io.setOneInput(input15, getInputState2(IS3->word03)); IS3->word03 = IS3->word03 >> 2;
    io.setOneInput(input16, getInputState2(IS3->word03));

    //    printf("    word04 \t%02x\n", IS3->word04);
    io.setOneInput(input17, getInputState2(IS3->word04)); IS3->word04 = IS3->word04 >> 2;
    io.setOneInput(input18, getInputState2(IS3->word04)); IS3->word04 = IS3->word04 >> 2;
    io.setOneInput(input19, getInputState2(IS3->word04)); IS3->word04 = IS3->word04 >> 2;
    io.setOneInput(input20, getInputState2(IS3->word04));

    //    printf("    word05 \t%02x\n", IS3->word05);
    io.setOneInput(input21, getInputState2(IS3->word05)); IS3->word05 = IS3->word05 >> 2;
    io.setOneInput(input22, getInputState2(IS3->word05)); IS3->word05 = IS3->word05 >> 2;
    io.setOneInput(input23, getInputState2(IS3->word05)); IS3->word05 = IS3->word05 >> 2;
    io.setOneInput(input24, getInputState2(IS3->word05));

    //    printf("    word06 \t%02x\n", IS3->word06);
    io.setOneInput(input25, getInputState2(IS3->word06)); IS3->word06 = IS3->word06 >> 2;
    io.setOneInput(input26, getInputState2(IS3->word06)); IS3->word06 = IS3->word06 >> 2;
    io.setOneInput(input27, getInputState2(IS3->word06)); IS3->word06 = IS3->word06 >> 2;
    io.setOneInput(input28, getInputState2(IS3->word06));

    //    printf("    word07 \t%02x\n", IS3->word07);
    io.setOneInput(input29, getInputState2(IS3->word07)); IS3->word07 = IS3->word07 >> 2;
    io.setOneInput(input30, getInputState2(IS3->word07)); IS3->word07 = IS3->word07 >> 2;
    io.setOneInput(input31, getInputState2(IS3->word07)); IS3->word07 = IS3->word07 >> 2;
    io.setOneInput(input32, getInputState2(IS3->word07));

    //    printf("    word08 \t%02x\n", IS3->word08);
    io.setOneInput(input33, getInputState2(IS3->word08)); IS3->word08 = IS3->word08 >> 2;
    io.setOneInput(input34, getInputState2(IS3->word08)); IS3->word08 = IS3->word08 >> 2;
    io.setOneInput(input35, getInputState2(IS3->word08)); IS3->word08 = IS3->word08 >> 2;
    io.setOneInput(input36, getInputState2(IS3->word08));

    //    printf("    word09 \t%02x\n", IS3->word09);
    io.setOneInput(input37, getInputState2(IS3->word09)); IS3->word09 = IS3->word09 >> 2;
    io.setOneInput(input38, getInputState2(IS3->word09)); IS3->word09 = IS3->word09 >> 2;
    io.setOneInput(input39, getInputState2(IS3->word09)); IS3->word09 = IS3->word09 >> 2;
    io.setOneInput(input40, getInputState2(IS3->word09));

    //    printf("    word10 \t%02x\n", IS3->word10);
    io.setOneInput(input41, getInputState2(IS3->word10)); IS3->word10 = IS3->word10 >> 2;
    io.setOneInput(input42, getInputState2(IS3->word10)); IS3->word10 = IS3->word10 >> 2;
    io.setOneInput(input43, getInputState2(IS3->word10)); IS3->word10 = IS3->word10 >> 2;
    io.setOneInput(input44, getInputState2(IS3->word10));

    //    printf("    word11 \t%02x\n", IS3->word11);
    io.setOneInput(input45, getInputState2(IS3->word11)); IS3->word11 = IS3->word11 >> 2;
    io.setOneInput(input46, getInputState2(IS3->word11)); IS3->word11 = IS3->word11 >> 2;
    io.setOneInput(input47, getInputState2(IS3->word11)); IS3->word11 = IS3->word11 >> 2;
    io.setOneInput(input48, getInputState2(IS3->word11));

    //    printf("    word12 \t%02x\n", IS3->word12);
    io.setOneInput(input49, getInputState2(IS3->word12)); IS3->word12 = IS3->word12 >> 2;
    io.setOneInput(input50, getInputState2(IS3->word12)); IS3->word12 = IS3->word12 >> 2;
    io.setOneInput(input51, getInputState2(IS3->word12)); IS3->word12 = IS3->word12 >> 2;
    io.setOneInput(input52, getInputState2(IS3->word12));

    //    printf("    word13 \t%02x\n", IS3->word13);
    io.setOneInput(input53, getInputState2(IS3->word13)); IS3->word13 = IS3->word13 >> 2;
    io.setOneInput(input54, getInputState2(IS3->word13)); IS3->word13 = IS3->word13 >> 2;
    io.setOneInput(input55, getInputState2(IS3->word13)); IS3->word13 = IS3->word13 >> 2;
    io.setOneInput(input56, getInputState2(IS3->word13));

    //    printf("    word14 \t%02x\n", IS3->word14);
    io.setOneInput(input57, getInputState2(IS3->word14)); IS3->word14 = IS3->word14 >> 2;
    io.setOneInput(input58, getInputState2(IS3->word14)); IS3->word14 = IS3->word14 >> 2;
    io.setOneInput(input59, getInputState2(IS3->word14)); IS3->word14 = IS3->word14 >> 2;
    io.setOneInput(input60, getInputState2(IS3->word14));

    //    printf("    word15 \t%02x\n", IS3->word15);
    io.setOneInput(input61, getInputState2(IS3->word15)); IS3->word15 = IS3->word15 >> 2;
    io.setOneInput(input62, getInputState2(IS3->word15)); IS3->word15 = IS3->word15 >> 2;
    io.setOneInput(input63, getInputState2(IS3->word15)); IS3->word15 = IS3->word15 >> 2;
    io.setOneInput(input64, getInputState2(IS3->word15));

    //    printf("    word16 \t%02x\n", IS3->word16);
    io.setOneInput(input65, getInputState2(IS3->word16)); IS3->word16 = IS3->word16 >> 2;
    io.setOneInput(input66, getInputState2(IS3->word16)); IS3->word16 = IS3->word16 >> 2;
    io.setOneInput(input67, getInputState2(IS3->word16)); IS3->word16 = IS3->word16 >> 2;
    io.setOneInput(input68, getInputState2(IS3->word16));

    //    printf("    word17 \t%02x\n", IS3->word17);
    io.setOneInput(input69, getInputState2(IS3->word17)); IS3->word17 = IS3->word17 >> 2;
    io.setOneInput(input70, getInputState2(IS3->word17)); IS3->word17 = IS3->word17 >> 2;
    io.setOneInput(input71, getInputState2(IS3->word17)); IS3->word17 = IS3->word17 >> 2;
    io.setOneInput(input72, getInputState2(IS3->word17));

    //    printf("    word18 \t%02x\n", IS3->word18);
    io.setOneInput(input73, getInputState2(IS3->word18)); IS3->word18 = IS3->word18 >> 2;
    io.setOneInput(input74, getInputState2(IS3->word18)); IS3->word18 = IS3->word18 >> 2;
    io.setOneInput(input75, getInputState2(IS3->word18)); IS3->word18 = IS3->word18 >> 2;
    io.setOneInput(input76, getInputState2(IS3->word18));

    //    printf("    word19 \t%02x\n", IS3->word19);
    io.setOneInput(input77, getInputState2(IS3->word19)); IS3->word19 = IS3->word19 >> 2;
    io.setOneInput(input78, getInputState2(IS3->word19)); IS3->word19 = IS3->word19 >> 2;
    io.setOneInput(input79, getInputState2(IS3->word19)); IS3->word19 = IS3->word19 >> 2;
    io.setOneInput(input80, getInputState2(IS3->word19));

    //    printf("    word20 \t%02x\n", IS3->word20);
    io.setOneInput(input81, getInputState2(IS3->word20)); IS3->word20 = IS3->word20 >> 2;
    io.setOneInput(input82, getInputState2(IS3->word20)); IS3->word20 = IS3->word20 >> 2;
    io.setOneInput(input83, getInputState2(IS3->word20)); IS3->word20 = IS3->word20 >> 2;
    io.setOneInput(input84, getInputState2(IS3->word20));

    //    printf("    word21 \t%02x\n", IS3->word21);
    io.setOneInput(input85, getInputState2(IS3->word21)); IS3->word21 = IS3->word21 >> 2;
    io.setOneInput(input86, getInputState2(IS3->word21)); IS3->word21 = IS3->word21 >> 2;
    io.setOneInput(input87, getInputState2(IS3->word21)); IS3->word21 = IS3->word21 >> 2;
    io.setOneInput(input88, getInputState2(IS3->word21));

    //    printf("    word22 \t%02x\n", IS3->word22);
    io.setOneInput(input89, getInputState2(IS3->word22)); IS3->word22 = IS3->word22 >> 2;
    io.setOneInput(input90, getInputState2(IS3->word22)); IS3->word22 = IS3->word22 >> 2;
    io.setOneInput(input91, getInputState2(IS3->word22)); IS3->word22 = IS3->word22 >> 2;
    io.setOneInput(input92, getInputState2(IS3->word22));

    //    printf("    word23 \t%02x\n", IS3->word23);
    io.setOneInput(input93, getInputState2(IS3->word23)); IS3->word23 = IS3->word23 >> 2;
    io.setOneInput(input94, getInputState2(IS3->word23)); IS3->word23 = IS3->word23 >> 2;
    io.setOneInput(input95, getInputState2(IS3->word23)); IS3->word23 = IS3->word23 >> 2;
    io.setOneInput(input96, getInputState2(IS3->word23));

    //    printf("    word24 \t%02x\n", IS3->word24);
    io.setOneInput(input97, getInputState2(IS3->word24)); IS3->word24 = IS3->word24 >> 2;
    io.setOneInput(input98, getInputState2(IS3->word24)); IS3->word24 = IS3->word24 >> 2;
    io.setOneInput(input99, getInputState2(IS3->word24)); IS3->word24 = IS3->word24 >> 2;
    io.setOneInput(input100, getInputState2(IS3->word24));

    //    printf("    word25 \t%02x\n", IS3->word25);
    io.setOneInput(input101, getInputState2(IS3->word25)); IS3->word25 = IS3->word25 >> 2;
    io.setOneInput(input102, getInputState2(IS3->word25)); IS3->word25 = IS3->word25 >> 2;
    io.setOneInput(input103, getInputState2(IS3->word25)); IS3->word25 = IS3->word25 >> 2;
    io.setOneInput(input104, getInputState2(IS3->word25));

    //    printf("    word26 \t%02x\n", IS3->word26);
    io.setOneInput(input105, getInputState2(IS3->word26)); IS3->word26 = IS3->word26 >> 2;
    io.setOneInput(input106, getInputState2(IS3->word26)); IS3->word26 = IS3->word26 >> 2;
    io.setOneInput(input107, getInputState2(IS3->word26)); IS3->word26 = IS3->word26 >> 2;
    io.setOneInput(input108, getInputState2(IS3->word26));

    //    printf("    word27 \t%02x\n", IS3->word27);
    io.setOneInput(input109, getInputState2(IS3->word27)); IS3->word27 = IS3->word27 >> 2;
    io.setOneInput(input110, getInputState2(IS3->word27)); IS3->word27 = IS3->word27 >> 2;
    io.setOneInput(input111, getInputState2(IS3->word27)); IS3->word27 = IS3->word27 >> 2;
    io.setOneInput(input112, getInputState2(IS3->word27));

    //    printf("    word28 \t%02x\n", IS3->word28);
    io.setOneInput(input113, getInputState2(IS3->word28)); IS3->word28 = IS3->word28 >> 2;
    io.setOneInput(input114, getInputState2(IS3->word28)); IS3->word28 = IS3->word28 >> 2;
    io.setOneInput(input115, getInputState2(IS3->word28)); IS3->word28 = IS3->word28 >> 2;
    io.setOneInput(input116, getInputState2(IS3->word28));

    //    printf("    word29 \t%02x\n", IS3->word29);
    io.setOneInput(input117, getInputState2(IS3->word29)); IS3->word29 = IS3->word29 >> 2;
    io.setOneInput(input118, getInputState2(IS3->word29)); IS3->word29 = IS3->word29 >> 2;
    io.setOneInput(input119, getInputState2(IS3->word29)); IS3->word29 = IS3->word29 >> 2;
    io.setOneInput(input120, getInputState2(IS3->word29));

//    printf("    word30 \t%02x\n", IS3->word30);
    io.setOneInput(input121, getInputState2(IS3->word30)); IS3->word30 = IS3->word30 >> 2;
    io.setOneInput(input122, getInputState2(IS3->word30)); IS3->word30 = IS3->word30 >> 2;
    io.setOneInput(input123, getInputState2(IS3->word30)); IS3->word30 = IS3->word30 >> 2;
    io.setOneInput(input124, getInputState2(IS3->word30));
}

void FormingIM_pvkp::parsingIS4(_is4 *IS4, bool &ok)
{
    qDebug() << "<<<" << __FUNCTION__ << "<<<";

    char crc = im.calculateCRC(IS4, (sizeof (_is4) - 1));

    if ((IS4->header == header) &&
        (IS4->managed == response_change) &&
        im.checkCRC(IS4, (sizeof (_is4) - 1), IS4->crc))
    {
        ok = true;
//        printf("    header \t%02x\n", IS4->header);
//        printf("   managed \t%02x\n", IS4->managed);

        parsingStates(IS4);

        qDebug() << "<<<header" << IS4->header;
        qDebug() << "<<managed" << IS4->managed;
        qDebug() << "<<<<<<crc" << IS4->crc;
        qDebug() << "<<<<<<<<<<<<";


        /// NOTE подготовка к рамке
        if (IS2.device_number != all_outputs)
        {
            if ((io.getOutputValue(IS2.device_number) == output_on) && (IS2.state == cntrl_on))
            {
                qDebug() << IS2.device_number << IS2.state;
            }
            else
            {
                if ((io.getOutputValue(IS2.device_number) == output_off) && (IS2.state == cntrl_off))
                {
                    qDebug() << IS2.device_number << IS2.state;
                }
                else
                {
                    if (io.getOutputValue(IS2.device_number) == no_output_state)
                    {
                        qDebug() << "no_output_state!";
                    }
                    if (io.getOutputValue(IS2.device_number) == error_output)
                    {
                        qDebug() << "error output!";
                    }
                }
            }
        }
    }
    else
    {
        ok = false;

        qDebug() << "<<<NO PARSE IS4"
                 << IS4->header
                 << IS4->managed
                 << IS4->crc
                 << crc;
    }
}

void FormingIM_pvkp::parsingStates(_is4 *IS4)
{
    //    printf("   state00 \t%02x\n", IS4->state00);
    // записываю в "номер входа - 1"
    io.setOneOutput(output1, getOutputState2(IS4->state00)); IS4->state00 = IS4->state00 >> 2;
    io.setOneOutput(output2, getOutputState2(IS4->state00)); IS4->state00 = IS4->state00 >> 2;
    io.setOneOutput(output3, getOutputState2(IS4->state00)); IS4->state00 = IS4->state00 >> 2;
    io.setOneOutput(output4, getOutputState2(IS4->state00));

    //    printf("   state01 \t%02x\n", IS4->state01);
    io.setOneOutput(output5, getOutputState2(IS4->state01)); IS4->state01 = IS4->state01 >> 2;
    io.setOneOutput(output6, getOutputState2(IS4->state01)); IS4->state01 = IS4->state01 >> 2;
    io.setOneOutput(output7, getOutputState2(IS4->state01)); IS4->state01 = IS4->state01 >> 2;
    io.setOneOutput(output8, getOutputState2(IS4->state01));

    //    printf("   state02 \t%02x\n", IS4->state02);
    io.setOneOutput(output9, getOutputState2(IS4->state02)); IS4->state02 = IS4->state02 >> 2;
    io.setOneOutput(output10, getOutputState2(IS4->state02)); IS4->state02 = IS4->state02 >> 2;
    io.setOneOutput(output11, getOutputState2(IS4->state02)); IS4->state02 = IS4->state02 >> 2;
    io.setOneOutput(output12, getOutputState2(IS4->state02));

    //    printf("   state03 \t%02x\n", IS4->state03);
    io.setOneOutput(output13, getOutputState2(IS4->state03)); IS4->state03 = IS4->state03 >> 2;
    io.setOneOutput(output14, getOutputState2(IS4->state03)); IS4->state03 = IS4->state03 >> 2;
    io.setOneOutput(output15, getOutputState2(IS4->state03)); IS4->state03 = IS4->state03 >> 2;
    io.setOneOutput(output16, getOutputState2(IS4->state03));

    //    printf("   state04 \t%02x\n", IS4->state04);
    io.setOneOutput(output17, getOutputState2(IS4->state04)); IS4->state04 = IS4->state04 >> 2;
    io.setOneOutput(output18, getOutputState2(IS4->state04)); IS4->state04 = IS4->state04 >> 2;
    io.setOneOutput(output19, getOutputState2(IS4->state04)); IS4->state04 = IS4->state04 >> 2;
    io.setOneOutput(output20, getOutputState2(IS4->state04));

    //    printf("   state05 \t%02x\n", IS4->state05);
    io.setOneOutput(output21, getOutputState2(IS4->state05)); IS4->state05 = IS4->state05 >> 2;
    io.setOneOutput(output22, getOutputState2(IS4->state05)); IS4->state05 = IS4->state05 >> 2;
    io.setOneOutput(output23, getOutputState2(IS4->state05)); IS4->state05 = IS4->state05 >> 2;
    io.setOneOutput(output24, getOutputState2(IS4->state05));

    //    printf("   state06 \t%02x\n", IS4->state06);
    io.setOneOutput(output25, getOutputState2(IS4->state06)); IS4->state06 = IS4->state06 >> 2;
    io.setOneOutput(output26, getOutputState2(IS4->state06)); IS4->state06 = IS4->state06 >> 2;
    io.setOneOutput(output27, getOutputState2(IS4->state06)); IS4->state06 = IS4->state06 >> 2;
    io.setOneOutput(output28, getOutputState2(IS4->state06));

    //    printf("   state07 \t%02x\n", IS4->state07);
    io.setOneOutput(output29, getOutputState2(IS4->state07)); IS4->state07 = IS4->state07 >> 2;
    io.setOneOutput(output30, getOutputState2(IS4->state07)); IS4->state07 = IS4->state07 >> 2;
    io.setOneOutput(output31, getOutputState2(IS4->state07)); IS4->state07 = IS4->state07 >> 2;
    io.setOneOutput(output32, getOutputState2(IS4->state07));

    //    printf("   state08 \t%02x\n", IS4->state08);
    io.setOneOutput(output33, getOutputState2(IS4->state08)); IS4->state08 = IS4->state08 >> 2;
    io.setOneOutput(output34, getOutputState2(IS4->state08)); IS4->state08 = IS4->state08 >> 2;
    io.setOneOutput(output35, getOutputState2(IS4->state08)); IS4->state08 = IS4->state08 >> 2;
    io.setOneOutput(output36, getOutputState2(IS4->state08));

    //    printf("   state09 \t%02x\n", IS4->state09);
    io.setOneOutput(output37, getOutputState2(IS4->state09)); IS4->state09 = IS4->state09 >> 2;
    io.setOneOutput(output38, getOutputState2(IS4->state09)); IS4->state09 = IS4->state09 >> 2;
    io.setOneOutput(output39, getOutputState2(IS4->state09)); IS4->state09 = IS4->state09 >> 2;
    io.setOneOutput(output40, getOutputState2(IS4->state09));

    //    printf("   state10 \t%02x\n", IS4->state10);
    io.setOneOutput(output41, getOutputState2(IS4->state10)); IS4->state10 = IS4->state10 >> 2;
    io.setOneOutput(output42, getOutputState2(IS4->state10)); IS4->state10 = IS4->state10 >> 2;
    io.setOneOutput(output43, getOutputState2(IS4->state10)); IS4->state10 = IS4->state10 >> 2;
    io.setOneOutput(output44, getOutputState2(IS4->state10));

    //    printf("   state11 \t%02x\n", IS4->state11);
    io.setOneOutput(output45, getOutputState2(IS4->state11)); IS4->state11 = IS4->state11 >> 2;
    io.setOneOutput(output46, getOutputState2(IS4->state11)); IS4->state11 = IS4->state11 >> 2;
    io.setOneOutput(output47, getOutputState2(IS4->state11)); IS4->state11 = IS4->state11 >> 2;
    io.setOneOutput(output48, getOutputState2(IS4->state11));

    //    printf("   state12 \t%02x\n", IS4->state12);
    io.setOneOutput(output49, getOutputState2(IS4->state12)); IS4->state12 = IS4->state12 >> 2;
    io.setOneOutput(output50, getOutputState2(IS4->state12)); IS4->state12 = IS4->state12 >> 2;
    io.setOneOutput(output51, getOutputState2(IS4->state12)); IS4->state12 = IS4->state12 >> 2;
    io.setOneOutput(output52, getOutputState2(IS4->state12));

    //    printf("   state13 \t%02x\n", IS4->state13);
    io.setOneOutput(output53, getOutputState2(IS4->state13)); IS4->state13 = IS4->state13 >> 2;
    io.setOneOutput(output54, getOutputState2(IS4->state13)); IS4->state13 = IS4->state13 >> 2;
    io.setOneOutput(output55, getOutputState2(IS4->state13)); IS4->state13 = IS4->state13 >> 2;
    io.setOneOutput(output56, getOutputState2(IS4->state13));

    //    printf("   state14 \t%02x\n", IS4->state14);
    io.setOneOutput(output57, getOutputState2(IS4->state14)); IS4->state14 = IS4->state14 >> 2;
    io.setOneOutput(output58, getOutputState2(IS4->state14)); IS4->state14 = IS4->state14 >> 2;
    io.setOneOutput(output59, getOutputState2(IS4->state14)); IS4->state14 = IS4->state14 >> 2;
    io.setOneOutput(output60, getOutputState2(IS4->state14));

    //    printf("   state15 \t%02x\n", IS4->state15);
    io.setOneOutput(output61, getOutputState2(IS4->state15)); IS4->state15 = IS4->state15 >> 2;
    io.setOneOutput(output62, getOutputState2(IS4->state15));
}

void FormingIM_pvkp::parsingIS5(_is5 *IS5)
{
    qDebug() << __FUNCTION__;

    if ((IS5->header == header) &&
        (IS5->managed == integrity_violation) &&
        (im.checkCRC(IS5, (sizeof (_is5) - 1), IS5->crc)))
    {
        printf("    header \t%02x\n", IS5->header);
        printf("   managed \t%02x\n", IS5->managed);
        printf("       crc \t%02x\n", IS5->crc);
    }
}

input_state FormingIM_pvkp::getInputState(int number)
{
    return io.getInputValue(number);
}

input_state FormingIM_pvkp::getInputState2(unsigned char word)
{
    input_state res = no_input_state;

    if ((word & no_signal_27v) == no_signal_27v)
    {
        res = no_signal_27v;
    }
    if ((word & is_signal_27v) == is_signal_27v)
    {
        res = is_signal_27v;
    }
    if ((word & no_input_state) == no_input_state)
    {
        res = no_input_state;
    }

    //    printInputState(input);
    return res;
}

_is1 FormingIM_pvkp::createIS1WithError()
{
    bzero(&IS1, sizeof(_is1));

    /// TODO random!
    qDebug() << "IS1 with error";
    IS1.header = header;
    IS1.header = IS1.header & 0xa5;
    printf("    header \t%02x\n", IS1.header);

    IS1.managed = request;
    IS1.managed = IS1.managed & 0x5a;
    printf("    managed \t%02x\n", IS1.managed);

    IS1.crc = im.calculateCRC(&IS1, (sizeof (_is1) - 1));
    printf("    cs \t%02x\n", IS1.crc);
    qDebug() << "-----\n";

    return IS1;
}

_is2 FormingIM_pvkp::createIS2WithError(char number, output_cntrl cntrl)
{
    bzero(&IS2, (sizeof (_is2)));

    /// TODO random!
    qDebug() << "IS with error";
    IS2.header = 0x00;
    printf("    header \t%02x\n", IS2.header);

    IS2.managed = 0xff;
    printf("    managed \t%02x\n", IS2.managed);

    IS2.device_number = (number++);
    printf("    device_number \t%d\n", IS2.device_number);

    IS2.state = cntrl;
    printf("    state \t%02x\n", IS2.state);

    IS1.crc = im.calculateCRC(&IS2, (sizeof (_is2) - 1));
    printf("    cs \t%02x\n", IS2.crc);
    qDebug() << "-----\n";

    return IS2;
}

output_state FormingIM_pvkp::getOutputState(int number)
{
    return io.getOutputValue(number);
}

output_state FormingIM_pvkp::getOutputState2(unsigned char state)
{
    output_state res = error_output;

    if ((state & output_on) == output_on)
    {
        res = output_on;
    }
    if ((state & output_off) == output_off)
    {
        res = output_off;
    }
    if ((state & no_output_state) == no_output_state)
    {
        res = no_output_state;
    }
    if ((state ^ error_output) == error_output)
    {
        res = error_output;
    }

    return res;
}

char *FormingIM_pvkp::getOutputs()
{
    return io.getAllOutputs();
}

char *FormingIM_pvkp::getInputs()
{
    return io.getAllInputs();
}
