#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCoreApplication>
#include <QObject>
#include <QPixmap>
#include <QWaitCondition>
#include "arbitr.h"
#include "knight.h"
#include "knife.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void SetLabel(const quint16 &id, const QString str);
    void PrintToList(const quint16 &id, const QString str);
    void printCoutEat(const quint16 &id, const int count);
    void printCoutHistory(const quint16 &id, const int count);
    void KnivesStatus(const int &lknife, const int &rknife,const QString str);
    void on_pushButtonStart_clicked();
    void on_pushButtonStop_clicked();

signals:
void stop(const quint16 s);

private:
    Ui::MainWindow *ui;
    Arbitr *arbitr;
   // Knight knights [5];



};

#endif // MAINWINDOW_H
