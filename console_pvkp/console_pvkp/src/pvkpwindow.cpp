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

    connect(ui->allOutputsOff, SIGNAL(pressed()), this, SLOT(slotAllOutputsOff()));
    connect(ui->allOutputsOn, SIGNAL(pressed()), this, SLOT(slotAllOutputsOn()));
    connect(ui->output1, SIGNAL(toggled(bool)), this, SLOT(slotOutput1toggled(bool)));
    connect(ui->output2, SIGNAL(toggled(bool)), this, SLOT(slotOutput2toggled(bool)));
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
    connect(ui->output62, SIGNAL(toggled(bool)), this, SLOT(slotOutput62toggled(bool)));

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
    me->startExchange();

    showInputsValue();
    showOutputValue();
}

void PVKPWindow::slotAllOutputsOff()
{
    qDebug() << __FUNCTION__;
    me->createIS2(all_outputs, cntrl_off);

    ui->output1->setChecked(true);
    ui->output2->setChecked(true);
    ui->output3->setChecked(true);
    ui->output4->setChecked(true);
    ui->output5->setChecked(true);
    ui->output6->setChecked(true);
    ui->output7->setChecked(true);
    ui->output8->setChecked(true);
    ui->output9->setChecked(true);
    ui->output10->setChecked(true);
    ui->output11->setChecked(true);
    ui->output12->setChecked(true);
    ui->output13->setChecked(true);
    ui->output14->setChecked(true);
    ui->output15->setChecked(true);
    ui->output16->setChecked(true);
    ui->output17->setChecked(true);
    ui->output18->setChecked(true);
    ui->output19->setChecked(true);
    ui->output20->setChecked(true);
    ui->output21->setChecked(true);
    ui->output22->setChecked(true);
    ui->output23->setChecked(true);
    ui->output24->setChecked(true);
    ui->output25->setChecked(true);
    ui->output26->setChecked(true);
    ui->output27->setChecked(true);
    ui->output28->setChecked(true);
    ui->output29->setChecked(true);
    ui->output30->setChecked(true);
    ui->output31->setChecked(true);
    ui->output32->setChecked(true);
    ui->output33->setChecked(true);
    ui->output34->setChecked(true);
    ui->output35->setChecked(true);
    ui->output36->setChecked(true);
    ui->output37->setChecked(true);
    ui->output38->setChecked(true);
    ui->output39->setChecked(true);
    ui->output40->setChecked(true);
    ui->output41->setChecked(true);
    ui->output42->setChecked(true);
    ui->output43->setChecked(true);
    ui->output44->setChecked(true);
    ui->output45->setChecked(true);
    ui->output46->setChecked(true);
    ui->output47->setChecked(true);
    ui->output48->setChecked(true);
    ui->output49->setChecked(true);
    ui->output50->setChecked(true);
    ui->output51->setChecked(true);
    ui->output52->setChecked(true);
    ui->output53->setChecked(true);
    ui->output54->setChecked(true);
    ui->output55->setChecked(true);
    ui->output56->setChecked(true);
    ui->output57->setChecked(true);
    ui->output58->setChecked(true);
    ui->output59->setChecked(true);
    ui->output60->setChecked(true);
    ui->output61->setChecked(true);
    ui->output62->setChecked(true);

    showOutputValue();
}

void PVKPWindow::slotAllOutputsOn()
{
    qDebug() << __FUNCTION__;
    me->createIS2(all_outputs, cntrl_on);

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

    showOutputValue();
}

void PVKPWindow::slotOutput1toggled(bool toggled)
{
    qDebug() << "toggled" << toggled <<  ui->output1->isChecked();
    if (toggled)
    {
        me->createIS2(0x01, cntrl_off);
    }
    else
    {
        me->createIS2(0x01, cntrl_on);
    }
}

void PVKPWindow::slotOutput2toggled(bool toggled)
{
    qDebug() << __FUNCTION__;
    if (toggled)
    {
        me->createIS2(0x02, cntrl_off);
    }
    else
    {
        me->createIS2(0x02, cntrl_on);
    }
}

void PVKPWindow::slotOutput3toggled(bool toggled)
{
    qDebug() << __FUNCTION__;
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
    qDebug() << __FUNCTION__;
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
    qDebug() << __FUNCTION__;
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
    qDebug() << __FUNCTION__;
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
    qDebug() << __FUNCTION__;
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
    qDebug() << __FUNCTION__;
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
    qDebug() << __FUNCTION__;
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
    qDebug() << __FUNCTION__;
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
    qDebug() << __FUNCTION__;
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
    qDebug() << __FUNCTION__;
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
    qDebug() << __FUNCTION__;
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
    qDebug() << __FUNCTION__;
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
    qDebug() << __FUNCTION__;
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
    qDebug() << __FUNCTION__;
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
    qDebug() << __FUNCTION__;
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
    qDebug() << __FUNCTION__;
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
    qDebug() << __FUNCTION__;
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
    qDebug() << __FUNCTION__;
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
    qDebug() << __FUNCTION__;
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
    qDebug() << __FUNCTION__;
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
    qDebug() << __FUNCTION__;
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
    qDebug() << __FUNCTION__;
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
    qDebug() << __FUNCTION__;
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
    qDebug() << __FUNCTION__;
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
    qDebug() << __FUNCTION__;
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
    qDebug() << __FUNCTION__;
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
    qDebug() << __FUNCTION__;
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
    qDebug() << __FUNCTION__;
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
    qDebug() << __FUNCTION__;
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
    qDebug() << __FUNCTION__;
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
    qDebug() << __FUNCTION__;
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
    qDebug() << __FUNCTION__;
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
    qDebug() << __FUNCTION__;
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
    qDebug() << __FUNCTION__;
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
    qDebug() << __FUNCTION__;
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
    qDebug() << __FUNCTION__;
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
    qDebug() << __FUNCTION__;
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
    qDebug() << __FUNCTION__;
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
    qDebug() << __FUNCTION__;
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
    qDebug() << __FUNCTION__;
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
    qDebug() << __FUNCTION__;
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
    qDebug() << __FUNCTION__;
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
    qDebug() << __FUNCTION__;
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
    qDebug() << __FUNCTION__;
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
    qDebug() << __FUNCTION__;
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
    qDebug() << __FUNCTION__;
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
    qDebug() << __FUNCTION__;
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
    qDebug() << __FUNCTION__;
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
    qDebug() << __FUNCTION__;
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
    qDebug() << __FUNCTION__;
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
    qDebug() << __FUNCTION__;
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
    qDebug() << __FUNCTION__;
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
    qDebug() << __FUNCTION__;
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
    qDebug() << __FUNCTION__;
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
    qDebug() << __FUNCTION__;
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
    qDebug() << __FUNCTION__;
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
    qDebug() << __FUNCTION__;
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
    qDebug() << __FUNCTION__;
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
    qDebug() << __FUNCTION__;
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
    qDebug() << __FUNCTION__;
    if (toggled)
    {
        me->createIS2(0x3e, cntrl_off);
        outputs.setOutput62(output_off);
        showOutputValue();
    }
    else
    {
        me->createIS2(0x3e, cntrl_on);
        outputs.setOutput62(output_on);
        showOutputValue();
    }
}

void PVKPWindow::showInputsValue()
{
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
