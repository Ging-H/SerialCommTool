#-------------------------------------------------
#
# Project created by QtCreator 2019-10-22T14:15:51
#
#-------------------------------------------------

QT       += core gui
QT       += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SerialAssistant
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
    baseserialcomm.cpp \
    main.cpp \
    serialassistant.cpp \
    sreialrx.cpp


HEADERS += \
    baseserialcomm.h \
    serialassistant.h \
    sreialrx.h \
    ui_serialassistant.h

FORMS += \
    serialassistant.ui



# 配置输出路径: debug和release模式下的输出路径
# 配置动态链接库的路径: debug和release模式下的dll路径
CONFIG(debug, debug|release){
DESTDIR = ../../debug                 # .exe 路径
#LIBS  += -L ../../debug -lSerialComm # .dll 路径
}else {
DESTDIR = ../../release
#LIBS  += -L ../../release -lSerialComm
}

DISTFILES += \
    theme/default.qss


