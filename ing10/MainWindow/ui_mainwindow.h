/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *TBLink;
    QAction *updataLink;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QPushButton *btnSerial;
    QPushButton *btnStepMotor;
    QPushButton *btnPID;
    QPushButton *btnModbus;
    QPushButton *btnNet;
    QPushButton *btnGSM;
    QGridLayout *subPanel;
    QSpacerItem *horizontalSpacer;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(697, 367);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(574, 78));
        TBLink = new QAction(MainWindow);
        TBLink->setObjectName(QStringLiteral("TBLink"));
        updataLink = new QAction(MainWindow);
        updataLink->setObjectName(QStringLiteral("updataLink"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        btnSerial = new QPushButton(centralWidget);
        btnSerial->setObjectName(QStringLiteral("btnSerial"));
        btnSerial->setMinimumSize(QSize(0, 25));
        btnSerial->setStyleSheet(QStringLiteral(""));
        btnSerial->setCheckable(true);

        gridLayout_2->addWidget(btnSerial, 0, 0, 1, 1);

        btnStepMotor = new QPushButton(centralWidget);
        btnStepMotor->setObjectName(QStringLiteral("btnStepMotor"));
        btnStepMotor->setMinimumSize(QSize(0, 25));
        btnStepMotor->setCheckable(true);

        gridLayout_2->addWidget(btnStepMotor, 0, 1, 1, 1);

        btnPID = new QPushButton(centralWidget);
        btnPID->setObjectName(QStringLiteral("btnPID"));
        btnPID->setMinimumSize(QSize(0, 25));
        btnPID->setCheckable(true);

        gridLayout_2->addWidget(btnPID, 0, 2, 1, 1);

        btnModbus = new QPushButton(centralWidget);
        btnModbus->setObjectName(QStringLiteral("btnModbus"));
        btnModbus->setMinimumSize(QSize(0, 25));
        btnModbus->setCheckable(true);

        gridLayout_2->addWidget(btnModbus, 0, 3, 1, 1);

        btnNet = new QPushButton(centralWidget);
        btnNet->setObjectName(QStringLiteral("btnNet"));
        btnNet->setMinimumSize(QSize(0, 25));
        btnNet->setCheckable(true);

        gridLayout_2->addWidget(btnNet, 0, 4, 1, 1);

        btnGSM = new QPushButton(centralWidget);
        btnGSM->setObjectName(QStringLiteral("btnGSM"));
        btnGSM->setMinimumSize(QSize(0, 25));
        btnGSM->setCheckable(true);

        gridLayout_2->addWidget(btnGSM, 0, 5, 1, 1);

        subPanel = new QGridLayout();
        subPanel->setSpacing(6);
        subPanel->setObjectName(QStringLiteral("subPanel"));

        gridLayout_2->addLayout(subPanel, 1, 0, 1, 7);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 6, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(TBLink);
        toolBar->addSeparator();
        toolBar->addAction(updataLink);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        TBLink->setText(QApplication::translate("MainWindow", "\346\267\230\345\256\235\351\223\276\346\216\245", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        TBLink->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>\346\211\223\345\274\200\346\267\230\345\256\235\351\223\276\346\216\245</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        updataLink->setText(QApplication::translate("MainWindow", "\350\265\204\346\226\231\346\233\264\346\226\260", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        updataLink->setToolTip(QApplication::translate("MainWindow", "\350\265\204\346\226\231\346\233\264\346\226\260\344\270\213\350\275\275\351\223\276\346\216\245", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnSerial->setText(QApplication::translate("MainWindow", "\344\270\262\345\217\243\345\212\251\346\211\213", Q_NULLPTR));
        btnStepMotor->setText(QApplication::translate("MainWindow", "\346\255\245\350\277\233\347\224\265\346\234\272\346\216\247\345\210\266", Q_NULLPTR));
        btnPID->setText(QApplication::translate("MainWindow", "PID\345\212\251\346\211\213", Q_NULLPTR));
        btnModbus->setText(QApplication::translate("MainWindow", "Modbus\345\215\217\350\256\256", Q_NULLPTR));
        btnNet->setText(QApplication::translate("MainWindow", "\347\275\221\347\273\234\351\200\232\344\277\241\345\212\251\346\211\213", Q_NULLPTR));
        btnGSM->setText(QApplication::translate("MainWindow", "GSM\350\260\203\350\257\225\345\212\251\346\211\213", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
