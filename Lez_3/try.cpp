#include <iostream>
using namespace std;

//Impiegato/Dirigente is a node, implementano

class Impiegato{
  protected:
    int Salario;
    string Name;
    public:
        Impiegato *Next;
        virtual void InsertValue(string _Nome,int _Salario){
          Salario = _Salario;
          Name = _Nome;
        };
        int GetSalario(){
          return Salario;
        }
        string GetName(){
          return Name;
        }
        int operator+ (int Sum){
            Sum += this->Salario;
            return Sum;
        };

        int GetChain(Impiegato *Head){
          int sum;
          while(Head->Next!= NULL){
            sum = *Head + sum;
            Head = Head->Next;
          }
          return sum;
        }
};


class Manager: public Impiegato{
    public:
    int bonus;
      void InsertValue(string _Name,int _Salario){
        bonus = 20;
        Salario = _Salario+bonus;
        Name = _Name;
      }
};

int main(){
    int i=0,sum=0;
    Impiegato *head;
    Impiegato *New_Impiegato,*First_Imp;
    New_Impiegato = new Impiegato();
    head = New_Impiegato;
    First_Imp = head;
    while(i< 10){
    New_Impiegato->InsertValue("Generic Name",i);
    Impiegato *var;
    New_Impiegato->Next = var = new Impiegato();
    head = var;
    i++;
    New_Impiegato=var;
    }
    head = First_Imp;
    while(head->Next!= NULL){
      cout<<head->GetName()<<endl;
      cout<<head->GetSalario()<<endl;
      head = head->Next;
    }
    cout<<head->GetChain(First_Imp)<<endl;
    return 0;

}
