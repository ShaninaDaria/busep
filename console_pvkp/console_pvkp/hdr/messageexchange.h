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

    bool startExchange();
    void usualExchange();

    int sendIS1(_is1 *IS1);
    int receiveIS3(bool &ok);

    int sendIS2(_is2 *IS2);
    int receiveIS4();

    void receiveIS5();

    char *getInputsValue();
    input_state getInputState(int number);

    char *getOutputsValue();
    output_state getOutputState(int number);

    int getBytes_rcv_IS3() const;

    int getBytes_rcv_IS4() const;

    void addErrorToIS1();
    void addErrorToIS2();

private slots:
    void slotWaitingForIS3();
    void slotWaitingForIS4();

signals:
    void signalReceiveIS3();
    void signalReceiveIS4();

private:
    void createTimer();
    static void timer_handler(int signum);

    void createIS1();

    FormingIM_pvkp *formingIMpvkp;
    DataTransmit *dataTransnmit;
    _is1 IS1;
    _is2 IS2;
    _is3 IS3;
    _is4 IS4;
    _rcv_data rcv_data;

    QTimer *timerIS1_IS3;
    QTimer *timerIS2_IS4;

    int bytes_send_IS1;
    int bytes_rcv_IS3;
    int bytes_send_IS2;
    int bytes_rcv_IS4;

};

#endif // MESSAGEEXCHANGE_H
