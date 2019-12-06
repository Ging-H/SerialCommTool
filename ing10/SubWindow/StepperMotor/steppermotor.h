#ifndef STEPPERMOTOR_H
#define STEPPERMOTOR_H

#include <QWidget>
#include "baseserialcomm.h"

namespace Ui {
class StepperMotor;
}

class StepperMotor : public QWidget
{
    Q_OBJECT

public:
    explicit StepperMotor(QWidget *parent = 0);
    ~StepperMotor();

    enum CtrlCmd {
        ModeSelect  = 0x01, // 1个字节 0x00 none, 0x01 speed, 0x02 position
        JogCtrl     = 0x02, // 1个字节 0x00 停止, 0x01 点动
        SetSpeed    = 0x03, // Param1 : 浮点数
        GetDevice   = 0x04, //
        SetPos      = 0x05, // Param1 : 脉冲数 整型数据
        OutCtrl     = 0x06, // 4个字节 Out1(00/01) Out2(00/01) Out3(00/01) Out4(00/01)
    };
    Q_ENUM(CtrlCmd)
    enum ResponseCmd {
        LimitState  = 0x80, // 12个字节, IN1(00/01), ... IN12(00/01)
        Response    = 0x84, // 响应反馈, 2个字节 0x55 0x55 = YS-F4Pro,  0x48 0x37 = YS-H7Multi
        PosError    = 0x85, // 位置指令错误,当前正在运动状态.

    };
    Q_ENUM(ResponseCmd)



    BaseSerialComm *currentPort;   // 端口号

    void initComboBox_Config();
    void configPort();
    void showDeviceName(QByteArray &);
    void sendFrame(CtrlCmd cmd, quint32 param1, quint32 param2, quint32 param3);

private slots:
    void on_btnRefresh_clicked();
    void on_btnOpenPort_clicked(bool checked);
    void slots_errorHandler(QSerialPort::SerialPortError error);

    void slots_serialRxCallback();
    void on_btnConnect_clicked();

    void on_btnJogCtrl_pressed();

    void on_btnJogCtrl_released();

    void on_spdStart_clicked(bool checked);

    void on_spdStop_clicked();

private:
    Ui::StepperMotor *ui;
};

#endif // STEPPERMOTOR_H
