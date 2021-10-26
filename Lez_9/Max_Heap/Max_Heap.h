#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class Max_Heap{
  private:
    int Heapsize;
    void swap (T &_elem1, T &_elem2);
  public:
    void Max_Heapify(vector<T> &_data_struct,int i);
    void Build_Max(vector<T> &_data_struct);
    void Insert(vector<T> &_data_struct,T _element);
    void PrintArray(vector<T> &_data_struct);
};

template <typename T> 
void Max_Heap<T>::Max_Heapify(vector<T> &_data_struct,int i){
  int max;
  int left_son = (2*i) + 1;
  int right_son = (2*i) + 2;
  if((left_son < Heapsize) &&(_data_struct.at(i) <  _data_struct.at(left_son)))
    max = left_son;
  else
    max = i;
  if( (right_son < Heapsize) && (_data_struct.at(max) < _data_struct.at(right_son)))
    max = right_son;
  if( max != i ){
    swap(_data_struct.at(i),_data_struct.at(max));
    Max_Heapify(_data_struct,max);
  }
}

template<typename T>
void Max_Heap<T>::PrintArray(vector<T> &_data_struct){
  for(auto &x : _data_struct)
    cout<<x<<" ";
  cout<<endl;
}

template<typename T>
void Max_Heap<T>::Build_Max(vector<T> &_data_struct){
  Heapsize = _data_struct.size();
  for(int j = (_data_struct.size()/2);j>-1;j--){
    Max_Heapify(_data_struct,j);
  }
}

template<typename T>
void Max_Heap<T>::Insert(vector<T> &_data_struct,T _element){
  Heapsize+=1;
  _data_struct.insert(_data_struct.begin(),_element);
  Max_Heapify(_data_struct,0);
};

template <typename T>
void Max_Heap<T>::swap(T &_elem1, T &_elem2){
  T temp = _elem1;
  _elem1 = _elem2;
  _elem2 = temp;
}