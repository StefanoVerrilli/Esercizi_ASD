#include <iostream>
#include <vector>
#include "Min_Heap.h"

using namespace std;

int main(){
  vector<int> _vec;
  Min_Heap<int> *_Min_Heap = new Min_Heap<int>();
  _vec.push_back(29);
  _vec.push_back(5);
  _vec.push_back(2);
  _vec.push_back(35);
  _vec.push_back(1);
  _vec.push_back(223);
  _vec.push_back(29);
  _Min_Heap->Build_Min(_vec);
  _Min_Heap->Insert(_vec,1432);
  _Min_Heap->PrintArray(_vec);
  int sum=0;
  _Min_Heap->Sum_Nodes_less_then(30,_vec,0,sum);
  cout<<"sum: "<<sum<<endl;
};