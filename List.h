#ifndef LIST_H
#define LIST_H
#include <QString>
#include <QDebug>
#include <QFile>

class Node {
    int DecreeNumber;
    int DrivLicenNumber;
    QString NSP;
    int TotalFine;
    class Node *ptr;
 //   int count;

    friend class List;

};

class List {
    Node *head;
    int DCi,DNi;   // на случай если делать норм ввод
    QString NSPi;
    double TFi;
    Node * Prev(Node* node) {
        if (isEmpty()==false) {
            return nullptr;
        }
        if (node == head) {
            return nullptr;
        }
        Node* p = head;
        while (p != node) {
            p=p->ptr;
        }
        return p;
    }
public:
    Node* TailPtr=nullptr;
    Node* FindPtr=nullptr;
//    Node* UsePtr;
    List () {
        head = nullptr;
    }
    ~List(){}

    bool isEmpty () {
        if (head == nullptr) {
            return false;
        } else {
            return true;
        }
    }

    Node* Adding (int DC_, int DLN_, QString NSP_, int TF_, Node* node ) {
        Node *elem = new Node();
        elem->DecreeNumber = DC_;
        elem->DrivLicenNumber=DLN_;
        elem->NSP=NSP_;
        elem->TotalFine=TF_;
  //      if (TailPtr==nullptr) {
  //      elem->count=1;
  //      } else {
   //     elem->count=TailPtr->count+1;
   //     }
        if(node==nullptr) {
            elem->ptr=head;
            if (head == nullptr) {
                TailPtr=elem;
            }
            head = elem;
            return  elem;
        } else {
            if (head == nullptr) {
                elem->ptr = nullptr;
                head = elem;
                TailPtr = elem;
                return elem;
            }
            else {
                elem->ptr=nullptr;
                node->ptr = elem;
                TailPtr = elem;
                return elem;
            }
        }
    }

    QString Deletion(int DC_) {

        if(Find(DC_)==nullptr) {return "Нет такого узла";}
        if(Find(DC_)==head) {
            head = head->ptr;
            return "Корневой узел удален";
        } else {
        Node *p =Prev(Find(DC_));
        p->ptr=Find(DC_)->ptr;
        delete Find(DC_);
        return "Узел удален";
        }
    }

    int getValue (Node *p) {
        return p->DecreeNumber;
    }

    Node* Next (Node* node) {
        if (isEmpty()==false) {
            return nullptr;
        } else {
            return node->ptr;
        }
    }

    Node* Find ( int DC_) {
        Node*p = head;
        while (p!=nullptr) {
            if (DC_==p->DecreeNumber) {
                FindPtr = p;
                return p;
            }
            p=Next(p);
        }
        return nullptr;
    }

    void CorrcetDC(Node* p, int DC_) {
        p->DecreeNumber = DC_;
    }

    void CorrcetDLN(Node* p, int DLN_) {
        p->DrivLicenNumber=DLN_;
    }

    void CorrcetNSP(Node* p,QString NSP_) {
        p->NSP=NSP_;
    }

    void CorrcetTF(Node* p, int TF_) {
        p->TotalFine=TF_;
    }

    int returnerDC (Node* node) {
        return node->DecreeNumber;
    }

    int returnerDLN (Node* node) {
        return node->DrivLicenNumber;
    }

    QString returnerNSP (Node* node) {
        return node->NSP;
    }

    int returnerTF(Node* node) {
        return node->TotalFine;
    }

    void Print () {
        if (isEmpty()==false) {
            qDebug() <<"empty";
    } else {
            Node *p = head;
            while (p!= nullptr)
             {
                qDebug()<<" "<< p->DecreeNumber<<" "<<p->NSP<<" "<<p->TotalFine;
                p=Next(p);
            }
        }
    }

    void Output (int DC_) {
        Node* p = Find(DC_);
        QFile file ("E:\\out.txt");
        if (file.open(QIODevice::WriteOnly)) {
            QTextStream out(&file);
            out<<p->NSP;
            out<<p->DecreeNumber;
            out<<p->DrivLicenNumber;
            out<<p->TotalFine;
            file.close();
    //        if (out.status()!= QTextStream::Ok){
  //              qDebug()<<"Error";
//            }
        }
    }

    void Input () {
        QFile file ("E:\\in.txt");
        if (file.open(QIODevice::ReadOnly)) {
            QTextStream in(&file);
            QString str;
            while (!in.atEnd()) {
                str=in.readLine();
                NSPi = str;
                str=in.readLine();
                DCi=str.toInt();
                str=in.readLine();
                DNi=str.toInt();
                str=in.readLine();
                TFi=str.toInt();
                Adding(DCi,DNi, NSPi,TFi,TailPtr);
            }
            file.close();
 //           if(in.status()!=QTextStream::Ok){
 //               qDebug()<<"Error";
  //          }
        }
    }

};



#endif // LIST_H
