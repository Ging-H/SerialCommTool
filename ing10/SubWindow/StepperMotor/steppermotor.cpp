#include "steppermotor.h"
#include "ui_steppermotor.h"
#include <QMessageBox>
#include <qDebug>
#include <QtEndian>

StepperMotor::StepperMotor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StepperMotor)
{
    ui->setupUi(this);
    initComboBox_Config();
    currentPort = new BaseSerialComm ();       // 当前的串口
    /* 串口错误信息处理 */
    connect(currentPort,SIGNAL(errorOccurred(QSerialPort::SerialPortError)),this,SLOT(slots_errorHandler(QSerialPort::SerialPortError)) );
}

StepperMotor::~StepperMotor()
{
    delete ui;
}
/*
 *  初始化了串口设置当中的下拉列表(ComboBox)
 *
 */
void StepperMotor::initComboBox_Config()
{
    /* 更新下拉列表 */
    BaseSerialComm::listBaudRate( ui -> cbbBaud    );
    BaseSerialComm::listDataBit ( ui -> cbbDataBit );
    BaseSerialComm::listVerify  ( ui -> cbbVerify  );
    BaseSerialComm::listStopBit ( ui -> cbbStopBit );
    BaseSerialComm::listPortNum ( ui -> cbbPortNum );
}
/* 刷新按钮点击 槽函数 */
void StepperMotor::on_btnRefresh_clicked()
{
    if( !ui->btnOpenPort->isChecked()){  // 关闭串口才能刷新端口号
        ui -> cbbPortNum ->clear();
        BaseSerialComm::listPortNum ( ui -> cbbPortNum );
    }
}

void StepperMotor::on_btnOpenPort_clicked(bool checked)
{
    QString tmp = ui->cbbPortNum->currentText();
    tmp = tmp.split(" ").first();//  Item的 text 由 <COM1 "描述"> 组成,使用空格作为分隔符取第一段就是端口名
    if(checked){
        // 当前串口处于关闭状态
        currentPort->setPortName( tmp );              // 设置端口号
        if( currentPort->open(QIODevice::ReadWrite)){ // 打开串口
            currentPort -> setDTRState(false);
            currentPort -> setRTSState(false);
            /* 配置端口的波特率等参数 */
                this->configPort();
                connect(currentPort ,SIGNAL(readyRead()),this,SLOT( slots_serialRxCallback()));// 有数据就直接接收显示
            ui->btnOpenPort->setText(tr("关闭串口"));
        }else{
            ui->btnOpenPort->setChecked(false);
        }

    }
    else{
        currentPort->close();
        ui->btnOpenPort->setText(tr("打开串口"));
    }
}
/* 配置端口的波特率\数据位\奇偶校验\停止位 */
void StepperMotor::configPort()
{
    QVariant tmpVariant;
    /* 设置波特率 */
    tmpVariant = ui->cbbBaud->currentData();  // 读取控件的当前项的值
    currentPort->setBaudRate(tmpVariant.value < BaseSerialComm::BaudRate > ()  );

    /* 设置数据位 */
    tmpVariant = ui->cbbDataBit->currentData();
    currentPort->setDataBits( tmpVariant.value <BaseSerialComm::DataBits > () );

    /* 设置校验位 */
    tmpVariant = ui->cbbVerify->currentData();
    currentPort->setParity (tmpVariant.value < BaseSerialComm::Parity > () );

    /* 设置停止位 */
    tmpVariant = ui->cbbStopBit->currentData();// 某些情况不支持1.5停止位
    if(currentPort->setStopBits (tmpVariant.value < BaseSerialComm::StopBits > () ) == false ){
        ui -> cbbStopBit->clear();
        BaseSerialComm::listStopBit ( ui -> cbbStopBit );
        QMessageBox::information(NULL, tr("不支持的设置"),  tr("该串口设备不支持当前停止位设置,已修改为默认的设置"), 0, 0);
    }
}
/* 串口错误信息处理 */
void StepperMotor::slots_errorHandler(QSerialPort::SerialPortError error)
{
    switch(error){
    case QSerialPort::DeviceNotFoundError:QMessageBox::information(NULL, tr("未找到设备"),  tr("检查设备是否已经连接,或者是否正常供电"), 0, 0);
        break;
    case QSerialPort::OpenError:
    case QSerialPort::PermissionError:QMessageBox::information(NULL, tr("打开失败"),  tr("检查设备是否已被其他软件占用"), 0, 0);
        break;
    default:
        break;
    }
}
/* 串口数据接收回调函数 */ // TODO:
void StepperMotor::slots_serialRxCallback()
{
    QByteArray rxbuf;

    rxbuf = currentPort->readAll();
    qint32 indexOfAA = rxbuf.indexOf(0xAA);
    if((rxbuf.contains(0xAA)) && (rxbuf.contains('/')) ){
        switch( (quint8)rxbuf.at( indexOfAA + 1 ) ){
        case 0x84:
            this->showDeviceName(rxbuf);
            break;
        case 0x80:

            break;
        case 0x85:
            QMessageBox::information(NULL, tr("接收到反馈信息"),  rxbuf.toHex(' '), 0, 0);// 位置指令出错.
            break;
        default:
            break;
        }
    }
}

void StepperMotor::showDeviceName(QByteArray &rxbuf)
{
    qint32 indexOfAA = rxbuf.indexOf(0xAA);
    qint32 indexOfCS = rxbuf.indexOf('/') - 1 ;
    quint8 cs = rxbuf.at( indexOfCS ); // 记录校验码
    currentPort->insertVerify(rxbuf, rxbuf.indexOf(0x84)+1, 2, BaseSerialComm::ADD8);// 计算校验码
    quint8 csNew = (rxbuf.at( indexOfCS) );
    if( csNew == cs){ // 校验码核对
        QString deviceName= rxbuf.mid( indexOfAA+2, 2 );
        if(  deviceName == "H7" )
            ui->lblDeviceName->setText("YS-H7Multi/YS-H7Core");
        else if(deviceName == "UU" )
            ui->lblDeviceName->setText("YS-F4Pro");
    }
}

// Tx:AA 04 55 55 55 55 55 55 55 55 55 55 55 55 00 2F // 响应测试
void StepperMotor::on_btnConnect_clicked()
{
    sendFrame(GetDevice, 0, 0, 0);
}

void StepperMotor::on_btnJogCtrl_pressed()
{
    union FloatToInt{
        float   floatNum;
        quint32 intNum;
    }floatToInt;
    floatToInt.floatNum = (float)ui->spbJogSpd->value()/60.0f;
    sendFrame(SetSpeed, floatToInt.intNum , 0, 0);
    sendFrame(JogCtrl, 1, 0, 0);
}


void StepperMotor::on_btnJogCtrl_released()
{
    sendFrame(JogCtrl, 0, 0, 0);
}


void StepperMotor::on_spdStart_clicked(bool checked)
{
    if(checked){
        sendFrame(ModeSelect, 0x01, 0, 0);// mode select speed

    }else{
        sendFrame(ModeSelect, 0x00, 0, 0);// mode select none
    }
}
void StepperMotor::on_spdStop_clicked()
{
    sendFrame(SetSpeed, 0, 0, 0); // set speed 0 rpm
}

void StepperMotor::sendFrame(CtrlCmd cmd, quint32 param1, quint32 param2, quint32 param3)
{
    QByteArray txBuf(12,0x55);
    txBuf.prepend(cmd);
    param3 = param3;
    switch(cmd){
    case ModeSelect:
        txBuf[1] = (quint8)param1;
        currentPort->insertVerify(txBuf, 1, 0, BaseSerialComm::ADD8 ); //
        txBuf.append('/');
        txBuf.prepend(0xAA);
        currentPort->write(txBuf);
        break;
    case JogCtrl:
        if(param1 != 0) {
            txBuf[1] = 0x01;
        }else txBuf[1] = 0x00;
        currentPort->insertVerify(txBuf, 1, 0, BaseSerialComm::ADD8 ); //
        txBuf.append('/');
        txBuf.prepend(0xAA);
        currentPort->write(txBuf);
        break;
    case SetSpeed:
        param2 = qToBigEndian(param1);// 传输数据是高位字节在前
        txBuf.replace(1, 4, (const char*)&param2, sizeof(param2));     // 4个字节
        currentPort->insertVerify(txBuf, 1, 0, BaseSerialComm::ADD8 ); //
        txBuf.append('/');
        txBuf.prepend(0xAA);
        currentPort->write(txBuf);
        break;
    case GetDevice:
        currentPort->insertVerify(txBuf, 1, 0, BaseSerialComm::ADD8 ); //
        txBuf.append('/');
        txBuf.prepend(0xAA);
        currentPort->write(txBuf);
        break;
    default:break;
    }
}






