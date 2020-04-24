#ifndef MESSAGEEXCHANGE_H
#define MESSAGEEXCHANGE_H

#include <QTimer>

#include "../../common/hdr/informationmessages.h"
#include "../../common/hdr/datatransmit.h"

class messageExchange
{
public:
    messageExchange();
    ~messageExchange();

    void startExchange();

    int sendIS1(_is1 *IS1);
    int receiveIS3();

    int sendIS2(_is2 *IS2);
    int receiveIS4();

    void receiveIS5();

private:
    void createTimer();
    static void timer_handler(int signum);

    informationMessages *IM;
    DataTransmit *dataTransnmit;
    _is1 IS1;
    _is2 IS2;
    _is3 IS3;
    _is4 IS4;
    _rcv_data rcv_data;

    void createIS1();
    void createIS2();
};

#endif // MESSAGEEXCHANGE_H
