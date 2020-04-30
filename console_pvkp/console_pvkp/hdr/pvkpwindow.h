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
    explicit PVKPWindow(QWidget *parent = nullptr);
    ~PVKPWindow();

private slots:
    void slotByTimer();

    void slotAllOutputsOff();
    void slotAllOutputsOn();

    void slotOutput1toggled(bool toggled);
    void slotOutput2toggled(bool toggled);
    void slotOutput3toggled(bool toggled);
    void slotOutput4toggled(bool toggled);

    void slotOutput5toggled(bool toggled);
    void slotOutput6toggled(bool toggled);
    void slotOutput7toggled(bool toggled);
    void slotOutput8toggled(bool toggled);

    void slotOutput9toggled(bool toggled);
    void slotOutput10toggled(bool toggled);
    void slotOutput11toggled(bool toggled);
    void slotOutput12toggled(bool toggled);

    void slotOutput13toggled(bool toggled);
    void slotOutput14toggled(bool toggled);
    void slotOutput15toggled(bool toggled);
    void slotOutput16toggled(bool toggled);

    void slotOutput17toggled(bool toggled);
    void slotOutput18toggled(bool toggled);
    void slotOutput19toggled(bool toggled);
    void slotOutput20toggled(bool toggled);

    void slotOutput21toggled(bool toggled);
    void slotOutput22toggled(bool toggled);
    void slotOutput23toggled(bool toggled);
    void slotOutput24toggled(bool toggled);

    void slotOutput25toggled(bool toggled);
    void slotOutput26toggled(bool toggled);
    void slotOutput27toggled(bool toggled);
    void slotOutput28toggled(bool toggled);

    void slotOutput29toggled(bool toggled);
    void slotOutput30toggled(bool toggled);
    void slotOutput31toggled(bool toggled);
    void slotOutput32toggled(bool toggled);

    void slotOutput33toggled(bool toggled);
    void slotOutput34toggled(bool toggled);
    void slotOutput35toggled(bool toggled);
    void slotOutput36toggled(bool toggled);

    void slotOutput37toggled(bool toggled);
    void slotOutput38toggled(bool toggled);
    void slotOutput39toggled(bool toggled);
    void slotOutput40toggled(bool toggled);

    void slotOutput41toggled(bool toggled);
    void slotOutput42toggled(bool toggled);
    void slotOutput43toggled(bool toggled);
    void slotOutput44toggled(bool toggled);

    void slotOutput45toggled(bool toggled);
    void slotOutput46toggled(bool toggled);
    void slotOutput47toggled(bool toggled);
    void slotOutput48toggled(bool toggled);

    void slotOutput49toggled(bool toggled);
    void slotOutput50toggled(bool toggled);
    void slotOutput51toggled(bool toggled);
    void slotOutput52toggled(bool toggled);

    void slotOutput53toggled(bool toggled);
    void slotOutput54toggled(bool toggled);
    void slotOutput55toggled(bool toggled);
    void slotOutput56toggled(bool toggled);

    void slotOutput57toggled(bool toggled);
    void slotOutput58toggled(bool toggled);
    void slotOutput59toggled(bool toggled);
    void slotOutput60toggled(bool toggled);

    void slotOutput61toggled(bool toggled);
    void slotOutput62toggled(bool toggled);

private:
    void createPalette();
    void showInputsValue();
    void setInputColor(const unsigned &input, QPushButton *input_button);

    void showOutputsValue();
    void setOutputColor(const unsigned &output, QPushButton *output_button);

    Ui::PVKPWindow *ui;
    QThread *thread;
    QTimer *timer;

    QPalette green_palette;
    QPalette red_palette;
    QPalette yellow_palette;
    QPalette gray_palette;

    messageExchange *me;

//    _outputs outputs;
};

#endif // PVKPWINDOW_H
