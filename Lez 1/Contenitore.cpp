#include <iostream>
using namespace std;

class Contenitore
{
    private:
        double qt;
    public:
        Contenitore(){qt=0;};
        void versa(double _quantity){
            qt += _quantity;
        };
        void togli(double _quantity){
            qt -= _quantity;
        };
        double getQt(){return qt;}
};
