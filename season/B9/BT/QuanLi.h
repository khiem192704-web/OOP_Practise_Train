#include"SVIT.h"
#include"SVCK.h"
class QuanLi  {
    private:
        SV** DSSV;
        int n;
    public:
        QuanLi(int = 0);
        ~QuanLi();
        void nhapDSSV(int soLuong);
        void xoaSV(string MSSV);
        void hienThiDSSV();
        void hienThiSVXHB();
};
