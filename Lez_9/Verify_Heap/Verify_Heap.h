#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Verify_Heap{
  private:
  public:
    bool Is_Binary_MaxHeap(vector<T> _vec,int Node_Index);
    bool Is_Binary_MinHeap(vector<T> _vec); 
};

template <typename T>
bool Verify_Heap<T>::Is_Binary_MaxHeap(vector<T> _vec,int Node_Index){
  int left_son = 2*Node_Index+1;
  int right_son = 2*Node_Index+2;
  if((left_son < _vec.size()) && (right_son < _vec.size())){
    if(_vec.at(Node_Index) > left_son && _vec.at(Node_Index) > right_son){
      Is_Binary_MaxHeap(_vec,left_son);
      Is_Binary_MaxHeap(_vec,right_son);
    }else{
      return false;
    }
  }
  return true;
}