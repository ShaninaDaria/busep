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

    void slotAllOutputsOff(bool toggled);
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
//    QThread *thread;
    QTimer *timer;

    QPalette green_palette;
    QPalette red_palette;
    QPalette yellow_palette;
    QPalette gray_palette;

    messageExchange *me;

    bool all_buttons_off;
    bool all_buttons_on;
    bool all_buttons_on_off;
    // для хранения предыдущего статуса кнопки выхода
    bool last_toggled_o1;
    bool last_toggled_o2;
    bool last_toggled_o3;
    bool last_toggled_o4;
    bool last_toggled_o5;
    bool last_toggled_o6;
    bool last_toggled_o7;
    bool last_toggled_o8;
    bool last_toggled_o9;
    bool last_toggled_o10;
    bool last_toggled_o11;
    bool last_toggled_o12;
    bool last_toggled_o13;
    bool last_toggled_o14;
    bool last_toggled_o15;
    bool last_toggled_o16;
    bool last_toggled_o17;
    bool last_toggled_o18;
    bool last_toggled_o19;
    bool last_toggled_o20;
    bool last_toggled_o21;
    bool last_toggled_o22;
    bool last_toggled_o23;
    bool last_toggled_o24;
    bool last_toggled_o25;
    bool last_toggled_o26;
    bool last_toggled_o27;
    bool last_toggled_o28;
    bool last_toggled_o29;
    bool last_toggled_o30;
    bool last_toggled_o31;
    bool last_toggled_o32;
    bool last_toggled_o33;
    bool last_toggled_o34;
    bool last_toggled_o35;
    bool last_toggled_o36;
    bool last_toggled_o37;
    bool last_toggled_o38;
    bool last_toggled_o39;
    bool last_toggled_o40;
    bool last_toggled_o41;
    bool last_toggled_o42;
    bool last_toggled_o43;
    bool last_toggled_o44;
    bool last_toggled_o45;
    bool last_toggled_o46;
    bool last_toggled_o47;
    bool last_toggled_o48;
    bool last_toggled_o49;
    bool last_toggled_o50;
    bool last_toggled_o51;
    bool last_toggled_o52;
    bool last_toggled_o53;
    bool last_toggled_o54;
    bool last_toggled_o55;
    bool last_toggled_o56;
    bool last_toggled_o57;
    bool last_toggled_o58;
    bool last_toggled_o59;
    bool last_toggled_o60;
    bool last_toggled_o61;
    bool last_toggled_o62;

};

#endif // PVKPWINDOW_H
