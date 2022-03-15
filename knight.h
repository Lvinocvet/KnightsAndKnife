#ifndef KNIGHT_H
#define KNIGHT_H

#include <QThread>
#include <QString>
#include <QWaitCondition>
#include <QMutex>
#include <QApplication>
#include "arbitr.h"
#include "knife.h"

// Класс Knight
class Knight : public QThread
{
    Q_OBJECT
public:
    explicit Knight(QObject *parent = 0, const int &_id = 0);
    void run();
    void setID(const quint32 &_id);
    void setKnives(Knife* l,Knife* r);
    void setArbitr(Arbitr* a);
    void setCountEat(const quint32 &_id);
    void setCountHistory(const quint32 &_id);
    void setState(const quint32 &_id,QString &_state);
    int countEat;
    int countHistory;
    QString state;
    bool active;



signals:
    void PrintToList(const quint16 &id, const QString str);
    void printCoutEat(const quint16 &id, const int count);
    void printCoutHistory(const quint16 &id, const int count);
    void KnivesStatus(const int &lknife, const int &rknife,const QString str);
    void SetLabel(const quint16 &id, const QString str);

public slots:
    void stop(const quint16 s);
    void Wakeup();

private:
    void k_history();
    void k_eat();
    Knife* left;
    Knife* right;
    Arbitr* arbitr;


    quint32 id;
    QWaitCondition cv;
    QMutex mutex;

};

#endif // KNIGHT_H

