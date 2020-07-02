#ifndef LIST_H
#define LIST_H
#include <QString>
#include <QDebug>

class Node {
public:
    int DecreeNumber;
    int DrivLicenNumber;
    QString NSP;
    double TotalFine;
    class Node *ptr;
    int count;

    friend class List;

};

class List {
public:
    Node *head;
    int count = 0;
    Node * Prev(Node*);
public:
    Node * TailPtr=nullptr;
    Node* FreePtr;
    Node* UsePtr;
    List () {
        head = nullptr;
    }

    bool isEmpty () {
        if (head == nullptr) {
            return false;
        } else {
            return true;
        }
    }

    Node* Add (int DC_, int DLN_, QString NSP_, double TF_,int f, Node* node ) {
        Node *elem = new Node();
        elem->DecreeNumber = DC_;
        elem->DrivLicenNumber=DLN_;
        elem->NSP=NSP_;
        elem->TotalFine=TF_;
        elem->count=f;
 //       if (head ==nullptr) {
  //          elem->ptr=nullptr;
  //          head = elem;
  //      } else {
  //          elem->ptr=nullptr;
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
 //       elem->ptr = node->ptr;
 //       node->ptr = elem;
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

    Node* Find ( int DC_, int DLN_) {
        Node*p = head;
        while (p!=nullptr) {
            if (DC_==p->DecreeNumber) {
                if (DLN_==p->DrivLicenNumber) {
                FreePtr = p;
                return p;
                }
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

    void CorrcetTF(Node* p, double TF_) {
        p->TotalFine=TF_;
    }


    void Print () {
        if (isEmpty()==false) {
            qDebug() <<"empty";
    } else {
            Node *p = head;
            while (p!= nullptr)
             {
                qDebug()<< p->DecreeNumber<<" "<<p->count;
                p=Next(p);
            }
        }
    }

};



#endif // LIST_H
