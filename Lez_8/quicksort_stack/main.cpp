#include<iostream>
#include "Iterative_quick.h"
using namespace std;

int main(){
  Iterative_quick *_Quicksort = new Iterative_quick();
  vector<int> _vec;
  _vec.push_back(3);
  _vec.push_back(123);
  _vec.push_back(321);
  _vec.push_back(31);
  _Quicksort->Quicksort_Iterativo(_vec,0,_vec.size()-1);
  return 0;
}