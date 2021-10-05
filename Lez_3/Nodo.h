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
        virtual ~Nodo() {}
        void SetNext(Nodo *_Next){this->Next = _Next;}
        Nodo *GetNext(){return this->Next;}
        Nodo *GetMyself(){return this;}
        //SetEmployee(Employee *emp)
        Employee *GetEmployee(){return this->Emp;}
};
