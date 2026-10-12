#include"SVIT.h"
SVIT::SVIT(const string& MSSV, const string& Name, double DiemLT, double DiemTH, double DiemCode) {
    this->MSSV = MSSV;
    this->Name = Name;
    this->DiemLT = DiemLT;
    this->DiemTH = DiemTH;
    this->DiemCode = DiemCode;
}
SVIT::~SVIT() {}
double SVIT::GPA(){
    return (DiemLT + DiemTH) / 2.0;
}
bool SVIT::XHB(){
    return GPA() >= 8.0;
}

void SVIT::show() {
    SV::show();
    cout << "DiemLT: " << this->DiemLT << endl;
    cout << "DiemTH: " << this->DiemTH << endl;
    cout << "DiemCode: " << this->DiemCode << endl;
    cout << "GPA: " << this->GPA() << endl;
    if(this->XHB()) {
        cout << "Ban duoc nhan hoc bong" << endl;
    } else {
        cout << "Ban khong duoc nhan hoc bong" << endl;
    }
}
