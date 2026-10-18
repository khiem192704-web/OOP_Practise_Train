#include "SV.h"
#include <iostream>
#include <limits>

using namespace std;

SV::SV(const string& mssv, const string& name)
    : MSSV(mssv), Name(name), DSMH(nullptr), soMon(0) {}

SV::~SV()
{
    delete[] DSMH;
    DSMH = nullptr;
}

// Copy Constructor (Deep Copy)
SV::SV(const SV& other)
    : MSSV(other.MSSV), Name(other.Name), DSMH(nullptr), soMon(other.soMon)
{
    if (other.DSMH != nullptr && other.soMon > 0)
    {
        this->DSMH = new MonHoc[this->soMon];
        for (int i = 0; i < this->soMon; ++i)
        {
            this->DSMH[i] = other.DSMH[i];
        }
    }
}

// Copy Assignment Operator (Deep Copy)
SV& SV::operator=(const SV& other)
{
    if (this != &other)
    {
        delete[] this->DSMH;
        this->DSMH = nullptr;

        this->MSSV = other.MSSV;
        this->Name = other.Name;
        this->soMon = other.soMon;

        if (other.DSMH != nullptr && other.soMon > 0)
        {
            this->DSMH = new MonHoc[this->soMon];
            for (int i = 0; i < this->soMon; ++i)
            {
                this->DSMH[i] = other.DSMH[i];
            }
        }
    }
    return *this;
}

void SV::nhapDanhSachMon()
{
    // Giai phong vung nho cu neu da tung nhap de tranh memory leak
    if (this->DSMH != nullptr)
    {
        delete[] this->DSMH;
        this->DSMH = nullptr;
    }

    int n;
    while (true)
    {
        cout << "Nhap so mon hoc: ";
        if (cin >> n && n > 0)
        {
            break;
        }
        cout << "So mon hoc khong hop le (phai la so nguyen > 0), vui long nhap lai!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    this->soMon = n;
    this->DSMH = new MonHoc[this->soMon];
    for (int i = 0; i < n; i++)
    {
        cout << "\n== Nhap mon hoc thu " << i + 1 << " ==\n";
        DSMH[i].nhap();
    }
}

int SV::tongTinChi() const
{
    int tong = 0;
    for (int i = 0; i < this->soMon; ++i)
    {
        tong += this->DSMH[i].getTinChi();
    }
    return tong;
}

double SV::GPA() const
{
    if (this->soMon == 0 || this->DSMH == nullptr)
        return 0.0;
    int tongTC = this->tongTinChi();
    if (tongTC == 0)
        return 0.0;

    double tongDiem = 0.0;
    for (int i = 0; i < this->soMon; ++i)
    {
        tongDiem += this->DSMH[i].getDiem() * this->DSMH[i].getTinChi();
    }

    return tongDiem / tongTC;
}

void SV::show() const
{
    cout << "MSSV: " << this->MSSV << " | Ho ten: " << this->Name << endl;
    cout << "Danh sach mon hoc:\n";
    for (int i = 0; i < this->soMon; ++i)
    {
        this->DSMH[i].xuat();
    }
    cout << "Tong tin chi: " << this->tongTinChi() << " | GPA: " << this->GPA() << endl;
}
