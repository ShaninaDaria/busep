#include "../hdr/pvkpwindow.h"
#include "ui_pvkpwindow.h"

PVKPWindow::PVKPWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PVKPWindow)
{
    ui->setupUi(this);

    red_palette.setColor(ui->output1->backgroundRole(), Qt::red/*255, 0, 0*/ );
    yellow_palette.setColor(ui->output1->backgroundRole(), Qt::yellow/*0, 0, 255*/ );
    green_palette.setColor(ui->output1->backgroundRole(), Qt::green/*0, 255, 0*/ );
    gray_palette.setColor(ui->output1->backgroundRole(), Qt::gray);
//    red_palette.setColor(QPalette::ColorRole::Background, QColor(255, 0, 0) );    // рамка
//    fictitiousOutputColor();
//    fictitiousInputColor();

    me = new messageExchange();

    timer = new QTimer(this);
    connect(timer, SIGNAL (timeout()), this, SLOT(slotByTimer()));
    timer->start(1000);

//    thread = new QThread(this);
    /// TODO - в отдельный поток?
//    me->moveToThread(thread);
    me->initTransmit();

//    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

//    thread->start();
//    me->startExchange();

//    showInputsValue();
}

PVKPWindow::~PVKPWindow()
{
    delete me;
//    delete thread;
    delete ui;
}

void PVKPWindow::slotByTimer()
{
    me->startExchange();

    showInputsValue();
    showOutputValue();
}

void PVKPWindow::fictitiousOutputColor()
{
    ui->output1->setPalette(yellow_palette);
    ui->output2->setPalette(yellow_palette);
    ui->output3->setPalette(yellow_palette);
    ui->output4->setPalette(yellow_palette);
    ui->output5->setPalette(yellow_palette);
    ui->output6->setPalette(yellow_palette);
    ui->output7->setPalette(yellow_palette);
    ui->output8->setPalette(yellow_palette);
    ui->output9->setPalette(yellow_palette);
    ui->output10->setPalette(yellow_palette);
    ui->output11->setPalette(yellow_palette);
    ui->output12->setPalette(yellow_palette);
    ui->output13->setPalette(yellow_palette);
    ui->output14->setPalette(yellow_palette);
    ui->output15->setPalette(yellow_palette);
    ui->output16->setPalette(yellow_palette);
    ui->output17->setPalette(yellow_palette);
    ui->output18->setPalette(yellow_palette);
    ui->output19->setPalette(yellow_palette);
    ui->output20->setPalette(yellow_palette);
    ui->output21->setPalette(yellow_palette);
    ui->output22->setPalette(yellow_palette);
    ui->output23->setPalette(yellow_palette);
    ui->output24->setPalette(yellow_palette);
    ui->output25->setPalette(yellow_palette);
    ui->output26->setPalette(yellow_palette);
    ui->output27->setPalette(yellow_palette);
    ui->output28->setPalette(yellow_palette);
    ui->output29->setPalette(yellow_palette);
    ui->output30->setPalette(yellow_palette);
    ui->output31->setPalette(yellow_palette);
    ui->output32->setPalette(yellow_palette);
    ui->output33->setPalette(yellow_palette);
    ui->output34->setPalette(yellow_palette);
    ui->output35->setPalette(yellow_palette);
    ui->output36->setPalette(yellow_palette);
    ui->output37->setPalette(yellow_palette);
    ui->output38->setPalette(yellow_palette);
    ui->output39->setPalette(yellow_palette);
    ui->output40->setPalette(yellow_palette);
    ui->output41->setPalette(yellow_palette);
    ui->output42->setPalette(yellow_palette);
    ui->output43->setPalette(yellow_palette);
    ui->output44->setPalette(yellow_palette);
    ui->output45->setPalette(yellow_palette);
    ui->output46->setPalette(yellow_palette);
    ui->output47->setPalette(yellow_palette);
    ui->output48->setPalette(yellow_palette);
    ui->output49->setPalette(yellow_palette);
    ui->output50->setPalette(yellow_palette);
    ui->output51->setPalette(yellow_palette);
    ui->output52->setPalette(yellow_palette);
    ui->output53->setPalette(yellow_palette);
    ui->output54->setPalette(yellow_palette);
    ui->output55->setPalette(yellow_palette);
    ui->output56->setPalette(yellow_palette);
    ui->output57->setPalette(yellow_palette);
    ui->output58->setPalette(yellow_palette);
    ui->output59->setPalette(yellow_palette);
    ui->output60->setPalette(yellow_palette);
    ui->output61->setPalette(yellow_palette);
    ui->output62->setPalette(yellow_palette);
}

void PVKPWindow::fictitiousInputColor()
{
    ui->input1 ->setPalette(gray_palette);
    ui->input2 ->setPalette(gray_palette);
    ui->input3 ->setPalette(gray_palette);
    ui->input4 ->setPalette(gray_palette);
    ui->input5 ->setPalette(gray_palette);
    ui->input6 ->setPalette(gray_palette);
    ui->input7 ->setPalette(gray_palette);
    ui->input8 ->setPalette(gray_palette);
    ui->input9 ->setPalette(gray_palette);
    ui->input10->setPalette(gray_palette);
    ui->input11->setPalette(gray_palette);
    ui->input12->setPalette(gray_palette);
    ui->input13->setPalette(gray_palette);
    ui->input14->setPalette(gray_palette);
    ui->input15->setPalette(gray_palette);



//    ui->pushButton_63->setPalette(green_palette);
//    ui->pushButton_63 ->setPalette(green_palette);
//    ui->pushButton_64 ->setPalette(green_palette);
//    ui->pushButton_65 ->setPalette(green_palette);
//    ui->pushButton_66 ->setPalette(green_palette);
//    ui->pushButton_67 ->setPalette(green_palette);
//    ui->pushButton_68 ->setPalette(green_palette);
//    ui->pushButton_69 ->setPalette(green_palette);
//    ui->pushButton_70 ->setPalette(red_palette);
//    ui->pushButton_72 ->setPalette(green_palette);
//    ui->pushButton_73 ->setPalette(green_palette);
//    ui->pushButton_75 ->setPalette(green_palette);
//    ui->pushButton_76 ->setPalette(green_palette);
//    ui->pushButton_77 ->setPalette(green_palette);
//    ui->pushButton_78 ->setPalette(green_palette);
//    ui->pushButton_79 ->setPalette(green_palette);
//    ui->pushButton_82 ->setPalette(green_palette);
//    ui->pushButton_84 ->setPalette(red_palette);
//    ui->pushButton_85 ->setPalette(green_palette);
//    ui->pushButton_86 ->setPalette(green_palette);
//    ui->pushButton_87 ->setPalette(green_palette);
//    ui->pushButton_88 ->setPalette(green_palette);
//    ui->pushButton_91 ->setPalette(green_palette);
//    ui->pushButton_93 ->setPalette(green_palette);
//    ui->pushButton_94 ->setPalette(green_palette);
//    ui->pushButton_95 ->setPalette(green_palette);
//    ui->pushButton_96 ->setPalette(red_palette);
//    ui->pushButton_98 ->setPalette(green_palette);
//    ui->pushButton_99 ->setPalette(green_palette);
//    ui->pushButton_100->setPalette(green_palette);
//    ui->pushButton_103->setPalette(green_palette);
//    ui->pushButton_104->setPalette(green_palette);
//    ui->pushButton_105->setPalette(green_palette);
//    ui->pushButton_106->setPalette(green_palette);
//    ui->pushButton_107->setPalette(green_palette);
//    ui->pushButton_108->setPalette(green_palette);
//    ui->pushButton_109->setPalette(green_palette);
//    ui->pushButton_110->setPalette(green_palette);
//    ui->pushButton_113->setPalette(green_palette);
//    ui->pushButton_114->setPalette(red_palette);
//    ui->pushButton_115->setPalette(green_palette);
//    ui->pushButton_116->setPalette(green_palette);
//    ui->pushButton_117->setPalette(green_palette);
//    ui->pushButton_118->setPalette(green_palette);
//    ui->pushButton_119->setPalette(green_palette);
//    ui->pushButton_121->setPalette(green_palette);
//    ui->pushButton_122->setPalette(green_palette);
//    ui->pushButton_124->setPalette(green_palette);
//    ui->pushButton_125->setPalette(green_palette);
//    ui->pushButton_126->setPalette(green_palette);
//    ui->pushButton_127->setPalette(green_palette);
//    ui->pushButton_128->setPalette(green_palette);
//    ui->pushButton_129->setPalette(red_palette);
//    ui->pushButton_130->setPalette(green_palette);
//    ui->pushButton_131->setPalette(green_palette);
//    ui->pushButton_132->setPalette(green_palette);
//    ui->pushButton_133->setPalette(green_palette);
//    ui->pushButton_134->setPalette(green_palette);
//    ui->pushButton_135->setPalette(green_palette);
//    ui->pushButton_136->setPalette(green_palette);
//    ui->pushButton_137->setPalette(green_palette);
//    ui->pushButton_138->setPalette(green_palette);
//    ui->pushButton_139->setPalette(green_palette);
//    ui->pushButton_140->setPalette(red_palette);
//    ui->pushButton_141->setPalette(green_palette);
//    ui->pushButton_142->setPalette(green_palette);
//    ui->pushButton_143->setPalette(red_palette);
//    ui->pushButton_144->setPalette(green_palette);
//    ui->pushButton_145->setPalette(green_palette);
//    ui->pushButton_146->setPalette(green_palette);
//    ui->pushButton_147->setPalette(green_palette);
//    ui->pushButton_148->setPalette(green_palette);
//    ui->pushButton_149->setPalette(green_palette);
//    ui->pushButton_150->setPalette(green_palette);
//    ui->pushButton_151->setPalette(green_palette);
//    ui->pushButton_152->setPalette(green_palette);
//    ui->pushButton_153->setPalette(green_palette);
//    ui->pushButton_154->setPalette(green_palette);
//    ui->pushButton_155->setPalette(red_palette);
//    ui->pushButton_156->setPalette(green_palette);
//    ui->pushButton_157->setPalette(green_palette);
//    ui->pushButton_158->setPalette(green_palette);
//    ui->pushButton_159->setPalette(green_palette);
//    ui->pushButton_160->setPalette(green_palette);
//    ui->pushButton_161->setPalette(red_palette);
//    ui->pushButton_162->setPalette(green_palette);
//    ui->pushButton_163->setPalette(green_palette);
//    ui->pushButton_164->setPalette(green_palette);
//    ui->pushButton_165->setPalette(green_palette);
//    ui->pushButton_166->setPalette(green_palette);
//    ui->pushButton_187->setPalette(green_palette);
//    ui->pushButton_274->setPalette(green_palette);
//    ui->pushButton_275->setPalette(green_palette);
//    ui->pushButton_276->setPalette(green_palette);
//    ui->pushButton_277->setPalette(green_palette);
//    ui->pushButton_278->setPalette(green_palette);
//    ui->pushButton_279->setPalette(green_palette);
//    ui->pushButton_280->setPalette(red_palette);
//    ui->pushButton_281->setPalette(green_palette);
//    ui->pushButton_282->setPalette(green_palette);
//    ui->pushButton_283->setPalette(green_palette);
//    ui->pushButton_284->setPalette(green_palette);
//    ui->pushButton_285->setPalette(green_palette);
//    ui->pushButton_286->setPalette(green_palette);
//    ui->pushButton_287->setPalette(green_palette);
//    ui->pushButton_288->setPalette(green_palette);
//    ui->pushButton_289->setPalette(green_palette);
//    ui->pushButton_290->setPalette(red_palette);
//    ui->pushButton_291->setPalette(green_palette);
//    ui->pushButton_312->setPalette(green_palette);
    //    ui->pushButton_312->setPalette(green_palette);
}

void PVKPWindow::showInputsValue()
{
    qDebug() << __FUNCTION__;
    _inputs inputs = me->getInputsValue();

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

void PVKPWindow::setInputColor(const unsigned &input, QPushButton *input_button)
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

void PVKPWindow::showOutputValue()
{
    qDebug() << __FUNCTION__;
    _outputs outputs = me->getOutputsValue();

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

void PVKPWindow::setOutputColor(const unsigned &output, QPushButton *output_button)
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
