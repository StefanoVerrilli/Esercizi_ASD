#include <iostream>
#include <vector>
using namespace std;

class Quicksort{
  private:
    void swap(int &a,int &b);
    int Partition(vector<int>_vec,vector<int>::iterator _begin,vector<int>::iterator end);
  public:
    void _quicksort(vector<int>_vec,vector<int>::iterator _begin,vector<int>::iterator _end);
};

void Quicksort::_quicksort(vector<int>_vec,vector<int>::iterator _begin,vector<int>::iterator _end){
  if(distance(_begin,_end) > 0){
    int pivot = Partition(_vec,_begin,_end);
    _quicksort(_vec,_begin,_end-1);
    _quicksort(_vec,_begin+1,_end);

  }
}

int Quicksort::Partition(vector<int>_vec,vector<int>::iterator _begin,vector<int>::iterator _end){
  int pivot = *_end;
  vector<int>::iterator i = _begin-1;
  vector<int>::iterator j = _end;
  while(1){
    while(*(++i) < pivot);
    while (pivot < *(--j)){
      if(j==_begin)
        break;
    }
    if(i >= j)
      break;
    swap(*i,*j);
  }
  swap(*i,*_end);
  return *i;
}

void Quicksort::swap(int &a,int &b){
  int temp=0;
  temp = a;
  a = b;
  b = temp;
};