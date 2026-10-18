#include "Mon.h"
#include <iostream>

using namespace std;

MonHoc::MonHoc(const string& ten, int tc, double d) 
    : tenmon(ten), tinchi(tc), diem(d) {}

void MonHoc::nhap() {
    cout << "Nhap ten mon: ";
    getline(cin >> ws, tenmon);

    cout << "Nhap so tin chi: ";
    while (!(cin >> tinchi) || tinchi <= 0) {
        cout << "Tin chi khong hop le (phai > 0), nhap lai: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    cout << "Nhap diem (0-10): ";
    while (!(cin >> diem) || diem < 0.0 || diem > 10.0) {
        cout << "Diem khong hop le (tu 0 den 10), nhap lai: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
}

void MonHoc::xuat() const {
    cout << "Ten mon: " << this->tenmon 
         << " | Tin chi: " << this->tinchi 
         << " | Diem: " << this->diem << '\n';
}

int MonHoc::getTinChi() const {
    return tinchi;
}

double MonHoc::getDiem() const {
    return diem;
}

const string& MonHoc::getTenMon() const {
    return tenmon;
}
