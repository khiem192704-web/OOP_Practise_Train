#include"SVCK.h"
SVCK::SVCK(const string& MSSV, const string& Name, double DiemCK, double DiemTH) {

    this->MSSV = MSSV;
    this->Name = Name;
    this->DiemCK = DiemCK;
    this->DiemTH = DiemTH;
}
SVCK::~SVCK() {}
double SVCK::GPA(){
    return DiemCK * 0.6 + DiemTH * 0.4;
}

bool SVCK::XHB(){
    return GPA() >= 8.0;
}

void SVCK::show() {
    SV::show();
    cout << "DiemTH: " << this->DiemTH << endl;
    cout << "DiemCK: " << this->DiemCK << endl;
    cout << "GPA: " << this->GPA() << endl;
    if(this->XHB()) {
        cout << "Ban duoc nhan hoc bong" << endl;
    } else {
        cout << "Ban khong duoc nhan hoc bong" << endl;
    }
}
