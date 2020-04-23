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

    void sendIS1(_is1 *IS1);
    int receiveIS3();

    void sendIS2();
    void receiveIS4();

    void receiveIS5();

private:
    informationMessages *IM;
    DataTransmit *dataTransnmit;
    _is1 IS1;
    _is3 IS3;
    _rcv_data rcv_data;

    void createIS1();
    void createIS2();

    int sendText();
};

#endif // MESSAGEEXCHANGE_H
