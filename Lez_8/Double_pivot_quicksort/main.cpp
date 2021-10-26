#include <iostream>
#include <vector>
#include "Quicksort.h"

using namespace std;

int main(){
  vector<int> _vec;
  _vec.push_back(8);
  _vec.push_back(2);
  _vec.push_back(90);
  _vec.push_back(25);
  _vec.push_back(24);
  _vec.push_back(14);
  _vec.push_back(66);
  _vec.push_back(57);
  Quicksort *_quicksort = new Quicksort();
  _quicksort->_Quicksort(_vec,0,_vec.size()-1);
  for(auto &x: _vec)
    cout<<x<<endl;
  return 0;
}