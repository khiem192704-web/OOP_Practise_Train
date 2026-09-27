#include<iostream>
#include"Sinhvien.h"
Sinhvien::Sinhvien():mssv(0), hoten(""), ngaysinh(""){}
Sinhvien::Sinhvien(const unsigned int& mssv, const std::string& hoten, const std::string& ngaysinh):mssv(mssv), hoten(hoten), ngaysinh(ngaysinh){}
Sinhvien::Sinhvien(const Sinhvien& other):mssv(other.mssv), hoten(other.hoten), ngaysinh(other.ngaysinh){}
Sinhvien::~Sinhvien(){}
void Sinhvien::setHoten(const std::string& hoten){this->hoten = hoten;}
void Sinhvien::setMssv(const unsigned int& mssv){this->mssv = mssv;}
void Sinhvien::setNgaysinh(const std::string& ngaysinh){this->ngaysinh = ngaysinh;}
void Sinhvien::setGpa(const float& gpa){this->gpa = gpa;}
float Sinhvien::getGpa() const {return this->gpa;}  
std::string Sinhvien::getHoten() const {return this->hoten;}
unsigned int Sinhvien::getMssv() const {return this->mssv;}
std::string Sinhvien::getNgaysinh() const {return this->ngaysinh;}
void Sinhvien::Show() const {
    std::cout << "MSSV: " << this->mssv << std::endl;
    std::cout << "Ho ten: " << this->hoten << std::endl;
    std::cout << "Ngay sinh: " << this->ngaysinh<<std::endl;
}
void Sinhvien::add(){
    std::cout << "Nhap MSSV: ";
    std::cin >> this->mssv;
    std::cin.ignore();
    std::cout << "Nhap ho ten: ";
    std::getline(std::cin, this->hoten);
    std::cout << "Nhap ngay sinh: ";
    std::getline(std::cin, this->ngaysinh);
}
