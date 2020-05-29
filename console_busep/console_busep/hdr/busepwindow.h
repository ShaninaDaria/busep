#ifndef BUSEPWINDOW_H
#define BUSEPWINDOW_H

#include <QObject>
#include <QMainWindow>
#include <QPushButton>
#include <QTimer>

#include "hdr/dummymessages.h"

namespace Ui {
class BusepWindow;
}

class BusepWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit BusepWindow(QWidget *parent = NULL);   /*nullptr*/
    ~BusepWindow();

private slots:
    void slotAllInputsOnOff(bool toggled);
    void slotInput1clicked(bool pressed);
    void slotInput2clicked(bool pressed);
    void slotInput3clicked(bool pressed);
    void slotInput4clicked(bool pressed);

    void slotInput5clicked(bool pressed);
    void slotInput6clicked(bool pressed);
    void slotInput7clicked(bool pressed);
    void slotInput8clicked(bool pressed);

    void slotInput9clicked(bool pressed);
    void slotInput10clicked(bool pressed);
    void slotInput11clicked(bool pressed);
    void slotInput12clicked(bool pressed);

    void slotInput13clicked(bool pressed);
    void slotInput14clicked(bool pressed);
    void slotInput15clicked(bool pressed);
    void slotInput16clicked(bool pressed);

    void slotInput17clicked(bool pressed);
    void slotInput18clicked(bool pressed);
    void slotInput19clicked(bool pressed);
    void slotInput20clicked(bool pressed);

    void slotInput21clicked(bool pressed);
    void slotInput22clicked(bool pressed);
    void slotInput23clicked(bool pressed);
    void slotInput24clicked(bool pressed);

    void slotInput25clicked(bool pressed);
    void slotInput26clicked(bool pressed);
    void slotInput27clicked(bool pressed);
    void slotInput28clicked(bool pressed);

    void slotInput29clicked(bool pressed);
    void slotInput30clicked(bool pressed);
    void slotInput31clicked(bool pressed);
    void slotInput32clicked(bool pressed);

    void slotInput33clicked(bool pressed);
    void slotInput34clicked(bool pressed);
    void slotInput35clicked(bool pressed);
    void slotInput36clicked(bool pressed);

    void slotInput37clicked(bool pressed);
    void slotInput38clicked(bool pressed);
    void slotInput39clicked(bool pressed);
    void slotInput40clicked(bool pressed);

    void slotInput41clicked(bool pressed);
    void slotInput42clicked(bool pressed);
    void slotInput43clicked(bool pressed);
    void slotInput44clicked(bool pressed);

    void slotInput45clicked(bool pressed);
    void slotInput46clicked(bool pressed);
    void slotInput47clicked(bool pressed);
    void slotInput48clicked(bool pressed);

    void slotInput49clicked(bool pressed);
    void slotInput50clicked(bool pressed);
    void slotInput51clicked(bool pressed);
    void slotInput52clicked(bool pressed);

    void slotInput53clicked(bool pressed);
    void slotInput54clicked(bool pressed);
    void slotInput55clicked(bool pressed);
    void slotInput56clicked(bool pressed);

    void slotInput57clicked(bool pressed);
    void slotInput58clicked(bool pressed);
    void slotInput59clicked(bool pressed);
    void slotInput60clicked(bool pressed);

    void slotInput61clicked(bool pressed);
    void slotInput62clicked(bool pressed);
    void slotInput63clicked(bool pressed);
    void slotInput64clicked(bool pressed);

    void slotInput65clicked(bool pressed);
    void slotInput66clicked(bool pressed);
    void slotInput67clicked(bool pressed);
    void slotInput68clicked(bool pressed);

    void slotInput69clicked(bool pressed);
    void slotInput70clicked(bool pressed);
    void slotInput71clicked(bool pressed);
    void slotInput72clicked(bool pressed);

    void slotInput73clicked(bool pressed);
    void slotInput74clicked(bool pressed);
    void slotInput75clicked(bool pressed);
    void slotInput76clicked(bool pressed);

    void slotInput77clicked(bool pressed);
    void slotInput78clicked(bool pressed);
    void slotInput79clicked(bool pressed);
    void slotInput80clicked(bool pressed);

    void slotInput81clicked(bool pressed);
    void slotInput82clicked(bool pressed);
    void slotInput83clicked(bool pressed);
    void slotInput84clicked(bool pressed);

    void slotInput85clicked(bool pressed);
    void slotInput86clicked(bool pressed);
    void slotInput87clicked(bool pressed);
    void slotInput88clicked(bool pressed);

    void slotInput89clicked(bool pressed);
    void slotInput90clicked(bool pressed);
    void slotInput91clicked(bool pressed);
    void slotInput92clicked(bool pressed);

    void slotInput93clicked(bool pressed);
    void slotInput94clicked(bool pressed);
    void slotInput95clicked(bool pressed);
    void slotInput96clicked(bool pressed);

    void slotInput97clicked(bool pressed);
    void slotInput98clicked(bool pressed);
    void slotInput99clicked(bool pressed);
    void slotInput100clicked(bool pressed);

    void slotInput101clicked(bool pressed);
    void slotInput102clicked(bool pressed);
    void slotInput103clicked(bool pressed);
    void slotInput104clicked(bool pressed);

    void slotInput105clicked(bool pressed);
    void slotInput106clicked(bool pressed);
    void slotInput107clicked(bool pressed);
    void slotInput108clicked(bool pressed);

    void slotInput109clicked(bool pressed);
    void slotInput110clicked(bool pressed);
    void slotInput111clicked(bool pressed);
    void slotInput112clicked(bool pressed);

    void slotInput113clicked(bool pressed);
    void slotInput114clicked(bool pressed);
    void slotInput115clicked(bool pressed);
    void slotInput116clicked(bool pressed);

    void slotInput117clicked(bool pressed);
    void slotInput118clicked(bool pressed);
    void slotInput119clicked(bool pressed);
    void slotInput120clicked(bool pressed);

    void slotInput121clicked(bool pressed);
    void slotInput122clicked(bool pressed);
    void slotInput123clicked(bool pressed);
    void slotInput124clicked(bool pressed);

    void slotStartExchangeByTimer();
    void slotUsualExchange();
    void slotSendIS5();

private:
    void createPalette();
    void showInputsValue();
    void setInputColor(int i_nmb, QPushButton *input_button);

    void showOutputsValue();
    void setOutputColor(int o_nmb, QPushButton *output_button);

    void manageOneInput(int number, bool pressed);

    Ui::BusepWindow *ui;
    QPalette green_palette;
    QPalette red_palette;
    QPalette yellow_palette;
    QPalette gray_palette;
    QPalette blue_palette;
    QPalette button_palette[output_size];
    QPalette input_palette[input_size];

    QTimer *timer;

    DummyMessages *dm;

    bool last_pressed_i[output_size];
    input_state i_state[input_size];
};

#endif // BUSEPWINDOW_H
