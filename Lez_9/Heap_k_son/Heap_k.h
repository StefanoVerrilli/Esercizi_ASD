#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class Heap_k{
  private:
    int Heapsize;
    int k = 4; //Figli per nodo non foglia
    void Valid_son_Index(vector<int> &_Index_sons,int condition);
    int Pick_Greater(vector<T> _vec,vector<int> sons_index,int Current_node);
    void swap(T &_elem1, T &_elem2);
  public:
    void Max_Heapify_k(vector<T> &_vec,int i);
    void Build_Max_Heapify_k(vector<T> &_vec);
};

template<typename T>
void Heap_k<T>::Max_Heapify_k(vector<T> &_vec,int i){
  int max=i;
  vector<int> sons_vec_index;
  for(int j=1;j<k+1;j++){sons_vec_index.push_back(k*i+j);}
  Valid_son_Index(sons_vec_index,_vec.size());
  if(sons_vec_index.size()!=0){
    max = Pick_Greater(_vec,sons_vec_index,i);}
  if(max != i){
    swap(_vec.at(i),_vec.at(max));
    Max_Heapify_k(_vec,max);
  }
}

template<typename T>
void Heap_k<T>::Build_Max_Heapify_k(vector<T> &_data_struct){
  Heapsize = _data_struct.size();
  cout<<"value: "<<((_data_struct.size()-1)/(k+1))<<endl;
  for(int j = ((_data_struct.size()-1)/(k+1));j>-1;j--){
    Max_Heapify_k(_data_struct,j);
  }
}

template <typename T>
int Heap_k<T>::Pick_Greater(vector<T> _vec,vector<int> sons_index,int Current_node){
  int max;
  if(_vec.at(sons_index.at(0)) > _vec.at(Current_node)){
    max = sons_index.at(0);}
    else{
    max = Current_node;
    }
  for(int i = 0;i<sons_index.size();i++){
    if(_vec.at(sons_index.at(i)) > _vec.at(max)){
      max = sons_index.at(i);
    }
  }
  return max;
}

template <typename T>
void Heap_k<T>::Valid_son_Index(vector<int> &_Index_sons,int condition){
  vector<int>::iterator i;
  vector<int> copy;
  for(i = _Index_sons.begin();i<_Index_sons.end();i++){
    if(*i < condition){
      copy.push_back(*i);
    }
  }
  _Index_sons = copy;
}

template <typename T>
void Heap_k<T>::swap(T &_elem1, T &_elem2){
  T temp = _elem1;
  _elem1 = _elem2;
  _elem2 = temp;
}