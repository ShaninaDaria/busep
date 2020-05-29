#ifndef DUMMYMESSAGES_H
#define DUMMYMESSAGES_H

#include <QObject>
#include <QThread>

#include "../../common/hdr/informationmessages.h"
#include "../../common/hdr/datatransmit.h"
#include "formingIM_busep.h"


class DummyMessages : public QObject
{
    Q_OBJECT
public:
    explicit DummyMessages(QObject *parent = NULL); /*nullptr*/
    ~DummyMessages();

    bool openSerialPort(QString port_name, int baud_rate);
    void startExchange(bool add_error, bool no_state, int wait_ms);

    void createIS3(int device_number, input_state state);
    void sendIS3();

    void createIS4(unsigned char device_number, unsigned char cnrtl,
                   bool add_error = false, bool no_state = false);
    void sendIS4();

    void createIS5();
    void sendIS5();

    char *getInputs();
    char *getOutputs();

    output_state getOutputState(int number);
    input_state getInputState(int number);

signals:
    void signalUsualExchange();
    void signalSendIS5();

private:
    header_and_managed receiveSmth(int wait_ms);

    FormingIM_busep *formingIM_busep;
    DataTransmit *dataTransnmit;
    _is1 IS1;
    _is2 IS2;
    _is3 *IS3;
    _is4 *IS4;
    _is5 *IS5;

    QThread *thread;
};

#endif // DUMMYMESSAGES_H
