#include "serialassistant.h"
#include "ui_serialassistant.h"
#include <QMessageBox>
#include <QDebug>
#include <QMetaEnum>
#include <QFileDialog>


bool SerialAssistant::openPort;      // 打开串口
bool SerialAssistant::rxPause ;      // 暂停接收
QString SerialAssistant::terminator; // 结束符 <NONE,CR,CR/LF,LF>
QString SerialAssistant::verifyType; // 校验码类型<NONE,ADD8,XOR8...>


// TODO: 开两个线程用于接收和发送
SerialAssistant::SerialAssistant(QWidget *parent) :
    QWidget(parent),
     ui(new Ui::SerialAssistant)
{
    ui->setupUi(this);
    initComboBox_Config();
    currentPort = new BaseSerialComm; // 构建一个端口对象
}

SerialAssistant::~SerialAssistant()
{
    delete ui;
}

/*
 *  初始化了串口设置当中的下拉列表(ComboBox)
 *
 */
void SerialAssistant::initComboBox_Config()
{
    /* 更新下拉列表 */
    BaseSerialComm::listBaudRate( ui -> cbbBaud    );
    BaseSerialComm::listDataBit ( ui -> cbbDataBit );
    BaseSerialComm::listVerify  ( ui -> cbbVerify  );
    BaseSerialComm::listStopBit ( ui -> cbbStopBit );
    BaseSerialComm::listPortNum ( ui -> cbbPortNum );
}

/*
 *  打开并配置串口
 *
 */
void SerialAssistant::on_btnOpenPort_clicked()
{
    QVariant tmpVariant;
    QString tmp = ui->cbbPortNum->currentText();

    tmp = tmp.split(" ").first();//  Item的 text 由 "COM1 描述" 组成,使用空格作为分隔符取第一段就是端口名

    // 当前串口处于关闭状态
    if(false == openPort ){
        currentPort->setPortName( tmp );              // 设置端口号
        if( currentPort->open(QIODevice::ReadWrite)){ // 打开串口

            tmpVariant = ui->cbbBaud->currentData();  // 读取控件的当前项的值
            currentPort->setBaudRate(tmpVariant.value < BaseSerialComm::BaudRate > ()  );// 设置波特率

            tmpVariant = ui->cbbDataBit->currentData();
            currentPort->setDataBits( tmpVariant.value <BaseSerialComm::DataBits > () );

            tmpVariant = ui->cbbVerify->currentData();
            currentPort->setParity (tmpVariant.value < BaseSerialComm::Parity > () );

            tmpVariant = ui->cbbStopBit->currentData();// 某些情况不支持1.5停止位
            if(currentPort->setStopBits (tmpVariant.value < BaseSerialComm::StopBits > () ) == false ){
                QMessageBox::information(NULL, "不支持的设置",  "该串口设备不支持当前停止位设置", 0, 0);
            }

            openPort = true;// 标记已经打开串口
            ui->btnOpenPort->setText("关闭串口");
        }
    }
    else{
        currentPort->close();
        openPort = false ;// 标记已经关闭串口
        ui->btnOpenPort->setText("打开串口");
    }
}

/* 刷新按钮点击 槽函数 */
void SerialAssistant::on_btnRefresh_clicked()
{
    if(openPort == false){  // 关闭串口才能刷新端口号
        ui -> cbbPortNum ->clear();
        BaseSerialComm::listPortNum ( ui -> cbbPortNum );
    }
}

/* DTR翻转 槽函数 */
// TODO:没有经过验证
void SerialAssistant::on_chkFlowCtrlDTR_toggled(bool checked)
{
    /* 确保已经打开串口才动作 */
    if(openPort == true){
        currentPort -> setDTRState(checked);
    }
}
/* RTS翻转 槽函数 */
// TODO:没有经过验证
void SerialAssistant::on_chkFlowCtrlRTS_toggled(bool checked)
{
    /* 确保已经打开串口才动作 */
    if(openPort == true){
        currentPort -> setRTSState(checked);
    }
}

/* 清空接收文本框 槽函数 */
void SerialAssistant::on_btnClear_clicked()
{
    ui->textBrower->clear();
}



void SerialAssistant::on_btnSaveFile_clicked()
{
    /* 获取文件绝对路径 */
    QString fileName = QFileDialog::getOpenFileName(this, "Open File", NULL ,
                                                    "Files (*.txt *.bin *.hex *.ini);;All (*.*)");
}

void SerialAssistant::on_btnLoadFile_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save File", NULL ,
                                                    "Files (*.txt *.bin *.hex *.ini);;All (*.*)");

}
