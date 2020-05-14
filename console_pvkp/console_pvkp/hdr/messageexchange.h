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
    void usualExchange();

    int sendIS1(_is1 *IS1);
//    int receiveIS3();

    int sendIS2(_is2 *IS2);
//    int receiveIS4();

    int receiveSmth();

    char *getInputsValue();
    input_state getInputState(int number);

    char *getOutputsValue();
    output_state getOutputState(int number);

    void addErrorToIS1();
    void addErrorToIS2(char number, output_cntrl cntrl);

    bool parse_IS3() const;

    bool parse_IS4() const;

    bool start_exchange() const;

private slots:
    void slotWaitingForIS3();
    void slotWaitingForIS4();

signals:
    void signalReceiveIS3();
    void signalReceiveIS4();
    void signalReceiveIS5();

private:
    void createTimer();
    static void timer_handler(int signum);

    void createIS1();

    void exchange(QTimer *main_timer, QTimer *second_timer, int &bytes_send, int d, bool &parse_ok, int var_exch);

    void receiveIS3inParts(int bytes_rcv, _is3 &rcv_IS3);
    void receiveIS4inParts(int bytes_rcv, _is4 &rcv_IS4);

    FormingIM_pvkp *formingIMpvkp;
    DataTransmit *dataTransnmit;
    _is1 IS1;
    _is2 IS2;
    _is3 IS3;
    _is4 IS4;
    _is5 IS5;
    _rcv_data rcv_data;

    QTimer *timerIS1_IS3;
    QTimer *timerIS2_IS4;

    int bytes_send_IS1;
//    int bytes_rcv_IS3_IS5;
    int bytes_send_IS2;
//    int bytes_rcv_IS4_IS5;

    bool _parse_IS3;
    bool _parse_IS4;
    bool _parse_IS5;

    bool _start_exchange;    // начало обработки

};

#endif // MESSAGEEXCHANGE_H
