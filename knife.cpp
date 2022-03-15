#include "knife.h"

Knife::Knife(QObject *parent) :
    QObject(parent)
{
    state = true; //(true/false) нож свободен или заблокирован
}
void Knife::put()// нож вернули на место и он доступен
{
    state = true;
    return;
}

void Knife::pull() // нож взят и недоступен
{
    state = false;
    return;
}

bool Knife::getState() // статус доступности ножа
{
    return state;
}
