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

//    timer = new QTimer(this);
//    connect(timer, SIGNAL (timeout()), this, SLOT(slotStartExchangeByTimer()));
//    timer->start(1000);


    dm = new DummyMessages();
    showOutputsValue();
    showInputsValue();
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
}

void BusepWindow::slotStartExchangeByTimer()
{
    dm->startExchange();
}

void BusepWindow::createPalette()
{
    red_palette.setColor(ui->output1->backgroundRole(), Qt::red/*255, 0, 0*/ );
    yellow_palette.setColor(ui->output1->backgroundRole(), Qt::yellow/*0, 0, 255*/ );
    green_palette.setColor(ui->output1->backgroundRole(), Qt::green/*0, 255, 0*/ );
    gray_palette.setColor(ui->output1->backgroundRole(), Qt::gray);
    //    red_palette.setColor(QPalette::ColorRole::Background, QColor(255, 0, 0) );    // рамка
}

void BusepWindow::showInputsValue()
{
    _inputs inputs = dm->getInputs();

    setInputColor(inputs.input1(), ui->input1);
    setInputColor(inputs.input2(), ui->input2);
    setInputColor(inputs.input3(), ui->input3);
    setInputColor(inputs.input4(), ui->input4);

    setInputColor(inputs.input5(), ui->input5);
    setInputColor(inputs.input6(), ui->input6);
    setInputColor(inputs.input7(), ui->input7);
    setInputColor(inputs.input8(), ui->input8);

    setInputColor(inputs.input9(), ui->input9);
    setInputColor(inputs.input10(), ui->input10);
    setInputColor(inputs.input11(), ui->input11);
    setInputColor(inputs.input12(), ui->input12);

    setInputColor(inputs.input13(), ui->input13);
    setInputColor(inputs.input14(), ui->input14);
    setInputColor(inputs.input15(), ui->input15);
    setInputColor(inputs.input16(), ui->input16);

    setInputColor(inputs.input17(), ui->input17);
    setInputColor(inputs.input18(), ui->input18);
    setInputColor(inputs.input19(), ui->input19);
    setInputColor(inputs.input20(), ui->input20);

    setInputColor(inputs.input21(), ui->input21);
    setInputColor(inputs.input22(), ui->input22);
    setInputColor(inputs.input23(), ui->input23);
    setInputColor(inputs.input24(), ui->input24);

    setInputColor(inputs.input25(), ui->input25);
    setInputColor(inputs.input26(), ui->input26);
    setInputColor(inputs.input27(), ui->input27);
    setInputColor(inputs.input28(), ui->input28);

    setInputColor(inputs.input29(), ui->input29);
    setInputColor(inputs.input30(), ui->input30);
    setInputColor(inputs.input31(), ui->input31);
    setInputColor(inputs.input32(), ui->input32);

    setInputColor(inputs.input33(), ui->input33);
    setInputColor(inputs.input34(), ui->input34);
    setInputColor(inputs.input35(), ui->input35);
    setInputColor(inputs.input36(), ui->input36);

    setInputColor(inputs.input37(), ui->input37);
    setInputColor(inputs.input38(), ui->input38);
    setInputColor(inputs.input39(), ui->input39);
    setInputColor(inputs.input40(), ui->input40);

    setInputColor(inputs.input41(), ui->input41);
    setInputColor(inputs.input42(), ui->input42);
    setInputColor(inputs.input43(), ui->input43);
    setInputColor(inputs.input44(), ui->input44);

    setInputColor(inputs.input45(), ui->input45);
    setInputColor(inputs.input46(), ui->input46);
    setInputColor(inputs.input47(), ui->input47);
    setInputColor(inputs.input48(), ui->input48);

    setInputColor(inputs.input49(), ui->input49);
    setInputColor(inputs.input50(), ui->input50);
    setInputColor(inputs.input51(), ui->input51);
    setInputColor(inputs.input52(), ui->input52);

    setInputColor(inputs.input53(), ui->input53);
    setInputColor(inputs.input54(), ui->input54);
    setInputColor(inputs.input55(), ui->input55);
    setInputColor(inputs.input56(), ui->input56);

    setInputColor(inputs.input57(), ui->input57);
    setInputColor(inputs.input58(), ui->input58);
    setInputColor(inputs.input59(), ui->input59);
    setInputColor(inputs.input60(), ui->input60);

    setInputColor(inputs.input61(), ui->input61);
    setInputColor(inputs.input62(), ui->input62);
    setInputColor(inputs.input63(), ui->input63);
    setInputColor(inputs.input64(), ui->input64);

    setInputColor(inputs.input65(), ui->input65);
    setInputColor(inputs.input66(), ui->input66);
    setInputColor(inputs.input67(), ui->input67);
    setInputColor(inputs.input68(), ui->input68);

    setInputColor(inputs.input69(), ui->input69);
    setInputColor(inputs.input70(), ui->input70);
    setInputColor(inputs.input71(), ui->input71);
    setInputColor(inputs.input72(), ui->input72);

    setInputColor(inputs.input73(), ui->input73);
    setInputColor(inputs.input74(), ui->input74);
    setInputColor(inputs.input75(), ui->input75);
    setInputColor(inputs.input76(), ui->input76);

    setInputColor(inputs.input77(), ui->input77);
    setInputColor(inputs.input78(), ui->input78);
    setInputColor(inputs.input79(), ui->input79);
    setInputColor(inputs.input80(), ui->input80);

    setInputColor(inputs.input81(), ui->input81);
    setInputColor(inputs.input82(), ui->input82);
    setInputColor(inputs.input83(), ui->input83);
    setInputColor(inputs.input84(), ui->input84);

    setInputColor(inputs.input85(), ui->input85);
    setInputColor(inputs.input86(), ui->input86);
    setInputColor(inputs.input87(), ui->input87);
    setInputColor(inputs.input88(), ui->input88);

    setInputColor(inputs.input89(), ui->input89);
    setInputColor(inputs.input90(), ui->input90);
    setInputColor(inputs.input91(), ui->input91);
    setInputColor(inputs.input92(), ui->input92);

    setInputColor(inputs.input93(), ui->input93);
    setInputColor(inputs.input94(), ui->input94);
    setInputColor(inputs.input95(), ui->input95);
    setInputColor(inputs.input96(), ui->input96);

    setInputColor(inputs.input97(), ui->input97);
    setInputColor(inputs.input98(), ui->input98);
    setInputColor(inputs.input99(), ui->input99);
    setInputColor(inputs.input100(), ui->input100);

    setInputColor(inputs.input101(), ui->input101);
    setInputColor(inputs.input102(), ui->input102);
    setInputColor(inputs.input103(), ui->input103);
    setInputColor(inputs.input104(), ui->input104);

    setInputColor(inputs.input105(), ui->input105);
    setInputColor(inputs.input106(), ui->input106);
    setInputColor(inputs.input107(), ui->input107);
    setInputColor(inputs.input108(), ui->input108);

    setInputColor(inputs.input109(), ui->input109);
    setInputColor(inputs.input110(), ui->input110);
    setInputColor(inputs.input111(), ui->input111);
    setInputColor(inputs.input112(), ui->input112);

    setInputColor(inputs.input113(), ui->input113);
    setInputColor(inputs.input114(), ui->input114);
    setInputColor(inputs.input115(), ui->input115);
    setInputColor(inputs.input116(), ui->input116);

    setInputColor(inputs.input117(), ui->input117);
    setInputColor(inputs.input118(), ui->input118);
    setInputColor(inputs.input119(), ui->input119);
    setInputColor(inputs.input120(), ui->input120);

    setInputColor(inputs.input121(), ui->input121);
    setInputColor(inputs.input122(), ui->input122);
    setInputColor(inputs.input123(), ui->input123);
    setInputColor(inputs.input124(), ui->input124);

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
    _outputs outputs = dm->getOutputs();

    setOutputColor(outputs.output1(), ui->output1);
    setOutputColor(outputs.output2(), ui->output2);
    setOutputColor(outputs.output3(), ui->output3);
    setOutputColor(outputs.output4(), ui->output4);

    setOutputColor(outputs.output5(), ui->output5);
    setOutputColor(outputs.output6(), ui->output6);
    setOutputColor(outputs.output7(), ui->output7);
    setOutputColor(outputs.output8(), ui->output8);

    setOutputColor(outputs.output9(), ui->output9);
    setOutputColor(outputs.output10(), ui->output10);
    setOutputColor(outputs.output11(), ui->output11);
    setOutputColor(outputs.output12(), ui->output12);

    setOutputColor(outputs.output13(), ui->output13);
    setOutputColor(outputs.output14(), ui->output14);
    setOutputColor(outputs.output15(), ui->output15);
    setOutputColor(outputs.output16(), ui->output16);

    setOutputColor(outputs.output17(), ui->output17);
    setOutputColor(outputs.output18(), ui->output18);
    setOutputColor(outputs.output19(), ui->output19);
    setOutputColor(outputs.output20(), ui->output20);

    setOutputColor(outputs.output21(), ui->output21);
    setOutputColor(outputs.output22(), ui->output22);
    setOutputColor(outputs.output23(), ui->output23);
    setOutputColor(outputs.output24(), ui->output24);

    setOutputColor(outputs.output25(), ui->output25);
    setOutputColor(outputs.output26(), ui->output26);
    setOutputColor(outputs.output27(), ui->output27);
    setOutputColor(outputs.output28(), ui->output28);

    setOutputColor(outputs.output29(), ui->output29);
    setOutputColor(outputs.output30(), ui->output30);
    setOutputColor(outputs.output31(), ui->output31);
    setOutputColor(outputs.output32(), ui->output32);

    setOutputColor(outputs.output33(), ui->output33);
    setOutputColor(outputs.output34(), ui->output34);
    setOutputColor(outputs.output35(), ui->output35);
    setOutputColor(outputs.output36(), ui->output36);

    setOutputColor(outputs.output37(), ui->output37);
    setOutputColor(outputs.output38(), ui->output38);
    setOutputColor(outputs.output39(), ui->output39);
    setOutputColor(outputs.output40(), ui->output40);

    setOutputColor(outputs.output41(), ui->output41);
    setOutputColor(outputs.output42(), ui->output42);
    setOutputColor(outputs.output43(), ui->output43);
    setOutputColor(outputs.output44(), ui->output44);

    setOutputColor(outputs.output45(), ui->output45);
    setOutputColor(outputs.output46(), ui->output46);
    setOutputColor(outputs.output47(), ui->output47);
    setOutputColor(outputs.output48(), ui->output48);

    setOutputColor(outputs.output49(), ui->output49);
    setOutputColor(outputs.output50(), ui->output50);
    setOutputColor(outputs.output51(), ui->output51);
    setOutputColor(outputs.output52(), ui->output52);

    setOutputColor(outputs.output53(), ui->output53);
    setOutputColor(outputs.output54(), ui->output54);
    setOutputColor(outputs.output55(), ui->output55);
    setOutputColor(outputs.output56(), ui->output56);

    setOutputColor(outputs.output57(), ui->output57);
    setOutputColor(outputs.output58(), ui->output58);
    setOutputColor(outputs.output59(), ui->output59);
    setOutputColor(outputs.output60(), ui->output60);

    setOutputColor(outputs.output61(), ui->output61);
    setOutputColor(outputs.output62(), ui->output62);
}

void BusepWindow::setOutputColor(const unsigned &output, QPushButton *output_button)
{
    switch (output)
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
        printf("  output \t%02x %s\n", output, "no data");
        break;
    }
}
