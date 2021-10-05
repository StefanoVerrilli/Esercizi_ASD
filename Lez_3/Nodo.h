#pragma once
#include "Employee.h"
using namespace std;

class Nodo
{
    private:
        Nodo *Next;
        Employee *Emp;

    public:
        Nodo(Employee *_emp){Emp = _emp;}
        virtual ~Nodo() {free(this);}
        void SetNext(Nodo *_Next){this->Next = _Next;}
        Nodo *GetNext(){return this->Next;}
        Nodo *GetMyself(){return this;}
        void SetEmployee(Employee *_emp){Emp = _emp;}

        Employee *GetEmployee(){return this->Emp;}
        int operator+(int &sum){
            return this->GetEmployee()->GetSalary() + sum;}

        int SumSalary(){
            Nodo *Node = this;
            int sum=0;
            while(Node!=NULL){
                sum = *Node + sum;
                Node = Node->GetNext();
            } 
            return sum;
        }
};
