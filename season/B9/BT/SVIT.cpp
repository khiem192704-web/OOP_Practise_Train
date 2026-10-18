#include "SVIT.h"
#include <iostream>

using namespace std;

SVIT::SVIT(const string &MSSV, const string &Name) 
    : SV(MSSV, Name) {}

bool SVIT::XHB() const
{
    // Dieu kien: Phai co mon hoc va GPA >= 8.0
    if (this->soMon == 0)
        return false;
    return (this->GPA() >= 8.0);
}

void SVIT::show() const
{
    cout << "[Khoa: Cong nghe Thong tin]\n";
    SV::show();
    cout << "Ket qua hoc bong: " << (XHB() ? "Dat hoc bong" : "Khong dat") << endl;
}
