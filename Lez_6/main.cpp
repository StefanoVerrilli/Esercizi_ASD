#include <iostream>
#include <vector>
#include "CheckArray.h"
using namespace std;


int main(){
  vector<int> Vec;
  CheckArray *check = new CheckArray();
  Vec = check->GenerateExemple(9,20,30);
  check->PrintVector(Vec);
  vector<int> result;
  check->FindHypotesis(Vec,0,Vec.size()-1,result);
  for(auto &x: result)
    cout<<"Elemento per cui l' ipotesi è dimostrato: "<<Vec.at(x)<<" rispetto a: "<<Vec.at(x+1)<<endl;
}