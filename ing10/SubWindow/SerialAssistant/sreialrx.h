#ifndef SREIALRX_H
#define SREIALRX_H

#include <QObject>
#include <QPushButton>

class SreialRx :public QPushButton
{
    Q_OBJECT
public:
    SreialRx();
    QString *lineEditText;
};

#endif // SREIALRX_H
