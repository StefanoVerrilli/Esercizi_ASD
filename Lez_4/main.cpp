#include "LinkedList.h"
#include "Tx.h"
#include "Blocco.h"
#include "Utility.h"
#include <iostream>
using namespace std;
int main(){
  
  LinkedList<Nodo,Blocco> ll_blocks;
  
  ll_blocks = GenerateBlockchain();
  Generate_Interface(ll_blocks);
  return 0;
}