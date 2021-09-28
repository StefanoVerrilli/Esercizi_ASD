#include <iostream>
using namespace std;
#include "Anfora.cpp"

int main(){
  Anfora Anfora_3(3);
  Anfora Anfora_5(5);
  Anfora_5.riempi();
  Anfora_5.spostaContenuto(Anfora_3);
  cout << "Anfora 3: "<< Anfora_3.getQt() <<endl;
  cout << "Anfora 5: "<< Anfora_5.getQt() <<endl;
  Anfora_3.svuota();
  cout<<"Svuoto Anfora 3"<<endl;
  Anfora_5.spostaContenuto(Anfora_3);
  cout<<"Sposto i restanti 2 in anfora 3"<<endl;
  Anfora_5.riempi();
  Anfora_5.spostaContenuto(Anfora_3);
  cout<<"Dopo aver riempito nuovamento l' anfora da 5, sposto il rimanente 1 nella 3"<<endl;
  Anfora_3.svuota();
  cout<<"Ottengo così il risultato desiderato"<<endl;
  cout << "Anfora 3: " << Anfora_3.getQt() << endl;
  cout << "Anfora 5: " << Anfora_5.getQt() << endl;
  return 0;
};