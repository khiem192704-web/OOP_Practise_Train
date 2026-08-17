#include<bits/stdc++.h>
using namespace std;

class Giaovien;
class SinhVien;

class SinhVien{
    friend class GiaoVien;
    private:
        string id, ten, ns;
        double gpa;
        static int dem;
    public:
        SinhVien();// ham khởi tạo
        SinhVien(string,string,string,double);
        void xinchao();
        void dihoc();
        void nhap();
        void in();
        double getGpa();
        void setGpa(double);
        void tangDem();
        int getGem(){return dem;}
        friend void inthongtin(SinhVien);
        friend void chuanhoa(SinhVien&);
        ~SinhVien();// hàm hủy diệt
};

class GiaoVien{
    private:
        string khoa;
    public:
    void update(SinhVien&);
};

void GiaoVien::update(SinhVien &x){
    x.gpa = 3.2;
}

void inthongtin(SinhVien a){
    cout<<a.id<<" "<<a.ten<<endl;
}

void chuanhoa(SinhVien &a){
    string res = "";
    stringstream ss(a.ten);
    string token;
    while(ss >> token){
        res += toupper(token[0]);
        for(int i = 0; i < token.length(); i++){
            res += tolower(token[i]);
        }
        res += " ";
    }
    res.erase(res.length() - 1);
    a.ten = res;
}

int SinhVien::dem = 0;

void SinhVien::tangDem(){
    ++dem;
}

SinhVien::SinhVien(string id, string ten, string ns, double gpa ){
    cout<<"Ham khoi tao duoc tao co tham so!\n";
    this->ten = ten;
    this->id = id;
    this->ns = ns;
    this->gpa = gpa;
}

void SinhVien::nhap(){
    ++dem;
    this->id = "SV" + string(3 - to_string(dem).length(),'0') + to_string(dem);
    // cout<<"Nhap id:"; cin>>this->id;
    cin.ignore();
    cout<<"Nhap ten:"; getline(cin,this->ten);
    cout<<"Nhap ns:"; cin>>this->ns;
    cout<<"Nhap diem:"; cin>> this->gpa;
}

void SinhVien::in(){
    cout<< this->id <<" "<< this->ten <<" "<< this->ns <<" "<< fixed << setprecision(2) << this->gpa << endl;
}

double SinhVien::getGpa(){
    return this->gpa;
}

void SinhVien::setGpa(double gpa){
    this->gpa = gpa;
}

bool cmp(SinhVien a, SinhVien b){
    return a.getGpa() > b.getGpa();
}

SinhVien::SinhVien(){
    cout<<"Doi tuong duoc khoi tao tai day!\n";
    id = ten = ns ="";
    gpa = 0;
}

SinhVien::~SinhVien(){
    cout<<"Doi tuong duoc huy tai day!\n";
}

void SinhVien::xinchao(){
    cout<<"Hello!\n";
}

void SinhVien::dihoc(){
    cout<<"Di hoc\n";
}

void abc(){
    SinhVien x;
}

int main(){
    // SinhVien x("123","Nguyen Van A","23/12/2003", 3.14);
    // x.dihoc();
    // x.xinchao();
    // abc();
    // cout<<"Xin chao!\n";
    // if(1){
    //     SinhVien x;
    // }
    // cout<<"Hello!\n";
    // SinhVien x;
    // x.nhap();
    // x.in();
    // int n; cin>>n;
    // SinhVien a[100];
    // for(int i = 0; i < n; i++){
    //     a[i].nhap();
    // }
    // sort(a, a + n, cmp);
    // for(int i = 0; i < n; i++){
    //     a[i].in();
    // }
    SinhVien x;
    x.tangDem();
    x.tangDem();
    SinhVien y;
    cout<<y.getGem()<<endl;
}