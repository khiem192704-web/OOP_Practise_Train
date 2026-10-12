#include"QuanLi.h"

QuanLi::QuanLi(int n):n(n) {
    DSSV = new SV*[n];
}

QuanLi::~QuanLi(){
    for(int i = 0; i < n; i++) {
        delete DSSV[i];
    }
    delete[] DSSV;
}
void QuanLi::nhapDSSV(int soLuong) {
    if (DSSV != nullptr) {
        for (int i = 0; i < n; i++) {
            delete DSSV[i];
        }
        delete[] DSSV;
    }

    this->n = soLuong;
    if (this->n <= 0) {
        DSSV = nullptr;
        return;
    }

    DSSV = new SV*[this->n];
    for (int i = 0; i < this->n; i++) DSSV[i] = nullptr;

    for(int i = 0; i < this->n; i++) {
        int type;
        string MSSV, Name;
        cout << "Nhap loai sinh vien (1: SVIT, 2: SVCK): ";
        cin >> type;
        cout << "Nhap MSSV: ";
        cin >> MSSV;
        cout << "Nhap Name: ";
        cin.ignore();
        getline(cin,Name);
        switch (type) {
            case 1: {
                double DiemLT, DiemTH, DiemCode;
                cout << "Nhap DiemLT: ";
                cin >> DiemLT;
                cout << "Nhap DiemTH: ";
                cin >> DiemTH;
                cout << "Nhap DiemCode: ";
                cin >> DiemCode;
                DSSV[i] = new SVIT(MSSV, Name, DiemLT, DiemTH, DiemCode);
                break;
            }
            case 2: {
                double DiemCK, DiemTH;
                cout << "Nhap DiemCK: ";
                cin >> DiemCK;
                cout << "Nhap DiemTH: ";
                cin >> DiemTH;
                DSSV[i] = new SVCK(MSSV,Name, DiemCK, DiemTH);
                break;
            }
            default:
                cout << "Loai sinh vien khong hop le!" << endl;
                i--; // Giảm chỉ số để nhập lại sinh viên
        }
    }
}

void QuanLi::xoaSV(string MSSV) {
    if(this->n == 0) {
        cout << "Danh sach sinh vien rong!" << endl;
        return;
    }
    int index = -1;
    for(int i = 0; i < n; i++) {
        if(DSSV[i]->getMSSV() == MSSV && DSSV[i] != nullptr) {
            index = i;
            break;
        }
    }
    if(index == -1) {
        cout << "Khong tim thay sinh vien co MSSV: " << MSSV << endl;
    } else {
        delete DSSV[index];
        for(int i = index; i < n - 1; i++) {
            DSSV[i] = DSSV[i + 1];
        }
        n--;
        cout << "Da xoa sinh vien co MSSV: " << MSSV << endl;
    }
}

void QuanLi::hienThiDSSV() {
    if(this->n == 0) {
        cout << "Danh sach sinh vien rong!" << endl;
        return;
    }
    for(int i = 0; i < n; i++) {
        DSSV[i]->show();
        cout << "------------------------" << endl;
    }
}

void QuanLi::hienThiSVXHB() {
    if(this->n == 0) {
        cout << "Danh sach sinh vien rong!" << endl;
        return;
    }
    int index = 0;
    for(int i = 0; i < n; i++) {
        if(DSSV[i]->XHB()) {
            DSSV[i]->show();
            cout << "------------------------" << endl;
            index++;
        }
    }
    if(index == 0) {
        cout << "Khong co sinh vien nao dat hoc bong!" << endl;
    }
    else {
        cout << "Co " << index << " sinh vien dat hoc bong!" << endl;
    }
}
