/********************************************************************************
** Form generated from reading UI file 'serialassistant.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIALASSISTANT_H
#define UI_SERIALASSISTANT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SerialAssistant
{
public:
    QGroupBox *QGBCtrlRx;
    QSpinBox *spbRxTimeOut;
    QLabel *lblDivision;
    QLabel *lblUnit_ms;
    QPushButton *btnSaveFile;
    QPushButton *btnClear;
    QPushButton *btnPause;
    QCheckBox *chkDisplayHex;
    QCheckBox *checkBox_5;
    QGroupBox *QGBCtrlTx;
    QSpinBox *spinBox_2;
    QLabel *lblUnit_ms_2;
    QLabel *lblTimedTx;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_8;
    QLabel *lblTerminator;
    QComboBox *cbbTerminator;
    QWidget *layoutWidget6;
    QHBoxLayout *horizontalLayout_9;
    QCheckBox *chbTxHex;
    QCheckBox *chbTimedTx;
    QLabel *lblFileSize;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_3;
    QLabel *lblVerifyPos;
    QLineEdit *lineEdit;
    QLabel *lblBeginPos;
    QLabel *lblByteNum;
    QLineEdit *lineEdit_2;
    QComboBox *cbbVerifyStyle;
    QPushButton *btnLoadFile;
    QPushButton *btnTxFile;
    QProgressBar *progressBar;
    QToolBox *toolBox;
    QWidget *page_1;
    QTextEdit *txtSingle;
    QPushButton *btnSend;
    QWidget *page_2;
    QWidget *layoutWidget7;
    QGridLayout *gridLayout_2;
    QPushButton *btnMultiPush02;
    QLineEdit *txtLine01;
    QLineEdit *txtLine02;
    QPushButton *btnMultiPush06;
    QPushButton *btnMultiPush03;
    QPushButton *btnMultiPush04;
    QLineEdit *txtLine03;
    QLineEdit *txtLine04;
    QLineEdit *txtLine05;
    QPushButton *btnMultiPush05;
    QPushButton *btnMultiPush01;
    QLineEdit *txtLine06;
    QPushButton *btnMultiPush07;
    QLineEdit *txtLine07;
    QPushButton *btnMultiPush08;
    QLineEdit *txtLine08;
    QPushButton *btnMultiPush09;
    QLineEdit *txtLine09;
    QPushButton *btnMultiPush10;
    QLineEdit *txtLine10;
    QGroupBox *QGBSerialConfig;
    QPushButton *btnOpenPort;
    QWidget *formLayoutWidget;
    QGridLayout *gridLayout_3;
    QLabel *lblPortNum;
    QComboBox *cbbPortNum;
    QLabel *lblBaudRate;
    QComboBox *cbbBaud;
    QLabel *lblDataBit;
    QComboBox *cbbDataBit;
    QLabel *lblVerify;
    QLabel *lblStopBit;
    QComboBox *cbbStopBit;
    QComboBox *cbbVerify;
    QPushButton *btnRefresh;
    QCheckBox *chkFlowCtrlDTR;
    QCheckBox *chkFlowCtrlRTS;
    QTextEdit *textBrower;

    void setupUi(QWidget *SerialAssistant)
    {
        if (SerialAssistant->objectName().isEmpty())
            SerialAssistant->setObjectName(QStringLiteral("SerialAssistant"));
        SerialAssistant->resize(1090, 677);
        SerialAssistant->setStyleSheet(QStringLiteral(""));
        QGBCtrlRx = new QGroupBox(SerialAssistant);
        QGBCtrlRx->setObjectName(QStringLiteral("QGBCtrlRx"));
        QGBCtrlRx->setGeometry(QRect(10, 230, 171, 141));
        QGBCtrlRx->setStyleSheet(QLatin1String("QGroupBox{\n"
"border-width:1px;\n"
"border-style:solid;\n"
"border-radius:4px;\n"
"font:bold ; \n"
"}"));
        QGBCtrlRx->setFlat(false);
        QGBCtrlRx->setCheckable(false);
        spbRxTimeOut = new QSpinBox(QGBCtrlRx);
        spbRxTimeOut->setObjectName(QStringLiteral("spbRxTimeOut"));
        spbRxTimeOut->setGeometry(QRect(65, 111, 61, 18));
        spbRxTimeOut->setMinimum(30);
        spbRxTimeOut->setMaximum(99999);
        lblDivision = new QLabel(QGBCtrlRx);
        lblDivision->setObjectName(QStringLiteral("lblDivision"));
        lblDivision->setGeometry(QRect(11, 111, 48, 16));
        lblUnit_ms = new QLabel(QGBCtrlRx);
        lblUnit_ms->setObjectName(QStringLiteral("lblUnit_ms"));
        lblUnit_ms->setGeometry(QRect(130, 111, 16, 16));
        btnSaveFile = new QPushButton(QGBCtrlRx);
        btnSaveFile->setObjectName(QStringLiteral("btnSaveFile"));
        btnSaveFile->setGeometry(QRect(11, 51, 151, 23));
        btnClear = new QPushButton(QGBCtrlRx);
        btnClear->setObjectName(QStringLiteral("btnClear"));
        btnClear->setGeometry(QRect(11, 21, 72, 20));
        btnPause = new QPushButton(QGBCtrlRx);
        btnPause->setObjectName(QStringLiteral("btnPause"));
        btnPause->setGeometry(QRect(89, 21, 71, 20));
        chkDisplayHex = new QCheckBox(QGBCtrlRx);
        chkDisplayHex->setObjectName(QStringLiteral("chkDisplayHex"));
        chkDisplayHex->setGeometry(QRect(11, 81, 67, 18));
        checkBox_5 = new QCheckBox(QGBCtrlRx);
        checkBox_5->setObjectName(QStringLiteral("checkBox_5"));
        checkBox_5->setGeometry(QRect(84, 81, 73, 18));
        QGBCtrlTx = new QGroupBox(SerialAssistant);
        QGBCtrlTx->setObjectName(QStringLiteral("QGBCtrlTx"));
        QGBCtrlTx->setGeometry(QRect(10, 380, 171, 261));
        QGBCtrlTx->setStyleSheet(QLatin1String("QGroupBox{\n"
"border-width:1px;\n"
"border-style:solid;\n"
"border-radius:4px;\n"
"font:bold ; \n"
"}"));
        QGBCtrlTx->setFlat(false);
        QGBCtrlTx->setCheckable(false);
        spinBox_2 = new QSpinBox(QGBCtrlTx);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setGeometry(QRect(65, 230, 61, 18));
        spinBox_2->setMinimumSize(QSize(61, 18));
        spinBox_2->setAutoFillBackground(false);
        spinBox_2->setMinimum(30);
        spinBox_2->setMaximum(99999);
        spinBox_2->setValue(99);
        lblUnit_ms_2 = new QLabel(QGBCtrlTx);
        lblUnit_ms_2->setObjectName(QStringLiteral("lblUnit_ms_2"));
        lblUnit_ms_2->setGeometry(QRect(130, 230, 16, 16));
        lblTimedTx = new QLabel(QGBCtrlTx);
        lblTimedTx->setObjectName(QStringLiteral("lblTimedTx"));
        lblTimedTx->setGeometry(QRect(11, 230, 48, 16));
        layoutWidget4 = new QWidget(QGBCtrlTx);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(10, 70, 151, 24));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        lblTerminator = new QLabel(layoutWidget4);
        lblTerminator->setObjectName(QStringLiteral("lblTerminator"));

        horizontalLayout_8->addWidget(lblTerminator);

        cbbTerminator = new QComboBox(layoutWidget4);
        cbbTerminator->setObjectName(QStringLiteral("cbbTerminator"));

        horizontalLayout_8->addWidget(cbbTerminator);

        layoutWidget6 = new QWidget(QGBCtrlTx);
        layoutWidget6->setObjectName(QStringLiteral("layoutWidget6"));
        layoutWidget6->setGeometry(QRect(10, 210, 151, 20));
        horizontalLayout_9 = new QHBoxLayout(layoutWidget6);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        chbTxHex = new QCheckBox(layoutWidget6);
        chbTxHex->setObjectName(QStringLiteral("chbTxHex"));

        horizontalLayout_9->addWidget(chbTxHex);

        chbTimedTx = new QCheckBox(layoutWidget6);
        chbTimedTx->setObjectName(QStringLiteral("chbTimedTx"));

        horizontalLayout_9->addWidget(chbTimedTx);

        lblFileSize = new QLabel(QGBCtrlTx);
        lblFileSize->setObjectName(QStringLiteral("lblFileSize"));
        lblFileSize->setGeometry(QRect(10, 50, 151, 16));
        layoutWidget = new QWidget(QGBCtrlTx);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 130, 151, 80));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit_3 = new QLineEdit(layoutWidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        gridLayout->addWidget(lineEdit_3, 1, 0, 1, 1);

        lblVerifyPos = new QLabel(layoutWidget);
        lblVerifyPos->setObjectName(QStringLiteral("lblVerifyPos"));

        gridLayout->addWidget(lblVerifyPos, 2, 1, 1, 1);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 0, 1, 1);

        lblBeginPos = new QLabel(layoutWidget);
        lblBeginPos->setObjectName(QStringLiteral("lblBeginPos"));

        gridLayout->addWidget(lblBeginPos, 0, 1, 1, 1);

        lblByteNum = new QLabel(layoutWidget);
        lblByteNum->setObjectName(QStringLiteral("lblByteNum"));

        gridLayout->addWidget(lblByteNum, 1, 1, 1, 1);

        lineEdit_2 = new QLineEdit(layoutWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 2, 0, 1, 1);

        cbbVerifyStyle = new QComboBox(QGBCtrlTx);
        cbbVerifyStyle->setObjectName(QStringLiteral("cbbVerifyStyle"));
        cbbVerifyStyle->setGeometry(QRect(11, 101, 151, 22));
        btnLoadFile = new QPushButton(QGBCtrlTx);
        btnLoadFile->setObjectName(QStringLiteral("btnLoadFile"));
        btnLoadFile->setGeometry(QRect(11, 22, 72, 20));
        btnTxFile = new QPushButton(QGBCtrlTx);
        btnTxFile->setObjectName(QStringLiteral("btnTxFile"));
        btnTxFile->setGeometry(QRect(89, 22, 71, 20));
        progressBar = new QProgressBar(SerialAssistant);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setEnabled(true);
        progressBar->setGeometry(QRect(10, 650, 171, 16));
        progressBar->setCursor(QCursor(Qt::ArrowCursor));
        progressBar->setMaximum(100);
        progressBar->setValue(0);
        progressBar->setTextVisible(true);
        progressBar->setInvertedAppearance(false);
        toolBox = new QToolBox(SerialAssistant);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        toolBox->setGeometry(QRect(200, 460, 881, 221));
        page_1 = new QWidget();
        page_1->setObjectName(QStringLiteral("page_1"));
        page_1->setGeometry(QRect(0, 0, 881, 169));
        txtSingle = new QTextEdit(page_1);
        txtSingle->setObjectName(QStringLiteral("txtSingle"));
        txtSingle->setGeometry(QRect(120, 0, 761, 171));
        btnSend = new QPushButton(page_1);
        btnSend->setObjectName(QStringLiteral("btnSend"));
        btnSend->setGeometry(QRect(20, 10, 71, 41));
        toolBox->addItem(page_1, QString::fromUtf8("\345\215\225\346\235\241\345\217\221\351\200\201"));
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        page_2->setGeometry(QRect(0, 0, 881, 169));
        layoutWidget7 = new QWidget(page_2);
        layoutWidget7->setObjectName(QStringLiteral("layoutWidget7"));
        layoutWidget7->setGeometry(QRect(0, 0, 881, 161));
        gridLayout_2 = new QGridLayout(layoutWidget7);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        btnMultiPush02 = new QPushButton(layoutWidget7);
        btnMultiPush02->setObjectName(QStringLiteral("btnMultiPush02"));

        gridLayout_2->addWidget(btnMultiPush02, 1, 0, 1, 1);

        txtLine01 = new QLineEdit(layoutWidget7);
        txtLine01->setObjectName(QStringLiteral("txtLine01"));

        gridLayout_2->addWidget(txtLine01, 0, 1, 1, 1);

        txtLine02 = new QLineEdit(layoutWidget7);
        txtLine02->setObjectName(QStringLiteral("txtLine02"));

        gridLayout_2->addWidget(txtLine02, 1, 1, 1, 1);

        btnMultiPush06 = new QPushButton(layoutWidget7);
        btnMultiPush06->setObjectName(QStringLiteral("btnMultiPush06"));

        gridLayout_2->addWidget(btnMultiPush06, 0, 2, 1, 1);

        btnMultiPush03 = new QPushButton(layoutWidget7);
        btnMultiPush03->setObjectName(QStringLiteral("btnMultiPush03"));

        gridLayout_2->addWidget(btnMultiPush03, 2, 0, 1, 1);

        btnMultiPush04 = new QPushButton(layoutWidget7);
        btnMultiPush04->setObjectName(QStringLiteral("btnMultiPush04"));

        gridLayout_2->addWidget(btnMultiPush04, 3, 0, 1, 1);

        txtLine03 = new QLineEdit(layoutWidget7);
        txtLine03->setObjectName(QStringLiteral("txtLine03"));

        gridLayout_2->addWidget(txtLine03, 2, 1, 1, 1);

        txtLine04 = new QLineEdit(layoutWidget7);
        txtLine04->setObjectName(QStringLiteral("txtLine04"));

        gridLayout_2->addWidget(txtLine04, 3, 1, 1, 1);

        txtLine05 = new QLineEdit(layoutWidget7);
        txtLine05->setObjectName(QStringLiteral("txtLine05"));

        gridLayout_2->addWidget(txtLine05, 4, 1, 1, 1);

        btnMultiPush05 = new QPushButton(layoutWidget7);
        btnMultiPush05->setObjectName(QStringLiteral("btnMultiPush05"));

        gridLayout_2->addWidget(btnMultiPush05, 4, 0, 1, 1);

        btnMultiPush01 = new QPushButton(layoutWidget7);
        btnMultiPush01->setObjectName(QStringLiteral("btnMultiPush01"));

        gridLayout_2->addWidget(btnMultiPush01, 0, 0, 1, 1);

        txtLine06 = new QLineEdit(layoutWidget7);
        txtLine06->setObjectName(QStringLiteral("txtLine06"));

        gridLayout_2->addWidget(txtLine06, 0, 3, 1, 1);

        btnMultiPush07 = new QPushButton(layoutWidget7);
        btnMultiPush07->setObjectName(QStringLiteral("btnMultiPush07"));

        gridLayout_2->addWidget(btnMultiPush07, 1, 2, 1, 1);

        txtLine07 = new QLineEdit(layoutWidget7);
        txtLine07->setObjectName(QStringLiteral("txtLine07"));

        gridLayout_2->addWidget(txtLine07, 1, 3, 1, 1);

        btnMultiPush08 = new QPushButton(layoutWidget7);
        btnMultiPush08->setObjectName(QStringLiteral("btnMultiPush08"));

        gridLayout_2->addWidget(btnMultiPush08, 2, 2, 1, 1);

        txtLine08 = new QLineEdit(layoutWidget7);
        txtLine08->setObjectName(QStringLiteral("txtLine08"));

        gridLayout_2->addWidget(txtLine08, 2, 3, 1, 1);

        btnMultiPush09 = new QPushButton(layoutWidget7);
        btnMultiPush09->setObjectName(QStringLiteral("btnMultiPush09"));

        gridLayout_2->addWidget(btnMultiPush09, 3, 2, 1, 1);

        txtLine09 = new QLineEdit(layoutWidget7);
        txtLine09->setObjectName(QStringLiteral("txtLine09"));

        gridLayout_2->addWidget(txtLine09, 3, 3, 1, 1);

        btnMultiPush10 = new QPushButton(layoutWidget7);
        btnMultiPush10->setObjectName(QStringLiteral("btnMultiPush10"));

        gridLayout_2->addWidget(btnMultiPush10, 4, 2, 1, 1);

        txtLine10 = new QLineEdit(layoutWidget7);
        txtLine10->setObjectName(QStringLiteral("txtLine10"));

        gridLayout_2->addWidget(txtLine10, 4, 3, 1, 1);

        toolBox->addItem(page_2, QString::fromUtf8("\345\244\232\346\235\241\345\217\221\351\200\201"));
        QGBSerialConfig = new QGroupBox(SerialAssistant);
        QGBSerialConfig->setObjectName(QStringLiteral("QGBSerialConfig"));
        QGBSerialConfig->setGeometry(QRect(10, 10, 171, 211));
        QGBSerialConfig->setStyleSheet(QLatin1String("QGroupBox{\n"
"border-width:1px;\n"
"border-style:solid;\n"
"border-radius:4px;\n"
"font:bold ; \n"
"}"));
        QGBSerialConfig->setFlat(false);
        QGBSerialConfig->setCheckable(false);
        btnOpenPort = new QPushButton(QGBSerialConfig);
        btnOpenPort->setObjectName(QStringLiteral("btnOpenPort"));
        btnOpenPort->setGeometry(QRect(89, 161, 71, 20));
        btnOpenPort->setStyleSheet(QStringLiteral(""));
        btnOpenPort->setChecked(false);
        btnOpenPort->setAutoDefault(false);
        btnOpenPort->setFlat(false);
        formLayoutWidget = new QWidget(QGBSerialConfig);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 20, 151, 136));
        gridLayout_3 = new QGridLayout(formLayoutWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        lblPortNum = new QLabel(formLayoutWidget);
        lblPortNum->setObjectName(QStringLiteral("lblPortNum"));

        gridLayout_3->addWidget(lblPortNum, 0, 0, 1, 1);

        cbbPortNum = new QComboBox(formLayoutWidget);
        cbbPortNum->setObjectName(QStringLiteral("cbbPortNum"));
        cbbPortNum->setMaxVisibleItems(20);
        cbbPortNum->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        cbbPortNum->setMinimumContentsLength(0);

        gridLayout_3->addWidget(cbbPortNum, 0, 1, 1, 1);

        lblBaudRate = new QLabel(formLayoutWidget);
        lblBaudRate->setObjectName(QStringLiteral("lblBaudRate"));

        gridLayout_3->addWidget(lblBaudRate, 1, 0, 1, 1);

        cbbBaud = new QComboBox(formLayoutWidget);
        cbbBaud->setObjectName(QStringLiteral("cbbBaud"));
        cbbBaud->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout_3->addWidget(cbbBaud, 1, 1, 1, 1);

        lblDataBit = new QLabel(formLayoutWidget);
        lblDataBit->setObjectName(QStringLiteral("lblDataBit"));

        gridLayout_3->addWidget(lblDataBit, 2, 0, 1, 1);

        cbbDataBit = new QComboBox(formLayoutWidget);
        cbbDataBit->setObjectName(QStringLiteral("cbbDataBit"));
        cbbDataBit->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout_3->addWidget(cbbDataBit, 2, 1, 1, 1);

        lblVerify = new QLabel(formLayoutWidget);
        lblVerify->setObjectName(QStringLiteral("lblVerify"));

        gridLayout_3->addWidget(lblVerify, 3, 0, 1, 1);

        lblStopBit = new QLabel(formLayoutWidget);
        lblStopBit->setObjectName(QStringLiteral("lblStopBit"));

        gridLayout_3->addWidget(lblStopBit, 4, 0, 1, 1);

        cbbStopBit = new QComboBox(formLayoutWidget);
        cbbStopBit->setObjectName(QStringLiteral("cbbStopBit"));
        cbbStopBit->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout_3->addWidget(cbbStopBit, 4, 1, 1, 1);

        cbbVerify = new QComboBox(formLayoutWidget);
        cbbVerify->setObjectName(QStringLiteral("cbbVerify"));
        cbbVerify->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout_3->addWidget(cbbVerify, 3, 1, 1, 1);

        btnRefresh = new QPushButton(QGBSerialConfig);
        btnRefresh->setObjectName(QStringLiteral("btnRefresh"));
        btnRefresh->setGeometry(QRect(11, 161, 72, 20));
        chkFlowCtrlDTR = new QCheckBox(QGBSerialConfig);
        chkFlowCtrlDTR->setObjectName(QStringLiteral("chkFlowCtrlDTR"));
        chkFlowCtrlDTR->setGeometry(QRect(31, 191, 43, 18));
        chkFlowCtrlRTS = new QCheckBox(QGBSerialConfig);
        chkFlowCtrlRTS->setObjectName(QStringLiteral("chkFlowCtrlRTS"));
        chkFlowCtrlRTS->setGeometry(QRect(80, 191, 43, 18));
        textBrower = new QTextEdit(SerialAssistant);
        textBrower->setObjectName(QStringLiteral("textBrower"));
        textBrower->setGeometry(QRect(200, 20, 881, 431));
#ifndef QT_NO_SHORTCUT
        lblPortNum->setBuddy(cbbPortNum);
        lblBaudRate->setBuddy(cbbBaud);
        lblDataBit->setBuddy(cbbDataBit);
        lblVerify->setBuddy(cbbVerify);
        lblStopBit->setBuddy(cbbStopBit);
#endif // QT_NO_SHORTCUT

        retranslateUi(SerialAssistant);

        toolBox->setCurrentIndex(0);
        btnOpenPort->setDefault(false);


        QMetaObject::connectSlotsByName(SerialAssistant);
    } // setupUi

    void retranslateUi(QWidget *SerialAssistant)
    {
        SerialAssistant->setWindowTitle(QApplication::translate("SerialAssistant", "SerialAssistant", Q_NULLPTR));
        QGBCtrlRx->setTitle(QApplication::translate("SerialAssistant", "\351\200\232\347\224\250\346\216\245\346\224\266\346\216\247\345\210\266", Q_NULLPTR));
        lblDivision->setText(QApplication::translate("SerialAssistant", "\345\210\206\345\214\205\351\227\264\351\232\224", Q_NULLPTR));
        lblUnit_ms->setText(QApplication::translate("SerialAssistant", "ms", Q_NULLPTR));
        btnSaveFile->setText(QApplication::translate("SerialAssistant", "\344\277\235\345\255\230\350\207\263\346\226\207\344\273\266...", Q_NULLPTR));
        btnClear->setText(QApplication::translate("SerialAssistant", "\346\270\205\347\251\272", Q_NULLPTR));
        btnPause->setText(QApplication::translate("SerialAssistant", "\346\232\202\345\201\234", Q_NULLPTR));
        chkDisplayHex->setText(QApplication::translate("SerialAssistant", "Hex\346\230\276\347\244\272", Q_NULLPTR));
        checkBox_5->setText(QApplication::translate("SerialAssistant", "\345\210\206\345\214\205\346\230\276\347\244\272", Q_NULLPTR));
        QGBCtrlTx->setTitle(QApplication::translate("SerialAssistant", "\350\207\252\345\212\250\345\217\221\351\200\201\346\216\247\345\210\266", Q_NULLPTR));
        spinBox_2->setSuffix(QString());
        lblUnit_ms_2->setText(QApplication::translate("SerialAssistant", "ms", Q_NULLPTR));
        lblTimedTx->setText(QApplication::translate("SerialAssistant", "\345\256\232\346\227\266\345\217\221\351\200\201", Q_NULLPTR));
        lblTerminator->setText(QApplication::translate("SerialAssistant", "\347\273\223\345\260\276\350\207\252\345\212\250\346\267\273\345\212\240", Q_NULLPTR));
        cbbTerminator->clear();
        cbbTerminator->insertItems(0, QStringList()
         << QApplication::translate("SerialAssistant", "NONE", Q_NULLPTR)
         << QApplication::translate("SerialAssistant", "CR", Q_NULLPTR)
         << QApplication::translate("SerialAssistant", "LF", Q_NULLPTR)
         << QApplication::translate("SerialAssistant", "CR\\LF", Q_NULLPTR)
        );
        chbTxHex->setText(QApplication::translate("SerialAssistant", "Hex\345\217\221\351\200\201", Q_NULLPTR));
        chbTimedTx->setText(QApplication::translate("SerialAssistant", "\345\256\232\346\227\266\345\217\221\351\200\201", Q_NULLPTR));
        lblFileSize->setText(QApplication::translate("SerialAssistant", "\346\226\207\344\273\266\345\244\247\345\260\217\357\274\232", Q_NULLPTR));
        lblVerifyPos->setText(QApplication::translate("SerialAssistant", "\346\240\241\351\252\214\347\240\201\346\217\222\345\205\245\344\275\215\347\275\256", Q_NULLPTR));
        lblBeginPos->setText(QApplication::translate("SerialAssistant", "\350\265\267\345\247\213\344\275\215\347\275\256", Q_NULLPTR));
        lblByteNum->setText(QApplication::translate("SerialAssistant", "\345\255\227\350\212\202\346\225\260", Q_NULLPTR));
        cbbVerifyStyle->clear();
        cbbVerifyStyle->insertItems(0, QStringList()
         << QApplication::translate("SerialAssistant", "\346\267\273\345\212\240\346\243\200\351\252\214\347\240\201", Q_NULLPTR)
         << QApplication::translate("SerialAssistant", "ADD8", Q_NULLPTR)
         << QApplication::translate("SerialAssistant", "0-ADD8", Q_NULLPTR)
         << QApplication::translate("SerialAssistant", "XOR8", Q_NULLPTR)
         << QApplication::translate("SerialAssistant", "CRC16(MUDBUS)", Q_NULLPTR)
         << QApplication::translate("SerialAssistant", "\345\233\272\345\256\232\345\255\227\350\212\202", Q_NULLPTR)
        );
        btnLoadFile->setText(QApplication::translate("SerialAssistant", "\345\212\240\350\275\275\346\226\207\344\273\266", Q_NULLPTR));
        btnTxFile->setText(QApplication::translate("SerialAssistant", "\344\274\240\350\276\223\346\226\207\344\273\266", Q_NULLPTR));
        txtSingle->setHtml(QApplication::translate("SerialAssistant", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", Q_NULLPTR));
        btnSend->setText(QApplication::translate("SerialAssistant", "\345\217\221\351\200\201", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page_1), QApplication::translate("SerialAssistant", "\345\215\225\346\235\241\345\217\221\351\200\201", Q_NULLPTR));
        btnMultiPush02->setText(QApplication::translate("SerialAssistant", "2", Q_NULLPTR));
        btnMultiPush06->setText(QApplication::translate("SerialAssistant", "6", Q_NULLPTR));
        btnMultiPush03->setText(QApplication::translate("SerialAssistant", "3", Q_NULLPTR));
        btnMultiPush04->setText(QApplication::translate("SerialAssistant", "4", Q_NULLPTR));
        btnMultiPush05->setText(QApplication::translate("SerialAssistant", "5", Q_NULLPTR));
        btnMultiPush01->setText(QApplication::translate("SerialAssistant", "1", Q_NULLPTR));
        btnMultiPush07->setText(QApplication::translate("SerialAssistant", "7", Q_NULLPTR));
        btnMultiPush08->setText(QApplication::translate("SerialAssistant", "8", Q_NULLPTR));
        btnMultiPush09->setText(QApplication::translate("SerialAssistant", "9", Q_NULLPTR));
        btnMultiPush10->setText(QApplication::translate("SerialAssistant", "10", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("SerialAssistant", "\345\244\232\346\235\241\345\217\221\351\200\201", Q_NULLPTR));
        QGBSerialConfig->setTitle(QApplication::translate("SerialAssistant", "\344\270\262\345\217\243\350\256\276\347\275\256", Q_NULLPTR));
        btnOpenPort->setText(QApplication::translate("SerialAssistant", "\346\211\223\345\274\200\344\270\262\345\217\243", Q_NULLPTR));
        lblPortNum->setText(QApplication::translate("SerialAssistant", "\347\253\257\345\217\243\345\217\267(&C)", Q_NULLPTR));
        lblBaudRate->setText(QApplication::translate("SerialAssistant", "\346\263\242\347\211\271\347\216\207", Q_NULLPTR));
        lblDataBit->setText(QApplication::translate("SerialAssistant", "\346\225\260\346\215\256\344\275\215", Q_NULLPTR));
        lblVerify->setText(QApplication::translate("SerialAssistant", "\346\240\241\351\252\214", Q_NULLPTR));
        lblStopBit->setText(QApplication::translate("SerialAssistant", "\345\201\234\346\255\242\344\275\215", Q_NULLPTR));
        btnRefresh->setText(QApplication::translate("SerialAssistant", "\345\210\267\346\226\260", Q_NULLPTR));
        chkFlowCtrlDTR->setText(QApplication::translate("SerialAssistant", "DTR", Q_NULLPTR));
        chkFlowCtrlRTS->setText(QApplication::translate("SerialAssistant", "RTS", Q_NULLPTR));
        textBrower->setHtml(QApplication::translate("SerialAssistant", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SerialAssistant: public Ui_SerialAssistant {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIALASSISTANT_H
