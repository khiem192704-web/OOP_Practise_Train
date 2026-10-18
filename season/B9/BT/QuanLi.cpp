#include "QuanLi.h"
#include <iostream>
#include <limits>

using namespace std;

QuanLi::QuanLi(int initialCap) 
    : n(0), capacity(initialCap > 0 ? initialCap : 10)
{
    DSSV = new SV*[capacity];
    for (int i = 0; i < capacity; ++i)
    {
        DSSV[i] = nullptr;
    }
}

QuanLi::~QuanLi()
{
    xoaToanBo();
    delete[] DSSV;
    DSSV = nullptr;
    capacity = 0;
}

void QuanLi::xoaToanBo()
{
    for (int i = 0; i < n; ++i)
    {
        delete DSSV[i];
        DSSV[i] = nullptr;
    }
    n = 0;
}

void QuanLi::expandCapacity(int minCapacity)
{
    if (minCapacity <= capacity)
        return;

    int newCap = capacity * 2;
    if (newCap < minCapacity)
        newCap = minCapacity;

    SV** newDSSV = new SV*[newCap];
    for (int i = 0; i < n; ++i)
    {
        newDSSV[i] = DSSV[i];
    }
    for (int i = n; i < newCap; ++i)
    {
        newDSSV[i] = nullptr;
    }

    delete[] DSSV;
    DSSV = newDSSV;
    capacity = newCap;
}

int QuanLi::timSV(const string& MSSV) const
{
    for (int i = 0; i < n; ++i)
    {
        if (DSSV[i] != nullptr && DSSV[i]->getMSSV() == MSSV)
        {
            return i;
        }
    }
    return -1;
}

void QuanLi::themSV(SV* sv)
{
    if (sv == nullptr) return;
    expandCapacity(n + 1);
    DSSV[n++] = sv;
}

void QuanLi::nhapDSSV(int soLuong)
{
    if (soLuong <= 0)
    {
        cout << "So luong sinh vien phai lon hon 0!\n";
        return;
    }

    expandCapacity(n + soLuong);

    for (int k = 0; k < soLuong; ++k)
    {
        cout << "\n====================================\n";
        cout << "   Nhap sinh vien thu " << n + 1 << "\n";
        cout << "====================================\n";

        int type = 0;
        while (true)
        {
            cout << "Nhap loai sinh vien (1: SVIT, 2: SVCK): ";
            if (cin >> type && (type == 1 || type == 2))
            {
                break;
            }
            cout << "Loai sinh vien khong hop le (chi nhan 1 hoac 2), vui long nhap lai!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        string MSSV, Name;
        while (true)
        {
            cout << "Nhap MSSV: ";
            getline(cin >> ws, MSSV);
            if (timSV(MSSV) != -1)
            {
                cout << "MSSV \"" << MSSV << "\" da ton tai trong he thong! Vui long nhap ma khac.\n";
            }
            else
            {
                break;
            }
        }

        cout << "Nhap Ho ten: ";
        getline(cin >> ws, Name);

        SV* sv = nullptr;
        if (type == 1)
        {
            sv = new SVIT(MSSV, Name);
        }
        else
        {
            sv = new SVCK(MSSV, Name);
        }

        sv->nhapDanhSachMon();
        DSSV[n++] = sv;
    }
}

void QuanLi::xoaSV(const string& MSSV)
{
    if (this->n == 0)
    {
        cout << "Danh sach sinh vien dang rong!\n";
        return;
    }

    int index = timSV(MSSV);
    if (index == -1)
    {
        cout << "Khong tim thay sinh vien co MSSV: " << MSSV << "\n";
        return;
    }

    delete DSSV[index];
    for (int i = index; i < n - 1; ++i)
    {
        DSSV[i] = DSSV[i + 1];
    }
    DSSV[n - 1] = nullptr;
    n--;

    cout << "Da xoa thanh cong sinh vien co MSSV: " << MSSV << "\n";
}

void QuanLi::hienThiDSSV() const
{
    if (this->n == 0)
    {
        cout << "Danh sach sinh vien dang rong!\n";
        return;
    }

    for (int i = 0; i < n; ++i)
    {
        if (DSSV[i] != nullptr)
        {
            DSSV[i]->show();
            cout << "-------------------------------------\n";
        }
    }
}

void QuanLi::hienThiSVXHB() const
{
    if (this->n == 0)
    {
        cout << "Danh sach sinh vien dang rong!\n";
        return;
    }

    int dem = 0;
    for (int i = 0; i < n; ++i)
    {
        if (DSSV[i] != nullptr && DSSV[i]->XHB())
        {
            DSSV[i]->show();
            cout << "-------------------------------------\n";
            dem++;
        }
    }

    if (dem == 0)
    {
        cout << "Khong co sinh vien nao dat hoc bong!\n";
    }
    cout << "==> Tong so sinh vien dat hoc bong: " << dem << "\n";
}
