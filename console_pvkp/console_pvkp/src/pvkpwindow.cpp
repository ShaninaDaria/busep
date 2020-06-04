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
    ui->testConnection->setPalette(yellow_palette);

    connect(ui->startStopButton, SIGNAL(pressed()), this, SLOT(slotStartStop()));
    connect(ui->testConnection, SIGNAL(pressed()), this, SLOT(slotTestConnection()));

    connect(ui->allOutputsOnOff, SIGNAL(toggled(bool)), this, SLOT(slotAllOutputsOnOff(bool)));

    connect(ui->output1_3, SIGNAL(clicked(bool)), this, SLOT(slotOutput1clicked(bool)));
    connect(ui->output2_3, SIGNAL(clicked(bool)), this, SLOT(slotOutput2clicked(bool)));
    connect(ui->output3_3, SIGNAL(clicked(bool)), this, SLOT(slotOutput3clicked(bool)));
    connect(ui->output4_3, SIGNAL(clicked(bool)), this, SLOT(slotOutput4clicked(bool)));
    connect(ui->output5_3, SIGNAL(clicked(bool)), this, SLOT(slotOutput5clicked(bool)));
    connect(ui->output6_3, SIGNAL(clicked(bool)), this, SLOT(slotOutput6clicked(bool)));
    connect(ui->output7_3, SIGNAL(clicked(bool)), this, SLOT(slotOutput7clicked(bool)));
    connect(ui->output8_3, SIGNAL(clicked(bool)), this, SLOT(slotOutput8clicked(bool)));
    connect(ui->output9_3, SIGNAL(clicked(bool)), this, SLOT(slotOutput9clicked(bool)));

    connect(ui->output10_3, SIGNAL(clicked(bool)), this, SLOT(slotOutput10clicked(bool)));
    connect(ui->output11_3, SIGNAL(clicked(bool)), this, SLOT(slotOutput11clicked(bool)));
    connect(ui->output12_3, SIGNAL(clicked(bool)), this, SLOT(slotOutput12clicked(bool)));
    connect(ui->output13_3, SIGNAL(clicked(bool)), this, SLOT(slotOutput13clicked(bool)));
    connect(ui->output14_3, SIGNAL(clicked(bool)), this, SLOT(slotOutput14clicked(bool)));
    connect(ui->output15_3, SIGNAL(clicked(bool)), this, SLOT(slotOutput15clicked(bool)));
    connect(ui->output16_3, SIGNAL(clicked(bool)), this, SLOT(slotOutput16clicked(bool)));
    connect(ui->output17_3, SIGNAL(clicked(bool)), this, SLOT(slotOutput17clicked(bool)));
    connect(ui->output18_3, SIGNAL(clicked(bool)), this, SLOT(slotOutput18clicked(bool)));
    connect(ui->output19_3, SIGNAL(clicked(bool)), this, SLOT(slotOutput19clicked(bool)));

    connect(ui->output20_3, SIGNAL(clicked(bool)), this, SLOT(slotOutput20clicked(bool)));
    connect(ui->output21_3, SIGNAL(clicked(bool)), this, SLOT(slotOutput21clicked(bool)));
    connect(ui->output22_3, SIGNAL(clicked(bool)), this, SLOT(slotOutput22clicked(bool)));
    connect(ui->output23_3, SIGNAL(clicked(bool)), this, SLOT(slotOutput23clicked(bool)));
    connect(ui->output24_3, SIGNAL(clicked(bool)), this, SLOT(slotOutput24clicked(bool)));
    connect(ui->output25_3, SIGNAL(clicked(bool)), this, SLOT(slotOutput25clicked(bool)));
    connect(ui->output26_3, SIGNAL(clicked(bool)), this, SLOT(slotOutput26clicked(bool)));
    connect(ui->output27_3, SIGNAL(clicked(bool)), this, SLOT(slotOutput27clicked(bool)));
    connect(ui->output28_3, SIGNAL(clicked(bool)), this, SLOT(slotOutput28clicked(bool)));
    connect(ui->output29_3, SIGNAL(clicked(bool)), this, SLOT(slotOutput29clicked(bool)));

    connect(ui->output30_3, SIGNAL(clicked(bool)), this, SLOT(slotOutput30clicked(bool)));
    connect(ui->output31_3, SIGNAL(clicked(bool)), this, SLOT(slotOutput31clicked(bool)));
    connect(ui->output32_3, SIGNAL(clicked(bool)), this, SLOT(slotOutput32clicked(bool)));
    connect(ui->output33_3, SIGNAL(clicked(bool)), this, SLOT(slotOutput33clicked(bool)));
    connect(ui->output34_3, SIGNAL(clicked(bool)), this, SLOT(slotOutput34clicked(bool)));
    connect(ui->output35_3, SIGNAL(clicked(bool)), this, SLOT(slotOutput35clicked(bool)));
    connect(ui->output36_3, SIGNAL(clicked(bool)), this, SLOT(slotOutput36clicked(bool)));
    connect(ui->output37_3, SIGNAL(clicked(bool)), this, SLOT(slotOutput37clicked(bool)));
    connect(ui->output38_3, SIGNAL(clicked(bool)), this, SLOT(slotOutput38clicked(bool)));
    connect(ui->output39_3, SIGNAL(clicked(bool)), this, SLOT(slotOutput39clicked(bool)));

    connect(ui->output40_3, SIGNAL(clicked(bool)), this, SLOT(slotOutput40clicked(bool)));
    connect(ui->output41_3, SIGNAL(clicked(bool)), this, SLOT(slotOutput41clicked(bool)));
    connect(ui->output42_3, SIGNAL(clicked(bool)), this, SLOT(slotOutput42clicked(bool)));
    connect(ui->output43_3, SIGNAL(clicked(bool)), this, SLOT(slotOutput43clicked(bool)));
    connect(ui->output44_3, SIGNAL(clicked(bool)), this, SLOT(slotOutput44clicked(bool)));
    connect(ui->output45_3, SIGNAL(clicked(bool)), this, SLOT(slotOutput45clicked(bool)));
    connect(ui->output46_3, SIGNAL(clicked(bool)), this, SLOT(slotOutput46clicked(bool)));
    connect(ui->output47_3, SIGNAL(clicked(bool)), this, SLOT(slotOutput47clicked(bool)));
    connect(ui->output48_3, SIGNAL(clicked(bool)), this, SLOT(slotOutput48clicked(bool)));
    connect(ui->output49_3, SIGNAL(clicked(bool)), this, SLOT(slotOutput49clicked(bool)));

    connect(ui->output50_3, SIGNAL(clicked(bool)), this, SLOT(slotOutput50clicked(bool)));
    connect(ui->output51_3, SIGNAL(clicked(bool)), this, SLOT(slotOutput51clicked(bool)));
    connect(ui->output52_3, SIGNAL(clicked(bool)), this, SLOT(slotOutput52clicked(bool)));
    connect(ui->output53_3, SIGNAL(clicked(bool)), this, SLOT(slotOutput53clicked(bool)));
    connect(ui->output54_3, SIGNAL(clicked(bool)), this, SLOT(slotOutput54clicked(bool)));
    connect(ui->output55_3, SIGNAL(clicked(bool)), this, SLOT(slotOutput55clicked(bool)));
    connect(ui->output56_3, SIGNAL(clicked(bool)), this, SLOT(slotOutput56clicked(bool)));
    connect(ui->output57_3, SIGNAL(clicked(bool)), this, SLOT(slotOutput57clicked(bool)));
    connect(ui->output58_3, SIGNAL(clicked(bool)), this, SLOT(slotOutput58clicked(bool)));
    connect(ui->output59_3, SIGNAL(clicked(bool)), this, SLOT(slotOutput59clicked(bool)));

    connect(ui->output60_3, SIGNAL(clicked(bool)), this, SLOT(slotOutput60clicked(bool)));
    connect(ui->output61_3, SIGNAL(clicked(bool)), this, SLOT(slotOutput61clicked(bool)));
    connect(ui->output62_3, SIGNAL(clicked(bool)), this, SLOT(slotOutput62clicked(bool)));


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
                port_name1 = file.readLine().trimmed();
                port_name2 = file.readLine().trimmed();
                baud_rate = file.readLine().trimmed();
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
        qDebug() << ui->listSerialPorts->itemText(port_index) + " is ready";
    }
    else
    {
        ui->statusbar->showMessage("Error with serial port " + ui->listSerialPorts->itemText(port_index));
         qDebug() << "Error with serial port " + ui->listSerialPorts->itemText(port_index);
    }
}

//----------------------------------------------------------

void PVKPWindow::createPalette()
{
    red_palette.setColor(ui->startStopButton->backgroundRole(), Qt::red);
    yellow_palette.setColor(ui->startStopButton->backgroundRole(), Qt::yellow);
    green_palette.setColor(ui->startStopButton->backgroundRole(), Qt::green);
    gray_palette.setColor(ui->startStopButton->backgroundRole(), Qt::gray);
    system_palette = ui->tabWidget->palette();
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
        ui->statusExchangeIS1_IS3->setText("Статус передачи ИС1 - ИС3 неизвестен");
        ui->statusExchangeIS2_IS4->setText("Статус передачи ИС2 - ИС4 неизвестен");
        start_simulator = true;

        ui->input1_3->setPalette(system_palette);
        ui->input2_3->setPalette(system_palette);
        ui->input3_3->setPalette(system_palette);
        ui->input4_3->setPalette(system_palette);
        ui->input5_3->setPalette(system_palette);
        ui->input6_3->setPalette(system_palette);
        ui->input7_3->setPalette(system_palette);
        ui->input8_3->setPalette(system_palette);
        ui->input9_3->setPalette(system_palette);
        ui->input10_3->setPalette(system_palette);
        ui->input11_3->setPalette(system_palette);
        ui->input12_3->setPalette(system_palette);
        ui->input13_3->setPalette(system_palette);
        ui->input14_3->setPalette(system_palette);
        ui->input15_3->setPalette(system_palette);
        ui->input16_3->setPalette(system_palette);
        ui->input17_3->setPalette(system_palette);
        ui->input18_3->setPalette(system_palette);
        ui->input19_3->setPalette(system_palette);
        ui->input20_3->setPalette(system_palette);
        ui->input21_3->setPalette(system_palette);
        ui->input22_3->setPalette(system_palette);
        ui->input23_3->setPalette(system_palette);
        ui->input24_3->setPalette(system_palette);
        ui->input25_3->setPalette(system_palette);
        ui->input26_3->setPalette(system_palette);
        ui->input27_3->setPalette(system_palette);
        ui->input28_3->setPalette(system_palette);
        ui->input29_3->setPalette(system_palette);
        ui->input30_3->setPalette(system_palette);
        ui->input31_3->setPalette(system_palette);
        ui->input32_3->setPalette(system_palette);
        ui->input33_3->setPalette(system_palette);
        ui->input34_3->setPalette(system_palette);
        ui->input35_3->setPalette(system_palette);
        ui->input36_3->setPalette(system_palette);
        ui->input37_3->setPalette(system_palette);
        ui->input38_3->setPalette(system_palette);
        ui->input39_3->setPalette(system_palette);
        ui->input40_3->setPalette(system_palette);
        ui->input41_3->setPalette(system_palette);
        ui->input42_3->setPalette(system_palette);
        ui->input43_3->setPalette(system_palette);
        ui->input44_3->setPalette(system_palette);
        ui->input45_3->setPalette(system_palette);
        ui->input46_3->setPalette(system_palette);
        ui->input47_3->setPalette(system_palette);
        ui->input48_3->setPalette(system_palette);
        ui->input49_3->setPalette(system_palette);
        ui->input50_3->setPalette(system_palette);
        ui->input51_3->setPalette(system_palette);
        ui->input52_3->setPalette(system_palette);
        ui->input53_3->setPalette(system_palette);
        ui->input54_3->setPalette(system_palette);
        ui->input55_3->setPalette(system_palette);
        ui->input56_3->setPalette(system_palette);
        ui->input57_3->setPalette(system_palette);
        ui->input58_3->setPalette(system_palette);
        ui->input59_3->setPalette(system_palette);
        ui->input60_3->setPalette(system_palette);
        ui->input61_3->setPalette(system_palette);
        ui->input62_3->setPalette(system_palette);
        ui->input63_3->setPalette(system_palette);
        ui->input64_3->setPalette(system_palette);
        ui->input65_3->setPalette(system_palette);
        ui->input66_3->setPalette(system_palette);
        ui->input67_3->setPalette(system_palette);
        ui->input68_3->setPalette(system_palette);
        ui->input69_3->setPalette(system_palette);
        ui->input70_3->setPalette(system_palette);
        ui->input71_3->setPalette(system_palette);
        ui->input72_3->setPalette(system_palette);
        ui->input73_3->setPalette(system_palette);
        ui->input74_3->setPalette(system_palette);
        ui->input75_3->setPalette(system_palette);
        ui->input76_3->setPalette(system_palette);
        ui->input77_3->setPalette(system_palette);
        ui->input78_3->setPalette(system_palette);
        ui->input79_3->setPalette(system_palette);
        ui->input80_3->setPalette(system_palette);
        ui->input81_3->setPalette(system_palette);
        ui->input82_3->setPalette(system_palette);
        ui->input83_3->setPalette(system_palette);
        ui->input84_3->setPalette(system_palette);
        ui->input85_3->setPalette(system_palette);
        ui->input86_3->setPalette(system_palette);
        ui->input87_3->setPalette(system_palette);
        ui->input88_3->setPalette(system_palette);
        ui->input89_3->setPalette(system_palette);
        ui->input90_3->setPalette(system_palette);
        ui->input91_3->setPalette(system_palette);
        ui->input92_3->setPalette(system_palette);
        ui->input93_3->setPalette(system_palette);
        ui->input94_3->setPalette(system_palette);
        ui->input95_3->setPalette(system_palette);
        ui->input96_3->setPalette(system_palette);
        ui->input97_3->setPalette(system_palette);
        ui->input98_3->setPalette(system_palette);
        ui->input99_3->setPalette(system_palette);
        ui->input100_3->setPalette(system_palette);
        ui->input101_3->setPalette(system_palette);
        ui->input102_3->setPalette(system_palette);
        ui->input103_3->setPalette(system_palette);
        ui->input104_3->setPalette(system_palette);
        ui->input105_3->setPalette(system_palette);
        ui->input106_3->setPalette(system_palette);
        ui->input107_3->setPalette(system_palette);
        ui->input108_3->setPalette(system_palette);
        ui->input109_3->setPalette(system_palette);
        ui->input110_3->setPalette(system_palette);
        ui->input111_3->setPalette(system_palette);
        ui->input112_3->setPalette(system_palette);
        ui->input113_3->setPalette(system_palette);
        ui->input114_3->setPalette(system_palette);
        ui->input115_3->setPalette(system_palette);
        ui->input116_3->setPalette(system_palette);
        ui->input117_3->setPalette(system_palette);
        ui->input118_3->setPalette(system_palette);
        ui->input119_3->setPalette(system_palette);
        ui->input120_3->setPalette(system_palette);
        ui->input121_3->setPalette(system_palette);
        ui->input122_3->setPalette(system_palette);
        ui->input123_3->setPalette(system_palette);
        ui->input124_3->setPalette(system_palette);

        ui->output1_3->setPalette(system_palette);
        ui->output2_3->setPalette(system_palette);
        ui->output3_3->setPalette(system_palette);
        ui->output4_3->setPalette(system_palette);
        ui->output5_3->setPalette(system_palette);
        ui->output6_3->setPalette(system_palette);
        ui->output7_3->setPalette(system_palette);
        ui->output8_3->setPalette(system_palette);
        ui->output9_3->setPalette(system_palette);
        ui->output10_3->setPalette(system_palette);
        ui->output11_3->setPalette(system_palette);
        ui->output12_3->setPalette(system_palette);
        ui->output13_3->setPalette(system_palette);
        ui->output14_3->setPalette(system_palette);
        ui->output15_3->setPalette(system_palette);
        ui->output16_3->setPalette(system_palette);
        ui->output17_3->setPalette(system_palette);
        ui->output18_3->setPalette(system_palette);
        ui->output19_3->setPalette(system_palette);
        ui->output20_3->setPalette(system_palette);
        ui->output21_3->setPalette(system_palette);
        ui->output22_3->setPalette(system_palette);
        ui->output23_3->setPalette(system_palette);
        ui->output24_3->setPalette(system_palette);
        ui->output25_3->setPalette(system_palette);
        ui->output26_3->setPalette(system_palette);
        ui->output27_3->setPalette(system_palette);
        ui->output28_3->setPalette(system_palette);
        ui->output29_3->setPalette(system_palette);
        ui->output30_3->setPalette(system_palette);
        ui->output31_3->setPalette(system_palette);
        ui->output32_3->setPalette(system_palette);
        ui->output33_3->setPalette(system_palette);
        ui->output34_3->setPalette(system_palette);
        ui->output35_3->setPalette(system_palette);
        ui->output36_3->setPalette(system_palette);
        ui->output37_3->setPalette(system_palette);
        ui->output38_3->setPalette(system_palette);
        ui->output39_3->setPalette(system_palette);
        ui->output40_3->setPalette(system_palette);
        ui->output41_3->setPalette(system_palette);
        ui->output42_3->setPalette(system_palette);
        ui->output43_3->setPalette(system_palette);
        ui->output44_3->setPalette(system_palette);
        ui->output45_3->setPalette(system_palette);
        ui->output46_3->setPalette(system_palette);
        ui->output47_3->setPalette(system_palette);
        ui->output48_3->setPalette(system_palette);
        ui->output49_3->setPalette(system_palette);
        ui->output50_3->setPalette(system_palette);
        ui->output51_3->setPalette(system_palette);
        ui->output52_3->setPalette(system_palette);
        ui->output53_3->setPalette(system_palette);
        ui->output54_3->setPalette(system_palette);
        ui->output55_3->setPalette(system_palette);
        ui->output56_3->setPalette(system_palette);
        ui->output57_3->setPalette(system_palette);
        ui->output58_3->setPalette(system_palette);
        ui->output59_3->setPalette(system_palette);
        ui->output60_3->setPalette(system_palette);
        ui->output61_3->setPalette(system_palette);
        ui->output62_3->setPalette(system_palette);

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
        last_pressed_o[i] = toggled;
    }

    if (toggled)
    {
        ui->allOutputsOnOff->setText("Выключить все");

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
        ui->allOutputsOnOff->setText("Включить все");

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

    ui->output1_3->clicked(true);
    ui->output2_3->clicked(true);
    ui->output3_3->clicked(true);
    ui->output4_3->clicked(true);
    ui->output5_3->clicked(true);
    ui->output6_3->clicked(true);
    ui->output7_3->clicked(true);
    ui->output8_3->clicked(true);
    ui->output9_3->clicked(true);
    ui->output10_3->clicked(true);
    ui->output11_3->clicked(true);
    ui->output12_3->clicked(true);
    ui->output13_3->clicked(true);
    ui->output14_3->clicked(true);
    ui->output15_3->clicked(true);
    ui->output16_3->clicked(true);
    ui->output17_3->clicked(true);
    ui->output18_3->clicked(true);
    ui->output19_3->clicked(true);
    ui->output20_3->clicked(true);
    ui->output21_3->clicked(true);
    ui->output22_3->clicked(true);
    ui->output23_3->clicked(true);
    ui->output24_3->clicked(true);
    ui->output25_3->clicked(true);
    ui->output26_3->clicked(true);
    ui->output27_3->clicked(true);
    ui->output28_3->clicked(true);
    ui->output29_3->clicked(true);
    ui->output30_3->clicked(true);
    ui->output31_3->clicked(true);
    ui->output32_3->clicked(true);
    ui->output33_3->clicked(true);
    ui->output34_3->clicked(true);
    ui->output35_3->clicked(true);
    ui->output36_3->clicked(true);
    ui->output37_3->clicked(true);
    ui->output38_3->clicked(true);
    ui->output39_3->clicked(true);
    ui->output40_3->clicked(true);
    ui->output41_3->clicked(true);
    ui->output42_3->clicked(true);
    ui->output43_3->clicked(true);
    ui->output44_3->clicked(true);
    ui->output45_3->clicked(true);
    ui->output46_3->clicked(true);
    ui->output47_3->clicked(true);
    ui->output48_3->clicked(true);
    ui->output49_3->clicked(true);
    ui->output50_3->clicked(true);
    ui->output51_3->clicked(true);
    ui->output52_3->clicked(true);
    ui->output53_3->clicked(true);
    ui->output54_3->clicked(true);
    ui->output55_3->clicked(true);
    ui->output56_3->clicked(true);
    ui->output57_3->clicked(true);
    ui->output58_3->clicked(true);
    ui->output59_3->clicked(true);
    ui->output60_3->clicked(true);
    ui->output61_3->clicked(true);
    ui->output62_3->clicked(true);
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
    setInputColor(input1, ui->input1_3);
    setInputColor(input2, ui->input2_3);
    setInputColor(input3, ui->input3_3);
    setInputColor(input4, ui->input4_3);

    setInputColor(input5, ui->input5_3);
    setInputColor(input6, ui->input6_3);
    setInputColor(input7, ui->input7_3);
    setInputColor(input8, ui->input8_3);

    setInputColor(input9, ui->input9_3);
    setInputColor(input10, ui->input10_3);
    setInputColor(input11, ui->input11_3);
    setInputColor(input12, ui->input12_3);

    setInputColor(input13, ui->input13_3);
    setInputColor(input14, ui->input14_3);
    setInputColor(input15, ui->input15_3);
    setInputColor(input16, ui->input16_3);

    setInputColor(input17, ui->input17_3);
    setInputColor(input18, ui->input18_3);
    setInputColor(input19, ui->input19_3);
    setInputColor(input20, ui->input20_3);

    setInputColor(input21, ui->input21_3);
    setInputColor(input22, ui->input22_3);
    setInputColor(input23, ui->input23_3);
    setInputColor(input24, ui->input24_3);

    setInputColor(input25, ui->input25_3);
    setInputColor(input26, ui->input26_3);
    setInputColor(input27, ui->input27_3);
    setInputColor(input28, ui->input28_3);

    setInputColor(input29, ui->input29_3);
    setInputColor(input30, ui->input30_3);
    setInputColor(input31, ui->input31_3);
    setInputColor(input32, ui->input32_3);

    setInputColor(input33, ui->input33_3);
    setInputColor(input34, ui->input34_3);
    setInputColor(input35, ui->input35_3);
    setInputColor(input36, ui->input36_3);

    setInputColor(input37, ui->input37_3);
    setInputColor(input38, ui->input38_3);
    setInputColor(input39, ui->input39_3);
    setInputColor(input40, ui->input40_3);

    setInputColor(input41, ui->input41_3);
    setInputColor(input42, ui->input42_3);
    setInputColor(input43, ui->input43_3);
    setInputColor(input44, ui->input44_3);

    setInputColor(input45, ui->input45_3);
    setInputColor(input46, ui->input46_3);
    setInputColor(input47, ui->input47_3);
    setInputColor(input48, ui->input48_3);

    setInputColor(input49, ui->input49_3);
    setInputColor(input50, ui->input50_3);
    setInputColor(input51, ui->input51_3);
    setInputColor(input52, ui->input52_3);

    setInputColor(input53, ui->input53_3);
    setInputColor(input54, ui->input54_3);
    setInputColor(input55, ui->input55_3);
    setInputColor(input56, ui->input56_3);

    setInputColor(input57, ui->input57_3);
    setInputColor(input58, ui->input58_3);
    setInputColor(input59, ui->input59_3);
    setInputColor(input60, ui->input60_3);

    setInputColor(input61, ui->input61_3);
    setInputColor(input62, ui->input62_3);
    setInputColor(input63, ui->input63_3);
    setInputColor(input64, ui->input64_3);

    setInputColor(input65, ui->input65_3);
    setInputColor(input66, ui->input66_3);
    setInputColor(input67, ui->input67_3);
    setInputColor(input68, ui->input68_3);

    setInputColor(input69, ui->input69_3);
    setInputColor(input70, ui->input70_3);
    setInputColor(input71, ui->input71_3);
    setInputColor(input72, ui->input72_3);

    setInputColor(input73, ui->input73_3);
    setInputColor(input74, ui->input74_3);
    setInputColor(input75, ui->input75_3);
    setInputColor(input76, ui->input76_3);

    setInputColor(input77, ui->input77_3);
    setInputColor(input78, ui->input78_3);
    setInputColor(input79, ui->input79_3);
    setInputColor(input80, ui->input80_3);

    setInputColor(input81, ui->input81_3);
    setInputColor(input82, ui->input82_3);
    setInputColor(input83, ui->input83_3);
    setInputColor(input84, ui->input84_3);

    setInputColor(input85, ui->input85_3);
    setInputColor(input86, ui->input86_3);
    setInputColor(input87, ui->input87_3);
    setInputColor(input88, ui->input88_3);

    setInputColor(input89, ui->input89_3);
    setInputColor(input90, ui->input90_3);
    setInputColor(input91, ui->input91_3);
    setInputColor(input92, ui->input92_3);

    setInputColor(input93, ui->input93_3);
    setInputColor(input94, ui->input94_3);
    setInputColor(input95, ui->input95_3);
    setInputColor(input96, ui->input96_3);

    setInputColor(input97, ui->input97_3);
    setInputColor(input98, ui->input98_3);
    setInputColor(input99, ui->input99_3);
    setInputColor(input100, ui->input100_3);

    setInputColor(input101, ui->input101_3);
    setInputColor(input102, ui->input102_3);
    setInputColor(input103, ui->input103_3);
    setInputColor(input104, ui->input104_3);

    setInputColor(input105, ui->input105_3);
    setInputColor(input106, ui->input106_3);
    setInputColor(input107, ui->input107_3);
    setInputColor(input108, ui->input108_3);

    setInputColor(input109, ui->input109_3);
    setInputColor(input110, ui->input110_3);
    setInputColor(input111, ui->input111_3);
    setInputColor(input112, ui->input112_3);

    setInputColor(input113, ui->input113_3);
    setInputColor(input114, ui->input114_3);
    setInputColor(input115, ui->input115_3);
    setInputColor(input116, ui->input116_3);

    setInputColor(input117, ui->input117_3);
    setInputColor(input118, ui->input118_3);
    setInputColor(input119, ui->input119_3);
    setInputColor(input120, ui->input120_3);

    setInputColor(input121, ui->input121_3);
    setInputColor(input122, ui->input122_3);
    setInputColor(input123, ui->input123_3);
    setInputColor(input124, ui->input124_3);
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
    setOutputColor(output1,  ui->output1_3);
    setOutputColor(output2,  ui->output2_3);
    setOutputColor(output3,  ui->output3_3);
    setOutputColor(output4,  ui->output4_3);

    setOutputColor(output5,  ui->output5_3);
    setOutputColor(output6,  ui->output6_3);
    setOutputColor(output7,  ui->output7_3);
    setOutputColor(output8,  ui->output8_3);

    setOutputColor(output9,  ui->output9_3);
    setOutputColor(output10,  ui->output10_3);
    setOutputColor(output11,  ui->output11_3);
    setOutputColor(output12,  ui->output12_3);

    setOutputColor(output13,  ui->output13_3);
    setOutputColor(output14,  ui->output14_3);
    setOutputColor(output15,  ui->output15_3);
    setOutputColor(output16,  ui->output16_3);

    setOutputColor(output17,  ui->output17_3);
    setOutputColor(output18,  ui->output18_3);
    setOutputColor(output19,  ui->output19_3);
    setOutputColor(output20,  ui->output20_3);

    setOutputColor(output21,  ui->output21_3);
    setOutputColor(output22,  ui->output22_3);
    setOutputColor(output23,  ui->output23_3);
    setOutputColor(output24,  ui->output24_3);

    setOutputColor(output25,  ui->output25_3);
    setOutputColor(output26,  ui->output26_3);
    setOutputColor(output27,  ui->output27_3);
    setOutputColor(output28,  ui->output28_3);

    setOutputColor(output29,  ui->output29_3);
    setOutputColor(output30,  ui->output30_3);
    setOutputColor(output31,  ui->output31_3);
    setOutputColor(output32,  ui->output32_3);

    setOutputColor(output33,  ui->output33_3);
    setOutputColor(output34,  ui->output34_3);
    setOutputColor(output35,  ui->output35_3);
    setOutputColor(output36,  ui->output36_3);

    setOutputColor(output37,  ui->output37_3);
    setOutputColor(output38,  ui->output38_3);
    setOutputColor(output39,  ui->output39_3);
    setOutputColor(output40,  ui->output40_3);

    setOutputColor(output41,  ui->output41_3);
    setOutputColor(output42,  ui->output42_3);
    setOutputColor(output43,  ui->output43_3);
    setOutputColor(output44,  ui->output44_3);

    setOutputColor(output45,  ui->output45_3);
    setOutputColor(output46,  ui->output46_3);
    setOutputColor(output47,  ui->output47_3);
    setOutputColor(output48,  ui->output48_3);

    setOutputColor(output49,  ui->output49_3);
    setOutputColor(output50,  ui->output50_3);
    setOutputColor(output51,  ui->output51_3);
    setOutputColor(output52,  ui->output52_3);

    setOutputColor(output53,  ui->output53_3);
    setOutputColor(output54,  ui->output54_3);
    setOutputColor(output55,  ui->output55_3);
    setOutputColor(output56,  ui->output56_3);

    setOutputColor(output57,  ui->output57_3);
    setOutputColor(output58,  ui->output58_3);
    setOutputColor(output59,  ui->output59_3);
    setOutputColor(output60,  ui->output60_3);

    setOutputColor(output61,  ui->output61_3);
    setOutputColor(output62,  ui->output62_3);
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
