#ifndef MESSAGEEXCHANGE_H
#define MESSAGEEXCHANGE_H

#include <QTimer>

#include "../../common/hdr/informationmessages.h"

class messageExchange
{
public:
    messageExchange();
    ~messageExchange();

    void startExchange();

    void sendIS1();
    void receiveIS3();

    void sendIS2();
    void receiveIS4();

    void receiveIS5();

private:
    informationMessages *IM;

    void createIS1();
    void createIS2();
};

#endif // MESSAGEEXCHANGE_H
