#include <iostream>
#include <vector>
using namespace std;

bool CheckIfPermutation(vector<int> Stringa1_int,vector<int> Stringa2_int){
  vector<int> arr(Stringa1_int.size()+1);
  int i;
          for(i=0;i<Stringa1_int.size();i++){
            arr.at(Stringa1_int.at(i))+=1;
          }

          for(i=0;i<Stringa2_int.size();i++){
            arr.at(Stringa2_int.at(i))-=1;
          }

          for(i=0;i<Stringa1_int.size();i++){
            if(arr.at(i)!=0)
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