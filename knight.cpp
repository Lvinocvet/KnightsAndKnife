#include "knight.h"

// Класс Knight(Рыцарь)
Knight::Knight(QObject *parent, const int &_id) :
    QThread(parent)
{
    id = _id;
    countEat = 0;
    countHistory = 0;
    state = "Arrives";
    active = true;



}

// Установка ID
void Knight::setID(const quint32 &_id){
    id = _id;
    return;
}
// Установка ножей
void Knight::setKnives(Knife* l,Knife* r){
    left = l;
    right = r;
    return;
}
// установка арбитра
void Knight::setArbitr(Arbitr* a)
{
    arbitr = a;
    return;
}

// Установка State
void Knight::setState(const quint32 &id,QString &_state)
{
    state = _state;
    emit SetLabel(id,state); // Вывод в таблицу состояния рыцаря (label)
    return;
}

// Увеличение счетчика приемов пищи для рыцаря
void Knight::setCountEat(const quint32 &_id)
{
    countEat +=1;
    emit printCoutEat(id,countEat); // Сигнал для отображения в таблице приемов пищи (label)
    return;
}

// Увеличение счетчика рассказанных историй для рыцаря
void Knight::setCountHistory(const quint32 &_id){
    countHistory +=1;
    emit printCoutHistory(id,countHistory); // Сигнал для отображения в таблице рассказанных историй(label)
    return;
}

// Моделирование поведения рыцаря за столом
void Knight::run(){
    QApplication::processEvents();

    for(int i=0; i<20; ++i){ // Симуляция работает до того момента, как рыцарь не примит пищу DINNERS_NUM раз
        k_history();
        if (active == false) {  break; } // Принудительная остановка через кнопку stop (путем изменения переменной st)
        while(!arbitr->hungryRequest(left,right)){
            QString vsp = "Waiting";
            setState(id,vsp); // Изменение состояня рыцаря
            emit PrintToList(id, "Waiting"); // Сигнал для вывода в консоль (listwidget)
            mutex.lock();
            cv.wait(&mutex);
            mutex.unlock();
        }
        emit KnivesStatus(id,id+1,"Blocked"); // Сигнал для вывода в таблицу и консоль информации о блокировке ножа(label)
        k_eat();
        arbitr->finishRequest(left,right); // Освобождение ножей
        emit KnivesStatus(id,id+1,"Free");// Сигнал для вывода в таблицу и консоль информации о освобождении ножа(label)
    }
    return;
}

// Моделирование рассказа историй
void Knight::k_history(){
    QString vsp = "Tells a story";
    setState(id,vsp); // Изменение состояня рыцаря
    emit PrintToList(id, "Tells a story"); // Сигнал для вывода в консоль информации о том, что рыцарь рассказывает исторю (listwidget)
    setCountHistory(id);
    qsrand((uint)id);
    sleep(qrand()%5 + (5/4)); // Искусственная задержка
}

// Моделирование приема пищи
void Knight::k_eat(){
    QString vsp = "Eating";
    setState(id,vsp); // Изменение состояня рыцаря
    emit PrintToList(id, "Eating"); // Сигнал для вывода в таблицу информации о том, что рыцарь рассказывает Принемает пищу (label)
    setCountEat(id);
    qsrand((uint)id);
    sleep(qrand()%5 + (5/4) );  // задержка
}

// Метод для изменения переменной st (чтобы остановить симуляцию)
void Knight::stop(const quint16 s)
{
   active = false;
}

// отключает Mutex в Knight::run()
void Knight::Wakeup()
{
    cv.wakeAll();
}
