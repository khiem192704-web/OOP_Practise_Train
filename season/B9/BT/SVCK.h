#pragma once
#include "SV.h"

class SVCK : public SV
{
public:
    explicit SVCK(const std::string &MSSV = "", const std::string &Name = "");
    ~SVCK() override = default;

    bool XHB() const override;
    void show() const override;
};
