#include "LinkedList.h"
#include "Tx.h"
#include "Blocco.h"
#include <iostream>
using namespace std;
int main(){
  
  LinkedList<Nodo,Tx> ll_tx;
  LinkedList<Nodo,Blocco> ll_blocks;
  
  Blocco *Block = new Blocco(1);
  Block->AddTx(new Tx(10,"0x04404","0x34434"));
  Block->AddTx(new Tx(20,"0x34434","0x32434"));
  Block->AddTx(new Tx(10,"0x04404","0x34434"));
  Blocco *Block2 = new Blocco(2);
  Block2->AddTx(new Tx(10,"0x04404","0x34434"));
  Block2->AddTx(new Tx(20,"0x34434","0x32434"));
  Block2->AddTx(new Tx(10,"0x04404","0x34442"));
  Blocco *Block3 = new Blocco(3);
  Block3->AddTx(new Tx(10,"0x04404","0x34434"));
  Block3->AddTx(new Tx(20,"0x34434","0x32434"));
  Block3->AddTx(new Tx(10,"0x04404","0x34434"));
  ll_blocks.AddNodo(Block);
  ll_blocks.AddNodo(Block2);
  ll_blocks.AddNodo(Block3);
  Nodo<Blocco> *Head = ll_blocks.Getfirst();
  float sum=0;
  while(Head!=NULL){
      sum += Head->GetElement()->FindUserTxs("0x34434");
      Head = Head->GetNext();
  }
  cout<<sum<<endl;
  return 0;
}