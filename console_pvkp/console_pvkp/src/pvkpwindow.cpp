#include "../hdr/pvkpwindow.h"
#include "ui_pvkpwindow.h"

PVKPWindow::PVKPWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PVKPWindow)
{
    ui->setupUi(this);

    createPalette();

    me = new messageExchange();

    for (int i = 0; i < output_size; i++)
    {
        last_pressed_o[i] = true;
    }

    /// NOTE по умолчанию шлю ИС2 с запросом "включить все выходы"
    me->createIS2(all_outputs, cntrl_on);
    for (int i = 0; i < output_size; i++)
    {
        o_cntrl[i] = cntrl_on;
    }

    connect(ui->allOutputsOff, SIGNAL(toggled(bool)), this, SLOT(slotAllOutputsOnOff(bool)));
    connect(ui->output1, SIGNAL(clicked(bool)), this, SLOT(slotOutput1clicked(bool)));
    connect(ui->output2, SIGNAL(clicked(bool)), this, SLOT(slotOutput2clicked(bool)));
    connect(ui->output3, SIGNAL(clicked(bool)), this, SLOT(slotOutput3clicked(bool)));
    connect(ui->output4, SIGNAL(clicked(bool)), this, SLOT(slotOutput4clicked(bool)));
    connect(ui->output5, SIGNAL(clicked(bool)), this, SLOT(slotOutput5clicked(bool)));
    connect(ui->output6, SIGNAL(clicked(bool)), this, SLOT(slotOutput6clicked(bool)));
    connect(ui->output7, SIGNAL(clicked(bool)), this, SLOT(slotOutput7clicked(bool)));
    connect(ui->output8, SIGNAL(clicked(bool)), this, SLOT(slotOutput8clicked(bool)));
    connect(ui->output9, SIGNAL(clicked(bool)), this, SLOT(slotOutput9clicked(bool)));
    connect(ui->output10, SIGNAL(clicked(bool)), this, SLOT(slotOutput10clicked(bool)));
    connect(ui->output11, SIGNAL(clicked(bool)), this, SLOT(slotOutput11clicked(bool)));
    connect(ui->output12, SIGNAL(clicked(bool)), this, SLOT(slotOutput12clicked(bool)));
    connect(ui->output13, SIGNAL(clicked(bool)), this, SLOT(slotOutput13clicked(bool)));
    connect(ui->output14, SIGNAL(clicked(bool)), this, SLOT(slotOutput14clicked(bool)));
    connect(ui->output15, SIGNAL(clicked(bool)), this, SLOT(slotOutput15clicked(bool)));
    connect(ui->output16, SIGNAL(clicked(bool)), this, SLOT(slotOutput16clicked(bool)));
    connect(ui->output17, SIGNAL(clicked(bool)), this, SLOT(slotOutput17clicked(bool)));
    connect(ui->output18, SIGNAL(clicked(bool)), this, SLOT(slotOutput18clicked(bool)));
    connect(ui->output19, SIGNAL(clicked(bool)), this, SLOT(slotOutput19clicked(bool)));
    connect(ui->output20, SIGNAL(clicked(bool)), this, SLOT(slotOutput20clicked(bool)));
    connect(ui->output21, SIGNAL(clicked(bool)), this, SLOT(slotOutput21clicked(bool)));
    connect(ui->output22, SIGNAL(clicked(bool)), this, SLOT(slotOutput22clicked(bool)));
    connect(ui->output23, SIGNAL(clicked(bool)), this, SLOT(slotOutput23clicked(bool)));
    connect(ui->output24, SIGNAL(clicked(bool)), this, SLOT(slotOutput24clicked(bool)));
    connect(ui->output25, SIGNAL(clicked(bool)), this, SLOT(slotOutput25clicked(bool)));
    connect(ui->output26, SIGNAL(clicked(bool)), this, SLOT(slotOutput26clicked(bool)));
    connect(ui->output27, SIGNAL(clicked(bool)), this, SLOT(slotOutput27clicked(bool)));
    connect(ui->output28, SIGNAL(clicked(bool)), this, SLOT(slotOutput28clicked(bool)));
    connect(ui->output29, SIGNAL(clicked(bool)), this, SLOT(slotOutput29clicked(bool)));
    connect(ui->output30, SIGNAL(clicked(bool)), this, SLOT(slotOutput30clicked(bool)));
    connect(ui->output31, SIGNAL(clicked(bool)), this, SLOT(slotOutput31clicked(bool)));
    connect(ui->output32, SIGNAL(clicked(bool)), this, SLOT(slotOutput32clicked(bool)));
    connect(ui->output33, SIGNAL(clicked(bool)), this, SLOT(slotOutput33clicked(bool)));
    connect(ui->output34, SIGNAL(clicked(bool)), this, SLOT(slotOutput34clicked(bool)));
    connect(ui->output35, SIGNAL(clicked(bool)), this, SLOT(slotOutput35clicked(bool)));
    connect(ui->output36, SIGNAL(clicked(bool)), this, SLOT(slotOutput36clicked(bool)));
    connect(ui->output37, SIGNAL(clicked(bool)), this, SLOT(slotOutput37clicked(bool)));
    connect(ui->output38, SIGNAL(clicked(bool)), this, SLOT(slotOutput38clicked(bool)));
    connect(ui->output39, SIGNAL(clicked(bool)), this, SLOT(slotOutput39clicked(bool)));
    connect(ui->output40, SIGNAL(clicked(bool)), this, SLOT(slotOutput40clicked(bool)));
    connect(ui->output41, SIGNAL(clicked(bool)), this, SLOT(slotOutput41clicked(bool)));
    connect(ui->output42, SIGNAL(clicked(bool)), this, SLOT(slotOutput42clicked(bool)));
    connect(ui->output43, SIGNAL(clicked(bool)), this, SLOT(slotOutput43clicked(bool)));
    connect(ui->output44, SIGNAL(clicked(bool)), this, SLOT(slotOutput44clicked(bool)));
    connect(ui->output45, SIGNAL(clicked(bool)), this, SLOT(slotOutput45clicked(bool)));
    connect(ui->output46, SIGNAL(clicked(bool)), this, SLOT(slotOutput46clicked(bool)));
    connect(ui->output47, SIGNAL(clicked(bool)), this, SLOT(slotOutput47clicked(bool)));
    connect(ui->output48, SIGNAL(clicked(bool)), this, SLOT(slotOutput48clicked(bool)));
    connect(ui->output49, SIGNAL(clicked(bool)), this, SLOT(slotOutput49clicked(bool)));
    connect(ui->output50, SIGNAL(clicked(bool)), this, SLOT(slotOutput50clicked(bool)));
    connect(ui->output51, SIGNAL(clicked(bool)), this, SLOT(slotOutput51clicked(bool)));
    connect(ui->output52, SIGNAL(clicked(bool)), this, SLOT(slotOutput52clicked(bool)));
    connect(ui->output53, SIGNAL(clicked(bool)), this, SLOT(slotOutput53clicked(bool)));
    connect(ui->output54, SIGNAL(clicked(bool)), this, SLOT(slotOutput54clicked(bool)));
    connect(ui->output55, SIGNAL(clicked(bool)), this, SLOT(slotOutput55clicked(bool)));
    connect(ui->output56, SIGNAL(clicked(bool)), this, SLOT(slotOutput56clicked(bool)));
    connect(ui->output57, SIGNAL(clicked(bool)), this, SLOT(slotOutput57clicked(bool)));
    connect(ui->output58, SIGNAL(clicked(bool)), this, SLOT(slotOutput58clicked(bool)));
    connect(ui->output59, SIGNAL(clicked(bool)), this, SLOT(slotOutput59clicked(bool)));
    connect(ui->output60, SIGNAL(clicked(bool)), this, SLOT(slotOutput60clicked(bool)));
    connect(ui->output61, SIGNAL(clicked(bool)), this, SLOT(slotOutput61clicked(bool)));
    connect(ui->output62, SIGNAL(clicked(bool)), this, SLOT(slotOutput62clicked(bool)));

//    connect(ui->addError, SIGNAL(clicked(bool)), this, SLOT(slotAddError(bool)));

    /// TODO - кнопку нажала, запрос ушел. Рамка!
    /// Если ответ совпадает, то рамка зеленая,
    /// если нет - красная или желтая

    //    thread = new QThread(this);
    /// TODO - в отдельный поток?
    //    me->moveToThread(thread);    
    //    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    //    thread->start();

    //    timer = new QTimer(this);
//    connect(timer, SIGNAL (timeout()), this, SLOT(slotByTimer()));


    me->initTransmit();
    me->startExchange();
    connect(me, SIGNAL(signalReceiveIS3()), this, SLOT(slotWaitForSignalIS3()));
    connect(me, SIGNAL(signalReceiveIS4()), this, SLOT(slotWaitForSignalIS4()));
    connect(me, SIGNAL(signalReceiveIS5()), this, SLOT(slotWaitForSignalIS5()));

//    if (!me->startExchange())
//    {
//        qDebug() << "Все плохо";
//    }
//    else
//    {
//        timer = new QTimer(this);
//        connect(timer, SIGNAL (timeout()), this, SLOT(slotByTimer()));
////        timer->start(1000);
//    }

    //    showInputsValue();

   ui->statusbar->showMessage("Hello, my dear Daria!");
}

PVKPWindow::~PVKPWindow()
{
//    if (timer->isActive())
//    {
//        timer->stop();
//    }
    delete me;
    //    delete thread;
    delete ui;
}

void PVKPWindow::createPalette()
{
    red_palette.setColor(ui->output1->backgroundRole(), Qt::red/*255, 0, 0*/ );
    yellow_palette.setColor(ui->output1->backgroundRole(), Qt::yellow/*0, 0, 255*/ );
    green_palette.setColor(ui->output1->backgroundRole(), Qt::green/*0, 255, 0*/ );
    gray_palette.setColor(ui->output1->backgroundRole(), Qt::gray);
}

//void PVKPWindow::slotByTimer()
//{
//    me->usualExchange();

//    showInputsValue();
//    showOutputsValue();
//}

void PVKPWindow::slotWaitForSignalIS3()
{
    if (me->parse_IS3())
    {
        showInputsValue();
//        qDebug() << "Start main work!";
        if (me->start_exchange())
        {
            ui->statusbar->showMessage("Связь установлена.");
        }
        else
        {
            ui->statusbar->showMessage("Обмен идёт в штатном режиме");
        }

        me->usualExchange();
    }
    else
    {
        if (me->start_exchange())
        {
            ui->statusbar->showMessage("При разборе ИС3 прозошла ошибка! Связь не установлена.");
        }
        else
        {
//            qDebug() << "Something with IS1-IS3 is wrong";
            static int wrong(0);
            if (wrong == 3)
            {
                ui->statusbar->showMessage("При разборе ИС3 прозошла ошибка!");
            }
            wrong++;
            me->usualExchange();
        }
    }
//    me->usualExchange();
}

void PVKPWindow::slotWaitForSignalIS4()
{
    if (me->parse_IS4())
    {
        showOutputsValue();
//        qDebug() << "Good main work!";
        ui->statusbar->showMessage("Обмен идёт в штатном режиме");
    }
    else
    {
//        qDebug() << "Something with IS2-IS4 is wrong";
        static int wrong(0);
        if (wrong == 3)
        {
            ui->statusbar->showMessage("При разборе ИС4 прозошла ошибка!");
        }
        wrong++;
        me->usualExchange();
    }
}

void PVKPWindow::slotWaitForSignalIS5()
{
//    qDebug() << __FUNCTION__;
    me->usualExchange();
//    if ((me->getBytes_rcv_IS3_IS5() == sizeof(_is5)) || (me->getBytes_rcv_IS4_IS5() == sizeof(_is5)))
//    {

//    }
}

void PVKPWindow::slotAllOutputsOnOff(bool toggled)
{
    for (int i = 0; i < output_size; i++)
    {
        last_pressed_o[i] = !toggled;
    }

    if (toggled)
    {
        ui->allOutputsOff->setText("Включить все");

        if (ui->addError->isChecked())
        {
            me->addErrorToIS2(all_outputs, cntrl_off);
        }
        else
        {
            me->createIS2(all_outputs, cntrl_off);
        }

        // сохраняю для дальнейшего сравения с результатом
        for (int i = 0; i < output_size; i++)
        {
            o_cntrl[i] = cntrl_off;
        }
    }
    else
    {
        ui->allOutputsOff->setText("Выключить все");

        if (ui->addError->isChecked())
        {
            me->addErrorToIS2(all_outputs, cntrl_on);
        }
        else
        {
            me->createIS2(all_outputs, cntrl_on);
        }
        // сохраняю для дальнейшего сравения с результатом
        for (int i = 0; i < output_size; i++)
        {
            o_cntrl[i] = cntrl_on;
        }
    }

    ui->output1->clicked(true);
    ui->output2->clicked(true);
    ui->output3->clicked(true);
    ui->output4->clicked(true);
    ui->output5->clicked(true);
    ui->output6->clicked(true);
    ui->output7->clicked(true);
    ui->output8->clicked(true);
    ui->output9->clicked(true);
    ui->output10->clicked(true);
    ui->output11->clicked(true);
    ui->output12->clicked(true);
    ui->output13->clicked(true);
    ui->output14->clicked(true);
    ui->output15->clicked(true);
    ui->output16->clicked(true);
    ui->output17->clicked(true);
    ui->output18->clicked(true);
    ui->output19->clicked(true);
    ui->output20->clicked(true);
    ui->output21->clicked(true);
    ui->output22->clicked(true);
    ui->output23->clicked(true);
    ui->output24->clicked(true);
    ui->output25->clicked(true);
    ui->output26->clicked(true);
    ui->output27->clicked(true);
    ui->output28->clicked(true);
    ui->output29->clicked(true);
    ui->output30->clicked(true);
    ui->output31->clicked(true);
    ui->output32->clicked(true);
    ui->output33->clicked(true);
    ui->output34->clicked(true);
    ui->output35->clicked(true);
    ui->output36->clicked(true);
    ui->output37->clicked(true);
    ui->output38->clicked(true);
    ui->output39->clicked(true);
    ui->output40->clicked(true);
    ui->output41->clicked(true);
    ui->output42->clicked(true);
    ui->output43->clicked(true);
    ui->output44->clicked(true);
    ui->output45->clicked(true);
    ui->output46->clicked(true);
    ui->output47->clicked(true);
    ui->output48->clicked(true);
    ui->output49->clicked(true);
    ui->output50->clicked(true);
    ui->output51->clicked(true);
    ui->output52->clicked(true);
    ui->output53->clicked(true);
    ui->output54->clicked(true);
    ui->output55->clicked(true);
    ui->output56->clicked(true);
    ui->output57->clicked(true);
    ui->output58->clicked(true);
    ui->output59->clicked(true);
    ui->output60->clicked(true);
    ui->output61->clicked(true);
    ui->output62->clicked(true);
}

void PVKPWindow::manageOneOutput(int number, bool pressed, QPushButton *output_button)
{
    if (!pressed)
    {
        if (last_pressed_o[number - 1])
        {
            last_pressed_o[number - 1] = false;
//            output_button->setText(QString::number(number) + " Выключен");

            if (ui->addError->isChecked())
            {
                me->addErrorToIS2(number, cntrl_off);
            }
            else
            {
                me->createIS2(number, cntrl_off);
            }

            // сохраняю для дальнейшего сравения с результатом
            o_cntrl[number - 1] = cntrl_off;
        }
        else
        {
            last_pressed_o[number - 1] = true;
//            output_button->setText(QString::number(number) + " Включен");

            if (ui->addError->isChecked())
            {
                me->addErrorToIS2(number, cntrl_on);
            }
            else
            {
                me->createIS2(number, cntrl_on);
            }

            // сохраняю для дальнейшего сравения с результатом
            o_cntrl[number - 1] = cntrl_on;
        }
    }
//    else
//    {
//        if (last_pressed_o[number - 1])
//        {
//            ui->output1->setText(QString::number(output1) + " Выключен");
//            ui->output1->setText(QString::number(output1) + " Выключен");
//            ui->output1->setText(QString::number(output1) + " Выключен");
//            ui->output1->setText(QString::number(output1) + " Выключен");
//            ui->output1->setText(QString::number(output1) + " Выключен");
//            ui->output1->setText(QString::number(output1) + " Выключен");
//            ui->output1->setText(QString::number(output1) + " Выключен");
//            ui->output1->setText(QString::number(output1) + " Выключен");
//            ui->output1->setText(QString::number(output1) + " Выключен");
//            ui->output1->setText(QString::number(output1) + " Выключен");
//            ui->output1->setText(QString::number(output1) + " Выключен");
//            ui->output1->setText(QString::number(output1) + " Выключен");

//        }
//        else
//        {
//            output_button->setText(QString::number(number) + " Включен");
//        }
//    }
}

void PVKPWindow::slotOutput1clicked(bool pressed)
{
    manageOneOutput(output1, pressed, ui->output1);
}

void PVKPWindow::slotOutput2clicked(bool pressed)
{

    manageOneOutput(output2, pressed, ui->output2);
}

void PVKPWindow::slotOutput3clicked(bool pressed)
{

    manageOneOutput(output3, pressed, ui->output3);
}

void PVKPWindow::slotOutput4clicked(bool pressed)
{

    manageOneOutput(output4, pressed, ui->output4);
}

void PVKPWindow::slotOutput5clicked(bool pressed)
{

    manageOneOutput(output5, pressed, ui->output5);
}

void PVKPWindow::slotOutput6clicked(bool pressed)
{

    manageOneOutput(output6, pressed, ui->output6);
}

void PVKPWindow::slotOutput7clicked(bool pressed)
{

    manageOneOutput(output7, pressed, ui->output7);
}

void PVKPWindow::slotOutput8clicked(bool pressed)
{

    manageOneOutput(output8, pressed, ui->output8);
}

void PVKPWindow::slotOutput9clicked(bool pressed)
{

    manageOneOutput(output9, pressed, ui->output9);
}

void PVKPWindow::slotOutput10clicked(bool pressed)
{

    manageOneOutput(output10, pressed, ui->output10);
}

void PVKPWindow::slotOutput11clicked(bool pressed)
{

    manageOneOutput(output11, pressed, ui->output11);
}

void PVKPWindow::slotOutput12clicked(bool pressed)
{

    manageOneOutput(output12, pressed, ui->output12);
}

void PVKPWindow::slotOutput13clicked(bool pressed)
{

    manageOneOutput(output13, pressed, ui->output13);
}

void PVKPWindow::slotOutput14clicked(bool pressed)
{

    manageOneOutput(output14, pressed, ui->output14);
}

void PVKPWindow::slotOutput15clicked(bool pressed)
{

    manageOneOutput(output15, pressed, ui->output15);
}

void PVKPWindow::slotOutput16clicked(bool pressed)
{

    manageOneOutput(output16, pressed, ui->output16);
}

void PVKPWindow::slotOutput17clicked(bool pressed)
{

    manageOneOutput(output17, pressed, ui->output17);
}

void PVKPWindow::slotOutput18clicked(bool pressed)
{

    manageOneOutput(output18, pressed, ui->output18);
}

void PVKPWindow::slotOutput19clicked(bool pressed)
{

    manageOneOutput(output19, pressed, ui->output19);
}

void PVKPWindow::slotOutput20clicked(bool pressed)
{

    manageOneOutput(output20, pressed, ui->output20);
}

void PVKPWindow::slotOutput21clicked(bool pressed)
{

    manageOneOutput(output21, pressed, ui->output21);
}

void PVKPWindow::slotOutput22clicked(bool pressed)
{

    manageOneOutput(output22, pressed, ui->output22);
}

void PVKPWindow::slotOutput23clicked(bool pressed)
{

    manageOneOutput(output23, pressed, ui->output23);
}

void PVKPWindow::slotOutput24clicked(bool pressed)
{

    manageOneOutput(output24, pressed, ui->output24);
}

void PVKPWindow::slotOutput25clicked(bool pressed)
{

    manageOneOutput(output25, pressed, ui->output25);
}

void PVKPWindow::slotOutput26clicked(bool pressed)
{

    manageOneOutput(output26, pressed, ui->output26);
}

void PVKPWindow::slotOutput27clicked(bool pressed)
{

    manageOneOutput(output27, pressed, ui->output27);
}

void PVKPWindow::slotOutput28clicked(bool pressed)
{

    manageOneOutput(output28, pressed, ui->output28);
}

void PVKPWindow::slotOutput29clicked(bool pressed)
{

    manageOneOutput(output29, pressed, ui->output29);
}

void PVKPWindow::slotOutput30clicked(bool pressed)
{

    manageOneOutput(output30, pressed, ui->output30);
}

void PVKPWindow::slotOutput31clicked(bool pressed)
{

    manageOneOutput(output31, pressed, ui->output31);
}

void PVKPWindow::slotOutput32clicked(bool pressed)
{

    manageOneOutput(output32, pressed, ui->output32);
}

void PVKPWindow::slotOutput33clicked(bool pressed)
{

    manageOneOutput(output33, pressed, ui->output33);
}

void PVKPWindow::slotOutput34clicked(bool pressed)
{

    manageOneOutput(output34, pressed, ui->output34);
}

void PVKPWindow::slotOutput35clicked(bool pressed)
{

    manageOneOutput(output35, pressed, ui->output35);
}

void PVKPWindow::slotOutput36clicked(bool pressed)
{

    manageOneOutput(output36, pressed, ui->output36);
}

void PVKPWindow::slotOutput37clicked(bool pressed)
{

    manageOneOutput(output37, pressed, ui->output37);
}

void PVKPWindow::slotOutput38clicked(bool pressed)
{

    manageOneOutput(output38, pressed, ui->output38);
}

void PVKPWindow::slotOutput39clicked(bool pressed)
{

    manageOneOutput(output39, pressed, ui->output39);
}

void PVKPWindow::slotOutput40clicked(bool pressed)
{

    manageOneOutput(output40, pressed, ui->output40);
}

void PVKPWindow::slotOutput41clicked(bool pressed)
{

    manageOneOutput(output41, pressed, ui->output41);
}

void PVKPWindow::slotOutput42clicked(bool pressed)
{

    manageOneOutput(output42, pressed, ui->output42);
}

void PVKPWindow::slotOutput43clicked(bool pressed)
{

    manageOneOutput(output43, pressed, ui->output43);
}

void PVKPWindow::slotOutput44clicked(bool pressed)
{

    manageOneOutput(output44, pressed, ui->output44);
}

void PVKPWindow::slotOutput45clicked(bool pressed)
{

    manageOneOutput(output45, pressed, ui->output45);
}

void PVKPWindow::slotOutput46clicked(bool pressed)
{

    manageOneOutput(output46, pressed, ui->output46);
}

void PVKPWindow::slotOutput47clicked(bool pressed)
{

    manageOneOutput(output47, pressed, ui->output47);
}

void PVKPWindow::slotOutput48clicked(bool pressed)
{

    manageOneOutput(output48, pressed, ui->output48);
}

void PVKPWindow::slotOutput49clicked(bool pressed)
{

    manageOneOutput(output49, pressed, ui->output49);
}

void PVKPWindow::slotOutput50clicked(bool pressed)
{

    manageOneOutput(output50, pressed, ui->output50);
}

void PVKPWindow::slotOutput51clicked(bool pressed)
{

    manageOneOutput(output51, pressed, ui->output51);
}

void PVKPWindow::slotOutput52clicked(bool pressed)
{

    manageOneOutput(output52, pressed, ui->output52);
}

void PVKPWindow::slotOutput53clicked(bool pressed)
{

    manageOneOutput(output53, pressed, ui->output53);
}

void PVKPWindow::slotOutput54clicked(bool pressed)
{

    manageOneOutput(output54, pressed, ui->output54);
}

void PVKPWindow::slotOutput55clicked(bool pressed)
{

    manageOneOutput(output55, pressed, ui->output55);
}

void PVKPWindow::slotOutput56clicked(bool pressed)
{

    manageOneOutput(output56, pressed, ui->output56);
}

void PVKPWindow::slotOutput57clicked(bool pressed)
{

    manageOneOutput(output57, pressed, ui->output57);
}

void PVKPWindow::slotOutput58clicked(bool pressed)
{

    manageOneOutput(output58, pressed, ui->output58);
}

void PVKPWindow::slotOutput59clicked(bool pressed)
{

    manageOneOutput(output59, pressed, ui->output59);
}

void PVKPWindow::slotOutput60clicked(bool pressed)
{

    manageOneOutput(output60, pressed, ui->output60);
}

void PVKPWindow::slotOutput61clicked(bool pressed)
{

    manageOneOutput(output61, pressed, ui->output61);
}

void PVKPWindow::slotOutput62clicked(bool pressed)
{

    manageOneOutput(output62, pressed, ui->output62);
}

void PVKPWindow::manageOneOutput(int number, QPushButton *output_button)
{
    if (last_pressed_o[number - 1])
    {
        output_button->setText(QString::number(number) + " Выключен");
        last_pressed_o[number - 1] = false;

        if (ui->addError->isChecked())
        {
            me->addErrorToIS2(number, cntrl_off);
        }
        else
        {
            me->createIS2(number, cntrl_off);
        }

        // сохраняю для дальнейшего сравения с результатом
        o_cntrl[number - 1] = cntrl_off;
    }
    else
    {
        output_button->setText(QString::number(number) + " Включен");
        last_pressed_o[number - 1] = true;

        if (ui->addError->isChecked())
        {
            me->addErrorToIS2(number, cntrl_on);
        }
        else
        {
            me->createIS2(number, cntrl_on);
        }

        // сохраняю для дальнейшего сравения с результатом
        o_cntrl[number - 1] = cntrl_on;
    }
}

void PVKPWindow::showInputsValue()
{
    setInputColor(me->getInputState(input1), ui->input1);
    setInputColor(me->getInputState(input2), ui->input2);
    setInputColor(me->getInputState(input3), ui->input3);
    setInputColor(me->getInputState(input4), ui->input4);

    setInputColor(me->getInputState(input5), ui->input5);
    setInputColor(me->getInputState(input6), ui->input6);
    setInputColor(me->getInputState(input7), ui->input7);
    setInputColor(me->getInputState(input8), ui->input8);

    setInputColor(me->getInputState(input9), ui->input9);
    setInputColor(me->getInputState(input10), ui->input10);
    setInputColor(me->getInputState(input11), ui->input11);
    setInputColor(me->getInputState(input12), ui->input12);

    setInputColor(me->getInputState(input13), ui->input13);
    setInputColor(me->getInputState(input14), ui->input14);
    setInputColor(me->getInputState(input15), ui->input15);
    setInputColor(me->getInputState(input16), ui->input16);

    setInputColor(me->getInputState(input17), ui->input17);
    setInputColor(me->getInputState(input18), ui->input18);
    setInputColor(me->getInputState(input19), ui->input19);
    setInputColor(me->getInputState(input20), ui->input20);

    setInputColor(me->getInputState(input21), ui->input21);
    setInputColor(me->getInputState(input22), ui->input22);
    setInputColor(me->getInputState(input23), ui->input23);
    setInputColor(me->getInputState(input24), ui->input24);

    setInputColor(me->getInputState(input25), ui->input25);
    setInputColor(me->getInputState(input26), ui->input26);
    setInputColor(me->getInputState(input27), ui->input27);
    setInputColor(me->getInputState(input28), ui->input28);

    setInputColor(me->getInputState(input29), ui->input29);
    setInputColor(me->getInputState(input30), ui->input30);
    setInputColor(me->getInputState(input31), ui->input31);
    setInputColor(me->getInputState(input32), ui->input32);

    setInputColor(me->getInputState(input33), ui->input33);
    setInputColor(me->getInputState(input34), ui->input34);
    setInputColor(me->getInputState(input35), ui->input35);
    setInputColor(me->getInputState(input36), ui->input36);

    setInputColor(me->getInputState(input37), ui->input37);
    setInputColor(me->getInputState(input38), ui->input38);
    setInputColor(me->getInputState(input39), ui->input39);
    setInputColor(me->getInputState(input40), ui->input40);

    setInputColor(me->getInputState(input41), ui->input41);
    setInputColor(me->getInputState(input42), ui->input42);
    setInputColor(me->getInputState(input43), ui->input43);
    setInputColor(me->getInputState(input44), ui->input44);

    setInputColor(me->getInputState(input45), ui->input45);
    setInputColor(me->getInputState(input46), ui->input46);
    setInputColor(me->getInputState(input47), ui->input47);
    setInputColor(me->getInputState(input48), ui->input48);

    setInputColor(me->getInputState(input49), ui->input49);
    setInputColor(me->getInputState(input50), ui->input50);
    setInputColor(me->getInputState(input51), ui->input51);
    setInputColor(me->getInputState(input52), ui->input52);

    setInputColor(me->getInputState(input53), ui->input53);
    setInputColor(me->getInputState(input54), ui->input54);
    setInputColor(me->getInputState(input55), ui->input55);
    setInputColor(me->getInputState(input56), ui->input56);

    setInputColor(me->getInputState(input57), ui->input57);
    setInputColor(me->getInputState(input58), ui->input58);
    setInputColor(me->getInputState(input59), ui->input59);
    setInputColor(me->getInputState(input60), ui->input60);

    setInputColor(me->getInputState(input61), ui->input61);
    setInputColor(me->getInputState(input62), ui->input62);
    setInputColor(me->getInputState(input63), ui->input63);
    setInputColor(me->getInputState(input64), ui->input64);

    setInputColor(me->getInputState(input65), ui->input65);
    setInputColor(me->getInputState(input66), ui->input66);
    setInputColor(me->getInputState(input67), ui->input67);
    setInputColor(me->getInputState(input68), ui->input68);

    setInputColor(me->getInputState(input69), ui->input69);
    setInputColor(me->getInputState(input70), ui->input70);
    setInputColor(me->getInputState(input71), ui->input71);
    setInputColor(me->getInputState(input72), ui->input72);

    setInputColor(me->getInputState(input73), ui->input73);
    setInputColor(me->getInputState(input74), ui->input74);
    setInputColor(me->getInputState(input75), ui->input75);
    setInputColor(me->getInputState(input76), ui->input76);

    setInputColor(me->getInputState(input77), ui->input77);
    setInputColor(me->getInputState(input78), ui->input78);
    setInputColor(me->getInputState(input79), ui->input79);
    setInputColor(me->getInputState(input80), ui->input80);

    setInputColor(me->getInputState(input81), ui->input81);
    setInputColor(me->getInputState(input82), ui->input82);
    setInputColor(me->getInputState(input83), ui->input83);
    setInputColor(me->getInputState(input84), ui->input84);

    setInputColor(me->getInputState(input85), ui->input85);
    setInputColor(me->getInputState(input86), ui->input86);
    setInputColor(me->getInputState(input87), ui->input87);
    setInputColor(me->getInputState(input88), ui->input88);

    setInputColor(me->getInputState(input89), ui->input89);
    setInputColor(me->getInputState(input90), ui->input90);
    setInputColor(me->getInputState(input91), ui->input91);
    setInputColor(me->getInputState(input92), ui->input92);

    setInputColor(me->getInputState(input93), ui->input93);
    setInputColor(me->getInputState(input94), ui->input94);
    setInputColor(me->getInputState(input95), ui->input95);
    setInputColor(me->getInputState(input96), ui->input96);

    setInputColor(me->getInputState(input97), ui->input97);
    setInputColor(me->getInputState(input98), ui->input98);
    setInputColor(me->getInputState(input99), ui->input99);
    setInputColor(me->getInputState(input100), ui->input100);

    setInputColor(me->getInputState(input101), ui->input101);
    setInputColor(me->getInputState(input102), ui->input102);
    setInputColor(me->getInputState(input103), ui->input103);
    setInputColor(me->getInputState(input104), ui->input104);

    setInputColor(me->getInputState(input105), ui->input105);
    setInputColor(me->getInputState(input106), ui->input106);
    setInputColor(me->getInputState(input107), ui->input107);
    setInputColor(me->getInputState(input108), ui->input108);

    setInputColor(me->getInputState(input109), ui->input109);
    setInputColor(me->getInputState(input110), ui->input110);
    setInputColor(me->getInputState(input111), ui->input111);
    setInputColor(me->getInputState(input112), ui->input112);

    setInputColor(me->getInputState(input113), ui->input113);
    setInputColor(me->getInputState(input114), ui->input114);
    setInputColor(me->getInputState(input115), ui->input115);
    setInputColor(me->getInputState(input116), ui->input116);

    setInputColor(me->getInputState(input117), ui->input117);
    setInputColor(me->getInputState(input118), ui->input118);
    setInputColor(me->getInputState(input119), ui->input119);
    setInputColor(me->getInputState(input120), ui->input120);

    setInputColor(me->getInputState(input121), ui->input121);
    setInputColor(me->getInputState(input122), ui->input122);
    setInputColor(me->getInputState(input123), ui->input123);
    setInputColor(me->getInputState(input124), ui->input124);

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

void PVKPWindow::showOutputsValue()
{
    setOutputColor(output1,  ui->output1);
    setOutputColor(output2,  ui->output2);
    setOutputColor(output3,  ui->output3);
    setOutputColor(output4,  ui->output4);

    setOutputColor(output5,  ui->output5);
    setOutputColor(output6,  ui->output6);
    setOutputColor(output7,  ui->output7);
    setOutputColor(output8,  ui->output8);

    setOutputColor(output9,  ui->output9);
    setOutputColor(output10,  ui->output10);
    setOutputColor(output11,  ui->output11);
    setOutputColor(output12,  ui->output12);

    setOutputColor(output13,  ui->output13);
    setOutputColor(output14,  ui->output14);
    setOutputColor(output15,  ui->output15);
    setOutputColor(output16,  ui->output16);

    setOutputColor(output17,  ui->output17);
    setOutputColor(output18,  ui->output18);
    setOutputColor(output19,  ui->output19);
    setOutputColor(output20,  ui->output20);

    setOutputColor(output21,  ui->output21);
    setOutputColor(output22,  ui->output22);
    setOutputColor(output23,  ui->output23);
    setOutputColor(output24,  ui->output24);

    setOutputColor(output25,  ui->output25);
    setOutputColor(output26,  ui->output26);
    setOutputColor(output27,  ui->output27);
    setOutputColor(output28,  ui->output28);

    setOutputColor(output29,  ui->output29);
    setOutputColor(output30,  ui->output30);
    setOutputColor(output31,  ui->output31);
    setOutputColor(output32,  ui->output32);

    setOutputColor(output33,  ui->output33);
    setOutputColor(output34,  ui->output34);
    setOutputColor(output35,  ui->output35);
    setOutputColor(output36,  ui->output36);

    setOutputColor(output37,  ui->output37);
    setOutputColor(output38,  ui->output38);
    setOutputColor(output39,  ui->output39);
    setOutputColor(output40,  ui->output40);

    setOutputColor(output41,  ui->output41);
    setOutputColor(output42,  ui->output42);
    setOutputColor(output43,  ui->output43);
    setOutputColor(output44,  ui->output44);

    setOutputColor(output45,  ui->output45);
    setOutputColor(output46,  ui->output46);
    setOutputColor(output47,  ui->output47);
    setOutputColor(output48,  ui->output48);

    setOutputColor(output49,  ui->output49);
    setOutputColor(output50,  ui->output50);
    setOutputColor(output51,  ui->output51);
    setOutputColor(output52,  ui->output52);

    setOutputColor(output53,  ui->output53);
    setOutputColor(output54,  ui->output54);
    setOutputColor(output55,  ui->output55);
    setOutputColor(output56,  ui->output56);

    setOutputColor(output57,  ui->output57);
    setOutputColor(output58,  ui->output58);
    setOutputColor(output59,  ui->output59);
    setOutputColor(output60,  ui->output60);

    setOutputColor(output61,  ui->output61);
    setOutputColor(output62,  ui->output62);
}

void PVKPWindow::setOutputColor(int o_nmb, QPushButton *output_button)
{
    output_state state = me->getOutputState(o_nmb);
    if (o_nmb < output_size)
    {
        if (o_cntrl[o_nmb - 1] == cntrl_on)
        {
            switch (state)
            {
            case output_on:
                button_palette[o_nmb - 1].setColor(output_button->backgroundRole(), Qt::green);
                break;

            case output_off:
                button_palette[o_nmb - 1].setColor(output_button->backgroundRole(), Qt::gray);
                break;

            case no_output_state:
                button_palette[o_nmb - 1].setColor(output_button->backgroundRole(), Qt::yellow);
                break;

            case error_output:
                button_palette[o_nmb - 1].setColor(output_button->backgroundRole(), Qt::red);
                break;

            default:
                qDebug() << "output " << state << "no data";
                break;
            }
            output_button->setPalette(button_palette[o_nmb - 1]);
        }

        if (o_cntrl[o_nmb - 1] == cntrl_off)
        {
            switch (state)
            {
            case output_on:
                button_palette[o_nmb - 1].setColor(output_button->backgroundRole(), Qt::gray);
                break;

            case output_off:
                button_palette[o_nmb - 1].setColor(output_button->backgroundRole(), Qt::gray);
                break;

            case no_output_state:
                button_palette[o_nmb - 1].setColor(output_button->backgroundRole(), Qt::yellow);
                break;

            case error_output:
                button_palette[o_nmb - 1].setColor(output_button->backgroundRole(), Qt::red);
                break;

            default:
                qDebug() << "output " << state << "no data";
                break;
            }
            output_button->setPalette(button_palette[o_nmb - 1]);
        }

/*
        switch (state)
        {
        case output_on:
            output_button->setPalette(green_palette);
            if (o_cntrl[o_nmb - 1] == cntrl_on)
            {
                green_palette.setColor(QPalette::ColorRole::Background, Qt::green);    // рамка
            }
            else
            {
                green_palette.setColor(QPalette::ColorRole::Background, Qt::red);    // рамка
            }
            break;

        case output_off:
            output_button->setPalette(gray_palette);
            if (o_cntrl[o_nmb - 1] == cntrl_off)
            {
                gray_palette.setColor(QPalette::ColorRole::Background, Qt::green);    // рамка
            }
            else
            {
                gray_palette.setColor(QPalette::ColorRole::Background, Qt::red);    // рамка
            }
            break;

        case no_output_state:
            output_button->setPalette(yellow_palette);
            break;

        case error_output:
            output_button->setPalette(red_palette);
            break;

        default:
            qDebug() << "output " << state << "no data";
            break;
        }
*/
    }
    else
    {

    }

}
