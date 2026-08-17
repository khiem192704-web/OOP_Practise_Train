#include<iostream>
using namespace std;
class fraction{
    private:
        double TS,MS;
    public:
        fraction() : TS(0),MS(0){}
        fraction(double TS = 1.2, double MS = 2.4);
        fraction(double TS, double MS){
            this->TS = TS;
            this->MS = MS;
        }
        double getTS(){return TS;}
        double getMS(){return MS;}
        friend istream& operator >>(istream &in, fraction &a ){
            
        }


};