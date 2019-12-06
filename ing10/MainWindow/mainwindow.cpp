#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWindow>
#include <QWidget>
#include <QDebug>
#include <windows.h>
#include <QDesktopServices>
#include <QUrl>

#define  TB_LINK  "https://3684336.taobao.com/?spm=a1z10.3-c-s.0.0.7465581boD1xTB"
#define  UPDATA_LINK "http://www.ing10bbs.com/forum.php?mod=viewthread&tid=1458&extra=page%3D1"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pBtnGroup = new QButtonGroup(this);
    pBtnGroup->setExclusive(true);
    pBtnGroup->addButton(ui->btnSerial);
    pBtnGroup->addButton(ui->btnStepMotor);
    pBtnGroup->addButton(ui->btnPID);
    pBtnGroup->addButton(ui->btnModbus);
    pBtnGroup->addButton(ui->btnNet);
    pBtnGroup->addButton(ui->btnGSM);
    connect(pBtnGroup, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(slots_btnClicked(QAbstractButton*)));
    /* 暂时隐藏控件 */
//    ui->btnStepMotor->hide();
    ui->btnPID->hide();
    ui->btnModbus->hide();
    ui->btnNet->hide();
    ui->btnGSM->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slots_btnClicked(QAbstractButton *btn)
{
    if( (ui->btnSerial == btn) || btn == NULL)
    {
        if(this->subitem != Serial){
            this->unloadSubItem(subitem);
            // load SerialAssistant;
            this->serial = new SerialAssistant();
            this->resizeForSerial();               // 调整尺寸
            ui->subPanel->addWidget(this->serial); // 将子程序添加进窗口
            this->serial->show();                  // 显示子程序
            this->subitem = Serial;
        }
    }
    if(ui->btnStepMotor == btn){
        if(this->subitem != SMotor){
            this->unloadSubItem(subitem);
            this->stepperMotor = new StepperMotor();
            ui->subPanel->addWidget(this->stepperMotor);
            this->stepperMotor->show();
            this->subitem = SMotor;
        }
    }
    if(ui->btnPID == btn){
        if(this->subitem != PID){
            this->unloadSubItem(subitem);
            // TODO: load PID;
            this->subitem = PID;
        }
    }
    if(ui->btnModbus == btn){
        if(this->subitem != Modbus){
            this->unloadSubItem(subitem);
            // TODO: load Modbus;
            this->subitem = Modbus;
        }
    }
    if(ui->btnNet == btn){
        if(this->subitem != Net){
            this->unloadSubItem(subitem);
            // TODO: load Net;
            this->subitem = Net;
        }
    }
    if(ui->btnGSM == btn){
        if(this->subitem != GSM){
            this->unloadSubItem(subitem);
            // TODO: load GSM;
            this->subitem = GSM;
        }
    }
}
void MainWindow::unloadSubItem(SubItem &current)
{
    switch(current){
    case None: // do nothing...
        break;
    case Serial:
        ui->subPanel->removeWidget(this->serial );
        this->serial->hide();
        delete this->serial;
        break;
    case SMotor: // TODO:
        ui->subPanel->removeWidget(this->stepperMotor);
        this->stepperMotor->hide();
        delete this->stepperMotor;
        break;
    case PID:
        break;
    case Modbus:
        break;
    case Net:
        break;
    case GSM:
        break;
    default:break;
    }
}
void MainWindow::resizeForSerial()
{
    QSize subSize;       // 子程序尺寸
    QSize sizeInc(6,64); // 尺寸微调
    QRect subRect;       // 主程序坐标和尺寸
    subSize  = this->serial->minimumSize();// 获取子程序的尺寸大小
    subRect = this->geometry();            // 获取main 程序的坐标和大小
    subRect.setSize( subSize + sizeInc);   // 修改main 程序的大小
    this->setGeometry( subRect);           // 重绘main 程序的大小
}

void MainWindow::on_TBLink_triggered()
{
    QDesktopServices::openUrl(QUrl(TB_LINK));
}

void MainWindow::on_updataLink_triggered()
{
    QDesktopServices::openUrl(QUrl(UPDATA_LINK));
}
