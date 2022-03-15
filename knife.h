#ifndef KNIFE_H
#define KNIFE_H

#include <QObject>

class Knife : public QObject
{
    Q_OBJECT
public:
    explicit Knife(QObject *parent = 0);
    bool state;
    void put();
    void pull();
    bool getState();
signals:
    
public slots:
    
};

#endif // KNIFE_H
