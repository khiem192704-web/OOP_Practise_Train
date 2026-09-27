#include"Vector.h"
Vector::Vector(const int& n) : n(n){
    if(n == 0) this->data = nullptr;
    else{
        this->data = new int[n];
        cin>> *this;
    }
}

Vector::Vector(const Vector& v) : n(v.n){
    this->data = new int[this->n];
    for(int i = 0; i < this->n; i++){
        (*this)[i] = *(v.data + i);
    }
    cout << "copy"<<endl;
}

Vector::~Vector(){
    if(this->data != nullptr) delete[] this->data;
}

ostream& operator<<(ostream& out, const Vector& v){
    for(int i = 0; i < v.n; i++) out<<v.data[i]<<" "; // out<<*(v.p+1)<<" ";
    return out;
}

istream& operator>>(istream& in, Vector& v){
    for(int i = 0; i< v.n; i++) in>>v.data[i]; // in>>*(v.p+i);
    return in;
}

int& Vector::operator[](const int& index){
    static int NGU = 0;
    if(index >= 0 && index < this->n) return *(this->data + index);
    else return NGU;
}

const Vector& Vector::operator=(const Vector& v){
    if(this != &v){
        delete[] this->data;
        this->n = v.n;
        this->data = new int[this->n];
        for(int i = 0; i < v.n; i++) (*this)[i] = *(v.data + i);
    }
    cout <<"="<<endl;
    return (*this);
}
