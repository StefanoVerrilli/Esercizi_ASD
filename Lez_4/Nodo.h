#pragma once
#include <iostream>
using namespace std;


template <class T>
class Nodo{
  private:
    Nodo *Next;
    Nodo *Prev;
    T* element;
  public:
    Nodo(T *_element){element=_element;}
    T* GetElement(){return element;}
    Nodo* GetNext(){return Next;}
    void SetNext(Nodo* _element){Next=_element;}
    Nodo* GetPrev(){return Prev;}
    void SetPrev(Nodo* _element){Prev=_element;}

};