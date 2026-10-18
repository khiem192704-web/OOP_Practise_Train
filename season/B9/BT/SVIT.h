#pragma once
#include "SV.h"

class SVIT : public SV
{
public:
    explicit SVIT(const std::string &MSSV = "", const std::string &Name = "");
    ~SVIT() override = default;

    bool XHB() const override;
    void show() const override;
};
