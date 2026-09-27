#pragma once
#include <string>
class Sinhvien{
    private:
        unsigned int mssv;
        std::string hoten;
        std::string ngaysinh;
        float gpa;
    public:
        Sinhvien();
        Sinhvien(const unsigned int&, const std::string&, const std::string&); 
        Sinhvien (const Sinhvien&);
        ~Sinhvien();
        void setHoten(const std::string&);
        void setMssv(const unsigned int&);
        void setNgaysinh(const std::string&);
        void setGpa(const float&);
        float getGpa() const;
        std::string getHoten() const;
        unsigned int getMssv() const;
        std::string getNgaysinh() const;
        void Show() const;
        void add();
};