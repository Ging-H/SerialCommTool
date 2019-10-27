#ifndef SERIALASSISTANT_H
#define SERIALASSISTANT_H

#include <QWidget>
#include <QSerialPortInfo>
#include "baseserialcomm.h"

namespace Ui {
class SerialAssistant;
}

class SerialAssistant : public QWidget
{
    Q_OBJECT

public:
    explicit SerialAssistant(QWidget *parent = 0);
    ~SerialAssistant();

    static bool openPort;      // 打开串口
    static bool rxPause ;      // 暂停接收
    static QString terminator; // 结束符    <NONE,CR,CR/LF,LF>
    static QString verifyType; // 校验码类型 <NONE,ADD8,XOR8...>

    void initComboBox_Config();    // 初始化串口配置的下拉列表(ComboBox)
    BaseSerialComm *currentPort;   // 端口号

private slots:
    void on_btnOpenPort_clicked();

    void on_btnRefresh_clicked();

    void on_chkFlowCtrlDTR_toggled(bool checked);

    void on_chkFlowCtrlRTS_toggled(bool checked);

    void on_btnClear_clicked();

    void on_btnSaveFile_clicked();

    void on_btnLoadFile_clicked();

private:
    Ui::SerialAssistant *ui;
};

#endif // SERIALASSISTANT_H
