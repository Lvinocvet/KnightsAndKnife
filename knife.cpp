#include "knife.h"

Knife::Knife(QObject *parent) :
    QObject(parent)
{
    state = true; //(true/false) ��� �������� ��� ������������
}
void Knife::put()// ��� ������� �� ����� � �� ��������
{
    state = true;
    return;
}

void Knife::pull() // ��� ���� � ����������
{
    state = false;
    return;
}

bool Knife::getState() // ������ ����������� ����
{
    return state;
}
