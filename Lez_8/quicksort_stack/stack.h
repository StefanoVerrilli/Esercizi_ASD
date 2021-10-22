#include <iostream>
using namespace std;

template <typename T>
class Stack{
  private:
    int dim;
    int top;
    T *Vet;
  public:
    Stack(){Vet = nullptr;dim=0;top=-1;}
    void push(T _element);
    bool Pop(T &_element);
    bool isEmpty();
};

template <typename T> bool Stack<T>::isEmpty(){
  if(top == -1)
    return true;
  else
    return false;
}

template <typename T> void Stack<T>::push(T _element){
  if(top == dim-1){
    T *App;
    App = new T[dim+10];
    for(int i=0;i<dim;i++){App[i] = Vet[i];}
    dim +=10;
    delete [] Vet;
    Vet = App;}
    Vet[++top] = _element;
}

template <typename T> bool Stack<T>::Pop(T &_element){
  bool Risp;
  if (top>=0){Risp=true; 
  _element=Vet[top--];
  }else{Risp=false;}
  return Risp;
}