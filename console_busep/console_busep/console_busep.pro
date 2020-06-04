QT += core
QT += gui
QT += serialport

CONFIG += c++11
#CONFIG += console
#CONFIG -= app_bundle
QMAKE_CXXFLAGS += -std=c++0x
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets network

TARGET = simulator_busep

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
DEFINES +=QNX

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        src/manageinputsoutputs.cpp \
        src/dummymessages.cpp \
        src/formingIM_busep.cpp \
        src/busepwindow.cpp \
        src/main.cpp \
        ../../common/src/inputs_outputs.cpp \
        ../../common/src/informationmessages.cpp \
        ../../common/src/datatransmit.cpp

HEADERS += \
    hdr/manageinputsoutputs.h \
    hdr/formingIM_busep.h \
    hdr/dummymessages.h \
    hdr/busepwindow.h \
    ../../common/hdr/common.h \
    ../../common/hdr/inputs_outputs.h \
    ../../common/hdr/informationmessages.h \
    ../../common/hdr/datatransmit.h

FORMS += \
    busepwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

