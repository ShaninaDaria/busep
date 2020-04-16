#include "informationmessages.h"

informationMessages::informationMessages()
{

}

void informationMessages::createIS1()
{
    qDebug() << "IS1";
    IS1.header = 0xff;
    qDebug() << "header" << IS1.header;
    IS1.managed = 0x01;
    qDebug() << "managed" << IS1.managed;
    qDebug() << "-----\n";
}

void informationMessages::createIS2(char number)
{
    qDebug() << "IS2";
    IS2.header = 0xff;
    qDebug() << "header" << IS2.header;
    IS2.managed = 0x02;
    qDebug() << "managed" << IS2.managed;
    IS2.device_number = number;
    qDebug() << "device_number" << IS2.device_number;
    IS2.state = 0x01;
    qDebug() << "state" << IS2.state;
    qDebug() << "-----\n";
}

void informationMessages::createIS3()
{
    qDebug() << "IS3";
    IS3.header = 0xff;
    qDebug() << "header" << IS3.header;
    IS3.managed = 0x02;
    qDebug() << "managed" << IS3.managed;

    inputs = io.changeInputs();

    IS3.word0 |= io.getInputs().input4();
    IS3.word0 = IS3.word0 << 2;
    IS3.word0 |= io.getInputs().input3();
    IS3.word0 = IS3.word0 << 2;
    IS3.word0 |= io.getInputs().input2();
    IS3.word0 = IS3.word0 << 2;
    IS3.word0 |= io.getInputs().input1();
    qDebug() << "word0" << IS3.word0;

    IS3.word1 |= io.getInputs().input8();
    IS3.word1 = IS3.word1 << 2;
    IS3.word1 |= io.getInputs().input7();
    IS3.word1 = IS3.word1 << 2;
    IS3.word1 |= io.getInputs().input6();
    IS3.word1 = IS3.word1 << 2;
    IS3.word1 |= io.getInputs().input5();
    qDebug() << "word1" << IS3.word1;

    IS3.word2 |= io.getInputs().input12();
    IS3.word2 = IS3.word2 << 2;
    IS3.word2 |= io.getInputs().input11();
    IS3.word2 = IS3.word2 << 2;
    IS3.word2 |= io.getInputs().input10();
    IS3.word2 = IS3.word2 << 2;
    IS3.word2 |= io.getInputs().input9();
    qDebug() << "word2" << IS3.word2;

    IS3.word3 |= io.getInputs().input16();
    IS3.word3 = IS3.word3 << 2;
    IS3.word3 |= io.getInputs().input15();
    IS3.word3 = IS3.word3 << 2;
    IS3.word3 |= io.getInputs().input14();
    IS3.word3 = IS3.word3 << 2;
    IS3.word3 |= io.getInputs().input13();
    qDebug() << "word3" << IS3.word3;

    IS3.word4 |= io.getInputs().input20();
    IS3.word4 = IS3.word4 << 2;
    IS3.word4 |= io.getInputs().input19();
    IS3.word4 = IS3.word4 << 2;
    IS3.word4 |= io.getInputs().input18();
    IS3.word4 = IS3.word4 << 2;
    IS3.word4 |= io.getInputs().input17();
    qDebug() << "word4" << IS3.word4;

    IS3.word5 |= io.getInputs().input24();
    IS3.word5 = IS3.word5 << 2;
    IS3.word5 |= io.getInputs().input23();
    IS3.word5 = IS3.word5 << 2;
    IS3.word5 |= io.getInputs().input22();
    IS3.word5 = IS3.word5 << 2;
    IS3.word5 |= io.getInputs().input21();
    qDebug() << "word5" << IS3.word5;

    IS3.word6 |= io.getInputs().input28();
    IS3.word6 = IS3.word6 << 2;
    IS3.word6 |= io.getInputs().input27();
    IS3.word6 = IS3.word6 << 2;
    IS3.word6 |= io.getInputs().input26();
    IS3.word6 = IS3.word6 << 2;
    IS3.word6 |= io.getInputs().input25();
    qDebug() << "word6" << IS3.word6;

    IS3.word7 |= io.getInputs().input32();
    IS3.word7 = IS3.word7 << 2;
    IS3.word7 |= io.getInputs().input31();
    IS3.word7 = IS3.word7 << 2;
    IS3.word7 |= io.getInputs().input30();
    IS3.word7 = IS3.word7 << 2;
    IS3.word7 |= io.getInputs().input29();
    qDebug() << "word7" << IS3.word7;

    IS3.word8 |= io.getInputs().input36();
    IS3.word8 = IS3.word8 << 2;
    IS3.word8 |= io.getInputs().input35();
    IS3.word8 = IS3.word8 << 2;
    IS3.word8 |= io.getInputs().input34();
    IS3.word8 = IS3.word8 << 2;
    IS3.word8 |= io.getInputs().input33();
    qDebug() << "word8" << IS3.word8;

    IS3.word9 |= io.getInputs().input40();
    IS3.word9 = IS3.word9 << 2;
    IS3.word9 |= io.getInputs().input39();
    IS3.word9 = IS3.word9 << 2;
    IS3.word9 |= io.getInputs().input38();
    IS3.word9 = IS3.word9 << 2;
    IS3.word9 |= io.getInputs().input37();
    qDebug() << "word9" << IS3.word9;

    IS3.word10 |= io.getInputs().input44();
    IS3.word10 = IS3.word10 << 2;
    IS3.word10 |= io.getInputs().input43();
    IS3.word10 = IS3.word10 << 2;
    IS3.word10 |= io.getInputs().input42();
    IS3.word10 = IS3.word10 << 2;
    IS3.word10 |= io.getInputs().input41();
    qDebug() << "word10" << IS3.word10;

    IS3.word11 |= io.getInputs().input48();
    IS3.word11 = IS3.word11 << 2;
    IS3.word11 |= io.getInputs().input47();
    IS3.word11 = IS3.word11 << 2;
    IS3.word11 |= io.getInputs().input46();
    IS3.word11 = IS3.word11 << 2;
    IS3.word11 |= io.getInputs().input45();
    qDebug() << "word11" << IS3.word11;

    IS3.word12 |= io.getInputs().input52();
    IS3.word12 = IS3.word12 << 2;
    IS3.word12 |= io.getInputs().input51();
    IS3.word12 = IS3.word12 << 2;
    IS3.word12 |= io.getInputs().input50();
    IS3.word12 = IS3.word12 << 2;
    IS3.word12 |= io.getInputs().input49();
    qDebug() << "word12" << IS3.word12;

    IS3.word13 |= io.getInputs().input56();
    IS3.word13 = IS3.word13 << 2;
    IS3.word13 |= io.getInputs().input55();
    IS3.word13 = IS3.word13 << 2;
    IS3.word13 |= io.getInputs().input54();
    IS3.word13 = IS3.word13 << 2;
    IS3.word13 |= io.getInputs().input53();
    qDebug() << "word13" << IS3.word13;

    IS3.word14 |= io.getInputs().input60();
    IS3.word14 = IS3.word14 << 2;
    IS3.word14 |= io.getInputs().input59();
    IS3.word14 = IS3.word14 << 2;
    IS3.word14 |= io.getInputs().input58();
    IS3.word14 = IS3.word14 << 2;
    IS3.word14 |= io.getInputs().input57();
    qDebug() << "word14" << IS3.word14;

    IS3.word15 |= io.getInputs().input64();
    IS3.word15 = IS3.word15 << 2;
    IS3.word15 |= io.getInputs().input63();
    IS3.word15 = IS3.word15 << 2;
    IS3.word15 |= io.getInputs().input62();
    IS3.word15 = IS3.word15 << 2;
    IS3.word15 |= io.getInputs().input61();
    qDebug() << "word15" << IS3.word15;

    IS3.word16 |= io.getInputs().input68();
    IS3.word16 = IS3.word16 << 2;
    IS3.word16 |= io.getInputs().input67();
    IS3.word16 = IS3.word16 << 2;
    IS3.word16 |= io.getInputs().input66();
    IS3.word16 = IS3.word16 << 2;
    IS3.word16 |= io.getInputs().input65();
    qDebug() << "word16" << IS3.word16;

    IS3.word17 |= io.getInputs().input72();
    IS3.word17 = IS3.word17 << 2;
    IS3.word17 |= io.getInputs().input71();
    IS3.word17 = IS3.word17 << 2;
    IS3.word17 |= io.getInputs().input70();
    IS3.word17 = IS3.word17 << 2;
    IS3.word17 |= io.getInputs().input69();
    qDebug() << "word17" << IS3.word17;

    IS3.word18 |= io.getInputs().input76();
    IS3.word18 = IS3.word18 << 2;
    IS3.word18 |= io.getInputs().input75();
    IS3.word18 = IS3.word18 << 2;
    IS3.word18 |= io.getInputs().input74();
    IS3.word18 = IS3.word18 << 2;
    IS3.word18 |= io.getInputs().input73();
    qDebug() << "word18" << IS3.word18;

    IS3.word19 |= io.getInputs().input80();
    IS3.word19 = IS3.word19 << 2;
    IS3.word19 |= io.getInputs().input79();
    IS3.word19 = IS3.word19 << 2;
    IS3.word19 |= io.getInputs().input78();
    IS3.word19 = IS3.word19 << 2;
    IS3.word19 |= io.getInputs().input77();
    qDebug() << "word19" << IS3.word19;

    IS3.word20 |= io.getInputs().input84();
    IS3.word20 = IS3.word20 << 2;
    IS3.word20 |= io.getInputs().input33();
    IS3.word20 = IS3.word20 << 2;
    IS3.word20 |= io.getInputs().input82();
    IS3.word20 = IS3.word20 << 2;
    IS3.word20 |= io.getInputs().input81();
    qDebug() << "word20" << IS3.word20;

    IS3.word21 |= io.getInputs().input88();
    IS3.word21 = IS3.word21 << 2;
    IS3.word21 |= io.getInputs().input87();
    IS3.word21 = IS3.word21 << 2;
    IS3.word21 |= io.getInputs().input86();
    IS3.word21 = IS3.word21 << 2;
    IS3.word21 |= io.getInputs().input85();
    qDebug() << "word21" << IS3.word21;

    IS3.word22 |= io.getInputs().input92();
    IS3.word22 = IS3.word22 << 2;
    IS3.word22 |= io.getInputs().input91();
    IS3.word22 = IS3.word22 << 2;
    IS3.word22 |= io.getInputs().input90();
    IS3.word22 = IS3.word22 << 2;
    IS3.word22 |= io.getInputs().input89();
    qDebug() << "word22" << IS3.word22;

    IS3.word23 |= io.getInputs().input96();
    IS3.word23 = IS3.word0 << 2;
    IS3.word23 |= io.getInputs().input95();
    IS3.word23 = IS3.word0 << 2;
    IS3.word23 |= io.getInputs().input94();
    IS3.word23 = IS3.word0 << 2;
    IS3.word23 |= io.getInputs().input93();
    qDebug() << "word0" << IS3.word0;

    IS3.word24 |= io.getInputs().input100();
    IS3.word24 = IS3.word24 << 2;
    IS3.word24 |= io.getInputs().input99();
    IS3.word24 = IS3.word24 << 2;
    IS3.word24 |= io.getInputs().input98();
    IS3.word24 = IS3.word24 << 2;
    IS3.word24 |= io.getInputs().input97();
    qDebug() << "word24" << IS3.word24;

    IS3.word25 |= io.getInputs().input104();
    IS3.word25 = IS3.word25 << 2;
    IS3.word25 |= io.getInputs().input103();
    IS3.word25 = IS3.word25 << 2;
    IS3.word25 |= io.getInputs().input102();
    IS3.word25 = IS3.word25 << 2;
    IS3.word25 |= io.getInputs().input101();
    qDebug() << "word25" << IS3.word25;

    IS3.word26 |= io.getInputs().input108();
    IS3.word26 = IS3.word26 << 2;
    IS3.word26 |= io.getInputs().input107();
    IS3.word26 = IS3.word26 << 2;
    IS3.word26 |= io.getInputs().input106();
    IS3.word26 = IS3.word26 << 2;
    IS3.word26 |= io.getInputs().input105();
    qDebug() << "word26" << IS3.word26;

    IS3.word27 |= io.getInputs().input112();
    IS3.word27 = IS3.word27 << 2;
    IS3.word27 |= io.getInputs().input111();
    IS3.word27 = IS3.word27 << 2;
    IS3.word27 |= io.getInputs().input110();
    IS3.word27 = IS3.word27 << 2;
    IS3.word27 |= io.getInputs().input109();
    qDebug() << "word27" << IS3.word27;

    IS3.word28 |= io.getInputs().input116();
    IS3.word28 = IS3.word28 << 2;
    IS3.word28 |= io.getInputs().input115();
    IS3.word28 = IS3.word28 << 2;
    IS3.word28 |= io.getInputs().input114();
    IS3.word28 = IS3.word28 << 2;
    IS3.word28 |= io.getInputs().input113();
    qDebug() << "word28" << IS3.word28;

    IS3.word29 |= io.getInputs().input120();
    IS3.word29 = IS3.word29 << 2;
    IS3.word29 |= io.getInputs().input119();
    IS3.word29 = IS3.word29 << 2;
    IS3.word29 |= io.getInputs().input118();
    IS3.word29 = IS3.word29 << 2;
    IS3.word29 |= io.getInputs().input117();
    qDebug() << "word0" << IS3.word29;

    IS3.word30 |= io.getInputs().input124();
    IS3.word30 = IS3.word30 << 2;
    IS3.word30 |= io.getInputs().input123();
    IS3.word30 = IS3.word30 << 2;
    IS3.word30 |= io.getInputs().input122();
    IS3.word30 = IS3.word30 << 2;
    IS3.word30 |= io.getInputs().input121();
    qDebug() << "word30" << IS3.word30;
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
    parsingIS3();
}

void informationMessages::setIS4(const _is4 &value)
{
    IS4 = value;
}

void informationMessages::parsingIS3()
{
    // inputs 1-4
    // 01 10 11 01
    IS3.word0 ^= 0x100000011;
}
