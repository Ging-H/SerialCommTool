#ifndef SERIALASSISTANT_H
#define SERIALASSISTANT_H

#include <QWidget>
#include <QSerialPort>
#include <QSerialPortInfo>

namespace Ui {
class SerialAssistant;
}

class SerialAssistant : public QWidget
{
    Q_OBJECT

public:
    explicit SerialAssistant(QWidget *parent = 0);
    ~SerialAssistant();

    typedef struct {
        bool OpenPort;     // 打开串口
        bool RxPause;      // 暂停
        QString Terminator;// 结束符 <NONE,CR,CR/LF,LF>
        qint32 VerifyType; // 校验码类型<NONE,ADD8,XOR8...>
    }GlobleFlag_Typedef;

private slots:
    void on_btnOpenPort_clicked();

private:
    Ui::SerialAssistant *ui;
};

#endif // SERIALASSISTANT_H
