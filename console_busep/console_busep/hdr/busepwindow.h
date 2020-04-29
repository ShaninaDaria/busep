#ifndef BUSEPWINDOW_H
#define BUSEPWINDOW_H

#include <QObject>
#include <QMainWindow>
#include <QPushButton>
#include <QTimer>

#include "hdr/dummymessages.h"

namespace Ui {
class BusepWindow;
}

class BusepWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit BusepWindow(QWidget *parent = nullptr);
    ~BusepWindow();

private slots:
    void slotAllInputsOff();
    void slotAllInputsOn();
    void slotStartExchangeByTimer();

private:
    void createPalette();
    void showInputsValue();
    void setInputColor(const unsigned &input, QPushButton *input_button);

    void showOutputsValue();
    void setOutputColor(const unsigned &output, QPushButton *output_button);

    Ui::BusepWindow *ui;
    QPalette green_palette;
    QPalette red_palette;
    QPalette yellow_palette;
    QPalette gray_palette;
    QTimer *timer;

    DummyMessages *dm;
};

#endif // BUSEPWINDOW_H
