#include <iostream>
using namespace std;

class Contenitore
{
  public:
    double qt;
    Contenitore(){qt=0;};
    void versa(double _quantity){
        qt += _quantity;
    };
    void togli(double _quantity){
        qt -= _quantity;
    };
    double getQt(){return qt;}
};
