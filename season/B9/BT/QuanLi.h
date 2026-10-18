#pragma once
#include "SVIT.h"
#include "SVCK.h"
#include <string>

class QuanLi {
private:
    SV** DSSV;
    int n;          // So luong sinh vien hien tai
    int capacity;   // Suc chua toi da cua mang con tro
    void expandCapacity(int minCapacity);

public:
    explicit QuanLi(int initialCap = 10);
    ~QuanLi();

    // Cam sao chep (ngan chan loi Double Free vi QuanLi quan ly bo nho dong)
    QuanLi(const QuanLi&) = delete;
    QuanLi& operator=(const QuanLi&) = delete;

    void nhapDSSV(int soLuong);
    void themSV(SV* sv);
    int timSV(const std::string& MSSV) const;
    void xoaSV(const std::string& MSSV);
    void hienThiDSSV() const;
    void hienThiSVXHB() const;
    int getSoLuong() const { return n; }
    void xoaToanBo();
};
