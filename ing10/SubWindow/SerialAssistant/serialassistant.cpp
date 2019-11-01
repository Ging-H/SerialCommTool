#include "serialassistant.h"
#include "ui_serialassistant.h"
#include <QMessageBox>
#include <QDebug>
#include <QMetaEnum>
#include <QFileDialog>
#include <QTextCodec>
#include <QKeyEvent>
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
    rxTimer = NULL;  // 接收定时器
    saveFile = NULL; // 保存文件指针
    ui->txtSingle->setPlaceholderText( "硬石电子 携手合作,共创未来" " " "http://www.ing10bbs.com/" );

    QList<QTextEdit::ExtraSelection> extraSelections;//提供一种方式显示选择的文本
    extraSelections = ui->txtSingle->extraSelections();//获取之前高亮的设置
    QTextEdit::ExtraSelection selection;
    selection.format.setBackground(QColor("#e8e8e8"));
    selection.format.setProperty(QTextFormat::FullWidthSelection, true);
    selection.cursor = ui->txtSingle->textCursor();
    selection.cursor.movePosition(QTextCursor::Up);//光标移动到某一行。此处移动到上一行，上一行将高亮。
    extraSelections.append(selection);
    ui->txtSingle->setExtraSelections(extraSelections);//设置高亮

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
                QMessageBox::information(NULL, tr("不支持的设置"),  tr("该串口设备不支持当前停止位设置,已修改为默认的设置"), 0, 0);
                ui -> cbbStopBit->clear();
                BaseSerialComm::listStopBit ( ui -> cbbStopBit );
            }
            if(NULL != rxTimer){
                rxTimer->start(10);
            }
            else{
                connect(currentPort ,SIGNAL(readyRead()),this,SLOT( slots_serialRxCallback()));
            }
            openPort = true;// 标记已经打开串口
            ui->btnOpenPort->setText(tr("关闭串口"));
        }
    }
    else{
        if(NULL != rxTimer ){
            rxTimer ->stop();
            disconnect(rxTimer,SIGNAL(timeout()),this,SLOT(slots_serialRxCallback()));
            connect(currentPort ,SIGNAL(readyRead()),this,SLOT( slots_serialRxCallback()));
            delete rxTimer;
            rxTimer = NULL;
            ui->checkBox_5->setChecked(false);
        }
        currentPort->close();
        openPort = false ;// 标记已经关闭串口
        ui->btnOpenPort->setText(tr("打开串口"));
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

/* 接收串口数据 槽函数 */
void SerialAssistant::slots_serialRxCallback()
{
    QByteArray rxBuffer;
    qint32 rxBytes;
    QString strToDisplay;

    //接收数据
    rxBytes = currentPort->readData(rxBuffer);
//    qDebug()<<rxTimer->
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

/* 加时间戳 槽函数 */
void SerialAssistant::on_checkBox_5_toggled(bool checked)
{
    if(checked){
        rxTimer = new QTimer;
        rxTimer->setTimerType(Qt::PreciseTimer );
        disconnect(currentPort ,SIGNAL(readyRead()),this,SLOT( slots_serialRxCallback()));
        connect(rxTimer,SIGNAL(timeout()),this,SLOT(slots_serialRxCallback()));
        if(openPort){
            rxTimer->start(10);// 10ms扫描一次
        }
    }else {
        if(NULL != rxTimer ){
            rxTimer ->stop();
            disconnect(rxTimer,SIGNAL(timeout()),this,SLOT(slots_serialRxCallback()));
            connect(currentPort ,SIGNAL(readyRead()),this,SLOT( slots_serialRxCallback()));
            delete rxTimer;
            rxTimer = NULL;
        }
    }
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
                QMessageBox::information(NULL, tr("不支持输入"),  tr("请输入完整的字节"), 0, 0);
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
        currentPort->write(txBuf);
    }
}
//TODO:Hex发送问题
/* 监控文本 槽函数 */
void SerialAssistant::on_txtSingle_textChanged()
{
    if(ui->chbTxHex->isChecked() ){
        bool match = true;
        QRegExp regExp("[a-f0-9A-F ]*");

        match = regExp.exactMatch(ui->txtSingle->toPlainText());

        if(!match){
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

void SerialAssistant::on_toolBox_currentChanged(int index)
{

}
