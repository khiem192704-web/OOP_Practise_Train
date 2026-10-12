#include"point3D.h"

Point3D::Point3D(const int& x, const int& y, const int& z) : Point(x,y), zVal(z){}

Point3D::~Point3D(){
    cout << "Huy Point3D" << endl;
}

void Point3D::show3D(){
    cout << this->xVal << "," << this->yVal << "," << this->zVal << endl;
}

void Point3D::show(){
    Point::show();
    cout << this->zVal << endl;
}

void Point3D::A(){
    cout << "A Point3D" << endl;
}
