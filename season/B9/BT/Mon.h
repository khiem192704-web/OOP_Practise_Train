#pragma once
#include <string>
using namespace std;

class MonHoc{
    private:
        string tenmon;
        int tinchi = 0;
        double diem = 0.0;
    public:
        MonHoc(string ten = "", int tc = 0, double d = 0.0);
        void nhap();
        void xuat() const;
        int getTinChi() const;
        double getDiem() const;
};
