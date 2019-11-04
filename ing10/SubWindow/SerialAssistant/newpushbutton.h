#ifndef NEWPUSHBUTTON_H
#define NEWPUSHBUTTON_H

#include <QObject>
#include <QPushButton>
#include <QLineEdit>

class NewPushButton:public QPushButton
{
public:
   explicit NewPushButton(QWidget *parent = Q_NULLPTR);
   ~NewPushButton();
    QString (QLineEdit::*text()) ;

};

#endif // NEWPUSHBUTTON_H
