#include <iostream>
#include "Nodo.h"
#include "Employee.h"  
#include <vector>

using namespace std;

int main(){
    int i;
    vector<Employee*> Emp_vector;
    Emp_vector.push_back(new Employee(string("Ciro Espostio"),1000));
    Emp_vector.push_back(new Employee(string("Gennaro Espostio"),2000));
    Emp_vector.push_back(new Manager(string("Carmine Espostio"),2000,2000));
    Emp_vector.push_back(new Manager(string("Salvatore Espostio"),3000,3000));

    //Creare una lista di Employee
    Nodo *Node = new Nodo(Emp_vector.at(0));
    Nodo *Node2 = new Nodo(Emp_vector.at(1));
    Node->SetNext(Node2);
    Nodo *first = Node;
    for(i=2;i<Emp_vector.size();i++){
        Node = new Nodo(Emp_vector.at(i));
        Node2->SetNext(Node);
        Node2 = Node;
    }

    //Stampare le info di ogni impiegato
    Nodo *head = first;
    while(head!=NULL){
        head->GetEmployee()->PrintInfo();
        head = head->GetNext();
    }

    //Stampare somma dei salari
    cout<<"Somma totale: "<<first->SumSalary()<<endl;

}
