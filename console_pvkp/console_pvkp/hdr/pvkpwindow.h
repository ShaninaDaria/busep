#ifndef PVKPWINDOW_H
#define PVKPWINDOW_H

#include <QMainWindow>

namespace Ui {
class PVKPWindow;
}

class PVKPWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PVKPWindow(QWidget *parent = nullptr);
    ~PVKPWindow();

private:
    void fictitiousOutputColor();
    void fictitiousInputColor();
    Ui::PVKPWindow *ui;

    QPalette green_palette;
    QPalette red_palette;
};

#endif // PVKPWINDOW_H
