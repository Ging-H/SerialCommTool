#include "serialassistant.h"
#include "ui_serialassistant.h"
#include <QMessageBox>
#include <QDebug>
#include <QMetaEnum>
#include <QFileDialog>
#include <QTextCodec>
#include <QKeyEvent>
#include "sreialrx.h"
bool SerialAssistant::openPort;      // 打开串口
//bool SerialAssistant::rxPause ;      // 暂停接收
//QString SerialAssistant::terminator; // 结束符 <NONE,CR,CR/LF,LF>
//QString SerialAssistant::verifyType; // 校验码类型<NONE,ADD8,XOR8...>

//TODO: 发送 添加数据校验码,添加结束符
//      加载,发送文件
//      统计发送文件的进度
//      将部分函数转移到serialcomm.cpp

//QTime timerTest; // 可用于测试运行时间

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

    /* 将多个按钮组合起来 */
    multiPushButton.push_back(ui->btnMultiPush01);
    multiPushButton.push_back(ui->btnMultiPush02);
    multiPushButton.push_back(ui->btnMultiPush03);
    multiPushButton.push_back(ui->btnMultiPush04);
    multiPushButton.push_back(ui->btnMultiPush05);
    multiPushButton.push_back(ui->btnMultiPush06);
    multiPushButton.push_back(ui->btnMultiPush07);
    multiPushButton.push_back(ui->btnMultiPush08);
    multiPushButton.push_back(ui->btnMultiPush09);
    multiPushButton.push_back(ui->btnMultiPush10);
    foreach (QPushButton *MultiPush, multiPushButton) { // 链接点击信号到一个函数
        connect(MultiPush,SIGNAL(clicked(bool)),this,SLOT(slots_multiSend()));
    }

    /* 将多条文本组合起来 */
    multiTxtLine.push_back(ui->txtLine01);
    multiTxtLine.push_back(ui->txtLine02);
    multiTxtLine.push_back(ui->txtLine03);
    multiTxtLine.push_back(ui->txtLine04);
    multiTxtLine.push_back(ui->txtLine05);
    multiTxtLine.push_back(ui->txtLine06);
    multiTxtLine.push_back(ui->txtLine07);
    multiTxtLine.push_back(ui->txtLine08);
    multiTxtLine.push_back(ui->txtLine09);
    multiTxtLine.push_back(ui->txtLine10);

    /* 将多个CheckBox组合起来 */
    multiCheckBox.push_back(ui->chkMulti01);
    multiCheckBox.push_back(ui->chkMulti02);
    multiCheckBox.push_back(ui->chkMulti03);
    multiCheckBox.push_back(ui->chkMulti04);
    multiCheckBox.push_back(ui->chkMulti05);
    multiCheckBox.push_back(ui->chkMulti06);
    multiCheckBox.push_back(ui->chkMulti07);
    multiCheckBox.push_back(ui->chkMulti08);
    multiCheckBox.push_back(ui->chkMulti09);
    multiCheckBox.push_back(ui->chkMulti10);

    disconnect(this->ui->txtSingle,SIGNAL(textChanged()),this,SLOT(on_txtSingle_textChanged()));


//    timerTest.start();

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
            this->startRxTimer();// 如果打开了定时器,则使用定时器的超时时间进行接收显示

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
        txBuf = this->stringToSend(ui->txtSingle->toPlainText(),ui->chbTxHex->isChecked());
        /* 显示发送字节数 */
        qint32 txBytes = currentPort->write(txBuf); // 发送数据
        qint32 tmp = ui->lbltxCnt->text().toInt();
        ui->lbltxCnt->setText(QString::number(tmp + txBytes));

        /* 显示发送数据 */
        if( ui->checkBox_5->checkState() ){// 加时间戳
            this->displayTxBuffer(txBuf);
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
        bool  isMatch = this->isHexString(ui->txtSingle->toPlainText());

        if(!isMatch){
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
/* 启动接收控制定时器 */
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

/* 停止接收定时器 */
void SerialAssistant::deleteRxTimer()
{
    /* 停止定时器 */
    if(rxTimer.isActive()){
        disconnect(&rxTimer ,SIGNAL(timeout()),0,0);
        connect(currentPort ,SIGNAL(readyRead()),this,SLOT( slots_serialRxCallback()));
        rxTimer.stop();
    }
}

/* 发送文本框的光标位置改变 槽函数 光标所在行高亮 */
void SerialAssistant::slots_highlightLine()
{
    QList<QTextEdit::ExtraSelection> extraSelections;//提供一种方式显示选择的文本
    QTextEdit::ExtraSelection selection;

    selection.format.setBackground(QColor(Qt::gray).lighter(145));       // 设置背景颜色和亮度
    selection.format.setProperty(QTextFormat::FullWidthSelection, true); // 选择当前行所有像素(宽)
    selection.cursor = ui->txtSingle->textCursor();                      // 高亮当前行
    extraSelections.append(selection);
    ui->txtSingle->setExtraSelections(extraSelections);                  //设置高亮
}

/* 定时发送点击事件 槽函数 */
void SerialAssistant::on_chbTimedTx_clicked(bool checked)
{
    if(checked){
        if(openPort ){
            this->startTxTimer();
        }

    }else if(txTimer.isActive()){
            this->deleteTxTimer();
    }
}
/* 启动发送控制定时器 */
void SerialAssistant::startTxTimer()
{
    txTimer.setTimerType(Qt::PreciseTimer );
    qint32 tmp = ui->spbTxInterval->value();
    txTimer.start(tmp);
    connect(&txTimer,SIGNAL(timeout()),this,SLOT(slots_timeOutTx()));
}
/* 停止发送控制定时器 */
void SerialAssistant::deleteTxTimer()
{
    /* 停止定时器 */
    txTimer.stop();
    disconnect(&txTimer,SIGNAL(timeout()),this,SLOT(slots_timeOutTx()));

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
            emit this->ui->btnSend->click();// 发送单条数据,与点击"发送"按钮功能一致
            break;
        case 1:
            static qint32 i(0);
            if(!multiCheckBox.value(i)->isChecked()){/* 轮询是否勾选发送 */
                qint32 j(0),k;
                i >=9 ? k=0: k=i+1;
                for( ; j < 9; j++){
                    if(multiCheckBox.value(k++)->isChecked()){
                        k--;
                        j--; // 用于标记没有执行完9次就退出循环
                        break;
                    }
                    if(k>=10)k=0;
                }
                if(9 != j){// 搜索到CheckedBox
                    emit multiPushButton.value(k)->clicked(true);
                    i = k+1;
                }
            }else{
                emit multiPushButton.value(i++)->clicked(true);
            }
            i>=10 ? i=0: 0;
            break;
        }
    }
}
// MultiPushButton 点击发送 槽函数
void SerialAssistant::slots_multiSend()
{
    QPushButton *btn = (QPushButton*) sender();
    if(openPort){
        QString tmpString = multiTxtLine.value(btn->text().toInt()-1)->text(); // 获取对应的文本
        QByteArray txBuf ;
        txBuf = this->stringToSend(tmpString, ui->chbTxHex->isChecked());
        qint32 txBytes = currentPort->write(txBuf);
        /* 显示发送字节数 */
        qint32 tmp = ui->lbltxCnt->text().toInt();
        ui->lbltxCnt->setText(QString::number(tmp + txBytes));

        this->displayTxBuffer(txBuf); // 显示发送的数据
    }
}

/* 定时发送 时间间隔改变 槽函数 */
void SerialAssistant::on_spbTxInterval_editingFinished()
{
    /* 改变定时器发送的 时间间隔 */
    if(txTimer.isActive()){
        qint32 tmp = ui->spbTxInterval->value();
        txTimer.setInterval( tmp );
    }
}

/* Hex发送点击事件 槽函数 */
void SerialAssistant::on_chbTxHex_clicked(bool checked)
{
    if(checked){
        /* 设定输入规则 */
        QRegExp regExp("[a-f0-9A-F ]*"); // Hex 字符串
        QRegExpValidator *regExpValidator = new QRegExpValidator (regExp,this);

        /* 将原有的非Hex字符转换成Hex字符 */
        foreach (QLineEdit *txtLine, multiTxtLine) {// 判断是否是Hex字符串
            txtLine->setText(this->asciiToHexString(txtLine->text()));
            txtLine->setValidator(regExpValidator);   // 设置输入规则
        }

        if(!this->isHexString(ui->txtSingle->toPlainText() ))
            ui->txtSingle->setPlainText(this->asciiToHexString(ui->txtSingle->toPlainText()));
        connect(this->ui->txtSingle,SIGNAL(textChanged()),this,SLOT(on_txtSingle_textChanged()));
    }else{
        /* 清除所有规则 */
        foreach (QLineEdit *txtLine, multiTxtLine) {
            txtLine->setValidator(0);
            if(this->isHexString(txtLine->text()))  // 判断是否是Hex字符串
                txtLine->setText(this->hexStringToAscii(txtLine->text()));
        }
        disconnect(this->ui->txtSingle,SIGNAL(textChanged()),this,SLOT(on_txtSingle_textChanged()));
        if(this->isHexString(ui->txtSingle->toPlainText()))  // 判断是否是Hex字符串
            ui->txtSingle->setPlainText(this->hexStringToAscii(ui->txtSingle->toPlainText()));

    }
}
/* ascii to hexString 将ascii字符串转换成hex字符串 "35"->"33 35" */
QString SerialAssistant::asciiToHexString(QString src)
{
    QByteArray buf;
    buf = src.toLocal8Bit();
    buf = buf.toHex().toUpper();
    buf = this->insertSpace(buf );
    return QString::fromLocal8Bit(buf);
}
/* hexString to ascii 将hex字符串转换成ascii字符串 "33 35"->"35" */
QString SerialAssistant::hexStringToAscii(QString src)
{
    QByteArray buf = stringToSend(src ,true);
    return QString::fromLocal8Bit(buf);
}

/* 检查src中字符是否符合Hex规则表达式 */
bool SerialAssistant::isHexString(QString src)
{
    bool isMatch = true;
    QRegExp regExp("[a-f0-9A-F ]*");
    isMatch = regExp.exactMatch(src);
    return isMatch;
}
/* 将QString 转换成可以直接发送的QByteArray */
QByteArray SerialAssistant::stringToSend(QString src, bool txInHex )
{
    QByteArray buf;
    QString tmpString ;
    if(txInHex ){/* 以十六进制发送 */
        tmpString = src.remove(QRegExp("\\s"));// delete ' '
        QByteArray tmpTest = tmpString.toLatin1();
        if(tmpTest.length() & 0x01 ) // 奇数个字符,最后一个字符不能满足转换成Hex数据
        {
            tmpTest.remove(tmpTest.length()-1, 1); // 移除并警告
            QMessageBox::information(NULL, tr("不支持的输入"),  tr("请输入完整的字节"), 0, 0);
        }
        buf = QByteArray::fromHex(tmpTest); // ascii to hex(hex字符串转换成 hex数据 ) "33 35"->0x33 0x35
    }else{
        buf = src.toLocal8Bit();
    }
    return buf;
}

void SerialAssistant::displayTxBuffer(QByteArray &txBuffer)
{
    /* 显示发送数据 */
    // Hex显示
    if(txBuffer.isEmpty())
        return;
    if( ui->chkDisplayHex->checkState() ){
        txBuffer = txBuffer.toHex().toUpper();
        txBuffer = this->insertSpace(txBuffer);
    }
    txBuffer.insert(0, "[" + QTime::currentTime().toString("hh:mm:ss.zzz") + "]Tx: ");
    QString strToDisplay = QString::fromLocal8Bit(txBuffer);
    ui->textBrower->appendPlainText(strToDisplay);
}
