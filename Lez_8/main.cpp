#include <iostream>
#include <vector>
using namespace std;

int main(){
  vector<int> Houses;
  int rob1=0,rob2=0;
  Houses.push_back(1);
  Houses.push_back(2);
  Houses.push_back(3);
  Houses.push_back(1);
  Houses.push_back(5);
  //[rob1 rob2 i]
  for(int i=0;i<Houses.size();i++){
    int temp = max(Houses.at(i) + rob1,rob2);
    rob1=rob2;
    rob2=temp;
  }
  cout<<"rob: "<<rob2<<endl;
  return rob2;
}

int max(int comp1,int comp2){
  if(comp1 < comp2){
    return comp2;
  }else{
    return comp1;
  }
}