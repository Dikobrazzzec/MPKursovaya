#include "mainwindow.h"
#include <List.h>
#include <QDebug>

#include <QApplication>

int main(int argc, char *argv[])
{


    List A;
    A.Adding(45,56,"Ivanov ivan ivanovich", 45,A.TailPtr );
    A.Adding(83,65,"Petr p", 45,A.TailPtr);
    A.Adding(95,32,"Vasiliu ivanovich", 45,A.TailPtr);
    A.Adding(56,14,"Krvec ivanovich", 45,A.TailPtr);
    A.Print();
    qDebug()<<" ";
    A.Find(56);
    A.CorrcetDC(A.FindPtr, 89);
    A.Print();
    qDebug()<<" ";
    A.Find(83);
    A.CorrcetDC(A.FindPtr, 48);
    A.Print();
    qDebug()<<" ";
    A.Adding(78,104,"asdf", 45.5,A.TailPtr);
    A.Adding(35,32,"vas t", 46.8,A.TailPtr);
    A.Adding(456,18,"erq", 325.3,A.TailPtr);
    A.Print();
    qDebug()<<" ";
    A.Deletion(45);
    A.Print();
    qDebug()<<" ";
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
    }
