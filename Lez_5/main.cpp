#include <iostream>
#include "Map.h"
#include <fstream>
using namespace std;

int main(){
    ifstream I_file("File.txt");
    Map *Counter = new Map(&I_file);
    Counter->Count_Word();
    Counter->Print_Word();
};