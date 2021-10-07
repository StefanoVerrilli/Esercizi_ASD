#pragma once
using namespace std;
#include <iostream>
#include "Nodo.h"
#include "LinkedList.h"
#include "Tx.h"

class Blocco{
    private:
        int ID;
        LinkedList<Nodo,Tx> Txs;
        bool closed;
    public:
        Blocco(int id):ID{id},closed(false){}
        int GetID(){return ID;}
        void AddTx(Tx *t){if(!closed)Txs.AddNodo(t);}
        void CloseTx(){closed=true;}
        LinkedList<Nodo,Tx> *GetLL(){return &Txs;}
        int operator+(int &sum){
            return sum;
        }
        float FindUserTxs(string _address){
            Nodo<Tx>* Head = GetLL()->Getfirst();
            float sum=0;
            while(Head!=NULL){ 
                    if(Head->GetElement()->GetTo()==_address)
                        sum += Head->GetElement()->GetVal();
                    else if(Head->GetElement()->GetFrom()==_address)
                        sum -= Head->GetElement()->GetVal();
                    Head = Head->GetNext();
            }
            return sum;
            }
};
