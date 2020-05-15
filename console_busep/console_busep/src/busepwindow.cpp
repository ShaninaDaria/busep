#include "hdr/busepwindow.h"
#include "ui_busepwindow.h"

BusepWindow::BusepWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BusepWindow)
{
    ui->setupUi(this);
    createPalette();

    connect(ui->allInputsOnOff, SIGNAL(toggled(bool)), this, SLOT(slotAllInputsOnOff(bool)));

    dm = new DummyMessages();
    // как-то не так, конечно - я не знаю, с какой частотой БУСЕП шлет сообщения
    timer = new QTimer(this);
    connect(timer, SIGNAL (timeout()), this, SLOT(slotStartExchangeByTimer()));
    timer->start(10);

    connect(dm, SIGNAL(signalUsualExchange()), this, SLOT(slotUsualExchange()));
    connect(dm, SIGNAL(signalSendIS5()), this, SLOT(slotSendIS5()));



//    slotStartExchangeByTimer();
}

BusepWindow::~BusepWindow()
{
    if (timer->isActive())
    {
        timer->stop();

    }
    delete dm;
    delete ui;
}

void BusepWindow::slotAllInputsOnOff(bool toggled)
{
    qDebug() << __FUNCTION__ << toggled;

    if (toggled)
    {
        ui->allInputsOnOff->setText("Выключить все");

        dm->createIS3(no_signal_27v);
    }
    else
    {
        ui->allInputsOnOff->setText("Включить все");

        dm->createIS3(is_signal_27v);
    }

    ui->input1->setChecked(toggled);
    ui->input2->setChecked(toggled);
    ui->input3->setChecked(toggled);
    ui->input4->setChecked(toggled);
    ui->input5->setChecked(toggled);
    ui->input6->setChecked(toggled);
    ui->input7->setChecked(toggled);
    ui->input8->setChecked(toggled);
    ui->input9->setChecked(toggled);
    ui->input10->setChecked(toggled);
    ui->input11->setChecked(toggled);
    ui->input12->setChecked(toggled);
    ui->input13->setChecked(toggled);
    ui->input14->setChecked(toggled);
    ui->input15->setChecked(toggled);
    ui->input16->setChecked(toggled);
    ui->input17->setChecked(toggled);
    ui->input18->setChecked(toggled);
    ui->input19->setChecked(toggled);
    ui->input20->setChecked(toggled);
    ui->input21->setChecked(toggled);
    ui->input22->setChecked(toggled);
    ui->input23->setChecked(toggled);
    ui->input24->setChecked(toggled);
    ui->input25->setChecked(toggled);
    ui->input26->setChecked(toggled);
    ui->input27->setChecked(toggled);
    ui->input28->setChecked(toggled);
    ui->input29->setChecked(toggled);
    ui->input30->setChecked(toggled);
    ui->input31->setChecked(toggled);
    ui->input32->setChecked(toggled);
    ui->input33->setChecked(toggled);
    ui->input34->setChecked(toggled);
    ui->input35->setChecked(toggled);
    ui->input36->setChecked(toggled);
    ui->input37->setChecked(toggled);
    ui->input38->setChecked(toggled);
    ui->input39->setChecked(toggled);
    ui->input40->setChecked(toggled);
    ui->input41->setChecked(toggled);
    ui->input42->setChecked(toggled);
    ui->input43->setChecked(toggled);
    ui->input44->setChecked(toggled);
    ui->input45->setChecked(toggled);
    ui->input46->setChecked(toggled);
    ui->input47->setChecked(toggled);
    ui->input48->setChecked(toggled);
    ui->input49->setChecked(toggled);
    ui->input50->setChecked(toggled);
    ui->input51->setChecked(toggled);
    ui->input52->setChecked(toggled);
    ui->input53->setChecked(toggled);
    ui->input54->setChecked(toggled);
    ui->input55->setChecked(toggled);
    ui->input56->setChecked(toggled);
    ui->input57->setChecked(toggled);
    ui->input58->setChecked(toggled);
    ui->input59->setChecked(toggled);
    ui->input60->setChecked(toggled);
    ui->input61->setChecked(toggled);
    ui->input62->setChecked(toggled);

    ui->input63->setChecked(toggled);
    ui->input64->setChecked(toggled);
    ui->input65->setChecked(toggled);
    ui->input66->setChecked(toggled);
    ui->input67->setChecked(toggled);
    ui->input68->setChecked(toggled);
    ui->input69->setChecked(toggled);
    ui->input70->setChecked(toggled);
    ui->input71->setChecked(toggled);
    ui->input72->setChecked(toggled);
    ui->input73->setChecked(toggled);
    ui->input74->setChecked(toggled);
    ui->input75->setChecked(toggled);
    ui->input76->setChecked(toggled);
    ui->input77->setChecked(toggled);
    ui->input78->setChecked(toggled);
    ui->input79->setChecked(toggled);
    ui->input80->setChecked(toggled);
    ui->input81->setChecked(toggled);
    ui->input82->setChecked(toggled);
    ui->input83->setChecked(toggled);
    ui->input84->setChecked(toggled);
    ui->input85->setChecked(toggled);
    ui->input86->setChecked(toggled);
    ui->input87->setChecked(toggled);
    ui->input88->setChecked(toggled);
    ui->input89->setChecked(toggled);
    ui->input90->setChecked(toggled);
    ui->input91->setChecked(toggled);
    ui->input92->setChecked(toggled);
    ui->input93->setChecked(toggled);
    ui->input94->setChecked(toggled);
    ui->input95->setChecked(toggled);
    ui->input96->setChecked(toggled);
    ui->input97->setChecked(toggled);
    ui->input98->setChecked(toggled);
    ui->input99->setChecked(toggled);
    ui->input100->setChecked(toggled);
    ui->input101->setChecked(toggled);
    ui->input102->setChecked(toggled);
    ui->input103->setChecked(toggled);
    ui->input104->setChecked(toggled);
    ui->input105->setChecked(toggled);
    ui->input106->setChecked(toggled);
    ui->input107->setChecked(toggled);
    ui->input108->setChecked(toggled);
    ui->input109->setChecked(toggled);
    ui->input110->setChecked(toggled);
    ui->input111->setChecked(toggled);
    ui->input112->setChecked(toggled);
    ui->input113->setChecked(toggled);
    ui->input114->setChecked(toggled);
    ui->input115->setChecked(toggled);
    ui->input116->setChecked(toggled);
    ui->input117->setChecked(toggled);
    ui->input118->setChecked(toggled);
    ui->input119->setChecked(toggled);
    ui->input120->setChecked(toggled);
    ui->input121->setChecked(toggled);
    ui->input122->setChecked(toggled);
    ui->input123->setChecked(toggled);
    ui->input124->setChecked(toggled);

//    showInputsValue();
}

void BusepWindow::slotStartExchangeByTimer()
{
    dm->startExchange();

    showOutputsValue();
    showInputsValue();
}

void BusepWindow::slotUsualExchange()
{
    ui->statusbar->showMessage("Обмен в штатном режиме");
}

void BusepWindow::slotSendIS5()
{
    ui->statusbar->showMessage("Отправка сообщения ИС5");
}

void BusepWindow::createPalette()
{
    red_palette.setColor(ui->output1->backgroundRole(), Qt::red);
    yellow_palette.setColor(ui->output1->backgroundRole(), Qt::yellow);
    green_palette.setColor(ui->output1->backgroundRole(), Qt::green);
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
