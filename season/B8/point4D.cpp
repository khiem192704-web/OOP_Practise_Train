#include"point4D.h"

Point4D::Point4D(const int& x, const int& y, const int& z, const int& t) : Point3D(x,y,z), tVal(t){}

Point4D::~Point4D(){
    cout << "Huy Point4D" <<endl;
}
void Point4D::show(){
    Point3D::show();
    cout << this->tVal << endl;
}
