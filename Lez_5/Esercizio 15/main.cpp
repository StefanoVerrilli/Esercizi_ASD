#include <iostream>
#include <string>
#include <vector>
#include "gameConvalidator.h"
#include <fstream>
using namespace std;

int main(){
  string File = "Possible_sol.txt";
  gameConvalidator *Convalidator = new gameConvalidator();
  //Convalidator->SingleFileConvalidator(File);
  Convalidator->MultithreadFileConvalidator("Multi_file.txt",2,"Output.txt");
};