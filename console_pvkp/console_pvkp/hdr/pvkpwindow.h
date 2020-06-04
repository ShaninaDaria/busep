#ifndef PVKPWINDOW_H
#define PVKPWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QThread>
#include <QTimer>
#include "hdr/messageexchange.h"

namespace Ui {
class PVKPWindow;
}

class PVKPWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PVKPWindow(QWidget *parent = NULL);    /*nullptr*/
    ~PVKPWindow();

private slots:
    void slotPortChecked(int port_index);

    void slotReceiveIS3();
    void slotReceiveIS4();
    void slotReceiveIS5();
    void slotTestReceive(QString str);

    void slotNoReceiveIS3();
    void slotNoReceiveIS4();

    void slotStartStop();
    void slotTestConnection();

    void slotAllOutputsOnOff(bool toggled);

    void slotOutput1clicked(bool pressed);
    void slotOutput2clicked(bool pressed);
    void slotOutput3clicked(bool pressed);
    void slotOutput4clicked(bool pressed);

    void slotOutput5clicked(bool pressed);
    void slotOutput6clicked(bool pressed);
    void slotOutput7clicked(bool pressed);
    void slotOutput8clicked(bool pressed);

    void slotOutput9clicked(bool pressed);
    void slotOutput10clicked(bool pressed);
    void slotOutput11clicked(bool pressed);
    void slotOutput12clicked(bool pressed);

    void slotOutput13clicked(bool pressed);
    void slotOutput14clicked(bool pressed);
    void slotOutput15clicked(bool pressed);
    void slotOutput16clicked(bool pressed);

    void slotOutput17clicked(bool pressed);
    void slotOutput18clicked(bool pressed);
    void slotOutput19clicked(bool pressed);
    void slotOutput20clicked(bool pressed);

    void slotOutput21clicked(bool pressed);
    void slotOutput22clicked(bool pressed);
    void slotOutput23clicked(bool pressed);
    void slotOutput24clicked(bool pressed);

    void slotOutput25clicked(bool pressed);
    void slotOutput26clicked(bool pressed);
    void slotOutput27clicked(bool pressed);
    void slotOutput28clicked(bool pressed);

    void slotOutput29clicked(bool pressed);
    void slotOutput30clicked(bool pressed);
    void slotOutput31clicked(bool pressed);
    void slotOutput32clicked(bool pressed);

    void slotOutput33clicked(bool pressed);
    void slotOutput34clicked(bool pressed);
    void slotOutput35clicked(bool pressed);
    void slotOutput36clicked(bool pressed);

    void slotOutput37clicked(bool pressed);
    void slotOutput38clicked(bool pressed);
    void slotOutput39clicked(bool pressed);
    void slotOutput40clicked(bool pressed);

    void slotOutput41clicked(bool pressed);
    void slotOutput42clicked(bool pressed);
    void slotOutput43clicked(bool pressed);
    void slotOutput44clicked(bool pressed);

    void slotOutput45clicked(bool pressed);
    void slotOutput46clicked(bool pressed);
    void slotOutput47clicked(bool pressed);
    void slotOutput48clicked(bool pressed);

    void slotOutput49clicked(bool pressed);
    void slotOutput50clicked(bool pressed);
    void slotOutput51clicked(bool pressed);
    void slotOutput52clicked(bool pressed);

    void slotOutput53clicked(bool pressed);
    void slotOutput54clicked(bool pressed);
    void slotOutput55clicked(bool pressed);
    void slotOutput56clicked(bool pressed);

    void slotOutput57clicked(bool pressed);
    void slotOutput58clicked(bool pressed);
    void slotOutput59clicked(bool pressed);
    void slotOutput60clicked(bool pressed);

    void slotOutput61clicked(bool pressed);
    void slotOutput62clicked(bool pressed);

private:
    bool readConfigFile();
    void createPalette();
    void showInputsValue();
    void setInputColor(int i_nmb, QPushButton *input_button);

    void showOutputsValue();
    void setOutputColor(int o_nmb, QPushButton *output_button);

    void manageOneOutput(int number, bool pressed);

    Ui::PVKPWindow *ui;
//    QThread *thread;

    QPalette green_palette;
    QPalette red_palette;
    QPalette yellow_palette;
    QPalette gray_palette;
    QPalette orange_palette;
    QPalette system_palette;

    messageExchange *me;

    // для хранения предыдущего статуса кнопки выхода
    bool last_pressed_o[output_size];
    output_cntrl o_cntrl[output_size];
    QPalette button_palette[output_size];

    bool start_simulator;

};

#endif // PVKPWINDOW_H
