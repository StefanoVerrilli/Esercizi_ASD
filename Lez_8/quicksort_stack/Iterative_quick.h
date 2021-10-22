#include <iostream>
#include <vector>
#include "stack.h"


class Iterative_quick{
  private:
  int Partition(vector<int>&_vec,int _begin,int _end);
  public:
    void Quicksort_Iterativo(vector<int> &_vec,int _begin,int _end){
      Stack<int> _MyStack;  //Creazione dello stack
      _MyStack.push(_begin);
      _MyStack.push(_end);
      while(!_MyStack.isEmpty()){
        _MyStack.Pop(_end);
        _MyStack.Pop(_begin);
        int pivot = Partition(_vec,_begin,_end);
        vector<int>::iterator pivot_split = _vec.begin() + pivot;
        vector<int> sx_vec,dx_vec;
        for(auto i=_vec.begin();i==pivot_split;i++){sx_vec.push_back(*i);}
        if(sx_vec.size()!=0){
          _MyStack.push(_begin);
          cout<<"Pushing _begin "<<_begin<<endl;
          _MyStack.push(pivot-1);
          cout<<"Pusing pivot-1 "<<pivot-1<<endl;
          sx_vec.clear();
        }
        for(auto j=pivot_split+1;j!=_vec.end();j++){dx_vec.push_back(*j);}
        if(dx_vec.size()!=0){
          _MyStack.push(pivot+1);
          cout<<"Pushing: "<<pivot+1<<endl;
          _MyStack.push(_end);
          cout<<"Pushing end: "<<_end<<endl;
          dx_vec.clear();
        }
      }


    }

};

int Iterative_quick::Partition(vector<int>&_vec,int _begin,int _end){
  int pivot = _vec.at(_end);
  int i = _begin-1;
  int j = _end;
  while(1){
    while(_vec.at(++i) < pivot);
    while (pivot < _vec.at(--j)){
      if(j==_begin)
        break;
    }
    if(i >= j)
      break;
    swap(_vec.at(i),_vec.at(j));
  }
  swap(_vec.at(i),_vec.at(_end));
  return i;
}