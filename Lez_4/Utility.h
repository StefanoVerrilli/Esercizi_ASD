#include <iostream>
#include "LinkedList.h"
#include "Tx.h"
#include "Blocco.h"
using namespace std;

LinkedList<Nodo,Blocco> GenerateBlockchain(){
    LinkedList<Nodo,Blocco> ll_blocks;

    for(int i=0;i<3;i++){
      Blocco *block = new Blocco(i);
      for(int j=0;j<20/*TODO: rand num*/;j++){
        block->AddTx(new Tx(30,"0x34434","0x04404"));
      }
      ll_blocks.AddNodo(block);
    }
    return ll_blocks;
}

float GetBalance(LinkedList<Nodo,Blocco> ll_to_iterate,string _tofind){
  Nodo<Blocco>*Head = ll_to_iterate.Getfirst();
  float sum=0;
  while(Head!=NULL){
      sum += Head->GetElement()->FindUserTxs(_tofind);
      Head = Head->GetNext();
  }
  return sum;
}

void Generate_Interface(LinkedList<Nodo,Blocco> _BC_Demo){
  string answer;
  float sum;
  while(1){
  cout<<"Inserire Indirizzo da Ricercare/ ottenere bilancio"<<"\n"<<endl;
  cin >> answer;
  sum = GetBalance(_BC_Demo,answer);
  cout<<"Total Balance: "<<sum<<endl;
  }
}