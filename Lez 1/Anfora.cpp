#include <iostream>
#include "Contenitore.cpp"
using namespace std;


class Anfora: public Contenitore
  {
    private:
        double capacity;
        double Lt_to_add;
        void Calulation_Recorsive(double _Lt_to_add,Anfora &_other);
    public:
        Anfora(double _capacity): Contenitore(){capacity=_capacity;}
        double getCapacity(){return capacity;}
        void riempi(){versa(getCapacity() - getQt());}
        void svuota(){togli(getQt());}
        bool isVuota(){return (getQt()==0 ? true : false);}
        bool isPiena(){return (getQt()==this->capacity ? true : false);}
        void spostaContenuto(Anfora &_other){
            Lt_to_add = _other.getCapacity() - _other.getQt();
            Calulation_Recorsive(Lt_to_add,_other);
        }
        
  };

     // Il metodo ricosivo è stato ottimale per adattarsi al numero di unità necessarie per completare
     // l' anfora, di seguito le condizioni di uscita e il calcolo della quantità da scalare.
  void Anfora::Calulation_Recorsive(double _Lt_to_add,Anfora &_other){
          if(_other.isPiena() || isVuota()){return;}
          if(getQt() >= _Lt_to_add){
              togli(_Lt_to_add);
              _other.versa(_Lt_to_add);
              return;
              }
              else{
                  _Lt_to_add--;
                  Calulation_Recorsive(_Lt_to_add,_other);
              }
      }
