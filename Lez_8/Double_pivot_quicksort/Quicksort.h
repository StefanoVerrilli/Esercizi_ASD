#include <iostream>
#include <vector>

using namespace std;

class Quicksort{
  private:
    void partition(vector<int> &_vec,int _begin,int _end,int &first_pivot,int &second_pivot);
    void swap(int &a,int &b);
  public:
    void _Quicksort(vector<int> &_vec,int _begin,int _end){
        if(_begin<_end){
        int first_pivot,second_pivot;
        partition(_vec,_begin,_end,first_pivot,second_pivot);
        _Quicksort(_vec,_begin,first_pivot-1);
        _Quicksort(_vec,first_pivot+1,second_pivot-1);
        _Quicksort(_vec,second_pivot+1,_end);
    }
}};

void Quicksort::partition(vector<int> &_vec,int _begin,int _end,int &first_pivot,int &second_pivot){
  //Prendo come primo pivot il primo elemento e come secondo pivot l' ultimo elemento,
  //se il primo risulta più grande del secondo effettuo lo swap
  if(_vec.at(_begin)> _vec.at(_end))
    swap(_vec.at(_begin),_vec.at(_end));
  
  //Imposto i due pivot come sopra definito e genero gli indici
  int i=_begin+1;
  int j = _end-1;
  int k = _begin+1;
  first_pivot = _vec.at(_begin);
  second_pivot = _vec.at(_end);

  while(k <= j){
    //Se gli elementi risultano essere più piccoli del first_pivot
    if(_vec.at(k) < first_pivot){
      swap(_vec.at(k),_vec.at(i));
      i++;
    }
  //Se invece gli elementi risultano essere più grandi o al massimo uguali del secondo pivot
    else if(_vec.at(k) >= second_pivot){
    //Allora swappa quest' ultimo con un elemento più piccolo del secondo pivot che trovi partendo da end-1
      while(_vec.at(j) > second_pivot && k<j)
        j--;
      swap(_vec.at(k),_vec.at(j));
      j--;
      if(_vec.at(k) < first_pivot){
          swap(_vec.at(k),_vec.at(i));
          j++;
      } 
    }
    k++;
  }
  i--;
  j++;

  swap(_vec.at(_begin),_vec.at(i));
  swap(_vec.at(_end),_vec.at(j));

  first_pivot = i;
  second_pivot = j;

};

void Quicksort::swap(int &a,int &b){
  int temp=0;
  temp = a;
  a = b;
  b = temp;
};