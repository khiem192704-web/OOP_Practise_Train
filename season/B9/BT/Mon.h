#pragma once
#include <string>

class MonHoc {
private:
    std::string tenmon;
    int tinchi = 0;
    double diem = 0.0;

public:
    MonHoc(const std::string& ten = "", int tc = 0, double d = 0.0);
    void nhap();
    void xuat() const;
    int getTinChi() const;
    double getDiem() const;
    const std::string& getTenMon() const;
};
