#-------------------------------------------------
#
# Project created by QtCreator 2019-10-22T11:29:17
#
#-------------------------------------------------

QT       += core gui
QT       += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MainWindow
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    ../SubWindow/SerialAssistant/baseserialcomm.cpp \
    ../SubWindow/SerialAssistant/serialassistant.cpp \
    ../SubWindow/SerialAssistant/crc32.c \
    ../SubWindow/SerialAssistant/crcccitt.c \
    ../SubWindow/StepperMotor/steppermotor.cpp



HEADERS += \
        mainwindow.h \
    ../SubWindow/SerialAssistant/baseserialcomm.h \
    ../SubWindow/SerialAssistant/checksum.h \
    ../SubWindow/SerialAssistant/serialassistant.h \
    ui_mainwindow.h \
    ui_serialassistant.h \
    ../SubWindow/StepperMotor/steppermotor.h


FORMS += \
        mainwindow.ui \
    ../SubWindow/SerialAssistant/serialassistant.ui \
    ../SubWindow/StepperMotor/steppermotor.ui





CONFIG(debug, debug|release){
DESTDIR = ../debug
# LIBS  += -L ../debug -lSerialComm
}else {
DESTDIR = ../release
# LIBS  += -L ../release -lSerialComm
}

#RESOURCES += \
#    ../SubWindow/SerialAssistant/images.qrc

RESOURCES += \
    images.qrc
