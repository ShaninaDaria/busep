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

private:
    void fictitiousOutputColor();
    void fictitiousInputColor();
    void showInputsValue();
    void setInputColor(const unsigned &input, QPushButton *input_button);

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
