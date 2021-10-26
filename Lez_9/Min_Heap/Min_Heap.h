#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class Min_Heap{
  private:
    int Heapsize;
    void swap (T &_elem1, T &_elem2);
  public:
    void Min_Heapify(vector<T> &_data_struct,int i);
    void Sum_Nodes_less_then(T value,vector<T> &_vec,int Node_index,int &sum);
    void Build_Min(vector<T> &_data_struct);
    void Insert(vector<T> &_data_struct,T _element);
    void PrintArray(vector<T> &_data_struct);
};

template <typename T> 
void Min_Heap<T>::Min_Heapify(vector<T> &_data_struct,int i){
  T min;
  int left_son = (2*i) + 1;
  int right_son = (2*i) + 2;
  if((left_son < Heapsize) && (_data_struct.at(i) >  _data_struct.at(left_son)))
    min = left_son;
  else
    min = i;
  if( (right_son < Heapsize) && (_data_struct.at(min) > _data_struct.at(right_son)))
    min = right_son;
  if( min != i ){
    swap(_data_struct.at(i),_data_struct.at(min));
    Min_Heapify(_data_struct,min);
  }
}

template<typename T>
void Min_Heap<T>::PrintArray(vector<T> &_data_struct){
  for(auto &x : _data_struct)
    cout<<x<<" ";
  cout<<endl;
}

template<typename T>
void Min_Heap<T>::Build_Min(vector<T> &_data_struct){
  Heapsize = _data_struct.size();
  for(int j = (_data_struct.size()/2);j>-1;j--){
    Min_Heapify(_data_struct,j);
  }
}

template<typename T>
void Min_Heap<T>::Insert(vector<T> &_data_struct,T _element){
  Heapsize+=1;
  _data_struct.insert(_data_struct.begin(),_element);
  Min_Heapify(_data_struct,0);
};

template <typename T>
void Min_Heap<T>::swap(T &_elem1, T &_elem2){
  T temp = _elem1;
  _elem1 = _elem2;
  _elem2 = temp;
}

template <typename T>
void Min_Heap<T>::Sum_Nodes_less_then(T value,vector<T> &_vec,int Node_index,int &sum){
  int left_son = 2*Node_index+1;
  int right_son = 2*Node_index+2;
  if((left_son) >= Heapsize || right_son >= Heapsize){ 
    if(_vec.at(Node_index) < value)
      sum+= _vec.at(Node_index);
    return;
  }
  Sum_Nodes_less_then(value,_vec,left_son,sum);
  Sum_Nodes_less_then(value,_vec,right_son,sum);
  if(_vec.at(Node_index) < value)
    sum += _vec.at(Node_index);
}