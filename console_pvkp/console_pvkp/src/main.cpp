#include <QApplication>
#include "hdr/pvkpwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    PVKPWindow pvkp_window;
    pvkp_window.show();

    return a.exec();
}
