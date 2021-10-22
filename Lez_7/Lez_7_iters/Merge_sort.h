#include <iostream>
#include <vector>

using namespace std;

class Mergesort{
  private:
    void Merge(vector<int> &out,vector<int> &_vector,int _begin_sx,int tot_sx,int _begin_dx,int tot_dx,int &swap_counter);
  public:
    void _mergesort(vector<int> &_vector,int _begin,int _end,int &swap_counter){
        if(_begin<_end){
          int mid = (_begin+_end)/2;
          _mergesort(_vector,_begin,mid,swap_counter); //left vector
          _mergesort(_vector,mid+1,_end,swap_counter); //right vector
          int tot_sx = mid-_begin+1;
          int tot_dx = _end-mid;
          Merge(_vector,tot_sx,mid+1,tot_dx,swap_counter);
        }
    }

}; 

void Mergesort::Merge(vector<int> &_vec_a,int tot_sx,vector<int> &_vec_b,int tot_dx,int &swap_counter){
  vector<int>::iterator main_iter;
  vector<int> vec_a(tot_sx);
  for (auto i = 0;i<tot_sx;i++){
    vec_a.at(i) = _vector.at(i);
  }
  vector<int> vec_b(tot_dx);
  for(auto i=0;i<tot_dx;i++){
    vec_b.at(i) = _vector.at(i+tot_sx);
  }
  vector<int>::iterator iter_a = vec_a.begin();
  vector<int>::iterator iter_b = vec_b.begin();
  for(main_iter=_vector.begin();main_iter!=_vector.end();main_iter++){
      if(iter_a==vec_a.end()){*main_iter = *iter_a++;}
      if(iter_b==vec_b.end()){*main_iter = *iter_b++;}
      *main_iter = (*iter_a<*iter_b) ? *iter_a++ : *iter_b++;
      //out.at(main_iter-_begin_dx);
  }

};