#ifndef BASESERIALCOMM_H
#define BASESERIALCOMM_H

#include <QSerialPort>
#include <QSerialPortInfo>


#include <QObject>

class BaseSerialComm : public QObject
{
    Q_OBJECT
public:
    explicit BaseSerialComm(QObject *parent = nullptr);

signals:

public slots:



};

#endif // BASESERIALCOMM_H
