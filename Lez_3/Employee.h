#pragma once
#include <string>

using namespace std;

class Employee
{
    private:
        string name;
        int salary;

    public:
        Employee(string _name,int _salary){salary=_salary;name=_name;}
        virtual ~Employee() {free(this);}
        string GetName(){return this->name;}
        int GetSalary(){return this->salary;}
        void virtual PrintInfo(){
            cout<<this->GetName()<<endl;
            cout<<this->GetSalary()<<endl;
        };
};

class Manager:public Employee
{
    private:
        int bonus;

    public:
        Manager(string _name,int _salary,int _bonus):Employee(_name,_salary){bonus=_bonus;}
        virtual ~Manager() {free(this);}
        int GetBonus(){return this->bonus;}
        void PrintInfo(){
            cout<<this->GetName()<<endl;
            cout<<this->GetSalary()<<endl;
            cout<<this->GetBonus()<<endl;
        };
};

