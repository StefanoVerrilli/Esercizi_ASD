#include <iostream>
#include <fstream>
#include "LinkedList.h"
#include "Tx.h"
#include "Blocco.h"
#include <ctime>
#include <vector>
using namespace std;

vector<string> ReadAddress(string _addr_file){
  ifstream SAddr_file(_addr_file);
  vector<string>  file_lines;
  string line;
  while(getline(SAddr_file,line))
    file_lines.push_back(line);
  SAddr_file.close();
  return file_lines;
}

void Generate_Correct_Transaction(vector<string> _addresses,string &from,string &to){
    string Dummy1,Dummy2;
    Dummy1 = _addresses.at(rand()%_addresses.size());
    Dummy2 = _addresses.at(rand()%_addresses.size());
    while(Dummy1==Dummy2)
          Dummy2 = _addresses.at(rand()%_addresses.size());
    from = Dummy1;to=Dummy2;
}

LinkedList<Nodo,Blocco> GenerateBlockchain(){
    LinkedList<Nodo,Blocco> ll_blocks;
    srand(time(NULL));
    vector<string> Addresses = ReadAddress("Address.txt");
    string from,to;
    for(int i=0;i<rand()%30+10;i++){
      Blocco *block = new Blocco(i);
      for(int j=0;j<rand()%20+2;j++){
        Generate_Correct_Transaction(Addresses,from,to);
        block->AddTx(new Tx(rand()%300+1,from,to));
      }
      block->CloseTx();
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
    cout<<"Inserire Indirizzo da Ricercare / ottenere bilancio"<<endl;
    cout<<"Query: ";
    cin >> answer;
    sum = GetBalance(_BC_Demo,answer);
    cout<<"Total Balance: "<<sum<<endl;
  }
}