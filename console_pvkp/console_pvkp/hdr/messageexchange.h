#ifndef MESSAGEEXCHANGE_H
#define MESSAGEEXCHANGE_H

#include <QObject>
#include <QTimer>
#include <QThread>

#include "hdr/formingIM_pvkp.h"
#include "../../common/hdr/datatransmit.h"

enum type_exchange
{
    is1_is3 = 1,
    is2_is4 = 2
};

class messageExchange : public QObject
{
    Q_OBJECT
public:
    explicit messageExchange(QObject *parent = NULL);   /*nullptr*/
    ~messageExchange();

    void initTransmit();

    QList <QSerialPortInfo> getAllSerialPorts();
    bool openSerialPort(QString port_name, int baud_rate);

    void createIS2(int number, output_cntrl cntrl);

    void startExchange();
    void usualExchange();
    void stopExchange();

    qint64 sendIS1();

    qint64 sendIS2();

    qint64 receiveSmth(int wait_ms);

    char *getInputsValue();
    input_state getInputState(int number);

    char *getOutputsValue();
    output_state getOutputState(int number);

    void addErrorToIS1();
    void addErrorToIS2(int number, output_cntrl cntrl);

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
//    void createTimer();
//    static void timer_handler(int signum);

    void createIS1();

    void exchange(QTimer *main_timer, qint64 &bytes_send, int wait_ms, type_exchange var_exch);

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

    qint64 bytes_send_IS1;
//    int bytes_rcv_IS3_IS5;
    qint64 bytes_send_IS2;
//    int bytes_rcv_IS4_IS5;

    bool _parse_IS3;
    bool _parse_IS4;
    bool _parse_IS5;

    bool _start_exchange;    // начало обработки

    QThread *thread;

};

#endif // MESSAGEEXCHANGE_H
