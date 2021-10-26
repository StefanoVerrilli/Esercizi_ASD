#include <iostream>
#include <vector>
#include "Heap_k.h"

using namespace std;

int main(){
  vector<int> vec;
  vec.push_back(202);
  vec.push_back(20);
  vec.push_back(70);
  vec.push_back(80);
  vec.push_back(18);
  vec.push_back(30);
  vec.push_back(19);
  vec.push_back(22);
  vec.push_back(32);
  vec.push_back(241);
  vec.push_back(37);
  Heap_k<int> *_Heap_k = new Heap_k<int>();
  _Heap_k->Build_Max_Heapify_k(vec);
  vector<int>::iterator x;
  for(x=vec.begin();x<vec.end();x++){
    cout<<*x<<endl;
  }
}