#include<iostream>
#include"CuCon.h"
CuCon::CuCon(const int& a, const int& b, const int& z) : P1(a), P2(b){
    this->z = z;
    cout << "Dung CuCon" << endl;
}

CuCon::~CuCon(){
    cout << "Huy CuCon" << endl;
}

void CuCon::CC(){
    cout << "CC CuCon" << endl;
}

void CuCon::PP(){
    cout << "PP CuCon" << endl;
}
