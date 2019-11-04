#ifndef SERIALASSISTANT_H
#define SERIALASSISTANT_H

#include <QWidget>
#include <QSerialPortInfo>
#include "baseserialcomm.h"
#include <QTimer>
#include <QTime>
#include <QFile>
#include <QTextStream>

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
    QTimer rxTimer; // 接收用的定时器
    QTimer txTimer; // 发送用的定时器

    QFile   *saveFile;
    QFile   *loadFile;
    QTextStream *streamToSave;

    BaseSerialComm *currentPort;   // 端口号

    void initComboBox_Config();    // 初始化串口配置的下拉列表(ComboBox)
//    void insertSpace(QByteArray &array);
    QByteArray insertSpace(QByteArray &array);
    void configPort();
    void deleteRxTimer();
    void startRxTimer();
    void deleteTxTimer();
    void startTxTimer();



public slots:
    void slots_serialRxCallback();
    void slots_errorHandler(QSerialPort::SerialPortError error);
    void slots_highlightLine();
    void slots_timeOutTx();
    void slots_multiSend();

private slots:
    void on_btnOpenPort_clicked();

    void on_btnRefresh_clicked();

    void on_chkFlowCtrlDTR_toggled(bool checked);

    void on_chkFlowCtrlRTS_toggled(bool checked);

    void on_btnSaveFile_clicked();

    void on_btnLoadFile_clicked();

    void on_textBrower_textChanged();

    void on_btnSend_clicked();

    void on_txtSingle_textChanged();

    void on_chbTimedTx_clicked(bool checked);

    void on_checkBox_5_clicked(bool checked);

    void on_spbTxInterval_editingFinished();
//    void on_btnMultiPush01_clicked();

    void on_chbTxHex_clicked(bool checked);

private:
    Ui::SerialAssistant *ui;
};

#endif // SERIALASSISTANT_H
