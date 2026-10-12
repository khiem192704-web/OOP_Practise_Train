#include "SVIT.h"
SVIT::SVIT(const string &MSSV, const string &Name)
{
    this->MSSV = MSSV;
    this->Name = Name;
    this->DSMH = nullptr;
    this->soMon = 0;
}
SVIT::~SVIT()
{
}

double SVIT::GPA() const
{
    return this->tinhGPA();
}

bool SVIT::XHB() const
{
    return (this->GPA() >= 8.0);
}

void SVIT::show() const
{
    cout << "[Khoa: Cong nghe Thong tin]\n";
    SV::show();
    cout << "Ket qua hoc bong: " << (XHB() ? "Dat hoc bong" : "Khong dat") << endl;
}
