#include <iostream>
#include <vector>

using namespace std;

class Mergesort{
  private:
    void merge(vector<int> &_vector,int _begin,int _end,int _mid,int &swap_counter);
    void merge_cormen(vector<int> &_vector,int _begin,int _end,int _mid,int &swap_counter);
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

/*void Mergesort::merge_cormen(vector<int> &_vector,int _begin,int _end,int _mid,int &swap_counter){
  vector<int> n1(_mid-_begin+1);
  vector<int> n2(_end-_mid);
  vector<int>::iterator i,j;
  vector<int>::iterator it = _vector.begin();
  for(i=n1.begin(),it=n1.begin();i<n1.end();i++,it++){
    i = next(it,_begin-1);
  }
  vector<int>::iterator it2 = _vector.begin();
  for(j= n2.begin(),it2=n2.begin();j<n2.end();j++,it2++){
    j = next(it2,_mid);
  }
  n1.push_back(100000000);
  n2.push_back(10000000);
  i=n1.begin();j=n2.begin();
  for(int k=_begin;k<_end;k++){
    if(*i <= *j){
      _vector.at(k) = *i;
      swap_counter++;
      i+=1;
    }else{
      _vector.at(k) = *j;
      j+=1;
    }
  }
}*/