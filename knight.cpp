#include "knight.h"

// ����� Knight(������)
Knight::Knight(QObject *parent, const int &_id) :
    QThread(parent)
{
    id = _id;
    countEat = 0;
    countHistory = 0;
    state = "Arrives";
    active = true;



}

// ��������� ID
void Knight::setID(const quint32 &_id){
    id = _id;
    return;
}
// ��������� �����
void Knight::setKnives(Knife* l,Knife* r){
    left = l;
    right = r;
    return;
}
// ��������� �������
void Knight::setArbitr(Arbitr* a)
{
    arbitr = a;
    return;
}

// ��������� State
void Knight::setState(const quint32 &id,QString &_state)
{
    state = _state;
    emit SetLabel(id,state); // ����� � ������� ��������� ������ (label)
    return;
}

// ���������� �������� ������� ���� ��� ������
void Knight::setCountEat(const quint32 &_id)
{
    countEat +=1;
    emit printCoutEat(id,countEat); // ������ ��� ����������� � ������� ������� ���� (label)
    return;
}

// ���������� �������� ������������ ������� ��� ������
void Knight::setCountHistory(const quint32 &_id){
    countHistory +=1;
    emit printCoutHistory(id,countHistory); // ������ ��� ����������� � ������� ������������ �������(label)
    return;
}

// ������������� ��������� ������ �� ������
void Knight::run(){
    QApplication::processEvents();

    for(int i=0; i<20; ++i){ // ��������� �������� �� ���� �������, ��� ������ �� ������ ���� DINNERS_NUM ���
        k_history();
        if (active == false) {  break; } // �������������� ��������� ����� ������ stop (����� ��������� ���������� st)
        while(!arbitr->hungryRequest(left,right)){
            QString vsp = "Waiting";
            setState(id,vsp); // ��������� �������� ������
            emit PrintToList(id, "Waiting"); // ������ ��� ������ � ������� (listwidget)
            mutex.lock();
            cv.wait(&mutex);
            mutex.unlock();
        }
        emit KnivesStatus(id,id+1,"Blocked"); // ������ ��� ������ � ������� � ������� ���������� � ���������� ����(label)
        k_eat();
        arbitr->finishRequest(left,right); // ������������ �����
        emit KnivesStatus(id,id+1,"Free");// ������ ��� ������ � ������� � ������� ���������� � ������������ ����(label)
    }
    return;
}

// ������������� �������� �������
void Knight::k_history(){
    QString vsp = "Tells a story";
    setState(id,vsp); // ��������� �������� ������
    emit PrintToList(id, "Tells a story"); // ������ ��� ������ � ������� ���������� � ���, ��� ������ ������������ ������ (listwidget)
    setCountHistory(id);
    qsrand((uint)id);
    sleep(qrand()%5 + (5/4)); // ������������� ��������
}

// ������������� ������ ����
void Knight::k_eat(){
    QString vsp = "Eating";
    setState(id,vsp); // ��������� �������� ������
    emit PrintToList(id, "Eating"); // ������ ��� ������ � ������� ���������� � ���, ��� ������ ������������ ��������� ���� (label)
    setCountEat(id);
    qsrand((uint)id);
    sleep(qrand()%5 + (5/4) );  // ��������
}

// ����� ��� ��������� ���������� st (����� ���������� ���������)
void Knight::stop(const quint16 s)
{
   active = false;
}

// ��������� Mutex � Knight::run()
void Knight::Wakeup()
{
    cv.wakeAll();
}
