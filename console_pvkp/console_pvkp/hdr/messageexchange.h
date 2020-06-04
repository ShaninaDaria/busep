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

    QList <QSerialPortInfo> getAllSerialPorts();
    bool openSerialPort(QString port_name, int baud_rate);
    QString portName();

    void createIS2(int number, output_cntrl cntrl);

    void startExchange();
    void testConnection();
    void stopExchange();

    void usualExchange2();

    qint64 sendIS1();

    qint64 sendIS2();

    qint64 receiveSmth(int wait_ms, bool test = false);

    input_state getInputState(int number);

    output_state getOutputState(int number);

    void addErrorToIS1();
    void addErrorToIS2(int number, output_cntrl cntrl);

    bool parse_IS3() const;
    void setParse_IS3(bool parse_IS3);

    bool parse_IS4() const;
    void setParse_IS4(bool parse_IS4);

    bool parse_IS5() const;

    bool start_exchange() const;


private slots:
    void slotWaitingForIS4();

    void slotUsualExchange();

signals:
    void signalTest(QString);
    void signalReceiveIS3();
    void signalReceiveIS4();
    void signalReceiveIS5();

    void signalNoReceiveIS3();
    void signalNoReceiveIS4();

private:
    void createIS1();

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
    qint64 bytes_send_IS2;

    bool _parse_IS3;
    bool _parse_IS4;
    bool _parse_IS5;

    bool _start_exchange;    // начало обработки

    QThread *thread;

    int no_rcv_count;

};

#endif // MESSAGEEXCHANGE_H
