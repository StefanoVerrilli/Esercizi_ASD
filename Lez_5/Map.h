#pragma once
#include <iostream>
#include <fstream>
#include <map>
using namespace std;

class Map{
    private:
      map<string,int> W_map;
      ifstream *Initial_file;
    public:
      Map(ifstream *_File){Initial_file = _File;}

      void Count_Word(){
        string Word_ToCount;
         while(*Initial_file >> Word_ToCount){
           W_map[Word_ToCount]++;
        }};
        
      void Print_Word(){
        for(auto it=W_map.begin();it!=W_map.end();it++){
          cout<<it->first<<" "<<it->second<<endl;
        }
      }
};