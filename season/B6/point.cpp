#include "point.h"
void point::Show(){
    cout<<this->xVal<<","<<this->yVal<<endl;
}

point::point(const point& p){
    this->xVal = p.xVal;
    this->yVal = p.yVal;
}

point::point(const int& xVal, const int& yVal){
    this->xVal = xVal;
    this->yVal = yVal;
}

point::point(const int& x) : xVal(x), yVal(x){}

point::~point(){}

point operator+(const point& p1, const point& p2){
    //point p(p1.xVal + p2.xVal, p1.yVal + p2.yVal);
    return point(p1.xVal + p2.xVal, p1.yVal + p2.yVal);//p;
}

//this-q
point point::operator-(const point& p){
    point q(this->xVal - p.xVal, this->yVal - p.yVal);
    return q;
}

ostream& operator<<(ostream& o, const point& p){
    o << p.xVal << "," << p.yVal << endl;
    return o;
}
istream& operator>>(istream& i, point& p){
    cout << "xVal = ";
    i >> p.xVal;
    cout << "yVal = ";
    i >> p.yVal;
    return i;
}

//prefix
point& point::operator++(){
    this->xVal++;this->yVal++;
    return (*this);
}
//postfix
const point& point::operator++(int){
    point bef = *this;
    this->xVal++; this->yVal++;
    return bef;
}

bool point::operator==(const point& p) const{
    return(this->xVal == p.xVal && this->yVal == p.yVal)
}
