#include "hdr/busepwindow.h"
#include "ui_busepwindow.h"

BusepWindow::BusepWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BusepWindow)
{
    ui->setupUi(this);
    createPalette();

    for (int i = 0; i < output_size; i++)
    {
        last_pressed_i[i] = false;
    }

    connect(ui->allInputsOnOff, SIGNAL(toggled(bool)), this, SLOT(slotAllInputsOnOff(bool)));

    connect(ui->input1, SIGNAL(clicked(bool)), this, SLOT(slotInput1clicked(bool)));
    connect(ui->input2, SIGNAL(clicked(bool)), this, SLOT(slotInput2clicked(bool)));
    connect(ui->input3, SIGNAL(clicked(bool)), this, SLOT(slotInput3clicked(bool)));
    connect(ui->input4, SIGNAL(clicked(bool)), this, SLOT(slotInput4clicked(bool)));
    connect(ui->input5, SIGNAL(clicked(bool)), this, SLOT(slotInput5clicked(bool)));
    connect(ui->input6, SIGNAL(clicked(bool)), this, SLOT(slotInput6clicked(bool)));
    connect(ui->input7, SIGNAL(clicked(bool)), this, SLOT(slotInput7clicked(bool)));
    connect(ui->input8, SIGNAL(clicked(bool)), this, SLOT(slotInput8clicked(bool)));
    connect(ui->input9, SIGNAL(clicked(bool)), this, SLOT(slotInput9clicked(bool)));

    connect(ui->input10, SIGNAL(clicked(bool)), this, SLOT(slotInput10clicked(bool)));
    connect(ui->input11, SIGNAL(clicked(bool)), this, SLOT(slotInput11clicked(bool)));
    connect(ui->input12, SIGNAL(clicked(bool)), this, SLOT(slotInput12clicked(bool)));
    connect(ui->input13, SIGNAL(clicked(bool)), this, SLOT(slotInput13clicked(bool)));
    connect(ui->input14, SIGNAL(clicked(bool)), this, SLOT(slotInput14clicked(bool)));
    connect(ui->input15, SIGNAL(clicked(bool)), this, SLOT(slotInput15clicked(bool)));
    connect(ui->input16, SIGNAL(clicked(bool)), this, SLOT(slotInput16clicked(bool)));
    connect(ui->input17, SIGNAL(clicked(bool)), this, SLOT(slotInput17clicked(bool)));
    connect(ui->input18, SIGNAL(clicked(bool)), this, SLOT(slotInput18clicked(bool)));
    connect(ui->input19, SIGNAL(clicked(bool)), this, SLOT(slotInput19clicked(bool)));

    connect(ui->input20, SIGNAL(clicked(bool)), this, SLOT(slotInput20clicked(bool)));
    connect(ui->input21, SIGNAL(clicked(bool)), this, SLOT(slotInput21clicked(bool)));
    connect(ui->input22, SIGNAL(clicked(bool)), this, SLOT(slotInput22clicked(bool)));
    connect(ui->input23, SIGNAL(clicked(bool)), this, SLOT(slotInput23clicked(bool)));
    connect(ui->input24, SIGNAL(clicked(bool)), this, SLOT(slotInput24clicked(bool)));
    connect(ui->input25, SIGNAL(clicked(bool)), this, SLOT(slotInput25clicked(bool)));
    connect(ui->input26, SIGNAL(clicked(bool)), this, SLOT(slotInput26clicked(bool)));
    connect(ui->input27, SIGNAL(clicked(bool)), this, SLOT(slotInput27clicked(bool)));
    connect(ui->input28, SIGNAL(clicked(bool)), this, SLOT(slotInput28clicked(bool)));
    connect(ui->input29, SIGNAL(clicked(bool)), this, SLOT(slotInput29clicked(bool)));

    connect(ui->input30, SIGNAL(clicked(bool)), this, SLOT(slotInput30clicked(bool)));
    connect(ui->input31, SIGNAL(clicked(bool)), this, SLOT(slotInput31clicked(bool)));
    connect(ui->input32, SIGNAL(clicked(bool)), this, SLOT(slotInput32clicked(bool)));
    connect(ui->input33, SIGNAL(clicked(bool)), this, SLOT(slotInput33clicked(bool)));
    connect(ui->input34, SIGNAL(clicked(bool)), this, SLOT(slotInput34clicked(bool)));
    connect(ui->input35, SIGNAL(clicked(bool)), this, SLOT(slotInput35clicked(bool)));
    connect(ui->input36, SIGNAL(clicked(bool)), this, SLOT(slotInput36clicked(bool)));
    connect(ui->input37, SIGNAL(clicked(bool)), this, SLOT(slotInput37clicked(bool)));
    connect(ui->input38, SIGNAL(clicked(bool)), this, SLOT(slotInput38clicked(bool)));
    connect(ui->input39, SIGNAL(clicked(bool)), this, SLOT(slotInput39clicked(bool)));

    connect(ui->input40, SIGNAL(clicked(bool)), this, SLOT(slotInput40clicked(bool)));
    connect(ui->input41, SIGNAL(clicked(bool)), this, SLOT(slotInput41clicked(bool)));
    connect(ui->input42, SIGNAL(clicked(bool)), this, SLOT(slotInput42clicked(bool)));
    connect(ui->input43, SIGNAL(clicked(bool)), this, SLOT(slotInput43clicked(bool)));
    connect(ui->input44, SIGNAL(clicked(bool)), this, SLOT(slotInput44clicked(bool)));
    connect(ui->input45, SIGNAL(clicked(bool)), this, SLOT(slotInput45clicked(bool)));
    connect(ui->input46, SIGNAL(clicked(bool)), this, SLOT(slotInput46clicked(bool)));
    connect(ui->input47, SIGNAL(clicked(bool)), this, SLOT(slotInput47clicked(bool)));
    connect(ui->input48, SIGNAL(clicked(bool)), this, SLOT(slotInput48clicked(bool)));
    connect(ui->input49, SIGNAL(clicked(bool)), this, SLOT(slotInput49clicked(bool)));

    connect(ui->input50, SIGNAL(clicked(bool)), this, SLOT(slotInput50clicked(bool)));
    connect(ui->input51, SIGNAL(clicked(bool)), this, SLOT(slotInput51clicked(bool)));
    connect(ui->input52, SIGNAL(clicked(bool)), this, SLOT(slotInput52clicked(bool)));
    connect(ui->input53, SIGNAL(clicked(bool)), this, SLOT(slotInput53clicked(bool)));
    connect(ui->input54, SIGNAL(clicked(bool)), this, SLOT(slotInput54clicked(bool)));
    connect(ui->input55, SIGNAL(clicked(bool)), this, SLOT(slotInput55clicked(bool)));
    connect(ui->input56, SIGNAL(clicked(bool)), this, SLOT(slotInput56clicked(bool)));
    connect(ui->input57, SIGNAL(clicked(bool)), this, SLOT(slotInput57clicked(bool)));
    connect(ui->input58, SIGNAL(clicked(bool)), this, SLOT(slotInput58clicked(bool)));
    connect(ui->input59, SIGNAL(clicked(bool)), this, SLOT(slotInput59clicked(bool)));

    connect(ui->input60, SIGNAL(clicked(bool)), this, SLOT(slotInput60clicked(bool)));
    connect(ui->input61, SIGNAL(clicked(bool)), this, SLOT(slotInput61clicked(bool)));
    connect(ui->input62, SIGNAL(clicked(bool)), this, SLOT(slotInput62clicked(bool)));
    connect(ui->input63, SIGNAL(clicked(bool)), this, SLOT(slotInput63clicked(bool)));
    connect(ui->input64, SIGNAL(clicked(bool)), this, SLOT(slotInput64clicked(bool)));
    connect(ui->input65, SIGNAL(clicked(bool)), this, SLOT(slotInput65clicked(bool)));
    connect(ui->input66, SIGNAL(clicked(bool)), this, SLOT(slotInput66clicked(bool)));
    connect(ui->input67, SIGNAL(clicked(bool)), this, SLOT(slotInput67clicked(bool)));
    connect(ui->input68, SIGNAL(clicked(bool)), this, SLOT(slotInput68clicked(bool)));
    connect(ui->input69, SIGNAL(clicked(bool)), this, SLOT(slotInput69clicked(bool)));
    connect(ui->input60, SIGNAL(clicked(bool)), this, SLOT(slotInput70clicked(bool)));

    connect(ui->input71, SIGNAL(clicked(bool)), this, SLOT(slotInput71clicked(bool)));
    connect(ui->input72, SIGNAL(clicked(bool)), this, SLOT(slotInput72clicked(bool)));
    connect(ui->input73, SIGNAL(clicked(bool)), this, SLOT(slotInput73clicked(bool)));
    connect(ui->input74, SIGNAL(clicked(bool)), this, SLOT(slotInput74clicked(bool)));
    connect(ui->input75, SIGNAL(clicked(bool)), this, SLOT(slotInput75clicked(bool)));
    connect(ui->input76, SIGNAL(clicked(bool)), this, SLOT(slotInput76clicked(bool)));
    connect(ui->input77, SIGNAL(clicked(bool)), this, SLOT(slotInput77clicked(bool)));
    connect(ui->input78, SIGNAL(clicked(bool)), this, SLOT(slotInput78clicked(bool)));
    connect(ui->input79, SIGNAL(clicked(bool)), this, SLOT(slotInput79clicked(bool)));

    connect(ui->input80, SIGNAL(clicked(bool)), this, SLOT(slotInput80clicked(bool)));
    connect(ui->input81, SIGNAL(clicked(bool)), this, SLOT(slotInput81clicked(bool)));
    connect(ui->input82, SIGNAL(clicked(bool)), this, SLOT(slotInput82clicked(bool)));
    connect(ui->input83, SIGNAL(clicked(bool)), this, SLOT(slotInput83clicked(bool)));
    connect(ui->input84, SIGNAL(clicked(bool)), this, SLOT(slotInput84clicked(bool)));
    connect(ui->input85, SIGNAL(clicked(bool)), this, SLOT(slotInput85clicked(bool)));
    connect(ui->input86, SIGNAL(clicked(bool)), this, SLOT(slotInput86clicked(bool)));
    connect(ui->input87, SIGNAL(clicked(bool)), this, SLOT(slotInput87clicked(bool)));
    connect(ui->input88, SIGNAL(clicked(bool)), this, SLOT(slotInput88clicked(bool)));
    connect(ui->input89, SIGNAL(clicked(bool)), this, SLOT(slotInput89clicked(bool)));

    connect(ui->input90, SIGNAL(clicked(bool)), this, SLOT(slotInput90clicked(bool)));
    connect(ui->input91, SIGNAL(clicked(bool)), this, SLOT(slotInput91clicked(bool)));
    connect(ui->input92, SIGNAL(clicked(bool)), this, SLOT(slotInput92clicked(bool)));
    connect(ui->input93, SIGNAL(clicked(bool)), this, SLOT(slotInput93clicked(bool)));
    connect(ui->input94, SIGNAL(clicked(bool)), this, SLOT(slotInput94clicked(bool)));
    connect(ui->input95, SIGNAL(clicked(bool)), this, SLOT(slotInput95clicked(bool)));
    connect(ui->input96, SIGNAL(clicked(bool)), this, SLOT(slotInput96clicked(bool)));
    connect(ui->input97, SIGNAL(clicked(bool)), this, SLOT(slotInput97clicked(bool)));
    connect(ui->input98, SIGNAL(clicked(bool)), this, SLOT(slotInput98clicked(bool)));
    connect(ui->input99, SIGNAL(clicked(bool)), this, SLOT(slotInput99clicked(bool)));

    connect(ui->input100, SIGNAL(clicked(bool)), this, SLOT(slotInput100clicked(bool)));
    connect(ui->input101, SIGNAL(clicked(bool)), this, SLOT(slotInput101clicked(bool)));
    connect(ui->input102, SIGNAL(clicked(bool)), this, SLOT(slotInput102clicked(bool)));
    connect(ui->input103, SIGNAL(clicked(bool)), this, SLOT(slotInput103clicked(bool)));
    connect(ui->input104, SIGNAL(clicked(bool)), this, SLOT(slotInput104clicked(bool)));
    connect(ui->input105, SIGNAL(clicked(bool)), this, SLOT(slotInput105clicked(bool)));
    connect(ui->input106, SIGNAL(clicked(bool)), this, SLOT(slotInput106clicked(bool)));
    connect(ui->input107, SIGNAL(clicked(bool)), this, SLOT(slotInput107clicked(bool)));
    connect(ui->input108, SIGNAL(clicked(bool)), this, SLOT(slotInput108clicked(bool)));
    connect(ui->input109, SIGNAL(clicked(bool)), this, SLOT(slotInput109clicked(bool)));

    connect(ui->input110, SIGNAL(clicked(bool)), this, SLOT(slotInput110clicked(bool)));
    connect(ui->input111, SIGNAL(clicked(bool)), this, SLOT(slotInput111clicked(bool)));
    connect(ui->input112, SIGNAL(clicked(bool)), this, SLOT(slotInput112clicked(bool)));
    connect(ui->input113, SIGNAL(clicked(bool)), this, SLOT(slotInput113clicked(bool)));
    connect(ui->input114, SIGNAL(clicked(bool)), this, SLOT(slotInput114clicked(bool)));
    connect(ui->input115, SIGNAL(clicked(bool)), this, SLOT(slotInput115clicked(bool)));
    connect(ui->input116, SIGNAL(clicked(bool)), this, SLOT(slotInput116clicked(bool)));
    connect(ui->input117, SIGNAL(clicked(bool)), this, SLOT(slotInput117clicked(bool)));
    connect(ui->input118, SIGNAL(clicked(bool)), this, SLOT(slotInput118clicked(bool)));
    connect(ui->input119, SIGNAL(clicked(bool)), this, SLOT(slotInput119clicked(bool)));

    connect(ui->input120, SIGNAL(clicked(bool)), this, SLOT(slotInput120clicked(bool)));
    connect(ui->input121, SIGNAL(clicked(bool)), this, SLOT(slotInput121clicked(bool)));
    connect(ui->input122, SIGNAL(clicked(bool)), this, SLOT(slotInput122clicked(bool)));
    connect(ui->input123, SIGNAL(clicked(bool)), this, SLOT(slotInput123clicked(bool)));
    connect(ui->input124, SIGNAL(clicked(bool)), this, SLOT(slotInput124clicked(bool)));

    dm = new DummyMessages();


    // вариант с конфигурационным файлом
    if (readConfigFile())
    {
        connect(ui->listSerialPorts, SIGNAL(currentIndexChanged(int)), this, SLOT(slotPortChecked(int)));
        ui->statusbar->showMessage("Hello, my dear Daria!");

        // вроде бы БУСЕП шлет сообщения с частотой 50 мс
        timer = new QTimer(this);
        connect(timer, SIGNAL (timeout()), this, SLOT(slotStartExchangeByTimer()));
        timer->start(50);

        connect(dm, SIGNAL(signalUsualExchange()), this, SLOT(slotUsualExchange()));
        connect(dm, SIGNAL(signalSendIS5()), this, SLOT(slotSendIS5()));

        ui->listSerialPorts->setCurrentIndex(0);
        slotPortChecked(0);
    }
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

void BusepWindow::slotPortChecked(int port_index)
{
    if (dm->openSerialPort(ui->listSerialPorts->itemText(port_index), ui->baud_rate->text().toInt()))
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

void BusepWindow::slotAllInputsOnOff(bool toggled)
{
    for (int i = 0; i < input_size; i++)
    {
        last_pressed_i[i] = toggled;
    }

    if (toggled)
    {
        ui->allInputsOnOff->setText("Выключить все");
        dm->createIS3(all_inputs, is_signal_27v);
    }
    else
    {
        ui->allInputsOnOff->setText("Включить все");
        dm->createIS3(all_inputs, no_signal_27v);
    }

    ui->input1->clicked(true); ui->input2->clicked(true);
    ui->input3->clicked(true); ui->input4->clicked(true);
    ui->input5->clicked(true); ui->input6->clicked(true);
    ui->input7->clicked(true); ui->input8->clicked(true);
    ui->input9->clicked(true); ui->input10->clicked(true);
    ui->input11->clicked(true); ui->input12->clicked(true);
    ui->input13->clicked(true); ui->input14->clicked(true);
    ui->input15->clicked(true); ui->input16->clicked(true);
    ui->input17->clicked(true); ui->input18->clicked(true);
    ui->input19->clicked(true); ui->input20->clicked(true);
    ui->input21->clicked(true); ui->input22->clicked(true);
    ui->input23->clicked(true);
    ui->input24->clicked(true);
    ui->input25->clicked(true);
    ui->input26->clicked(true);
    ui->input27->clicked(true);
    ui->input28->clicked(true);
    ui->input29->clicked(true);
    ui->input30->clicked(true);
    ui->input31->clicked(true);
    ui->input32->clicked(true);
    ui->input33->clicked(true);
    ui->input34->clicked(true);
    ui->input35->clicked(true);
    ui->input36->clicked(true);
    ui->input37->clicked(true);
    ui->input38->clicked(true);
    ui->input39->clicked(true);
    ui->input40->clicked(true);
    ui->input41->clicked(true);
    ui->input42->clicked(true);
    ui->input43->clicked(true);
    ui->input44->clicked(true);
    ui->input45->clicked(true);
    ui->input46->clicked(true);
    ui->input47->clicked(true);
    ui->input48->clicked(true);
    ui->input49->clicked(true);
    ui->input50->clicked(true);
    ui->input51->clicked(true);
    ui->input52->clicked(true);
    ui->input53->clicked(true);
    ui->input54->clicked(true);
    ui->input55->clicked(true);
    ui->input56->clicked(true);
    ui->input57->clicked(true);
    ui->input58->clicked(true);
    ui->input59->clicked(true);
    ui->input60->clicked(true);
    ui->input61->clicked(true);
    ui->input62->clicked(true);

    ui->input63->clicked(true);
    ui->input64->clicked(true);
    ui->input65->clicked(true);
    ui->input66->clicked(true);
    ui->input67->clicked(true);
    ui->input68->clicked(true);
    ui->input69->clicked(true);
    ui->input70->clicked(true);
    ui->input71->clicked(true);
    ui->input72->clicked(true);
    ui->input73->clicked(true);
    ui->input74->clicked(true);
    ui->input75->clicked(true);
    ui->input76->clicked(true);
    ui->input77->clicked(true);
    ui->input78->clicked(true);
    ui->input79->clicked(true);
    ui->input80->clicked(true);
    ui->input81->clicked(true);
    ui->input82->clicked(true);
    ui->input83->clicked(true);
    ui->input84->clicked(true);
    ui->input85->clicked(true);
    ui->input86->clicked(true);
    ui->input87->clicked(true);
    ui->input88->clicked(true);
    ui->input89->clicked(true);
    ui->input90->clicked(true);
    ui->input91->clicked(true);
    ui->input92->clicked(true);
    ui->input93->clicked(true);
    ui->input94->clicked(true);
    ui->input95->clicked(true);
    ui->input96->clicked(true);
    ui->input97->clicked(true);
    ui->input98->clicked(true);
    ui->input99->clicked(true);
    ui->input100->clicked(true);
    ui->input101->clicked(true);
    ui->input102->clicked(true);
    ui->input103->clicked(true);
    ui->input104->clicked(true);
    ui->input105->clicked(true);
    ui->input106->clicked(true);
    ui->input107->clicked(true);
    ui->input108->clicked(true);
    ui->input109->clicked(true);
    ui->input110->clicked(true);
    ui->input111->clicked(true);
    ui->input112->clicked(true);
    ui->input113->clicked(true);
    ui->input114->clicked(true);
    ui->input115->clicked(true);
    ui->input116->clicked(true);
    ui->input117->clicked(true);
    ui->input118->clicked(true);
    ui->input119->clicked(true);
    ui->input120->clicked(true);
    ui->input121->clicked(true);
    ui->input122->clicked(true);
    ui->input123->clicked(true);
    ui->input124->clicked(true);
}

void BusepWindow::slotInput1clicked(bool pressed)
{
    manageOneInput(input1, pressed);
}

void BusepWindow::slotInput2clicked(bool pressed)
{
    manageOneInput(input2, pressed);
}

void BusepWindow::slotInput3clicked(bool pressed)
{
    manageOneInput(input3, pressed);
}

void BusepWindow::slotInput4clicked(bool pressed)
{
    manageOneInput(input4, pressed);
}

void BusepWindow::slotInput5clicked(bool pressed)
{
    manageOneInput(input5, pressed);
}

void BusepWindow::slotInput6clicked(bool pressed)
{
    manageOneInput(input6, pressed);
}

void BusepWindow::slotInput7clicked(bool pressed)
{
    manageOneInput(input7, pressed);
}

void BusepWindow::slotInput8clicked(bool pressed)
{
    manageOneInput(input8, pressed);
}

void BusepWindow::slotInput9clicked(bool pressed)
{
    manageOneInput(input9, pressed);
}

void BusepWindow::slotInput10clicked(bool pressed)
{
    manageOneInput(input10, pressed);
}

void BusepWindow::slotInput11clicked(bool pressed)
{
    manageOneInput(input11, pressed);
}

void BusepWindow::slotInput12clicked(bool pressed)
{
    manageOneInput(input12, pressed);
}

void BusepWindow::slotInput13clicked(bool pressed)
{
    manageOneInput(input13, pressed);
}

void BusepWindow::slotInput14clicked(bool pressed)
{
    manageOneInput(input14, pressed);
}

void BusepWindow::slotInput15clicked(bool pressed)
{
    manageOneInput(input15, pressed);
}

void BusepWindow::slotInput16clicked(bool pressed)
{
    manageOneInput(input16, pressed);
}

void BusepWindow::slotInput17clicked(bool pressed)
{
    manageOneInput(input17, pressed);
}

void BusepWindow::slotInput18clicked(bool pressed)
{
    manageOneInput(input18, pressed);
}

void BusepWindow::slotInput19clicked(bool pressed)
{
    manageOneInput(input19, pressed);
}

void BusepWindow::slotInput20clicked(bool pressed)
{
    manageOneInput(input20, pressed);
}

void BusepWindow::slotInput21clicked(bool pressed)
{
    manageOneInput(input21, pressed);
}

void BusepWindow::slotInput22clicked(bool pressed)
{
    manageOneInput(input22, pressed);
}

void BusepWindow::slotInput23clicked(bool pressed)
{
    manageOneInput(input23, pressed);
}

void BusepWindow::slotInput24clicked(bool pressed)
{
    manageOneInput(input24, pressed);
}

void BusepWindow::slotInput25clicked(bool pressed)
{
    manageOneInput(input25, pressed);
}

void BusepWindow::slotInput26clicked(bool pressed)
{
    manageOneInput(input26, pressed);
}

void BusepWindow::slotInput27clicked(bool pressed)
{
    manageOneInput(input27, pressed);
}

void BusepWindow::slotInput28clicked(bool pressed)
{
    manageOneInput(input28, pressed);
}

void BusepWindow::slotInput29clicked(bool pressed)
{
    manageOneInput(input29, pressed);
}

void BusepWindow::slotInput30clicked(bool pressed)
{
    manageOneInput(input30, pressed);
}

void BusepWindow::slotInput31clicked(bool pressed)
{
    manageOneInput(input31, pressed);
}

void BusepWindow::slotInput32clicked(bool pressed)
{
    manageOneInput(input32, pressed);
}

void BusepWindow::slotInput33clicked(bool pressed)
{
    manageOneInput(input33, pressed);
}

void BusepWindow::slotInput34clicked(bool pressed)
{
    manageOneInput(input34, pressed);
}

void BusepWindow::slotInput35clicked(bool pressed)
{
    manageOneInput(input35, pressed);
}

void BusepWindow::slotInput36clicked(bool pressed)
{
    manageOneInput(input36, pressed);
}

void BusepWindow::slotInput37clicked(bool pressed)
{
    manageOneInput(input37, pressed);
}

void BusepWindow::slotInput38clicked(bool pressed)
{
    manageOneInput(input38, pressed);
}

void BusepWindow::slotInput39clicked(bool pressed)
{
    manageOneInput(input39, pressed);
}

void BusepWindow::slotInput40clicked(bool pressed)
{
    manageOneInput(input40, pressed);
}

void BusepWindow::slotInput41clicked(bool pressed)
{
    manageOneInput(input41, pressed);
}

void BusepWindow::slotInput42clicked(bool pressed)
{
    manageOneInput(input42, pressed);
}

void BusepWindow::slotInput43clicked(bool pressed)
{
    manageOneInput(input43, pressed);
}

void BusepWindow::slotInput44clicked(bool pressed)
{
    manageOneInput(input44, pressed);
}

void BusepWindow::slotInput45clicked(bool pressed)
{
    manageOneInput(input45, pressed);
}

void BusepWindow::slotInput46clicked(bool pressed)
{
    manageOneInput(input46, pressed);
}

void BusepWindow::slotInput47clicked(bool pressed)
{
    manageOneInput(input47, pressed);
}

void BusepWindow::slotInput48clicked(bool pressed)
{
    manageOneInput(input48, pressed);
}

void BusepWindow::slotInput49clicked(bool pressed)
{
    manageOneInput(input49, pressed);
}

void BusepWindow::slotInput50clicked(bool pressed)
{
    manageOneInput(input50, pressed);
}

void BusepWindow::slotInput51clicked(bool pressed)
{
    manageOneInput(input51, pressed);
}

void BusepWindow::slotInput52clicked(bool pressed)
{
    manageOneInput(input52, pressed);
}

void BusepWindow::slotInput53clicked(bool pressed)
{
    manageOneInput(input53, pressed);
}

void BusepWindow::slotInput54clicked(bool pressed)
{
    manageOneInput(input54, pressed);
}

void BusepWindow::slotInput55clicked(bool pressed)
{
    manageOneInput(input55, pressed);
}

void BusepWindow::slotInput56clicked(bool pressed)
{
    manageOneInput(input56, pressed);
}

void BusepWindow::slotInput57clicked(bool pressed)
{
    manageOneInput(input57, pressed);
}

void BusepWindow::slotInput58clicked(bool pressed)
{
    manageOneInput(input58, pressed);
}

void BusepWindow::slotInput59clicked(bool pressed)
{
    manageOneInput(input59, pressed);
}

void BusepWindow::slotInput60clicked(bool pressed)
{
    manageOneInput(input60, pressed);
}

void BusepWindow::slotInput61clicked(bool pressed)
{
    manageOneInput(input61, pressed);
}

void BusepWindow::slotInput62clicked(bool pressed)
{
    manageOneInput(input62, pressed);
}

void BusepWindow::slotInput63clicked(bool pressed)
{
    manageOneInput(input63, pressed);
}

void BusepWindow::slotInput64clicked(bool pressed)
{
    manageOneInput(input64, pressed);
}

void BusepWindow::slotInput65clicked(bool pressed)
{
    manageOneInput(input65, pressed);
}

void BusepWindow::slotInput66clicked(bool pressed)
{
    manageOneInput(input66, pressed);
}

void BusepWindow::slotInput67clicked(bool pressed)
{
    manageOneInput(input67, pressed);
}

void BusepWindow::slotInput68clicked(bool pressed)
{
    manageOneInput(input68, pressed);
}

void BusepWindow::slotInput69clicked(bool pressed)
{
    manageOneInput(input69, pressed);
}

void BusepWindow::slotInput70clicked(bool pressed)
{
    manageOneInput(input70, pressed);
}

void BusepWindow::slotInput71clicked(bool pressed)
{
    manageOneInput(input71, pressed);
}

void BusepWindow::slotInput72clicked(bool pressed)
{
    manageOneInput(input72, pressed);
}

void BusepWindow::slotInput73clicked(bool pressed)
{
    manageOneInput(input73, pressed);
}

void BusepWindow::slotInput74clicked(bool pressed)
{
    manageOneInput(input74, pressed);
}

void BusepWindow::slotInput75clicked(bool pressed)
{
    manageOneInput(input75, pressed);
}

void BusepWindow::slotInput76clicked(bool pressed)
{
    manageOneInput(input76, pressed);
}

void BusepWindow::slotInput77clicked(bool pressed)
{
    manageOneInput(input77, pressed);
}

void BusepWindow::slotInput78clicked(bool pressed)
{
    manageOneInput(input78, pressed);
}

void BusepWindow::slotInput79clicked(bool pressed)
{
    manageOneInput(input79, pressed);
}

void BusepWindow::slotInput80clicked(bool pressed)
{
    manageOneInput(input80, pressed);
}

void BusepWindow::slotInput81clicked(bool pressed)
{
    manageOneInput(input81, pressed);
}

void BusepWindow::slotInput82clicked(bool pressed)
{
    manageOneInput(input82, pressed);
}

void BusepWindow::slotInput83clicked(bool pressed)
{
    manageOneInput(input83, pressed);
}

void BusepWindow::slotInput84clicked(bool pressed)
{
    manageOneInput(input84, pressed);
}

void BusepWindow::slotInput85clicked(bool pressed)
{
    manageOneInput(input85, pressed);
}

void BusepWindow::slotInput86clicked(bool pressed)
{
    manageOneInput(input86, pressed);
}

void BusepWindow::slotInput87clicked(bool pressed)
{
    manageOneInput(input87, pressed);
}

void BusepWindow::slotInput88clicked(bool pressed)
{
    manageOneInput(input88, pressed);
}

void BusepWindow::slotInput89clicked(bool pressed)
{
    manageOneInput(input89, pressed);
}

void BusepWindow::slotInput90clicked(bool pressed)
{
    manageOneInput(input90, pressed);
}

void BusepWindow::slotInput91clicked(bool pressed)
{
    manageOneInput(input91, pressed);
}

void BusepWindow::slotInput92clicked(bool pressed)
{
    manageOneInput(input92, pressed);
}

void BusepWindow::slotInput93clicked(bool pressed)
{
    manageOneInput(input93, pressed);
}

void BusepWindow::slotInput94clicked(bool pressed)
{
    manageOneInput(input94, pressed);
}

void BusepWindow::slotInput95clicked(bool pressed)
{
    manageOneInput(input95, pressed);
}

void BusepWindow::slotInput96clicked(bool pressed)
{
    manageOneInput(input96, pressed);
}

void BusepWindow::slotInput97clicked(bool pressed)
{
    manageOneInput(input97, pressed);
}

void BusepWindow::slotInput98clicked(bool pressed)
{
    manageOneInput(input98, pressed);
}

void BusepWindow::slotInput99clicked(bool pressed)
{
    manageOneInput(input99, pressed);
}

void BusepWindow::slotInput100clicked(bool pressed)
{
    manageOneInput(input100, pressed);
}

void BusepWindow::slotInput101clicked(bool pressed)
{
    manageOneInput(input101, pressed);
}

void BusepWindow::slotInput102clicked(bool pressed)
{
    manageOneInput(input102, pressed);
}

void BusepWindow::slotInput103clicked(bool pressed)
{
    manageOneInput(input103, pressed);
}

void BusepWindow::slotInput104clicked(bool pressed)
{
    manageOneInput(input104, pressed);
}

void BusepWindow::slotInput105clicked(bool pressed)
{
    manageOneInput(input105, pressed);
}

void BusepWindow::slotInput106clicked(bool pressed)
{
    manageOneInput(input106, pressed);
}

void BusepWindow::slotInput107clicked(bool pressed)
{
    manageOneInput(input107, pressed);
}

void BusepWindow::slotInput108clicked(bool pressed)
{
    manageOneInput(input108, pressed);
}

void BusepWindow::slotInput109clicked(bool pressed)
{
    manageOneInput(input109, pressed);
}

void BusepWindow::slotInput110clicked(bool pressed)
{
    manageOneInput(input110, pressed);
}

void BusepWindow::slotInput111clicked(bool pressed)
{
    manageOneInput(input111, pressed);
}

void BusepWindow::slotInput112clicked(bool pressed)
{
    manageOneInput(input112, pressed);
}

void BusepWindow::slotInput113clicked(bool pressed)
{
    manageOneInput(input113, pressed);
}

void BusepWindow::slotInput114clicked(bool pressed)
{
    manageOneInput(input114, pressed);
}

void BusepWindow::slotInput115clicked(bool pressed)
{
    manageOneInput(input115, pressed);
}

void BusepWindow::slotInput116clicked(bool pressed)
{
    manageOneInput(input116, pressed);
}

void BusepWindow::slotInput117clicked(bool pressed)
{
    manageOneInput(input117, pressed);
}

void BusepWindow::slotInput118clicked(bool pressed)
{
    manageOneInput(input118, pressed);
}

void BusepWindow::slotInput119clicked(bool pressed)
{
    manageOneInput(input119, pressed);
}

void BusepWindow::slotInput120clicked(bool pressed)
{
    manageOneInput(input120, pressed);
}

void BusepWindow::slotInput121clicked(bool pressed)
{
    manageOneInput(input121, pressed);
}

void BusepWindow::slotInput122clicked(bool pressed)
{
    manageOneInput(input122, pressed);
}

void BusepWindow::slotInput123clicked(bool pressed)
{
    manageOneInput(input123, pressed);
}

void BusepWindow::slotInput124clicked(bool pressed)
{
    manageOneInput(input124, pressed);
}

void BusepWindow::manageOneInput(int number, bool pressed)
{
//    qDebug() << __FUNCTION__ << number << last_pressed_i[number - 1];
    if (!pressed)
    {
        if (last_pressed_i[number - 1])
        {
            last_pressed_i[number - 1] = false;

            if (ui->addError->isChecked())
            {
                /// TODO addErrorToIS3
//                dm->addErrorToIS3(number, no_signal_27v);
            }
            else
            {
                dm->createIS3(number, no_signal_27v);
            }

            // сохраняю для дальнейшего сравения с результатом
            i_state[number - 1] = no_signal_27v;
        }
        else
        {
            last_pressed_i[number - 1] = true;

            if (ui->addError->isChecked())
            {
                /// TODO addErrorToIS3
//                dm->addErrorToIS3(number, is_signal_27v);
            }
            else
            {
               dm->createIS3(number, is_signal_27v);
            }

            // сохраняю для дальнейшего сравения с результатом
            i_state[number - 1] = is_signal_27v;
        }
    }
}

void BusepWindow::slotStartExchangeByTimer()
{
    dm->startExchange(ui->addError->isChecked(), ui->noOutputState->isChecked(), timer->interval());

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

bool BusepWindow::readConfigFile()
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

void BusepWindow::createPalette()
{
    red_palette.setColor(ui->output1->backgroundRole(), Qt::red);
    yellow_palette.setColor(ui->output1->backgroundRole(), Qt::yellow);
    green_palette.setColor(ui->output1->backgroundRole(), Qt::green);
    gray_palette.setColor(ui->output1->backgroundRole(), Qt::gray);
    blue_palette.setColor(ui->output1->backgroundRole(), Qt::blue);
}

void BusepWindow::showInputsValue()
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

void BusepWindow::setInputColor(int i_nmb, QPushButton *input_button)
{
    input_state state = dm->getInputState(i_nmb);
    switch (state)
    {
    case no_signal_27v:
        input_palette[i_nmb - 1].setColor(input_button->backgroundRole(), Qt::gray);
        break;

    case is_signal_27v:
        input_palette[i_nmb - 1].setColor(input_button->backgroundRole(), Qt::green);
        break;

    case no_input_state:
        input_palette[i_nmb - 1].setColor(input_button->backgroundRole(), Qt::red);
        break;

    default:
        input_palette[i_nmb - 1].setColor(input_button->backgroundRole(), Qt::yellow);
        break;
    }
    input_button->setPalette(input_palette[i_nmb - 1]);
}

void BusepWindow::showOutputsValue()
{
    setOutputColor(output1, ui->output1);
    setOutputColor(output2, ui->output2);
    setOutputColor(output3, ui->output3);
    setOutputColor(output4, ui->output4);

    setOutputColor(output5, ui->output5);
    setOutputColor(output6, ui->output6);
    setOutputColor(output7, ui->output7);
    setOutputColor(output8, ui->output8);

    setOutputColor(output9, ui->output9);
    setOutputColor(output10, ui->output10);
    setOutputColor(output11, ui->output11);
    setOutputColor(output12, ui->output12);

    setOutputColor(output13, ui->output13);
    setOutputColor(output14, ui->output14);
    setOutputColor(output15, ui->output15);
    setOutputColor(output16, ui->output16);

    setOutputColor(output17, ui->output17);
    setOutputColor(output18, ui->output18);
    setOutputColor(output19, ui->output19);
    setOutputColor(output20, ui->output20);

    setOutputColor(output21, ui->output21);
    setOutputColor(output22, ui->output22);
    setOutputColor(output23, ui->output23);
    setOutputColor(output24, ui->output24);

    setOutputColor(output25, ui->output25);
    setOutputColor(output26, ui->output26);
    setOutputColor(output27, ui->output27);
    setOutputColor(output28, ui->output28);

    setOutputColor(output29, ui->output29);
    setOutputColor(output30, ui->output30);
    setOutputColor(output31, ui->output31);
    setOutputColor(output32, ui->output32);

    setOutputColor(output33, ui->output33);
    setOutputColor(output34, ui->output34);
    setOutputColor(output35, ui->output35);
    setOutputColor(output36, ui->output36);

    setOutputColor(output37, ui->output37);
    setOutputColor(output38, ui->output38);
    setOutputColor(output39, ui->output39);
    setOutputColor(output40, ui->output40);

    setOutputColor(output41, ui->output41);
    setOutputColor(output42, ui->output42);
    setOutputColor(output43, ui->output43);
    setOutputColor(output44, ui->output44);

    setOutputColor(output45, ui->output45);
    setOutputColor(output46, ui->output46);
    setOutputColor(output47, ui->output47);
    setOutputColor(output48, ui->output48);

    setOutputColor(output49, ui->output49);
    setOutputColor(output50, ui->output50);
    setOutputColor(output51, ui->output51);
    setOutputColor(output52, ui->output52);

    setOutputColor(output53, ui->output53);
    setOutputColor(output54, ui->output54);
    setOutputColor(output55, ui->output55);
    setOutputColor(output56, ui->output56);

    setOutputColor(output57, ui->output57);
    setOutputColor(output58, ui->output58);
    setOutputColor(output59, ui->output59);
    setOutputColor(output60, ui->output60);

    setOutputColor(output61, ui->output61);
    setOutputColor(output62, ui->output62);
}

void BusepWindow::setOutputColor(int o_nmb, QPushButton *output_button)
{
    output_state state = dm->getOutputState(o_nmb);

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
