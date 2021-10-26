#include <iostream>
#include <vector>
#include "Verify_Heap.h"

using namespace std;

int main(){
  vector<int> _vec;
  Verify_Heap<int> *_Verify_Heap = new Verify_Heap<int>();
  _vec.push_back(202);
  _vec.push_back(20);
  _vec.push_back(70);
  _vec.push_back(2);
  _vec.push_back(15);
  _vec.push_back(30);
  _vec.push_back(40);
  _Verify_Heap->Is_Binary_MaxHeap(_vec,0) ? cout<<"yes"<<endl : cout<<"no"<<endl;
};