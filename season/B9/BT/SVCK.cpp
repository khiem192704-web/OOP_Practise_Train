#include "SVCK.h"
#include <iostream>

using namespace std;

SVCK::SVCK(const string& MSSV, const string& Name) 
    : SV(MSSV, Name) {}

bool SVCK::XHB() const {
    if (this->soMon == 0) return false;
    if (this->GPA() < 8.0) return false;
    for (int i = 0; i < soMon; ++i) {
        if (DSMH[i].getDiem() < 5.0) return false;
    }
    return true;
}

void SVCK::show() const {
    cout << "[Khoa: Co khi]\n";
    SV::show();
    cout << "Ket qua hoc bong: " << (XHB() ? "Dat hoc bong" : "Khong dat") << endl;
}
