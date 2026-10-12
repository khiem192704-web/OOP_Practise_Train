#pragma once
#include"SV.h"

class SVIT : public SV {
    private:
        double DiemLT;
        double DiemTH;
        double DiemCode;
    public:
        SVIT(const string& MSSV, const string& Name, double DiemLT, double DiemTH, double DiemCode);
        ~SVIT();
        double GPA() override;
        bool XHB() override;
        void show() override;
};
