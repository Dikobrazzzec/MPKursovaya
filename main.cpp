#include "mainwindow.h"
#include <List.h>
#include <QDebug>

#include <QApplication>

int main(int argc, char *argv[])
{


    List A;
    A.Add(45,56,"Ivanov ivan ivanovich", 45,1,A.TailPtr );
    A.Add(83,65,"Petr p", 45,2,A.TailPtr);
    A.Add(95,32,"Vasiliu ivanovich", 45,3,A.TailPtr);
    A.Add(56,14,"Krvec ivanovich", 45,4,A.TailPtr);
    A.Print();
    qDebug()<<A.head->NSP;
    A.Find(56,14);
    A.CorrcetDC(A.FreePtr, 89);
    A.Print();
    qDebug()<<" ";
    A.Find(83,65)
    A.CorrcetDC(A.FreePtr, 48);
    A.Print();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
    }
