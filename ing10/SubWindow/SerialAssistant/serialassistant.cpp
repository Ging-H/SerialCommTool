#include "serialassistant.h"
#include "ui_serialassistant.h"
#include <QMessageBox>
#include <QDebug>
#include <QMetaEnum>
#include <QFileDialog>
#include <QTextCodec>
#include <QKeyEvent>
#include "sreialrx.h"
#include "newpushbutton.h"

bool SerialAssistant::openPort;      // 打开串口
bool SerialAssistant::rxPause ;      // 暂停接收
QString SerialAssistant::terminator; // 结束符 <NONE,CR,CR/LF,LF>
QString SerialAssistant::verifyType; // 校验码类型<NONE,ADD8,XOR8...>


SerialAssistant::SerialAssistant(QWidget *parent) :
    QWidget(parent),
     ui(new Ui::SerialAssistant)
{
    ui->setupUi(this);
    initComboBox_Config();
    currentPort = new BaseSerialComm; // 构建一个端口对象
//    rxTimer = NULL;  // 接收定时器
    saveFile = NULL; // 保存文件指针
    ui->txtSingle->setPlaceholderText( "硬石电子 携手合作,共创未来" " " "http://www.ing10bbs.com/" );
    connect(currentPort,SIGNAL(errorOccurred(QSerialPort::SerialPortError)),this,SLOT(slots_errorHandler(QSerialPort::SerialPortError)) );
    connect(this->ui->txtSingle,SIGNAL(cursorPositionChanged()),this,SLOT(slots_highlightLine()));


    connect(this->ui->btnMultiPush01,SIGNAL(clicked(bool)),this,SLOT(slots_multiSend()));
    connect(this->ui->btnMultiPush02,SIGNAL(clicked(bool)),this,SLOT(slots_multiSend()));
    connect(this->ui->btnMultiPush03,SIGNAL(clicked(bool)),this,SLOT(slots_multiSend()));
    connect(this->ui->btnMultiPush04,SIGNAL(clicked(bool)),this,SLOT(slots_multiSend()));
    connect(this->ui->btnMultiPush05,SIGNAL(clicked(bool)),this,SLOT(slots_multiSend()));
    connect(this->ui->btnMultiPush06,SIGNAL(clicked(bool)),this,SLOT(slots_multiSend()));
    connect(this->ui->btnMultiPush07,SIGNAL(clicked(bool)),this,SLOT(slots_multiSend()));
    connect(this->ui->btnMultiPush08,SIGNAL(clicked(bool)),this,SLOT(slots_multiSend()));
    connect(this->ui->btnMultiPush09,SIGNAL(clicked(bool)),this,SLOT(slots_multiSend()));
    connect(this->ui->btnMultiPush10,SIGNAL(clicked(bool)),this,SLOT(slots_multiSend()));


    ui->toolBox->setCurrentIndex(0);
}

SerialAssistant::~SerialAssistant()
{
    if(currentPort->isOpen()){
       currentPort->close();
    }
    delete currentPort;
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
    QString tmp = ui->cbbPortNum->currentText();

    tmp = tmp.split(" ").first();//  Item的 text 由 <COM1 "描述"> 组成,使用空格作为分隔符取第一段就是端口名

    // 当前串口处于关闭状态
    if(false == openPort ){
        currentPort->setPortName( tmp );              // 设置端口号
        if( currentPort->open(QIODevice::ReadWrite)){ // 打开串口
            openPort = true;
            /* 配置端口的波特率等参数 */
            configPort();
            connect(currentPort ,SIGNAL(readyRead()),this,SLOT( slots_serialRxCallback()));// 有数据就直接接收显示
            this->startRxTimer();// 如果打开了定时器,则使用定时器的超时时间进行接收现实

            ui->btnOpenPort->setText(tr("关闭串口"));
        }else{
            ui->btnOpenPort->setChecked(false);
        }
    }
    else{
        this->deleteRxTimer();
        this->deleteTxTimer();
        currentPort->close();
        openPort = false ;// 标记已经关闭串口
        ui->btnOpenPort->setText(tr("打开串口"));
    }
}
/* 配置端口的波特率\数据位\奇偶校验\停止位 */
void SerialAssistant::configPort()
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



/* 保存到文件 槽函数 */
void SerialAssistant::on_btnSaveFile_clicked()
{
    QString saveFilePath;
    /* 获取文件绝对路径 */
    if(ui->btnSaveFile->isChecked()){
        saveFilePath.clear();
        saveFilePath = QFileDialog::getOpenFileName(this, "Open File", NULL ,
                                                        "Files (*.txt *.log);;All (*.*)");
        if( NULL != saveFilePath){
            saveFile = new QFile(saveFilePath);
            saveFile->open(QIODevice::WriteOnly | QIODevice::WriteOnly);
            streamToSave = new QTextStream(saveFile);
            QMessageBox::information(NULL, tr("保存到文件"), saveFilePath, 0, 0);
            ui->btnSaveFile->setText(saveFilePath);
        }else{
            ui->btnSaveFile->setChecked(false);
        }
    }
    else if( NULL != saveFile) {
        saveFile->close();
        delete saveFile;
        delete streamToSave;
        saveFile = NULL;
        streamToSave = NULL;
        ui->btnSaveFile->setText("保存至文件...");
    }
}

void SerialAssistant::on_btnLoadFile_clicked()
{
//    QFile files;
//    files.open()
    QString loadFilePath = QFileDialog::getSaveFileName(this, "Save File", NULL ,
                                                    "Files (*.txt);;All (*.*)");

}
/* 设置光标到尾部 槽函数 */
void SerialAssistant::on_textBrower_textChanged()
{
    ui->textBrower->moveCursor(QTextCursor::End);
}


/* 插入空格,针对HEX显示的数据 */
QByteArray SerialAssistant::insertSpace(QByteArray &array)
{
    qint32 i(0);
    qint32 length = array.length();
    QByteArray ary;
    for(; i< length; i+=2)
    {
        ary += array.mid(i,2);
        ary += ' ';
    }
    return ary;
}
/* 发送按钮 槽函数 */
void SerialAssistant::on_btnSend_clicked()
{
    QByteArray txBuf;
    QString tmpString;
    if(openPort){
        if(ui->chbTxHex->isChecked() ){
            tmpString = ui->txtSingle->toPlainText().remove(QRegExp("\\s"));// delete ' '
            QByteArray tmpTest = tmpString.toLatin1();
            if(tmpTest.length() & 0x01 )
            {
                tmpTest.remove(tmpTest.length()-1, 1);
                QMessageBox::information(NULL, tr("不支持的输入"),  tr("请输入完整的字节"), 0, 0);
            }
            txBuf = QByteArray::fromHex(tmpTest); // ascii to hex

            tmpString = QString::fromLocal8Bit(txBuf );

            QByteArray tmpArray = txBuf.toHex().toUpper();
            tmpArray = this->insertSpace(tmpArray);
            ui->txtSingle->setPlainText(QString::fromLocal8Bit(tmpArray));
            ui->txtSingle->moveCursor(QTextCursor::End);
        }else{
            tmpString = ui->txtSingle->toPlainText();
            txBuf = tmpString.toLocal8Bit();
        }
        /* 显示发送字节数 */
        qint32 txBytes = currentPort->write(txBuf); // 发送数据
        qint32 tmp = ui->lbltxCnt->text().toInt();
        ui->lbltxCnt->setText(QString::number(tmp + txBytes));

        /* 显示发送数据 */
        if( ui->checkBox_5->checkState() ){// 加时间戳
            // Hex显示
            if( ui->chkDisplayHex->checkState() ){
                txBuf = txBuf.toHex().toUpper();
                txBuf = this->insertSpace(txBuf);
            }
            txBuf.insert(0, "[" + QTime::currentTime().toString("hh:mm:ss.zzz") + "]Tx: ");
            QString strToDisplay = QString::fromLocal8Bit(txBuf);
            ui->textBrower->appendPlainText(strToDisplay);
        }
    }
}


/* 接收串口数据 槽函数 */
void SerialAssistant::slots_serialRxCallback()
{
    QByteArray rxBuffer;
    qint32 rxBytes;
    QString strToDisplay;

    //接收数据
    rxBytes = currentPort->readData(rxBuffer);
    if( (0 != rxBytes) &&  !ui->btnPause->isChecked()) // 缓存非空并且没有暂停
    {
        // Hex显示
        if( ui->chkDisplayHex->checkState() ){
            rxBuffer = rxBuffer.toHex().toUpper();
            rxBuffer = this->insertSpace(rxBuffer);
        }
        // 加时间戳,分包显示
        if( ui->checkBox_5->checkState() ){
           rxBuffer.insert(0, "[" + QTime::currentTime().toString("hh:mm:ss.zzz") + "]Rx: ");
           strToDisplay = QString::fromLocal8Bit(rxBuffer);
           if( NULL != saveFile){
               streamToSave->operator << (strToDisplay) << endl;
           }else{
               ui->textBrower->appendPlainText(strToDisplay);
           }
        }else{
            strToDisplay = QString::fromLocal8Bit(rxBuffer);
            if( NULL != saveFile){
                streamToSave->operator << (strToDisplay);
            }else{
                ui->textBrower->insertPlainText(strToDisplay);
            }
        }
    }
    qint32 tmp = ui->lblrxCnt->text().toInt();
    ui->lblrxCnt->setText(QString::number(tmp + rxBytes));
}
/* 监控文本 槽函数 */
void SerialAssistant::on_txtSingle_textChanged()
{
    if(ui->chbTxHex->isChecked() ){
        bool isMatch = true;
        QRegExp regExp("[a-f0-9A-F ]*");

        isMatch = regExp.exactMatch(ui->txtSingle->toPlainText());

        if(!isMatch){// TODO:封装成函数
            QString tmp;
            disconnect(this->ui->txtSingle,SIGNAL(textChanged()),this,SLOT(on_txtSingle_textChanged()));
            tmp = ui->txtSingle->toPlainText();
            tmp.replace(QRegExp("[^a-f0-9A-F ]") ,"");
            ui->txtSingle->setPlainText(tmp);
            ui->txtSingle->moveCursor(QTextCursor::End);
            QMessageBox::information(NULL, tr("不支持输入"),  tr("只支持[0~9],[a~f],[A~F]和空格的输入"), 0, 0);
            connect(this->ui->txtSingle,SIGNAL(textChanged()),this,SLOT(on_txtSingle_textChanged()));
        }
    }
}

/* 串口错误信息处理 */
void SerialAssistant::slots_errorHandler(QSerialPort::SerialPortError error)
{
    switch(error){
    case QSerialPort::DeviceNotFoundError:QMessageBox::information(NULL, tr("未找到设备"),  tr("检查设备是否已经连接"), 0, 0);
        break;
    case QSerialPort::OpenError:
    case QSerialPort::PermissionError:QMessageBox::information(NULL, tr("打开失败"),  tr("检查设备是否已被占用"), 0, 0);
        break;
    default:break;
    }

}

void SerialAssistant::startRxTimer()
{
    /* 勾选"加时间戳"和打开串口都会调用这个函数 */
    /* 只有在两个都有效的情况下才会启动定时器 */
    if(openPort ){
        disconnect(currentPort ,SIGNAL(readyRead()),0,0);
        connect(currentPort ,SIGNAL(readyRead()),this,SLOT( slots_serialRxCallback()));
        if(ui->checkBox_5->isChecked()){
            rxTimer.setTimerType(Qt::PreciseTimer );
            disconnect(currentPort ,SIGNAL(readyRead()),0,0);
            connect(&rxTimer,SIGNAL(timeout()),this,SLOT(slots_serialRxCallback()));
            rxTimer.start(10);// 10ms扫描一次串口
        }
    }
}

void SerialAssistant::deleteRxTimer()
{
    /* 停止定时器 */
    if(rxTimer.isActive()){
        disconnect(&rxTimer ,SIGNAL(timeout()),0,0);
        connect(currentPort ,SIGNAL(readyRead()),this,SLOT( slots_serialRxCallback()));
        rxTimer.stop();
    }
}
void SerialAssistant::slots_highlightLine()
{
    QList<QTextEdit::ExtraSelection> extraSelections;//提供一种方式显示选择的文本
    QTextEdit::ExtraSelection selection;

    selection.format.setBackground(QColor(Qt::gray).lighter(145));        // 设置背景颜色和亮度
    selection.format.setProperty(QTextFormat::FullWidthSelection, true); // 选择当前行所有像素
    selection.cursor = ui->txtSingle->textCursor();                      // 高亮当前行
    extraSelections.append(selection);
    ui->txtSingle->setExtraSelections(extraSelections);                  //设置高亮
}

void SerialAssistant::on_chbTimedTx_clicked(bool checked)
{
    if(checked){
        this->startTxTimer();

    }else{
        this->deleteTxTimer();
    }

}
void SerialAssistant::startTxTimer()
{
    if(openPort ){
        txTimer.setTimerType(Qt::PreciseTimer );
        qint32 tmp = ui->spbTxInterval->value();
        txTimer.start(tmp);
        connect(&txTimer,SIGNAL(timeout()),this,SLOT(slots_timeOutTx()));
    }
}
void SerialAssistant::deleteTxTimer()
{
    /* 停止定时器 */
    if(txTimer.isActive()){
        txTimer.stop();
        disconnect(&txTimer,SIGNAL(timeout()),this,SLOT(slots_timeOutTx()));
    }
}

/* 加时间戳 槽函数 */
void SerialAssistant::on_checkBox_5_clicked(bool checked)
{
    if(checked){
        this->startRxTimer();
    }else {
        this->deleteRxTimer();
    }
}
/* 超时发送 槽函数 */
void SerialAssistant::slots_timeOutTx()
{
    qint32 index(0);
    if(openPort){
        index = ui->toolBox->currentIndex();
        switch(index ){
        case 0:
            this->on_btnSend_clicked();// 发送单条数据,与点击"发送"按钮功能一致
            break;
        case 1://TODO:定时发送
            // multiSend( index);
            // 定时进入
            // 点击按钮动作:进入一个函数,然后调用 multiSend( index),index就是点击的按钮序号
            // 代码优化:使用函数整合功能的实现
            break;
        }
    }
}
//QPushButton
void SerialAssistant::slots_multiSend()
{
    QPushButton *btn = (QPushButton*) sender();
    if(openPort){
        qint32 btnNum= btn->text().toInt();
        QString tmpString;
        switch (btnNum) {
        case 1: // button 1
            tmpString = ui->txtLine01->text();
            break;
        case 2: // button 2
            tmpString = ui->txtLine02->text();
            break;
        case 3: // button 3
            tmpString = ui->txtLine03->text();
            break;
        case 4: // button 4
            tmpString = ui->txtLine04->text();
            break;
        case 5: // button 5
            tmpString = ui->txtLine05->text();
            break;
        case 6: // button 6
            tmpString = ui->txtLine06->text();
            break;
        case 7: // button 7
            tmpString = ui->txtLine07->text();
            break;
        case 8: // button 8
            tmpString = ui->txtLine08->text();
            break;
        case 9: // button 9
            tmpString = ui->txtLine09->text();
            break;
        case 10:// button 10
            tmpString = ui->txtLine10->text();
            break;
        default:
            break;
        }
        // TODO:封装成函数
        QByteArray txBuf ;
        if(ui->chbTxHex->isChecked() ){
            tmpString = tmpString.remove(QRegExp("\\s"));// delete ' '
            QByteArray tmpTest = tmpString.toLatin1();
            if(tmpTest.length() & 0x01 )
            {
                tmpTest.remove(tmpTest.length()-1, 1);
                QMessageBox::information(NULL, tr("不支持的输入"),  tr("请输入完整的字节"), 0, 0);
            }
            txBuf = QByteArray::fromHex(tmpTest); // ascii to hex
        }else{
            txBuf = tmpString.toLocal8Bit();
        }
        currentPort->write(txBuf);
    }
}
void SerialAssistant::on_spbTxInterval_editingFinished()
{
    if(txTimer.isActive()){
        qint32 tmp = ui->spbTxInterval->value();
        txTimer.setInterval( tmp );
    }
}


void SerialAssistant::on_chbTxHex_clicked(bool checked)
{
    // TODO:检查原有的字符串是否符合表达式,不符合则清空,符合则保留
    QRegExp regExp("[a-f0-9A-F ]+");
    if(checked){
        ui->txtLine01->setValidator(new QRegExpValidator(regExp,this));
        ui->txtLine02->setValidator(new QRegExpValidator(regExp,this));
        ui->txtLine03->setValidator(new QRegExpValidator(regExp,this));
    }else{
        ui->txtLine01->setValidator(0);
        ui->txtLine02->setValidator(0);
        ui->txtLine03->setValidator(0);
    }

}
