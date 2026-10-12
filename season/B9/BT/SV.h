#pragma once
#include "Mon.h"
#include <iostream>
#include <string>

using namespace std;
class SV
{
protected:
    string MSSV;
    string Name;
    MonHoc *DSMH;
    int soMon;

public:
    virtual ~SV();
    virtual double GPA() const = 0;
    virtual bool XHB() const = 0;
    virtual void show() const = 0;
    void nhapDanhSachMon();
    int getSoMon() const
    {
        return this->soMon;
    }
    int tongTinChi() const;
    double tinhGPA() const;
    string getMSSV() const
    {
        return this->MSSV;
    }
    string getName() const
    {
        return this->Name;
    }
};
