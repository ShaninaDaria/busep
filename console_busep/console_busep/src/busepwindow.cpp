#include "hdr/busepwindow.h"
#include "ui_busepwindow.h"

BusepWindow::BusepWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BusepWindow)
{
    ui->setupUi(this);
    createPalette();

    connect(ui->allInputsOff, SIGNAL(pressed()), this, SLOT(slotAllInputsOff()));
    connect(ui->allInputsOn, SIGNAL(pressed()), this, SLOT(slotAllInputsOn()));

    dm = new DummyMessages();
//    timer = new QTimer(this);
//    connect(timer, SIGNAL (timeout()), this, SLOT(slotStartExchangeByTimer()));
//    timer->start(1000);



    slotStartExchangeByTimer();
}

BusepWindow::~BusepWindow()
{
//    timer->stop();
    delete dm;
    delete ui;
}

void BusepWindow::slotAllInputsOff()
{
    qDebug() << __FUNCTION__;
    dm->createIS3(no_signal_27v);

    ui->input1->setChecked(true);
    ui->input2->setChecked(true);
    ui->input3->setChecked(true);
    ui->input4->setChecked(true);
    ui->input5->setChecked(true);
    ui->input6->setChecked(true);
    ui->input7->setChecked(true);
    ui->input8->setChecked(true);
    ui->input9->setChecked(true);
    ui->input10->setChecked(true);
    ui->input11->setChecked(true);
    ui->input12->setChecked(true);
    ui->input13->setChecked(true);
    ui->input14->setChecked(true);
    ui->input15->setChecked(true);
    ui->input16->setChecked(true);
    ui->input17->setChecked(true);
    ui->input18->setChecked(true);
    ui->input19->setChecked(true);
    ui->input20->setChecked(true);
    ui->input21->setChecked(true);
    ui->input22->setChecked(true);
    ui->input23->setChecked(true);
    ui->input24->setChecked(true);
    ui->input25->setChecked(true);
    ui->input26->setChecked(true);
    ui->input27->setChecked(true);
    ui->input28->setChecked(true);
    ui->input29->setChecked(true);
    ui->input30->setChecked(true);
    ui->input31->setChecked(true);
    ui->input32->setChecked(true);
    ui->input33->setChecked(true);
    ui->input34->setChecked(true);
    ui->input35->setChecked(true);
    ui->input36->setChecked(true);
    ui->input37->setChecked(true);
    ui->input38->setChecked(true);
    ui->input39->setChecked(true);
    ui->input40->setChecked(true);
    ui->input41->setChecked(true);
    ui->input42->setChecked(true);
    ui->input43->setChecked(true);
    ui->input44->setChecked(true);
    ui->input45->setChecked(true);
    ui->input46->setChecked(true);
    ui->input47->setChecked(true);
    ui->input48->setChecked(true);
    ui->input49->setChecked(true);
    ui->input50->setChecked(true);
    ui->input51->setChecked(true);
    ui->input52->setChecked(true);
    ui->input53->setChecked(true);
    ui->input54->setChecked(true);
    ui->input55->setChecked(true);
    ui->input56->setChecked(true);
    ui->input57->setChecked(true);
    ui->input58->setChecked(true);
    ui->input59->setChecked(true);
    ui->input60->setChecked(true);
    ui->input61->setChecked(true);
    ui->input62->setChecked(true);

    ui->input63->setChecked(true);
    ui->input64->setChecked(true);
    ui->input65->setChecked(true);
    ui->input66->setChecked(true);
    ui->input67->setChecked(true);
    ui->input68->setChecked(true);
    ui->input69->setChecked(true);
    ui->input70->setChecked(true);
    ui->input71->setChecked(true);
    ui->input72->setChecked(true);
    ui->input73->setChecked(true);
    ui->input74->setChecked(true);
    ui->input75->setChecked(true);
    ui->input76->setChecked(true);
    ui->input77->setChecked(true);
    ui->input78->setChecked(true);
    ui->input79->setChecked(true);
    ui->input80->setChecked(true);
    ui->input81->setChecked(true);
    ui->input82->setChecked(true);
    ui->input83->setChecked(true);
    ui->input84->setChecked(true);
    ui->input85->setChecked(true);
    ui->input86->setChecked(true);
    ui->input87->setChecked(true);
    ui->input88->setChecked(true);
    ui->input89->setChecked(true);
    ui->input90->setChecked(true);
    ui->input91->setChecked(true);
    ui->input92->setChecked(true);
    ui->input93->setChecked(true);
    ui->input94->setChecked(true);
    ui->input95->setChecked(true);
    ui->input96->setChecked(true);
    ui->input97->setChecked(true);
    ui->input98->setChecked(true);
    ui->input99->setChecked(true);
    ui->input100->setChecked(true);
    ui->input101->setChecked(true);
    ui->input102->setChecked(true);
    ui->input103->setChecked(true);
    ui->input104->setChecked(true);
    ui->input105->setChecked(true);
    ui->input106->setChecked(true);
    ui->input107->setChecked(true);
    ui->input108->setChecked(true);
    ui->input109->setChecked(true);
    ui->input110->setChecked(true);
    ui->input111->setChecked(true);
    ui->input112->setChecked(true);
    ui->input113->setChecked(true);
    ui->input114->setChecked(true);
    ui->input115->setChecked(true);
    ui->input116->setChecked(true);
    ui->input117->setChecked(true);
    ui->input118->setChecked(true);
    ui->input119->setChecked(true);
    ui->input120->setChecked(true);
    ui->input121->setChecked(true);
    ui->input122->setChecked(true);
    ui->input123->setChecked(true);
    ui->input124->setChecked(true);

//    showInputsValue();
}

void BusepWindow::slotAllInputsOn()
{
    qDebug() << __FUNCTION__;
    dm->createIS3(is_signal_27v);

    ui->input1->setChecked(false);
    ui->input2->setChecked(false);
    ui->input3->setChecked(false);
    ui->input4->setChecked(false);
    ui->input5->setChecked(false);
    ui->input6->setChecked(false);
    ui->input7->setChecked(false);
    ui->input8->setChecked(false);
    ui->input9->setChecked(false);
    ui->input10->setChecked(false);
    ui->input11->setChecked(false);
    ui->input12->setChecked(false);
    ui->input13->setChecked(false);
    ui->input14->setChecked(false);
    ui->input15->setChecked(false);
    ui->input16->setChecked(false);
    ui->input17->setChecked(false);
    ui->input18->setChecked(false);
    ui->input19->setChecked(false);
    ui->input20->setChecked(false);
    ui->input21->setChecked(false);
    ui->input22->setChecked(false);
    ui->input23->setChecked(false);
    ui->input24->setChecked(false);
    ui->input25->setChecked(false);
    ui->input26->setChecked(false);
    ui->input27->setChecked(false);
    ui->input28->setChecked(false);
    ui->input29->setChecked(false);
    ui->input30->setChecked(false);
    ui->input31->setChecked(false);
    ui->input32->setChecked(false);
    ui->input33->setChecked(false);
    ui->input34->setChecked(false);
    ui->input35->setChecked(false);
    ui->input36->setChecked(false);
    ui->input37->setChecked(false);
    ui->input38->setChecked(false);
    ui->input39->setChecked(false);
    ui->input40->setChecked(false);
    ui->input41->setChecked(false);
    ui->input42->setChecked(false);
    ui->input43->setChecked(false);
    ui->input44->setChecked(false);
    ui->input45->setChecked(false);
    ui->input46->setChecked(false);
    ui->input47->setChecked(false);
    ui->input48->setChecked(false);
    ui->input49->setChecked(false);
    ui->input50->setChecked(false);
    ui->input51->setChecked(false);
    ui->input52->setChecked(false);
    ui->input53->setChecked(false);
    ui->input54->setChecked(false);
    ui->input55->setChecked(false);
    ui->input56->setChecked(false);
    ui->input57->setChecked(false);
    ui->input58->setChecked(false);
    ui->input59->setChecked(false);
    ui->input60->setChecked(false);
    ui->input61->setChecked(false);
    ui->input62->setChecked(false);

    ui->input63->setChecked(false);
    ui->input64->setChecked(false);
    ui->input65->setChecked(false);
    ui->input66->setChecked(false);
    ui->input67->setChecked(false);
    ui->input68->setChecked(false);
    ui->input69->setChecked(false);
    ui->input70->setChecked(false);
    ui->input71->setChecked(false);
    ui->input72->setChecked(false);
    ui->input73->setChecked(false);
    ui->input74->setChecked(false);
    ui->input75->setChecked(false);
    ui->input76->setChecked(false);
    ui->input77->setChecked(false);
    ui->input78->setChecked(false);
    ui->input79->setChecked(false);
    ui->input80->setChecked(false);
    ui->input81->setChecked(false);
    ui->input82->setChecked(false);
    ui->input83->setChecked(false);
    ui->input84->setChecked(false);
    ui->input85->setChecked(false);
    ui->input86->setChecked(false);
    ui->input87->setChecked(false);
    ui->input88->setChecked(false);
    ui->input89->setChecked(false);
    ui->input90->setChecked(false);
    ui->input91->setChecked(false);
    ui->input92->setChecked(false);
    ui->input93->setChecked(false);
    ui->input94->setChecked(false);
    ui->input95->setChecked(false);
    ui->input96->setChecked(false);
    ui->input97->setChecked(false);
    ui->input98->setChecked(false);
    ui->input99->setChecked(false);
    ui->input100->setChecked(false);
    ui->input101->setChecked(false);
    ui->input102->setChecked(false);
    ui->input103->setChecked(false);
    ui->input104->setChecked(false);
    ui->input105->setChecked(false);
    ui->input106->setChecked(false);
    ui->input107->setChecked(false);
    ui->input108->setChecked(false);
    ui->input109->setChecked(false);
    ui->input110->setChecked(false);
    ui->input111->setChecked(false);
    ui->input112->setChecked(false);
    ui->input113->setChecked(false);
    ui->input114->setChecked(false);
    ui->input115->setChecked(false);
    ui->input116->setChecked(false);
    ui->input117->setChecked(false);
    ui->input118->setChecked(false);
    ui->input119->setChecked(false);
    ui->input120->setChecked(false);
    ui->input121->setChecked(false);
    ui->input122->setChecked(false);
    ui->input123->setChecked(false);
    ui->input124->setChecked(false);

//    showInputsValue();
}

void BusepWindow::slotStartExchangeByTimer()
{
    dm->startExchange();

    showOutputsValue();
    showInputsValue();
}

void BusepWindow::createPalette()
{
    red_palette.setColor(ui->output1->backgroundRole(), Qt::red/*255, 0, 0*/ );
    yellow_palette.setColor(ui->output1->backgroundRole(), Qt::yellow/*0, 0, 255*/ );
    green_palette.setColor(ui->output1->backgroundRole(), Qt::green/*0, 255, 0*/ );
    gray_palette.setColor(ui->output1->backgroundRole(), Qt::gray);
    blue_palette.setColor(ui->output1->backgroundRole(), Qt::blue);
    //    red_palette.setColor(QPalette::ColorRole::Background, QColor(255, 0, 0) );    // рамка
}

void BusepWindow::showInputsValue()
{
    setInputColor(dm->getInputState(input1), ui->input1);
    setInputColor(dm->getInputState(input2), ui->input2);
    setInputColor(dm->getInputState(input3), ui->input3);
    setInputColor(dm->getInputState(input4), ui->input4);

    setInputColor(dm->getInputState(input5), ui->input5);
    setInputColor(dm->getInputState(input6), ui->input6);
    setInputColor(dm->getInputState(input7), ui->input7);
    setInputColor(dm->getInputState(input8), ui->input8);

    setInputColor(dm->getInputState(input9), ui->input9);
    setInputColor(dm->getInputState(input10), ui->input10);
    setInputColor(dm->getInputState(input11), ui->input11);
    setInputColor(dm->getInputState(input12), ui->input12);

    setInputColor(dm->getInputState(input13), ui->input13);
    setInputColor(dm->getInputState(input14), ui->input14);
    setInputColor(dm->getInputState(input15), ui->input15);
    setInputColor(dm->getInputState(input16), ui->input16);

    setInputColor(dm->getInputState(input17), ui->input17);
    setInputColor(dm->getInputState(input18), ui->input18);
    setInputColor(dm->getInputState(input19), ui->input19);
    setInputColor(dm->getInputState(input20), ui->input20);

    setInputColor(dm->getInputState(input21), ui->input21);
    setInputColor(dm->getInputState(input22), ui->input22);
    setInputColor(dm->getInputState(input23), ui->input23);
    setInputColor(dm->getInputState(input24), ui->input24);

    setInputColor(dm->getInputState(input25), ui->input25);
    setInputColor(dm->getInputState(input26), ui->input26);
    setInputColor(dm->getInputState(input27), ui->input27);
    setInputColor(dm->getInputState(input28), ui->input28);

    setInputColor(dm->getInputState(input29), ui->input29);
    setInputColor(dm->getInputState(input30), ui->input30);
    setInputColor(dm->getInputState(input31), ui->input31);
    setInputColor(dm->getInputState(input32), ui->input32);

    setInputColor(dm->getInputState(input33), ui->input33);
    setInputColor(dm->getInputState(input34), ui->input34);
    setInputColor(dm->getInputState(input35), ui->input35);
    setInputColor(dm->getInputState(input36), ui->input36);

    setInputColor(dm->getInputState(input37), ui->input37);
    setInputColor(dm->getInputState(input38), ui->input38);
    setInputColor(dm->getInputState(input39), ui->input39);
    setInputColor(dm->getInputState(input40), ui->input40);

    setInputColor(dm->getInputState(input41), ui->input41);
    setInputColor(dm->getInputState(input42), ui->input42);
    setInputColor(dm->getInputState(input43), ui->input43);
    setInputColor(dm->getInputState(input44), ui->input44);

    setInputColor(dm->getInputState(input45), ui->input45);
    setInputColor(dm->getInputState(input46), ui->input46);
    setInputColor(dm->getInputState(input47), ui->input47);
    setInputColor(dm->getInputState(input48), ui->input48);

    setInputColor(dm->getInputState(input49), ui->input49);
    setInputColor(dm->getInputState(input50), ui->input50);
    setInputColor(dm->getInputState(input51), ui->input51);
    setInputColor(dm->getInputState(input52), ui->input52);

    setInputColor(dm->getInputState(input53), ui->input53);
    setInputColor(dm->getInputState(input54), ui->input54);
    setInputColor(dm->getInputState(input55), ui->input55);
    setInputColor(dm->getInputState(input56), ui->input56);

    setInputColor(dm->getInputState(input57), ui->input57);
    setInputColor(dm->getInputState(input58), ui->input58);
    setInputColor(dm->getInputState(input59), ui->input59);
    setInputColor(dm->getInputState(input60), ui->input60);

    setInputColor(dm->getInputState(input61), ui->input61);
    setInputColor(dm->getInputState(input62), ui->input62);
    setInputColor(dm->getInputState(input63), ui->input63);
    setInputColor(dm->getInputState(input64), ui->input64);

    setInputColor(dm->getInputState(input65), ui->input65);
    setInputColor(dm->getInputState(input66), ui->input66);
    setInputColor(dm->getInputState(input67), ui->input67);
    setInputColor(dm->getInputState(input68), ui->input68);

    setInputColor(dm->getInputState(input69), ui->input69);
    setInputColor(dm->getInputState(input70), ui->input70);
    setInputColor(dm->getInputState(input71), ui->input71);
    setInputColor(dm->getInputState(input72), ui->input72);

    setInputColor(dm->getInputState(input73), ui->input73);
    setInputColor(dm->getInputState(input74), ui->input74);
    setInputColor(dm->getInputState(input75), ui->input75);
    setInputColor(dm->getInputState(input76), ui->input76);

    setInputColor(dm->getInputState(input77), ui->input77);
    setInputColor(dm->getInputState(input78), ui->input78);
    setInputColor(dm->getInputState(input79), ui->input79);
    setInputColor(dm->getInputState(input80), ui->input80);

    setInputColor(dm->getInputState(input81), ui->input81);
    setInputColor(dm->getInputState(input82), ui->input82);
    setInputColor(dm->getInputState(input83), ui->input83);
    setInputColor(dm->getInputState(input84), ui->input84);

    setInputColor(dm->getInputState(input85), ui->input85);
    setInputColor(dm->getInputState(input86), ui->input86);
    setInputColor(dm->getInputState(input87), ui->input87);
    setInputColor(dm->getInputState(input88), ui->input88);

    setInputColor(dm->getInputState(input89), ui->input89);
    setInputColor(dm->getInputState(input90), ui->input90);
    setInputColor(dm->getInputState(input91), ui->input91);
    setInputColor(dm->getInputState(input92), ui->input92);

    setInputColor(dm->getInputState(input93), ui->input93);
    setInputColor(dm->getInputState(input94), ui->input94);
    setInputColor(dm->getInputState(input95), ui->input95);
    setInputColor(dm->getInputState(input96), ui->input96);

    setInputColor(dm->getInputState(input97), ui->input97);
    setInputColor(dm->getInputState(input98), ui->input98);
    setInputColor(dm->getInputState(input99), ui->input99);
    setInputColor(dm->getInputState(input100), ui->input100);

    setInputColor(dm->getInputState(input101), ui->input101);
    setInputColor(dm->getInputState(input102), ui->input102);
    setInputColor(dm->getInputState(input103), ui->input103);
    setInputColor(dm->getInputState(input104), ui->input104);

    setInputColor(dm->getInputState(input105), ui->input105);
    setInputColor(dm->getInputState(input106), ui->input106);
    setInputColor(dm->getInputState(input107), ui->input107);
    setInputColor(dm->getInputState(input108), ui->input108);

    setInputColor(dm->getInputState(input109), ui->input109);
    setInputColor(dm->getInputState(input110), ui->input110);
    setInputColor(dm->getInputState(input111), ui->input111);
    setInputColor(dm->getInputState(input112), ui->input112);

    setInputColor(dm->getInputState(input113), ui->input113);
    setInputColor(dm->getInputState(input114), ui->input114);
    setInputColor(dm->getInputState(input115), ui->input115);
    setInputColor(dm->getInputState(input116), ui->input116);

    setInputColor(dm->getInputState(input117), ui->input117);
    setInputColor(dm->getInputState(input118), ui->input118);
    setInputColor(dm->getInputState(input119), ui->input119);
    setInputColor(dm->getInputState(input120), ui->input120);

    setInputColor(dm->getInputState(input121), ui->input121);
    setInputColor(dm->getInputState(input122), ui->input122);
    setInputColor(dm->getInputState(input123), ui->input123);
    setInputColor(dm->getInputState(input124), ui->input124);
}

void BusepWindow::setInputColor(const unsigned &input, QPushButton *input_button)
{
    switch (input)
    {
    case no_signal_27v:
        input_button->setPalette(gray_palette);
        break;

    case is_signal_27v:
        input_button->setPalette(green_palette);
        break;

    case no_input_state:
        input_button->setPalette(red_palette);
        break;

    default:
        input_button->setPalette(yellow_palette);
        break;
    }
}

void BusepWindow::showOutputsValue()
{
    setOutputColor(dm->getOutputState(output1), ui->output1);
    setOutputColor(dm->getOutputState(output2), ui->output2);
    setOutputColor(dm->getOutputState(output3), ui->output3);
    setOutputColor(dm->getOutputState(output4), ui->output4);

    setOutputColor(dm->getOutputState(output5), ui->output5);
    setOutputColor(dm->getOutputState(output6), ui->output6);
    setOutputColor(dm->getOutputState(output7), ui->output7);
    setOutputColor(dm->getOutputState(output8), ui->output8);

    setOutputColor(dm->getOutputState(output9), ui->output9);
    setOutputColor(dm->getOutputState(output10), ui->output10);
    setOutputColor(dm->getOutputState(output11), ui->output11);
    setOutputColor(dm->getOutputState(output12), ui->output12);

    setOutputColor(dm->getOutputState(output13), ui->output13);
    setOutputColor(dm->getOutputState(output14), ui->output14);
    setOutputColor(dm->getOutputState(output15), ui->output15);
    setOutputColor(dm->getOutputState(output16), ui->output16);

    setOutputColor(dm->getOutputState(output17), ui->output17);
    setOutputColor(dm->getOutputState(output18), ui->output18);
    setOutputColor(dm->getOutputState(output19), ui->output19);
    setOutputColor(dm->getOutputState(output20), ui->output20);

    setOutputColor(dm->getOutputState(output21), ui->output21);
    setOutputColor(dm->getOutputState(output22), ui->output22);
    setOutputColor(dm->getOutputState(output23), ui->output23);
    setOutputColor(dm->getOutputState(output24), ui->output24);

    setOutputColor(dm->getOutputState(output25), ui->output25);
    setOutputColor(dm->getOutputState(output26), ui->output26);
    setOutputColor(dm->getOutputState(output27), ui->output27);
    setOutputColor(dm->getOutputState(output28), ui->output28);

    setOutputColor(dm->getOutputState(output29), ui->output29);
    setOutputColor(dm->getOutputState(output30), ui->output30);
    setOutputColor(dm->getOutputState(output31), ui->output31);
    setOutputColor(dm->getOutputState(output32), ui->output32);

    setOutputColor(dm->getOutputState(output33), ui->output33);
    setOutputColor(dm->getOutputState(output34), ui->output34);
    setOutputColor(dm->getOutputState(output35), ui->output35);
    setOutputColor(dm->getOutputState(output36), ui->output36);

    setOutputColor(dm->getOutputState(output37), ui->output37);
    setOutputColor(dm->getOutputState(output38), ui->output38);
    setOutputColor(dm->getOutputState(output39), ui->output39);
    setOutputColor(dm->getOutputState(output40), ui->output40);

    setOutputColor(dm->getOutputState(output41), ui->output41);
    setOutputColor(dm->getOutputState(output42), ui->output42);
    setOutputColor(dm->getOutputState(output43), ui->output43);
    setOutputColor(dm->getOutputState(output44), ui->output44);

    setOutputColor(dm->getOutputState(output45), ui->output45);
    setOutputColor(dm->getOutputState(output46), ui->output46);
    setOutputColor(dm->getOutputState(output47), ui->output47);
    setOutputColor(dm->getOutputState(output48), ui->output48);

    setOutputColor(dm->getOutputState(output49), ui->output49);
    setOutputColor(dm->getOutputState(output50), ui->output50);
    setOutputColor(dm->getOutputState(output51), ui->output51);
    setOutputColor(dm->getOutputState(output52), ui->output52);

    setOutputColor(dm->getOutputState(output53), ui->output53);
    setOutputColor(dm->getOutputState(output54), ui->output54);
    setOutputColor(dm->getOutputState(output55), ui->output55);
    setOutputColor(dm->getOutputState(output56), ui->output56);

    setOutputColor(dm->getOutputState(output57), ui->output57);
    setOutputColor(dm->getOutputState(output58), ui->output58);
    setOutputColor(dm->getOutputState(output59), ui->output59);
    setOutputColor(dm->getOutputState(output60), ui->output60);

    setOutputColor(dm->getOutputState(output61), ui->output61);
    setOutputColor(dm->getOutputState(output62), ui->output62);
}

void BusepWindow::setOutputColor(const output_state state, QPushButton *output_button)
{
    switch (state)
    {
    case output_on:
        output_button->setPalette(green_palette);
        break;

    case output_off:
        output_button->setPalette(gray_palette);
        break;

    case no_output_state:
        output_button->setPalette(yellow_palette);
        break;

    case error_output:
        output_button->setPalette(red_palette);
        break;

    default:
        output_button->setPalette(blue_palette);
        break;
    }
}
