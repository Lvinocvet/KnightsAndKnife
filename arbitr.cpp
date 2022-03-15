#include "arbitr.h"
#include "mainwindow.h"

// Класс Atbitr
Arbitr::Arbitr(QObject *parent) :
    QThread(parent)
{
}

// Получение разрешения, чтобы взять ножи и начать питаться
bool Arbitr::hungryRequest(Knife* l,Knife* r){
    mutex.lock();
    bool answer = l->getState() && r->getState(); // Если ножи свободны - берет, до этого ждет
    if(answer){
        l->pull();
        r->pull();
    }
    mutex.unlock();
    return answer;
}

// После питания, освобождение ножей
void Arbitr::finishRequest(Knife* l,Knife* r){
    mutex.lock();
    l->put();
    r->put();
    emit WakeAll();
    mutex.unlock();
    return;
}




