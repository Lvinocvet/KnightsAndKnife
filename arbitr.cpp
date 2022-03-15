#include "arbitr.h"
#include "mainwindow.h"

// ����� Atbitr
Arbitr::Arbitr(QObject *parent) :
    QThread(parent)
{
}

// ��������� ����������, ����� ����� ���� � ������ ��������
bool Arbitr::hungryRequest(Knife* l,Knife* r){
    mutex.lock();
    bool answer = l->getState() && r->getState(); // ���� ���� �������� - �����, �� ����� ����
    if(answer){
        l->pull();
        r->pull();
    }
    mutex.unlock();
    return answer;
}

// ����� �������, ������������ �����
void Arbitr::finishRequest(Knife* l,Knife* r){
    mutex.lock();
    l->put();
    r->put();
    emit WakeAll();
    mutex.unlock();
    return;
}




