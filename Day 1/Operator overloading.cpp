#include<bits/stdc++.h>
using namespace std;

class Giaovien;
class SinhVien;

class SinhVien{
    friend class GiaoVien;
    private:
        string id, ten, ns;
        double gpa;
    public:
        friend istream& operator >> (istream &in, SinhVien& a);
        friend ostream& operator << (ostream &out, SinhVien a);
};

istream& operator >> (istream &in, SinhVien& a){
    cout<<"Nhap id:";
    in>>a.id;
    cout<<"Nhap ten:"; in.ignore();
    getline(in,a.ten);
    cout<<"Nhap ngay sinh:"; in>>a.ns;
    cout<<"Nhap diem:"; in>>a.gpa;
    return in;
}

ostream& operator << (ostream &out, SinhVien a){
    cout<< a.id <<" "<< a.ten <<" "<< a.ns << fixed << setprecision(2) << a.gpa <<endl;
    return out;
}


int main(){
    SinhVien x;
    cin>>x;
    cout<<x;

}