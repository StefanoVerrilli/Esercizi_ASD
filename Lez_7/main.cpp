#include <iostream>
#include <vector>
#include "Merge_sort.h"

using namespace std;

int main(){
  vector<int> _vector;
  _vector.push_back(4);
  _vector.push_back(40);
  _vector.push_back(2);
  _vector.push_back(1);
  Mergesort *_merge = new Mergesort();
  int counter=0;
  _merge->_mergesort(_vector,0,_vector.size()-1,counter);
  for(auto &x : _vector){
            //cout<<x<<endl;
          }
  cout<<"Numero di swap effettuati: "<<counter<<endl;
}