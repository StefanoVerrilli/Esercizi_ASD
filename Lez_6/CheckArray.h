#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

class CheckArray{
  public:
    vector<int> GenerateExemple(int _size,int _initial,int _final);
    int FindHypotesis(vector<int> _Data,int _begin,int _end,vector<int> &result);
    void PrintVector(vector<int> _Vec);
};

void CheckArray::PrintVector(vector<int> _Vec){
  for(auto x = _Vec.begin();x!=_Vec.end();x++)
    cout<<"elemento: "<<*x<<endl;
}

vector<int> CheckArray::GenerateExemple(int _size,int _initial,int _final){
        srand(time(NULL));
        vector<int> Demo_Vec;
        if(_initial < _final){
            Demo_Vec.push_back(_initial);
            for(int i=0;i<_size;i++){
              Demo_Vec.push_back(rand()%30+1);
            }
            Demo_Vec.push_back(_final);
        }
        return Demo_Vec;
    }

int CheckArray::FindHypotesis(vector<int> _Data,int _begin,int _end,vector<int> &result){
      if(_begin == _end){return _begin;}
      else{
        int mid = (_begin+_end)/2;
        int Data1 = (FindHypotesis(_Data,_begin,mid,result));  //Left Array
        int Data2 = (FindHypotesis(_Data,mid+1,_end,result));     //Right Array
        
        if(_Data.at(Data1) < _Data.at(Data1+1)){
          result.push_back(Data1);}
          return Data2;
        }
          }

//Co author Francesco Pollasto 