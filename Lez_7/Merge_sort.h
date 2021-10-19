#include <iostream>
#include <vector>

using namespace std;

class Mergesort{
  private:
    void merge(vector<int> &_vector,int _begin,int _end,int _mid,int &swap_counter);
  public:
    void _mergesort(vector<int> &_vector,int _begin,int _end,int &swap_counter){
        if(_begin<_end){
          int mid = (_begin+_end)/2;
          _mergesort(_vector,_begin,mid,swap_counter); //left vector
          _mergesort(_vector,mid+1,_end,swap_counter); //right vector
          merge(_vector,_begin,_end,mid,swap_counter);
        }
    }

}; 

/*void Mergesort::merge(vector<int> &_vector,int _begin,int _end,int _mid,int &swap_counter){
  vector<int> Demo_vector(_begin+_end+1);
  vector<int>::iterator i,j,k;
  cout<<*_vector.begin()<<endl;
  iterator it{_mid};
  vector<int>::iterator i_Demo = Demo_vector.begin()+ (_mid+1);
  for(i,i_Demo;i!=_vector.begin();--i,--i_Demo){
    *(i_Demo-1) = *(i-1);
  }

  j = _vector.begin()+_mid;
  auto j_Demo = Demo_vector.begin()+_mid;
  for(j,j_Demo;j<_vector.end();j++,j_Demo++){
    auto aux = prev(j_Demo,_end+_mid);
    *aux = *j+1;
  }

  for(auto k = _vector.begin();k<=_vector.end();k++){
    if(j_Demo < i_Demo){
      swap_counter++;
      cout<<"Elementi swappati: "<<*j<<" con: "<<*i<<endl;
      j_Demo = prev(j_Demo,1);
      *k = *(j_Demo--);
    }else{
      *k = *(i_Demo++);
    }
  }
};*/

void Mergesort::merge(vector<int> &_vector,int _begin,int _end,int _mid,int &swap_counter){
  int n = _begin+_end+1;
  vector<int> Demo_vector(n);
  int i,j,k;
  for(i=_mid+1;i>_begin;i--){
     Demo_vector.at(i-1) = _vector.at(i-1);
  }
  for(j= _mid;j<_end;j++){
    Demo_vector.at(_end+_mid-j) = _vector.at(j+1);
  }
  for(k = _begin;k<=_end;k++){
    if(Demo_vector.at(j) < Demo_vector.at(i)){
      swap_counter++;
      cout<<"Elementi swappati: "<<Demo_vector.at(j)<<" con: "<<Demo_vector.at(i)<<endl;
      _vector.at(k) = Demo_vector.at(j--);
    }else{
      _vector.at(k) = Demo_vector.at(i++);
    }
  }
};