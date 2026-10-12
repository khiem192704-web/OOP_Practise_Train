#pragma once
#include "SV.h"

class SVIT : public SV
{
public:
    SVIT(const string &MSSV, const string &Name);
    ~SVIT();
    double GPA() const override;
    bool XHB() const override;
    void show() const override;
};
