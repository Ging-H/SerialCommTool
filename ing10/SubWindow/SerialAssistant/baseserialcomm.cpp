#include "baseserialcomm.h"

#include <QMessageBox>
#include <QMetaEnum>
#include <QDebug>

BaseSerialComm::BaseSerialComm(QSerialPort *parent) : QSerialPort(parent)
{
}

/* BaudRate 波特率 在控件中列出支持的波特率 */
void BaseSerialComm::listBaudRate(QComboBox *cbbBaud)
{
    QMetaEnum mtaEnum = QMetaEnum::fromType<BaseSerialComm::BaudRate>();
    QString tmp;
    for (int i = 0; i < mtaEnum.keyCount(); i++) {
        tmp = QString::number(mtaEnum.value(i));
        cbbBaud->addItem(tmp, mtaEnum.value(i));
//        qDebug() << tmp;
        /* 删除未知值 */
        if(mtaEnum.value(i)== BaseSerialComm::BaudRate::UnknownBaud ){
            cbbBaud->removeItem(i);
        }
    }
    cbbBaud->setCurrentText("115200"); // 设定默认值
}

void BaseSerialComm::listDataBit(QComboBox *cbbDataBit)
{

    QString tmp;
    QMetaEnum mtaEnum = QMetaEnum::fromType<BaseSerialComm::DataBits>();
    for (int i = 0; i < mtaEnum.keyCount(); i++) {
        tmp = QString::number(mtaEnum.value(i));
        cbbDataBit->addItem(tmp, mtaEnum.value(i));
        /* 删除未知值 */
        if(mtaEnum.value(i) == BaseSerialComm::DataBits::UnknownDataBits )
            cbbDataBit->removeItem(i);
    }
    cbbDataBit->setCurrentText("8"); // 设定默认值
}


/* Parity 校验*/
void BaseSerialComm::listVerify(QComboBox *cbbVerify)
{
    /* 获取枚举元信息,并且与下拉列表 cbbVerify的item 绑定 */
    QMetaEnum mtaEnum = QMetaEnum::fromType<QSerialPort::Parity>();
    for (int i = 0; i < mtaEnum.keyCount(); i++) { // 遍历每个枚举值,获得text和data,添加到item中
        cbbVerify->addItem(mtaEnum.key(i), mtaEnum.value(i));
        /* 删除未知值 */
        if(mtaEnum.value(i) == BaseSerialComm::Parity::UnknownParity )
            cbbVerify->removeItem(i);
    }
    cbbVerify->setCurrentText("NoParity"); // 设定默认值
}

/* StopBits 停止位 */
void BaseSerialComm::listStopBit(QComboBox *cbbStopBit)
{
    /* StopBits 停止位 */
    QMetaEnum mtaEnum = QMetaEnum::fromType < BaseSerialComm::StopBits >();
    QString tmp;
    for (int i = 0; i < mtaEnum.keyCount(); i++) {
        tmp = QString::number(mtaEnum.value(i));
        if(mtaEnum.value(i) == 3)
            tmp = "1.5";  // 用3表示1.5个停止位
        cbbStopBit->addItem(tmp, mtaEnum.value(i));

        /* 删除未知值 */
        if(mtaEnum.value(i) == BaseSerialComm::StopBits::UnknownStopBits )
            cbbStopBit->removeItem(i);
    }
    cbbStopBit->setCurrentText("1"); // 设定默认值
}



/* 更新 端口号 控件 */
void BaseSerialComm::listPortNum(QComboBox *cbbPortNum)
{
    QStringList portList;
    qint32 len = 0;   // list中最大的字符宽度

    portList.clear(); // 清空列表
    searchPort(portList);                      // 搜索可用的串口和描述
    if(portList.empty() == false){
        cbbPortNum->addItems(portList);    // 添加到ComboBox
        foreach(const QString &item, portList) // 遍历list每一项
        {
            if(len < item.toLocal8Bit().length() ) // 获取字符宽度
                len = item.toLocal8Bit().length();
        }
        qint32 fontSize = cbbPortNum->font().pointSize(); // 获取所用字体大小
        cbbPortNum->view()->setFixedWidth( len * fontSize * 0.75 ); // 调整显示宽度,字符数*字符宽度*0.75

    }
    else{
        QMessageBox::information(NULL, "无串口设备",  "没有搜索到串口设备", 0, 0);
    }
}


/* 搜索端口号,返回串口列表 */
void BaseSerialComm::searchPort(QStringList &portList)
{
    portList.clear();
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()){
        portList << info.portName() + " " + info.description();
    }
}

/* 设置DTR状态 */
void BaseSerialComm::setDTRState(bool set)
{
    this->setDataTerminalReady(set);
}

/* 设置RTS状态 */
void BaseSerialComm::setRTSState(bool set)
{
    this->setRequestToSend(set);
}

/* 读取串口缓存中的数据 ,返回0代表没有接收到数据*/
qint32 BaseSerialComm::readData(QByteArray &rxBuffer)
{
    rxBuffer = this->readAll();
    if(rxBuffer.isEmpty()){
        return 0;
    }
    else {
        return rxBuffer.length();
    }
}

/* 往串口写入数据 */
/* 返回-1代表写入错误*/
qint32 BaseSerialComm::writtenData(QString txBuffer)
{
    QByteArray tmpBuffer = txBuffer.toLatin1();
    return this->write(tmpBuffer);
}
