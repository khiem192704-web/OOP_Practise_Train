#include "SV.h"
SV::~SV()
{
    delete[] DSMH;
}
void SV::nhapDanhSachMon()
{
    if (this->DSMH != nullptr)
    {
        delete[] this->DSMH;
    }
    int n;
    do
    {
        cout << "Nhap so mon hoc: ";
        cin >> n;
        if (cin.fail())
        {
            cout << "So mon hoc khong hop le" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else if (n <= 0)
        {
            cout << "So mon hoc phai lon hon 0" << endl;
        }
        else
        {
            break;
        }
    } while (true);
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
double SV::tinhGPA() const
{
    if (this->soMon == 0 || this->DSMH == nullptr)
        return 0.0;
    int tongTinChi = this->tongTinChi();
    double tongDiem = 0.0;
    if (tongTinChi == 0)
        return 0.0;
    for (int i = 0; i < this->soMon; ++i)
    {
        tongDiem += this->DSMH[i].getDiem() * this->DSMH[i].getTinChi();
    }

    return (tongTinChi == 0) ? 0.0 : (tongDiem / tongTinChi);
}

void SV::show() const
{
    cout << "MSSV: " << this->MSSV << " | Ho ten: " << this->Name << endl;
    cout << "Danh sach mon hoc:\n";
    for (int i = 0; i < this->soMon; ++i)
    {
        this->DSMH[i].xuat();
    }
    cout << "GPA: " << this->tinhGPA() << endl;
}
