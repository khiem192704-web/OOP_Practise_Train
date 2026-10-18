#pragma once
#include "Mon.h"
#include <string>

class SV
{
protected:
    std::string MSSV;
    std::string Name;
    MonHoc *DSMH;
    int soMon;

public:
    explicit SV(const std::string& mssv = "", const std::string& name = "");
    virtual ~SV();

    // Rule of Three: tranh loi Double Free khi sao chep doi tuong
    SV(const SV& other);
    SV& operator=(const SV& other);

    // Tinh da hinh
    virtual double GPA() const;
    virtual bool XHB() const = 0;
    virtual void show() const;

    void nhapDanhSachMon();
    int getSoMon() const { return this->soMon; }
    int tongTinChi() const;
    const std::string& getMSSV() const { return this->MSSV; }
    const std::string& getName() const { return this->Name; }
};
