#include "serialassistant.h"
#include "ui_serialassistant.h"
#include "baseserialcomm.h"
#include <QMessageBox>
#include <QDebug>
#include <QMetaEnum>

SerialAssistant::GlobleFlag_Typedef flag = {false,false,0,0}; // 全局变量

SerialAssistant::SerialAssistant(QWidget *parent) :
    QWidget(parent),
     ui(new Ui::SerialAssistant)
{
    ui->setupUi(this);


    QStringList list;

    /* 获取枚举元信息,并且与下拉列表 cbbVerify的item 绑定 */
    QMetaEnum mtaEnum = QMetaEnum::fromType<QSerialPort::Parity>();

    /* Parity 校验 */
    for (int i = 0; i < mtaEnum.keyCount(); i++) { // 遍历每个枚举值,获得text和data,添加到item中
        ui->cbbVerify->addItem(mtaEnum.key(i), mtaEnum.value(i));
        /* 删除未知值 */
        if(mtaEnum.value(i) == QSerialPort::Parity::UnknownParity )
            ui->cbbVerify->removeItem(i);
    }
    ui->cbbVerify->setCurrentText("NoParity"); // 设定默认值


    /* BaudRate 波特率 */
    mtaEnum = QMetaEnum::fromType<QSerialPort::BaudRate>();
    QString tmp;
    for (int i = 0; i < mtaEnum.keyCount(); i++) {
        tmp = QString::number(mtaEnum.value(i));
        ui->cbbBaud->addItem(tmp, mtaEnum.value(i));
        /* 删除未知值 */
        if(mtaEnum.value(i) == QSerialPort::BaudRate::UnknownBaud )
            ui->cbbBaud->removeItem(i);
    }

    ui->cbbBaud->setCurrentText("115200"); // 设定默认值

/* 使用方法如下,可以获得item的text对应的data,也就是115200,之所以不直接使用
 * ui->cbbBaud->currentText().toInt() 是因为考虑个别下拉列表控件的text与data不一致
 */
//  qDebug() << ui->cbbBaud->itemData( ui->cbbBaud->currentIndex() ).toInt();


    /* DataBits 数据位 */
    mtaEnum = QMetaEnum::fromType<QSerialPort::DataBits>();
    for (int i = 0; i < mtaEnum.keyCount(); i++) {
        tmp = QString::number(mtaEnum.value(i));
        ui->cbbDataBit->addItem(tmp, mtaEnum.value(i));
        /* 删除未知值 */
        if(mtaEnum.value(i) == QSerialPort::DataBits::UnknownDataBits )
            ui->cbbDataBit->removeItem(i);
    }
    ui->cbbDataBit->setCurrentText("8"); // 设定默认值


    /* StopBits 停止位 */
    mtaEnum = QMetaEnum::fromType<QSerialPort::StopBits>();
    for (int i = 0; i < mtaEnum.keyCount(); i++) {
        tmp = QString::number(mtaEnum.value(i));
        if(mtaEnum.value(i) == 3)
            tmp = "1.5";  // 用3表示1.5个停止位
        ui->cbbStopBit->addItem(tmp, mtaEnum.value(i));

        /* 删除未知值 */
        if(mtaEnum.value(i) == QSerialPort::StopBits::UnknownStopBits )
            ui->cbbStopBit->removeItem(i);
    }
    ui->cbbStopBit->setCurrentText("1"); // 设定默认值

}

SerialAssistant::~SerialAssistant()
{
    delete ui;
}


/* 打开并配置串口 */
void SerialAssistant::on_btnOpenPort_clicked()
{
    QSerialPort *currentPort = new QSerialPort();



//    QSerialPort::DataBits;



    QMessageBox::information(NULL, "Title",  "Content", 0, 0);
    // 当前串口处于关闭状态
    if(false == flag.OpenPort ){
        currentPort->setPortName( ui->cbbPortNum->currentText());
        if( currentPort->open(QIODevice::ReadWrite)){
//            currentPort->setBaudRate(ui->cbbBaud->currentText().toInt());
//            currentPort->setDataBits(dataBits);


        }


    }




    flag.OpenPort = true;// 标记打开串口

}
