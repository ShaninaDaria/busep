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

    void slotOutput1off();
    void slotOutput2off();
    void slotOutput3off();
    void slotOutput4off();

    void slotOutput5off();
    void slotOutput6off();
    void slotOutput7off();
    void slotOutput8off();

    void slotOutput9off();
    void slotOutput10off();
    void slotOutput11off();
    void slotOutput12off();

    void slotOutput13off();
    void slotOutput14off();
    void slotOutput15off();
    void slotOutput16off();

    void slotOutput17off();
    void slotOutput18off();
    void slotOutput19off();
    void slotOutput20off();
    void slotOutput21off();
    void slotOutput22off();
    void slotOutput23off();
    void slotOutput24off();
    void slotOutput25off();
    void slotOutput26off();
    void slotOutput27off();
    void slotOutput28off();
    void slotOutput29off();
    void slotOutput30off();
    void slotOutput31off();
    void slotOutput32off();
    void slotOutput33off();
    void slotOutput34off();
    void slotOutput35off();
    void slotOutput36off();
    void slotOutput37off();
    void slotOutput38off();
    void slotOutput39off();
    void slotOutput40off();
    void slotOutput41off();
    void slotOutput42off();
    void slotOutput43off();
    void slotOutput44off();
    void slotOutput45off();
    void slotOutput46off();
    void slotOutput47off();
    void slotOutput48off();
    void slotOutput49off();
    void slotOutput50off();
    void slotOutput51off();
    void slotOutput52off();
    void slotOutput53off();
    void slotOutput54off();
    void slotOutput55off();
    void slotOutput56off();
    void slotOutput57off();
    void slotOutput58off();
    void slotOutput59off();
    void slotOutput60off();
    void slotOutput61off();
    void slotOutput62off();

    void slotOutput1on();
    void slotOutput2on();
    void slotOutput3on();
    void slotOutput4on();
    void slotOutput5on();
    void slotOutput6on();
    void slotOutput7on();
    void slotOutput8on();
    void slotOutput9on();
    void slotOutput10on();
    void slotOutput11on();
    void slotOutput12on();
    void slotOutput13on();
    void slotOutput14on();
    void slotOutput15on();
    void slotOutput16on();
    void slotOutput17on();
    void slotOutput18on();
    void slotOutput19on();
    void slotOutput20on();
    void slotOutput21on();
    void slotOutput22on();
    void slotOutput23on();
    void slotOutput24on();
    void slotOutput25on();
    void slotOutput26on();
    void slotOutput27on();
    void slotOutput28on();
    void slotOutput29on();
    void slotOutput30on();
    void slotOutput31on();
    void slotOutput32on();
    void slotOutput33on();
    void slotOutput34on();
    void slotOutput35on();
    void slotOutput36on();
    void slotOutput37on();
    void slotOutput38on();
    void slotOutput39on();
    void slotOutput40on();
    void slotOutput41on();
    void slotOutput42on();
    void slotOutput43on();
    void slotOutput44on();
    void slotOutput45on();
    void slotOutput46on();
    void slotOutput47on();
    void slotOutput48on();
    void slotOutput49on();
    void slotOutput50on();
    void slotOutput51on();
    void slotOutput52on();
    void slotOutput53on();
    void slotOutput54on();
    void slotOutput55on();
    void slotOutput56on();
    void slotOutput57on();
    void slotOutput58on();
    void slotOutput59on();
    void slotOutput60on();
    void slotOutput61on();
    void slotOutput62on();


private:
    void showInputsValue();
    void setInputColor(const unsigned &input, QPushButton *input_button);

    void showOutputValue();
    void setOutputColor(const unsigned &output, QPushButton *output_button);

    Ui::PVKPWindow *ui;
    QThread *thread;
    QTimer *timer;

    QPalette green_palette;
    QPalette red_palette;
    QPalette yellow_palette;
    QPalette gray_palette;

    messageExchange *me;
};

#endif // PVKPWINDOW_H
