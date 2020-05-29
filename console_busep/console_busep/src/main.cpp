//#include <QCoreApplication>
//#include "hdr/dummymessages.h"

#include <QApplication>
#include "hdr/busepwindow.h"

int main(int argc, char *argv[])
{
//    QCoreApplication a(argc, argv);
//    dummyMessages dm;
//    dm.startExchange();
//    exit(0);

    QApplication a(argc, argv);

    BusepWindow busep_window;
    busep_window.show();

    return a.exec();
}
