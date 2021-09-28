#include <iostream>
#include "Contenitore.cpp"
using namespace std;


class Anfora: public Contenitore
  {
    private:
        double capacity;
        bool CheckOverflow(double _quantity);
        bool CheckUnderflow(double _quantity);
    public:
        Anfora(double _capacity): Contenitore(){capacity=_capacity;}
        double getCapacity(){return capacity;}
        void riempi(){
          !CheckOverflow(capacity) ? versa(getCapacity()) : versa(getQt());
        }
        void svuota(){
          !CheckUnderflow(capacity) ? togli(getCapacity()) : togli(getQt());
        }
        bool isVuota(){return (getQt()==0 ? true : false);}
        bool isPiena(){return (getQt()==this->capacity ? true : false);}
        void spostaContenuto(Anfora &_other){
            double Lt_to_add = _other.getCapacity() - _other.getQt();
            Calulation_Recorsive(Lt_to_add,_other);
        }

        // Il metodo ricosivo è stato ottimale per adattarsi al numero di unità necessarie per completare
        // l' anfora, di seguito le condizioni di uscita e il calcolo della quantità da scalare.
        void Calulation_Recorsive(double _Lt_to_add,Anfora &_other){
          if(_other.isPiena() || _Lt_to_add ==0){return;}
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
  };

bool Anfora::CheckOverflow(double insertion){
  return (getQt() + insertion > this->capacity ? true : false);
}

bool Anfora::CheckUnderflow(double _deletion){
  return (getQt() - _deletion < 0 ? true : false);
}