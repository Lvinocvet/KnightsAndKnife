#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCoreApplication>
#include <QObject>
#include <QListWidget>
#include <QString>
#include <QPixmap>
#include <QWaitCondition>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

// Заполнение статуса рыцарей в таблице (label)
void MainWindow::SetLabel(const quint16 &id, const QString str)
{
    if (id == 0)
    {
        ui->label_state_1->setText(str);
    }
    else if (id == 1)
    {
        ui->label_state_2->setText(str);
    }
    else if (id == 2)
    {
        ui->label_state_3->setText(str);
    }
    else if (id == 3)
    {
        ui->label_state_4->setText(str);
    }
    else if (id == 4)
    {
        ui->label_state_5->setText(str);
    }
}
// Вывод в консоль действия (listWidget)
void MainWindow::PrintToList(const quint16 &id, const QString str)
{
    QString name;
    if (id == 0){name = "Artur : ";}
    if (id == 1){name = "Lancelot : ";}
    if (id == 2){name = "Galaxad : ";}
    if (id == 3){name = "Persival : ";}
    if (id == 4){name = "Mordred : ";}

    ui->listWidget->addItem(name + str);
}

// Вывод в таблицу счетчика приемов пищи
void MainWindow::printCoutEat(const quint16 &id, const int count)
{
    if (id == 0) { ui->label_eat_1->setText(QString::number(count));}
    if (id == 1) { ui->label_eat_2->setText(QString::number(count));}
    if (id == 2) { ui->label_eat_3->setText(QString::number(count));}
    if (id == 3) { ui->label_eat_4->setText(QString::number(count));}
    if (id == 4) { ui->label_eat_5->setText(QString::number(count));}
}
// Вывод в таблицу счетчика рассказаных историй
void MainWindow::printCoutHistory(const quint16 &id, const int count)
{
    if (id == 0) { ui->label_history_1->setText(QString::number(count));}
    if (id == 1) { ui->label_history_2->setText(QString::number(count));}
    if (id == 2) { ui->label_history_3->setText(QString::number(count));}
    if (id == 3) { ui->label_history_4->setText(QString::number(count));}
    if (id == 4) { ui->label_history_5->setText(QString::number(count));}
}

// Вывод в таблицу статуса ножей, анимация ножей
void MainWindow::KnivesStatus(const int &lknife, const int &rknife,const QString str)
{
    // Ножи в таблицу
    // Левый нож
    if (lknife == 0) { ui->label_knifeL_1->setText(str);ui->label_knifeR_1->setText(str);}
    if (lknife == 1) { ui->label_knifeL_2->setText(str);ui->label_knifeR_2->setText(str);}
    if (lknife == 2) { ui->label_knifeL_3->setText(str);ui->label_knifeR_3->setText(str);}
    if (lknife == 3) { ui->label_knifeL_4->setText(str);ui->label_knifeR_4->setText(str);}
    if (lknife == 4) { ui->label_knifeL_5->setText(str);ui->label_knifeR_5->setText(str);}
    // Правый нож
    if (rknife == 1) { ui->label_knifeR_2->setText(str);}
    if (rknife == 2) { ui->label_knifeR_3->setText(str);}
    if (rknife == 3) { ui->label_knifeR_4->setText(str);}
    if (rknife == 4) { ui->label_knifeR_5->setText(str);}
    if (rknife == 5) { ui->label_knifeR_1->setText(str);}

    QString name;
    if (lknife== 0){name = "Artur : ";}
    if (lknife == 1){name = "Lancelot : ";}
    if (lknife == 2){name = "Galaxad : ";}
    if (lknife == 3){name = "Persival : ";}
    if (lknife == 4){name = "Mordred : ";}
// Анимация ножей
    QString txt;
    if (str == "Blocked")
    {
        txt = "put a knife";
        QPixmap pix(":/img/img/knife2.jpg");
        int w = ui->label_image_1->width();
        int h = ui->label_image_1->width();
        // Левые ножи
     if (lknife == 0) { ui->label_image_1->setPixmap(pix.scaled(w,h, Qt::KeepAspectRatio)); }
     if (lknife == 1) { ui->label_image_2->setPixmap(pix.scaled(w,h, Qt::KeepAspectRatio));}
     if (lknife == 2) { ui->label_image_3->setPixmap(pix.scaled(w,h, Qt::KeepAspectRatio));}
     if (lknife == 3) { ui->label_image_4->setPixmap(pix.scaled(w,h, Qt::KeepAspectRatio));}
     if (lknife == 4) { ui->label_image_5->setPixmap(pix.scaled(w,h, Qt::KeepAspectRatio));}
     // правые ножи
     if (rknife == 1) { ui->label_image_2->setPixmap(pix.scaled(w,h, Qt::KeepAspectRatio)); }
     if (rknife == 2) { ui->label_image_3->setPixmap(pix.scaled(w,h, Qt::KeepAspectRatio));}
     if (rknife == 3) { ui->label_image_4->setPixmap(pix.scaled(w,h, Qt::KeepAspectRatio));}
     if (rknife == 4) { ui->label_image_5->setPixmap(pix.scaled(w,h, Qt::KeepAspectRatio));}
     if (rknife == 5) { ui->label_image_1->setPixmap(pix.scaled(w,h, Qt::KeepAspectRatio));}
    }
    else
    {
        txt = "took a knife";
        QPixmap pix(":/img/img/knife.jpg");
        int w = ui->label_image_1->width();
        int h = ui->label_image_1->width();
        // Левые ножи
     if (lknife == 0) { ui->label_image_1->setPixmap(pix.scaled(w,h, Qt::KeepAspectRatio)); }
     if (lknife == 1) { ui->label_image_2->setPixmap(pix.scaled(w,h, Qt::KeepAspectRatio));}
     if (lknife == 2) { ui->label_image_3->setPixmap(pix.scaled(w,h, Qt::KeepAspectRatio));}
     if (lknife == 3) { ui->label_image_4->setPixmap(pix.scaled(w,h, Qt::KeepAspectRatio));}
     if (lknife == 4) { ui->label_image_5->setPixmap(pix.scaled(w,h, Qt::KeepAspectRatio));}
     // правые ножи
     if (rknife == 1) { ui->label_image_2->setPixmap(pix.scaled(w,h, Qt::KeepAspectRatio)); }
     if (rknife == 2) { ui->label_image_3->setPixmap(pix.scaled(w,h, Qt::KeepAspectRatio));}
     if (rknife == 3) { ui->label_image_4->setPixmap(pix.scaled(w,h, Qt::KeepAspectRatio));}
     if (rknife == 4) { ui->label_image_5->setPixmap(pix.scaled(w,h, Qt::KeepAspectRatio));}
     if (rknife == 5) { ui->label_image_1->setPixmap(pix.scaled(w,h, Qt::KeepAspectRatio));}
    }


    ui->listWidget->addItem(name + txt);
}

// Нажатие на кнопку старт
void MainWindow::on_pushButtonStart_clicked()
{
    QString str = ui->lineEdit->text();
    int n = str.toInt(); // кол-во рыцарей


    Knife** knivves = new Knife*[n];
    for (int i = 0; i < n; i++)
    {
        knivves[i] = new Knife();
    }

    arbitr = new Arbitr; // Обьект класса Arbitr
    arbitr->start();
    Knight **knights = new Knight*[n];


    for(int i=0; i<n; ++i){
        knights[i] = new Knight(0,i);
        knights[i]->setID(i);
        knights[i]->setArbitr(arbitr);


        Knife* l;
        Knife* r;

        l = knivves[i];
        if (i == n-1)
        {
            r = knivves[0];
        }
        else
        {
           r = knivves[i+1];
        }

        knights[i]->setKnives(l,r);





        // Прием всех сигналов в этм месте
        QObject::connect(arbitr, SIGNAL(WakeAll()),knights[i],SLOT(Wakeup()));
        QObject::connect(knights[i], SIGNAL(SetLabel(quint16,QString)), this,SLOT(SetLabel(quint16,QString)));
        QObject::connect(knights[i], SIGNAL(PrintToList(quint16,QString)), this,SLOT(PrintToList(quint16,QString)));
        QObject::connect(knights[i], SIGNAL(printCoutEat(quint16,int)),this,SLOT(printCoutEat(quint16,int)));
        QObject::connect(knights[i], SIGNAL(printCoutHistory(quint16,int)),this,SLOT(printCoutHistory(quint16,int)));
        QObject::connect(knights[i],SIGNAL(KnivesStatus(int,int,QString)),this, SLOT(KnivesStatus(int,int,QString)));
        QObject::connect(this,SIGNAL(stop(quint16)),knights[i],SLOT(stop(quint16)));
        knights[i]->start();
    }
}

// Кнопка стоп
void MainWindow::on_pushButtonStop_clicked()
{
    emit stop(1);
}
