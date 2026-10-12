#pragma once
#include "SV.h"
class SVCK : public SV
{
public:
    SVCK(const string &MSSV, const string &Name);
    ~SVCK();
    double GPA() const override;
    bool XHB() const override;
    void show() const override;
};
