#include <iostream>
#include <vector>
#include "Quicksort.h"

using namespace std;

int main(){
  vector<int> _vec;
  _vec.push_back(24);
  _vec.push_back(8);
  _vec.push_back(42);
  _vec.push_back(75);
  _vec.push_back(200);
  _vec.push_back(77);
  _vec.push_back(38);
  _vec.push_back(2424);
  Quicksort *_quicksort = new Quicksort();
  _quicksort->_quicksort(_vec,_vec.begin(),_vec.end()-1);
  for(auto &x: _vec)
    cout<<x<<endl;
  return 0;
}