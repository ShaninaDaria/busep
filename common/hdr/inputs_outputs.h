#ifndef INPUTS_OUTPUTS_H
#define INPUTS_OUTPUTS_H

enum input_state
{
    no_signal_27v = 0x01,
    is_signal_27v = 0x02,
    no_input_state = 0x03
};

enum output_state
{
    output_on = 0x01,
    output_off = 0x02,
    no_output_state = 0x03,
    error_output = 0x00
};

enum output_cntrl
{
    cntrl_off = 0x00,
    cntrl_on = 0x01
};

struct _inputs  // 124
{
    unsigned _input1:2; unsigned _input2:2;
    unsigned _input3:2; unsigned _input4:2;
    unsigned _input5:2; unsigned _input6:2;
    unsigned _input7:2; unsigned _input8:2;
    unsigned _input9:2; unsigned _input10:2;
    unsigned _input11:2; unsigned _input12:2;
    unsigned _input13:2; unsigned _input14:2;
    unsigned _input15:2; unsigned _input16:2;
    unsigned _input17:2; unsigned _input18:2;
    unsigned _input19:2; unsigned _input20:2;
    unsigned _input21:2; unsigned _input22:2;
    unsigned _input23:2; unsigned _input24:2;
    unsigned _input25:2; unsigned _input26:2;
    unsigned _input27:2; unsigned _input28:2;
    unsigned _input29:2; unsigned _input30:2;
    unsigned _input31:2; unsigned _input32:2;
    unsigned _input33:2; unsigned _input34:2;
    unsigned _input35:2; unsigned _input36:2;
    unsigned _input37:2; unsigned _input38:2;
    unsigned _input39:2; unsigned _input40:2;
    unsigned _input41:2; unsigned _input42:2;
    unsigned _input43:2; unsigned _input44:2;
    unsigned _input45:2; unsigned _input46:2;
    unsigned _input47:2; unsigned _input48:2;
    unsigned _input49:2; unsigned _input50:2;
    unsigned _input51:2; unsigned _input52:2;
    unsigned _input53:2; unsigned _input54:2;
    unsigned _input55:2; unsigned _input56:2;
    unsigned _input57:2; unsigned _input58:2;
    unsigned _input59:2; unsigned _input60:2;
    unsigned _input61:2; unsigned _input62:2;
    unsigned _input63:2; unsigned _input64:2;
    unsigned _input65:2; unsigned _input66:2;
    unsigned _input67:2; unsigned _input68:2;
    unsigned _input69:2; unsigned _input70:2;
    unsigned _input71:2; unsigned _input72:2;
    unsigned _input73:2; unsigned _input74:2;
    unsigned _input75:2; unsigned _input76:2;
    unsigned _input77:2; unsigned _input78:2;
    unsigned _input79:2; unsigned _input80:2;
    unsigned _input81:2; unsigned _input82:2;
    unsigned _input83:2; unsigned _input84:2;
    unsigned _input85:2; unsigned _input86:2;
    unsigned _input87:2; unsigned _input88:2;
    unsigned _input89:2; unsigned _input90:2;
    unsigned _input91:2; unsigned _input92:2;
    unsigned _input93:2; unsigned _input94:2;
    unsigned _input95:2; unsigned _input96:2;
    unsigned _input97:2; unsigned _input98:2;
    unsigned _input99:2; unsigned _input100:2;
    unsigned _input101:2; unsigned _input102:2;
    unsigned _input103:2; unsigned _input104:2;
    unsigned _input105:2; unsigned _input106:2;
    unsigned _input107:2; unsigned _input108:2;
    unsigned _input109:2; unsigned _input110:2;
    unsigned _input111:2; unsigned _input112:2;
    unsigned _input113:2; unsigned _input114:2;
    unsigned _input115:2; unsigned _input116:2;
    unsigned _input117:2; unsigned _input118:2;
    unsigned _input119:2; unsigned _input120:2;
    unsigned _input121:2; unsigned _input122:2;
    unsigned _input123:2; unsigned _input124:2;

public:
    unsigned input1() const; void setInput1(const unsigned &input1);
    unsigned input2() const; void setInput2(const unsigned &input2);
    unsigned input3() const; void setInput3(const unsigned &input3);
    unsigned input4() const; void setInput4(const unsigned &input4);
    unsigned input5() const; void setInput5(const unsigned &input5);
    unsigned input6() const; void setInput6(const unsigned &input6);
    unsigned input7() const; void setInput7(const unsigned &input7);
    unsigned input8() const; void setInput8(const unsigned &input8);
    unsigned input9() const; void setInput9(const unsigned &input9);
    unsigned input10() const; void setInput10(const unsigned &input10);
    unsigned input11() const; void setInput11(const unsigned &input11);
    unsigned input12() const; void setInput12(const unsigned &input12);
    unsigned input13() const; void setInput13(const unsigned &input13);
    unsigned input14() const; void setInput14(const unsigned &input14);
    unsigned input15() const; void setInput15(const unsigned &input15);
    unsigned input16() const; void setInput16(const unsigned &input16);
    unsigned input17() const; void setInput17(const unsigned &input17);
    unsigned input18() const; void setInput18(const unsigned &input18);
    unsigned input19() const; void setInput19(const unsigned &input19);
    unsigned input20() const; void setInput20(const unsigned &input20);
    unsigned input21() const; void setInput21(const unsigned &input21);
    unsigned input22() const; void setInput22(const unsigned &input22);
    unsigned input23() const; void setInput23(const unsigned &input23);
    unsigned input24() const; void setInput24(const unsigned &input24);
    unsigned input25() const; void setInput25(const unsigned &input25);
    unsigned input26() const; void setInput26(const unsigned &input26);
    unsigned input27() const; void setInput27(const unsigned &input27);
    unsigned input28() const; void setInput28(const unsigned &input28);
    unsigned input29() const; void setInput29(const unsigned &input29);
    unsigned input30() const; void setInput30(const unsigned &input30);
    unsigned input31() const; void setInput31(const unsigned &input31);
    unsigned input32() const; void setInput32(const unsigned &input32);
    unsigned input33() const; void setInput33(const unsigned &input33);
    unsigned input34() const; void setInput34(const unsigned &input34);
    unsigned input35() const; void setInput35(const unsigned &input35);
    unsigned input36() const; void setInput36(const unsigned &input36);
    unsigned input37() const; void setInput37(const unsigned &input37);
    unsigned input38() const; void setInput38(const unsigned &input38);
    unsigned input39() const; void setInput39(const unsigned &input39);
    unsigned input40() const; void setInput40(const unsigned &input40);
    unsigned input41() const; void setInput41(const unsigned &input41);
    unsigned input42() const; void setInput42(const unsigned &input42);
    unsigned input43() const; void setInput43(const unsigned &input43);
    unsigned input44() const; void setInput44(const unsigned &input44);
    unsigned input45() const; void setInput45(const unsigned &input45);
    unsigned input46() const; void setInput46(const unsigned &input46);
    unsigned input47() const; void setInput47(const unsigned &input47);
    unsigned input48() const; void setInput48(const unsigned &input48);
    unsigned input49() const; void setInput49(const unsigned &input49);
    unsigned input50() const; void setInput50(const unsigned &input50);
    unsigned input51() const; void setInput51(const unsigned &input51);
    unsigned input52() const; void setInput52(const unsigned &input52);
    unsigned input53() const; void setInput53(const unsigned &input53);
    unsigned input54() const; void setInput54(const unsigned &input54);
    unsigned input55() const; void setInput55(const unsigned &input55);
    unsigned input56() const; void setInput56(const unsigned &input56);
    unsigned input57() const; void setInput57(const unsigned &input57);
    unsigned input58() const; void setInput58(const unsigned &input58);
    unsigned input59() const; void setInput59(const unsigned &input59);
    unsigned input60() const; void setInput60(const unsigned &input60);
    unsigned input61() const; void setInput61(const unsigned &input61);
    unsigned input62() const; void setInput62(const unsigned &input62);
    unsigned input63() const; void setInput63(const unsigned &input63);
    unsigned input64() const; void setInput64(const unsigned &input64);
    unsigned input65() const; void setInput65(const unsigned &input65);
    unsigned input66() const; void setInput66(const unsigned &input66);
    unsigned input67() const; void setInput67(const unsigned &input67);
    unsigned input68() const; void setInput68(const unsigned &input68);
    unsigned input69() const; void setInput69(const unsigned &input69);
    unsigned input70() const; void setInput70(const unsigned &input70);
    unsigned input71() const; void setInput71(const unsigned &input71);
    unsigned input72() const; void setInput72(const unsigned &input72);
    unsigned input73() const; void setInput73(const unsigned &input73);
    unsigned input74() const; void setInput74(const unsigned &input74);
    unsigned input75() const; void setInput75(const unsigned &input75);
    unsigned input76() const; void setInput76(const unsigned &input76);
    unsigned input77() const; void setInput77(const unsigned &input77);
    unsigned input78() const; void setInput78(const unsigned &input78);
    unsigned input79() const; void setInput79(const unsigned &input79);
    unsigned input80() const; void setInput80(const unsigned &input80);
    unsigned input81() const; void setInput81(const unsigned &input81);
    unsigned input82() const; void setInput82(const unsigned &input82);
    unsigned input83() const; void setInput83(const unsigned &input83);
    unsigned input84() const; void setInput84(const unsigned &input84);
    unsigned input85() const; void setInput85(const unsigned &input85);
    unsigned input86() const; void setInput86(const unsigned &input86);
    unsigned input87() const; void setInput87(const unsigned &input87);
    unsigned input88() const; void setInput88(const unsigned &input88);
    unsigned input89() const; void setInput89(const unsigned &input89);
    unsigned input90() const; void setInput90(const unsigned &input90);
    unsigned input91() const; void setInput91(const unsigned &input91);
    unsigned input92() const; void setInput92(const unsigned &input92);
    unsigned input93() const; void setInput93(const unsigned &input93);
    unsigned input94() const; void setInput94(const unsigned &input94);
    unsigned input95() const; void setInput95(const unsigned &input95);
    unsigned input96() const; void setInput96(const unsigned &input96);
    unsigned input97() const; void setInput97(const unsigned &input97);
    unsigned input98() const; void setInput98(const unsigned &input98);
    unsigned input99() const; void setInput99(const unsigned &input99);
    unsigned input100() const; void setInput100(const unsigned &input100);
    unsigned input101() const; void setInput101(const unsigned &input101);
    unsigned input102() const; void setInput102(const unsigned &input102);
    unsigned input103() const; void setInput103(const unsigned &input103);
    unsigned input104() const; void setInput104(const unsigned &input104);
    unsigned input105() const; void setInput105(const unsigned &input105);
    unsigned input106() const; void setInput106(const unsigned &input106);
    unsigned input107() const; void setInput107(const unsigned &input107);
    unsigned input108() const; void setInput108(const unsigned &input108);
    unsigned input109() const; void setInput109(const unsigned &input109);
    unsigned input110() const; void setInput110(const unsigned &input110);
    unsigned input111() const; void setInput111(const unsigned &input111);
    unsigned input112() const; void setInput112(const unsigned &input112);
    unsigned input113() const; void setInput113(const unsigned &input113);
    unsigned input114() const; void setInput114(const unsigned &input114);
    unsigned input115() const; void setInput115(const unsigned &input115);
    unsigned input116() const; void setInput116(const unsigned &input116);
    unsigned input117() const; void setInput117(const unsigned &input117);
    unsigned input118() const; void setInput118(const unsigned &input118);
    unsigned input119() const; void setInput119(const unsigned &input119);
    unsigned input120() const; void setInput120(const unsigned &input120);
    unsigned input121() const; void setInput121(const unsigned &input121);
    unsigned input122() const; void setInput122(const unsigned &input122);
    unsigned input123() const; void setInput123(const unsigned &input123);
    unsigned input124() const; void setInput124(const unsigned &input124);
};

struct _outputs // 62
{
    unsigned _output1:2; unsigned _output2:2;
    unsigned _output3:2; unsigned _output4:2;
    unsigned _output5:2; unsigned _output6:2;
    unsigned _output7:2; unsigned _output8:2;
    unsigned _output9:2; unsigned _output10:2;
    unsigned _output11:2; unsigned _output12:2;
    unsigned _output13:2; unsigned _output14:2;
    unsigned _output15:2; unsigned _output16:2;
    unsigned _output17:2; unsigned _output18:2;
    unsigned _output19:2; unsigned _output20:2;
    unsigned _output21:2; unsigned _output22:2;
    unsigned _output23:2; unsigned _output24:2;
    unsigned _output25:2; unsigned _output26:2;
    unsigned _output27:2; unsigned _output28:2;
    unsigned _output29:2; unsigned _output30:2;
    unsigned _output31:2; unsigned _output32:2;
    unsigned _output33:2; unsigned _output34:2;
    unsigned _output35:2; unsigned _output36:2;
    unsigned _output37:2; unsigned _output38:2;
    unsigned _output39:2; unsigned _output40:2;
    unsigned _output41:2; unsigned _output42:2;
    unsigned _output43:2; unsigned _output44:2;
    unsigned _output45:2; unsigned _output46:2;
    unsigned _output47:2; unsigned _output48:2;
    unsigned _output49:2; unsigned _output50:2;
    unsigned _output51:2; unsigned _output52:2;
    unsigned _output53:2; unsigned _output54:2;
    unsigned _output55:2; unsigned _output56:2;
    unsigned _output57:2; unsigned _output58:2;
    unsigned _output59:2; unsigned _output60:2;
    unsigned _output61:2; unsigned _output62:2;

public:
    unsigned output1() const; void setOutput1(const unsigned &output1);
    unsigned output2() const; void setOutput2(const unsigned &output2);
    unsigned output3() const; void setOutput3(const unsigned &output3);
    unsigned output4() const; void setOutput4(const unsigned &output4);
    unsigned output5() const; void setOutput5(const unsigned &output5);
    unsigned output6() const; void setOutput6(const unsigned &output6);
    unsigned output7() const; void setOutput7(const unsigned &output7);
    unsigned output8() const; void setOutput8(const unsigned &output8);
    unsigned output9() const; void setOutput9(const unsigned &output9);
    unsigned output10() const; void setOutput10(const unsigned &output10);
    unsigned output11() const; void setOutput11(const unsigned &output11);
    unsigned output12() const; void setOutput12(const unsigned &output12);
    unsigned output13() const; void setOutput13(const unsigned &output13);
    unsigned output14() const; void setOutput14(const unsigned &output14);
    unsigned output15() const; void setOutput15(const unsigned &output15);
    unsigned output16() const; void setOutput16(const unsigned &output16);
    unsigned output17() const; void setOutput17(const unsigned &output17);
    unsigned output18() const; void setOutput18(const unsigned &output18);
    unsigned output19() const; void setOutput19(const unsigned &output19);
    unsigned output20() const; void setOutput20(const unsigned &output20);
    unsigned output21() const; void setOutput21(const unsigned &output21);
    unsigned output22() const; void setOutput22(const unsigned &output22);
    unsigned output23() const; void setOutput23(const unsigned &output23);
    unsigned output24() const; void setOutput24(const unsigned &output24);
    unsigned output25() const; void setOutput25(const unsigned &output25);
    unsigned output26() const; void setOutput26(const unsigned &output26);
    unsigned output27() const; void setOutput27(const unsigned &output27);
    unsigned output28() const; void setOutput28(const unsigned &output28);
    unsigned output29() const; void setOutput29(const unsigned &output29);
    unsigned output30() const; void setOutput30(const unsigned &output30);
    unsigned output31() const; void setOutput31(const unsigned &output31);
    unsigned output32() const; void setOutput32(const unsigned &output32);
    unsigned output33() const; void setOutput33(const unsigned &output33);
    unsigned output34() const; void setOutput34(const unsigned &output34);
    unsigned output35() const; void setOutput35(const unsigned &output35);
    unsigned output36() const; void setOutput36(const unsigned &output36);
    unsigned output37() const; void setOutput37(const unsigned &output37);
    unsigned output38() const; void setOutput38(const unsigned &output38);
    unsigned output39() const; void setOutput39(const unsigned &output39);
    unsigned output40() const; void setOutput40(const unsigned &output40);
    unsigned output41() const; void setOutput41(const unsigned &output41);
    unsigned output42() const; void setOutput42(const unsigned &output42);
    unsigned output43() const; void setOutput43(const unsigned &output43);
    unsigned output44() const; void setOutput44(const unsigned &output44);
    unsigned output45() const; void setOutput45(const unsigned &output45);
    unsigned output46() const; void setOutput46(const unsigned &output46);
    unsigned output47() const; void setOutput47(const unsigned &output47);
    unsigned output48() const; void setOutput48(const unsigned &output48);
    unsigned output49() const; void setOutput49(const unsigned &output49);
    unsigned output50() const; void setOutput50(const unsigned &output50);
    unsigned output51() const; void setOutput51(const unsigned &output51);
    unsigned output52() const; void setOutput52(const unsigned &output52);
    unsigned output53() const; void setOutput53(const unsigned &output53);
    unsigned output54() const; void setOutput54(const unsigned &output54);
    unsigned output55() const; void setOutput55(const unsigned &output55);
    unsigned output56() const; void setOutput56(const unsigned &output56);
    unsigned output57() const; void setOutput57(const unsigned &output57);
    unsigned output58() const; void setOutput58(const unsigned &output58);
    unsigned output59() const; void setOutput59(const unsigned &output59);
    unsigned output60() const; void setOutput60(const unsigned &output60);
    unsigned output61() const; void setOutput61(const unsigned &output61);
    unsigned output62() const; void setOutput62(const unsigned &output62);
};

class InputsOutputs
{
public:
    InputsOutputs();
    _inputs getInputs() const;
    _inputs changeInputs();
    void setInputs(const _inputs &value);

    _outputs getOutputs() const;
    _outputs changeOutputs();
    void setOutputs(const _outputs &value);

//    void showInputs();

    _inputs inputs;
    _outputs outputs;
};

#endif // INPUTS_OUTPUTS_H
