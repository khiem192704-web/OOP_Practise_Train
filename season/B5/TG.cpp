#include"TG.h"
TG::TG(const Point& pa, const Point& pb, const Point& ppc){
    this->A = pa;
    this->B = pb;
    this->C = ppc;
}
TG::TG(const int& xa, const int& ya, const int& xb, const int& yb, const int& xc, const int& yc):A(xa, ya), B(xb, yb), C(xc, yc){}
TG::~TG(){}
void TG::show(){
    A.Show();
    B.Show();
    C.Show();
}