#ifndef MESSAGEEXCHANGE_H
#define MESSAGEEXCHANGE_H

#include <QObject>
#include <QTimer>

#include "hdr/formingIM_pvkp.h"
#include "../../common/hdr/datatransmit.h"

class messageExchange : public QObject
{
    Q_OBJECT
public:
    explicit messageExchange(QObject *parent = nullptr);
    ~messageExchange();

    void initTransmit();

    void createIS2(char number, output_cntrl cntrl);

    void startExchange();

    int sendIS1(_is1 *IS1);
    int receiveIS3();

    int sendIS2(_is2 *IS2);
    int receiveIS4();

    void receiveIS5();

    _inputs &getInputsValue();
    char *getOutputsValue();
    output_state getOutputState(int number);

private:
    void createTimer();
    static void timer_handler(int signum);


    FormingIM_pvkp *formingIMpvkp;
    DataTransmit *dataTransnmit;
    _is1 IS1;
    _is2 IS2;
    _is3 IS3;
    _is4 IS4;
    _rcv_data rcv_data;

    void createIS1();
};

#endif // MESSAGEEXCHANGE_H
