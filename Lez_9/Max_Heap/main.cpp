#include <iostream>
#include <vector>
#include "Max_Heap.h"

using namespace std;

int main(){
  vector<int> _vec;
  Max_Heap<int> *_Max_Heap = new Max_Heap<int>();
  _vec.push_back(32424);
  _vec.push_back(143);
  _vec.push_back(3421);
  _vec.push_back(3512);
  _vec.push_back(532532);
  _Max_Heap->Build_Max(_vec);
  _Max_Heap->Insert(_vec,1432);
  _Max_Heap->PrintArray(_vec);
};