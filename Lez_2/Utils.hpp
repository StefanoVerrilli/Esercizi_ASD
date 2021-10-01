#include <iostream>
#include <vector>
using namespace std;

bool CheckIfPermutation(string Stringa1,string Stringa2,vector<int> Stringa1_int,vector<int> Stringa2_int){
  vector<int> arr(Stringa1.size());
  int i;
          for(i=0;i<Stringa1.size();i++){
            arr[Stringa1_int[i]]+=1;
          }
          for(i=0;i<Stringa2.size();i++){
            arr[Stringa2_int[i]]-=1;
          }

          for(i=0;i<Stringa1.size();i++){
            if(arr[i]!=0)
              return false;
          }
          return true;
}

int max_element(vector<int> vec){
        auto max=0;
        for(auto i = vec.begin();i<vec.end();i++){
          if(*i > max){
              max = *i;
          }
        }
        return max;
      }