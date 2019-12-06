/********************************************************************************
** Form generated from reading UI file 'steppermotor.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STEPPERMOTOR_H
#define UI_STEPPERMOTOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StepperMotor
{
public:
    QGridLayout *gridLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupBox_3;
    QComboBox *comboBox;
    QSpinBox *spinBox;
    QPushButton *posStart;
    QPushButton *posStop;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox_2;
    QGroupBox *groupBox_2;
    QDial *dial;
    QPushButton *spdStart;
    QPushButton *spdStop;
    QLabel *label_2;
    QGroupBox *groupBox_4;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_7;
    QLabel *label_5;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_10;
    QLabel *label_9;
    QLabel *label_8;
    QLabel *label_12;
    QLabel *label_11;
    QLabel *label_15;
    QPushButton *pushButton_7;
    QLabel *label_14;
    QPushButton *pushButton_10;
    QPushButton *pushButton_9;
    QPushButton *pushButton_8;
    QLabel *label_13;
    QGroupBox *groupBox;
    QPushButton *btnJogCtrl;
    QDoubleSpinBox *spbJogSpd;
    QTextBrowser *textBrowser;
    QGroupBox *QGBSerialConfig;
    QPushButton *btnOpenPort;
    QWidget *formLayoutWidget;
    QGridLayout *gridLayout_3;
    QLabel *lblVerify;
    QComboBox *cbbDataBit;
    QLabel *lblPortNum;
    QLabel *lblStopBit;
    QLabel *lblBaudRate;
    QComboBox *cbbPortNum;
    QComboBox *cbbVerify;
    QComboBox *cbbStopBit;
    QComboBox *cbbBaud;
    QLabel *lblDataBit;
    QPushButton *btnRefresh;
    QCheckBox *chkFlowCtrlDTR;
    QCheckBox *chkFlowCtrlRTS;
    QTextBrowser *textBrowser_2;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnConnect;
    QLabel *lblDeviceName;

    void setupUi(QWidget *StepperMotor)
    {
        if (StepperMotor->objectName().isEmpty())
            StepperMotor->setObjectName(QStringLiteral("StepperMotor"));
        StepperMotor->setEnabled(true);
        StepperMotor->resize(950, 532);
        QIcon icon;
        icon.addFile(QStringLiteral(":/ico/res/ico/ing10.ico"), QSize(), QIcon::Normal, QIcon::Off);
        StepperMotor->setWindowIcon(icon);
        gridLayout_2 = new QGridLayout(StepperMotor);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        tabWidget = new QTabWidget(StepperMotor);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        groupBox_3 = new QGroupBox(tab);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(201, 320, 301, 141));
        comboBox = new QComboBox(groupBox_3);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(140, 50, 111, 21));
        spinBox = new QSpinBox(groupBox_3);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(140, 30, 111, 22));
        spinBox->setStyleSheet(QLatin1String("\n"
"QSpinBox\n"
"{\n"
"	border:1px solid #7A7A7A;\n"
"}\n"
"\n"
"QSpinBox::up-button,QSpinBox::down-button\n"
"{\n"
"	width:0px;\n"
"}\n"
""));
        spinBox->setReadOnly(false);
        posStart = new QPushButton(groupBox_3);
        posStart->setObjectName(QStringLiteral("posStart"));
        posStart->setGeometry(QRect(10, 30, 71, 41));
        posStop = new QPushButton(groupBox_3);
        posStop->setObjectName(QStringLiteral("posStop"));
        posStop->setGeometry(QRect(10, 80, 71, 41));
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(140, 100, 111, 21));
        doubleSpinBox_2 = new QDoubleSpinBox(groupBox_3);
        doubleSpinBox_2->setObjectName(QStringLiteral("doubleSpinBox_2"));
        doubleSpinBox_2->setGeometry(QRect(140, 70, 111, 21));
        doubleSpinBox_2->setDecimals(2);
        doubleSpinBox_2->setMinimum(-600);
        doubleSpinBox_2->setMaximum(600);
        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(201, 150, 299, 141));
        dial = new QDial(groupBox_2);
        dial->setObjectName(QStringLiteral("dial"));
        dial->setGeometry(QRect(170, 20, 121, 121));
        dial->setMinimum(-60);
        dial->setMaximum(60);
        dial->setSingleStep(5);
        dial->setPageStep(10);
        dial->setSliderPosition(0);
        dial->setInvertedAppearance(false);
        dial->setInvertedControls(false);
        dial->setWrapping(false);
        dial->setNotchesVisible(true);
        spdStart = new QPushButton(groupBox_2);
        spdStart->setObjectName(QStringLiteral("spdStart"));
        spdStart->setGeometry(QRect(10, 30, 71, 31));
        spdStart->setCheckable(true);
        spdStop = new QPushButton(groupBox_2);
        spdStop->setObjectName(QStringLiteral("spdStop"));
        spdStop->setGeometry(QRect(10, 70, 71, 31));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 110, 121, 21));
        groupBox_4 = new QGroupBox(tab);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(530, 10, 361, 211));
        layoutWidget = new QWidget(groupBox_4);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 30, 340, 161));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 0, 3, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 0, 1, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 0, 2, 1, 1);

        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout->addWidget(label_10, 1, 0, 1, 1);

        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 1, 2, 1, 1);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 1, 1, 1, 1);

        label_12 = new QLabel(layoutWidget);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout->addWidget(label_12, 2, 0, 1, 1);

        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout->addWidget(label_11, 1, 3, 1, 1);

        label_15 = new QLabel(layoutWidget);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout->addWidget(label_15, 2, 3, 1, 1);

        pushButton_7 = new QPushButton(layoutWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setCheckable(true);

        gridLayout->addWidget(pushButton_7, 3, 0, 1, 1);

        label_14 = new QLabel(layoutWidget);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout->addWidget(label_14, 2, 2, 1, 1);

        pushButton_10 = new QPushButton(layoutWidget);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setCheckable(true);

        gridLayout->addWidget(pushButton_10, 3, 3, 1, 1);

        pushButton_9 = new QPushButton(layoutWidget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setCheckable(true);

        gridLayout->addWidget(pushButton_9, 3, 2, 1, 1);

        pushButton_8 = new QPushButton(layoutWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setCheckable(true);

        gridLayout->addWidget(pushButton_8, 3, 1, 1, 1);

        label_13 = new QLabel(layoutWidget);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout->addWidget(label_13, 2, 1, 1, 1);

        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(201, 50, 301, 81));
        btnJogCtrl = new QPushButton(groupBox);
        btnJogCtrl->setObjectName(QStringLiteral("btnJogCtrl"));
        btnJogCtrl->setGeometry(QRect(20, 30, 91, 31));
        spbJogSpd = new QDoubleSpinBox(groupBox);
        spbJogSpd->setObjectName(QStringLiteral("spbJogSpd"));
        spbJogSpd->setGeometry(QRect(130, 30, 141, 31));
        spbJogSpd->setDecimals(2);
        spbJogSpd->setMinimum(-600);
        spbJogSpd->setMaximum(600);
        textBrowser = new QTextBrowser(tab);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(11, 228, 171, 231));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy);
        textBrowser->setMinimumSize(QSize(171, 0));
        QGBSerialConfig = new QGroupBox(tab);
        QGBSerialConfig->setObjectName(QStringLiteral("QGBSerialConfig"));
        QGBSerialConfig->setEnabled(true);
        QGBSerialConfig->setGeometry(QRect(11, 11, 171, 211));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(QGBSerialConfig->sizePolicy().hasHeightForWidth());
        QGBSerialConfig->setSizePolicy(sizePolicy1);
        QGBSerialConfig->setMinimumSize(QSize(171, 211));
        QGBSerialConfig->setMaximumSize(QSize(171, 211));
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
        btnOpenPort->setEnabled(true);
        btnOpenPort->setGeometry(QRect(69, 160, 91, 31));
        btnOpenPort->setStyleSheet(QStringLiteral(""));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/action/res/action/centrejust.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QStringLiteral(":/action/res/action/stock_stop.png"), QSize(), QIcon::Normal, QIcon::On);
        btnOpenPort->setIcon(icon1);
        btnOpenPort->setCheckable(true);
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
        lblVerify = new QLabel(formLayoutWidget);
        lblVerify->setObjectName(QStringLiteral("lblVerify"));

        gridLayout_3->addWidget(lblVerify, 3, 0, 1, 1);

        cbbDataBit = new QComboBox(formLayoutWidget);
        cbbDataBit->setObjectName(QStringLiteral("cbbDataBit"));
        cbbDataBit->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout_3->addWidget(cbbDataBit, 2, 1, 1, 1);

        lblPortNum = new QLabel(formLayoutWidget);
        lblPortNum->setObjectName(QStringLiteral("lblPortNum"));

        gridLayout_3->addWidget(lblPortNum, 0, 0, 1, 1);

        lblStopBit = new QLabel(formLayoutWidget);
        lblStopBit->setObjectName(QStringLiteral("lblStopBit"));

        gridLayout_3->addWidget(lblStopBit, 4, 0, 1, 1);

        lblBaudRate = new QLabel(formLayoutWidget);
        lblBaudRate->setObjectName(QStringLiteral("lblBaudRate"));

        gridLayout_3->addWidget(lblBaudRate, 1, 0, 1, 1);

        cbbPortNum = new QComboBox(formLayoutWidget);
        cbbPortNum->setObjectName(QStringLiteral("cbbPortNum"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(cbbPortNum->sizePolicy().hasHeightForWidth());
        cbbPortNum->setSizePolicy(sizePolicy2);
        cbbPortNum->setMaxVisibleItems(20);
        cbbPortNum->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        cbbPortNum->setMinimumContentsLength(0);

        gridLayout_3->addWidget(cbbPortNum, 0, 1, 1, 1);

        cbbVerify = new QComboBox(formLayoutWidget);
        cbbVerify->setObjectName(QStringLiteral("cbbVerify"));
        cbbVerify->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout_3->addWidget(cbbVerify, 3, 1, 1, 1);

        cbbStopBit = new QComboBox(formLayoutWidget);
        cbbStopBit->setObjectName(QStringLiteral("cbbStopBit"));
        cbbStopBit->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout_3->addWidget(cbbStopBit, 4, 1, 1, 1);

        cbbBaud = new QComboBox(formLayoutWidget);
        cbbBaud->setObjectName(QStringLiteral("cbbBaud"));
        cbbBaud->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout_3->addWidget(cbbBaud, 1, 1, 1, 1);

        lblDataBit = new QLabel(formLayoutWidget);
        lblDataBit->setObjectName(QStringLiteral("lblDataBit"));

        gridLayout_3->addWidget(lblDataBit, 2, 0, 1, 1);

        btnRefresh = new QPushButton(QGBSerialConfig);
        btnRefresh->setObjectName(QStringLiteral("btnRefresh"));
        btnRefresh->setGeometry(QRect(11, 160, 51, 31));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/action/res/action/stock_refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRefresh->setIcon(icon2);
        chkFlowCtrlDTR = new QCheckBox(QGBSerialConfig);
        chkFlowCtrlDTR->setObjectName(QStringLiteral("chkFlowCtrlDTR"));
        chkFlowCtrlDTR->setGeometry(QRect(31, 190, 43, 18));
        chkFlowCtrlRTS = new QCheckBox(QGBSerialConfig);
        chkFlowCtrlRTS->setObjectName(QStringLiteral("chkFlowCtrlRTS"));
        chkFlowCtrlRTS->setGeometry(QRect(80, 190, 43, 18));
        textBrowser_2 = new QTextBrowser(tab);
        textBrowser_2->setObjectName(QStringLiteral("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(530, 230, 361, 231));
        layoutWidget1 = new QWidget(tab);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(201, 11, 301, 31));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        btnConnect = new QPushButton(layoutWidget1);
        btnConnect->setObjectName(QStringLiteral("btnConnect"));

        horizontalLayout_2->addWidget(btnConnect);

        lblDeviceName = new QLabel(layoutWidget1);
        lblDeviceName->setObjectName(QStringLiteral("lblDeviceName"));
        lblDeviceName->setStyleSheet(QStringLiteral(""));

        horizontalLayout_2->addWidget(lblDeviceName);

        tabWidget->addTab(tab, QString());

        gridLayout_2->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(StepperMotor);
        QObject::connect(posStop, SIGNAL(clicked()), spdStop, SLOT(click()));

        tabWidget->setCurrentIndex(0);
        btnOpenPort->setDefault(false);


        QMetaObject::connectSlotsByName(StepperMotor);
    } // setupUi

    void retranslateUi(QWidget *StepperMotor)
    {
        StepperMotor->setWindowTitle(QApplication::translate("StepperMotor", "StepperMotor", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("StepperMotor", "\344\275\215\347\275\256\346\216\247\345\210\266\346\250\241\345\274\217", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("StepperMotor", "\347\273\206\345\210\206\346\225\26032", Q_NULLPTR)
        );
        spinBox->setSuffix(QString());
        spinBox->setPrefix(QApplication::translate("StepperMotor", "\350\204\211\345\206\262\346\225\260", Q_NULLPTR));
        posStart->setText(QApplication::translate("StepperMotor", "\345\220\257\345\212\250", Q_NULLPTR));
        posStop->setText(QApplication::translate("StepperMotor", "\346\232\202\345\201\234", Q_NULLPTR));
        label_3->setText(QApplication::translate("StepperMotor", "\345\234\210\346\225\260:", Q_NULLPTR));
        doubleSpinBox_2->setPrefix(QApplication::translate("StepperMotor", "\351\200\237\345\272\246\345\200\274", Q_NULLPTR));
        doubleSpinBox_2->setSuffix(QApplication::translate("StepperMotor", "rpm", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("StepperMotor", "\351\200\237\345\272\246\346\216\247\345\210\266\346\250\241\345\274\217", Q_NULLPTR));
        spdStart->setText(QApplication::translate("StepperMotor", "\345\220\257\345\212\250", Q_NULLPTR));
        spdStop->setText(QApplication::translate("StepperMotor", "\346\232\202\345\201\234", Q_NULLPTR));
        label_2->setText(QApplication::translate("StepperMotor", "\344\275\277\347\224\250\346\227\213\351\222\256\346\216\247\345\210\266\347\224\265\346\234\272\350\275\254\351\200\237", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("StepperMotor", "\351\200\232\347\224\250\350\276\223\345\205\245\350\276\223\345\207\272\347\212\266\346\200\201", Q_NULLPTR));
        label_7->setText(QApplication::translate("StepperMotor", "IN1", Q_NULLPTR));
        label_5->setText(QApplication::translate("StepperMotor", "IN1", Q_NULLPTR));
        label_4->setText(QApplication::translate("StepperMotor", "IN1", Q_NULLPTR));
        label_6->setText(QApplication::translate("StepperMotor", "IN1", Q_NULLPTR));
        label_10->setText(QApplication::translate("StepperMotor", "IN1", Q_NULLPTR));
        label_9->setText(QApplication::translate("StepperMotor", "IN1", Q_NULLPTR));
        label_8->setText(QApplication::translate("StepperMotor", "IN1", Q_NULLPTR));
        label_12->setText(QApplication::translate("StepperMotor", "IN1", Q_NULLPTR));
        label_11->setText(QApplication::translate("StepperMotor", "IN1", Q_NULLPTR));
        label_15->setText(QApplication::translate("StepperMotor", "IN1", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("StepperMotor", "OUT1", Q_NULLPTR));
        label_14->setText(QApplication::translate("StepperMotor", "IN1", Q_NULLPTR));
        pushButton_10->setText(QApplication::translate("StepperMotor", "OUT1", Q_NULLPTR));
        pushButton_9->setText(QApplication::translate("StepperMotor", "OUT1", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("StepperMotor", "OUT1", Q_NULLPTR));
        label_13->setText(QApplication::translate("StepperMotor", "IN1", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("StepperMotor", "\347\202\271\345\212\250\346\216\247\345\210\266", Q_NULLPTR));
        btnJogCtrl->setText(QApplication::translate("StepperMotor", "\347\202\271\345\212\250\346\216\247\345\210\266", Q_NULLPTR));
        spbJogSpd->setPrefix(QApplication::translate("StepperMotor", "\351\200\237\345\272\246\345\200\274", Q_NULLPTR));
        spbJogSpd->setSuffix(QApplication::translate("StepperMotor", "rpm", Q_NULLPTR));
        QGBSerialConfig->setTitle(QApplication::translate("StepperMotor", "\344\270\262\345\217\243\350\256\276\347\275\256", Q_NULLPTR));
        btnOpenPort->setText(QApplication::translate("StepperMotor", "\346\211\223\345\274\200\344\270\262\345\217\243", Q_NULLPTR));
        lblVerify->setText(QApplication::translate("StepperMotor", "\346\240\241\351\252\214", Q_NULLPTR));
        lblPortNum->setText(QApplication::translate("StepperMotor", "\347\253\257\345\217\243\345\217\267", Q_NULLPTR));
        lblStopBit->setText(QApplication::translate("StepperMotor", "\345\201\234\346\255\242\344\275\215", Q_NULLPTR));
        lblBaudRate->setText(QApplication::translate("StepperMotor", "\346\263\242\347\211\271\347\216\207", Q_NULLPTR));
        lblDataBit->setText(QApplication::translate("StepperMotor", "\346\225\260\346\215\256\344\275\215", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        btnRefresh->setToolTip(QApplication::translate("StepperMotor", "\345\210\267\346\226\260\347\253\257\345\217\243\345\217\267", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnRefresh->setText(QApplication::translate("StepperMotor", "\345\210\267\346\226\260", Q_NULLPTR));
        chkFlowCtrlDTR->setText(QApplication::translate("StepperMotor", "DTR", Q_NULLPTR));
        chkFlowCtrlRTS->setText(QApplication::translate("StepperMotor", "RTS", Q_NULLPTR));
        textBrowser_2->setHtml(QApplication::translate("StepperMotor", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\347\254\254\344\270\211\346\226\271\347\232\204\346\263\225\345\270\210\346\211\223\345\217\221<span style=\" font-weight:600;\">\346\226\257\350\222\202\350\212\254\346\230\257\346\211\223\345\217\221\347\210\261\347\232\204\346\230\257\347\232\204\345\217\221\347\224\237\347\232\204</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">\346\263\225\350\241\250\347\216\260\351\235\236\345\270\270vcxvcxvxczxcvzxc </span></p>\n"
"<p style=\" margin-to"
                        "p:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\263\225\350\247\204\350\247\204\350\214\203\347\232\204\351\235\236\345\256\230\346\226\271\345\205\254\345\217\270\347\232\204\346\263\225\345\233\275</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\263\225\345\233\275\345\210\206\351\232\224\347\254\246\350\213\237\345\257\214\350\264\265</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/action/res/action/document-open-recent.png\" /></p></body></html>", Q_NULLPTR));
        btnConnect->setText(QApplication::translate("StepperMotor", "\350\277\236\346\216\245\350\256\276\345\244\207", Q_NULLPTR));
        lblDeviceName->setText(QApplication::translate("StepperMotor", "No connected devices", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("StepperMotor", "\346\255\245\350\277\233\347\224\265\346\234\2721", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class StepperMotor: public Ui_StepperMotor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STEPPERMOTOR_H
