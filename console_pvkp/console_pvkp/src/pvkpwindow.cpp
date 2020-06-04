#include <QTime>

#include "../hdr/pvkpwindow.h"
#include "ui_pvkpwindow.h"

//----------------------------------------------------------

PVKPWindow::PVKPWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PVKPWindow)
{
    ui->setupUi(this);
    createPalette();

    me = new messageExchange();

    for (int i = 0; i < output_size; i++)
    {
        last_pressed_o[i] = false;
    }

    for (int i = 0; i < output_size; i++)
    {
        o_cntrl[i] = cntrl_off;
    }

    start_simulator = true;

    ui->startStopButton->setPalette(green_palette);

    connect(ui->startStopButton, SIGNAL(pressed()), this, SLOT(slotStartStop()));
    connect(ui->testConnection, SIGNAL(pressed()), this, SLOT(slotTestConnection()));

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


    //    thread = new QThread(this);
    /// TODO - в отдельный поток?
    //    me->moveToThread(thread);    
    //    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    //    thread->start();


    /// проверка работы с последовательным портом
    /// не удалось вывести список всех портов - Failed to load the library: udev, supported version(s): 1 and 0
//    QList <QSerialPortInfo> list_sp_info = me->getAllSerialPorts();
//    for (int i = (list_sp_info.size() - 1); i >= 0 ; i--)
//    {
//        if (!list_sp_info.at(i).description().isEmpty())
//        {
//            ui->listSerialPorts->addItem(list_sp_info.at(i).portName());
//            qDebug() << list_sp_info.at(i).portName();
//        }
//        else
//        {
//            list_sp_info.removeAt(i);
//        }
//    }

//    if (!list_sp_info.isEmpty())
//    {
//        if (me->openSerialPort(list_sp_info.at(ui->listSerialPorts->currentIndex()).portName(), baud_rate))
//        {
//            ui->statusbar->showMessage("Ready");

//            connect(me, SIGNAL(signalReceiveIS3()), this, SLOT(slotReceiveIS3()));
//            connect(me, SIGNAL(signalReceiveIS4()), this, SLOT(slotReceiveIS4()));
//            connect(me, SIGNAL(signalReceiveIS5()), this, SLOT(slotReceiveIS5()));
//            connect(me, SIGNAL(signalNoReceiveIS3()), this, SLOT(slotNoReceiveIS3()));
//            connect(me, SIGNAL(signalNoReceiveIS4()), this, SLOT(slotNoReceiveIS4()));
//        }
//        else
//        {
//            ui->statusbar->showMessage("Error with serial port " +
//                                       list_sp_info.at(ui->listSerialPorts->currentIndex()).portName());
//        }
//    }
//    else
//    {
//        ui->listSerialPorts->hide();

        // вариант с конфигурационным файлом
        if (readConfigFile())
        {
            connect(ui->listSerialPorts, SIGNAL(currentIndexChanged(int)), this, SLOT(slotPortChecked(int)));
            connect(me, SIGNAL(signalReceiveIS3()), this, SLOT(slotReceiveIS3()));
            connect(me, SIGNAL(signalReceiveIS4()), this, SLOT(slotReceiveIS4()));
            connect(me, SIGNAL(signalReceiveIS5()), this, SLOT(slotReceiveIS5()));
            connect(me, SIGNAL(signalNoReceiveIS3()), this, SLOT(slotNoReceiveIS3()));
            connect(me, SIGNAL(signalNoReceiveIS4()), this, SLOT(slotNoReceiveIS4()));
            connect(me, SIGNAL(signalTest(QString)), this, SLOT(slotTestReceive(QString)));

            ui->listSerialPorts->setCurrentIndex(1);
//            slotPortChecked(1);
        }
        else
        {
            ui->startStopButton->setEnabled(false);
        }

//    }
}

//----------------------------------------------------------

PVKPWindow::~PVKPWindow()
{
//    delete thread;

    delete me;

    delete ui;
}

//----------------------------------------------------------

bool PVKPWindow::readConfigFile()
{
    QFile file;
    file.setFileName(file_name);
    QString port_name1, port_name2, baud_rate;
    if (file.exists())
    {
        file.open(QIODevice::ReadOnly | QIODevice::Text);
//        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        if (file.isOpen())
        {
            qDebug() << file.fileName();
            while (!file.atEnd())
            {
                port_name1 = file.readLine();
                port_name2 = file.readLine();
                baud_rate = file.readLine();
                port_name1 = port_name1.trimmed();
                port_name2 = port_name2.trimmed();
                baud_rate = baud_rate.trimmed();
                ui->listSerialPorts->addItem(port_name1);
                ui->listSerialPorts->addItem(port_name2);
                ui->baud_rate->setText(baud_rate);

                qDebug() << port_name1 << port_name2 << baud_rate;
            }

            file.close();

            if (!port_name1.isEmpty() && !port_name2.isEmpty() && !baud_rate.isEmpty())
            {
                return true;
            }
        }
        else
        {
            ui->statusbar->showMessage("Error open file 'config.ini'");
        }
    }
    else
    {
        ui->statusbar->showMessage("No file 'config.ini'");
    }

    return false;
}

//----------------------------------------------------------

void PVKPWindow::slotPortChecked(int port_index)
{
    if (me->openSerialPort(ui->listSerialPorts->itemText(port_index), ui->baud_rate->text().toInt()))
    {
        ui->statusbar->showMessage(ui->listSerialPorts->itemText(port_index) + " is ready");
        qDebug() << __FUNCTION__ << ui->listSerialPorts->itemText(port_index) + " is ready";
    }
    else
    {
        ui->statusbar->showMessage("Error with serial port " + ui->listSerialPorts->itemText(port_index));
         qDebug() << __FUNCTION__ << "Error with serial port " + ui->listSerialPorts->itemText(port_index);
    }

}

//----------------------------------------------------------

void PVKPWindow::createPalette()
{
    red_palette.setColor(ui->output1->backgroundRole(), Qt::red);
    yellow_palette.setColor(ui->output1->backgroundRole(), Qt::yellow);
    green_palette.setColor(ui->output1->backgroundRole(), Qt::green);
    gray_palette.setColor(ui->output1->backgroundRole(), Qt::gray);
}

//----------------------------------------------------------

void PVKPWindow::slotReceiveIS3()
{
    if (me->parse_IS3())
    {
        showInputsValue();
        if (me->start_exchange())
        {
            ui->log->append("Подключено к БУСЭП");
            ui->statusbar->showMessage("Связь установлена.");
            qDebug() << "HANGUP";
        }
        else
        {
            if (!me->parse_IS5())
            {
                ui->statusExchangeIS1_IS3->setText("Обмен ИС1 - ИС3 идёт в штатном режиме");
                ui->statusReceiveIS5->clear();
            }
        }
        me->setParse_IS3(false);

        me->usualExchange2();
    }
    else
    {
        if (me->start_exchange())
        {
            ui->statusbar->showMessage("При разборе ИС3 прозошла ошибка! Связь не установлена.");
        }
        else
        {
            static int wrong(0);
            if (wrong == 3)
            {
                ui->statusExchangeIS1_IS3->setText("При разборе ИС3 прозошла ошибка!");
                ui->statusReceiveIS5->clear();
            }
            wrong++;
            me->usualExchange2();
        }
    }
}

//----------------------------------------------------------

void PVKPWindow::slotReceiveIS4()
{
//    qDebug() << __FUNCTION__;
    static int wrong(0);
    if (me->parse_IS4())
    {
        showOutputsValue();
        if (!me->parse_IS5())
        {
            ui->statusExchangeIS2_IS4->setText("Обмен ИС2 - ИС4 идёт в штатном режиме");
            me->setParse_IS4(false);
            wrong = 0;
        }

    }
    else
    {
        if (wrong == 3)
        {
            ui->statusExchangeIS2_IS4->setText("При разборе ИС4 прозошла ошибка!");
        }
        wrong++;
    }
    ui->statusReceiveIS5->clear();
    me->usualExchange2();
}

//----------------------------------------------------------

void PVKPWindow::slotReceiveIS5()
{
//    qDebug() << __FUNCTION__;
//    ui->statusReceiveIS5->setText("Принято сообщение ИС5!");
    ui->log->append("Принято сообщение ИС5!");
    me->usualExchange2();
}

//----------------------------------------------------------

void PVKPWindow::slotTestReceive(QString str)
{
    ui->log->append(str);
}

//----------------------------------------------------------

void PVKPWindow::slotNoReceiveIS3()
{
    ui->log->append(QTime::currentTime().toString("hh:mm:ss:zzz") + " За ожидаемое время (100 мс) не принято ИС3");
}

//----------------------------------------------------------

void PVKPWindow::slotNoReceiveIS4()
{
    ui->log->append(QTime::currentTime().toString("hh:mm:ss:zzz") + " За ожидаемое время (10 мс) не принято ИС4");
}

//----------------------------------------------------------

void PVKPWindow::slotStartStop()
{
    if (start_simulator)
    {
        me->startExchange();

        ui->startStopButton->setPalette(red_palette);
        ui->startStopButton->setText("Стоп");
        ui->log->append("Старт");
        start_simulator = false;
    }
    else
    {
        me->stopExchange();
        ui->startStopButton->setPalette(green_palette);
        ui->startStopButton->setText("Старт");
        ui->log->append("Стоп");
        ui->statusbar->showMessage("Стоп");
        start_simulator = true;
    }
}

//----------------------------------------------------------

void PVKPWindow::slotTestConnection()
{
    me->testConnection();
}

//----------------------------------------------------------

void PVKPWindow::slotAllOutputsOnOff(bool toggled)
{
    for (int i = 0; i < output_size; i++)
    {
        last_pressed_o[i] = !toggled;
    }

    if (toggled)
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
    else
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

    if (me->sendIS2() < 0)
    {
        ui->log->append("Ошибка передачи ИС2 <" + QString(toggled? "включить" : "выключить") + " все выходы>");
    }
    else
    {
        ui->log->append("ИС2 <" + QString(toggled? "включить" : "выключить") + " все выходы> отправлено успешно");
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

//----------------------------------------------------------

void PVKPWindow::manageOneOutput(int number, bool pressed)
{
    if (!pressed)
    {
        if (last_pressed_o[number - 1])
        {
            if (ui->addError->isChecked())
            {
                qDebug() << number << "off with error";
                me->addErrorToIS2(number, cntrl_off);
            }
            else
            {
                qDebug() << number << "off";
                last_pressed_o[number - 1] = false;
                me->createIS2(number, cntrl_off);
            }

            // сохраняю для дальнейшего сравения с результатом
            o_cntrl[number - 1] = cntrl_off;
        }
        else
        {
            if (ui->addError->isChecked())
            {
                qDebug() << number << "on with error";
                me->addErrorToIS2(number, cntrl_on);
            }
            else
            {
                qDebug() << number << "on";
                last_pressed_o[number - 1] = true;
                me->createIS2(number, cntrl_on);
            }

            // сохраняю для дальнейшего сравения с результатом
            o_cntrl[number - 1] = cntrl_on;
        }

        if (me->sendIS2() < 0)
        {
            ui->log->append("Ошибка передачи ИС2 <" +
                            QString(last_pressed_o[number - 1]? "включить выход %1>" : "выключить выход %1>").arg(number));
        }
        else
        {
            ui->log->append("ИС2 <" +
                            QString(last_pressed_o[number - 1]? "включить выход %1>" : "выключить выход %1>").arg(number) +
                    " отправлено успешно");
        }
    }
}

//----------------------------------------------------------

void PVKPWindow::slotOutput1clicked(bool pressed)
{
    manageOneOutput(output1, pressed);
}

//----------------------------------------------------------

void PVKPWindow::slotOutput2clicked(bool pressed)
{
    manageOneOutput(output2, pressed);
}

//----------------------------------------------------------

void PVKPWindow::slotOutput3clicked(bool pressed)
{
    manageOneOutput(output3, pressed);
}

//----------------------------------------------------------

void PVKPWindow::slotOutput4clicked(bool pressed)
{
    manageOneOutput(output4, pressed);
}

//----------------------------------------------------------

void PVKPWindow::slotOutput5clicked(bool pressed)
{
    manageOneOutput(output5, pressed);
}

//----------------------------------------------------------

void PVKPWindow::slotOutput6clicked(bool pressed)
{

    manageOneOutput(output6, pressed);
}

//----------------------------------------------------------

void PVKPWindow::slotOutput7clicked(bool pressed)
{
    manageOneOutput(output7, pressed);
}

//----------------------------------------------------------

void PVKPWindow::slotOutput8clicked(bool pressed)
{
    manageOneOutput(output8, pressed);
}

//----------------------------------------------------------

void PVKPWindow::slotOutput9clicked(bool pressed)
{
    manageOneOutput(output9, pressed);
}

//----------------------------------------------------------

void PVKPWindow::slotOutput10clicked(bool pressed)
{
    manageOneOutput(output10, pressed);
}

//----------------------------------------------------------

void PVKPWindow::slotOutput11clicked(bool pressed)
{

    manageOneOutput(output11, pressed);
}

//----------------------------------------------------------

void PVKPWindow::slotOutput12clicked(bool pressed)
{
    manageOneOutput(output12, pressed);
}

//----------------------------------------------------------

void PVKPWindow::slotOutput13clicked(bool pressed)
{
    manageOneOutput(output13, pressed);
}

//----------------------------------------------------------

void PVKPWindow::slotOutput14clicked(bool pressed)
{
    manageOneOutput(output14, pressed);
}

//----------------------------------------------------------

void PVKPWindow::slotOutput15clicked(bool pressed)
{
    manageOneOutput(output15, pressed);
}

//----------------------------------------------------------

void PVKPWindow::slotOutput16clicked(bool pressed)
{
    manageOneOutput(output16, pressed);
}

//----------------------------------------------------------

void PVKPWindow::slotOutput17clicked(bool pressed)
{
    manageOneOutput(output17, pressed);
}

//----------------------------------------------------------

void PVKPWindow::slotOutput18clicked(bool pressed)
{
    manageOneOutput(output18, pressed);
}

//----------------------------------------------------------

void PVKPWindow::slotOutput19clicked(bool pressed)
{
    manageOneOutput(output19, pressed);
}

//----------------------------------------------------------

void PVKPWindow::slotOutput20clicked(bool pressed)
{
    manageOneOutput(output20, pressed);
}

//----------------------------------------------------------

void PVKPWindow::slotOutput21clicked(bool pressed)
{
    manageOneOutput(output21, pressed);
}

//----------------------------------------------------------

void PVKPWindow::slotOutput22clicked(bool pressed)
{
    manageOneOutput(output22, pressed);
}

//----------------------------------------------------------

void PVKPWindow::slotOutput23clicked(bool pressed)
{
    manageOneOutput(output23, pressed);
}

//----------------------------------------------------------

void PVKPWindow::slotOutput24clicked(bool pressed)
{
    manageOneOutput(output24, pressed);
}

//----------------------------------------------------------

void PVKPWindow::slotOutput25clicked(bool pressed)
{
    manageOneOutput(output25, pressed);
}

//----------------------------------------------------------

void PVKPWindow::slotOutput26clicked(bool pressed)
{

    manageOneOutput(output26, pressed);
}

//----------------------------------------------------------

void PVKPWindow::slotOutput27clicked(bool pressed)
{
    manageOneOutput(output27, pressed);
}

//----------------------------------------------------------

void PVKPWindow::slotOutput28clicked(bool pressed)
{
    manageOneOutput(output28, pressed);
}

//----------------------------------------------------------

void PVKPWindow::slotOutput29clicked(bool pressed)
{
    manageOneOutput(output29, pressed);
}

//----------------------------------------------------------

void PVKPWindow::slotOutput30clicked(bool pressed)
{
    manageOneOutput(output30, pressed);
}

//----------------------------------------------------------

void PVKPWindow::slotOutput31clicked(bool pressed)
{

    manageOneOutput(output31, pressed);
}

//----------------------------------------------------------

void PVKPWindow::slotOutput32clicked(bool pressed)
{
    manageOneOutput(output32, pressed);
}

//----------------------------------------------------------

void PVKPWindow::slotOutput33clicked(bool pressed)
{
    manageOneOutput(output33, pressed);
}

//----------------------------------------------------------

void PVKPWindow::slotOutput34clicked(bool pressed)
{
    manageOneOutput(output34, pressed);
}

//----------------------------------------------------------

void PVKPWindow::slotOutput35clicked(bool pressed)
{

    manageOneOutput(output35, pressed);
}

//----------------------------------------------------------

void PVKPWindow::slotOutput36clicked(bool pressed)
{
    manageOneOutput(output36, pressed);
}

//----------------------------------------------------------

void PVKPWindow::slotOutput37clicked(bool pressed)
{
    manageOneOutput(output37, pressed);
}

//----------------------------------------------------------

void PVKPWindow::slotOutput38clicked(bool pressed)
{
    manageOneOutput(output38, pressed);
}

//----------------------------------------------------------

void PVKPWindow::slotOutput39clicked(bool pressed)
{
    manageOneOutput(output39, pressed);
}

//----------------------------------------------------------

void PVKPWindow::slotOutput40clicked(bool pressed)
{
    manageOneOutput(output40, pressed);
}

//----------------------------------------------------------

void PVKPWindow::slotOutput41clicked(bool pressed)
{
    manageOneOutput(output41, pressed);
}

//----------------------------------------------------------

void PVKPWindow::slotOutput42clicked(bool pressed)
{
    manageOneOutput(output42, pressed);
}

//----------------------------------------------------------

void PVKPWindow::slotOutput43clicked(bool pressed)
{
    manageOneOutput(output43, pressed);
}

//----------------------------------------------------------

void PVKPWindow::slotOutput44clicked(bool pressed)
{
    manageOneOutput(output44, pressed);
}

//----------------------------------------------------------

void PVKPWindow::slotOutput45clicked(bool pressed)
{
    manageOneOutput(output45, pressed);
}

//----------------------------------------------------------

void PVKPWindow::slotOutput46clicked(bool pressed)
{
    manageOneOutput(output46, pressed);
}

//----------------------------------------------------------

void PVKPWindow::slotOutput47clicked(bool pressed)
{
    manageOneOutput(output47, pressed);
}

//----------------------------------------------------------

void PVKPWindow::slotOutput48clicked(bool pressed)
{
    manageOneOutput(output48, pressed);
}

//----------------------------------------------------------

void PVKPWindow::slotOutput49clicked(bool pressed)
{
    manageOneOutput(output49, pressed);
}

//----------------------------------------------------------

void PVKPWindow::slotOutput50clicked(bool pressed)
{
    manageOneOutput(output50, pressed);
}

//----------------------------------------------------------

void PVKPWindow::slotOutput51clicked(bool pressed)
{
    manageOneOutput(output51, pressed);
}

//----------------------------------------------------------

void PVKPWindow::slotOutput52clicked(bool pressed)
{
    manageOneOutput(output52, pressed);
}

//----------------------------------------------------------

void PVKPWindow::slotOutput53clicked(bool pressed)
{
    manageOneOutput(output53, pressed);
}

//----------------------------------------------------------

void PVKPWindow::slotOutput54clicked(bool pressed)
{
    manageOneOutput(output54, pressed);
}

//----------------------------------------------------------

void PVKPWindow::slotOutput55clicked(bool pressed)
{
    manageOneOutput(output55, pressed);
}

//----------------------------------------------------------

void PVKPWindow::slotOutput56clicked(bool pressed)
{
    manageOneOutput(output56, pressed);
}

//----------------------------------------------------------

void PVKPWindow::slotOutput57clicked(bool pressed)
{
    manageOneOutput(output57, pressed);
}

//----------------------------------------------------------

void PVKPWindow::slotOutput58clicked(bool pressed)
{
    manageOneOutput(output58, pressed);
}

//----------------------------------------------------------

void PVKPWindow::slotOutput59clicked(bool pressed)
{
    manageOneOutput(output59, pressed);
}

//----------------------------------------------------------

void PVKPWindow::slotOutput60clicked(bool pressed)
{
    manageOneOutput(output60, pressed);
}

//----------------------------------------------------------

void PVKPWindow::slotOutput61clicked(bool pressed)
{
    manageOneOutput(output61, pressed);
}

//----------------------------------------------------------

void PVKPWindow::slotOutput62clicked(bool pressed)
{
    manageOneOutput(output62, pressed);
}

//----------------------------------------------------------

void PVKPWindow::showInputsValue()
{
    setInputColor(input1, ui->input1);
    setInputColor(input2, ui->input2);
    setInputColor(input3, ui->input3);
    setInputColor(input4, ui->input4);

    setInputColor(input5, ui->input5);
    setInputColor(input6, ui->input6);
    setInputColor(input7, ui->input7);
    setInputColor(input8, ui->input8);

    setInputColor(input9, ui->input9);
    setInputColor(input10, ui->input10);
    setInputColor(input11, ui->input11);
    setInputColor(input12, ui->input12);

    setInputColor(input13, ui->input13);
    setInputColor(input14, ui->input14);
    setInputColor(input15, ui->input15);
    setInputColor(input16, ui->input16);

    setInputColor(input17, ui->input17);
    setInputColor(input18, ui->input18);
    setInputColor(input19, ui->input19);
    setInputColor(input20, ui->input20);

    setInputColor(input21, ui->input21);
    setInputColor(input22, ui->input22);
    setInputColor(input23, ui->input23);
    setInputColor(input24, ui->input24);

    setInputColor(input25, ui->input25);
    setInputColor(input26, ui->input26);
    setInputColor(input27, ui->input27);
    setInputColor(input28, ui->input28);

    setInputColor(input29, ui->input29);
    setInputColor(input30, ui->input30);
    setInputColor(input31, ui->input31);
    setInputColor(input32, ui->input32);

    setInputColor(input33, ui->input33);
    setInputColor(input34, ui->input34);
    setInputColor(input35, ui->input35);
    setInputColor(input36, ui->input36);

    setInputColor(input37, ui->input37);
    setInputColor(input38, ui->input38);
    setInputColor(input39, ui->input39);
    setInputColor(input40, ui->input40);

    setInputColor(input41, ui->input41);
    setInputColor(input42, ui->input42);
    setInputColor(input43, ui->input43);
    setInputColor(input44, ui->input44);

    setInputColor(input45, ui->input45);
    setInputColor(input46, ui->input46);
    setInputColor(input47, ui->input47);
    setInputColor(input48, ui->input48);

    setInputColor(input49, ui->input49);
    setInputColor(input50, ui->input50);
    setInputColor(input51, ui->input51);
    setInputColor(input52, ui->input52);

    setInputColor(input53, ui->input53);
    setInputColor(input54, ui->input54);
    setInputColor(input55, ui->input55);
    setInputColor(input56, ui->input56);

    setInputColor(input57, ui->input57);
    setInputColor(input58, ui->input58);
    setInputColor(input59, ui->input59);
    setInputColor(input60, ui->input60);

    setInputColor(input61, ui->input61);
    setInputColor(input62, ui->input62);
    setInputColor(input63, ui->input63);
    setInputColor(input64, ui->input64);

    setInputColor(input65, ui->input65);
    setInputColor(input66, ui->input66);
    setInputColor(input67, ui->input67);
    setInputColor(input68, ui->input68);

    setInputColor(input69, ui->input69);
    setInputColor(input70, ui->input70);
    setInputColor(input71, ui->input71);
    setInputColor(input72, ui->input72);

    setInputColor(input73, ui->input73);
    setInputColor(input74, ui->input74);
    setInputColor(input75, ui->input75);
    setInputColor(input76, ui->input76);

    setInputColor(input77, ui->input77);
    setInputColor(input78, ui->input78);
    setInputColor(input79, ui->input79);
    setInputColor(input80, ui->input80);

    setInputColor(input81, ui->input81);
    setInputColor(input82, ui->input82);
    setInputColor(input83, ui->input83);
    setInputColor(input84, ui->input84);

    setInputColor(input85, ui->input85);
    setInputColor(input86, ui->input86);
    setInputColor(input87, ui->input87);
    setInputColor(input88, ui->input88);

    setInputColor(input89, ui->input89);
    setInputColor(input90, ui->input90);
    setInputColor(input91, ui->input91);
    setInputColor(input92, ui->input92);

    setInputColor(input93, ui->input93);
    setInputColor(input94, ui->input94);
    setInputColor(input95, ui->input95);
    setInputColor(input96, ui->input96);

    setInputColor(input97, ui->input97);
    setInputColor(input98, ui->input98);
    setInputColor(input99, ui->input99);
    setInputColor(input100, ui->input100);

    setInputColor(input101, ui->input101);
    setInputColor(input102, ui->input102);
    setInputColor(input103, ui->input103);
    setInputColor(input104, ui->input104);

    setInputColor(input105, ui->input105);
    setInputColor(input106, ui->input106);
    setInputColor(input107, ui->input107);
    setInputColor(input108, ui->input108);

    setInputColor(input109, ui->input109);
    setInputColor(input110, ui->input110);
    setInputColor(input111, ui->input111);
    setInputColor(input112, ui->input112);

    setInputColor(input113, ui->input113);
    setInputColor(input114, ui->input114);
    setInputColor(input115, ui->input115);
    setInputColor(input116, ui->input116);

    setInputColor(input117, ui->input117);
    setInputColor(input118, ui->input118);
    setInputColor(input119, ui->input119);
    setInputColor(input120, ui->input120);

    setInputColor(input121, ui->input121);
    setInputColor(input122, ui->input122);
    setInputColor(input123, ui->input123);
    setInputColor(input124, ui->input124);
}

//----------------------------------------------------------

void PVKPWindow::setInputColor(int i_nmb, QPushButton *input_button)
{
    input_state state = me->getInputState(i_nmb);
    switch (state)
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

//----------------------------------------------------------

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

//----------------------------------------------------------
// к сожалению, нет команды опроса выходов, поэтому такая радуга
void PVKPWindow::setOutputColor(int o_nmb, QPushButton *output_button)
{
    output_state state = me->getOutputState(o_nmb);
    if (o_nmb < output_size)
    {
        // по моим данным, выход был включен
        if (o_cntrl[o_nmb - 1] == cntrl_on)
        {
            switch (state)
            {
            case output_on:
                button_palette[o_nmb - 1].setColor(output_button->backgroundRole(), Qt::green);
                break;

            // а из имитатора БУСЭП пришло состояние "выключен" (т.е. выход не был объявлен)
            // или имататор БУСЭПа упал
            case output_off:
                button_palette[o_nmb - 1].setColor(output_button->backgroundRole(), Qt::blue);
                break;

            case no_output_state:
                button_palette[o_nmb - 1].setColor(output_button->backgroundRole(), Qt::yellow);
                break;

            case error_output:
                button_palette[o_nmb - 1].setColor(output_button->backgroundRole(), Qt::red);
                break;
            }
            output_button->setPalette(button_palette[o_nmb - 1]);
        }

        // по моим данным, выход был выключен
        if (o_cntrl[o_nmb - 1] == cntrl_off)
        {
            switch (state)
            {
            // а из имитатора БУСЭП пришло состояние "включен"
            // (надеюсь, имитатор ПВКП переподключался, а это не была ошибка)
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
            }
            output_button->setPalette(button_palette[o_nmb - 1]);
        }

//        qDebug() << "STATE " << o_nmb << me->getOutputState(o_nmb);
    }
    else
    {
        ui->log->append(QString("Номер выхода %1 превышает количество выходов %2").arg(o_nmb).arg(output_size));
    }
}
