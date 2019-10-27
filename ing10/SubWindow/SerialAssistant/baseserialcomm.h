#ifndef BASESERIALCOMM_H
#define BASESERIALCOMM_H

#include "ui_serialassistant.h"

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QObject>


class BaseSerialComm : public QSerialPort,public QSerialPortInfo
{
    Q_OBJECT
public:
    // QSerialPort 只有115200波特率, 为避免直接修改库文件,重写波特率枚举类型
    // TODO: 115200以上的波特率并没有经过实际的测试,无法证明实际能使用
    enum BaudRate {
        Baud1200    = 1200,
        Baud2400    = 2400,
        Baud4800    = 4800,
        Baud9600    = 9600,
        Baud19200   = 19200,
        Baud38400   = 38400,
        Baud57600   = 57600,
        Baud115200  = 115200,
        Baud128000  = 128000,
        Baud256000  = 256000,
        UnknownBaud = -1
    };
    Q_ENUM(BaudRate)

    explicit BaseSerialComm(QSerialPort *parent = nullptr);

    static void listVerify(QComboBox *cbbVerify);
    static void listStopBit(QComboBox *cbbStopBit);
    static void listBaudRate(QComboBox *cbbBaud);
    static void listDataBit(QComboBox *cbbDataBit);
    static void listPortNum(QComboBox *cbbPortNum);
    static void searchPort(QStringList &portList);
    void setDTRState(bool set);
    void setRTSState(bool set);



signals:

public slots:



};

#endif // BASESERIALCOMM_H

