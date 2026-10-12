#include"point.h"

Point::Point(const Point& p) : xVal(p.xVal), yVal(p.yVal){}

Point::Point(const int& x, const int& y) : xVal(x), yVal(y){}

void Point::show(){
    cout<<this->xVal<<","<<this->yVal<<endl;
}

Point::~Point(){
    cout << "Huy Point" <<endl;
}

void Point::A(){
    cout << "A point" << endl;
}

void Point::A(int x){
    cout << "A point" << x << endl;
}
