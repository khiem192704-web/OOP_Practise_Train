#include"matrix.h"
Matrix::Matrix(const int& r, const int& c) : r(r),c(c) {
    if(r == 0 || c == 0) this->p = nullptr;
    else{
        this->p = new int*[r];
        for(int i = 0; i < r; i++) *(this->p + i) = new int[this->c];
        cin>>(*this);
    }
}
Matrix::~Matrix(){
    for(int i = 0; i < this->r; i++) delete[]*(this->p+i);
    delete[] this->p;
}
ostream& operator<<(ostream& out, const Matrix& m){
    for(int i = 0; i < m.r; i++){
        for(int j = 0; j < m.c; j++){
            out<<*(*(m.p + i) + j) <<" ";
        }
        out<<endl;
    }
    return out;
}
istream& operator>>(istream& in, Matrix& m){
    for(int i = 0; i < m.r; i++){
        for(int j = 0; j < m.c; j++){
            cout<<"p["<<i<<"]["<<j<<"]=";
            in>>*(*(m.p + i) + j);
        }
    }
    return in;
}

int& Matrix::operator()(const int& r, const int& c){
    static int NGU;
    if(r >= 0 && r < this->r && c >= 0 && c < this->c) return *(*(this->p + r) + c);
    else return NGU;
}
