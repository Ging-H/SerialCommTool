#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../SubWindow/SerialAssistant/serialassistant.h"
#include "../SubWindow/Steppermotor/steppermotor.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    enum SubItem {
        None         = 0,
        Serial       = 1,
        SMotor       = 2,
        PID          = 3,
        Modbus       = 4,
        Net          = 5,
        GSM          = 6,
        UnknownBaud  = -1
    };
    Q_ENUM(SubItem)
    SubItem subitem = None;

    SerialAssistant *serial;
    StepperMotor *stepperMotor;
    void resizeForSerial();
    void unloadSubItem(SubItem &current);


public slots:
    void slots_btnClicked(QAbstractButton *button);

private slots:


    void on_TBLink_triggered();

    void on_updataLink_triggered();

private:
    Ui::MainWindow *ui;
    QButtonGroup *pBtnGroup;

};

#endif // MAINWINDOW_H
