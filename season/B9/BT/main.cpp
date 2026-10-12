#include "QuanLi.h"

int main() {
    QuanLi ql; // Khoi tao 1 doi tuong duy nhat (mac dinh n = 0)
    int choose;

    while (true) {
        cout << "\n====================================\n";
        cout << "   CHUONG TRINH QUAN LI SINH VIEN   \n";
        cout << "====================================\n";
        cout << "1. Nhap danh sach sinh vien\n";
        cout << "2. Xoa sinh vien\n";
        cout << "3. Hien thi danh sach sinh vien\n";
        cout << "4. Hien thi sinh vien dat hoc bong\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> choose;

        switch (choose) {
            case 1: {
                int n;
                cout << "Nhap so luong sinh vien: ";
                cin >> n;
                ql.nhapDSSV(n);
                break;
            }
            case 2: {
                string MSSV;
                cout << "Nhap MSSV can xoa: ";
                cin >> MSSV;
                ql.xoaSV(MSSV);
                break;
            }
            case 3: {
                cout << "\n--- Danh sach sinh vien ---\n";
                ql.hienThiDSSV();
                break;
            }
            case 4: {
                cout << "\n--- Sinh vien dat hoc bong ---\n";
                ql.hienThiSVXHB();
                break;
            }
            case 0:
                cout << "Thoat chuong trinh.\n";
                return 0;
            default:
                cout << "Lua chon khong hop le! Vui long chon lai.\n";
                break;
        }
    }
}