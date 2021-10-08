#pragma once
#include <iostream>
#include"Nodo.h"
#include<string>

using namespace std;

class Tx{
    private:
        int Val;
        string From;
        string To;

    public:
        Tx(int val, string f, string t):Val{val},From(f), To(t){}
        string GetFrom(){return From;}
        string GetTo(){return To;}
        int GetVal(){return Val;}
        void PrintInfo(){
            cout<<"--------------------"<<endl;
            cout<<"From: "<<this->GetFrom()<<endl;
            cout<<"--------------------"<<endl;
            cout<<"To: "<<this->GetTo()<<endl;
            cout<<"--------------------"<<endl;
            cout<<"Value: "<<this->GetVal()<<endl;
            cout<<"--------------------"<<endl;
            cout<<"\n"<<endl;
        }
};
