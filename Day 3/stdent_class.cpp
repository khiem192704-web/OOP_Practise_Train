#include<bits/stdc++.h>
using namespace std;
class SinhVien{
    private:
        string ma, hoten, ngaysinh, lop;
        double gpa;
    public:
        void student(string ma,string hoten,string ngaysinh,string lop,double gpa){
            this->ma = ma;
            this->hoten = hoten;
            this->ngaysinh = ngaysinh;
            this->lop = lop;
            this->gpa = gpa;
        }
        void in(){
            cout << ma <<" "<< hoten <<" "<< ngaysinh <<" "<< lop <<" "<< gpa;
        }
        friend istream& operator >> (istream& in, SinhVien& a);
};

istream& operator >> (istream& in, SinhVien& a){
    cout<<"Nhap ma so sinh vien:"; in >> a.ma;
    cout<<"Nhap ho va ten:";
    in.ignore();
    getline(in,a.hoten);
    cout<<"Nhap ngay sinh:"; in>>a.ngaysinh;
    cout<<"Nhap lop:"; in>>a.lop;
    cout<<"Nhap gpa:"; in>>a.gpa;
    return in;
}

int main(){
    SinhVien a;
    cin>>a;
    a.in();
}