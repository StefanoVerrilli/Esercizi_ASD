#pragma once
#include <iostream>
#include "Nodo.h"
#include "Tx.h"
using namespace std;

template <template<class> class T,class S>
class LinkedList{
  private:
    T<S>* first;
    T<S>* last;
  public:
    LinkedList(){first=last=nullptr;}
    T<S>* Getfirst(){return first;}
    void AddNodo(S *_obj){
      T<S> *_element = new T<S>(_obj);
      if(first==NULL){
        first=_element;
        last =_element;
      }else{
      last->SetNext(_element);
      _element->SetPrev(last);
      last=_element;
      }
    }
};