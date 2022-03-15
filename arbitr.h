#ifndef ARBITR_H
#define ARBITR_H

#include <QThread>
#include <QDebug>
#include <QProcess>
#include "knife.h"
#include <QString>
#include <QMutex>


// Класс Arbitr
class Arbitr : public QThread
{
    Q_OBJECT
public:
    explicit Arbitr(QObject *parent = 0);
    bool hungryRequest(Knife* l,Knife* r);
    void finishRequest(Knife* l,Knife* r);

signals:
    void WakeAll();

public slots:

private:
    QMutex mutex;
};

#endif // ARBITR_H
