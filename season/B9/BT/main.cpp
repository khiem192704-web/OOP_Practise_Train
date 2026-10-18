#include "QuanLi.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    QuanLi ql;

    while (true) {
        cout << "\n====================================\n";
        cout << "   CHUONG TRINH QUAN LI SINH VIEN   \n";
        cout << "====================================\n";
        cout << "1. Nhap them sinh vien\n";
        cout << "2. Xoa sinh vien theo MSSV\n";
        cout << "3. Hien thi toan bo danh sach sinh vien\n";
        cout << "4. Hien thi sinh vien dat hoc bong\n";
        cout << "0. Thoat chuong trinh\n";
        cout << "Nhap lua chon cua ban: ";

        int choose;
        if (!(cin >> choose)) {
            cout << "Gia tri khong hop le, vui long nhap so!\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        switch (choose) {
            case 1: {
                int n;
                cout << "Nhap so luong sinh vien can them: ";
                if (!(cin >> n) || n <= 0) {
                    cout << "So luong phai la so nguyen lon hon 0!\n";
                    cin.clear();
                    cin.ignore(1000, '\n');
                    break;
                }
                ql.nhapDSSV(n);
                break;
            }
            case 2: {
                string MSSV;
                cout << "Nhap MSSV can xoa: ";
                getline(cin >> ws, MSSV);
                ql.xoaSV(MSSV);
                break;
            }
            case 3:
                cout << "\n--- DANH SACH SINH VIEN (" << ql.getSoLuong() << " sinh vien) ---\n";
                ql.hienThiDSSV();
                break;
            case 4:
                cout << "\n--- DANH SACH SINH VIEN DAT HOC BONG ---\n";
                ql.hienThiSVXHB();
                break;
            case 0:
                cout << "Ket thuc chuong trinh. Tam biet!\n";
                return 0;
            default:
                cout << "Lua chon khong hop le! Vui long chon lai.\n";
        }
    }
}
