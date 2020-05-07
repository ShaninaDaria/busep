#include "../hdr/pvkpwindow.h"
#include "ui_pvkpwindow.h"

PVKPWindow::PVKPWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PVKPWindow)
{
    ui->setupUi(this);

    createPalette();

    me = new messageExchange();

    timer = new QTimer(this);
    connect(timer, SIGNAL (timeout()), this, SLOT(slotByTimer()));
    timer->start(1000);

    all_buttons_off = false;
    all_buttons_on = false;
    all_buttons_on_off = false;
    last_toggled_o1 = false;
    last_toggled_o2 = false;
    last_toggled_o3 = false;
    last_toggled_o4 = false;
    last_toggled_o5 = false;
    last_toggled_o6 = false;
    last_toggled_o7 = false;
    last_toggled_o8 = false;
    last_toggled_o9 = false;
    last_toggled_o10 = false;
    last_toggled_o11 = false;
    last_toggled_o12 = false;
    last_toggled_o13 = false;
    last_toggled_o14 = false;
    last_toggled_o15 = false;
    last_toggled_o16 = false;
    last_toggled_o17 = false;
    last_toggled_o18 = false;
    last_toggled_o19 = false;
    last_toggled_o20 = false;
    last_toggled_o21 = false;
    last_toggled_o22 = false;
    last_toggled_o23 = false;
    last_toggled_o24 = false;
    last_toggled_o25 = false;
    last_toggled_o26 = false;
    last_toggled_o27 = false;
    last_toggled_o28 = false;
    last_toggled_o29 = false;
    last_toggled_o30 = false;
    last_toggled_o31 = false;
    last_toggled_o32 = false;
    last_toggled_o33 = false;
    last_toggled_o34 = false;
    last_toggled_o35 = false;
    last_toggled_o36 = false;
    last_toggled_o37 = false;
    last_toggled_o38 = false;
    last_toggled_o39 = false;
    last_toggled_o40 = false;
    last_toggled_o41 = false;
    last_toggled_o42 = false;
    last_toggled_o43 = false;
    last_toggled_o44 = false;
    last_toggled_o45 = false;
    last_toggled_o46 = false;
    last_toggled_o47 = false;
    last_toggled_o48 = false;
    last_toggled_o49 = false;
    last_toggled_o50 = false;
    last_toggled_o51 = false;
    last_toggled_o52 = false;
    last_toggled_o53 = false;
    last_toggled_o54 = false;
    last_toggled_o55 = false;
    last_toggled_o56 = false;
    last_toggled_o57 = false;
    last_toggled_o58 = false;
    last_toggled_o59 = false;
    last_toggled_o60 = false;
    last_toggled_o61 = false;
    last_toggled_o62 = false;

    connect(ui->allOutputsOff, SIGNAL(toggled(bool)), this, SLOT(slotAllOutputsOff(bool)));
    //    connect(ui->allOutputsOff, SIGNAL(pressed()), this, SLOT(slotAllOutputsOff()));
    connect(ui->allOutputsOn, SIGNAL(pressed()), this, SLOT(slotAllOutputsOn()));
    connect(ui->output1, SIGNAL(toggled(bool)), this, SLOT(slotOutput1toggled(bool)));
    connect(ui->output2, SIGNAL(toggled(bool)), this, SLOT(slotOutput2toggled(bool)));
    /*
    connect(ui->output3, SIGNAL(toggled(bool)), this, SLOT(slotOutput3toggled(bool)));
    connect(ui->output4, SIGNAL(toggled(bool)), this, SLOT(slotOutput4toggled(bool)));
    connect(ui->output5, SIGNAL(toggled(bool)), this, SLOT(slotOutput5toggled(bool)));
    connect(ui->output6, SIGNAL(toggled(bool)), this, SLOT(slotOutput6toggled(bool)));
    connect(ui->output7, SIGNAL(toggled(bool)), this, SLOT(slotOutput7toggled(bool)));
    connect(ui->output8, SIGNAL(toggled(bool)), this, SLOT(slotOutput8toggled(bool)));
    connect(ui->output9, SIGNAL(toggled(bool)), this, SLOT(slotOutput9toggled(bool)));
    connect(ui->output10, SIGNAL(toggled(bool)), this, SLOT(slotOutput10toggled(bool)));
    connect(ui->output11, SIGNAL(toggled(bool)), this, SLOT(slotOutput11toggled(bool)));
    connect(ui->output12, SIGNAL(toggled(bool)), this, SLOT(slotOutput12toggled(bool)));
    connect(ui->output13, SIGNAL(toggled(bool)), this, SLOT(slotOutput13toggled(bool)));
    connect(ui->output14, SIGNAL(toggled(bool)), this, SLOT(slotOutput14toggled(bool)));
    connect(ui->output15, SIGNAL(toggled(bool)), this, SLOT(slotOutput15toggled(bool)));
    connect(ui->output16, SIGNAL(toggled(bool)), this, SLOT(slotOutput16toggled(bool)));
    connect(ui->output17, SIGNAL(toggled(bool)), this, SLOT(slotOutput17toggled(bool)));
    connect(ui->output18, SIGNAL(toggled(bool)), this, SLOT(slotOutput18toggled(bool)));
    connect(ui->output19, SIGNAL(toggled(bool)), this, SLOT(slotOutput19toggled(bool)));
    connect(ui->output20, SIGNAL(toggled(bool)), this, SLOT(slotOutput20toggled(bool)));
    connect(ui->output21, SIGNAL(toggled(bool)), this, SLOT(slotOutput21toggled(bool)));
    connect(ui->output22, SIGNAL(toggled(bool)), this, SLOT(slotOutput22toggled(bool)));
    connect(ui->output23, SIGNAL(toggled(bool)), this, SLOT(slotOutput23toggled(bool)));
    connect(ui->output24, SIGNAL(toggled(bool)), this, SLOT(slotOutput24toggled(bool)));
    connect(ui->output25, SIGNAL(toggled(bool)), this, SLOT(slotOutput25toggled(bool)));
    connect(ui->output26, SIGNAL(toggled(bool)), this, SLOT(slotOutput26toggled(bool)));
    connect(ui->output27, SIGNAL(toggled(bool)), this, SLOT(slotOutput27toggled(bool)));
    connect(ui->output28, SIGNAL(toggled(bool)), this, SLOT(slotOutput28toggled(bool)));
    connect(ui->output29, SIGNAL(toggled(bool)), this, SLOT(slotOutput29toggled(bool)));
    connect(ui->output30, SIGNAL(toggled(bool)), this, SLOT(slotOutput30toggled(bool)));
    connect(ui->output31, SIGNAL(toggled(bool)), this, SLOT(slotOutput31toggled(bool)));
    connect(ui->output32, SIGNAL(toggled(bool)), this, SLOT(slotOutput32toggled(bool)));
    connect(ui->output33, SIGNAL(toggled(bool)), this, SLOT(slotOutput33toggled(bool)));
    connect(ui->output34, SIGNAL(toggled(bool)), this, SLOT(slotOutput34toggled(bool)));
    connect(ui->output35, SIGNAL(toggled(bool)), this, SLOT(slotOutput35toggled(bool)));
    connect(ui->output36, SIGNAL(toggled(bool)), this, SLOT(slotOutput36toggled(bool)));
    connect(ui->output37, SIGNAL(toggled(bool)), this, SLOT(slotOutput38toggled(bool)));
    connect(ui->output38, SIGNAL(toggled(bool)), this, SLOT(slotOutput38toggled(bool)));
    connect(ui->output39, SIGNAL(toggled(bool)), this, SLOT(slotOutput39toggled(bool)));
    connect(ui->output40, SIGNAL(toggled(bool)), this, SLOT(slotOutput40toggled(bool)));
    connect(ui->output41, SIGNAL(toggled(bool)), this, SLOT(slotOutput41toggled(bool)));
    connect(ui->output42, SIGNAL(toggled(bool)), this, SLOT(slotOutput42toggled(bool)));
    connect(ui->output43, SIGNAL(toggled(bool)), this, SLOT(slotOutput43toggled(bool)));
    connect(ui->output44, SIGNAL(toggled(bool)), this, SLOT(slotOutput44toggled(bool)));
    connect(ui->output45, SIGNAL(toggled(bool)), this, SLOT(slotOutput45toggled(bool)));
    connect(ui->output46, SIGNAL(toggled(bool)), this, SLOT(slotOutput46toggled(bool)));
    connect(ui->output47, SIGNAL(toggled(bool)), this, SLOT(slotOutput47toggled(bool)));
    connect(ui->output48, SIGNAL(toggled(bool)), this, SLOT(slotOutput48toggled(bool)));
    connect(ui->output49, SIGNAL(toggled(bool)), this, SLOT(slotOutput49toggled(bool)));
    connect(ui->output50, SIGNAL(toggled(bool)), this, SLOT(slotOutput50toggled(bool)));
    connect(ui->output51, SIGNAL(toggled(bool)), this, SLOT(slotOutput51toggled(bool)));
    connect(ui->output52, SIGNAL(toggled(bool)), this, SLOT(slotOutput52toggled(bool)));
    connect(ui->output53, SIGNAL(toggled(bool)), this, SLOT(slotOutput53toggled(bool)));
    connect(ui->output54, SIGNAL(toggled(bool)), this, SLOT(slotOutput54toggled(bool)));
    connect(ui->output55, SIGNAL(toggled(bool)), this, SLOT(slotOutput55toggled(bool)));
    connect(ui->output56, SIGNAL(toggled(bool)), this, SLOT(slotOutput56toggled(bool)));
    connect(ui->output57, SIGNAL(toggled(bool)), this, SLOT(slotOutput57toggled(bool)));
    connect(ui->output58, SIGNAL(toggled(bool)), this, SLOT(slotOutput58toggled(bool)));
    connect(ui->output59, SIGNAL(toggled(bool)), this, SLOT(slotOutput59toggled(bool)));
    connect(ui->output60, SIGNAL(toggled(bool)), this, SLOT(slotOutput60toggled(bool)));
    connect(ui->output61, SIGNAL(toggled(bool)), this, SLOT(slotOutput61toggled(bool)));
    connect(ui->output62, SIGNAL(toggled(bool)), this, SLOT(slotOutput62toggled(bool)));*/

    /// TODO - кнопку нажала, запрос ушел. Если ответ совпадает, то рамка зеленая,
    /// если нет - красная или желтая

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
    //    timer->stop();
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
    //    red_palette.setColor(QPalette::ColorRole::Background, QColor(255, 0, 0) );    // рамка
}

void PVKPWindow::slotByTimer()
{
    //    me->startExchange();

    showInputsValue();
    showOutputsValue();
}
/// FIXME при нажатии "выключить/включить все" нажимаются все кнопки,
/// что приводит к вызову всех слотов
void PVKPWindow::slotAllOutputsOff(bool toggled)
{
    qDebug() << __FUNCTION__ << toggled;

    //    all_buttons_off = true;
    //    all_buttons_on = true;
//        all_buttons_on_off = true;

    all_buttons_on_off = toggled;
    qDebug() << "all_buttons_on_off" << all_buttons_on_off;
    last_toggled_o1 = toggled;
    last_toggled_o2 = toggled;

    if (toggled)
    {
        ui->allOutputsOff->setText("Включить все");

//        me->createIS2(all_outputs, cntrl_off);
    }
    else
    {
        ui->allOutputsOff->setText("Выключить все");

//        me->createIS2(all_outputs, cntrl_on);
    }

    ui->output1->setChecked(toggled);
    ui->output2->setChecked(toggled);
    ui->output3->setChecked(toggled);
    ui->output4->setChecked(toggled);
    ui->output5->setChecked(toggled);
    ui->output6->setChecked(toggled);
    ui->output7->setChecked(toggled);
    ui->output8->setChecked(toggled);
    ui->output9->setChecked(toggled);
    ui->output10->setChecked(toggled);
    ui->output11->setChecked(toggled);
    ui->output12->setChecked(toggled);
    ui->output13->setChecked(toggled);
    ui->output14->setChecked(toggled);
    ui->output15->setChecked(toggled);
    ui->output16->setChecked(toggled);
    ui->output17->setChecked(toggled);
    ui->output18->setChecked(toggled);
    ui->output19->setChecked(toggled);
    ui->output20->setChecked(toggled);
    ui->output21->setChecked(toggled);
    ui->output22->setChecked(toggled);
    ui->output23->setChecked(toggled);
    ui->output24->setChecked(toggled);
    ui->output25->setChecked(toggled);
    ui->output26->setChecked(toggled);
    ui->output27->setChecked(toggled);
    ui->output28->setChecked(toggled);
    ui->output29->setChecked(toggled);
    ui->output30->setChecked(toggled);
    ui->output31->setChecked(toggled);
    ui->output32->setChecked(toggled);
    ui->output33->setChecked(toggled);
    ui->output34->setChecked(toggled);
    ui->output35->setChecked(toggled);
    ui->output36->setChecked(toggled);
    ui->output37->setChecked(toggled);
    ui->output38->setChecked(toggled);
    ui->output39->setChecked(toggled);
    ui->output40->setChecked(toggled);
    ui->output41->setChecked(toggled);
    ui->output42->setChecked(toggled);
    ui->output43->setChecked(toggled);
    ui->output44->setChecked(toggled);
    ui->output45->setChecked(toggled);
    ui->output46->setChecked(toggled);
    ui->output47->setChecked(toggled);
    ui->output48->setChecked(toggled);
    ui->output49->setChecked(toggled);
    ui->output50->setChecked(toggled);
    ui->output51->setChecked(toggled);
    ui->output52->setChecked(toggled);
    ui->output53->setChecked(toggled);
    ui->output54->setChecked(toggled);
    ui->output55->setChecked(toggled);
    ui->output56->setChecked(toggled);
    ui->output57->setChecked(toggled);
    ui->output58->setChecked(toggled);
    ui->output59->setChecked(toggled);
    ui->output60->setChecked(toggled);
    ui->output61->setChecked(toggled);
    ui->output62->setChecked(toggled);
}

void PVKPWindow::slotAllOutputsOn()
{
    qDebug() << __FUNCTION__;
    me->createIS2(all_outputs, cntrl_on);

    all_buttons_on = true;
    all_buttons_off = true;
    all_buttons_on_off = true;

    ui->output1->setChecked(false);
    ui->output2->setChecked(false);
    ui->output3->setChecked(false);
    ui->output4->setChecked(false);
    ui->output5->setChecked(false);
    ui->output6->setChecked(false);
    ui->output7->setChecked(false);
    ui->output8->setChecked(false);
    ui->output9->setChecked(false);
    ui->output10->setChecked(false);
    ui->output11->setChecked(false);
    ui->output12->setChecked(false);
    ui->output13->setChecked(false);
    ui->output14->setChecked(false);
    ui->output15->setChecked(false);
    ui->output16->setChecked(false);
    ui->output17->setChecked(false);
    ui->output18->setChecked(false);
    ui->output19->setChecked(false);
    ui->output20->setChecked(false);
    ui->output21->setChecked(false);
    ui->output22->setChecked(false);
    ui->output23->setChecked(false);
    ui->output24->setChecked(false);
    ui->output25->setChecked(false);
    ui->output26->setChecked(false);
    ui->output27->setChecked(false);
    ui->output28->setChecked(false);
    ui->output29->setChecked(false);
    ui->output30->setChecked(false);
    ui->output31->setChecked(false);
    ui->output32->setChecked(false);
    ui->output33->setChecked(false);
    ui->output34->setChecked(false);
    ui->output35->setChecked(false);
    ui->output36->setChecked(false);
    ui->output37->setChecked(false);
    ui->output38->setChecked(false);
    ui->output39->setChecked(false);
    ui->output40->setChecked(false);
    ui->output41->setChecked(false);
    ui->output42->setChecked(false);
    ui->output43->setChecked(false);
    ui->output44->setChecked(false);
    ui->output45->setChecked(false);
    ui->output46->setChecked(false);
    ui->output47->setChecked(false);
    ui->output48->setChecked(false);
    ui->output49->setChecked(false);
    ui->output50->setChecked(false);
    ui->output51->setChecked(false);
    ui->output52->setChecked(false);
    ui->output53->setChecked(false);
    ui->output54->setChecked(false);
    ui->output55->setChecked(false);
    ui->output56->setChecked(false);
    ui->output57->setChecked(false);
    ui->output58->setChecked(false);
    ui->output59->setChecked(false);
    ui->output60->setChecked(false);
    ui->output61->setChecked(false);
    ui->output62->setChecked(false);

    showOutputsValue();
}

void PVKPWindow::slotOutput1toggled(bool toggled)
{
    qDebug() << __FUNCTION__ << toggled << "\n";
    // если пользователь не выключал и не включал все кнопки
    if (last_toggled_o1 != toggled)
    {
        qDebug() << "HURAH1" << "\n";
        last_toggled_o1 = toggled;
        //        if (toggled)
        //        {
        //            me->createIS2(0x01, cntrl_off);
        //        }
        //        else
        //        {
        //            me->createIS2(0x01, cntrl_on);
        //        }

    }

}

void PVKPWindow::slotOutput2toggled(bool toggled)
{
    qDebug() << __FUNCTION__ << toggled << "\n";
    if (last_toggled_o2 != toggled)
    {
        qDebug() << "HURAH2" << "\n";
        last_toggled_o2 = toggled;
        if (toggled)
        {
            me->createIS2(0x02, cntrl_off);
        }
        else
        {
            me->createIS2(0x02, cntrl_on);
        }
    }
}

void PVKPWindow::slotOutput3toggled(bool toggled)
{
    qDebug() << __FUNCTION__ << toggled;
    if (toggled)
    {
        me->createIS2(0x03, cntrl_off);
    }
    else
    {
        me->createIS2(0x03, cntrl_on);
    }
}

void PVKPWindow::slotOutput4toggled(bool toggled)
{
    qDebug() << __FUNCTION__ << toggled;
    if (toggled)
    {
        me->createIS2(0x04, cntrl_off);
    }
    else
    {
        me->createIS2(0x04, cntrl_on);
    }
}

void PVKPWindow::slotOutput5toggled(bool toggled)
{
    qDebug() << __FUNCTION__ << toggled;
    if (toggled)
    {
        me->createIS2(0x05, cntrl_off);
    }
    else
    {
        me->createIS2(0x05, cntrl_on);
    }
}

void PVKPWindow::slotOutput6toggled(bool toggled)
{
    qDebug() << __FUNCTION__ << toggled;
    if (toggled)
    {
        me->createIS2(0x06, cntrl_off);
    }
    else
    {
        me->createIS2(0x06, cntrl_on);
    }
}

void PVKPWindow::slotOutput7toggled(bool toggled)
{
    qDebug() << __FUNCTION__ << toggled;
    if (toggled)
    {
        me->createIS2(0x07, cntrl_off);
    }
    else
    {
        me->createIS2(0x07, cntrl_on);
    }
}

void PVKPWindow::slotOutput8toggled(bool toggled)
{
    qDebug() << __FUNCTION__ << toggled;
    if (toggled)
    {
        me->createIS2(0x08, cntrl_off);
    }
    else
    {
        me->createIS2(0x08, cntrl_on);
    }
}

void PVKPWindow::slotOutput9toggled(bool toggled)
{
    qDebug() << __FUNCTION__ << toggled;
    if (toggled)
    {
        me->createIS2(0x09, cntrl_off);
    }
    else
    {
        me->createIS2(0x09, cntrl_on);
    }
}

void PVKPWindow::slotOutput10toggled(bool toggled)
{
    qDebug() << __FUNCTION__ << toggled;
    if (toggled)
    {
        me->createIS2(0x0a, cntrl_off);
    }
    else
    {
        me->createIS2(0x0a, cntrl_on);
    }
}

void PVKPWindow::slotOutput11toggled(bool toggled)
{
    qDebug() << __FUNCTION__ << toggled;
    if (toggled)
    {
        me->createIS2(0x0b, cntrl_off);
    }
    else
    {
        me->createIS2(0x0b, cntrl_on);
    }
}

void PVKPWindow::slotOutput12toggled(bool toggled)
{
    qDebug() << __FUNCTION__ << toggled;
    if (toggled)
    {
        me->createIS2(0x0c, cntrl_off);
    }
    else
    {
        me->createIS2(0x0c, cntrl_on);
    }
}

void PVKPWindow::slotOutput13toggled(bool toggled)
{
    qDebug() << __FUNCTION__ << toggled;
    if (toggled)
    {
        me->createIS2(0x0d, cntrl_off);
    }
    else
    {
        me->createIS2(0x0d, cntrl_on);
    }
}

void PVKPWindow::slotOutput14toggled(bool toggled)
{
    qDebug() << __FUNCTION__ << toggled;
    if (toggled)
    {
        me->createIS2(0x0e, cntrl_off);
    }
    else
    {
        me->createIS2(0x0e, cntrl_on);
    }
}

void PVKPWindow::slotOutput15toggled(bool toggled)
{
    qDebug() << __FUNCTION__ << toggled;
    me->createIS2(0x0f, cntrl_off);
    if (toggled)
    {
        me->createIS2(0x01, cntrl_off);
    }
    else
    {
        me->createIS2(0x01, cntrl_on);
    }
}

void PVKPWindow::slotOutput16toggled(bool toggled)
{
    qDebug() << __FUNCTION__ << toggled;
    if (toggled)
    {
        me->createIS2(0x10, cntrl_off);
    }
    else
    {
        me->createIS2(0x10, cntrl_on);
    }
}

void PVKPWindow::slotOutput17toggled(bool toggled)
{
    qDebug() << __FUNCTION__ << toggled;
    if (toggled)
    {
        me->createIS2(0x11, cntrl_off);
    }
    else
    {
        me->createIS2(0x11, cntrl_on);
    }
}

void PVKPWindow::slotOutput18toggled(bool toggled)
{
    qDebug() << __FUNCTION__ << toggled;
    if (toggled)
    {
        me->createIS2(0x12, cntrl_off);
    }
    else
    {
        me->createIS2(0x12, cntrl_on);
    }
}

void PVKPWindow::slotOutput19toggled(bool toggled)
{
    qDebug() << __FUNCTION__ << toggled;
    if (toggled)
    {
        me->createIS2(0x13, cntrl_off);
    }
    else
    {
        me->createIS2(0x13, cntrl_on);
    }
}

void PVKPWindow::slotOutput20toggled(bool toggled)
{
    qDebug() << __FUNCTION__ << toggled;
    if (toggled)
    {
        me->createIS2(0x14, cntrl_off);
    }
    else
    {
        me->createIS2(0x14, cntrl_on);
    }
}

void PVKPWindow::slotOutput21toggled(bool toggled)
{
    qDebug() << __FUNCTION__ << toggled;
    if (toggled)
    {
        me->createIS2(0x15, cntrl_off);
    }
    else
    {
        me->createIS2(0x15, cntrl_on);
    }
}

void PVKPWindow::slotOutput22toggled(bool toggled)
{
    qDebug() << __FUNCTION__ << toggled;
    if (toggled)
    {
        me->createIS2(0x16, cntrl_off);
    }
    else
    {
        me->createIS2(0x16, cntrl_on);
    }
}

void PVKPWindow::slotOutput23toggled(bool toggled)
{
    qDebug() << __FUNCTION__ << toggled;
    if (toggled)
    {
        me->createIS2(0x17, cntrl_off);
    }
    else
    {
        me->createIS2(0x17, cntrl_on);
    }
}

void PVKPWindow::slotOutput24toggled(bool toggled)
{
    qDebug() << __FUNCTION__ << toggled;
    if (toggled)
    {
        me->createIS2(0x18, cntrl_off);
    }
    else
    {
        me->createIS2(0x18, cntrl_on);
    }
}

void PVKPWindow::slotOutput25toggled(bool toggled)
{
    qDebug() << __FUNCTION__ << toggled;
    if (toggled)
    {
        me->createIS2(0x19, cntrl_off);
    }
    else
    {
        me->createIS2(0x19, cntrl_on);
    }
}

void PVKPWindow::slotOutput26toggled(bool toggled)
{
    qDebug() << __FUNCTION__ << toggled;
    if (toggled)
    {
        me->createIS2(0x1a, cntrl_off);
    }
    else
    {
        me->createIS2(0x1a, cntrl_on);
    }
}

void PVKPWindow::slotOutput27toggled(bool toggled)
{
    qDebug() << __FUNCTION__ << toggled;
    if (toggled)
    {
        me->createIS2(0x1b, cntrl_off);
    }
    else
    {
        me->createIS2(0x1b, cntrl_on);
    }
}

void PVKPWindow::slotOutput28toggled(bool toggled)
{
    qDebug() << __FUNCTION__ << toggled;
    if (toggled)
    {
        me->createIS2(0x1c, cntrl_off);
    }
    else
    {
        me->createIS2(0x1c, cntrl_on);
    }
}

void PVKPWindow::slotOutput29toggled(bool toggled)
{
    qDebug() << __FUNCTION__ << toggled;
    if (toggled)
    {
        me->createIS2(0x1d, cntrl_off);
    }
    else
    {
        me->createIS2(0x1d, cntrl_on);
    }
}

void PVKPWindow::slotOutput30toggled(bool toggled)
{
    qDebug() << __FUNCTION__ << toggled;
    if (toggled)
    {
        me->createIS2(0x1e, cntrl_off);
    }
    else
    {
        me->createIS2(0x1e, cntrl_on);
    }
}

void PVKPWindow::slotOutput31toggled(bool toggled)
{
    qDebug() << __FUNCTION__ << toggled;
    if (toggled)
    {
        me->createIS2(0x1f, cntrl_off);
    }
    else
    {
        me->createIS2(0x1f, cntrl_on);
    };
}

void PVKPWindow::slotOutput32toggled(bool toggled)
{
    qDebug() << __FUNCTION__ << toggled;
    if (toggled)
    {
        me->createIS2(0x20, cntrl_off);
    }
    else
    {
        me->createIS2(0x20, cntrl_on);
    }
}

void PVKPWindow::slotOutput33toggled(bool toggled)
{
    qDebug() << __FUNCTION__ << toggled;
    if (toggled)
    {
        me->createIS2(0x21, cntrl_off);
    }
    else
    {
        me->createIS2(0x21, cntrl_on);
    }
}

void PVKPWindow::slotOutput34toggled(bool toggled)
{
    qDebug() << __FUNCTION__ << toggled;
    if (toggled)
    {
        me->createIS2(0x22, cntrl_off);
    }
    else
    {
        me->createIS2(0x22, cntrl_on);
    }
}

void PVKPWindow::slotOutput35toggled(bool toggled)
{
    qDebug() << __FUNCTION__ << toggled;
    if (toggled)
    {
        me->createIS2(0x23, cntrl_off);
    }
    else
    {
        me->createIS2(0x23, cntrl_on);
    }
}

void PVKPWindow::slotOutput36toggled(bool toggled)
{
    qDebug() << __FUNCTION__ << toggled;
    if (toggled)
    {
        me->createIS2(0x24, cntrl_off);
    }
    else
    {
        me->createIS2(0x24, cntrl_on);
    }
}

void PVKPWindow::slotOutput37toggled(bool toggled)
{
    qDebug() << __FUNCTION__ << toggled;
    if (toggled)
    {
        me->createIS2(0x25, cntrl_off);
    }
    else
    {
        me->createIS2(0x25, cntrl_on);
    }
}

void PVKPWindow::slotOutput38toggled(bool toggled)
{
    qDebug() << __FUNCTION__ << toggled;
    if (toggled)
    {
        me->createIS2(0x26, cntrl_off);
    }
    else
    {
        me->createIS2(0x26, cntrl_on);
    }
}

void PVKPWindow::slotOutput39toggled(bool toggled)
{
    qDebug() << __FUNCTION__ << toggled;
    if (toggled)
    {
        me->createIS2(0x27, cntrl_off);
    }
    else
    {
        me->createIS2(0x27, cntrl_on);
    }
}

void PVKPWindow::slotOutput40toggled(bool toggled)
{
    qDebug() << __FUNCTION__ << toggled;
    if (toggled)
    {
        me->createIS2(0x28, cntrl_off);
    }
    else
    {
        me->createIS2(0x28, cntrl_on);
    }
}

void PVKPWindow::slotOutput41toggled(bool toggled)
{
    qDebug() << __FUNCTION__ << toggled;
    if (toggled)
    {
        me->createIS2(0x29, cntrl_off);
    }
    else
    {
        me->createIS2(0x29, cntrl_on);
    }
}

void PVKPWindow::slotOutput42toggled(bool toggled)
{
    qDebug() << __FUNCTION__ << toggled;
    if (toggled)
    {
        me->createIS2(0x2a, cntrl_off);
    }
    else
    {
        me->createIS2(0x2a, cntrl_on);
    }
}

void PVKPWindow::slotOutput43toggled(bool toggled)
{
    qDebug() << __FUNCTION__ << toggled;
    if (toggled)
    {
        me->createIS2(0x2b, cntrl_off);
    }
    else
    {
        me->createIS2(0x2b, cntrl_on);
    }
}

void PVKPWindow::slotOutput44toggled(bool toggled)
{
    qDebug() << __FUNCTION__ << toggled;
    if (toggled)
    {
        me->createIS2(0x2c, cntrl_off);
    }
    else
    {
        me->createIS2(0x2c, cntrl_on);
    }
}

void PVKPWindow::slotOutput45toggled(bool toggled)
{
    qDebug() << __FUNCTION__ << toggled;
    if (toggled)
    {
        me->createIS2(0x2d, cntrl_off);
    }
    else
    {
        me->createIS2(0x2d, cntrl_on);
    }
}

void PVKPWindow::slotOutput46toggled(bool toggled)
{
    qDebug() << __FUNCTION__ << toggled;
    if (toggled)
    {
        me->createIS2(0x2e, cntrl_off);
    }
    else
    {
        me->createIS2(0x2e, cntrl_on);
    }
}

void PVKPWindow::slotOutput47toggled(bool toggled)
{
    qDebug() << __FUNCTION__ << toggled;
    if (toggled)
    {
        me->createIS2(0x2f, cntrl_off);
    }
    else
    {
        me->createIS2(0x2f, cntrl_on);
    }
}

void PVKPWindow::slotOutput48toggled(bool toggled)
{
    qDebug() << __FUNCTION__ << toggled;
    if (toggled)
    {
        me->createIS2(0x30, cntrl_off);
    }
    else
    {
        me->createIS2(0x30, cntrl_on);
    }
}

void PVKPWindow::slotOutput49toggled(bool toggled)
{
    qDebug() << __FUNCTION__ << toggled;
    if (toggled)
    {
        me->createIS2(0x31, cntrl_off);
    }
    else
    {
        me->createIS2(0x31, cntrl_on);
    }
}

void PVKPWindow::slotOutput50toggled(bool toggled)
{
    qDebug() << __FUNCTION__ << toggled;
    if (toggled)
    {
        me->createIS2(0x32, cntrl_off);
    }
    else
    {
        me->createIS2(0x32, cntrl_on);
    }
}

void PVKPWindow::slotOutput51toggled(bool toggled)
{
    qDebug() << __FUNCTION__ << toggled;
    if (toggled)
    {
        me->createIS2(0x33, cntrl_off);
    }
    else
    {
        me->createIS2(0x33, cntrl_on);
    }
}

void PVKPWindow::slotOutput52toggled(bool toggled)
{
    qDebug() << __FUNCTION__ << toggled;
    if (toggled)
    {
        me->createIS2(0x34, cntrl_off);
    }
    else
    {
        me->createIS2(0x34, cntrl_on);
    }
}

void PVKPWindow::slotOutput53toggled(bool toggled)
{
    qDebug() << __FUNCTION__ << toggled;
    if (toggled)
    {
        me->createIS2(0x35, cntrl_off);
    }
    else
    {
        me->createIS2(0x35, cntrl_on);
    }
}

void PVKPWindow::slotOutput54toggled(bool toggled)
{
    qDebug() << __FUNCTION__ << toggled;
    if (toggled)
    {
        me->createIS2(0x36, cntrl_off);
    }
    else
    {
        me->createIS2(0x36, cntrl_on);
    }
}

void PVKPWindow::slotOutput55toggled(bool toggled)
{
    qDebug() << __FUNCTION__ << toggled;
    if (toggled)
    {
        me->createIS2(0x37, cntrl_off);
    }
    else
    {
        me->createIS2(0x37, cntrl_on);
    }
}

void PVKPWindow::slotOutput56toggled(bool toggled)
{
    qDebug() << __FUNCTION__ << toggled;
    if (toggled)
    {
        me->createIS2(0x38, cntrl_off);
    }
    else
    {
        me->createIS2(0x38, cntrl_on);
    }
}

void PVKPWindow::slotOutput57toggled(bool toggled)
{
    qDebug() << __FUNCTION__ << toggled;
    if (toggled)
    {
        me->createIS2(0x39, cntrl_off);
    }
    else
    {
        me->createIS2(0x39, cntrl_on);
    }
}

void PVKPWindow::slotOutput58toggled(bool toggled)
{
    qDebug() << __FUNCTION__ << toggled;
    if (toggled)
    {
        me->createIS2(0x3a, cntrl_off);
    }
    else
    {
        me->createIS2(0x3a, cntrl_on);
    }
}

void PVKPWindow::slotOutput59toggled(bool toggled)
{
    qDebug() << __FUNCTION__ << toggled;
    if (toggled)
    {
        me->createIS2(0x3b, cntrl_off);
    }
    else
    {
        me->createIS2(0x3b, cntrl_on);
    }
}

void PVKPWindow::slotOutput60toggled(bool toggled)
{
    qDebug() << __FUNCTION__ << toggled;
    if (toggled)
    {
        me->createIS2(0x3c, cntrl_off);
    }
    else
    {
        me->createIS2(0x3c, cntrl_on);
    }
}

void PVKPWindow::slotOutput61toggled(bool toggled)
{
    qDebug() << __FUNCTION__ << toggled;
    if (toggled)
    {
        me->createIS2(0x3d, cntrl_off);
    }
    else
    {
        me->createIS2(0x3d, cntrl_on);
    }
}

void PVKPWindow::slotOutput62toggled(bool toggled)
{
    qDebug() << __FUNCTION__ << toggled;
    if (toggled)
    {
        me->createIS2(output62, cntrl_off);
    }
    else
    {
        me->createIS2(output62, cntrl_on);
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
    setOutputColor(me->getOutputState(output1), ui->output1);
    setOutputColor(me->getOutputState(output2), ui->output2);
    setOutputColor(me->getOutputState(output3), ui->output3);
    setOutputColor(me->getOutputState(output4), ui->output4);

    setOutputColor(me->getOutputState(output5), ui->output5);
    setOutputColor(me->getOutputState(output6), ui->output6);
    setOutputColor(me->getOutputState(output7), ui->output7);
    setOutputColor(me->getOutputState(output8), ui->output8);

    setOutputColor(me->getOutputState(output9), ui->output9);
    setOutputColor(me->getOutputState(output10), ui->output10);
    setOutputColor(me->getOutputState(output11), ui->output11);
    setOutputColor(me->getOutputState(output12), ui->output12);

    setOutputColor(me->getOutputState(output13), ui->output13);
    setOutputColor(me->getOutputState(output14), ui->output14);
    setOutputColor(me->getOutputState(output15), ui->output15);
    setOutputColor(me->getOutputState(output16), ui->output16);

    setOutputColor(me->getOutputState(output17), ui->output17);
    setOutputColor(me->getOutputState(output18), ui->output18);
    setOutputColor(me->getOutputState(output19), ui->output19);
    setOutputColor(me->getOutputState(output20), ui->output20);

    setOutputColor(me->getOutputState(output21), ui->output21);
    setOutputColor(me->getOutputState(output22), ui->output22);
    setOutputColor(me->getOutputState(output23), ui->output23);
    setOutputColor(me->getOutputState(output24), ui->output24);

    setOutputColor(me->getOutputState(output25), ui->output25);
    setOutputColor(me->getOutputState(output26), ui->output26);
    setOutputColor(me->getOutputState(output27), ui->output27);
    setOutputColor(me->getOutputState(output28), ui->output28);

    setOutputColor(me->getOutputState(output29), ui->output29);
    setOutputColor(me->getOutputState(output30), ui->output30);
    setOutputColor(me->getOutputState(output31), ui->output31);
    setOutputColor(me->getOutputState(output32), ui->output32);

    setOutputColor(me->getOutputState(output33), ui->output33);
    setOutputColor(me->getOutputState(output34), ui->output34);
    setOutputColor(me->getOutputState(output35), ui->output35);
    setOutputColor(me->getOutputState(output36), ui->output36);

    setOutputColor(me->getOutputState(output37), ui->output37);
    setOutputColor(me->getOutputState(output38), ui->output38);
    setOutputColor(me->getOutputState(output39), ui->output39);
    setOutputColor(me->getOutputState(output40), ui->output40);

    setOutputColor(me->getOutputState(output41), ui->output41);
    setOutputColor(me->getOutputState(output42), ui->output42);
    setOutputColor(me->getOutputState(output43), ui->output43);
    setOutputColor(me->getOutputState(output44), ui->output44);

    setOutputColor(me->getOutputState(output45), ui->output45);
    setOutputColor(me->getOutputState(output46), ui->output46);
    setOutputColor(me->getOutputState(output47), ui->output47);
    setOutputColor(me->getOutputState(output48), ui->output48);

    setOutputColor(me->getOutputState(output49), ui->output49);
    setOutputColor(me->getOutputState(output50), ui->output50);
    setOutputColor(me->getOutputState(output51), ui->output51);
    setOutputColor(me->getOutputState(output52), ui->output52);

    setOutputColor(me->getOutputState(output53), ui->output53);
    setOutputColor(me->getOutputState(output54), ui->output54);
    setOutputColor(me->getOutputState(output55), ui->output55);
    setOutputColor(me->getOutputState(output56), ui->output56);

    setOutputColor(me->getOutputState(output57), ui->output57);
    setOutputColor(me->getOutputState(output58), ui->output58);
    setOutputColor(me->getOutputState(output59), ui->output59);
    setOutputColor(me->getOutputState(output60), ui->output60);

    setOutputColor(me->getOutputState(output61), ui->output61);
    setOutputColor(me->getOutputState(output62), ui->output62);
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
