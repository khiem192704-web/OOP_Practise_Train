#include "QuanLi.h"

QuanLi::QuanLi(int n) : n(n)
{
    DSSV = new SV *[n];
}

QuanLi::~QuanLi()
{
    for (int i = 0; i < n; i++)
    {
        delete DSSV[i];
    }
    delete[] DSSV;
}
void QuanLi::nhapDSSV(int soLuong)
{
    if (DSSV != nullptr)
    {
        for (int i = 0; i < n; i++)
        {
            delete DSSV[i];
        }
        delete[] DSSV;
    }
    this->n = soLuong;
    if (this->n <= 0)
    {
        DSSV = nullptr;
        return;
    }
    DSSV = new SV *[this->n];
    for (int i = 0; i < n; i++)
    {
        int type;
        cout << "Nhap loai sinh vien (1: SVIT, 2: SVCK): ";
        if (!(cin >> type))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            type = 0;
        }
        if (type != 1 && type != 2)
        {
            cout << "Loai sinh vien khong hop le!" << endl;
            i--;
            continue;
        }

        string MSSV, Name;
        cout << "Nhap MSSV: ";
        cin >> MSSV;
        cout << "Nhap Name: ";
        getline(cin >> ws, Name);

        if (type == 1)
            DSSV[i] = new SVIT(MSSV, Name);
        else
            DSSV[i] = new SVCK(MSSV, Name);
        DSSV[i]->nhapDanhSachMon();
    }
}

void QuanLi::xoaSV(string MSSV)
{
    if (this->n == 0)
    {
        cout << "Danh sach sinh vien rong!" << endl;
        return;
    }
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        if (DSSV[i]->getMSSV() == MSSV && DSSV[i] != nullptr)
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        cout << "Khong tim thay sinh vien co MSSV: " << MSSV << endl;
    }
    else
    {
        delete DSSV[index];
        for (int i = index; i < n - 1; i++)
        {
            DSSV[i] = DSSV[i + 1];
        }
        n--;
        cout << "Da xoa sinh vien co MSSV: " << MSSV << endl;
    }
}

void QuanLi::hienThiDSSV()
{
    if (this->n == 0)
    {
        cout << "Danh sach sinh vien rong!" << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        DSSV[i]->show();
        cout << "------------------------" << endl;
    }
}

void QuanLi::hienThiSVXHB()
{
    if (this->n == 0)
    {
        cout << "Danh sach sinh vien rong!" << endl;
        return;
    }
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        if (DSSV[i]->XHB())
        {
            DSSV[i]->show();
            cout << "------------------------" << endl;
            index++;
        }
    }
    if (index == 0)
    {
        cout << "Khong co sinh vien nao dat hoc bong!" << endl;
    }
    cout << "Tong so sinh vien dat hoc bong: " << index << endl;
}
