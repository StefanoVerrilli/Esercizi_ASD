#include <iostream>
#include "Nodo.h"
#include "Employee.h"  
#include <vector>

using namespace std;

int main(){
    int i;
    vector<Employee*> Emp_vector;
    Employee *emp1=new Employee(string("Ciro Espostio"),1000);
    Emp_vector.push_back(emp1);
    
    Employee *emp2=new Employee(string("Gennaro Espostio"),2000);
    Emp_vector.push_back(emp2);
    Employee *emp3=new Manager(string("Carmine Espostio"),2000,2000);
    Emp_vector.push_back(emp3);
    Employee *emp4=new Manager(string("Salvatore Espostio"),3000,3000);
    Emp_vector.push_back(emp4);
    Employee *emp5=new Manager(string("Salvatore Espostio"),3000,3000);
    Emp_vector.push_back(emp5);
    Employee *emp6=new Manager(string("Salvatore Espostio"),3000,3000);
    Emp_vector.push_back(emp6);

    //Creare una lista di Employee
    Nodo *Node = new Nodo(Emp_vector.at(0));
    Nodo *Node2 = new Nodo(Emp_vector.at(1));
    Node->SetNext(Node2);
    cout<<"Node 0: "<<Node->GetMyself()<<endl;
    cout<<"Node 0 points to:"<<Node->GetNext()<<endl;
    Nodo *first = Node;
    /*Node = new Nodo(Emp_vector.at(2));
    Node2->SetNext(Node);
    cout<<"Node 1: "<<Node2->GetMyself()<<endl;
    cout<<"Node 1 points to:"<<Node2->GetNext()<<endl;
    Node2 = new Nodo(Emp_vector.at(3));
    Node->SetNext(Node2);
    cout<<"Node 2: "<<Node->GetMyself()<<endl;
    cout<<"Node 2 points to:"<<Node->GetNext()<<endl;
    Node2->SetNext(0);
    cout<<"Node 3: "<<Node2->GetMyself()<<endl;
    cout<<"Node 3 points to:"<<Node2->GetNext()<<endl;*/
    i=2;
    while(i<Emp_vector.size()){
        Node = new Nodo(Emp_vector.at(i));
        Node2->SetNext(Node);
        cout<<"Node 1: "<<Node2->GetMyself()<<endl;
        cout<<"Node1 points to:" <<Node2->GetNext()<<endl;
        Node2 = new Nodo(Emp_vector.at(i+1));
        Node->SetNext(Node2);
        cout<<"Node 2: "<<Node->GetMyself()<<endl;
        cout<<"Node 2 points to:" <<Node->GetNext()<<endl;
        i=i+2;
    }
    Node2->SetNext(0);
    //cout<<first.GetEmployee()<<endl;

    //Traversa tutti i nodi
    Nodo *head = first;
    while(head->GetNext()!=0){
        cout<<head->GetMyself()<<endl;
        head = head->GetNext();
    }

    //Stampare le info di ogni impiegato
}
