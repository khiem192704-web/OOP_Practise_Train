#pragma once
#include"SV.h"
class SVCK : public SV {
    private:
        double DiemTH;
        double DiemCK;
    public:
        SVCK(const string& MSSV, const string& Name,double DiemCK, double DiemTH);
        ~SVCK();
        double GPA() override;
        bool XHB() override;
        void show() override;
};
